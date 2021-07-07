#include <stdio.h>
#include <stdlib.h>
#include "files.h"
#include <string.h>
#define OK 1
#define ERROR 0



int file_verifyPathText(char path[])
{
    int isOk = ERROR;
    FILE* pFile;
    if(path != NULL)
    {
        pFile = fopen(path,"r");
        if(pFile != NULL)
        {
            isOk = OK;
        }
    }

    return isOk;
}

int file_verifyPathBinary(char path[])
{
    int isOk = ERROR;
    FILE* pFile;
    if(path != NULL)
    {
        pFile = fopen(path,"rb");
        if(pFile != NULL)
        {
            isOk = OK;
        }
    }
    return isOk;
}

int file_getPath(char msg[],char path[])
{
    int retorno = ERROR;

    if(msg != NULL)
    {
        printf("%s",msg);
        fflush(stdin);
        gets(path);

        retorno=OK;
    }
    return retorno;
}

int file_getAndValidatePath(char msg[],char path[],int textOrBinary)
{
    int isOk = ERROR;

    if(msg!=NULL && (textOrBinary == 0 || textOrBinary == 1))
    {
        file_getPath(msg,path);
        if(textOrBinary == 0)
        {
            if(file_verifyPathText(path))
            {
                isOk = OK;
            }
        }
        else
        {
            if(file_verifyPathBinary(path))
            {
                isOk = OK;
            }

        }
    }
    return isOk;
}
