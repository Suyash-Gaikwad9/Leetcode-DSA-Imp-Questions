class Solution {
public:
    int minFlips(string target) {
        int cnt = 0;
        char ch = '0';
        for(int i = 0; i<target.length(); i++){
            if(ch != target[i]){
                ch = target[i];
                cnt++;
            }
        }
        return cnt;
    }
};