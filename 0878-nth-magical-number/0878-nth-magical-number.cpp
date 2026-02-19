class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long l = min(a,b);
        long long  h = n * 1LL * min(a,b);
        long long ans = LLONG_MAX;
        long long mod = 1e9 + 7;
        while(l <= h){
            long long mid = l + (h - l)/2;
            long long div_by_a = mid/a;
            long long div_by_b = mid/b;
            long long lcm = (a*b)/__gcd(a,b);
            long long cnt = (div_by_a + div_by_b) - (mid/lcm);

            if(n <= cnt){
                h = mid - 1;
                ans = mid;
            }
            else l = mid + 1;
            
        }
        return ans % mod;
    }
};