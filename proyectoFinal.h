#ifndef PROYECTOFINAL_H
#define PROYECTOFINAL_H

float calculoPeso();

typedef struct {
    int transportes;   
    float toneladas;   
} ResultadoTransporte;

ResultadoTransporte validarTransporte(float pesoKg);

#endif
