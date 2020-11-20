#pragma once
#include "Person.h"
class Student : public Person
{
public:
	PROPERTIES(std::string, SetOffBookNumber);
	PROPERTIES(double, GPA);

	double calculate() override
	{
		if (GPA > 4.5)
			return 1000;
		else
		{
			return 700;
		}
	}
};
