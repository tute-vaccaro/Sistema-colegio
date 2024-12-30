#include "pagosSueldo.h"

///REGISTRAR PAGO DE ALUMNO
void pagoAlumno (alumno * alumnito)
{
    int mes=0, flag=0, pago=0;
    printf("1-ENERO\n2-FEBRERO\n3-MARZO\n4-ABRIL\n5-MAYO\n6-JUNIO\n7-JULIO\n8-AGOSTO\n9-SEPTIEMBRE\n10-OCTUBRE\n11-NOVIEMBRE\n12-DICIEMBRE\nPAGO CORRESPONDIENTE AL MES:");
    scanf("%i", &mes);
    printf("1-ADEUDA\n2-PAGADO\n3-PAGO PARCIAL\n");
    scanf("%i", &alumnito->pagos[mes-1]);
    if(alumnito->pagos[mes-1]==1 || (alumnito->pagos[mes-1]==3))
    {
        printf("Ingrese el monto del pago: ");
        scanf("%i", &pago);
        alumnito->cuotas[mes-1]=(alumnito->cuotas)-pago;
    }

    FILE * buffer;
    alumno aux;
    buffer = fopen(ARCHIVOALUMNOS, "r+b" );
    if(buffer)
    {
        while (flag==0 && (fread(&aux, sizeof(alumno),1, buffer)) > 0)
        {
            if (aux.dato.dni==alumnito->dato.dni)
            {
                flag=1;
            }
        }
        if(flag == 1)
        {
            fseek(buffer,sizeof(alumno)*(-1), SEEK_CUR);
            fwrite(&aux,sizeof(alumno),1, buffer);
        }
        fclose(buffer);
    }
}

///VER ESTADO CONTABLE DE ALUMNO
void mostrarCuadroPagos (alumno alumnito)
{
    int cuotas[12];
    int i=0, y=3;

    for(i=0; i<12; i++)
    {
        cuotas[i]=i+1;
    }

    printf("ESTADO CONTABLE de %s, %s - DNI: %i\n", alumnito.dato.nombre, alumnito.dato.apellido, alumnito.dato.dni);
    gotoxy(50,2);
    color(143);
    printf("     CUOTA \t|\t ESTADO \t|\t VALOR \t\t");
    color(0);
    printf(".\n");
    for(i=0; i<12; i++)
    {
        gotoxy(50, y);
        color(15);
        if(alumnito.pagos[i]==1)
        {
            color(4);
            printf("Cuota %i \t|", cuotas[i]);
            color(64);
            printf("\tAdeuda \t\t");
            color(4);
            printf("|\t$%i", alumnito.cuotas[i]);
        }
        if(alumnito.pagos[i]==2)
        {
            color(2);
            printf("Cuota %i \t|", cuotas[i]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),32);
            printf("\tPagado \t\t");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
            printf("|\t$%i", alumnito.cuotas[i]);

        }
        if(alumnito.pagos[i]==0)
        {
            color(15);
            printf("Cuota %i \t|}", cuotas[i]);
            printf("\tPendiente \t\t");
            printf("|\t$%i", alumnito.cuotas[i]);
        }
        if(alumnito.pagos[i]==3)
        {
            color(6);
            printf("Cuota %i \t|", cuotas[i]);
            color(96);
            printf("\tPago parcial \t\t");
            color(6);
            printf("|\t$%i", alumnito.cuotas[i]);
        }
        y++;
        color(15);
        printf("\n");
    }
}

///REGISTRAR PAGO A PROFESOR
void registrarPagoSueldo (profesor* profe)
{
    int mes=0, flag=0;
    printf("1-ENERO\n 2-FEBRERO\n 3-MARZO\n 4-ABRIL\n 5-MAYO\n 6-JUNIO\n 7-JULIO\n 8-AGOSTO\n 9-SEPTIEMBRE\n 10-OCTUBRE\n 11-NOVIEMBRE\n 12-DICIEMBRE\n");
    printf("Acreditar pago correspondiente al mes:");
    scanf("%i", &mes);

    profe->estadoSueldo[mes-1]=1;

    FILE * buffer;
    profesor aux;
    buffer = fopen(ARCHIVOPROFESORES, "r+b" );
    if(buffer)
    {
        while (flag==0 && (fread(&aux, sizeof(profesor),1, buffer)) > 0)
        {
            if (aux.dato.dni==profe->dato.dni)
            {
                flag=1;
            }
        }
        if(flag == 1)
        {
            fseek(buffer,sizeof(alumno)*(-1), SEEK_CUR);
            fwrite(&aux,sizeof(alumno),1, buffer);
        }
        fclose(buffer);
    }
}

///VER ESTADO CONTABLE DE ALUMNO
void mostrarEstadoSueldo (profesor profe)
{
    int i=0;
    int mes[12];

    for(i=0; i<12; i++)
    {
        mes[i]=i+1;
    }

    printf("MES   \t| ESTADO \t\t| VALOR\n");
    for(i=0; i<12; i++)
    {
        if(profe.estadoSueldo[i]==1)
        {
            color(2);
            printf("%i \t|\t", mes[i]);
            printf("Pagado \t\t|\t");
            printf("$%i", profe.sueldo);

        }
        if(profe.estadoSueldo[i]==0)
        {
            color(15);
            printf("%i \t|\t", mes[i]);
            printf("Pendiente \t|\t");
            printf("$%i", profe.sueldo);
        }
        color(15);
        printf("\n");
    }
}

