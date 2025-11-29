class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       int c = nums.size()/3;
       vector<int>ans;
    //    sort(nums.begin(),nums.end());
    //    int val = nums[0];
    //    int count = 1;
    //    for(int i=1;i<nums.size();i++)
    //    {
    //        if(nums[i] == val) count++;
    //        else
    //        {
    //             if(count > c) ans.push_back(val);
    //             val = nums[i];
    //             count = 1;
    //        }
    //    }
    //    if(count > c) ans.push_back(val);


     int c1 = 0, c2 = 0;
     int a,b;
     for(int i=0;i<nums.size();i++)
     {
        if(c1 == 0 && b!=nums[i])
        {
            a = nums[i];
            c1++;
        }
        else if(c2 == 0 && a!=nums[i])
        {
            b = nums[i];
            c2++;
        }
        else if(a == nums[i]) c1++;
        else if(b == nums[i]) c2++;
        else 
        {
            c1--;
            c2--;
        }
     } 
     c1 = 0 , c2 = 0;
     for(int i=0;i<nums.size();i++)
     {
        if(nums[i] == a) c1++;
        if(nums[i] == b) c2++;
     }
     if(c1 > c) ans.push_back(a);
     if(c2 > c) ans.push_back(b);
       return ans;
    }
};