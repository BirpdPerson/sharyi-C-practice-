#pragma once
#include "Teacher.h"
/// Ученая степень
class DegreeDecorator : public Teacher
{
protected:
	Teacher* _teacher;

public:
	DegreeDecorator(Teacher* teacher)
	{
		_teacher = teacher;
	}

	~DegreeDecorator()
	{
		delete _teacher;
	}

	virtual double calculate()
	{
		auto experience = this->YearOfCommencement != 0 ? 2020 - this->YearOfCommencement : 0;
		return _teacher->calculate() + (static_cast<double>(experience) / 5 * 700);
	}
};

class CandidateSciences : public DegreeDecorator
{
public:
	CandidateSciences(Teacher* teacher)
		: DegreeDecorator(teacher)
	{
	}

	double calculate() override
	{
		return DegreeDecorator::calculate() + 700;
	}
};

class DoctorScience : public DegreeDecorator
{
public:
	DoctorScience(Teacher* teacher)
		: DegreeDecorator(teacher)
	{
	}

	double calculate() override
	{
		return DegreeDecorator::calculate() + 1200;
	}
};

/// Ученое звание
class AcademicTitleDecorator : public Teacher
{
protected:
	Teacher* _teacher;

public:
	AcademicTitleDecorator(Teacher* teacher)
	{
		_teacher = teacher;
	}

	~AcademicTitleDecorator()
	{
		delete _teacher;
	}

	virtual double calculate()
	{
		auto experience = this->YearOfCommencement != 0 ? 2020 - this->YearOfCommencement : 0;
		return _teacher->calculate() + (static_cast<double>(experience) / 5 * 700);
	}
};

class Docent : public AcademicTitleDecorator
{
public:
	Docent(Teacher* teacher)
		: AcademicTitleDecorator(teacher)
	{
	}

	double calculate() override
	{
		return AcademicTitleDecorator::calculate() + 2200;
	}
};

class Professor : public AcademicTitleDecorator
{
public:
	Professor(Teacher* teacher)
		: AcademicTitleDecorator(teacher)
	{
	}

	double calculate() override
	{
		return AcademicTitleDecorator::calculate() + 3500;
	}
};
