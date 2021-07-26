
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string digitToChar[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        queue<string> result;
        result.push("");
        while (true){
            string top = result.front();
            int iter = top.size();
            if (iter >= digits.size()) break;
            
            for (int i = 0; i < digitToChar[digits[iter] - '2'].size(); i++){
                result.push(top + digitToChar[digits[iter] - '2'][i]);
            }
            result.pop();
        }
        
        vector<string> res;
        while(result.empty() == false){
            res.push_back(result.front());
            result.pop();
        }
        return res;
    }
};