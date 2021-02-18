#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution24 {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* pre = new ListNode(0, head);
        ListNode* ptr2 = pre;
        while(ptr2){
            ListNode* ptr = ptr2;
            ptr = ptr -> next;
            if(!ptr){
                return pre -> next;
            }
            ptr = ptr -> next;
            if(!ptr){
                return pre -> next;
            }
            ListNode* copy = ptr -> next;
            ptr2 -> next -> next = nullptr;
            ptr -> next = ptr2 -> next;
            ptr2 -> next -> next = copy;
            ptr2 -> next = ptr;
            ptr2 = ptr2 -> next -> next;
        }
        return pre -> next;
    }
};