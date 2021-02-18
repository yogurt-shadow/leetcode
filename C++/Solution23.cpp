#include<iostream>
#include<vector>

#include<queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution23 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int> > pq;
        for(auto& ele: lists){
            while(ele){
                pq.push(ele -> val);
                ele = ele -> next;
            }
        }
        ListNode* result = new ListNode();
        ListNode* ptr = result;
        while(!pq.empty()){
            ptr -> next = new ListNode(pq.top());
            pq.pop();
            ptr = ptr -> next;
        }
        return result -> next;
    }
};
