#include <iostream>
#include <string>

using namespace std;

//Класс СТУДЕНТ.
//Данные: ФИО, пол, год рождения, год поступления, номер зачетки, средний балл.
//Создать массив из 3 студентов и установить их личные данные с помощью сеттеров.
//Еще одного студента создать отдельно в куче и установить его данные в конструкторе с
//параметрами.В главной функции проимитировать три сессии – случайным образом
//сформировать по 4 новые оценки и пересчитать в отдельном методе средний балл.
//Вывести результаты студентов, отсортировав их в порядке убывания среднего балла


class Student
{

public:

    Student()
    {
    
    }
    Student(string FullName, string Gender, string Birthday, string YearOfReceipt, string NumberEnchantedBook, int GPA)
    {   
        this->FullName = FullName;
        this->Gender = Gender;
        this->Birthday = Birthday;
        this->YearOfReceipt = YearOfReceipt;
        this->NumberEnchantedBook = NumberEnchantedBook;
        this->GPA = GPA;
    }
    void SetFullName(string FullName)
    {   
        this->FullName = FullName;
    }
    void SetGender(string Gender)
    {
        this->Gender = Gender;
    }
    void SetBirthday(string Birthday)
    {
        this->Birthday = Birthday;
    }
    void SetYearOfReceipt(string YearOfReceipt)
    {
        this->YearOfReceipt = YearOfReceipt;
    }
    void SetEnchantedBook(string NumberEnchantedBook)
    {
        this->NumberEnchantedBook = NumberEnchantedBook;
    }
    void SetGPA(int* ArrayEstimates, int size)
    {
        int temp = 0;
        for (int i = 0; i < size; i++)
        {
            temp += ArrayEstimates[i];
        }
        GPA = temp / size;
    }
    int GetGPA()
    {
        return GPA;
    }
    void Print()
    {
        cout <<"FullName: \t" << FullName << "\nGender: \t" <<  Gender <<"\nBirthday \t" << Birthday << "\nYearOfReceipt \t" << YearOfReceipt << "\nNumberEnchantedBook: \t" << NumberEnchantedBook << "\nGPA: \t" << GPA << "\n" <<endl;
    }
        template<class Pred>
        static void bubbleSorting(Student* arr, int size, Pred pred)
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

private:
    string FullName;
    string Gender;
    string Birthday;
    string YearOfReceipt;
    string NumberEnchantedBook;
    int GPA;
};

int main()
{
    setlocale(0, "rus");
    Student s1;
    Student s2;
    Student s3;
    Student* s4 = new Student("ВАсерман Андрей Юрьевич", "мужской", "20.10.2020", "12.09.2020", "543", 212);


    int ArrayEstimatesS1[4];
    for (int i = 0; i < 4; i++)
    {
        ArrayEstimatesS1[i] = rand() % 100;
    }
    int ArrayEstimatesS2[4];
    for (int i = 0; i < 4; i++)
    {
        ArrayEstimatesS2[i] = rand() % 100;
    }
    int ArrayEstimatesS3[4];
    for (int i = 0; i < 4; i++)
    {
        ArrayEstimatesS3[i] = rand() % 100;
    }

    
    s1.SetFullName("Григорий Николай Николавич");
    s1.SetBirthday("10.10.2000");
    s1.SetEnchantedBook("564");
    s1.SetGender("мужской");
    s1.SetGPA(ArrayEstimatesS1,4);
    s1.SetYearOfReceipt("12.09.2020");

    s2.SetFullName("Чамрашный Евгений Анюткин");
    s2.SetBirthday("11.30.2001");
    s2.SetEnchantedBook("534");
    s2.SetGender("мужской");
    s2.SetGPA(ArrayEstimatesS2, 4);
    s2.SetYearOfReceipt("12.09.2020");

    s3.SetFullName("Головач Лена Ивановна");
    s3.SetBirthday("12.11.2000");
    s3.SetEnchantedBook("456");
    s3.SetGender("женски");
    s3.SetGPA(ArrayEstimatesS1, 4);
    s3.SetYearOfReceipt("12.09.2020");

    Student student[4];
    student[0] = s1;
    student[1] = s2;
    student[2] = s3;
    student[3] = *s4;
    
    Student::bubbleSorting(student, 4, [](Student s1, Student s2) {return s1.GetGPA() < s2.GetGPA(); });

    for (int i = 0; i < 4; i++)
    {
        student[i].Print();
    }

    delete s4;
}