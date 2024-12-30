#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gotoxy.h"

#ifndef AULAS_H_INCLUDED
#define AULAS_H_INCLUDED

#define ARCHIVOAULAS "Aulas.bin"

typedef struct
{
    int capacidad;
    char disponibilidad[20];
    int numero;
} aula;

aula cargarAula ();
int verificarNumAula(int num);
void mostrarAula(aula aux);
void cargarArchivoAulas ();
//void mostrarArchivoAula();
//void verAulasDisponibles();
int pasarArchivoAArregloAulas(aula A[], int dimension);
void mostrarArregloAulas(aula A[], int validos);
void mostrarArregloAulasDisponibles(aula A[], int validos);
void insertarAulaParaOrdenamiento(aula A[], int  i, aula B);
void ordenarPorInsercionSegunNumeroAula(aula a[], int validos);
void mostrarArregloAulasDisponiblesParaXcantidad(aula A[], int validos, int cantidad);
int asignarAula (aula array[], int validos, int cantidad);


#endif // AULAS_H_INCLUDED
