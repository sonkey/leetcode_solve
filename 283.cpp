class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    	if (nums.size() < 2) return; 

    	auto it_zero = nums.begin();
    	auto it_move = nums.begin();

    	while (it_move != nums.end()) {
    		if (*it_zero == 0) {
    			it_move = it_zero;
    			while (it_move != nums.end() && *it_move == 0) {
    				it_move++;
    			}

    			if (it_move != nums.end()) 
    				std::swap(*it_zero, *it_move);
    		}
    		it_zero++;
    	}
    }
};
