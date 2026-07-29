class Solution {
public:
    bool asteroidsDestroyed(int m, vector<int>& a) {
        long long curr = m ;
        sort(a.begin() , a.end()) ;
        for (int x : a) {
            if ( x > curr ) return false ;
            curr += x ;
        }
        return true ;
    }
};