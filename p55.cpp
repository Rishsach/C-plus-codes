
#include<iostream>
#include<iterator>
#include<vector>

using namespace std;

int main()
{
    vector<int> ar = { 1, 2, 3, 4, 5 };
    
   
    vector<int>::iterator ptr = ar.begin();
    
    advance(ptr, 3);
    
    cout << "The position of iterator after advancing is : ";
    cout << *ptr << " ";
    
    return 0;
    
}