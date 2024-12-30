#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "gotoxy.h"

#include "informacionPersonal.h"
#include "validaciones.h"
#include "profesor.h"
#include "alumno.h"
#include "aulas.h"
#include "ADL.h"
#include "pagosSueldo.h"

#ifndef HOME_H_INCLUDED
#define HOME_H_INCLUDED

#define ARCHIVOUSUARIO "archivoAlumnos.bin"
#define ADMINID 1

typedef struct
{
    int dni;
    char contrasenia[15];
    int tipo;
    int baja;
}stUsuario;

typedef struct nodoArbol
{
    struct nodoArbol* der;
    struct nodoArbol* izq;
    stUsuario dato;
} nodoArbol;

nodoArbol* inicArbol();
nodoArbol* crearNodoArbol(stUsuario dato);
nodoArbol* insertar(nodoArbol* arbol, stUsuario usuario);
nodoArbol* pasarDeArchivoToArbol(nodoArbol* arbol);
nodoArbol* buscarUsuarioEnArbol(nodoArbol* arbol, int dni);
nodoArbol* iniciarSesion();
void menuAdminUsuario();
void menuAdminAulas();
void menuAdminContabilidad();
void menuAdministrador();
void menuProfesor(int dni);
void menuAlumno(int dni);
void home();
void centrarTexto(char texto[], int y);





#endif // HOME_H_INCLUDED
