class FindSumPairs {
public:
    unordered_map<int,int> mp , mpp ;
    vector<int> a , b ;
    FindSumPairs(vector<int>& a, vector<int>& b) {
        this-> a = a ;
        this-> b = b ;
        for ( int x : a ) mp[x]++ ;
        for ( int x : b ) mpp[x]++ ;
    }
    
    void add(int idx , int val) {
        int prev = b[idx] ;
        mpp[prev]-- ;

        if ( mpp[prev] == 0 ) mpp.erase(prev) ;

        b[idx] += val ;
        mpp[b[idx]]++ ;
    }
    
    int count(int tot) {
        int ans = 0 ;
        for ( auto p : mp ) {
            int f1 = p.second ;
            int t = tot - p.first ;
            int f2 = 0 ;
            if ( mpp.count(t) ) f2 = mpp[t] ;
            ans += f1 * f2 ;
        }
        return ans ;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */