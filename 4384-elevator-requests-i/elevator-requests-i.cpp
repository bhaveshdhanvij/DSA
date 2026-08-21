class Solution {
public:
    int elevatorRequests(int n, vector<int>& a) {
        int ans = a[0] ;
        for ( int i = 1 ; i < a.size() ; i++ ) {
            ans += abs(a[i] - a[i - 1]);
        }
        return ans ;
    }
};