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
 
class Solution82 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* sentinel = new ListNode(-1);
        ListNode* ptr1 = sentinel;
        ListNode* ptr2 = head;
        while(ptr2){
            if(ptr2 -> next && ptr2 -> next -> val == ptr2 -> val){
                while(ptr2 -> next && ptr2 -> next -> val == ptr2 -> val){
                    ptr2 = ptr2 -> next;
                }
                ptr2 = ptr2 -> next;
            }
            else{
                ptr1 -> next = new ListNode(ptr2 -> val);
                ptr1 = ptr1 -> next;
                ptr2 = ptr2 -> next;
            }
        }
        return sentinel -> next;
    }
};