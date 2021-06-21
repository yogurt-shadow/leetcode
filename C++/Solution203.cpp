#include <iostream>
#include <vector>

#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution203 {
public:
    ListNode *removeElements(ListNode *head, int val){
        ListNode* sentinel = new ListNode(0, head);
        ListNode* ptr = sentinel;
        while(ptr -> next){
            if(ptr -> next -> val == val){
                ptr -> next = ptr -> next -> next;
            }
            else{
                ptr = ptr -> next;
            }
        }
        return sentinel -> next;
    }
};