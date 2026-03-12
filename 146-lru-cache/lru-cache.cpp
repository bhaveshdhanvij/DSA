class LRUCache {
public:
    class Node {
    public:
        int key , value ;
        Node* prev , *next ;
        Node( int key , int value) {
            this->key = key ;
            this->value = value ;
        }
    };
    Node* head = new Node(0 , 0) , *tail = new Node(0 , 0) ;
    int capacity ;
    unordered_map<int,Node*> mp ;

    LRUCache(int capacity) {
        this->capacity = capacity ;
        head->next = tail ;
        tail->prev = head ;
    }
    
    int get(int key) {
        if ( mp.count(key) ) {
            Node* node = mp[key] ;
            remove(node) ;
            insert(node) ;
            return node->value ;
        }else {
            return -1 ;
        }
    }
    
    void put(int key, int value) {
        if ( mp.count(key) ) {
            remove(mp[key]) ;
        }
        if ( capacity == mp.size() ) {
            remove(tail->prev) ;
        }
        insert(new Node(key , value)) ;
    }

    void remove(Node* node) {
        mp.erase(node->key) ;
        node->prev->next = node->next ;
        node->next->prev = node->prev ;
    }

    void insert(Node* node) {
        mp[node->key] = node ;
        Node* headnext = head->next ;
        head->next = node ;
        node->prev = head ;
        node->next = headnext ;
        headnext->prev = node ;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */