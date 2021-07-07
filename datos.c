#include <stdio.h>
#include <stdlib.h>
#include "Datos.h"
#include "string.h"
#include "ctype.h"

int getString(char msg[],char msgError[],char cadena[], int tam)
{
    int retorno=0;
    char buffer[200];

    if(msg!=NULL && msgError != NULL && cadena != NULL)
    {

        printf("%s",msg);
        fflush(stdin);
        gets(buffer);


        while(validarBuffer(buffer,tam) != 1 || sonLetras(buffer) != 1)
        {
            printf("\n%s\n",msgError);
            printf("%s",msg);
            fflush(stdin);
            gets(buffer);
        }
        strcpy(cadena,buffer);
        retorno=1;
    }



    return retorno;
}

int getTelefono(char msg[],char msgError[],char cadena[], int tam)
{
    int retorno=0;
    char buffer[200];

    if(msg!=NULL && msgError != NULL && cadena != NULL)
    {

        printf("%s",msg);
        fflush(stdin);
        gets(buffer);


        while(validarBuffer(buffer,tam) != 1 || esNumero(buffer) != 0)
        {
            printf("\n%s\n",msgError);
            printf("%s",msg);
            fflush(stdin);
            gets(buffer);
        }
        strcpy(cadena,buffer);
        retorno=1;
    }



    return retorno;
}

int validarBuffer(char buffer[],int tamCadena)
{
    int retorno = 0;
    int len;
    len = strlen(buffer);
    if(len<=tamCadena-1 && buffer!=NULL)
    {
        retorno = 1;
    }
    return retorno;
}

int esNumero(char numero[])
{
    int i=0;
    int retorno=0;
    if(numero!=NULL)
    {
        if(numero[0] == '-')
        {
            i = 1;
        }
        for( ; i < strlen(numero) ; i++)
        {
            if(numero[i]<'0' ||  numero[i]>'9')
            {
                retorno = 1;
            }
            if(numero[i]=='.')
            {
                retorno = 0;
            }
        }
    }

    return retorno;
}

int getInt(char mensaje[], int* resultado,char mensajeError[])
{
    char buffer[20];
    int retorno=0;
    if(mensaje!=NULL && resultado!=NULL && mensajeError != NULL)
    {
        printf("%s",mensaje);
        fflush(stdin);
        scanf("%s",buffer);

        *resultado = esNumero(buffer);
        while(*resultado != 0)
        {
            printf("%s: ",mensajeError);
            fflush(stdin);
            scanf("%s",buffer);
            *resultado = esNumero(buffer);
        }
        *resultado = atoi(buffer);
        retorno = 1;
    }
    return retorno;
}

int getFloat(char mensaje[], float* resultado,char mensajeError[])
{
    char buffer[20];
    int retorno=0;
    if(mensaje!=NULL && resultado!=NULL && mensajeError != NULL)
    {
        printf("%s",mensaje);
        fflush(stdin);
        scanf("%s",buffer);

        retorno = esNumero(buffer);
        while(retorno != 0)
        {
            printf("%s: ",mensajeError);
            fflush(stdin);
            scanf("%s",buffer);
            retorno = esNumero(buffer);
        }
        *resultado = atof(buffer);
        retorno = 1;
    }
    return retorno;
}


int esLetra(char caracterRecibido)
{
    int retorno=0;
    if((caracterRecibido >= 65 && caracterRecibido<= 90) || (caracterRecibido >= 97 && caracterRecibido <= 122) || caracterRecibido == ' ')
    {
        retorno = 1;
    }

    return retorno;
}

int sonLetras(char cadena[])
{
    int i;
    int retorno=0;
    if(cadena!=NULL)
    {
        for(i=0; cadena[i]!='\0'; i++)
        {
            if(esLetra(cadena[i]) == 1)
            {
                retorno = 1;
            }
            else
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int getChar(char mensaje[],char* caracterRecibido,char mensajeError[])
{
    int retorno = 0;
    if(mensaje!=NULL && caracterRecibido != NULL && mensajeError != NULL)
    {
        printf("%s",mensaje);
        fflush(stdin);
        scanf("%c",caracterRecibido);
        while(esLetra(*caracterRecibido)!=1)
        {
            printf("%s",mensajeError);
            fflush(stdin);
            scanf("%c",caracterRecibido);
        }
        *caracterRecibido = tolower(*caracterRecibido);
        retorno = 1;
    }

    return retorno;
}

int getCaracter(char mensaje[],char* caracterRecibido,char mensajeError[],char mensajeErrorValidacion[],char primerCaracter,char segundoCaracter)
{
    int retorno = 0;
    if(mensaje != NULL && caracterRecibido != NULL && mensajeError != NULL && mensajeErrorValidacion != NULL)
    {
        while(getChar(mensaje,caracterRecibido,mensajeError) != 1 ||  (*caracterRecibido != primerCaracter && *caracterRecibido != segundoCaracter))
        {
            printf("%s\n", mensajeErrorValidacion);
        }
        retorno = 1;
    }

    return retorno;
}

int getEntero(char mensaje[],int* enteroRecibido,char mensajeError[],char mensajeErrorValidacion[],int minimo,int maximo)
{
    int retorno = 0;
    if(mensaje != NULL && enteroRecibido != NULL && mensajeError != NULL && mensajeErrorValidacion != NULL)
    {
        while(getInt(mensaje,enteroRecibido,mensajeError) != 1 || *enteroRecibido < minimo ||  *enteroRecibido > maximo)
        {
            printf("%s\n", mensajeErrorValidacion);
        }
        retorno = 1;
    }

    return retorno;
}

int validarRangoDeEnteros(int valor,int minimo,int maximo)
{
    int retorno=0;
    if(valor>=minimo && valor<=maximo)
    {
        retorno = 1;
    }
    return retorno;
}

int getFecha(int* dia, int* mes, int* anio)
{
    int retorno=0;
    int scanfRetorno;

    if(dia!=NULL && mes!=NULL && anio!=NULL)
    {
        printf("Ingrese fecha dd/mm/aa: ");
        scanfRetorno = scanf("%d/%d/%d",dia,mes,anio);

        while(scanfRetorno!=3 || !validarRangoDeEnteros(*dia,1,31) || !validarRangoDeEnteros(*mes,1,12) || !validarRangoDeEnteros(*anio,2000,2021))
        {
            printf("Error, Ingrese fecha dd/mm/aa: ");
            scanfRetorno = scanf("%d/%d/%d",dia,mes,anio);
        }
        retorno = 1;
    }

    return retorno;
}

