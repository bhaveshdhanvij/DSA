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
    // Google
    // Google
    // Amazon
    // Amazon
    // Meta
    // Meta
    // Uber
    // Uber
    // Adobe
    // Adobe
    unordered_map<Node*,Node*> mp ;
    Node* cloneGraph(Node* node) {
        // Optimal Approach : Using HashMap + DFS 
        // TC : O(V + E) , SC : O(V)
        
        if (!node) return nullptr ;
        
        if ( mp.count(node) ) return mp[node] ;
        
        Node* clone = new Node(node->val) ;
        
        mp[node] = clone ;

        for ( Node* n : node->neighbors ) {
            clone->neighbors.push_back(cloneGraph(n)) ;
        }

        return clone ;
    }
};