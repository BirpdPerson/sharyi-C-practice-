#include <iostream>
#include <cstring>
#include <iostream>
#include <cstring>
#include <cstdio>

//Функция strchr.
//Формат char* strchr(char* s, int c).
//Функция находит в строке s первое вхождение символа с и возвращает подстроку,
//начинающуюся с этого символа.
char* strchr(char* s, char c);

int main()
{
	char* str = new char[255];
	std::cin >> str;
	char i;
	std::cin >> i;
	//scanf_s("%c", &i);
	auto s = strchr(str, i);
	//std::cout << s;
	printf("%s", s);

}

char* strchr(char* s, char c) {
	int move = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == c)
		{
			move = i;
			break;
		}
	}

	return s + move;
}