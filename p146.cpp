
#include <deque>
#include <iostream>
using namespace std;

int main()
{
	deque<int> mydeque;
	mydeque.push_back(8);
	mydeque.push_back(7);
	mydeque.push_back(6);
	mydeque.push_back(5);
	mydeque.push_back(4);
	mydeque.push_back(3);
	mydeque.push_back(2);
	mydeque.push_back(1);


	if (mydeque.front() > mydeque.back()) {
		cout << mydeque.front() - mydeque.back();
	}
	else if (mydeque.front() < mydeque.back()) {
		cout << mydeque.back() - mydeque.front();
	}
	else
		cout << "0";
}
