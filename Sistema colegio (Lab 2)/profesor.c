#include "profesor.h"

/// CARGAR PROFESOR
profesor cargarProfesor(int dni)
{
    profesor aux;

    printf("\n-------------- CARGAR PROFESOR --------------\n");
    printf("DNI %i \n", dni);

    cargarMateria(&aux);

    cargarSueldo(&aux);

    aux.dato = cargarInfoPersonalProfesor(dni);

    return aux;
}


///MODIFICAR DATOS PROFESOR
profesor modificarDatosProfesor(profesor profe)
{
    int num=0;
    char seguir='s';

    printf("Desea modificar un dato del profesor? s/n \n");
    fflush(stdin);
    scanf("%c", &seguir);

    while(seguir=='s')
    {
        printf("Que dato desea modificar?\n 1- Nombre \n 2- Apellido \n 3- N° DNI \n 4- Edad \n 5- N° direccion \n  6- Calle \n 7- N° telefono \n \n");
        scanf("%i", &num);

        if(num==1)
        {
            cargarNombre(&profe.dato);
        }
        else if(num==2)
        {
            cargarApellido(&profe.dato);
        }
        else if(num==3)
        {
            cargarDNI(&profe.dato);
        }
        else if(num==4)
        {
            cargarEdad(&profe.dato);
        }
        else if(num==5)
        {
            cargarNDirec(&profe.dato);
        }
        else if(num==6)
        {
            cargarCalle(&profe.dato);
        }
        else if(num==7)
        {
            cargarNTelefono(&profe.dato);
        }
        else
        {
            printf("Esa no es una opcion correcta. \n");
        }

        printf("Desea modificar otro dato? \n");
        fflush(stdin);
        scanf("%c", &seguir);
    }
    return profe;
}

///MODIFICAR ARCHIVO PROFESORES
void arModificarDatosProfesor(profesor profe)
{
    FILE* buffer=fopen(ARCHIVOPROFESORES, "r+b");
    profesor aux;

    int flag=0;

    if(buffer)
    {
        while((fread(&aux,sizeof(profesor),1,buffer)>0) && (flag==0))
        {
            if(aux.dato.dni==profe.dato.dni)
            {
                flag=1;
            }
        }
        if(flag==1)
        {
            aux=modificarDatosProfesor(aux);
            fseek(buffer, (-1)*sizeof(profesor), SEEK_CUR);
            fwrite(&aux, sizeof(profesor), 1, buffer);
        }
        fclose(buffer);
    }
}

///CARGAR ARCHIVO PROFESORES
void cargarArchivoProfesores(int dni)
{
    FILE* buffer=fopen(ARCHIVOPROFESORES, "ab");
    profesor aux;

    if(buffer)
    {
        aux=cargarProfesor(dni);
        fwrite(&aux, sizeof(profesor),1,buffer);

        fclose(buffer);
    }
}

/// VER ARCHIVO PROFESORES
void verArchivoProfesores()
{
    FILE* buffer=fopen(ARCHIVOPROFESORES, "rb");
    profesor aux;

    if(buffer)
    {
        while(fread(&aux,sizeof(profesor),1,buffer)>0)
        {
            verInformacionDeProfesor(aux);
        }
        fclose(buffer);
    }
}

///VER INFORMACION PROFESOR
void verInformacionDeProfesor(profesor profe)
{
    printf("\n-------------- Informacion del profesor --------------\n");

    printf("\n-Nombre y apellido: %s, %s \n", profe.dato.apellido, profe.dato.nombre);

    printf("\n-N° de DNI: %i\n", profe.dato.dni);
    printf("Materia: %s \n", profe.materia);
    printf("Sueldo: %i \n", profe.sueldo);

    printf("\n-Edad: %i\n", profe.dato.edad);

    printf("\n-Calle: %s\n", profe.dato.calle);

    printf("\n-N° de direccion: %i\n", profe.dato.numDir);

    printf("\n-N° de telefono: %ld\n", profe.dato.numTelefono);
}

///ASIGNAR MATERIA A PROFESOR
void cargarMateria(profesor* profe)
{
    char materia[maxCaracteres];
    printf("\n MATERIA: ");

    fflush(stdin);
    ///fgets(materia, maxCaracteres, stdin);
    gets(materia);
    int valido = validarStringNombre(materia);


    if(valido == 1)
    {
        strcpy(profe->materia, materia);
    }

    else if(valido == 0)
    {

        while (valido == 0)
        {

            printf("Ingrese una materia valida\n MATERIA: ");
            fflush(stdin);
            fgets(materia, maxCaracteres, stdin);

            valido = validarStringNombre(materia);

        }
    }

    strcpy(profe->materia, materia);
}

/// CARGAR SUELDO A PROFESOR
void cargarSueldo(profesor* profe)
{

    int operador = -1;
    char strOpcion[maxCaracteres];

    printf("\n SUELDO: ");
    fflush(stdin);
    gets(strOpcion);

    while(operador < 0)
    {
        operador = validacionNumeros(strOpcion,sueldoMinimo,sueldoMaximno, datosueldo);

        if (operador > sueldoMinimo && operador < sueldoMaximno)
        {
            profe->sueldo = operador;
            break;
        }
    }
}

void cargarEdadProfesor(informacionPersonal* info)
{

    int operador = -1;
    char strOpcion[maxCaracteres];

    printf("\n EDAD: ");
    fflush(stdin);
    gets(strOpcion);

    while(operador < 0)
    {
        operador = validacionNumeros(strOpcion,edadMinimaP,edadMaximaP, datoEdadP);

        if (operador > edadMinimaP && operador < edadMaximaP)
        {
            info->edad= operador;
            break;
        }
    }

}


informacionPersonal cargarInfoPersonalProfesor(int dni)
{


    informacionPersonal aux;


    printf("\n-------------- INFORMACION PERSONAL DEL PROFESOR--------------\n\n");


    cargarNombre(&aux);

    cargarApellido(&aux);

    cargarEdadProfesor(&aux);

    //cargarDNI(&aux);

    cargarCalle(&aux);

    cargarNDirec(&aux);

    cargarNTelefono(&aux);


    return aux;
}

///BUSCAR PROFESOR EN ARCHIVO
profesor buscarProfesor(int dni)
{
    FILE* buffer=fopen(ARCHIVOPROFESORES, "rb");
    profesor aux;
    int flag=0;

    if(buffer)
    {
        while(fread(&aux,sizeof(profesor),1,buffer)>0 && flag==0)
        {
            if(aux.dato.dni==dni)
            {
                flag=1;
            }
        }
        fclose(buffer);
    }

    fseek(buffer, (-1)*sizeof(profesor), SEEK_CUR);
    return aux;
}
