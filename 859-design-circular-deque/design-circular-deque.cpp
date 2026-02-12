class MyCircularDeque {
public:
    deque<int> a ;
    int k ;
    MyCircularDeque(int k) {
        this->k = k ;
    }
    
    bool insertFront(int value) {
        if ( a.size() == k ) return false ;
        a.push_front(value) ;
        return true ;
    }
    
    bool insertLast(int value) {
        if ( a.size() == k ) return false ;
        a.push_back(value) ;
        return true ;
    }
    
    bool deleteFront() {
        if ( a.empty() ) return false ;
        a.pop_front() ;
        return true ;
    }
    
    bool deleteLast() {
        if ( a.empty() ) return false ;
        a.pop_back() ;
        return true ;
    }
    
    int getFront() {
        if ( a.empty() ) return -1 ;
        return a.front() ;
    }
    
    int getRear() {
        if ( a.empty() ) return -1 ;
        return a.back() ;
    }
    
    bool isEmpty() {
        return a.empty() ;
    }
    
    bool isFull() {
        return a.size() == k ;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */