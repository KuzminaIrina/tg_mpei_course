//https://leetcode.com/problems/powx-n/
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1.0;
        if(n < 0)
            return 1/(x * myPow(x, -(n+ 1)));
        double p = myPow(x, n/2);
        return n & 1 ? p * p * x : p * p;
    }
};
