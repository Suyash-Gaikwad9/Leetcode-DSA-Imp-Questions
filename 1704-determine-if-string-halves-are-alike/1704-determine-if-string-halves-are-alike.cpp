class Solution {
public:
    bool isVowel(char ch){
        if( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ){
            return true;
        }
        return false;
    }
    bool halvesAreAlike(string s) {
        int l = s.length();
        int c1 = 0, c2 = 0;
        for(int i = 0; i<l/2; i++){
            if(isVowel(s[i])){
                ++c1;
            }
        }
        for(int i = l/2; i<l; i++){
            if(isVowel(s[i])){
                ++c2;
            }
        }
        return c1==c2;
    }
};