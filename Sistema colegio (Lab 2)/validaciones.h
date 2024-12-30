#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string.h"

#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

#define maxCaracteres 100

///Edad
#define edadMinima 12
#define edadMaxima 100
#define datoEdad "una edad valida |12-100|"

///Direccion
#define nDirecMinimo 1
#define nDirecMaximo 9999
#define datoNDirec "un numero de direccion valido |>99|"

///Telefono
#define nTelefonoMin 1000000
#define nTelefonoMax 9999999
#define datoNTelefono "numero de telefono valido |>0|"


///DNI
#define dniMinimo 10000000
#define dniMaximo 99999999
#define datoDni "un DNI valido |>0|"

///Edad Profesor
#define edadMinimaP 18
#define edadMaximaP 100
#define datoEdadP "una edad valida |18-100|"

int validacionNumeros(char str[100], int min, int max, char dato[maxCaracteres]);
int validacionString(char string[maxCaracteres]);
int validarStringNombre(char nombre[]);
int validarNTel(long nTel);
int validarLenghtContrasenia(char contrasenia[]);
int validarContrasenia(char contrasenia[], char contrasenia1[]);
#endif // VALIDACIONES_H_INCLUDED
