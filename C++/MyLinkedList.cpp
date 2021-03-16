#include<iostream>
#include<vector>

#include<unordered_map>

using namespace std;

// Solution707
class Node{
public:
    int val;
    Node* prev;
    Node* next;

    Node(){
        val = 0;
        prev = nullptr;
        next = nullptr;
    }

    Node(int v, Node* n1, Node* n2){
        val = v;
        prev = n1;
        next = n2;
    }
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    Node* head;
    Node* tail;
    int size;

    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index < 0 || index >= size){
            return -1;
        }
        Node* node = head;
        while(index > 0){
            index--;
            node = node -> next;
        }
        return node -> val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        if(size == 0){
            Node* node = new Node(val, nullptr, nullptr);
            head = node;
            tail = node;
        }
        else{
            Node* node = new Node(val, nullptr, head);
            head -> prev = node;
            head = node;
        }
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if(size == 0){
            Node* node = new Node(val, nullptr, nullptr);
            head = node;
            tail = node;
        }
        else{
            Node* node = new Node(val, tail, nullptr);
            tail -> next = node;
            tail = node;
        }
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > size){
            return;
        }
        if(index == size){
            addAtTail(val);
        }
        else if(index <= 0){
            addAtHead(val);
        }
        else{
            Node* node1 = head;
            while(index > 1){
                index--;
                node1 = node1 -> next;
            }
            Node* node2 = node1 -> next;
            Node* node3 = new Node(val, node1, node2);
            node1 -> next = node3;
            node2 -> prev = node3;
            size++;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size){
            return;
        }
        if(size == 1){
            head = nullptr;
            tail = nullptr;
            size--;
        }
        else{
            if(index == 0){
                head = head -> next;
                head -> prev = nullptr;
                size--;
            }
            else if(index == size - 1){
                tail  = tail -> prev;
                tail -> next = nullptr;
                size--;
            }
            else{
                Node* node1 = head;
                while(index > 1){
                    index--;
                    node1 = node1 -> next;
                }
                Node* node2 = node1 -> next -> next;
                node1 -> next = node2;
                node2 -> prev = node1;
                size--;
            }
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main(){
    MyLinkedList linkedlist;
    linkedlist.addAtHead(7);
    linkedlist.addAtHead(2);
    linkedlist.addAtHead(1);
    cout << linkedlist.size << endl;
    linkedlist.addAtIndex(3, 0);
    Node* node = linkedlist.head;
    cout << linkedlist.size << endl;
    while(node){
        cout << node -> val << " ";
        node = node -> next;
    }
    return 0;
}