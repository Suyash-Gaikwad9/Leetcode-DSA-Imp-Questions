class Solution {
public:
    bool isPalindrome(int x) {
        string reve = to_string(x);
        reverse(reve.begin(), reve.end());
        return to_string(x) == reve;
    }
};