/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengA = 0, lengB = 0;
        ListNode* currA = headA;
        ListNode* currB = headB;
        // find the length of linked lists
        while (currA) {
            currA = currA->next;
            lengA++;
        }
        while (currB) {
            currB = currB->next;
            lengB++;
        }

        // adjust the starter
        currA = headA;
        currB = headB;
        int lengDiff = abs(lengA - lengB);
        while (lengDiff != 0) {
            if (lengA > lengB) currA = currA->next;
            else currB = currB->next;
            lengDiff--;
        };

        // find the intersection
        while (currA && currB) {
            if (currA == currB) return currA;
            currA = currA->next;
            currB = currB->next;
        }
        return nullptr;
    }
};