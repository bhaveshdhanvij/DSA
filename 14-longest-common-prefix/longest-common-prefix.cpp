class Node {
public:
    Node* child[26] ;
    int c ;
    Node() {
        for ( int i = 0 ; i < 26 ; i++ ) {
            child[i] = nullptr ;
        }
        c = 0 ;
    }
};
class Solution {
public:
    void insert(Node* root , string& s ) {
        Node* node = root ;
        
        for ( int i = 0 ; i < s.size() ; i++ ) {
            int idx = s[i] - 'a' ;
            if ( node->child[idx] == nullptr ) {
                node->child[idx] = new Node() ;
            }
            node = node->child[idx] ;
            node->c++ ;
        }
    }
    string search(Node* root , int n) {
        Node* node = root ;
        string ans = "" ;

        while ( true ) {
            int cnt = 0 ;
            int idx = -1 ;

            for ( int i = 0 ; i < 26 ; i++ ) {
                if ( node->child[i] != nullptr && node->child[i]->c == n ) {
                    cnt++ ; 
                    idx = i ;
                }
            }

            if ( cnt != 1 ) break ;
            ans.push_back(char(idx + 'a')) ;
            node = node->child[idx] ;
        }
        return ans ;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size() ;
        if ( n == 0 ) return "" ;

        Node* root = new Node() ;
        
        for ( string s : strs ) {
            insert(root , s) ;
        }
        
        return search(root , n) ;
    }
};