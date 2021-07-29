class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++) {
            char top = st.empty() ? '#' : st.top();
            
            if(top == '(' && s[i] == ')') {
                st.pop();
            }else if(top == '{' && s[i] == '}') {
                st.pop();
            }else if(top == '[' && s[i] == ']') {
                st.pop();
            }else{
                st.push(s[i]);
            }    
        }
        
        return st.empty();
    }
};