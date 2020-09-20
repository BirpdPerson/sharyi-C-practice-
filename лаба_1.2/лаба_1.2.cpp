#include <iostream>

void printArray(double** mass){
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			//std::cout << mass[i][j] << "       ";
			std::cout << *(*(mass + i) + j) << "       ";
		}
		std::cout << std::endl;
	}
}

double* initArray() {
	double* mass = new double[25];
	for (int i = 0; i < 25; i++)
	{
		*(mass + i) = i * sin(3.14 * i / 25);
	}

	return mass;
}
double** convertArray(double* mass) {
	double** mass2 = new double* [5];
	for (int i = 0; i < 5; i++)
	{
		//mass2[i] = new double[5];
		*(mass2 + i) = new double[5];
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			*(*(mass2 + i) + j) = *(mass + (j + i));
		}
	}

	for (int i = 0; i < 5; i++)
	{
		double sum = 0;

		for (int j = 1; j < 5; j++)
		{
			sum += *(*(mass2 + i) + j);
		}

		*(*(mass2 + i) + 0) = sum;
	}

	return mass2;
}

int main()
{
	double* mass=initArray();

	double** mass2 = convertArray(mass);
	
	printArray(mass2);
	
	for (int i = 0; i < 5; i++)
	{
		delete[] mass2[i];
	}

	delete[] mass2, mass;
}
