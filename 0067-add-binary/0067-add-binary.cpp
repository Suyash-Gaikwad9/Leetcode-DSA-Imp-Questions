class Solution {
public:
    string addBinary(string a, string b) {
        int aLen = a.length();
        int bLen = b.length();
        int i = 0, carry = 0;
        string ans = "";

        while(i < aLen || i < bLen || carry != 0){
            int x = 0;
            if(i < aLen && a[aLen - i - 1] == '1'){
                x = 1;
            }
            int y = 0;
            if(i < bLen && b[bLen - i - 1] == '1'){
                y = 1;
            }
            ans = to_string((x+y+carry)%2) + ans;
            carry = (x+y+carry) / 2;
            i+=1;
        }
        
        return ans;
    }
};