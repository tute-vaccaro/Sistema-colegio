#include "aulas.h"

///CARGAR AULA
aula cargarAula ()
{
    aula aux;
    int estado=0;
    int flag=0;

    printf("Numero de aula: ");
    scanf("%i", &aux.numero);
    flag=verificarNumAula(aux.numero);
    while(flag==1)
    {
        printf("Ya existe un aula N %i. Intente nuevamente\n", aux.numero);
        printf("Numero de aula: ");
        scanf("%i", &aux.numero);
        flag=verificarNumAula(aux.numero);
    }
    printf("Ingrese la capacidad del aula: ");
    scanf("%i", &aux.capacidad);
    printf("Estado del aula: \n1-DISPONIBLE\n2-NO DISPONIBLE\nOpcion: ");
    scanf("%i", &estado);
    if(estado==1)
    {
        strcpy(aux.disponibilidad, "Disponible");
    }
    else
    {
        strcpy(aux.disponibilidad, "No disponible");
    }

    return aux;
}

///VERIFICA EN EL ARCHIVO SI YA EXISTE UN AULA CON EL NUMERO INGRESADO
int verificarNumAula(int num)
{
    FILE* archi=fopen(ARCHIVOAULAS, "rb");
    aula A;
    int flag=0;

    if(archi)
    {
        while (fread(&A, sizeof(aula), 1, archi)>0)
        {
            if(A.numero==num)
            {
                flag=1;
            }
        }
        fclose(archi);
    }
    return flag;
}
///MOSTRAR AULA
void mostrarAula(aula aux)
{
    printf("--------------------------------------\n");
    printf("Aula %i\n", aux.numero);
    printf("CAPACIDAD: %i - ", aux.capacidad);
    if (strcmpi(aux.disponibilidad, "Disponible")==0)
    {
        color(2);
        printf("%s\n", aux.disponibilidad);
        color(15);
    }
    else
    {
        color(4);
        printf("%s\n", aux.disponibilidad);
        color(15);
    }
    printf("--------------------------------------\n");
}

///CARGAR ARCHIVO AULAS
void cargarArchivoAulas ()
{
    FILE* archi=fopen(ARCHIVOAULAS, "ab");
    char seguir='s';
    aula aux;
    if(archi)
    {
        while (seguir=='s')
        {
            aux=cargarAula();
            fwrite(&aux, sizeof(aula),1, archi);

            printf("Desea cargar mas aulas? s/n\n");
            fflush(stdin);
            scanf("%c", &seguir);
        }
        fclose(archi);
    }
}

///MOSTRAR ARCHIVO AULAS
/*void mostrarArchivoAula()
{
    FILE* archi=fopen(ARCHIVOAULAS, "rb");
    aula aux;
    if(archi)
    {
        while (fread(&aux, sizeof(aula), 1, archi)>0)
        {
            mostrarAula(aux);
        }
        fclose(archi);
    }
}

///VER AULAS DISPONIBLES PARA X CANTIDAD
void verAulasDisponibles(int cantidad)
{
    FILE* archi=fopen(ARCHIVOAULAS, "rb");
    aula A;
    if(archi)
    {
        while (fread(&A, sizeof(aula), 1, archi)>0)
        {
            if(strcmpi(A.disponibilidad, "disponible")==0 && A.capacidad>=cantidad)
            {
                mostrarAula(A);
            }
        }
        fclose(archi);
    }
}*/

int pasarArchivoAArregloAulas(aula A[], int dimension)
{
    int validos=0;
    aula aux;

    FILE *buffer=fopen(ARCHIVOAULAS, "rb");
    if(buffer)
    {
        while (((fread(&aux,sizeof(aula), 1, buffer))>0) && (validos<dimension))
        {
            A[validos]=aux;
            validos++;
        }
        fclose(buffer);
    }
    return validos;
}

void mostrarArregloAulas(aula A[], int validos)
{
    int i = 0;
    while(i<validos)
    {
        mostrarAula(A[i]);
        i++;
    }
}

void mostrarArregloAulasDisponibles(aula A[], int validos)
{
    int i = 0;
    while(i<validos)
    {
        if(strcmpi (A[i].disponibilidad, "Disponible")==0)
        {
            mostrarAula(A[i]);
        }
        i++;
    }
}

void mostrarArregloAulasDisponiblesParaXcantidad(aula A[], int validos, int cantidad)
{
    int i = 0;
    while(i<validos)
    {
        if(strcmpi(A[i].disponibilidad, "disponible")==0 && A[i].capacidad>=cantidad)
        {
            mostrarAula(A[i]);
        }
        i++;
    }
}

void insertarAulaParaOrdenamiento(aula A[], int  i, aula B)
{
    int u = i;
    while(u>= 0 &&  A[u].numero>B.numero)
    {
        A[u+1] = A[u];
        u--;
    }
    A[u+1] = B;
}

void ordenarPorInsercionSegunNumeroAula(aula a[], int validos)
{
    int i;

    for(i=0; i<validos-1; i++)
    {
        insertarAulaParaOrdenamiento(a, i, a[i+1]);
    }
}

///ASIGNAR AULA A MATERIA
int asignarAula (aula array[], int validos, int cantidad)
{
    FILE* archi=fopen(ARCHIVOAULAS, "r+b");
    aula aux;
    int num=-1, aulaElegida=0;

    printf("----------------------------\n");
    mostrarArregloAulasDisponiblesParaXcantidad(array, validos, cantidad);
    printf("----------------------------\n");

    printf("Elija un aula: ");
    scanf("%i", &aulaElegida);

    if(archi)
    {
        while((fread(&aux, sizeof(aula),1, archi)>0))
        {
            if (aux.numero==aulaElegida)
            {
                if(aux.capacidad>=cantidad)
                {
                    printf("Aula asignada correctamente\n");
                    strcpy(aux.disponibilidad, "No disponible");
                    num=aulaElegida;
                }
                else
                {
                    printf("La capacidad del aula no es suficiente\n");
                }
            }
            fseek(archi,sizeof(aula)*(-1), SEEK_CUR);
            fwrite(&aux,sizeof(aula),1, archi);
        }
        fclose(archi);
    }
    return num;
}


