class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        unordered_map<char, int>m;
        for(int i = 0; jewels[i] != '\0'; ++i){
            m[jewels[i]]++;
        }
        for(int i = 0; stones[i] != '\0'; ++i){
            if(m.find(stones[i]) != m.end()){
                count+=1;
            }
        }
        return count;
    }
};