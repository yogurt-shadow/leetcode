#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        ListNode* ans = new ListNode();
        ListNode* p = ans;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for(int i = 0; i < size; i++){
            if (lists[i]){
                pq.push({lists[i]->val, i});
            }
        }
        while(!pq.empty()){
            auto ele = pq.top();
            pq.pop();
            p -> next = new ListNode(ele.first);
            p = p -> next;
            lists[ele.second] = lists[ele.second] -> next;
            if(lists[ele.second]){
                pq.push({lists[ele.second] -> val, ele.second});
            }
        }
        return ans -> next;
    }
};