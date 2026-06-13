class Solution {
public:
    ListNode* reverse(ListNode* start, ListNode* end) {
        ListNode* prev = nullptr;
        ListNode* curr = start;

        while (curr != end) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ptr = head;
        int count = 0;

        while (ptr != nullptr && count < k) {
            ptr = ptr->next;
            count++;
        }

        if (count < k)
            return head;

        ListNode* newHead = reverse(head, ptr);

        head->next = reverseKGroup(ptr, k);

        return newHead;
    }
};