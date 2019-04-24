// https://leetcode-cn.com/problems/kth-largest-element-in-a-stream/

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        size_ = k;
        for (auto c : nums) {
            if (heap_.size() < size_) {
                heap_.push(c);
            } else {
                if (c  < heap_.top()) continue;
                heap_.pop();
                heap_.push(c);
            }
        }
    }
    
    int add(int val) {
        if (heap_.size() < size_) {
            heap_.push(val);
            return heap_.top();
        }
        
        if (val > heap_.top()) {
            heap_.pop();
            heap_.push(val);
        }
        return heap_.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> heap_;
    int size_;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */