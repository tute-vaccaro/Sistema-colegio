#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "gotoxy.h"

#include "alumno.h"
#include "profesor.h"
#include "informacionPersonal.h"

#ifndef PAGOSSUELDO_H_INCLUDED
#define PAGOSSUELDO_H_INCLUDED

void pagoAlumno (alumno * alumnito);
void mostrarCuadroPagos (alumno alumnito);
void mostrarEstadoSueldo (profesor profe);
void registrarPagoSueldo (profesor* profe);

#endif // PAGOSSUELDO_H_INCLUDED
