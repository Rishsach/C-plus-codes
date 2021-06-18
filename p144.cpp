
#include <deque>
#include <iostream>
using namespace std;

int main()
{
	deque<int> mydeque;
	mydeque.push_back(1);
	mydeque.push_back(2);
	mydeque.push_back(3);
	mydeque.push_back(4);
	mydeque.push_back(5);
	mydeque.push_back(6);
	mydeque.push_back(7);
	mydeque.push_back(8);
	mydeque.push_back(9);

	for (int i = 0; i < mydeque.size(); ++i) {
		if (i % 2 == 0) {
			cout << mydeque.at(i);
			cout << " ";
		}
	}
	return 0;
}
