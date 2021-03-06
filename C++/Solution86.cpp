#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>
using namespace std;


 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution86 {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* sentinel = new ListNode();
        ListNode* small = new ListNode();
        ListNode* large = new ListNode();
        ListNode* ptr = head;
        ListNode* s = small;
        ListNode* l = large;
        while(ptr){
            if(ptr -> val < x){
                s -> next = new ListNode(ptr -> val);
                s = s -> next;
            }
            else{
                l -> next = new ListNode(ptr -> val);
                l = l -> next;
            }
            ptr = ptr -> next;
        }
        if(small -> next){
            sentinel -> next = small -> next;
            s -> next = large -> next;
            return sentinel -> next;
        }
        return head;
    }
};