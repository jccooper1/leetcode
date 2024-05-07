class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        head = reverseList(head);
        int maxVal = head->val;
        ListNode* current = head;
        ListNode* prev = nullptr;
        while (current != nullptr) {
            if (current->val < maxVal) {
                prev->next = current->next;
            } else {
                maxVal = current->val;
                prev = current;
            }
            current = current->next;
        }
        head = reverseList(head);
        return head;
    }

private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* nextTemp = current->next;
            current->next = prev;
            prev = current;
            current = nextTemp;
        }
        return prev;
    }
};