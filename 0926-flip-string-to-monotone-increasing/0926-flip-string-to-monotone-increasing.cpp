class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int one = 0;
        int flip = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '1'){
                one++;
            }
            if(s[i] == '0'){
                if(one > 0){
                    flip++;
                }
            }
            if(one < flip){
                flip = one;
            }
        }
        return flip;
        
    }
};