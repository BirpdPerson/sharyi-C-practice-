#include <iostream>
#include "Summator.h"
#include "Divisor.h"
#include "CustomExpressionEvaluator.h"
#include "Student.h"
#include "Teacher.h"
#include "Decorator.h"
//Задание 1
//Вид выражения CustomExpression : result = x1 + x2 / 2 + x3 / 3 + x4 / 4 + ...
//Порядок создания и инициализации объектов подклассов :
//CustomExpressionEvaluator: 6 операндов, присвоить группой 5, 16, -3, 10, 12, 2.
//Subtractor : 4 операнда, присвоить группой 5.6, -2.1, 3.2, 1.5.
//Multiplier : 3 операнда, присвоить поэлементно 1.5, -8, 2.5.
//Метод shuffle() – поменять местами первый и последний операнды и изменить их
//знак.Метод shuffle(size_t i, size_t j) – поменять местами i - ый и j - ый операнды и
//изменить их знак.
//Формат вывода :
//Operands: 4
//5.6 - (-2.1) - 3.2 - 1.5
//Result = 3

//Задание 2
//Класс СТУДЕНТ + классы ПРЕПОДАВАТЕЛЬ, ЛИЧНОСТЬ.
//Реализовать схему наследования классов и корректно распределить по классам данные :
//ФИО, пол, год рождения, год поступления, номер зачетки, средний балл, стаж, год
//начала работы в университете, должность, ученая степень, ученое звание.
//Интерфейс начислителя суммы оплаты труда ISalaryCalculation с методом double
//calculate() – рассчитать сумму за месяц.Реализация метода в классе преподавателей :
//сумма равна 5000 + 700 за научную степень кандидата наук(или + 1200 за степень
//доктора наук) + 2200 за звание доцента(или + 3500 за звание профессора) + 700 за
//каждые 5 лет стажа.Реализация метода в классе студентов – если средний балл выше
//4.5, то начислить 1000, иначе – 700. В main() создать 2 преподавателей и 2 студентов,
//продемонстрировать полиморфизм calculate().

void Log(ILoggable& s)
{
	s.logToScreen();
	s.logToFile("log.txt");
}

void print(Person* p)
{
	std::cout << p->get_FIO() << " Получает: " << p->calculate() << "\n";
}

int main()
{
	setlocale(0, "rus");
	double mass[]{ 5, 16, -3, 10, 12, 2 };

	Subtractor s(4);
	s.setOperand(0, 5.6);
	s.setOperand(1, -2.1);
	s.setOperand(2, 3.2);
	s.setOperand(3, 1.5);

	Log(s);

	Multiplier d(3);
	d.setOperand(0, 1.5);
	d.setOperand(1, -8);
	d.setOperand(2, 2.5);

	Log(d);

	CustomExpressionEvaluator c;
	c.setOperands(mass, 6);
	c.shuffle();

	Log(c);

	/// TODO: To make the facade
	Teacher* mainT1 = new DoctorScience(new Professor(new Teacher()));
	mainT1->set_FIO("Петрик Петр Яковлевич");
	mainT1->set_Gender("мужской");
	mainT1->set_Position("Преподаватель");
	mainT1->set_YearOfBirth("20.10.1967");
	mainT1->set_YearOfCommencement(2000);

	print(mainT1);

	Teacher* mainT2 = new CandidateSciences(new Docent(new Teacher()));
	mainT2->set_FIO("НАстюшина Анастасия Петровна");
	mainT2->set_Gender("Женский");
	mainT2->set_Position("Преподаватель");
	mainT2->set_YearOfBirth("01.01.1980");
	mainT2->set_YearOfCommencement(2010);

	print(mainT2);

	Student* mainS1 = new Student();
	mainS1->set_FIO("Гришин Максим игоревич");
	mainS1->set_Gender("мужской");
	mainS1->set_GPA(5);
	mainS1->set_SetOffBookNumber("12312");

	print(mainS1);

	Student* mainS2 = new Student();
	mainS2->set_FIO("Ломтик Андрей игоревич");
	mainS2->set_Gender("мужской");
	mainS2->set_GPA(4);
	mainS2->set_SetOffBookNumber("23521");

	print(mainS2);

	delete mainS1;
	delete mainS2;
	delete mainT1;
	delete mainT2;
}