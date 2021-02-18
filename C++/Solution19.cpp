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

class Solution19 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pre = new ListNode(0, head);
        ListNode* ptr = pre;
        while(ptr -> next){
            ListNode* ptr2 = ptr;
            int copy = n;
            while(copy > 0){
                ptr2 = ptr2 -> next;
                copy--;
            }
            if(!ptr2 -> next){
                ptr -> next = ptr -> next -> next;
                return pre -> next;
            }
            ptr = ptr -> next;
        }
        return pre -> next;
    }
};