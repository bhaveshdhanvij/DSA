class Node {
public:
    Node* child[26] ;
    int count ;
    Node() {
        count = 0 ;
        for ( int i = 0 ; i < 26 ; i++ ) {
            child[i] = nullptr ;
        } 
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Node* root = new Node() ;

        for ( string s : words ) {
            Node* node = root ;
            for ( char c : s ) {
                int i = c - 'a' ;
                if ( node->child[i] == nullptr ) {
                    node->child[i] = new Node() ;
                }
                node = node->child[i] ;
                node->count++ ;
            }
        }        

        vector<int> ans ;
        for ( string s : words ) {
            int curr = 0 ;
            Node* node = root ;
            for ( char c : s ) {
                int i = c - 'a' ;
                node = node->child[i] ;
                curr += node->count ;
            }
            ans.push_back(curr) ;
        }

        return ans ;
    }
};