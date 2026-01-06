/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root ;
        queue<Node*> q ;
        q.push(root) ;
        while ( q.size() > 0 ) {
            int n = q.size() ;
            vector<Node*> a ;
            for ( int i = 0 ; i < n ; i++ ) {
                Node* node = q.front() ;
                q.pop() ;
                a.push_back(node) ;

                if ( node->left ) q.push(node->left) ;
                if ( node->right ) q.push(node->right) ;
            }
            for ( int i = 1 ; i < a.size() ; i++ ) {
                a[i - 1]->next = a[i] ;
            }
        } 
        return root ;
    }
};