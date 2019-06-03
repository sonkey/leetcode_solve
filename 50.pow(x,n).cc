// https://leetcode-cn.com/problems/powx-n/

//c++
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 1) return x;
        if (n < 0) return 1/myPow(x, -n);
        if (n % 2) return myPow(x, n / 2)* myPow(x, n / 2) * x;
        return myPow(x, n/2) * myPow(x, n/2);
    }
};

//go
func myPow(x float64, n int) float64 {
    if n == 1 {
        return x
    }
    if n < 0 {
        return 1/myPow(x, n)
    }
    if n % 2 {
        return myPow(x, n / 2) * myPow(x, n / 2) * x
    }
    return myPow(x, n / 2) * myPow(x, n / 2)
}