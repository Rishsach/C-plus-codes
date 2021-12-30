class Solution {
    public:
        int maxPower(string s){
            char prev = s[0];
            int maxi =  0;
            int cnt = 0;
            for(auto &it :s){
                if(it  == prev ) cnt += 1;
                else {
                    cnt = 1;
                }
                maxi = max(cnt, maxi);
                prev = it;
            }
            return maxi;
        }
};