class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();

    vector<long long> pref(n + 1, 0);

    for(int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + nums[i];

    long long ans = 0;

        for(int l = 0; l < n; l++) {
            for(int r = l; r < n; r++) {

                long long sum = pref[r + 1] - pref[l];

                if(sum % 10 != x) continue;

                long long t = sum;
                while(t >= 10) t /= 10;

                if(t == x) ans++;
            }
        }
    return ans;

    }
};