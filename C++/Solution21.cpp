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

class Solution21 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode();
        ListNode* ptr = result;
        while(l1 || l2){
            if(!l1){
                ptr -> next = new ListNode(l2 -> val);
                l2 = l2 -> next;
            }
            else if(!l2){
                ptr -> next = new ListNode(l1 -> val);
                l1 = l1 -> next;
            }
            else{
                if(l1 -> val >= l2 -> val){
                    ptr -> next = new ListNode(l2 -> val);
                    l2 = l2 -> next;
                }
                else{
                    ptr -> next = new ListNode(l1 -> val);
                    l1 = l1 -> next;
                }
            }
            ptr = ptr -> next;
        }
        return result -> next;
    }
};