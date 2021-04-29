
#include <bits/stdc++.h>
using namespace std;

void identifyParenthesis(string a)
{
	stack<int> st;

	for (int i = 0; i < a.length(); i++) {

		if (a[i] == '(')
			st.push(i);
		
		else if (a[i] == ')') {

		
			if (st.empty())
				a.replace(i, 1, "-1");
			
			else {

				
				a.replace(i, 1, "1");
				a.replace(st.top(), 1, "0");
				st.pop();
			}
		}
	}

	while (!st.empty()) {
		a.replace(st.top(), 1, "-1");
		st.pop();
	}
	cout << a << endl;
}

int main()
{
	string str = "(a))";
	identifyParenthesis(str);
	return 0;
}
