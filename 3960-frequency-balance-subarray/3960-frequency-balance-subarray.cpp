class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {

            unordered_map<int, int> freq;
            unordered_map<int, int> freqCnt;

            for (int j = i; j < n; j++) {

                int x = nums[j];

                int oldFreq = freq[x];

                if (oldFreq > 0) {
                    freqCnt[oldFreq]--;

                    if (freqCnt[oldFreq] == 0) {
                        freqCnt.erase(oldFreq);
                    }
                }

                freq[x]++;

                int newFreq = freq[x];
                freqCnt[newFreq]++;

                // Only one distinct value
                if (freq.size() == 1) {
                    ans = max(ans, j - i + 1);
                }
                // Two frequencies exist
                else if (freqCnt.size() == 2) {

                    auto it = freqCnt.begin();

                    int f1 = it->first;
                    ++it;
                    int f2 = it->first;

                    int mn = min(f1, f2);
                    int mx = max(f1, f2);

                    if (mx == 2 * mn) {
                        ans = max(ans, j - i + 1);
                    }
                }
            }
        }

        return ans;
    }
};