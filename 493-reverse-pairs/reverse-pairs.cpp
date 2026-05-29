class Solution {
public:
    // Adobe
    // Apple
    // Amazon
    // Uber
    void merge(vector<int>& a , int low , int mid , int high ) {
        int n1 = mid - low + 1 ;
        int n2 = high - mid ;
        vector<int> l(n1) ;
        vector<int> r(n2) ;

        for ( int i = 0 ; i < n1 ; i++ ) {
            l[i] = a[low + i] ;
        }

        for ( int i = 0 ; i < n2 ; i++ ) {
            r[i] = a[mid + 1 + i] ;
        }

        int k = low ;
        int i = 0 , j = 0 , c = 0 ;
        while ( i < n1 && j < n2 ) {
            if ( l[i] >= r[j] ) {
                a[k++] = r[j++] ;
            }else {
                a[k++] = l[i++] ;
            }
        }
        while ( i < n1 ) a[k++] = l[i++] ;
        while ( i < n2 ) a[k++] = r[j++] ;
    }
    int countPairs(vector<int>& a , int low , int mid , int high ) {
        int right = mid + 1 ;
        int c = 0 ;
        for ( int i = low ; i <= mid ; i++ ) {
            while ( right <= high && a[i] > (long long)2 * a[right] ) {
                right++ ;
            }
            c += (right - (mid + 1)) ;
        }
        return c ;
    }
    int mergeSort ( vector<int>& a , int low , int high ) {
        int c = 0 ;
        if ( low < high ) {
            int mid = (low + high) / 2 ;
            c += mergeSort(a , low , mid) ;
            c += mergeSort(a , mid + 1 , high) ;
            c += countPairs(a , low , mid , high) ;
            merge(a , low , mid , high) ;
        }
        return c ;
    }
    int reversePairs(vector<int>& nums) {
        // Naive Approach : Using 2 for loops 
        // TC : O(N * N) , SC : O(1) 

        // int n = nums.size() ;
        // int ans = 0 ;
        // for ( int i = 0 ; i < n ; i++ ) {
        //     for ( int j = i + 1 ; j < n ; j++ ) {
        //         if ( nums[i] > (long long)2 * nums[j] ) {
        //             ans++ ;
        //         }
        //     }
        // }        
        // return ans ;

        
        // Optimal Approach : Using merge sort 
        // TC : O(Nlog(N)) , SC : O(N)
        
        int low = 0 , high = nums.size() - 1 ;
        return mergeSort ( nums , low , high) ;
    }
};