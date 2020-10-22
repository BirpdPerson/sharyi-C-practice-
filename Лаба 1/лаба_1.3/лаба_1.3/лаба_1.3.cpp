#include <iostream>
#include <cstring>
#include <cstdio>

int main()
{
	char i;
	//std::cin >> i;
	scanf_s("%c", &i);
	auto s = strchr("string", i);
	//std::cout << s;
	printf("%s", s);

}

char* strchr(char* s, char c) {
	int move = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] = c)
		{
			move = i;
			break;
		}
	}

	return s + move;
}