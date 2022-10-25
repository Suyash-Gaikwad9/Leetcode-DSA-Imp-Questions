class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string x, y;
        x = "";
        y = "";
        for(int i = 0; i<word1.size(); i++){
            x+= word1[i];
        }
        for(int j = 0; j<word2.size(); j++){
            y+= word2[j];
        }
        return x==y;
    }
};