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
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        // Approach 1 : brute force directly add elements of b into a and apply the sort function 
        // int i = m , j = 0 ;
        // while ( j < n ) {
        //     a[i++] = b[j++] ;
        // }
        // sort ( a.begin() , a.end() ) ;

        // Approach 2 : 2 pointer approach : try to fill the last element of a by comparing 
        int k = m + n - 1 ;
        int i = m - 1 , j = n - 1 ;
        while ( i >= 0 && j >= 0 ) {
            if ( a[i] > b[j] ) {
                a[k--] = a[i--] ;
            }else {
                a[k--] = b[j--] ;
            }
        }
        while ( j >= 0 ) {
            a[k--] = b[j--] ;
        }
    }
};