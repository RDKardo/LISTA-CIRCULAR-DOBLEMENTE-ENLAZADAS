#include <stdio.h>
#include "operaciones_circular_doble.h"

int main()
{
	int valor;
	struct nodo lista;
	inicializar(&lista);
	while(valor != -1){
		printf("Escribe un numero\n");
		scanf("%d", &valor);
        if (valor != -1)
		insertar_al_final(&lista,valor);
	}

	imprimir_lista(&lista);
	borrar_lista(&lista);

	return 0;
}
