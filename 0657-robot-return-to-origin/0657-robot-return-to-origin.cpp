class Solution {
public:
    bool judgeCircle(string moves) {
        int i=0 , j=0;
        for(int k=0;k<moves.size();k++)
        {
            if(moves[k] == 'L') i++;
            if(moves[k] == 'R') i--;
            if(moves[k] == 'U') j++;
            if(moves[k] == 'D') j--;
        }
        if(j == 0 && i==0) return true;
        return false;
    }
};