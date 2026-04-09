class ATM {
public:
    vector<int> a = vector<int>(5 , 0) ;
    vector<int> d = {20 , 50 , 100 , 200 , 500} ;

    ATM() {
        
    }
    
    void deposit(vector<int> b) {
        for ( int i = 0 ; i < 5 ; i++ ) {
            a[i] += b[i] ;
        }
    }
    
    vector<int> withdraw(int amount) {
        if ( amount % 10 ) return { -1 } ;

        vector<int> ans(5 , 0) ;
        vector<int> temp = a ;

        for ( int i = 4 ; i >= 0 && amount > 0 ; i-- ) {
            int curr = min ( temp[i] , amount / d[i] ) ;

            amount -= d[i] * curr ;

            temp[i] -= curr ;

            ans[i] += curr ;
        }

        if ( amount == 0 ) {
            a = temp ;
            return ans ;
        }

        return {-1} ;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */