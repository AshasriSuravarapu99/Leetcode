class Solution {
public:
    void construct(string &s, int n, vector<string> &res, int oc, int cc) {
        if (oc == n && cc == n) {
            res.push_back(s);
            return;
        }
        if (oc < n) {
            s.push_back('(');
            construct(s, n, res, oc + 1, cc);
            s.pop_back(); 
        }
        if (cc < oc) {
            s.push_back(')');
            construct(s, n, res, oc, cc + 1);
            s.pop_back(); 
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s = "";
        construct(s, n, res, 0, 0);
        return res;
    }
};