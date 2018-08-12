class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        vector<int> res;
   		vector<int>& small = nums1, big = nums2;
        bool flag = nums1.size() < nums2.size();
        small = flag ? nums1 : nums2;
        big = flag ? nums2: nums1;
        auto its = small.begin();
        auto itb = big.begin();
        while (its != small.end()) {
        	if (*its == *itb) {
        		res.push_back(*its);
        		++its;
        		++itb;
        	} else {
        		++its;
        	}
        }
        return res;
    }
};
