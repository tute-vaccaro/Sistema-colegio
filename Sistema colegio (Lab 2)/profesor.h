#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#include "informacionPersonal.h"
#include "validaciones.h"
#ifndef PROFESOR_H_INCLUDED
#define PROFESOR_H_INCLUDED

///Sueldo
#define sueldoMinimo 49999
#define sueldoMaximno 2000000
#define datosueldo "un sueldo valido |50k - 2M|"

#define maxCaracteres 100

#define ARCHIVOPROFESORES "archivoProfesores.bin"

///PROFESOR
typedef struct
{
    char materia[30];
    int sueldo;
    int estadoSueldo[12];
    informacionPersonal dato;
} profesor;

profesor cargarProfesor();
void cargarArchivoProfesores();
profesor modificarDatosProfesor(profesor profe);
void arModificarDatosProfesor(profesor profe);
void verArchivoProfesores();
void verInformacionDeProfesor(profesor profe);
void cargarMateria(profesor* profe);
void cargarSueldo(profesor* profe);
void cargarEdadProfesor(informacionPersonal* info);
profesor buscarProfesor(int dni);
informacionPersonal cargarInfoPersonalProfesor();

#endif // PROFESOR_H_INCLUDED
