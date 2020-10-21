
class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        auto it = m_.find(key);
        //找看看KEY是否已經存在
        if(it == m_.cend()){
            return -1;
        }
        //如果存在就將這個key往前
        cache_.splice(cache_.begin(), cache_, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = m_.find(key);
        //如果KEY已經存在就把值更新後將KEY提前後返回
        if(it != m_.cend()){
            it->second->second = value;
            cache_.splice(cache_.begin(), cache_, it->second);
            return;
        }
        //如果快取滿了就把在快取的最後一個元素移除
        if(cache_.size() == capacity_){
            auto node = cache_.back();
            m_.erase(node.first);
            cache_.pop_back();
        }
        //如果沒滿就加到最前面，並且建立對照表在map中
        cache_.emplace_front(key, value);
        m_[key] = cache_.begin();
    }
private:
    unordered_map<int, list<pair<int,int>>::iterator> m_;
    int capacity_;
    list<pair<int,int>>cache_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */