class Solution {
public:
    // Apple
    // Goldman Sachs
    // Adobe
    // Yahoo
    // IBM
    int findDuplicate(vector<int>& nums) {
        // Naive Approach : Use 2 for loops and identify if no. at two diff indices are same 
        // TC : O(N * N) , SC : O(1) 

        // Approach 2 : Using HashMap : counting frequencies of each element in the array 
        // TC : O(N) , SC : O(N) 

        // int n = nums.size() ;
        // unordered_map<int,int> mp ;
        // for ( int i = 0 ; i < n ; i++ ) {
        //     mp[nums[i]]++ ;
        //     if ( mp[nums[i]] == 2 ) {
        //         return nums[i] ;
        //     }
        // }
        // return -1 ;

        // Optimal Approach : Using Maths basic 
        // TC : O(N) , SC : O(1) 

        int n = nums.size() ;
        
        int slow = nums[0] , fast = nums[0] ;
        while ( true ) {
            slow = nums[slow] ;
            fast = nums[nums[fast]] ;
            if ( slow == fast ) break ;
        }

        slow = nums[0] ;
        while ( slow != fast ) {
            slow = nums[slow] ;
            fast = nums[fast] ;
        }

        return slow ;
    }
};