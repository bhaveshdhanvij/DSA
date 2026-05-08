class Node {
public:
    bool isend ;
    Node* child[26] ;
    Node() {
        isend = false ;
        for ( int i = 0 ; i < 26 ; i++ ) {
            child[i] = nullptr ;
        }
    }
};
class Trie {
private:
    Node* root ;
public:
    Trie() {
        root = new Node() ;
    }

    void insert( string s ) {
        Node* node = root ;
        for ( char c : s ) {
            int i = c - 'a' ;
            
            if ( node->child[i] == nullptr ) {
                node->child[i] = new Node() ;
            }

            node = node->child[i] ;
        }
        node->isend = true ;
    }

    string prefix ( string s ) {
        Node* node = root ;
        string t = "" ;
        for ( char c : s ) {
            int i = c - 'a' ;
            
            if ( node->child[i] == nullptr ) {
                return "" ;
            }

            node = node->child[i] ;
            
            t += c ;
            if ( node->isend ) return t ;
        }

        return t ;
    }
};
class Solution {
public:
    string replaceWords(vector<string>& d, string s) {
        Trie t ;
        for ( string a : d ) {
            t.insert(a) ;
        }
        
        stringstream ss(s) ;
        string word , ans = "" ;
        while ( ss >> word ) {
            string temp = t.prefix(word) ;

            if ( !ans.empty() ) ans += ' ' ;
            
            if ( temp.empty() ) {
                ans += word ;
            }else {
                ans += temp ;
            }
        }

        return ans ;
    }
};