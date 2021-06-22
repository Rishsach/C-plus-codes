
#include <cstring>
#include <iostream>
using namespace std;
void printPatternUtil(const char str[],
					char buff[], int i,
							int j, int n)
{
	if (i == n)
	{
		buff[j] = '\0';
		cout << buff << endl;
		return;
	}
	buff[j] = str[i];
	printPatternUtil(str, buff, i + 1, j + 1, n);

	buff[j] = ' ';
	buff[j + 1] = str[i];

	printPatternUtil(str, buff, i + 1, j + 2, n);
}

void printPattern(const char* str)
{
	int n = strlen(str);

	char buf[2 * n];

	buf[0] = str[0];

	printPatternUtil(str, buf, 1, 1, n);
}

int main()
{
	const char* str = "ABCD";
	printPattern(str);
	return 0;
}
