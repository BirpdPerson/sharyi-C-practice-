#include "CustomExpressionEvaluator.h"

void CustomExpressionEvaluator::logToScreen()
{
	std::string str = "";

	for (size_t i = 0; i < this->countOperands; i++)
	{
		str += this->operands[i] >= 0 ? std::to_string(this->operands[i])
			: "(" + std::to_string(this->operands[i]) + ")";

		if (i != this->countOperands - 1)
			str += i % 2 == 0 && i != 1 ? " + " : " - ";
	}

	std::cout << str << " = " << this->calculate() << "\n";
}

void CustomExpressionEvaluator::logToFile(const std::string& fileName)
{
	std::string str = "";
	std::ofstream ofs(fileName, std::ofstream::out | std::ofstream::app);

	for (size_t i = 0; i < this->countOperands; i++)
	{
		str += this->operands[i] >= 0 ? std::to_string(this->operands[i])
			: "(" + std::to_string(this->operands[i]) + ")";

		if (i != this->countOperands - 1)
			str += i % 2 == 0 && i != 1 ? " + " : " - ";
	}

	ofs << str << " = " << this->calculate() << "\n";
	ofs.close();
}

template<class TItem, class Pred>
static void bubbleSorting(TItem*& arr, size_t size,  Pred pred)
{
	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			if (pred(arr[j], arr[j + 1]))
			{
				auto temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void CustomExpressionEvaluator::shuffle()
{
	shuffle(0, this->countOperands - 1);
}

void CustomExpressionEvaluator::shuffle(size_t i, size_t j)
{
		auto temp = this->operands[j];
		this->operands[j] = this->operands[i]*-1;
		this->operands[i] = temp*-1;
}

double CustomExpressionEvaluator::calculate()
{
    double result = 1;

	for (size_t i = 0; i < this->countOperands; i++)
	{
		if (this->operands[i]!=0)
		{
			result += this->operands[i] / (i+1);
		}
		else
		{
			result = 0;
		}
			
	}

    return result;
}
