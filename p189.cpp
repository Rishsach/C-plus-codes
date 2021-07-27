class Solution {
public:
    int romanToInt(string s) {
        int i = 0; int result = 0;
        enum r {I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000};
        while(i < s.length())
        {
            switch(s[i])
            {
                case 'M': result += M; break;
                case 'D': result += D; break;
                case 'C':
                    if (s[i + 1] == 'D' ||
                        s[i + 1] == 'M' && 
                        i + 1 != s.size())
                        result -= C;
                    else
                        result += C;
                    break;
                case 'L': result += L; break;
                case 'X': 
                    if (s[i + 1] == 'L' ||
                        s[i + 1] == 'C' && 
                        i + 1 != s.size())
                        result -= X;
                    else
                        result += X;
                    break;
                case 'V': result += V; break;
                case 'I':
                    if (s[i + 1] == 'V' ||
                        s[i + 1] == 'X' &&
                        i + 1 != s.size())
                        result -= I;
                    else
                        result += I;
                    break;
                default:
                    break;
            }
            i++;
        }
        return result;
    }
};