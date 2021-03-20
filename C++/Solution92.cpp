#include<iostream>
#include<vector>

#include<unordered_map>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution92 {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* sentinel = new ListNode(0, head);
        ListNode* node1 = sentinel;
        int left2 = left;
        while(left > 1){
            left--;
            node1 = node1 -> next;
        }
        vector<ListNode*> vec(right - left + 1);
        ListNode* node2 = node1;
        for(int i = 0; i < right - left2 + 1; i++){
            node2 = node2 -> next;
            vec[i] = node2;
            //cout << node2 -> val << endl;
        }
        ListNode* copy = node2 -> next;
        node1 -> next = node2;
        for(int i = right - left2; i >= 1; i--){
            vec[i] -> next = vec[i - 1];
        }
        vec[0] -> next = copy;
        return sentinel -> next;
    }
};