class Node {
public:
    Node* child[26] ;
    bool isend ;
    int val ;
    Node() {
        isend = false ;
        val = -1 ;
        for ( int i = 0 ; i < 26 ; i++ ) {
            child[i] = nullptr ;
        }
    }
};

class MapSum {
private:
    Node* root ;

    int dfs ( Node* node ) {
        if ( node == nullptr ) return 0 ;

        int ans = 0 ;
        if ( node->isend ) ans += node->val ;

        for ( int i = 0 ; i < 26 ; i++ ) {
            ans += dfs(node->child[i]) ;
        }

        return ans ;
    }
public:
    MapSum() {
        root = new Node() ;
    }
    
    void insert(string key, int value) {
        Node* node = root ;
        for ( char c : key ) {
            int i = c - 'a' ;
            if ( node->child[i] == nullptr ) {
                node->child[i] = new Node() ;
            }
            node = node->child[i] ;
        }
        node->isend = true ;
        node->val = value ;
    }
    
    int sum(string s) {
        int ans = 0 ;
        Node* node = root ;
        for ( char c : s ) {
            int i = c - 'a' ;
            if ( node->child[i] == nullptr ) {
                return 0 ;
            }
            node = node->child[i] ;
        }
        return dfs(node) ;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */