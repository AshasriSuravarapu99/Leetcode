class Solution {
public:
    void construct(string s, int n, vector<string> &res, int oc, int cc){
        if(oc == n && cc == n){
            res.push_back(s);
            return;
        }

        if(oc < n){
            construct(s+'(',n,res,oc+1,cc);
        }
        if(cc < oc){
            construct(s+')', n, res, oc, cc+1);
        }

        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        construct("",n,res,0,0);
        return res;
    }
};