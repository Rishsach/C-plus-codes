class Solution {
public:
    int climbStairs(int n) {
        if(n==0) return 0;
        int i=1, fn2=1, fn1=1, fn=1;
        while(i++<n)
            fn = fn1 + fn2, fn2 = fn1, fn1 = fn;
        return fn;
    }
};