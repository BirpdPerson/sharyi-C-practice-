#include <iostream>
#include <cstdio> 
#include "Vector.cpp"


int main()
{
	Vector<double> vector(25);

	for (int i = 0; i < 25; i++)
	{
		vector[i] = i * sin(3.1415926535 * i / 25);
		std::cout << vector[i] << "  ";
	}
	std::cout << std::endl;
	
	Matrix<double> matrix = vector.convert(25);

	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			std::cout << matrix[i][j] << "  ";
		}

		std::cout << std::endl;
	}
}





