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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)  {
        ListNode*head , * pre, * now = nullptr;
        bool flag = 0;
        int result = l1->val + l2->val;
        head = new  ListNode(result % 10);
        flag = result >= 10;
        now = head;
        for (l1 = l1->next, l2 = l2->next; l1 != nullptr && l2 != nullptr;l1 = l1->next,l2 = l2->next)
        {
            pre = now;
            result = l1->val + l2->val+ flag;
            now = new ListNode(result % 10);
            flag = result >= 10;
            pre->next = now;
        }
        l1 ? l1 = l1 : l1 = l2;
        while (flag && l1 != nullptr)
        {
            l1->val = (l1->val + 1) % 10 ;
            flag = !l1->val;
            now->next = l1;
            now = l1;
            l1 = l1->next;
        }
        if (flag)    
            now->next = new ListNode(1);
        else
            now->next = l1;
        return head;
    }
};
