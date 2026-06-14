class BrowserHistory {
public:
    vector<string> a ;
    int curr , last ;
    BrowserHistory(string homepage) {
        a.push_back(homepage) ;
        curr = 0 ;
        last = 0 ;
    }
    
    void visit(string url) {
        curr++ ;
        if ( curr < a.size() ) {
            a[curr] = url ;
        }else {
            a.push_back(url) ;
        }
        last = curr ;
    }
    
    string back(int steps) {
        curr = max ( 0 , curr - steps ) ;
        return a[curr] ;
    }
    
    string forward(int steps) {
        curr = min ( last , curr + steps ) ;
        return a[curr] ;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */