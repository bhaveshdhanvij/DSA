class MyLinkedList {
public:
    class Node {
    public:
        int value ;
        Node* next , *prev ;
        Node( int value ) {
            this->value = value ;
            next = prev = nullptr ;
        }
    };

    int n = 0 ; // this is the no of nodes 
    Node* head = new Node(0) , *tail = new Node(0) ;

    MyLinkedList() {
        head->next = tail ;
        tail->prev = head ;                
    }
    
    int get(int index) {
        if ( index < 0 || index > n - 1 ) return -1 ;

        Node* curr = head->next ;
        for ( int i = 0 ; i < index ; i++ ) {
            curr = curr->next ;
        }
        
        return curr->value ;
    }
    
    void addAtHead(int val) {
        Node* node = new Node(val) ;
        Node* headnext = head->next ;
        head->next = node ;
        node->prev = head ;
        node->next = headnext ;
        headnext->prev = node ;
        n++ ;
    }
    
    void addAtTail(int val) {
        Node* node = new Node(val) ;
        Node* tailprev = tail->prev ;
        tailprev->next = node ;
        node->prev = tailprev ;
        node->next = tail ;
        tail->prev = node ;
        n++ ;  
    }
    
    void addAtIndex(int index, int val) {
        if ( index > n ) return ;
        if ( index < 0 ) index = 0 ;

        Node* node = new Node(val) ;
        Node* prev = head ;
        
        for ( int i = 0 ; i < index ; i++ ) {
            prev = prev->next ;
        }

        Node* prevnext = prev->next ;
        prev->next = node ;
        node->prev = prev ;
        
        node->next = prevnext ;
        prevnext->prev = node ;

        n++ ;
    }
    
    void deleteAtIndex(int index) {

        if ( index < 0 || index > n - 1 ) return ;

        Node* curr = head->next ;
        for ( int i = 0 ; i < index ; i++ ) {
            curr = curr->next ;
        }

        curr->prev->next = curr->next ;
        curr->next->prev = curr->prev ;
        n-- ;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */