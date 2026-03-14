class Solution {
public:
    int smallestDistancePair(vector<int>& a, int k) {
        sort ( a.begin() , a.end() ) ;
        int l = 0 , h = a.back() - a.front() ;

        while ( l < h ) {
            int mid = l + (h - l) / 2 ;

            int c = 0 , left = 0 ;
            for ( int right = 0 ; right < a.size() ; right++ ) {
                while ( a[right] - a[left] > mid ) left++ ;
                c += right - left ;
            }

            if ( c >= k ) h = mid ;
            else l = mid + 1 ;
        }

        return l ;
    }
};