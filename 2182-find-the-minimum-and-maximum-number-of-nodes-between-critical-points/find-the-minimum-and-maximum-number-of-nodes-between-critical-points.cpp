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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int c = 2 ;
        vector<int> a ;
        ListNode* prev = head ;
        ListNode* curr = head->next ;
        while ( curr && curr->next ) {
            if ( (curr->val > prev->val && curr->val > curr->next->val) || 
                (curr->val < prev->val && curr->val < curr->next->val) ) {
                    a.push_back(c) ;
            }
            prev = curr ;
            curr = curr->next ;
            c++ ;
        }
        int minn = INT_MAX ;
        if ( a.size() < 2 ) return {-1 , -1} ;
        for (int i = 1 ; i < a.size() ; i++ ) {
            minn = min ( minn , a[i] - a[i - 1] ) ;
        }
        return {minn , a.back() - a.front() } ;
    }
};