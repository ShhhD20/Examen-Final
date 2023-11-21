#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble (int lista[10000], int size){
	int flag = 0, temp = 0;
	for(int a = 1; a < size; a++){
		flag = 0;
		for(int b = 0; b < size-a ;b++){
			if(lista[b] > lista[b+1]){
				flag = 1;
				temp = lista[b];
				lista[b] = lista[b+1];
				lista[b+1] = temp;
			}
		}
	if(flag == 0)
		break;
	}
}

void insert (int lista[10000], int size){
	int act = 0, prev = 0;
	for (int a = 0; a < size; a++){
		act = lista[a];
		prev = a - 1;
		while(prev >= 0 && lista[prev] > act){
			lista[prev + 1] = lista[prev];
			prev--;
		}
		lista[prev+1] = act;
	}
}

int partir(int lista[10000], int high, int low){
	int tope = lista[high];
	int pIndex = low;
	int temp = 0;
	
	for (int a = low; a < high; a++){
		if (lista[a] <= tope){
			temp = lista[pIndex];
			lista[pIndex] = lista[a];
			lista[a] = temp;
			pIndex++;
		}
	}
	temp = lista[pIndex];
	lista[pIndex] = lista[high];
	lista[high] = temp;
	
	return pIndex;
}

void quick (int lista[10000], int high, int low){
	if(low >= high){
		return;
	}
	int pivote = partir(lista, low, high);
	quick(lista, pivote - 1, low);
	quick(lista, high, pivote + 1);
	
}

int main(){
	srand(time(NULL));
	int size = 10000;
	int arreglo[size];
	double dur, durAvg = 0, durMax = 0, durMin = 0;
	
	for(int a = 0; a < size; a++){
		arreglo[a] = rand() % 10000;
	}
	
	for(int b = 0; b < size; b++){
		clock_t tic = clock();
		bubble(arreglo, size);
		clock_t toc = clock();
		durAvg += (double)(toc - tic) / CLOCKS_PER_SEC;
		dur = (double)(toc - tic) / CLOCKS_PER_SEC;
		if(b == 0){
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
	printf("Duracion promedio de Bubble sort: %lf milisgundos\n", dur/10000);
	printf("Duracion minima de Bubble sort: %lf milisgundos\n", durMin);
	printf("Duracion maxima de Bubble sort: %lf milisgundos\n", durMax);
	printf("----------------------\n");
	
	durAvg = 0; durMax = 0; durMin = 0;
	for(int c = 0; c < size; c++){
		clock_t tic = clock();
		insert(arreglo, size);
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
	printf("Duracion promedio de Insertion sort: %lf milisgundos\n", dur/10000);
	printf("Duracion minima de Insertion sort: %lf milisgundos\n", durMin);
	printf("Duracion maxima de Insertion sort: %lf milisgundos\n", durMax);
	printf("----------------------\n");
	
	durAvg = 0; durMax = 0; durMin = 0;
	for(int c = 0; c < size; c++){
		clock_t tic = clock();
		quick(arreglo, size - 1, 0);
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
	printf("Duracion promedio de Quick sort: %lf milisgundos\n", dur/10000);
	printf("Duracion minima de Quick sort: %lf milisgundos\n", durMin);
	printf("Duracion maxima de Quick sort: %lf milisgundos\n", durMax);
	printf("----------------------\n");
	
	return 0;
}
