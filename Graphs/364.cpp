#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int,Node*>m1;
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return NULL;
        Node* ans = new Node(node -> val);
        m1[node -> val] = ans;
        
        for(int i = 0;i<node->neighbors.size();i++) {
            if(!m1.count(node->neighbors[i]->val))
                ans->neighbors.push_back(cloneGraph(node->neighbors[i]));
            else 
                ans->neighbors.push_back(m1[node->neighbors[i]->val]);
        }
        
        return ans;
    }
};