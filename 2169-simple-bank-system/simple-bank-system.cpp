class Bank {
public:
    long long n ;
    vector<long long> a ;

    Bank(vector<long long>& b) {
        n = b.size() ;
        a.resize(n + 1, 0) ;
        for ( int i = 0 ; i < n ; i++ ) {
            a[i + 1] = b[i] ;
        }
    }
    
    bool transfer(int x, int y, long long money) {
        if ( x < 1 || y < 1 || x > n || y > n ) return false ;
        if ( a[x] < money ) return false ;

        a[x] -= money ;
        a[y] += money ;

        return true ;
    }
    
    bool deposit(int x, long long money) {
        if ( x < 1 || x > n ) return false ;
        a[x] += money ;

        return true ;
    }
    
    bool withdraw(int x, long long money) {
        if ( x < 1 || x > n ) return false ;
        if ( a[x] < money ) return false ;

        a[x] -= money ;
        return true ;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */