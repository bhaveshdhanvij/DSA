/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    // Meta
    // Apple
    // Amazon
    Node* flatten(Node* head) {
        // Approach : Basic recursion
        // TC : O(N) , SC : O(D) depth - considering recursive stack 
        
        if ( head == nullptr ) return head ;
        
        Node* curr = head ;

        while ( curr != nullptr ) {
            if ( curr->child != nullptr ) {
                // flatten the child nodes 
                Node* next = curr->next ;

                curr->next = flatten(curr->child) ;

                curr->next->prev = curr ;
                curr->child = nullptr ;

                // find tail 

                while ( curr->next != nullptr) {
                    curr = curr->next ;
                }

                // attach tail with next ptr 

                if ( next != nullptr ) {
                    curr->next = next ;
                    next->prev = curr ;
                }
            }

            curr = curr->next ;
        }

        return head ;
    }
};