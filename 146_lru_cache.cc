/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 /capacity/ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4

运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。

获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。

进阶:

你是否可以在 O(1) 时间复杂度内完成这两种操作？

示例:

LRUCache cache = new LRUCache( 2 /缓存容量/ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回  1
cache.put(3, 3);    // 该操作会使得密钥 2 作废
cache.get(2);       // 返回 -1 (未找到)
cache.put(4, 4);    // 该操作会使得密钥 1 作废
cache.get(1);       // 返回 -1 (未找到)
cache.get(3);       // 返回  3
cache.get(4);       // 返回  4
*/

struct CacheNode {
    int key;
    int val;
    CacheNode(int key, int val): key(key), val(val) {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        size_ = capacity;
    }
    
    int get(int key) {
        auto it = cmap_.find(key);
        if (it == cmap_.end()) return -1;
        clist_.splice(clist_.begin(), clist_, it->second);
        cmap_[key] = clist_.begin();
        return it->second->val;
    }
    
    void put(int key, int value) {
        auto it = cmap_.find(key);
        if (it == cmap_.end()) {
            if (clist_.size() == size_) {
                cmap_.erase(clist_.back().key);
                clist_.pop_back();
            }
            clist_.push_front(CacheNode(key, value));
            cmap_[key] = clist_.begin();
        } else {
            clist_.splice(clist_.begin(), clist_, it->second);
            cmap_[key] = clist_.begin();
            clist_.begin()->val = value;
        }
    }

private:
    list<CacheNode> clist_;
    unordered_map<int, list<CacheNode>::iterator> cmap_;
    int size_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */