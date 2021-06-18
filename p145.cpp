
#include <deque>
#include <iostream>
using namespace std;

int main()
{
	int sum = 0;
	deque<int> mydeque;
	mydeque.push_back(1);
	mydeque.push_back(8);
	mydeque.push_back(3);
	mydeque.push_back(6);
	mydeque.push_back(2);


	while (mydeque.size() > 0) {
		sum = sum + mydeque.front();
		mydeque.pop_front();
	}
	cout << sum;
	return 0;
}
