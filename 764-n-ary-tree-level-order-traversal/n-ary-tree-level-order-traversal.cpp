/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans ;
        if (!root) return ans ;
        queue<Node*> q ;
        q.push(root) ;
        while ( q.size() > 0 ) {
            int n = q.size() ;
            vector<int> t ;
            for ( int i = 0 ; i < n ; i++ ) {
                Node* node = q.front() ;
                q.pop() ;
                t.push_back(node->val) ;

                for ( Node* child : node->children ) {
                    q.push(child) ;
                }
            }
            ans.push_back(t) ;
        }
        return ans ;
    }
};