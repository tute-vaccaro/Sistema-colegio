#include "home.h"
///INICIALIZAR ARBOL
nodoArbol* inicArbol()
{
    return NULL;
}

///CREAR NODO ARBOL
nodoArbol* crearNodoArbol(stUsuario dato)
{
    nodoArbol* aux=(nodoArbol*) malloc(sizeof(nodoArbol));

    aux->der=NULL;
    aux->izq=NULL;
    aux->dato=dato;

    return aux;
}

///INSERTAR USUARIO EN ARBOL
nodoArbol* insertar(nodoArbol* arbol, stUsuario usuario)
{
    if(arbol==NULL)
    {
        arbol=crearNodoArbol(usuario);
    }
    else
    {
        if(usuario.dni > arbol->dato.dni)
        {
            arbol->der=insertar(arbol->der, usuario);
        }
        else
        {
            arbol->izq=insertar(arbol->izq, usuario);
        }
    }
    return arbol;
}

///ARCHIVO A ARBOL
nodoArbol* pasarDeArchivoToArbol(nodoArbol* arbol)
{
    FILE* buffer=fopen(ARCHIVOUSUARIO, "rb");
    stUsuario aux;

    if(buffer)
    {
        while(fread(&aux,sizeof(stUsuario),1,buffer)>0)
        {
            arbol=insertar(arbol, aux);
        }
        fclose(buffer);
    }
    return arbol;
}

///BSUCAR USUARIO POR DNI
nodoArbol* buscarUsuarioEnArbolIniciarSesion(nodoArbol* arbol, int dni, char contrasenia[])
{
    nodoArbol* rta=NULL;

    if(arbol)
    {
        if(arbol->dato.dni == dni && strcmpi(arbol->dato.contrasenia, contrasenia)==0)
        {
            rta=arbol;
        }
        else
        {
            if(arbol->dato.dni > dni)
            {
                rta=buscarUsuarioEnArbolIniciarSesion(arbol->izq, dni, contrasenia);
            }
            else
            {
                rta=buscarUsuarioEnArbolIniciarSesion(arbol->der, dni, contrasenia);
            }
        }
    }
    return rta;
}

nodoArbol* buscarUsuarioEnArbol(nodoArbol* arbol, int dni)
{
    nodoArbol* rta=NULL;

    if(arbol)
    {
        if(arbol->dato.dni == dni)
        {
            rta=arbol;
        }
        else
        {
            if(arbol->dato.dni > dni)
            {
                rta=buscarUsuarioEnArbol(arbol->izq, dni);
            }
            else
            {
                rta=buscarUsuarioEnArbol(arbol->der, dni);
            }
        }
    }
    return rta;
}

void mostrarUsuario (stUsuario usuario)
{
    if(usuario.tipo==1)
    {
        printf("USUARIO: %i\t-\tTIPO: %s\t-\tESTADO: %s\n", usuario.dni, "ADMINISTRADOR", "INACTIVO");
    }
    else if(usuario.tipo==2)
    {
        printf("USUARIO: %i\t-\tTIPO: %s\t-\tESTADO: %s\n", usuario.dni, "PROFESOR", "INACTIVO");

    }
    else if(usuario.tipo==3)
    {
        printf("USUARIO: %i\t-\tTIPO: %s\t-\tESTADO: %s\n", usuario.dni, "ESTUDIANTE", "INACTIVO");
    }
}
void mostrarInOrderDNI (nodoArbol* arbolUsuarios)
{
    mostrarInOrderDNI(arbolUsuarios->izq);
    mostrarUsuario(arbolUsuarios->dato);
    mostrarInOrderDNI(arbolUsuarios->der);
}
///INICIO DE SESION
nodoArbol* iniciarSesion(nodoArbol* arbolUsuarios)
{
    nodoArbol* usuario;
    int dni;
    char contrasenia[30];

    centrarTexto("Ingrese su DNI: ", 20);
    scanf("%i", &dni);
    centrarTexto("Ingrese contrasenia: ",22);
    fflush(stdin);
    gets(contrasenia);
    usuario = buscarUsuarioEnArbolIniciarSesion(arbolUsuarios, dni, contrasenia);
    return usuario;
}

///REGISTRAR NUEVO USUARIO
nodoArbol* registrarNuevoUsuario(int tipo, nodoArbol* arbolUsuarios)
{
    stUsuario usuario;

    printf("Ingrese el DNI del usuario: ");
    scanf("%i", &usuario.dni);;
    usuario.baja = 0;
    usuario.tipo=tipo;
    strcpy(usuario.contrasenia, "12345");
    color(111);
    printf("\nATENCION! La contrasenia del usuario sera 12345 por defecto. Podra ser modificada porsteriormente por el usuario\n\n");
    color(15);

    arbolUsuarios=insertar(arbolUsuarios, usuario);

    if(usuario.tipo==2)
    {
        cargarArchivoProfesores(usuario.dni);
    }
    if(usuario.tipo==3)
    {
        cargarArchivoAlumnos(usuario.dni);
    }
    return arbolUsuarios;
}

///DAR DE BAJA/ALTA UN USUARIO
nodoArbol* bajaAltaLogica(int opcion, /*nodoArbol* arbolUsuarios,*/ nodoArbol* usuario)
{
    if(opcion == 1)
    {
        usuario->dato.baja = 1;
    }
    else
    {
        usuario->dato.baja = 0;
    }
    return usuario;
}

///MENU PARA ADMIN
void menuAdminUsuario(nodoArbol* arbolUsuarios)
{
    int option=0, tipo=-1, dni=0, bajaAlta=0, opcion2=0;
    do
    {
        printf("1. Registrar nuevo usuario\n");
        printf("2. Ver usuarios \n");
        printf("3. Dar de baja/alta usuario \n");
        printf("0. Volver al menu anterior \n");
        scanf("%i",&option);
        system("cls");
        switch(option)
        {
        case 1:
            printf("Ingrese el tipo de usuario:\n1-ADMINISTRADOR\n2-PROFESOR\n3-ESTUDIANTE\n");
            scanf("%i", &tipo);
            arbolUsuarios=registrarNuevoUsuario(tipo, arbolUsuarios);
            system("pause");
            system("cls");
            break;
        case 2:
            printf("1. Ver usuarios activos\n");
            printf("2. Ver usuarios inactivos\n");
            printf("3. Ver todos los usuarios \n");
            scanf("%i", &opcion2);
            mostrarInOrderDNI(arbolUsuarios);
            system("pause");
            system("cls");
            break;
        case 3:
            printf("Seleccione: \n1-BAJA\n2-ALTA\n\n");
            scanf("%i", &bajaAlta);
            printf("Ingrese el DNI de usuario: ");
            scanf("%i", &dni);
            nodoArbol* usuario=buscarUsuarioEnArbol(arbolUsuarios, dni);
            if(usuario==NULL)
            {
                printf("No se encontro al usuario DNI %i", dni);
            }
            else
            {
                usuario=bajaAltaLogica(bajaAlta,usuario);
                if(usuario->dato.tipo==1)
                {
                    printf("El usuario ha sido dado de alta correctamente\n");
                }
                else if(usuario->dato.tipo==0)
                {
                    printf("El usuario ha sido dado de baja correctamente\n");
                }
                else
                {
                    printf("Algo ha salido mal. Intente nuevamente\n");
                }
            }
            system("pause");
            system("cls");
            break;
        case 0:
            system("cls");
            break;
        default:
            printf("Opcion Incorrecta \n\n");
            system("pause");
            system("cls");
            break;
        }
    }
    while(option!=0);
}
///MENU PARA ADMIN
void menuAdminAulas()
{
    int option=0, opcion2=0, dimension=100, validos=0, cantidad=0;
    aula array[dimension];
    do
    {
        printf("1. Registrar aula\n");
        printf("2. Ver aulas \n");
        printf("3. Agregar nueva materia \n");
        printf("0. Volver al menu anterior \n");
        scanf("%i",&option);
        system("cls");
        switch(option)
        {
        case 1:
            cargarArchivoAulas();
            system("pause");
            system("cls");
            break;
        case 2:
            printf("1- Ver todas las aulas\n");
            printf("2- Ver aulas disponibles\n");
            printf("3- Ver aulas dispoinbles para cierta cantidad\n");
            printf("0. Volver al menu anterior \n");
            printf("\nIngrese un numero: ");
            scanf("%i", &opcion2);
            system("cls");
            validos=pasarArchivoAArregloAulas(array, dimension);
            ordenarPorInsercionSegunNumeroAula(array, validos);
            if(opcion2==1)
            {
                mostrarArregloAulas(array, validos);
                system("pause");
                system("cls");
            }
            else if(opcion2==2)
            {
                mostrarArregloAulasDisponibles(array, validos);
                system("pause");
                system("cls");
            }
            else if(opcion2==3)
            {
                printf("Ingrese cantidad de personas: ");
                scanf("%i", &cantidad);
                printf("Las aulas se mostraran de acuerdo a su capacidad, en orden decreciente\n");
                mostrarArregloAulasDisponiblesParaXcantidad(array, validos, cantidad);
                system("pause");
                system("cls");
            }
            else if(opcion2==0)
            {
                system("cls");
            }
            else
            {
                color(4);
                printf("Opcion invalida\n");
                color(15);
                system("pause");
                system("cls");
            }
            system("pause");
            system("cls");
            break;
        case 3:
            printf("Completar\n");
            system("pause");
            system("cls");
            break;
        case 0:
            system("cls");
            break;
        default:
            printf("Opcion Incorrecta \n\n");
            system("pause");
            system("cls");
            break;
        }
    }
    while(option!=0);
}
///MENU PARA ADMIN
void menuAdminContabilidad()
{
    int option=0, dni=0, cuota=0;
    alumno alumnito;
    do
    {
        printf("1. Registrar pago\n"); /// a alumno o docente
        printf("2. Ver estado contable usuario\n");
        printf("3. Ver estado contable \n");
        printf("0. Volver al menu anterior \n");
        scanf("%i",&option);
        system("cls");
        switch(option)
        {
        case 1:
           cargarArchivoAlumnos();
            verAlumnosEnArchivo();
            printf("Ingrese el DNI del alumno: ");
            scanf("%i", &dni);
            alumnito=buscarAlumno(dni);
            verInformacionDeAlumno(alumnito);
            pagoAlumno(&alumnito);
            system("pause");
            system("cls");
            break;
        case 2:
            printf("Ingrese el DNI del alumno: ");
            scanf("%i", &dni);
            alumnito=buscarAlumno(dni);
            mostrarCuadroPagos(alumnito);
            system("pause");
            system("cls");
            break;
        case 3:
            menuAdminContabilidad();
            system("pause");
            system("cls");
            break;
        case 0:
            system("cls");
            break;
        default:
            printf("Opcion Incorrecta \n\n");
            system("pause");
            system("cls");
            break;
        }
    }
    while(option!=0);
}
///MENU ADMIN
void menuAdministrador(nodoArbol* arbolUsuarios)
{
    int option=0;
    do
    {
        printf("1. Usuarios \n");
        printf("2. Materias-Aulas \n");
        printf("3. Contabilidad \n");
        printf("0. Volver al menu anterior \n");
        scanf("%i",&option);
        system("cls");
        switch(option)
        {
        case 1:
            menuAdminUsuario(arbolUsuarios);
            system("pause");
            system("cls");
            break;
        case 2:
            menuAdminAulas();
            system("pause");
            system("cls");
            break;
        case 3:
            menuAdminContabilidad();
            system("pause");
            system("cls");
            break;
        case 0:
            system("cls");
            break;
        default:
            printf("Opcion Incorrecta \n");
            system("pause");
            system("cls");
            break;
        }

    }
    while(option!=0);
}
///MENU PROFESOR
void menuProfesor(int dni)
{
    profesor profe=buscarProfesor(dni);
    int option=0;
    do
    {
        printf("1. Cargar notas \n");
        printf("2. Ver estado contable \n");
        printf("3. Modificar información personal\n");
        printf("0. Volver al menu anterior \n");
        scanf("%i",&option);
        system("cls");
        switch(option)
        {
        case 1:
//            cargarListaEnADL();
            system("pause");
            system("cls");
            break;
        case 2:
            mostrarEstadoSueldo(profe);
            system("pause");
            system("cls");
            break;
        case 3:
            arModificarDatosProfesor(profe);
            system("pause");
            system("cls");
            break;
        case 0:
            system("cls");
            break;
        default:
            printf("Opcion Incorrecta \n");
            system("pause");
            system("cls");
            break;
        }

    }
    while(option!=0);
}
///MENU ALUMNO
void menuAlumno(int dni)
{
    int option=0;
    do
    {
        printf("1. Ver notas \n");
        printf("2. Ver estado contable \n");
        printf("3. Modificar información personal\n");
        printf("0. Volver al menu anterior \n");
        scanf("%i",&option);
        system("cls");
        switch(option)
        {
        case 1:
//            menuAdminUsuario();
            system("pause");
            system("cls");
            break;
        case 2:
//            adMenuRegistro();
            system("pause");
            system("cls");
            break;
        case 3:
//            modificarPerfil(admin);
            system("pause");
            system("cls");
            break;
        case 0:
            system("cls");
            break;
        default:
            printf("Opcion Incorrecta \n");
            system("pause");
            system("cls");
            break;
        }

    }
    while(option!=0);
}
///MENU PRINCIPAL
void home()
{
    nodoArbol* arbolUsuarios=NULL;
    //arbolUsuarios=pasarDeArchivoToArbol(arbolUsuarios);

    int option=0;
    nodoArbol* usuario;

    if(arbolUsuarios == NULL)
    {
        arbolUsuarios=inicArbol();
        printf("Registre al administrador: \n");
        arbolUsuarios = registrarNuevoUsuario(1, arbolUsuarios);
        system("pause");
        system("cls");
        printf("Administrador creado exitosamente! \n");
        system("pause");
        system("cls");

    }

    do
    {
        printf("1. Iniciar Sesion \n");
        printf("0. Salir \n");
        printf("\nIngrese un numero: ");
        scanf("%i",&option);
        system("cls");
        switch(option)
        {
        case 1:
            usuario = iniciarSesion(arbolUsuarios);
            system("cls");
            if(usuario==NULL)
            {
                color(4);
                printf("Usuario o contrasenia incorrecta\n\n");
                color(15);
                system("pause");
                system("cls");
            }
            else
            {
                if(usuario->dato.tipo == 1)
                {
                    printf("Bienvenido Administrador!\n");
                    system("pause");
                    system("cls");
                    menuAdministrador(arbolUsuarios);
                }
                else if(usuario->dato.tipo == 2)
                {
                    printf("Bienvenido!\n");
                    system("pause");
                    system("cls");
                    menuProfesor(usuario->dato.dni);
                }
                else if(usuario->dato.tipo == 3)
                {
                    printf("Bienvenido!\n");
                    system("pause");
                    system("cls");
                    menuAlumno(usuario->dato.dni);
                }
            }
            break;
        case 0:
            printf("Saliendo del sistema... \n\n");
            system("pause");
            system("cls");
            break;
        default:
            color(4);
            printf("Opcion Incorrecta \n");
            color(15);
            system("pause");
            system("cls");
            break;
        }
    }
    while(option != 0);
}

/// /////////////////
void centrarTexto(char texto[], int y)
{
    int tamanio=strlen(texto);
    gotoxy(90-(tamanio/2), y);
    printf("%s ",texto);
}

