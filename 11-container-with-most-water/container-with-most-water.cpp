class Solution {
public:
    // Dunzo
    // Flipkart
    int maxArea(vector<int>& height) {
        // Naive Approach : Nested loops : brute for each pair of sticks and calculate the maxx out of that
        // TC : O(N ** 2) , SC : O(1) 

        // Optimal Approach : 2-pointer Approach : moving the pointer at the shorter height to potentially get a taller line and a larger area 
        // TC : O(N) , SC : O(1) 

        int n = height.size() ;
        int left = 0 , right = n - 1 ;
        int maxArea = 0 ;

        while ( left < right ) {
            int width = right - left ;
            int curr = min ( height[left] , height[right] ) ;

            int currArea = curr * width ;
            maxArea = max ( maxArea , currArea ) ;

            if ( height[left] <= height[right] ) left++ ;
            else right-- ;
        }

        return maxArea ;
    }
};