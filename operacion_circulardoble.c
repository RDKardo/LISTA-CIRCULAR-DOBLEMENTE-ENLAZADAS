de <stdio.h>
#include <stdlib.h>
#include "operaciones_circular_doble.h"

void inicializar(struct nodo *cabecera)
{
	cabecera->sig = cabecera;
	cabecera->ant = cabecera;
}

void borrar_lista(struct nodo *cabecera)
{
	struct nodo *actual;
	struct nodo *borrar;

	/* Si es diferente de cabecera borrar lista */
	if (cabecera->sig != cabecera) {
		actual = cabecera->sig;
		borrar = cabecera->sig;
		/* Mientras el siguiente sea diferente de cabecera */
		while ( actual->sig != cabecera) {
			actual = actual->sig;
			free(borrar);
			borrar = actual;
		}
		free(borrar);
		cabecera->sig = cabecera;
		cabecera->ant = cabecera;
	}
}

void insertar_al_final(struct nodo *cabecera, int valor_nuevo)
{
	struct nodo *nuevo;
	struct nodo *actual;
	nuevo = (struct nodo*) malloc(sizeof(struct nodo) * 1);
	nuevo->val = valor_nuevo;
	nuevo->sig = cabecera;
    if(cabecera->sig == cabecera){
        cabecera->sig = nuevo;
	nuevo->ant = cabecera;
	nuevo->sig = cabecera;
	cabecera->ant = nuevo;
    }
    else{
            actual = cabecera->sig;
            while(actual->sig != cabecera){
                actual = actual->sig;
		}
        actual->sig = nuevo;
	nuevo->ant = actual;
	cabecera->ant = nuevo;
	}

}

void insertar_al_principio(struct nodo *cabecera, int valor_nuevo)
{
	struct nodo *nuevo;
	nuevo = (struct nodo*) malloc(sizeof(struct nodo) * 1);
	nuevo->val = valor_nuevo;
	
	nuevo->sig = cabecera->sig;
	nuevo->ant = cabecera;

	cabecera->sig->ant = nuevo;
	cabecera->sig = nuevo;
}

void imprimir_lista(struct nodo *cabecera)
{
	struct nodo *actual;
	if(cabecera->sig != cabecera){
		actual = cabecera->sig;
		while (actual->sig != cabecera){
			printf("%d <-> ", actual->val);
			actual = actual->sig;
		}
	printf("%d", actual->val);
	}
}

void insertar_despues_de(struct nodo *cabecera, int valor_nuevo, int valor_antes)
{
	struct nodo *nuevo;
	struct nodo *actual;
	nuevo = (struct nodo*) malloc(sizeof(struct nodo) * 1);
	nuevo->val = valor_nuevo;

	if(cabecera->sig != cabecera){
		actual = cabecera->sig;
		while(actual->sig != cabecera){
			if (actual->val == valor_antes){
				nuevo->sig = actual->sig;
				actual->sig->ant = nuevo;
				actual->sig = nuevo;
				nuevo->ant = actual;
			}
			actual = actual->sig;
		}
	}
}

void eliminar_nodo(struct nodo *cabecera, int buscando)
{
	struct nodo *borrar;
	struct nodo *lista;
	lista = cabecera;
	if(lista->sig != NULL){
		while (lista->sig->val != buscando){
			lista = lista->sig;
		}
		borrar = lista->sig;
		lista->sig = borrar->sig;
		borrar->sig->ant = lista;
		free(borrar);
	}
}
