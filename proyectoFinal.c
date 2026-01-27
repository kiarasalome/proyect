#include <stdio.h>
#include <string.h>
float calculoPeso();
//HOLAaaaaaaaaa
int main(){

    
    printf("%.2f", calculoPeso());
    return 0;
}

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
