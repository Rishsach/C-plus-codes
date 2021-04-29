
#include <bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 26;

bool adjSign(string s, int i)
{
	if (i == 0)
		return true;
	if (s[i - 1] == '-')
		return false;
	return true;
};

void eval(string s, vector<int>& v, bool add)
{
	stack<bool> stk;
	stk.push(true);


	int i = 0;
	while (s[i] != '\0') {
		if (s[i] == '+' || s[i] == '-') {
			i++;
			continue;
		}
		if (s[i] == '(') {

			if (adjSign(s, i))
				stk.push(stk.top());
			else
				stk.push(!stk.top());
		}

		else if (s[i] == ')')
			stk.pop();
		
		else {
			if (stk.top())				
				v[s[i] - 'a'] += (adjSign(s, i) ? add ? 1 : -1 :
												add ? -1 : 1);

			
			else				
				v[s[i] - 'a'] += (adjSign(s, i) ? add ? -1 : 1 :
												add ? 1 : -1);
		}
		i++;
	}
};

bool areSame(string expr1, string expr2)
{
	vector<int> v(MAX_CHAR, 0);

	eval(expr1, v, true);

	eval(expr2, v, false);

	for (int i = 0; i < MAX_CHAR; i++)
		if (v[i] != 0)
			return false;

	return true;
}

int main()
{
	string expr1 = "-(a+b+c)", expr2 = "-a-b-c";
	if (areSame(expr1, expr2))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}
