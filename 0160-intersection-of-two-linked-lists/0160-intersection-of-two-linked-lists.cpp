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
        if (!headA || !headB) return nullptr;
        ListNode* currA = headA;
        ListNode* currB = headB;
        // Edge case protection: currA != currB. For example, listA = [1], listB = [1], skipA = 0, skipB = 0.
        while (currA && currB && currA != currB) {
            currA = currA->next;
            currB = currB->next;
            if (currA == currB) return currA;
            if (!currA) currA = headB;
            if (!currB) currB = headA;

            // WRONG: Move two steps on the linked list!! It causes a forever loop!
            // if (currA == currB) return currA;
            // currA = currA->next;
            // currB = currB->next;
            // if (!currA) currA = headB;
            // if (!currB) currB = headA;

        }
        return currA;
    }
};