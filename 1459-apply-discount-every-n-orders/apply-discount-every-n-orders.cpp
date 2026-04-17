class Cashier {
public:
    int n , discount ;
    unordered_map<int,int> mp ; 
    int curr = 0 ;

    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        this->n = n ;
        this->discount = discount ;
        for ( int i = 0 ; i < products.size() ; i++ ) {
            mp[products[i]] = prices[i] ;
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double ans = 0 ;
        curr++ ;

        for ( int i = 0 ; i < product.size() ; i++ ) {
            ans += mp[product[i]] * amount[i] ;
        }
        if ( curr % n == 0 ) {
            ans = ans * ((100.0 - discount) / 100) ;
        }

        return ans ;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */