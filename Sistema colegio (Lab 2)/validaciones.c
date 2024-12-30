#include "validaciones.h"

///VALIDACION DE TIPO DE DATO INT
int validacionNumeros(char str[100], int min, int max, char dato[maxCaracteres])
{
    char *endptr;
    long num = strtol(str, &endptr, 10);
    int valido =0;
    int conv;

    conv = (int)num;
    if (*endptr == '\0' && conv >= min && conv <= max )
    {
        valido = 1;
    }
    else
    {
        while (valido == 0)
        {
            printf("Ingrese %s\n NUMERO:", dato);
            gets(str);
            num = strtol(str, &endptr, 10);
            conv = (int)num;
            if (*endptr == '\0' && conv >= min && conv <= max)
            {
                valido = 1;

            }
        }
    }
    conv = (int)num;
    return conv;
}

///VALIDACION DE TIPO DE DATO CHAR/STRING
int validacionString(char string[maxCaracteres])
{

    int cantidadCaracteres = strlen(string);
    int i;

    for (i = 0; i < cantidadCaracteres; i++)
    {
        char caracter = string[i];

        if (isalpha(caracter) == 0)
        {
            return 0;
        }
    }

    return 1;
}

///VALIDACION DE NOMBRE
int validarStringNombre(char nombre[])
{
    for(int i=0; i<strlen(nombre); i++)
    {
        if(!isalpha(nombre[i]) && !isspace(nombre[i]))
        {
            return 0;
        }
    }
    return 1;
}

///VALIDACION DE TIPO DE DATO LONG INT
int validarNTel(long nTel)
{
    if((long)nTel >= nTelefonoMin && (long)nTel <= nTelefonoMax)
    {
        return 1;

    }
    return 0;
}

/// VALIDAR LENGHT DE LA CONTRASENIA
int validarLenghtContrasenia(char contrasenia[])
{
    if(strlen(contrasenia)<5)
    {
        return 0;
    }
    return 1;
}

/// VALIDAR CONTRASENIA
int validarContrasenia(char contrasenia[], char contrasenia1[])
{
    if(strcmp(contrasenia, contrasenia1)==0)
    {
        return 1;
    }
    return 0;
}

