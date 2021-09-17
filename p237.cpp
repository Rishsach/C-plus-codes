class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        bool valid = true;
        bool check[10];
        int value;
        
        for(int i = 0; i < 9; i++){
            memset(check, false, sizeof(check));
            for(int j = 0; j < 9; j++){
                value = board[i][j] - '0';
                if(value > 9 || value < 1)
                    continue;
                    
                if(!check[value])
                    check[value] = true;
                else
                    return false;
            }
        }
        
        for(int i = 0; i < 9; i++){
            memset(check, false, sizeof(check));
            for(int j = 0; j < 9; j++){
                value = board[j][i] - '0';
                if(value > 9 || value < 1)
                    continue;
                    
                if(!check[value])
                    check[value] = true;
                else
                    return false;
            }
        }
        
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                memset(check, false, sizeof(check));
                
                for(int k = 0; k < 3; k++){
                    for(int h = 0; h < 3; h++){
                        value = board[i * 3 + k][j * 3 + h] - '0';
                        if(value > 9 || value < 1)
                            continue;
                            
                        if(!check[value])
                            check[value] = true;
                        else
                            return false;
                    }
                }
            }
        }
        return true;
    }
};