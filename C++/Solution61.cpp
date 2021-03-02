#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

class Solution61 {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head){
            return head;
        }
        int size = 1;
        ListNode* sentinel = new ListNode(0, head);
        ListNode* ptr = head;
        while(ptr -> next){
            ptr = ptr -> next;
            size++;
        }
        k = k % size;
        if(k == 0){
            return head;
        }
        ListNode* pre = sentinel;
        ListNode* ptr1 = pre -> next;
        ListNode* ptr2 = ptr1;
        for(int i = 0; i < k; i++){
            ptr2 = ptr2 -> next;
        }
        while(ptr2){
            pre = pre -> next;
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }
        pre -> next = nullptr;
        ptr -> next = head;
        return ptr1;
    }
};