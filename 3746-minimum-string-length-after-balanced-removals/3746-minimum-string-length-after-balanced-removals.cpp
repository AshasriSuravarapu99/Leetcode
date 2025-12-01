class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int a = 0, b = 0;
        int len = 0;
        for(int i=0;i<s.size();i++)
        {
            len++;
            if(s[i] == 'a') a++;
            else b++;
            if((a!=0 && b!=0) && a >= b)
            {
                int val = b;
                b=0;
                a = a-val;
                len-=(2*val);
            }
            else if((a!=0 && b!=0) && a<b)
            {
                int val = a;
                b-=val;
                a=0;
                len-=(2*val);
            }

        }
        return len;
    }
};