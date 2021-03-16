#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

// Solution705
class MyHashSet {
public:
    int array[1000001];
    /** Initialize your data structure here. */
    MyHashSet() {
        for(int i = 0; i <= 1000000; i++){
            array[i] = 0;
        }
    }
    
    void add(int key) {
        array[key] = 1;
    }
    
    void remove(int key) {
        array[key] = 0;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return array[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */