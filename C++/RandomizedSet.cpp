#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class RandomizedSet {
public:
    vector<int> vec;
    unordered_map<int, int> mp;
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.count(val)){
            return false;
        }
        vec.push_back(val);
        mp[val] = vec.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp.count(val) == 0){
            return false;
        }
        int index = mp[val];
        int ele = vec.back();
        vec.back() = val;
        vec[index] = ele;
        mp[ele] = index;
        vec.pop_back();
        mp.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return vec[rand() % vec.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main(){
    unordered_map<int, int> mp;
    mp[123] = 2;
    cout << mp.count(123) << endl;
    mp.erase(123);
    cout << mp.count(123) << endl;
    vector<int> vec = {1, 2, 3};
    cout << vec.back() << endl;
    vec.back() = 9;
    cout << vec.back() << endl;
    return 0;
}