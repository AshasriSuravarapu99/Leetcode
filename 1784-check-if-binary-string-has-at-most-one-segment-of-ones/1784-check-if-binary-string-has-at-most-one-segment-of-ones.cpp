class Solution {
public:
    bool checkOnesSegment(string s) {
       int c = 0;
       int st = -1 , e = -1;
       for(int i = 0; i < s.size(); i++){
           if(s[i] == '1'){
                 c++;
                if(st == -1) st = i;
                e = i;
           }
       }
       return ((e-st+1) == c);
    }
};