#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int secuencial (int lista[], int size){
	int num = rand() % 50000;
	for (int a = 0; a < size; a++){
		if (lista[a] == num){
			break;
		}
	}
}
int binaria (int lista[], int low, int high){
	int num = rand() % 50000;
	int mitad = (low + high) / 2;
	while(low <= high){
		if(lista[mitad] < num){
			low = mitad + 1;
		}else if(lista[mitad] == num){
			break;
		} else{
			high = mitad - 1;
		}
		mitad = (low + high) / 2;
	}
}

int main (){
	int size = 50000;
	int arreglo[size];
	int act, prev;
	srand(time(NULL));
	for(int a = 0; a < size; a++){
		arreglo[a] = rand() % 50000;
	}
	for (int b = 0; b < size; b++){
		act = arreglo[b];
		prev = b - 1;
		while(prev >= 0 && arreglo[prev] > act){
			arreglo[prev + 1] = arreglo[prev];
			prev--;
		}
		arreglo[prev+1] = act;
	}

	
	double dur, durAvg = 0, durMax = 0, durMin = 0;
	for(int c = 0; c < size; c++){
		clock_t tic = clock();
		secuencial(arreglo, size);
		clock_t toc = clock();
		durAvg += (double)(toc - tic) / CLOCKS_PER_SEC;
		dur = (double)(toc - tic) / CLOCKS_PER_SEC;
		if(c == 0){
			durMin = dur;
			durMax = dur;
		}
		if(durMin > dur){
			durMin = dur;
		}
		if(durMax < dur){
			durMax = dur;
		} 
	}
	durAvg = durAvg*1000; durMin = durMin*1000; durMax = durMax*1000; //*/
	printf("Duracion promedio de Busqueda Secuencial: %lf milisegundos\n", durAvg/10000);
	printf("Duracion minima de Busqueda Secuencial: %lf milisegundos\n", durMin);
	printf("Duracion maxima de Busqueda Secuencial: %lf milisegundos\n", durMax);
	printf("----------------------\n");
	
	durAvg = 0; durMax = 0; durMin = 0;
	for(int c = 0; c < size; c++){
		clock_t tic = clock();
		binaria(arreglo, 0, size-1);
		clock_t toc = clock();
		durAvg += (double)(toc - tic) / CLOCKS_PER_SEC;
		dur = (double)(toc - tic) / CLOCKS_PER_SEC;
		if(c == 0){
			durMin = dur;
			durMax = dur;
		}
		if(durMin > dur){
			durMin = dur;
		}
		if(durMax < dur){
			durMax = dur;
		}
	}
	durAvg = durAvg*1000; durMin = durMin*1000; durMax = durMax*1000;
	printf("Duracion promedio de Busqueda Binaria: %lf milisegundos\n", durAvg/10000);
	printf("Duracion minima de Busqueda Binaria: %lf milisegundos\n", durMin);
	printf("Duracion maxima de Busqueda Binaria: %lf milisegundos\n", durMax);
	printf("----------------------\n"); //*/
	
	return 0;
}
