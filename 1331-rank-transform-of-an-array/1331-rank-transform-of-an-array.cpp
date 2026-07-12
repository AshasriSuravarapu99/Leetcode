class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> s(arr.begin(),arr.end());
        map<int,int> mpp;
        int rank=1;
        vector<int>res;
        for(int i:s)
        {
            mpp[i]=rank++;
        }
        for(int i:arr)
        {
            res.push_back(mpp[i]);
        }
       return res;
        
    }
};