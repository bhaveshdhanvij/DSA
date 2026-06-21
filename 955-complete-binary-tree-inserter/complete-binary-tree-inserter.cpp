/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class CBTInserter {
public:
    TreeNode* root ;
    queue<TreeNode*> q ;

    CBTInserter(TreeNode* root) {
        this->root = root ;
        
        queue<TreeNode*> qq ;
        qq.push(root) ;
        while ( qq.size() > 0 ) {
            auto curr = qq.front() ;
            qq.pop() ;

            if ( curr->left ) qq.push(curr->left) ;
            if ( curr->right ) qq.push(curr->right) ;

            if ( curr->left == nullptr || curr->right == nullptr ) {
                q.push(curr) ; // possible candidate for next insertion into the CBT
            }
        }    
    }
    
    int insert(int val) {
        TreeNode* p = q.front() ;
        TreeNode* node = new TreeNode(val) ;

        if ( p->left == NULL ) {
            p->left = node ;
        }else {
            p->right = node ;
            q.pop() ;
        }

        q.push(node) ;
        return p->val ;
    }
    
    TreeNode* get_root() {
        return root ;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */