#pragma once
#include "string"
#define PROPERTIES(type, var)  protected: type var; \
	public: type get_##var() const { return var; } \
            void set_##var(type val) { var = val; }

class ISalaryCalculation
{
public:
	virtual double calculate() = 0;
};

class Person : public ISalaryCalculation
{
public:
	PROPERTIES(std::string, FIO);
	PROPERTIES(std::string, Gender);
	PROPERTIES(std::string, YearOfBirth);
};