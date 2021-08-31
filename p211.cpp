class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1){
            return x;
        }

        int start = 2, end = x, middle;

        while(start <= end){
            middle = start + (end - start)/2;

            if(middle == x/middle){
                return middle;
            }

            if(middle < x/middle){
                start = middle + 1;
            } else {
                end = middle - 1;
            }
        }

        if(start > x/start){
            return start - 1;
        }

        return start;
    }
};