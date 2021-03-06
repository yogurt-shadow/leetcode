#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;


 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution83 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head){
            return head;
        }
        ListNode* res = new ListNode(head -> val);
        ListNode* ptr1 = res;
        ListNode* ptr2 = head;
        while(ptr2){
            if(ptr2 -> val == ptr1 -> val){
                ptr2 = ptr2 -> next;
            }
            else{
                ptr1 -> next = new ListNode(ptr2 -> val);
                ptr1 = ptr1 -> next;
            }
        }
        return res;
    }
};