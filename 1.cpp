class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	auto it = nums.begin();
    	auto iter = nums.begin();
    	bool flag = false;
        for (; it != nums.end(); ++it) {
        	int minus = target - *it;
        	for (iter = it+1; iter != nums.end(); ++iter) {
        		if (*iter == minus) {
        			flag = true;
        			break;
        		}
        	}
            if (flag) break;
        }

        vector<int> res{it-nums.begin(), iter-nums.begin()};
        return res;
    }
};
