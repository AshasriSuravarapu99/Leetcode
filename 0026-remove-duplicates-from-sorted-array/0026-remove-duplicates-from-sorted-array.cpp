class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
           int temp = nums[0];
           int ind = 1;
           for(int i=1;i<nums.size();i++)
           {
             int curr = nums[i];
             if(temp!=curr)
             {
                nums[ind]=curr;
                ind+=1;
                 temp=curr;

             }
            
           }
       return ind; 
    }
};