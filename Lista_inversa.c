#include <stdio.h>
#include "operaciones_circular_doble.h"

int main()
{
	struct nodo lista;
	int valor;
	
	inicializar(&lista);
	while(valor != -1){
		printf("escribe un numero\n");
		scanf("%d", &valor);
		if(valor != -1)
			insertar_al_principio(&lista, valor);
	}
	imprimir_lista(&lista);
	borrar_lista(&lista);

	return 0;
}
