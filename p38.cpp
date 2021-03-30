
#include <iostream>
using namespace std;

#define OUT 0
#define IN 1

unsigned countWords(char *str)
{
	int state = OUT;
	unsigned wc = 0; 
	while (*str)
	{
		
		if (*str == ' ' || *str == '\n' || *str == '\t')
			state = OUT;

		
		else if (state == OUT)
		{
			state = IN;
			++wc;
		}

		++str;
	}

	return wc;
}

int main(void)
{
	char str[] = "One two	 three\n four\tfive ";
	cout<<"No of words : "<<countWords(str);
	return 0;
}