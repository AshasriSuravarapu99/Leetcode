class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
          map<int,int>m;
          int n = nums.size();
          int dup;
          int mi;
          for(int i=0;i<n;i++) m[nums[i]]++;
          for(int i=1;i<=n;i++)
          {
              if(m.find(i) != m.end() && m[i] == 2) dup = i;
              if(m.find(i) == m.end()) mi = i;
          }
          return {dup,mi};
    }
};