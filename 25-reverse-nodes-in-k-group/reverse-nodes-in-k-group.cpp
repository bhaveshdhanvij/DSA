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
    // Salesforce
    // Apple
    // Microsoft
    // Google
    // Amazon
    // Infosys
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Optimal Approach : Recursion with in-place Linked list reversal 
        // TC : O(N) , SC : O(N) - considering recursive stack

        // checking whether current group consist of k nodes or not 
        
        ListNode* temp = head ;
        int cnt = 0 ;

        while ( cnt < k ) {
            if ( temp == nullptr ) {
                return head ; // current gp is having less than k nodes 
            }
            temp = temp->next ;
            cnt++ ;
        }
        
        // recursive call for rest of the linked list
        ListNode* prev = reverseKGroup(temp , k) ;

        // reversing the current gp of k nodes 
        temp = head ;
        cnt = 0 ;

        while ( cnt < k ) {
            ListNode* next = temp->next ;
            temp->next = prev ;

            prev = temp ;
            temp = next ;
            cnt++ ;
        }

        return prev ; // new head of curr gp 
    }
};