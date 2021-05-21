
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
class Stack{
	
	int cnt;
	priority_queue<pair<int, int> > pq;
public:
	Stack():cnt(0){}
	void push(int n);
	void pop();
	int top();
	bool isEmpty();
};

void Stack::push(int n){
	cnt++;
	pq.push(pi(cnt, n));
}
void Stack::pop(){
	if(pq.empty()){ cout<<"Nothing to pop!!!";}
	cnt--;
	pq.pop();
}

int Stack::top(){
	pi temp=pq.top();
	return temp.second;
}

bool Stack::isEmpty(){
	return pq.empty();
}

int main()
{
	Stack* s=new Stack();
	s->push(1);
	s->push(2);
	s->push(3);
	while(!s->isEmpty()){
		cout<<s->top()<<endl;
		s->pop();
	}
}
