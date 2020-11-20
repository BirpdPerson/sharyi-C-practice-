#pragma once
#include "Person.h"
class Teacher : public Person
{
public:
	PROPERTIES(std::string, Experience);
	PROPERTIES(int, YearOfCommencement);
	PROPERTIES(std::string, Position)

		double calculate() override
	{
		return 5000;
	}
};