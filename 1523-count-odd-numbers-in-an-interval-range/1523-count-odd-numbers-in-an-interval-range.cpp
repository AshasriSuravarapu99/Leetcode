class Solution {
public:
    int countOdds(int low, int high) {
        int len = (high-low)+1;
        if(low%2 == 0 && high % 2 == 0) return (len/2);
        else if(low%2 !=0 && high%2 != 0) return ceil(len/2.0);
        return len/2;
    }
};