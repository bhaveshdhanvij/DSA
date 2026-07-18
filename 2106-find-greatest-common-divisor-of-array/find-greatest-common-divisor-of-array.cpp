#include<numeric>
class Solution {
public:
    int findGCD(vector<int>& a) {
        int maxx = *max_element(a.begin() , a.end()) ;
        int minn = *min_element(a.begin() , a.end()) ;
        return std::gcd(minn , maxx) ;
    }
};