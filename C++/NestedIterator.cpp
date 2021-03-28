/**
    Solution341
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>
using namespace std;

class NestedIterator {
public:
    vector<int> vec;
    int size;
    int index;

    NestedIterator(vector<NestedInteger> &nestedList) {
        for(auto ele: nestedList){
            push(vec, ele);
        }
        size = vec.size();
        index = 0;
    }

    void push(vector<int>& vec, NestedInteger x){
        if(x.isInteger()){
            vec.push_back(x.getInteger());
            return;
        }
        auto list = x.getList();
        for(auto ele: list){
            push(vec, ele);
        }
    }
    
    int next() {
        return vec[index++];
    }
    
    bool hasNext() {
        return index < size;
    }
};

class NestedInteger{
public:
    bool isInteger() const;
    int getInteger() const;
    const vector<NestedInteger> &getList() const;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */