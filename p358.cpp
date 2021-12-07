class Solution {
 public:
  int getSum(unsigned a, unsigned b) {
    while (b != 0) {                 
      const unsigned carry = a & b;  
      a ^= b;                        
      b = carry << 1;
    }
    return a;
  }
};