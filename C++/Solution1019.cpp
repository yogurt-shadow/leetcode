#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <string>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution1019 {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans(10001, 0);
        int size = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq; // {value, index}
        while(head){
            while(!pq.empty() && head -> val > pq.top().first){
                auto ele = pq.top();
                pq.pop();
                ans[ele.second] = head -> val;
            }
            pq.push({head -> val, size});
            size ++;
            head = head -> next;
        }
        return vector<int>(ans.begin(), ans.begin() + size);
    }
};
