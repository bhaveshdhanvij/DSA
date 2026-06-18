// Meta
// Nvidia
// Google
// Uber
// Samsung
// Amazon
// Microsoft

class Node{
public:
    Node* child[26] ;
    bool isend ;

    Node() {
        isend = false ;
        for ( int i = 0 ; i < 26 ; i++ ) {
            child[i] = NULL ;
        }
    }
};

class Trie {
public:
    Node* root ;
    Trie() {
        root = new Node() ;
    }
    
    void insert(string word) {
        Node* node = root ;
        for ( char c : word ) {
            int idx = c - 'a' ;
            if ( node->child[idx] == NULL ) {
                node->child[idx] = new Node() ;
            }

            node = node->child[idx] ;
        }

        node->isend = true ;
    }
    
    bool search(string word) {
        Node* node = root ;
        for ( char c : word ) {
            int idx = c - 'a' ;
            if ( node->child[idx] == NULL ) {
                return false ;
            }

            node = node->child[idx] ;
        }

        return node->isend ;
    }
    
    bool startsWith(string prefix) {
        Node* node = root ;
        for ( char c : prefix ) {
            int idx = c - 'a' ;
            if ( node->child[idx] == NULL ) {
                return false ;
            }

            node = node->child[idx] ;
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