class Solution {
public:
void solve(int open, int close, string path, vector<string>&v) {
        if(!open && !close) { v.push_back(path); return ; }
        if(open > 0) solve(open-1, close, path+"(", v);
        if(open < close) solve(open, close-1, path+")", v);
        
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>v;
        solve(n, n, "", v);
        return v;
    }
};