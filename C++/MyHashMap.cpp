#include<iostream>
#include<vector>

#include<unordered_map>

using namespace std;

// Solution706
class MyHashMap {
public:
    /** Initialize your data structure here. */
    vector<int> keys;
    vector<int> values;

    MyHashMap() {
        keys.resize(1000001, 0);
        values.resize(1000001, 0);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        keys[key] = 1;
        values[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        if(!keys[key]){
            return -1;
        }
        return values[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        keys[key] = 0;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */