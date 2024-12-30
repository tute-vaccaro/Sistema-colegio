#include "informacionPersonal.h"


///funcion main de carga de informacion personal
informacionPersonal cargarInfoPersonal()
{
    informacionPersonal aux;

    printf("\n-------------- INFORMACION PERSONAL --------------\n\n");

    printf(" NOMBRE: ");
    fflush(stdin);
    gets(aux.nombre);

    printf(" APELLIDO: ");
    fflush(stdin);
    gets(aux.apellido);

    //cargarNombre(&aux);

    //cargarApellido(&aux);

    cargarEdad(&aux);

    //cargarDNI(&aux);
    printf(" DNI: ");
    scanf("%i", &aux.dni);


    cargarCalle(&aux);

    cargarNDirec(&aux);

    cargarNTelefono(&aux);

    return aux;
}

///cargar edad
void cargarEdad(informacionPersonal* info)
{

    int operador = -1;
    char strOpcion[maxCaracteres];

    printf("\n EDAD: ");
    fflush(stdin);
    gets(strOpcion);

    while(operador < 0)
    {
        operador = validacionNumeros(strOpcion,edadMinima,edadMaxima, datoEdad);

        if (operador > edadMinima && operador < edadMaxima)
        {
            info->edad= operador;
            break;
        }
    }

}

///cargar numero de direccion
void cargarNDirec(informacionPersonal* info)
{
    int operador = -1;
    char strOpcion[maxCaracteres];

    printf("\n N DIRECCION: ");
    fflush(stdin);
    gets(strOpcion);

    while(operador < 0)
    {
        operador = validacionNumeros(strOpcion,nDirecMinimo,nDirecMaximo, datoNDirec);

        if (operador > nDirecMinimo && operador < nDirecMaximo)
        {
            info->numDir= operador;
            break;
        }
    }

}

///cargar numero de telefono
void cargarNTelefono(informacionPersonal* info)
{
    long nTel;

    printf("\n N DE TELEFONO (sin prefijo): ");
    scanf("%ld", &nTel);

    int validar = validarNTel(nTel);

    while(validar != 1)
    {

        printf("\n Ingresar N de telefono correcto: ");
        scanf("%ld", &nTel);

        validar = validarNTel(nTel);

    }

    info->numTelefono = nTel;

}

///carga de N° DNI
void cargarDNI(informacionPersonal* info)
{

    int operador = -1;
    char strOpcion[maxCaracteres];

    printf("\n DNI: ");
    fflush(stdin);
    gets(strOpcion);

    while(operador < 0)
    {
        operador = validacionNumeros(strOpcion,dniMinimo,dniMaximo, datoDni);

        if (operador > dniMinimo && operador < dniMaximo)
        {
            info->dni = operador;
            break;
        }
    }
}

///carga de nombre
void cargarNombre(informacionPersonal* info)
{
    char nombre[maxCaracteres];
    printf("\n NOMBRE: ");

    fflush(stdin);
    fgets(nombre, maxCaracteres, stdin);

    int valido = validarStringNombre(nombre);


    if(valido == 1)
    {
        strcpy(info->nombre, nombre);
    }

    else if(valido == 0)
    {

        while (valido == 0)
        {

            printf("Ingrese un nombre valido\n NOMBRE: ");
            fflush(stdin);
            fgets(nombre, 50, stdin);

            valido = validarStringNombre(nombre);

        }
    }

    strcpy(info->nombre, nombre);
}

///carga de apellido
void cargarApellido(informacionPersonal* info)
{
    char apellido[maxCaracteres];
    printf("\n APELLIDO: ");

    fflush(stdin);
    fgets(apellido, maxCaracteres, stdin);

    int valido = validarStringNombre(apellido);


    if(valido == 1)
    {
        strcpy(info->apellido, apellido);
    }

    else if(valido == 0)
    {

        while (valido == 0)
        {

            printf("Ingrese un apellido valido\n APELLIDO: ");
            fflush(stdin);
            fgets(apellido, maxCaracteres, stdin);


            valido = validarStringNombre(apellido);

        }
    }

    strcpy(info->apellido, apellido);
}

///carga de nombre de calle
void cargarCalle(informacionPersonal* info)
{
    char calle[maxCaracteres];
    printf("\n CALLE: ");

    fflush(stdin);
    fgets(calle,maxCaracteres,stdin);

    int valido = validarStringNombre(calle);


    if(valido == 1)
    {
        strcpy(info->calle, calle);
    }

    else if(valido == 0)
    {

        while (valido == 0)
        {

            printf("Ingrese una calle valida\n CALLE: ");
            fflush(stdin);
            gets(calle);

            valido = validacionString(calle);

        }
    }

    strcpy(info->calle, calle);
}
