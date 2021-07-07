#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ctype.h"
#include "menu.h"


void mostrarMenuChar(char opciones[],char* pRespuesta)
{
    if(opciones!=NULL && pRespuesta !=NULL)
    {
        printf("%s", opciones);
        fflush(stdin);
        scanf("%c",pRespuesta);
        *pRespuesta = tolower(*pRespuesta);
    }
    else
    {
        printf("Error menu\n");
    }

}

void mostrarMenuInt(char opciones[],int* pRespuesta)
{
    if(opciones!=NULL && pRespuesta !=NULL)
    {
        printf("%s", opciones);
        scanf("%d",pRespuesta);
    }
    else
    {
        printf("Error menu\n");
    }

}


