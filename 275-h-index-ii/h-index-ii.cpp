class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size() ;
        int low = 0 , high = n - 1 , mid ;
        while ( low <= high ) {
            mid = low + (high - low) / 2 ;
            if ( citations[mid] >= (n - mid) ) high = mid - 1 ;
            else low = mid + 1 ;
        }
        return n - low ;
    }
};