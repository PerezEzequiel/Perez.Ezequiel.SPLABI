#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "pais.h"
#include <string.h>
#define OK 1
#define ERROR 0

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int isOk = ERROR;
    ePais* paisAuxiliar=NULL;
    char id[20];
    char nombre[128];
    char vac1Dosis[20];
    char vac2Dosis[20];
    char sinVacunar[20];


    if(pFile!=NULL && pArrayListEmployee != NULL)
    {
        ll_clear(pArrayListEmployee);
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,vac1Dosis,vac2Dosis,sinVacunar); // Falsa lectura.
        while(!feof(pFile))
        {
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,vac1Dosis,vac2Dosis,sinVacunar)==5)
            {
                paisAuxiliar = pais_newParametros(id,nombre,vac1Dosis,vac2Dosis,sinVacunar);
                ll_add(pArrayListEmployee,paisAuxiliar);
            }
            else
            {
                break;
            }
        }
        isOk = OK;
    }
    return isOk;

}

/*int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int isOk = ERROR;
    eBicicleta* bicicletaAux=NULL;


    if(pFile != NULL && pArrayListEmployee !=NULL)
    {
        ll_clear(pArrayListEmployee);
        while(!feof(pFile))
        {
            bicicletaAux = bicicleta_new();
            if(fread(bicicletaAux,sizeof(eBicicleta),1,pFile)<1)
            {
                break;
            }
            else
            {
                ll_add(pArrayListEmployee,bicicletaAux);
                bicicletaAux = NULL;
            }
        }
        isOk = OK;
    }

    return isOk;
}*/
