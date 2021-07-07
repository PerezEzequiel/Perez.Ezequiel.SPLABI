#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "pais.h"
#include "parser.h"
#include "datos.h"
#include "files.h"
#include "Controller.h"
#include "menu.h"
#define OK 1
#define ERROR 0



int controller_loadFromText(char* path, LinkedList* pArrayList)
{
    int isOk = ERROR;
    FILE* archivoText = NULL;
    char confirma;

    if(path!=NULL && pArrayList!=NULL)
    {
        archivoText = fopen(path,"r");
        if(archivoText!=NULL)
        {
            if(ll_len(pArrayList)>0)
            {
                getCaracter("La lista ya contiene elementos, desea sobreescribirlos?s/n: ",&confirma,"Error ingrese un caracter: ","Error,ingrese s o n: ",'s','n');

            }
            if(confirma == 's' || ll_len(pArrayList)<=0)
            {
                parser_EmployeeFromText(archivoText,pArrayList);
            }
            fclose(archivoText);
        }
        isOk = OK;
    }

    return isOk;
}


int controller_ListPaises(LinkedList* pArrayList)
{
    int isOk = ERROR;

    if(pArrayList!=NULL)
    {
        if(mostrarPaises(pArrayList))
        {
            isOk=OK;
        }
    }
    return isOk;
}

int controller_mapVacunas(LinkedList* pArrayList)
{
    int isOk = ERROR;
    if(pArrayList!=NULL)
    {
        pArrayList = ll_map(pArrayList,aleatorioVacunas);
        if(pArrayList!=NULL)
        {
            isOk = OK;
        }
    }
    return isOk;
}
int controller_saveFilterHorno(char*path,LinkedList* pArrayList)
{
    int isOk = ERROR;
    LinkedList* filter=NULL;

    if(path!=NULL && pArrayList!=NULL)
    {
        filter = ll_filter(pArrayList,filterPaisHorno);
        if(controller_saveAsText(path,filter))
        {
            printf("Lista guardada con exito.\n");
            ll_deleteLinkedList(filter);
        }

        isOk = OK;
    }
    return isOk;
}


int controller_saveAsText(char* path, LinkedList* pArrayList)
{
    int isOk = ERROR;
    FILE* archivoTexto;
    char respuesta;

    ePais* paisAux=NULL;
    int id;
    char nombre[20];
    int vac1Dosis;
    int vac2Dosis;
    int sinVacunar;

    int size;

    if(path!=NULL && pArrayList != NULL)
    {
        if(file_verifyPathText(path))
        {
            getCaracter("*****CUIDADO*****\nEste archivo ya existe. Desea sobreescribir los cambios?s/n: ",&respuesta,"Error, ingrese un caracter: ","Error,ingrese s o n: ",'s','n');
        }
        if(!file_verifyPathText(path) || respuesta == 's')
        {
            archivoTexto = fopen(path,"w");

            if(archivoTexto!=NULL)
            {
                fprintf(archivoTexto,"Id,Nombre,Vac1,Vac2,SinVacunar\n");
                size = ll_len(pArrayList);
                for(int i=0; i<size; i++)
                {
                    paisAux = (ePais*)ll_get(pArrayList,i);

                    if(pais_getId(paisAux,&id)
                    && pais_getNombre(paisAux,nombre)
                    && pais_getVac1Dosis(paisAux,&vac1Dosis)
                    && pais_getVac2Dosis(paisAux,&vac2Dosis)
                    && pais_getSinVacunar(paisAux,&sinVacunar))
                    {
                        fprintf(archivoTexto,"%d,%s,%d,%d,%d\n", id,nombre,vac1Dosis,vac2Dosis,sinVacunar);
                    }
                }
                fclose(archivoTexto);
            }
        }

        isOk = OK;
    }

    return isOk;
}


int controller_sortPais(LinkedList* pArrayList)
{
    int isOk = ERROR;
    int order;

    if(pArrayList!=NULL)
    {
        getEntero("Como desea ordenar?1.asc || 0. desc: ",&order,"Error, ingrese un numero","Error ingrese 1 o 0",0,1);
        if(!ll_sort(pArrayList,pais_cmp1dosis,order))
        {
            isOk = OK;
        }
    }
    return isOk;
}


int controller_paisCastigado(LinkedList* pListEmployee)
{
    int isOk = ERROR;
    int size;
    int sinVacunar;
    int mayor;

    char nombreAux[20];

    ePais* paisAux = NULL;

    if(pListEmployee!=NULL)
    {
        size = ll_len(pListEmployee);
        for(int i=0;i<size;i++)
        {
            paisAux = (ePais*)ll_get(pListEmployee,i);
            if(pais_getSinVacunar(paisAux,&sinVacunar))
            {
                if(i==0 || sinVacunar > mayor)
                {
                    mayor = sinVacunar;
                }
            }
        }
        paisAux=NULL;
        printf("\n\n****Paises mas castigados con %d personas sin vacunar****\n\n",mayor);
        for(int i=0;i<size;i++)
        {
            paisAux = (ePais*)ll_get(pListEmployee,i);
            if(pais_getSinVacunar(paisAux,&sinVacunar) && pais_getNombre(paisAux,nombreAux))
            {
                if(sinVacunar == mayor)
                {
                   printf("****%s*****\n",nombreAux);
                }
            }
        }
        printf("\n\n");
        paisAux=NULL;
        isOk = OK;
    }
    return isOk;
}


int controller_saveFilterExitoso(char*path,LinkedList* pArrayList)
{
    int isOk = ERROR;
    LinkedList* filter=NULL;

    if(path!=NULL && pArrayList!=NULL)
    {
        filter = ll_filter(pArrayList,filterPaisExitoso);
        if(controller_saveAsText(path,filter))
        {
            printf("Lista guardada con exito.\n");
        }

        isOk = OK;
    }
    return isOk;

}
