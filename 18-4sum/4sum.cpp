class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        int n = a.size() ;
        sort ( a.begin() , a.end() ) ;
        set<vector<int>> s ;
        
        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = i + 1 ; j < n ; j++ ) {
                for ( int k = j + 1 ; k < n ; k++ ) {
                    long t = target ;
                    t -= a[i] ;
                    t -= a[j] ;
                    t -= a[k] ;
                    // binary search to find the remaining sum 
                    int l = k + 1 , h = n - 1 ;
                    while ( l <= h ) {
                        int mid = l + (h - l) / 2 ;
                        if ( a[mid] == t ) {
                            vector<int> b ;
                            b.push_back(a[i]) ;
                            b.push_back(a[j]) ;
                            b.push_back(a[k]) ;
                            b.push_back(a[mid]) ;
                            s.insert(b) ;
                            break ;
                        }else if ( a[mid] < t ) {
                            l = mid + 1 ;
                        }else {
                            h = mid - 1 ;
                        }
                    }
                }
            }
        }
        
        vector<vector<int>> ans ( s.begin() , s.end() ) ;
        
        return ans ;
    }
};