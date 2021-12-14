class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int firstNeg = -1, lastZero = -1;
        int negCount = 0;
        int ans = 0;
        
        int n = nums.size();
        
        for(int i = 0; i < n; ++i){
            int e = nums[i];
            
            if(e < 0){
                ++negCount;
                if(firstNeg == -1)
                    firstNeg = i;
            }
            
            if(e == 0){
                lastZero = i;
                negCount = 0;
       
                firstNeg = -1;
            }else{
     
                if(!(negCount&1)){
                   
                    ans = max(ans, i-lastZero);
                }else{
                    
                    ans = max(ans, i-firstNeg);
                }
            }
        }
        
        return ans;
    }
};