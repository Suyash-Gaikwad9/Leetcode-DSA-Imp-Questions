class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int ansIndex = 0;
        int n = chars.size();
        while(i<n){
            int j = i+1;
            while(j<n && chars[i]==chars[j]){
                j++;
            }
            //code will come here if vector is fully travered or you get a diffrent character
            
            
            //store the old character
            chars[ansIndex++] = chars[i];
            
            int count = j-i;
            
            if(count>1){
                //convert count which could be of two digits and asve it as character in ans
                string cnt = to_string(count);
                for(char ch: cnt){
                    chars[ansIndex++] = ch;
                }
                //move to next charachter
                
            }
            i=j;
        }
        return ansIndex;
    }
};