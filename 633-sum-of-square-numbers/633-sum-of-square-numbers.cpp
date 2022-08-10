class Solution {
public:
    bool judgeSquareSum(int c) {
       if(c<0)
           return false;
           
           long int l = 0;
           long int r = sqrt(c);
           
       
        while(l<=r){
            long int cur = l*l+r*r;
            
            if(cur<c){
                l++;
            }
            else if(cur>c){
                r--;
            }
            else{
                return true;
            }
        }
        
        
        
        
        
        return false;        
        
    }
};