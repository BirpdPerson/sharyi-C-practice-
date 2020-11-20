#include "Divisor.h"

Multiplier::Multiplier() 
    : ExpressionEvaluator::ExpressionEvaluator()
{
}

Multiplier::Multiplier(size_t n)
    : ExpressionEvaluator::ExpressionEvaluator(n)
{
}

void Multiplier::logToScreen()
{
    std::cout << this->joinOperands(" * ") << " = " << this->calculate() << "\n";
}

void Multiplier::logToFile(const std::string& fileName)
{
    std::ofstream ofs(fileName, std::ofstream::out | std::ofstream::app);
    ofs << this->joinOperands(" * ") + " = " + std::to_string(this->calculate()) + "\n";
    ofs.close();
}

double Multiplier::calculate()
{
    double result = 1;

    for (size_t i = 0; i < this->countOperands; i++)
    {
        if (this->operands[i] == 0)
        {
            return NULL;
        }

        result *= this->operands[i];
    }

    return result;
}
