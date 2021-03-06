#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>
using namespace std;


// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


class Solution558 {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if(quadTree1 -> isLeaf && quadTree2 -> isLeaf){
            return new Node(quadTree1 -> val || quadTree2 -> val, true);
        }
        if(quadTree1 -> isLeaf){
            if(quadTree1 -> val){
                return new Node(true, true);
            }
            return new Node(false, false, quadTree2 -> topLeft, quadTree2 -> topRight, quadTree2 -> bottomLeft, quadTree2 -> bottomRight);
        }
        if(quadTree2 -> isLeaf){
            if(quadTree2 -> val){
                return new Node(true, true);
            }
            return new Node(false, false, quadTree1 -> topLeft, quadTree1 -> topRight, quadTree1 -> bottomLeft, quadTree1 -> bottomRight);
        }
        Node* node1 = intersect(quadTree1 -> topLeft, quadTree2 -> topLeft);
        Node* node2 = intersect(quadTree1 -> topRight, quadTree2 -> topRight);
        Node* node3 = intersect(quadTree1 -> bottomLeft, quadTree2 -> bottomLeft);
        Node* node4 = intersect(quadTree1-> bottomRight, quadTree2 -> bottomRight);
        if(node1 -> isLeaf && node2 -> isLeaf && node3 -> isLeaf && node4 -> isLeaf){
            if(node1 -> val && node2 -> val && node3 -> val && node4 -> val){
                return new Node(true, true);
            }
            if(!node1 -> val && !node2 -> val && !node3 -> val && !node4 -> val){
                return new Node(false, true);
            }
        }
        return new Node(false, false, node1, node2, node3, node4);
    }
};