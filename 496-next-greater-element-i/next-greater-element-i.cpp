class Solution {
public: 
    // Apple
    // Microsoft
    // Meta
    // Swiggy
    // Amazon
    // Google
    // Oracle
    // Morgan Stanley
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Optimal Approach : Calculate the NG for every element in nums2 and then map it for nums1 ans storage
        // TC : O(N + M) , SC : O(N + M) 
        
        unordered_map<int,int> mp ; // nums2 -> NG 
        stack<int> s ;

        for ( int i = nums2.size() - 1 ; i >= 0 ; i-- ) {
            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop() ;
            }     

            if ( s.empty() ) {
                mp[nums2[i]] = -1 ;
            }else {
                mp[nums2[i]] = s.top() ;
            }

            s.push(nums2[i]) ;
        }

        vector<int> ans ;
        
        for ( int i = 0 ; i < nums1.size() ; i++ ) {
            ans.push_back(mp[nums1[i]]) ;
        }

        return ans ;
    }
};