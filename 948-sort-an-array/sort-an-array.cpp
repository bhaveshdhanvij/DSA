class Solution {
public:
    // Oracle
    // Adobe
    // Amazon
    // Apple
    // Meta
    // Infosys
    // TCS
    void merge(vector<int> &nums , int st , int mid , int end ) {
        vector<int> temp ;
        int i = st , j = mid + 1 ;
        while ( i <= mid && j <= end ) {
            if ( nums[i] <= nums[j] ) {
                temp.push_back(nums[i]) ;
                i++ ;
            }else {
                temp.push_back(nums[j]) ;
                j++ ;
            }
        }

        while ( i <= mid ) {
            temp.push_back(nums[i]) ;
            i++ ;
        }

        while ( j <= end ) {
            temp.push_back(nums[j]) ;
            j++ ;
        }

        for ( int idx = 0 ; idx < temp.size() ; idx++ ) {
            nums[idx + st] = temp[idx] ;
        }
    }
    void mergesort ( vector<int> &nums , int st , int end ) {
        int mid = st + (end - st) / 2 ;
        
        if ( st < end ) {
            
            mergesort(nums , st , mid) ; // left 
            mergesort(nums , mid + 1 , end) ; // right 

            merge(nums , st , mid , end) ;
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        // Merge Sort Algorithm 
        // TC : O(Nlog(N)) 
        
        mergesort(nums , 0 , nums.size() - 1) ;
        return nums ;
    }
};