#include "ADL.h"
///CARGAR NOTA
notaAlumno cargarNota (alumno alumnito)
{
    notaAlumno A;
    strcpy(A.dato.dato.nombre, alumnito.dato.nombre);
    strcpy(A.dato.dato.apellido, alumnito.dato.apellido);
    printf("%s, %s - nota: ", alumnito.dato.apellido, alumnito.dato.nombre);
    scanf("%i", &A.nota);

    return A;
}
///INICIALIZAR LISTA
nodoL* inicLista()
{
    return NULL;
}
///CREAR NODO LISTA SIMPLE
nodoL* crearNodo (notaAlumno dato)
{
    nodoL* aux=(nodoL*) malloc(sizeof(nodoL));

    aux->dato=dato;
    aux->siguiente = NULL;

    return aux;
}
///AGREGAR EN ORDEN EN LISTA
nodoL* agregarNodoEnOrden (nodoL* lista, nodoL* nuevoNodo)
{
    if (lista==NULL)
    {
        lista=nuevoNodo;
    }
    else if(strcmpi(nuevoNodo->dato.dato.dato.apellido, lista->dato.dato.dato.apellido)<=0)
    {
        nuevoNodo->siguiente=lista;
        lista=nuevoNodo;
    }
    else
    {
        nodoL* ante= lista;
        nodoL* seg = lista->siguiente;

        while ((seg!=NULL) && (strcmpi(nuevoNodo->dato.dato.dato.nombre, seg->dato.dato.dato.nombre)>0))
        {
            ante=seg;
            seg=seg->siguiente;
        }

            nuevoNodo->siguiente=seg;
            ante->siguiente=nuevoNodo;

    }
    return lista;
}
///CARGAR LISTA NOTAS
nodoL* cargarListaNotas (nodoL* lista, int curso, char division)
{
    notaAlumno aux;
    FILE* buffer=fopen(ARCHIVOALUMNOS, "rb");
    alumno auxiliar;
    if(buffer)
    {
        while(fread(&auxiliar,sizeof(alumno),1,buffer)>0)
        {
            if(auxiliar.curso==curso && auxiliar.division==division)
            {
                aux=cargarNota(auxiliar);
                nodoL* nuevo=crearNodo(aux);
                lista=agregarNodoEnOrden(lista, nuevo);
            }
        }
        fclose(buffer);
    }
    return lista;
}
///BUSCAR POS MATERIA ADL
int buscarPosMateria (celdaCurso adl[], int validos, char materia[])
{
    int pos=-1, i=0;
    while (i<validos && pos==-1)
    {
        if(strcmpi(adl[i].materia, materia)==0)
        {
            pos=i;
        }
        i++;
    }
    return pos;
}
///AGREGAR MATERIA
int agregarMateria (celdaCurso adl[], int validos, int dimension, aula array[], int validos2) ///  PARA ADMIN
{
    int aula=-1;
    if(validos<dimension)
    {
        printf("Nombre de la materia: ");
        fflush(stdin);
        gets(adl[validos].materia);
        printf("Profesor de la materia: ");
        fflush(stdin);
        gets(adl[validos].profesor);
        printf("Horario de la materia: ");
        fflush(stdin);
        gets(adl[validos].hora);
        printf("Cantidad de alumnos: ");
        scanf("%i", &adl[validos].cantidad);
        while(aula==-1)
        {
            aula=asignarAula(array, validos2, adl[validos].cantidad);
        }
        adl[validos].aula=aula;
        printf("Curso: ");
        scanf("%i", &adl[validos].curso);
        printf("Division: ");
        fflush(stdin);
        scanf("%c", &adl[validos].division);
        validos++;
    }
    return validos;
}
///CARGAR LISTA DE NOTAS EN ADL
void cargarListaEnADL (celdaCurso adl[], int validos, profesor profe) ///Para profesor
{
    int pos=-1;
    pos=buscarPosMateria(adl, validos, profe.materia);
    if(pos==-1)
    {
        printf("No se encontro esa materia. Pidale al administrador que agregue su materia.\n");
    }
    else
    {
        adl[pos].listaDeNotas=cargarListaNotas(adl[pos].listaDeNotas, adl[pos].curso, adl[pos].division);
    }
}
///MOSTRAR NOTA
void mostrarNota(notaAlumno nota)
{
    printf("%s, %s \t-",  nota.dato.dato.apellido, nota.dato.dato.nombre);
    switch(nota.nota)
    {
    case 1:
        color(4);
        printf("\t%i (uno)\n", nota.nota);
        color(15);
        break;
    case 2:
        color(4);
        printf("\t%i (dos)\n", nota.nota);
        color(15);
        break;
    case 3:
        color(4);
        printf("\t%i (tres)\n", nota.nota);
        color(15);
        break;
    case 4:
        color(4);
        printf("\t%i (cuatro)\n", nota.nota);
        color(15);
        break;
    case 5:
        color(4);
        printf("\t%i (cinco)\n", nota.nota);
        color(15);
        break;
    case 6:
        color(4);
        printf("\t%i (seis)\n", nota.nota);
        color(15);
        break;
    case 7:
        color(2);
        printf("\t%i (siete)\n", nota.nota);
        color(15);
        break;
    case 8:
        color(2);
        printf("\t%i (ocho)\n", nota.nota);
        color(15);
        break;
    case 9:
        color(2);
        printf("\t%i (nueve)\n", nota.nota);
        color(15);
        break;
    case 10:
        color(2);
        printf("\t%i (diez)\n", nota.nota);
        color(15);
        break;
    }
}
///MOSTRAR LISTA NOTAS
void mostrarListaNotas(nodoL* lista)
{
    nodoL* seg=lista;
    if(lista!=NULL)
    {
        while(seg!=NULL)
        {
            mostrarNota(seg->dato);
            seg=seg->siguiente;
        }
    }
}
///MOSTRAR CELDA ADL
void mostrarCelda (celdaCurso adl[], int i)
{
    color(5);
    printf("%s\n",adl[i].materia);
    color(15);
    printf("%s\n",adl[i].hora);
    printf("DOCENTE: %s\n",adl[i].profesor);
    printf("CANTIDAD DE ALUMNOS: %i\n",adl[i].cantidad);
    printf("CURSO: %i %c\n",adl[i].curso, adl[i].division);
    printf("AULA: %i\n",adl[i].aula);

    printf("\nNotas:\n");
    mostrarListaNotas(adl[i].listaDeNotas);

}
