#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#include "informacionPersonal.h"
#include "validaciones.h"

#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

#define maxCaracteres 100

///legajo
#define legajoMinimo 0
#define legajoMaximno 1000000000
#define datoLegajo "un legajo valido |>0|"

///pagos
#define pagosMinimo -1
#define pagosMaximo 2
#define datoPagos "un Pago valido |>0|"


///Curso
#define cursoMinimo 1
#define cursoMaximno 6
#define datoCurso "un curso valido |1 - 6|"

#define ARCHIVOALUMNOS "archivoAlumnos.bin"

typedef struct
{
    int legajo;
    int pagos[12]; ///ESTADO DEL PAGO
    int cuotas[12]; ///MONTO
    int curso;
    char division;
    informacionPersonal dato;
} alumno;

alumno cargarAlumno();
void cargarLegajo(alumno* alumnito);
void cargarDivision(alumno* alumnito);
void cargarCurso(alumno* alumnito);
void verInformacionDeAlumno(alumno alumnito);
alumno modificarDatosAlumno(alumno alumnito);
void cargarArchivoAlumnos();
void verAlumnosEnArchivo();
void arModificarDatosAlumno();
alumno buscarAlumno(int dni);

#endif // ALUMNO_H_INCLUDED
