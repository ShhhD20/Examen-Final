#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimir (int Matriz[30][30], int num){
	for(int a = 0; a < num; a++){
		for(int b = 0; b < num; b++){
			printf("  %d", Matriz[a][b]);
		}
		printf("\n");
	}
	printf("\n\n");
}

int main (){
	double duracion = 0;
	int size = 30;
	srand(time(NULL));
	int Matriz1[30][30], Matriz2[30][30], Mfinal[30][30];
	int A[30][30];
	
	for(int a = 0; a < size; a++){
		for(int b = 0; b < size; b++){
			Matriz1[a][b] = rand() % 10;
			Matriz2[a][b] = rand() % 10;
			A[a][b] = rand() % 10;
		}
	}
	imprimir(Matriz1, size);
	imprimir(Matriz2, size);
	
	clock_t tic = clock();
	for(int c = 0; c < size; c++){
		for(int d = 0; d < size; d++){
			for(int e = 0; e < size; e++){
				Mfinal[d][e] = 0;
				for(int f = 0; f < size; f++){
					Mfinal[d][e] += Matriz1[d][f] * Matriz2[f][e];
				}
			}
		}
	}
	clock_t toc = clock();
	imprimir(Mfinal, size);
	duracion = (double)(toc - tic) / CLOCKS_PER_SEC;
	printf("Duracion de la operacion: %lf milisgundos\n", duracion*1000);
	
	return 0;
}
