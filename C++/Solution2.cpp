#include<iostream>
#include<vector>
#include<map>

using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = new ListNode();
        ListNode* head = p;
        int over = 0;
        while(l1 || l2){
            int ele1 = 0, ele2 = 0;
            if(l1 && l2){
                ele1 = l1 -> val;
                ele2 = l2 -> val;
                l1 = l1 -> next;
                l2 = l2 -> next;
            }
            else if(l1){
                ele1 = l1 -> val;
                l1 = l1 -> next;
            }
            else{
                ele2 = l2 -> val;
                l2 = l2 -> next;
            }
            int ele = ele1 + ele2 + over;
            p -> next = new ListNode(ele % 10);
            if(ele >= 10){
                over = 1;
            }
            else{
                over = 0;
            }
            p = p -> next;
        }
        if(over == 1){
            p -> next = new ListNode(1);
        }
        return head -> next;
    }
};