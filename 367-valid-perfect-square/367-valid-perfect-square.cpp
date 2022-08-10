class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 1;
        while(i<=num){
               long long int sqrt = pow(i,2);
                if(sqrt == num){
                    return true;    
                }
                else{
                    i++;
                }
                if(sqrt>num){
                    break;
            }
            }
        return false;
            
        }
    
};