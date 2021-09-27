#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>

using namespace std;

typedef long long ll;

class MedianFinder {
public:
    int size = 0;
    priority_queue<int, vector<int>, greater<int>> small;
    priority_queue<int, vector<int>, less<int>> large;
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(size == 0){
            small.push(num);
            size ++;
        }
        else{
            if(num <= small.top()){
                small.push(num);
                if(small.size() - large.size() > 1){
                    large.push(small.top());
                    small.pop();
                }
            }
            else{
                large.push(num);
                if(large.size() > small.size()){
                    small.push(large.top());
                    large.pop();
                }
            }
        }
    }
    
    double findMedian() {
        return size % 2 == 0 ? (small.top() + large.top()) * 1.0 / 2 : small.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main(){
    priority_queue<int, vector<int>, greater<int>> small;
    small.push(1);
    small.push(2);
    cout << small.top() << endl;
    return 0;
}