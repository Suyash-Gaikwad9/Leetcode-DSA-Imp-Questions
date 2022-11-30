class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> res;
        res.push_back({});
        int col, row=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ') //If whitespace is encountered
            {
                col++;
                row=0;
                continue;
            }
            if(row>=res.size()) //Insert new row
                res.push_back({});
            if(res[row].size()<col) 
                res[row].append(string(col-res[row].size(), ' '));
            res[row++].push_back(s[i]);
        }
        return res;
    }
};