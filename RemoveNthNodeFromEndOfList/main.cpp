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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int listSize = 0;
        ListNode* counter = head;

        while(counter){
            listSize++;
            counter = counter->next;
        }

        if(listSize == n){
            ListNode* deletedNode = head;
            head = head->next;
            delete deletedNode;
            return head;
        }

        // cout << "the size of the list is: " << listSize << "\n";

        ListNode* current = head;

        for(int i = 1; i < listSize - n; i++){
            current = current->next;
        }

        ListNode* deletedNode = current->next;

        current->next = current->next->next;

        delete deletedNode;
        return head;
    }
};