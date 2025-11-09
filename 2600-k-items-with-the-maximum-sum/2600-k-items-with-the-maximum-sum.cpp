class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        if(numOnes < k){
            if(numZeros+numOnes < k) return numOnes-(k-(numOnes+numZeros));
            return numOnes;
        }
        return k;
    }
};