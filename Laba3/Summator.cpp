#include "Summator.h"

Subtractor::Subtractor()
    : ExpressionEvaluator::ExpressionEvaluator()
{
}

Subtractor::Subtractor(size_t n) 
    : ExpressionEvaluator::ExpressionEvaluator(n)
{
}

void Subtractor::logToScreen()
{
    std::cout << this->joinOperands(" - ") << " = " << this->calculate() << "\n";
}

void Subtractor::logToFile(const std::string& fileName)
{
    std::ofstream ofs(fileName, std::ofstream::out | std::ofstream::app);
    ofs << this->joinOperands(" - ") +  " = " + std::to_string(this->calculate()) + "\n";
    ofs.close();
}

double Subtractor::calculate()
{
	double result = this->operands[0];

	for (size_t i = 1; i < this->countOperands; i++)
	{
		result -= this->operands[i];
	}

	return result;
}