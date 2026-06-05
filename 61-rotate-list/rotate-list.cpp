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
    // Nvidia
    // Meta
    // Siemens
    // Adobe
    // Oracle
    // Amazon
    // Microsoft
    // Google
    // Infosys
    // Morgan Stanley
    ListNode* rotateRight(ListNode* head, int k) {
        // Approach 1 : Rotate list by 1 position exactly k times 
        // TC : O(K * N) , SC : O(1) 

        // Approach 2 : Storing nodes in vector and updates pointers using index cal 
        // TC : O(N) , SC : O(N) 

        // Optimal Approach : Greedy new tail will be at pos (n - k - 1) 
        // TC : O(N) , SC : O(1) 

        if (!head || k == 0 || !head->next) {
            return head ;
        }

        int n = 1 ;
        ListNode* tail = head ;
        while (tail->next) {
            n++ ;
            tail = tail->next ;
        }

        k = k % n ;

        if ( k == 0 ) {
            return head ;
        }

        tail->next = head ;
        
        int steps = n - k - 1 ;

        ListNode* curr = head ;
        while ( steps-- ) {
            curr = curr->next ;
        }

        ListNode* ans = curr->next ;

        curr->next = nullptr ;
        
        return ans ;
    }
};