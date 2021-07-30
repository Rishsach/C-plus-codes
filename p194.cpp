class Solution {
public:
    vector<string> ans;
    void backtrack(string tmp,const int n, int left, int right){
	if(left == n && right == n){
		ans.push_back(tmp);		
		return ;
	}else{
		if(left<n)
			backtrack(tmp+"(",n ,left+1, right);
		if(right<left)
			backtrack(tmp+")",n ,left, right+1);
	}
    }
    vector<string> generateParenthesis(int n) {
        backtrack("",n, 0,0);
        return  ans;
    } 
};