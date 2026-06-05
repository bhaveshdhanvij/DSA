/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // Uber
    // Adobe
    // Microsoft
    // Amazon
    // Meta
    // Google
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Brute Approach : Store values in vector and reverse the segment , later override the values over original ll 
        // TC : O(N) , SC : O(N)

        // Optimal Approach : Head insertion technique that reverses the sublist inplace without extra space
        // TC : O(N) , SC : O(1) 

        if ( head == nullptr || (left == right) ) {
            return head ;
        }

        ListNode* dummy = new ListNode(0) ;
        dummy->next = head ;
        
        ListNode* prev = dummy ;
        for ( int i = 1 ; i < left ; i++ ) {
            prev = prev->next ;
        }

        ListNode* curr = prev->next ; // start of the segment to be reversed 
        ListNode* nextnode = nullptr ;

        for ( int i = 0 ; i < right - left; i++ ) {
            nextnode = curr->next ;
            curr->next = nextnode->next ;
            nextnode->next = prev->next ;
            prev->next = nextnode ;
        }

        return dummy->next ;
    }
};