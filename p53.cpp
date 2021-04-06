
#include <iostream> 
#include <vector> 

using namespace std; 

int main() 
{ 
    vector<int> v; 
     
    for (int i = 1; i <= 5; i++) 
        v.push_back(i); 

    cout << "Size : " << v.size(); 
    
    if (v.empty() == false) 
        cout << "\nVector is not empty"; 
    else
        cout << "\nVector is empty"; 

    cout << "\nOutput of begin and end: "; 
    for (auto i = v.begin(); i != v.end(); ++i) 
        cout << *i << " "; 
    
    v.emplace(v.begin(), 5); 
    cout << "\nThe first element is: " << v[0]; 
  
    v.emplace_back(20); 
    int n = v.size(); 
    cout << "\nThe last element is: " << v[n - 1]; 
  
    v.clear(); 
    cout << "\nVector size after erase(): " << v.size();     

    return 0; 
} 
