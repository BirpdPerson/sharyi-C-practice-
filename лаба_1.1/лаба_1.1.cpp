﻿#include <iostream>
#include <cstdio> 

//Объявить массив из n=15 вещественных чисел, проинициализировать единицами.
//Функция processArray() должна домножить все элементы с четными индексами на
//случайное число из диапазона [a, b] (a и b ввести с клавиатуры, a < 0), подсчитать и
//вернуть количество отрицательных элементов массива и сформировать выходной
//массив, содержащий только отрицательные элементы входного (т.е. размерность
//уменьшится). Вывести на экран результирующие массивы.

int count = 0;

int* processArray(int* arr, int sizeMass) {

	int a, b;
	scanf_s("%d", &a);
	scanf_s("%d", &b);

	srand(NULL);


	for (int i = 0; i < sizeMass; i++)
	{
		int r = rand() % b + a;
		if (i % 2 == 0 && i > 0)
		{
			arr[i] = arr[i]*r;
		}

		//cout << "arr[" << i << "] " << arr[i] << endl;
		printf("arr[%d] = %d  \n", i, arr[i]);

		if (arr[i] < 0)
		{
			count = count + 1;
		}
	}

	int* arr2 = new int[count];

	for (int i = 0, j = 0; i < sizeMass; i++)
	{
		if (arr[i] < 0)
		{
			arr2[j] = arr[i];
			j++;
		}
	}

	return arr2;
}
int main()
{
    int* mass = new int[15];
	for (int i = 0; i < 15 ; i++)
	{
		mass[i] = 1;
	}

	int* a = processArray(mass, 15);

	//cout << "\nmass[i] < 0:   ";
	printf("\nmass[i]<0  ");

	for (int i = 0; i < count; i++)
	{
		/*cout << a[i] << " ";*/
		printf("%d  ", a[i]);
	}

	delete[] mass;
	delete a;
}

