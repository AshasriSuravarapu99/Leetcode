class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = s.size();
        int i = 0;
        int c =0 ;
        map<char,int>m;
        for(int j=0;j<l;j++)
        {
            m[s[j]]++;
            cout<<j<<" ";
            while(m['a']>0 && m['b']>0 && m['c']>0)
            {
                c+=l-j;
                m[s[i]]--;
                cout<<i<<"\n";
                i++;   
            }
            
        } 

        return c;
    }
};