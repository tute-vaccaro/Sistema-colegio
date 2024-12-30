#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#include "validaciones.h"

#ifndef INFORMACIONPERSONAL_H_INCLUDED
#define INFORMACIONPERSONAL_H_INCLUDED

///INFO PERSONAL
typedef struct
{
    char nombre[30];
    char apellido [30];
    int edad;
    int dni;
    char calle[20];
    int numDir;
    long int numTelefono;
} informacionPersonal;

informacionPersonal cargarInfoPersonal();
void cargarEdad(informacionPersonal* info);
void cargarNDirec(informacionPersonal* info);
void cargarNTelefono(informacionPersonal* info);
void cargarDNI(informacionPersonal* info);
void cargarNombre(informacionPersonal* info);
void cargarApellido(informacionPersonal* info);
void cargarCalle(informacionPersonal* info);
#endif // INFORMACIONPERSONAL_H_INCLUDED
