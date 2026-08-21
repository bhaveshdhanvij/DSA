class Fenwick {
    int n ;
    vector<long long> bit ;
public:
    Fenwick(int n) {
        this->n = n ;
        bit.assign(n + 1 , 0) ;
    }

    void update(int i , long long delta) {
        for ( ; i <= n ; i += i & -i ) {
            bit[i] += delta ;
        }
    }

    long long query(int i) {
        long long sum = 0 ;
        for ( ; i > 0 ; i -= i & -i ) {
            sum += bit[i] ;
        }
        return sum ;
    }

    long long rangesum(int l , int r) {
        return query(r) - query(l - 1) ;
    }
};
class NumArray {
    vector<int> nums ;
    Fenwick bit ;
public:
    NumArray(vector<int>& nums) : nums(nums) , bit(nums.size()) {
        for ( int i = 0 ; i < nums.size() ; i++ ) {
            bit.update(i + 1 , nums[i]) ;
        }
    }
    
    void update(int index, int val) {
        int delta = val - nums[index] ;
        nums[index] = val ;
        bit.update(index + 1 , delta) ;
    }
    
    int sumRange(int left, int right) {
        return bit.rangesum(left + 1, right + 1 ) ;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */