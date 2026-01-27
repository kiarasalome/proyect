#include <stdio.h>
#include <string.h>
#include "proyectoFinal.h"

typedef struct {
    int transportes;   
    float toneladas;   
} ResultadoTransporte;

ResultadoTransporte validarTransporte(float pesoKg) {

    ResultadoTransporte r;
    r.transportes = 0;
    r.toneladas = 0;

    float pesoT = pesoKg / 1000.0;

    // Capacidades
    const float capG = 10.0;   // transporte grande
    const float capP = 2.0;   // transporte pequeño

    const int maxG = 10;
    const int maxP = 2;

    int mejorG = -1, mejorP = -1;
    float mejorCapacidad = 0;
    int minTransportes = 9999;

    // 1. Encontrar la mejor combinación SIN redondear aún
    for (int g = 0; g <= maxG; g++) {
        for (int p = 0; p <= maxP; p++) {

            float capacidadTotal = g * capG + p * capP;

            if (capacidadTotal >= pesoT && (g + p) > 0) {

                int usados = g + p;

                if (usados < minTransportes) {
                    minTransportes = usados;
                    mejorG = g;
                    mejorP = p;
                    mejorCapacidad = capacidadTotal;
                }
            }
        }
    }

    // Si no hay combinación posible
    if (mejorG == -1) {
        printf("\nNo existe una combinación de transportes que pueda mover este peso.\n");
        return r;
    }

    // 2. Ahora sí aplicar el redondeo DESPUÉS de encontrar la combinación
    float decimal = pesoT - (int)pesoT;
    float pesoFinalT;

    if (decimal > 0.5) {
        pesoFinalT = (int)pesoT + 1;
        printf("\nEl decimal %.2f t es mayor a 0.5, se redondea hacia arriba.\n", decimal);
    } else {
        pesoFinalT = (int)pesoT;
        printf("\nEl decimal %.2f t es menor o igual a 0.5, se rechaza.\n", decimal);
        printf("Peso rechazado: %.2f t\n", decimal);
    }

    printf("\n=== MEJOR COMBINACIÓN DE TRANSPORTE ===\n");
    printf("Transportes grandes usados: %d\n", mejorG);
    printf("Transportes pequeños usados: %d\n", mejorP);
    printf("Total de transportes: %d\n", minTransportes);
    printf("Capacidad total disponible: %.2f t\n", mejorCapacidad);
    printf("Peso final considerado: %.2f t\n", pesoFinalT);

    // 3. Guardar valores para retornar
    r.transportes = minTransportes;
    r.toneladas = mejorCapacidad;

    return r;
}