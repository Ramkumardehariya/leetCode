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
    Node* flatten(Node* head) {
        

        Node* curr = head;
        
        while(curr != NULL){

            while(curr->child != NULL){
                
                Node* temp = curr->child;

                while(temp->next != NULL){
                    temp = temp->next;
                }
                temp->next = curr->next;
                if(curr->next != NULL){
                    curr->next->prev = temp;
                }
                curr->child->prev = curr;
                curr->next = curr->child;
                curr->child = NULL;
            }
            
            curr = curr->next;
        }
        return head;
    }
};