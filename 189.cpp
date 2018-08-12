class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int pivot = nums.size() - k % nums.size();

        PartialRotate(nums, 0, pivot);
        PartialRotate(nums, pivot, nums.size());
        PartialRotate(nums, 0, nums.size());
    }

private:
	void PartialRotate(vector<int>& nums, int begin, int end) {
		int first = begin;
		int last = end - 1;
		while (first < last) {
			std::swap(nums[first], nums[last]);
			first++;
			last--;
		}
	}
};
