class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0); // Dummy node to simplify list construction
        ListNode* current = dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            // Extract values or use 0 if the list is null
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            // Calculate the sum and the carry
            int sum = val1 + val2 + carry;
            carry = sum / 10;

            // Create a new node with the current digit
            current->next = new ListNode(sum % 10);
            current = current->next;

            // Move to the next nodes
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return dummy->next; // Return the next of dummy as the actual head
    }
};
