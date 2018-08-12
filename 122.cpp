class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0 || prices.size() == 1)
        	return 0;

        int sum = 0;
        for (int i = 1; i < prices.size(); ++i) {
        	int minus = prices[i] - prices[i-1];
        	if (minus > 0) {
        		sum += minus;
        	}
        }

        return sum;
    }
};
