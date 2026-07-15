class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return std::gcd((n*(n+1)),n*n);
        
    }
};