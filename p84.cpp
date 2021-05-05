#include <bits/stdc++.h>
using namespace std;

#define MAX_COUNT 10000

vector<string> vec;

void generateNumbersUtil()
{
	queue<string> q;
	q.push("9");
	
	for (int count = MAX_COUNT; count > 0; count--)
	{
		string s1 = q.front();
		q.pop();
		vec.push_back(s1);
		
		string s2 = s1;
		
		q.push(s1.append("0"));
		q.push(s2.append("9"));
	}
}

string findSmallestMultiple(int n)
{
	for (int i = 0; i < vec.size(); i++)

		if (stoi(vec[i])%n == 0)
			return vec[i];		
}

int main()
{
	generateNumbersUtil();	
	int n = 7;	
	cout << findSmallestMultiple(n);	
	return 0;
}
