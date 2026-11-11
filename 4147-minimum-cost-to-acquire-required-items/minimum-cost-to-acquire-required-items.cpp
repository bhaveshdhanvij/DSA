class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long k = min ( need1 , need2 ) ;
        return k * min ( cost1 + cost2 , costBoth ) + (need1 - k) * min ( cost1 , costBoth ) +
            (need2 - k) * min ( cost2 , costBoth) ;
    }
};