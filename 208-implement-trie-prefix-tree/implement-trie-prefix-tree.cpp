class Node {
public:
    Node* child[26] ;
    bool isend ;
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
    
    void insert(string word) {
        Node* node = root ;
        for ( char c : word ) {
            int i = c - 'a' ;
            if ( node->child[i] == nullptr ) {
                node->child[i] = new Node() ;
            }
            node = node->child[i] ;
        }
        node->isend = true ;
    }
    
    bool search(string word) {
        Node* node = root ;
        for ( char c : word ) {
            int i = c - 'a' ;
            if ( node->child[i] == nullptr ) {
                return false ;
            }

            node = node->child[i] ;
        }

        return node->isend ;
    }
    
    bool startsWith(string s) {
        Node* node = root ;
        for ( char c : s ) {
            int i = c - 'a' ;
            if ( node->child[i] == nullptr ) {
                return false ;
            }
            node = node->child[i] ;
        }
        return true ;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */