/*
Implement a data structure supporting the following operations:

Inc(Key) - Inserts a new key with value 1. Or increments an existing key by 1. Key is guaranteed to be a non-empty string.
Dec(Key) - If Key's value is 1, remove it from the data structure. Otherwise decrements an existing key by 1. If the key does not exist, this function does nothing. Key is guaranteed to be a non-empty string.
GetMaxKey() - Returns one of the keys with maximal value. If no element exists, return an empty string "".
GetMinKey() - Returns one of the keys with minimal value. If no element exists, return an empty string "".
Challenge: Perform all these in O(1) time complexity.

实现一个数据结构支持以下操作：

Inc(key) - 插入一个新的值为 1 的 key。或者使一个存在的 key 增加一，保证 key 不为空字符串。
Dec(key) - 如果这个 key 的值是 1，那么把他从数据结构中移除掉。否者使一个存在的 key 值减一。如果这个 key 不存在，这个函数不做任何事情。key 保证不为空字符串。
GetMaxKey() - 返回 key 中值最大的任意一个。如果没有元素存在，返回一个空字符串""。
GetMinKey() - 返回 key 中值最小的任意一个。如果没有元素存在，返回一个空字符串""。
挑战：以 O(1) 的时间复杂度实现所有操作。
*/

class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {}
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (m_.find(key) == m_.end()) {
            if (list_.empty() || list_.begin()->num != 1) {
                list_.push_front({1, {key}});
                m_[key] = list_.begin();
            } else {
                list_.front().keys.insert(key);
                m_[key] = list_.begin();
            }
            return;
        }

        auto it = m_[key];
        auto current = it++;
        if (it == list_.end()) {
            //list_.push_back({current->num+1, {key}});
            it = list_.insert(it, {current->num+1, {key}});
            m_[key] = it;
        } else {
            if (it->num != current->num+1) {
                it = list_.insert(it, {current->num+1, {key}});
            } else {
                it->keys.insert(key);
            }
            m_[key] = it;
        }
        current->keys.erase(key);
        if (current->keys.empty()) list_.erase(current);
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (m_.find(key) == m_.end()) return;
        auto it = m_[key];
        
        if (it->num == 1) {
            it->keys.erase(key);
            m_.erase(key);
            if (it->keys.empty()) list_.erase(it);
            return;
        }

        auto current = it--;
        if (current == list_.begin() || it->num != current->num-1) {
            it = list_.insert(current, {current->num-1, {key}});
            m_[key] = it;
        } else {
            it->keys.insert(key);
            m_[key] = it;
        }
        current->keys.erase(key);
        if (current->keys.empty()) list_.erase(current);
    }

    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return list_.empty() ? "" : *(list_.back().keys.begin());
    }
                                         
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return list_.empty() ? "" : *(list_.front().keys.begin());
    }

private:
    struct Bucket { int num; unordered_set<string> keys; };
    list<Bucket> list_;
    unordered_map<string, list<Bucket>::iterator> m_;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */