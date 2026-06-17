class Solution {
public:
    // Quikr
    // Snapdeal
    // Synopsys
    // Zoho
    // Juniper
    // Goldman Sachs
    // Brocade
    // Amdocs
    // Networks
    // Linkedin
    // Microsoft
    // Adobe
    // Cisco
    // Amazon
    // Oracle
    // Adobe
    // Google
    // HCL
    // Microsoft
    // IBM
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        // Approach 1 : brute force directly add elements of b into a and apply the sort function 
        // int i = m , j = 0 ;
        // while ( j < n ) {
        //     a[i++] = b[j++] ;
        // }
        // sort ( a.begin() , a.end() ) ;

        // Approach 2 (most optimal): 2 pointer approach : try to fill the last element of a by comparing 
        // TC : O(N + M) , SC : O(1)

        // int k = m + n - 1 ;
        // int i = m - 1 , j = n - 1 ;
        // while ( i >= 0 && j >= 0 ) {
        //     if ( a[i] > b[j] ) {
        //         a[k--] = a[i--] ;
        //     }else {
        //         a[k--] = b[j--] ;
        //     }
        // }

        // [1 , 2 , 3 , 0 , 0 , 0] [4 , 5 , 6] 
        // [4 , 5  , 6 , 4 , 5 , 6] [1 , 2 , 3]

        // while ( j >= 0 ) {
        //     a[k--] = b[j--] ;
        // }


        // Approach 3 : Using min heap : push all elements from both arrays and then override into a 
        // TC : O(M + N) , SC : O(M + N)

        priority_queue<int,vector<int>,greater<int>> pq ;
        for ( int i = 0 ; i < m ; i++ ) {
            pq.push(a[i]) ;
        }

        for ( int i = 0 ; i < n ; i++ ) {
            pq.push(b[i]) ;
        }

        int idx = 0 ;
        while (!pq.empty()) {
            a[idx++] = pq.top() ;
            pq.pop() ;
        }
    }
};