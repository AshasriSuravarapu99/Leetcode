class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        string ans = "";
        int n = shifts.size();

        long long c = 0;

        for(int i = n - 1; i >= 0; i--) {
            c += shifts[i];

            int val = ((s[i] - 'a') + c) % 26;
            ans += char('a' + val);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};