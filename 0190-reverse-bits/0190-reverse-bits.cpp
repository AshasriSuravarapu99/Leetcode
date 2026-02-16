class Solution {
public:
    int reverseBits(int n) {
        string s = "";
        for(int i = 1; i <= 32; i++){
            s+=(n%2)+'0';
            n = n/2;
        }
        int ans = stoi(s,nullptr,2);
        return ans;
    }
};