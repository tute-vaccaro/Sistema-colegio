#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "gotoxy.h"

#include "informacionPersonal.h"
#include "validaciones.h"
#include "profesor.h"
#include "alumno.h"
#include "aulas.h"

#ifndef ADL_H_INCLUDED
#define ADL_H_INCLUDED


typedef struct
{
    int nota;
    alumno dato;
} notaAlumno;

typedef struct nodoL
{
    notaAlumno dato;
    struct nodoL* siguiente;
} nodoL; /// LISTA DE NOTAS

typedef struct
{
    char materia[30];
    char hora[6];
    char profesor[50];
    int cantidad;
    int curso;
    char division;
    int aula;
    nodoL* listaDeNotas;
} celdaCurso;

notaAlumno cargarNota (alumno alumnito);
nodoL* inicLista();
nodoL* crearNodo (notaAlumno dato);
nodoL* agregarNodoEnOrden (nodoL* lista, nodoL* nuevoNodo);
nodoL* cargarListaNotas (nodoL* lista, int curso, char division);
int buscarPosMateria (celdaCurso adl[], int validos, char materia[]);
int agregarMateria (celdaCurso adl[], int validos, int dimension, aula array[], int validos2); ///  PARA ADMIN
void cargarListaEnADL (celdaCurso adl[], int validos, profesor profe); ///Para profesor
void mostrarNota(notaAlumno nota);
void mostrarListaNotas(nodoL* lista);
void mostrarCelda (celdaCurso adl[], int i);



#endif // ADL_H_INCLUDED
