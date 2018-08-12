class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        auto iter = res.begin();
        bool flag = true;
        for (auto it = digits.crbegin(); it != digits.crend(); ++it) {
        	int num;
        	num = flag ? (*it + 1) : *it;
        	if (num == 10) {
        		iter = res.insert(iter, 0);
        		flag = true;
        	} else {
        		iter = res.insert(iter, num);
        		flag = false;
        	}
        }

        if (flag) res.insert(iter, 1);
        return res;
    }
}; 
