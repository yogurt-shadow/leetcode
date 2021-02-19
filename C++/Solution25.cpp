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

class Solution25 {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* pre = new ListNode(0, head);
        ListNode* ptr = pre;
        while(ptr){
            ListNode* ptr2 = ptr;
            int copy = k;
            vector<ListNode*> array;
            while(ptr2 && copy > 0){
                ptr2 = ptr2 -> next;
                array.push_back(ptr2);
                copy--;
            }
            if(!ptr2){
                return pre -> next;
            }
            ListNode* temp = ptr2 -> next;
            for(int i = array.size() - 1; i >= 1; i--){
                array[i] -> next = array[i - 1];
            }
            array[0] -> next = temp;
            ptr -> next = ptr2;
            ptr = array[0];
        }
        return pre -> next;
    }
};