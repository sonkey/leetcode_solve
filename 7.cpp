class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0;
        bool negative = false;

        if (x < 0) {
            x = -x;
            negative = true;
        }
        
        long long res = 0;
        while (x > 0) {
        	res += (x % 10);
        	res *= 10;
        	x /= 10;
        } 

        res = res / 10;
        
        if (res > numeric_limits<int>::max()) return 0;
        if (negative) res = -res;
        return res;
    }
};
