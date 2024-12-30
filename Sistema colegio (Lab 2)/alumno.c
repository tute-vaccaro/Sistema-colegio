#include "alumno.h"

///FUNCION PRINCIPAL CARGAR ALUMNO
alumno cargarAlumno()
{

    alumno aux;
    int cuota=0;
    printf("\n-------------- CARGAR ALUMNO --------------\n");
//    printf("DNI %i \n", dni);

    cargarLegajo(&aux);

    for(int i=0; i<12; i++)
    {
        aux.pagos[i]=0;
    }

    printf("Cuota: ");
    scanf("%i", &cuota);

    for(int i=0; i<12; i++)
    {
        aux.cuotas[i]=cuota;
    }

    cargarCurso(&aux);
    //printf(" Ingrese el curso: ");
    //scanf("%i", &aux.curso);

    printf(" Ingrese la division: ");
    fflush(stdin);
    scanf("%c", &aux.division);

    aux.dato = cargarInfoPersonal();


    return aux;
}

///CARGAR LEGAJO
void cargarLegajo(alumno* alumnito)
{
    int operador = -1;
    char strOpcion[maxCaracteres];

    printf("\n LEGAJO: ");
    fflush(stdin);
    gets(strOpcion);

    while(operador < 0)
    {
        operador = validacionNumeros(strOpcion,legajoMinimo,legajoMaximno, datoLegajo);

        if (operador > legajoMinimo && operador < legajoMaximno)
        {
            alumnito->legajo = operador;
            break;
        }
    }
}

///CARGAR CURSO
void cargarCurso(alumno* alumnito)
{
    int operador = -1;
    char strOpcion[maxCaracteres];

    printf("\n CURSO: ");
    fflush(stdin);
    gets(strOpcion);

    while(operador < 0)
    {
        operador = validacionNumeros(strOpcion,cursoMinimo,cursoMaximno, datoCurso);

        if (operador > cursoMinimo && operador < cursoMaximno)
        {
            alumnito->curso = operador;
            break;
        }
    }
}

///VER INFORMACION ALUMNO
void verInformacionDeAlumno(alumno alumnito)
{
    printf("\n-------------- Informacion del alumno --------------\n\n");

    printf("Legajo: %i\n", alumnito.legajo);
    printf("Curso: %i\n", alumnito.curso);
    printf("Division: %c\n", alumnito.division);

    printf("\n-Nombre y apellido: %s, %s \n", alumnito.dato.apellido, alumnito.dato.nombre);

    printf("\n-N de DNI: %i\n", alumnito.dato.dni);

    printf("\n-Edad: %i\n", alumnito.dato.edad);

    printf("\n-Direccion: %s\n", alumnito.dato.calle);

    printf("\n-N de direccion: %i\n", alumnito.dato.numDir);

    printf("\n-N de telefono: %ld\n", alumnito.dato.numTelefono);
}

/// MODIFICAR DATOS ALUMNO
alumno modificarDatosAlumno(alumno alumnito)
{
    int num=0;
    char seguir='s';

    printf("Desea modificar un dato del alumno? s/n \n");
    fflush(stdin);
    scanf("%c", &seguir);

    while(seguir=='s')
    {
        printf("Que dato desea modificar?\n 1- Nombre \n 2- Apellido \n 3- N° DNI \n 4- Edad \n 5- N° direccion \n  6- Calle \n 7- N° telefono \n \n");
        scanf("%i", &num);

        if(num==1)
        {
            cargarNombre(&alumnito.dato);
        }
        else if(num==2)
        {
            cargarApellido(&alumnito.dato);
        }
        else if(num==3)
        {
            cargarDNI(&alumnito.dato);
        }
        else if(num==4)
        {
            cargarEdad(&alumnito.dato);
        }
        else if(num==5)
        {
            cargarNDirec(&alumnito.dato);
        }
        else if(num==6)
        {
            cargarCalle(&alumnito.dato);
        }
        else if(num==7)
        {
            cargarNTelefono(&alumnito.dato);
        }
        else
        {
            printf("Esa no es una opcion correcta. \n");
        }

        printf("Desea modificar otro dato? \n");
        fflush(stdin);
        scanf("%c", &seguir);
    }
    return alumnito;
}

///CARGAR ARCHIVO ALUMNOS
void cargarArchivoAlumnos(int dni)
{
    FILE* buffer=fopen(ARCHIVOALUMNOS, "ab");
    alumno aux;
    char seguir='s';

    if(buffer)
    {
        while(seguir=='s')
        {
            aux=cargarAlumno();
            fwrite(&aux, sizeof(alumno),1,buffer);

            printf("\nDesea cargar otro alumno? \n");
            fflush(stdin);
            scanf("%c", &seguir);
        }
        fclose(buffer);
    }
}

///VER ARCHIVO ALUMNOS
void verAlumnosEnArchivo()
{
    FILE* buffer=fopen(ARCHIVOALUMNOS, "rb");
    alumno aux;

    if(buffer)
    {
        while(fread(&aux,sizeof(alumno),1,buffer)>0)
        {
            verInformacionDeAlumno(aux);
        }
        fclose(buffer);
    }
}

///MODIFICAR ARCHIVO ALUMNOS
void arModificarDatosAlumno()
{
    FILE* buffer=fopen(ARCHIVOALUMNOS, "r+b");
    alumno aux;
    int dni;
    printf("Ingrese el DNI del alumno a modificar: \n");
    scanf("%i",&dni);

    int flag=0;

    if(buffer)
    {
        while((fread(&aux,sizeof(alumno),1,buffer)>0) && (flag==0))
        {
            if(aux.dato.dni==dni)
            {
                flag=1;
            }
        }
        if(flag==1)
        {
            aux=modificarDatosAlumno(aux);
            fseek(buffer, (-1)*sizeof(alumno), SEEK_CUR);
            fwrite(&aux, sizeof(alumno), 1, buffer);
        }
        fclose(buffer);
    }
}

///BUSCAR ALUMNO EN ARCHIVO
alumno buscarAlumno(int dni)
{
    FILE* buffer=fopen(ARCHIVOALUMNOS, "rb");
    alumno aux;
    int flag=0;

    if(buffer)
    {
        while(fread(&aux,sizeof(alumno),1,buffer)>0 && flag==0)
        {
            if(aux.dato.dni==dni)
            {
                flag=1;
            }
        }
        fclose(buffer);
    }
    return aux;
}
