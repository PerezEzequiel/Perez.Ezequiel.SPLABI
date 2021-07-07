#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pais.h"
#define OK 1
#define ERROR 0

ePais* pais_new()
{
    ePais* paisAuxiliar = (ePais*)malloc(sizeof(ePais));

    if(paisAuxiliar!=NULL)
    {
        pais_setId(paisAuxiliar,0);
        pais_setNombre(paisAuxiliar,"");
        pais_setVac1Dosis(paisAuxiliar,0);
        pais_setVac2Dosis(paisAuxiliar,0);
        pais_setSinVacunar(paisAuxiliar,0);
    }

    return paisAuxiliar;
}

ePais* pais_newParametros(char* idStr,char* nombreStr,char* vac1DosisStr,char* vac2DosisStr,char* sinVacunarStr)
{
    ePais* paisAuxiliar = pais_new();

    if(paisAuxiliar!=NULL)
    {
        if(!(pais_setId(paisAuxiliar,atoi(idStr))
                && pais_setNombre(paisAuxiliar,nombreStr)
                && pais_setVac1Dosis(paisAuxiliar,atoi(vac1DosisStr))
                && pais_setVac2Dosis(paisAuxiliar,atoi(vac2DosisStr))
                && pais_setSinVacunar(paisAuxiliar,atoi(sinVacunarStr))))
        {
            paisAuxiliar = NULL;
        }
    }
    return paisAuxiliar;
}


int pais_setId(ePais* this,int id)
{
    int isOk = ERROR;
    if(this!=NULL && id > 0)
    {
        this->id = id;
        isOk = OK;
    }
    return isOk;
}
int pais_getId(ePais* this,int* id)
{
    int isOk = ERROR;
    if(this!=NULL && id != NULL)
    {
        *id = this->id;
        isOk = OK;
    }
    return isOk;
}


int pais_setNombre(ePais* this,char* nombre)
{
    int isOk = ERROR;
    if(this!=NULL && nombre != NULL &&  strlen(nombre)>= 3 && strlen(nombre)<20)
    {
        strcpy(this->nombre,nombre);
        isOk = OK;
    }
    return isOk;
}
int pais_getNombre(ePais* this,char* nombre)
{
    int isOk = ERROR;
    if(this!=NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        isOk = OK;
    }
    return isOk;
}


int pais_setVac1Dosis(ePais* this,int vac1Dosis)
{
    int isOk = ERROR;
    if(this!=NULL && vac1Dosis >= 0)
    {
        this->vac1Dosis = vac1Dosis;
        isOk = OK;
    }
    return isOk;
}
int pais_getVac1Dosis(ePais* this,int* vac1Dosis)
{
    int isOk = ERROR;
    if(this!=NULL && vac1Dosis != NULL)
    {
        *vac1Dosis = this->vac1Dosis;
        isOk = OK;
    }
    return isOk;
}





int pais_setVac2Dosis(ePais* this,int vac2Dosis)
{
    int isOk = ERROR;
    if(this!=NULL && vac2Dosis >= 0)
    {
        this->vac2Dosis = vac2Dosis;
        isOk = OK;
    }
    return isOk;
}
int pais_getVac2Dosis(ePais* this,int* vac2Dosis)
{
    int isOk = ERROR;
    if(this!=NULL && vac2Dosis != NULL)
    {
        *vac2Dosis = this->vac2Dosis;
        isOk = OK;
    }
    return isOk;
}

int pais_setSinVacunar(ePais* this,int sinVacunar)
{
    int isOk = ERROR;
    if(this!=NULL && sinVacunar >= 0)
    {
        this->sinVacunar = sinVacunar;
        isOk = OK;
    }
    return isOk;
}
int pais_getSinVacunar(ePais* this,int* sinVacunar)
{
    int isOk = ERROR;
    if(this!=NULL && sinVacunar != NULL)
    {
        *sinVacunar = this->sinVacunar;
        isOk = OK;
    }
    return isOk;
}
int mostrarPais(ePais* paisRecibido)
{
    int isOk = ERROR;
    int id;
    char nombre[20];
    int vac1Dosis;
    int vac2Dosis;
    int sinVacunar;

    if(paisRecibido!=NULL)
    {
        if(pais_getId(paisRecibido,&id) && pais_getNombre(paisRecibido,nombre) && pais_getVac1Dosis(paisRecibido,&vac1Dosis) && pais_getVac2Dosis(paisRecibido,&vac2Dosis) && pais_getSinVacunar(paisRecibido,&sinVacunar))
        {
            printf("%d %5s %d %d %d\n",id,nombre,vac1Dosis,vac2Dosis,sinVacunar);
        }
        isOk = OK;
    }
    return isOk;
}


int mostrarPaises(LinkedList* lista)
{
    int isOk = ERROR;
    int size;
    ePais* paisAuxiliar = NULL;

    if(lista!=NULL)
    {
        size = ll_len(lista);

        printf("Id Nombre Vac1 Vac2 SinVacunar\n");
        for(int i=0; i<size; i++)
        {
            paisAuxiliar = (ePais*)ll_get(lista,i);
            if(paisAuxiliar!=NULL)
            {
                mostrarPais(paisAuxiliar);
            }
        }

        isOk = OK;
    }
    return isOk;
}


void* aleatorioVacunas(void* paisRecibido)
{
    int numero1Dosis;
    int min1Dosis = 1;
    int max1Dosis = 60;


    int numero2Dosis;
    int min2Dosis = 1;
    int max2Dosis = 40;

    int numeroSinVacunar;

    ePais* aux=NULL;

    if(paisRecibido!=NULL)
    {
        numero1Dosis = rand() % (max1Dosis-min1Dosis+1) + min1Dosis;
        numero2Dosis = rand() % (max2Dosis-min2Dosis+1) + min2Dosis;
        numeroSinVacunar = 100-(numero1Dosis+numero2Dosis);

        aux = (ePais*)paisRecibido;

        if(!(pais_setVac1Dosis(aux,numero1Dosis) && pais_setVac2Dosis(aux,numero2Dosis) && pais_setSinVacunar(aux,numeroSinVacunar)))
        {
            aux = NULL;
        }
    }

    return (void*)aux;
}

int filterPaisHorno(void* p)
{
    int retorno = 0;
    ePais* aux=NULL;
    int vac1;
    int vac2;
    int noVacunados;
    if(p!=NULL)
    {
        aux = (ePais*) p;
        if(pais_getVac1Dosis(aux,&vac1) && pais_getVac2Dosis(aux,&vac2) && pais_getSinVacunar(aux,&noVacunados))
        {
            if(noVacunados>(vac1+vac2))
            {
                retorno = 1;
            }
        }
    }
    return retorno;
}

int filterPaisExitoso(void* p)
{
    int retorno = 0;
    ePais* aux = NULL;
    int vac2;
    if(p!=NULL)
    {
        aux = (ePais*) p;
        if(pais_getVac2Dosis(aux,&vac2))
        {
            if(vac2>30)
            {
                retorno = 1;
            }
        }
    }
    return retorno;
}

int pais_cmp1dosis(void* p1,void*p2)
{
    int retorno = 0;
    ePais* pais1Aux=NULL;
    ePais* pais2Aux=NULL;

    int paisUnoVac1;
    int paisDosVac1;

    if(p1!=NULL && p2 != NULL)
    {
        pais1Aux = (ePais*) p1;
        pais2Aux = (ePais*) p2;
        if(pais_getVac1Dosis(pais1Aux,&paisUnoVac1) && pais_getVac1Dosis(pais2Aux,&paisDosVac1))
        {
            if(paisUnoVac1>paisDosVac1)
            {
                retorno = 1;
            }
            else if(paisUnoVac1<paisDosVac1)
            {
                retorno = -1;
            }
        }
    }
    return retorno;
}
