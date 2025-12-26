class Solution {
public:
    int bestClosingTime(string s) {
        int n = s.size();
        vector<int>preN(n);
        vector<int>sufY(n);
        if(s[0] == 'N') preN[0]=1;
        else preN[0] = 0;
        if(s[n-1] == 'Y') sufY[n-1] = 1;
        else sufY[n-1] = 0;
        for(int i=1;i<n;i++){
            if(s[i] == 'N') preN[i] = 1+preN[i-1];
            else preN[i] = preN[i-1];
        }
        for(int i=n-2;i>=0;i--){
            if(s[i] == 'Y') sufY[i] = 1+sufY[i+1];
            else sufY[i] = sufY[i+1];
        }
        int ans = n;
        int mini = 0;
        for(int i=0;i<n;i++){
            if(s[i] == 'N') mini++;
        }
        for(int i=0;i<n;i++){
            int val = 0;
            if(s[i] == 'Y'){
                val+=preN[i];
                val+=sufY[i];
            } 
            else{
                val+=max(0,(preN[i]-1));
                val+=sufY[i];
            }
            if(mini > val){
                mini = val;
                ans = i;
            }
            else if(mini == val){
                ans = min(ans,i);
            }
        }
        cout<<mini;
        return ans;
    }
};