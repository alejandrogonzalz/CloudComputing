#include <iostream>
#include <omp.h>

#define N 10000
#define chunk 1000
#define mostrar 11

void imprimeArreglo(float* d);

int main() {
	std::cout << "Tarea 1. Alejandro Gonzalez Almazan - A00517113\n";
	std::cout << "\n";
	std::cout << "Sumando arreglos en paralelo!\n";
	float a[N], b[N], c[N];
	int i;

	for (i = 0; i < N; i++) {
		a[i] = i;
		b[i] = i + 10;
	}

	int pedazos = chunk;


#pragma omp parallel for shared(a, b, c, pedazos) private(i) schedule(static, pedazos)
	for (i = 0; i < N; i++)
		c[i] = a[i] + b[i];

	std::cout << "Imprimiendo los primeros " << mostrar << " valores de arreglo a: " << std::endl;
	imprimeArreglo(a);

	std::cout << "Imprimiendo los primeros " << mostrar << " valores de arreglo b " << std::endl;
	imprimeArreglo(b);

	std::cout << "Imprimiendo los primeros " << mostrar << " valores de arreglo c: " << std::endl;
	imprimeArreglo(c);
}

void imprimeArreglo(float* d) {
	for (int x = 0; x < mostrar; x++) {
		std::cout << d[x] << " - ";
	}
	std::cout << std::endl;
}