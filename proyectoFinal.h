#ifndef PROYECTOFINAL_H
#define PROYECTOFINAL_H

float calculoPeso();

typedef struct {
    int transportes;   
    float toneladas;   
} ResultadoTransporte;

ResultadoTransporte validarTransporte(float pesoKg);
float calculoCostoPais(float pesoFinalT, int *pais);
float calculoImpuestos(float costoTransporte, int pais);
void cotizacionFinal(float costoTransporte, float impuesto);

#endif