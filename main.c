#include <stdio.h>
#include <string.h>
#include "proyectoFinal.h"

int main(){
   float pesoKg;
    ResultadoTransporte r;
    float costoTransporte;
    float impuesto;
    int pais;

    pesoKg = calculoPeso();
    r = validarTransporte(pesoKg);
    costoTransporte = calculoCostoPais(r.toneladas, &pais);
    impuesto = calculoImpuestos(costoTransporte, pais);
    cotizacionFinal(costoTransporte, impuesto);
   return 0;
}
