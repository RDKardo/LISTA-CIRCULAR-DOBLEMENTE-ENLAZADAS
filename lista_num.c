#include <stdio.h>
#include "operaciones_circular_doble.h"

int main()
{
	struct nodo lista;
	int valor;
	int valor_antes;

	inicializar(&lista);

	printf("Escriba un numero, al escribir -1 se terminará la lista\n");
	while(valor != -1){
		scanf("%d", &valor);
		if(valor != -1)
		insertar_al_final(&lista,valor);
	}
	printf("Escriba un numero\n");
	scanf("%d", &valor);
	printf("escribe el valor que estara antes del valor introducido\n");
	imprimir_lista(&lista);
	printf("\n");
	scanf("%d", &valor_antes);
	insertar_despues_de(&lista, valor, valor_antes);
	imprimir_lista(&lista);
	borrar_lista(&lista);
	return 0;
}
