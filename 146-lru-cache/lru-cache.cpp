class LRUCache {
public:
    // Amazon
    // Miro
    // Ebay
    // Microsoft
    // Uber
    // Visa
    // Oracle
    // Intuit
    // Samsung
    // PayPal

    // Optimal Approach : Using two DS ie Doubly Linked List + unordered hashMap for node retrival
    // TC : O(1) for both put and get queries

    class Node {
    public:
        int key , val ;
        Node* next ;
        Node* prev ;

        Node(int k , int v) {
            key = k ;
            val = v ;
            next = prev = nullptr ;
        }
    };

    Node* head ;
    Node* tail ;

    unordered_map<int,Node*> mp ;

    int lim ;

    void addnode (Node* node) {
        Node* temp = head->next ; // previously MSU
        
        head->next = node ; // new node ;

        node->prev = head ; // designing connections 
        node->next = temp ;

        temp->prev = node ; // for prev node too 
    }

    void delnode(Node* node) {
        Node* prev = node->prev ;
        Node* next = node->next ;

        prev->next = next ;
        next->prev = prev ;
    }


    LRUCache(int capacity) {
        lim = capacity ;    
        
        head = new Node(-1 , -1) ;
        tail = new Node(-1 , -1) ;

        head->next = tail ;
        tail->prev = head ;
    }
    
    int get(int key) {
        if ( !mp.count(key) ) return -1 ;
        
        int ans = mp[key]->val ;
        
        delnode(mp[key]) ; // delete that particular code in the middle 
        addnode(mp[key]) ; // add that node to the front 

        return ans ;
    }
    
    void put(int key, int value) {
        if ( mp.count(key) ) {
            Node* old = mp[key] ;
            delnode(old) ;
            mp.erase(key) ;
            delete old ;
        }

        if ( mp.size() == lim ) {
            Node* lru = tail->prev ;
            mp.erase(lru->key) ;
            delnode(lru) ;
            delete lru ;
        }

        Node* newnode = new Node(key , value) ;
        
        addnode(newnode) ; // adds to the front 
        mp[key] = newnode ;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */