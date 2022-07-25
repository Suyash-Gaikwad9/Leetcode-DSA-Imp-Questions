class Solution {
public:
    int bitwiseComplement(int n) {
        
        
        //edge case
        if(n==0){
            return 1;
        }
        
        int m = n;
        int mask = 0;
        while(m!=0){
            mask = (mask<<1) | 1;
            m = m>>1;
        }
        
        int answer = (~n)&mask;
        
        return answer;
        
    }
};