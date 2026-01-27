#include <stdio.h>
#include <string.h>
#include "proyectoFinal.h"

int main () {
    typedef struct {
    int transportes;   
    float toneladas;   
    } ResultadoTransporte;
    return 0;
}

int validarTransporte(float pesoKg) {
    pesoKg = calculoPeso();
    float pesoT = pesoKg / 1000.0;

    // Separar parte entera y decimal
    int parteEntera = (int)pesoT;
    float decimal = pesoT - parteEntera;
    float pesoFinalT;

    // Aplicar regla del decimal
    if (decimal > 0.5) {
        pesoFinalT = parteEntera + 1;  // redondear hacia arriba
        printf("\nEl decimal %.2f t es mayor a 0.5, se redondea hacia arriba.\n", decimal);
    } else {
        pesoFinalT = parteEntera;      // rechazar decimal
        printf("\nEl decimal %.2f t es menor o igual a 0.5, se rechaza.\n", decimal);
        printf("Peso rechazado: %.2f t\n", decimal);
    }

    // Capacidades en toneladas
    const float capG = 10.0;   // transporte grande
    const float capP = 2.0;   // transporte pequeño

    const int maxG = 10;
    const int maxP = 2;

    int mejorG = -1, mejorP = -1;
    float mejorCapacidad = 0;
    int minTransportes = 9999;

    printf("\n=== VALIDACIÓN DEL TRANSPORTE ===\n");
    printf("Peso total original: %.2f t\n", pesoT);
    printf("Peso usado para transporte: %.2f t\n", pesoFinalT);

    // Probar todas las combinaciones posibles
    for (int g = 0; g <= maxG; g++) {
        for (int p = 0; p <= maxP; p++) {

            float capacidadTotal = g * capG + p * capP;

            if (capacidadTotal >= pesoFinalT && (g + p) > 0) {

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

    if (mejorG == -1) {
        printf("\nNo existe una combinación de transportes que pueda mover este peso.\n");
        return 0;
    }

    printf("\nMEJOR COMBINACIÓN DE TRANSPORTES\n");
    printf("Transportes grandes usados: %d\n", mejorG);
    printf("Transportes pequeños usados: %d\n", mejorP);
    printf("Total de transportes aprobados: %d\n", minTransportes);
    printf("Capacidad total disponible: %.2f t\n", mejorCapacidad);

    return minTransportes; 
}