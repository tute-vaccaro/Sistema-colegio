#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "gotoxy.h"

#include "home.h"

int main()
{
    color(9);
    centrarTexto("BIENVENIDO!", 0);
    centrarTexto("Colegio CTN", 2);
    centrarTexto("Nivel Secundario", 4);
    centrarTexto("Desde 1999", 6);

    centrarTexto("Avenida Dorrego 281", 10);
    centrarTexto("Mar del plata, Buenos Aires", 12);
    centrarTexto("TEL: 480-1220", 14);
    centrarTexto("--------------------------------------", 16);
    color(15);
    printf("\n");
    system("pause");
    system("cls");

    alumno aux;
    aux=cargarAlumno();
    pagoAlumno(&aux);
    system("pause");
    system("cls");
    mostrarCuadroPagos(aux);

    //verAlumnosEnArchivo();
    //home();

    return 0;
}






