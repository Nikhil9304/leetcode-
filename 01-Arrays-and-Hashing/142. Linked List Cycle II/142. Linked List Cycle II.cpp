1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode(int x) : val(x), next(NULL) {}
7 * };
8 */
9class Solution {
10public:
11    ListNode *detectCycle(ListNode *head) {
12        ListNode* slow = head;
13        ListNode* fast = head;
14        while(fast!=nullptr && fast->next!=nullptr){
15            fast = fast->next->next;
16            slow = slow->next;
17            if(slow==fast){
18                slow = head;
19                // prev = NULL;
20                while(slow!=fast){
21                    slow = slow->next;
22                    // prev = fast; to remove cycle prev->next = nullptr
23                    fast = fast->next;
24                }
25                return slow;
26            }
27        }
28        return NULL;
29
30    }
31};