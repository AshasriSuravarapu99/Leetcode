class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n == 1) return s;
        long long p = s+m;
        long long rem = n/2 - 1;
        long long ans = p + (rem * (m-1));
        return ans; 
    }
};