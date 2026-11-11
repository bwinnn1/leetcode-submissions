class LRUCache {
private:
    vector<pair<int, int>> cache;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        // find in cache for key
        for (int i = 0; i < cache.size(); i++) {
            // if found
            // make a temp one and insert that to the back
            if (cache[i].first == key) {
                pair<int, int> temp = cache[i];
                // cache::erase is an iterator not integer index
                cache.erase(cache.begin() + i);
                cache.push_back(temp);
                return temp.second;
            }
        }
        // if not found then return -1
        return -1;
    }
    
    void put(int key, int value) {
        // if current LRU.cache is at capacity
        // remove the top key-value 
        // find if the key already existed
        for (int i = 0; i < cache.size(); i++) {
            if (cache[i].first == key) {
                cache.erase(cache.begin() + i);
                cache.push_back({key, value});
                return;
            }
        }
        if (cache.size() == capacity) {
            // evict the top one which is the lest recently used
            cache.erase(cache.begin());
        }

        // if never seen before and not at capacity
        cache.push_back({key, value});
    }
};
