#include <stdio.h>
#include <string.h>

//FUNCION 1 (PARTE DE DOME)
float calculoPeso(){
    int numeroProductos, tipoProducto, cantidadTipo;
    float pesoUnitario, pesoTotalProducto;
    float acumulador = 0;

    const float pesos[] = {45.5, 14.2, 11.0, 32.5, 55.0, 65.0, 40.0, 25.5, 70.0, 22.0, 7.5, 38.0, 12.0, 6.5, 18.5};

    printf("\nLISTA DE PRODUCTOS\n");
    const char *catalogo[] = {
        "1.  Escritorios y Mesas de Trabajo\n",
        "2.  Sillas de Oficina\n",
        "3.  Sillas de Sala de Espera\n", 
        "4.  Archivadores y Cajoneras\n", 
        "5.  Armarios y Estanterias\n", 
        "6.  Mobiliario para Salas de Reuniones\n", 
        "7.  Mobiliario para Coworking\n", 
        "8.  Muebles para Areas Comunes\n", 
        "9.  Recepciones\n", 
        "10. Mobiliario para Cafeterias/Comedores\n", 
        "11. Sillas de comedor\n", 
        "12. Mesas de comedor\n", 
        "13. Bancos y Banquetas\n", 
        "14. Barras y Taburetes de Bar\n", 
        "15. Mobiliario para Terrazas\n"
    };

    for(int i = 0; i < 15; i++) {
        printf("%s\n", catalogo[i]);
    }
    
    printf("\nCAPACIDAD DE CARGA DE LOS TRANSPORTES\n");
    printf("GRANDES: Buques Portacontenedores (3). Capacidad: 10 t\n");
    printf("PEQUEÑOS: Buques de Cabotaje (2). Capacidad: 2 t\n");

    do{
        printf("Ingresa el numero de productos a transportar:\n");
        scanf("%d", &numeroProductos);
        if(numeroProductos <= 0 || numeroProductos >= 100){
            printf("Error: Cantidad no valida. Ingrese un valor entre 1 y 99.\n");
        }
    }while(numeroProductos <= 0 || numeroProductos >= 100);

    for(int i = 1; i <= numeroProductos; i++){
        
        do{
            printf("Ingresa el numero correspondiente al producto seleccionado (1-15):\n");
            scanf("%d", &tipoProducto);
            if(tipoProducto < 1 || tipoProducto > 15){
                printf("Error. Opción no valida. Intente con un numero del 1 al 15\n");
            }
        } while(tipoProducto < 1 || tipoProducto > 15);

        pesoUnitario = pesos[tipoProducto - 1];
        
        printf("Producto seleccionado: %s\n", catalogo[tipoProducto - 1]);
        printf("Peso unitario: %.2f kg\n", pesoUnitario);

        do {
            printf("¿Cuantos productos de este tipo lleva:\n ");
            scanf("%d", &cantidadTipo);
            if(cantidadTipo <= 0){
                printf("La cantidad debe ser mayor a 0.\n");
            }
        } while (cantidadTipo <= 0);

        pesoTotalProducto = cantidadTipo * pesoUnitario;
        acumulador += pesoTotalProducto;

        printf("Peso total de este producto: %.2f kg\n", pesoTotalProducto);
    }

    printf("El peso total de la carga es: %.2f kg\n", acumulador);
    
    return acumulador;
}


//FUNCION 2 (PARTE DE KIARA) 
//La funcion devuelve el trasnporte y las toneladas q carga

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
    const float capG = 10.0;  
    const float capP = 2.0;   

    const int maxG = 10;
    const int maxP = 2;

    int mejorG = -1, mejorP = -1;
    float mejorCapacidad = 0;
    int minTransportes = 9999;

    // 1. Encontrar la mejor combinación
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

    if (mejorG == -1) {
        printf("\nNo existe una combinación de transportes que pueda mover este peso.\n");
        return r;
    }

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

    // 3. Valores para retornar
    r.transportes = minTransportes;
    r.toneladas = mejorCapacidad;

    return r;
}

//Funcion 3 (parte mateo).
float calculoCostoPais(float pesoFinalT, int *pais){

    int CHINA = 18749; 
    int ALEMANIA = 10310; 
    int ITALIA = 11500; 
    int MEXICO = 3000;
    int VIETNAM = 21000; 

    float costoTransporte;
    float valorPagar = pesoFinalT * 1;

    printf("Seleccione el pais de destino:\n");
    printf("1. China\n2. Alemania\n3. Italia\n4. Mexico\n5. Vietnam\n");

    scanf("%i", pais);

    while(*pais < 1 || *pais > 5){
        printf("Seleccione una opcion valida:\n");
        scanf("%i", pais);
    }

    switch(*pais){

        case 1:
         costoTransporte = CHINA * valorPagar;
         break;
        case 2: 
        costoTransporte = ALEMANIA * valorPagar;
         break;

        case 3: 
        costoTransporte = ITALIA * valorPagar; 
        break;

        case 4: 
        costoTransporte = MEXICO * valorPagar;
         break;

        case 5:
        costoTransporte = VIETNAM * valorPagar; 
        break;
    }
        printf("Costo de transporte: $%f\n", costoTransporte);

    return costoTransporte;
}
//Funcion 4 (Irvin)
float calculoImpuestos(float costoTransporte, int pais) {

    float impuesto = 0;

    const float impuestos[] = {
        0.15, // China
        0.05, // Alemania
        0.05, // Italia
        0.20, // Mexico
        0.15  // Vietnam
    };

    impuesto = costoTransporte * impuestos[pais - 1];

    printf("\n=== CALCULO DE IMPUESTOS ===\n");
    printf("Porcentaje de impuesto: %f%%\n", impuestos[pais - 1] * 100);
    printf("Valor del impuesto: $%f\n", impuesto);

    return impuesto;
}
//Funcion 5(Irvin)
void cotizacionFinal(float costoTransporte, float impuesto) {

    float total;

    total = costoTransporte + impuesto;

    printf("=== COTIZACION FINAL ===\n");
    printf("Costo de transporte: $%f\n", costoTransporte);
    printf("Impuesto: $%f\n", impuesto);
    printf("TOTAL A PAGAR: $%f\n", total);
}
