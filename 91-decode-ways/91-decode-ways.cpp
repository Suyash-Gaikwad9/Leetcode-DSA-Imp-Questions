class Solution
{
    public:

        int a[102];
    int decode(string &s, int index, int n)
    {
        if (index < n && s[index] == '0') return 0;
        if (index >= n)
            return 1;

        if (a[index] != -1) return a[index];

        int ans = 0;

       	// Pick single
        if (s[index] != '0') ans = decode(s, index + 1, n);

       	// Pick couple
        if (index + 1 < n && ((s[index] == '1' && s[index + 1] <= '9') || 
                              (s[index] == '2' && s[index + 1]<'7')))
            ans += decode(s, index + 2, n);

        return a[index] = ans;
    }

    int numDecodings(string s)
    {

        int n = s.size();
        memset(a, -1, sizeof(a));
        return decode(s, 0, n);
    }
};