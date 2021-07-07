#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"
#include "datos.h"
#include "menu.h"
#include "Controller.h"
#include "files.h"
#include "pais.h"
#define TEXT 0
#define BIN 1

int main()
{
    srand(time(NULL));
    char banderaSalir = 'n';
    int opcion;
    char path[100];
    LinkedList* miLista = ll_newLinkedList();
    do
    {

       system("cls");
        mostrarMenuInt("\n****Segundo parcial lab****\n\n1. Cargar archivo.\n2. Imprimir lista.\n3. Asignar estadisticas.\n4. filtrar por paises exitosos.\n5. filtrar por paises en el horno.\n6. ordenar por nivel de vacunacion.\n7. mostrar mas castigado\n8. Salir\nQue desea hacer?: ",&opcion);
        switch(opcion)
        {
        case 1:
            if(file_getAndValidatePath("Ingrese path csv: ",path,TEXT))
            {
                if(controller_loadFromText(path,miLista))
                {
                    printf("Opcion 1 con exito.\n");
                }
            }
            else
            {
                printf("Path csv invalido.\n");
            }
            break;
        case 2:
            system("cls");
            if(controller_ListPaises(miLista))
            {
                printf("Opcion 2 con exito.\n");
            }
            else
            {
                printf("Error en la opcion 2.\n");
            }
            break;
        case 3:
            if(controller_mapVacunas(miLista))
            {
                printf("Opcion 3 con exito.\n");
            }
            break;
        case 4:
                if(controller_saveFilterExitoso(path,miLista))
                {
                    printf("Opcion 4 con exito.\n");
                }
                else
                {
                    printf("Error en la opcion 4.\n");
                }

            break;
        case 5:
                if(controller_saveFilterHorno(path,miLista))
                {
                    printf("Opcion 5 con exito.\n");
                }
                else
                {
                    printf("Error en la opcion 5.\n");
                }

            break;
        case 6:
            if(controller_sortPais(miLista))
            {
                printf("Opcion 6 con exito.\n");
            }
            else
            {
                printf("Error en la opcion 6.\n");
            }
            break;
        case 7:
            if(controller_paisCastigado(miLista))
            {
                printf("Opcion 7 con exito.\n\n");
            }
            else
            {
                printf("Error en la opcion 7.\n");
            }
            break;
        case 8:
            getCaracter("Desea salir? s/n: ",&banderaSalir,"Error, ingrese un caracter: ","Error,ingrese s/n",'s','n');
            break;
        }
        system("pause");
    }
    while(banderaSalir!='s');

    ll_deleteLinkedList(miLista);
    return 0;
}
