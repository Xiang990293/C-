//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// using namespace std;

// ListNode result;

// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* result = new ListNode(); // Initialize an empty ListNode
//         ListNode* current = result; // Pointer to the current node in result
//         int carry = 0;

//         while (l1 != nullptr || l2 != nullptr || carry != 0) {
//             int sum = carry;
//             if (l1 != nullptr) {
//                 sum += l1->val;
//                 l1 = l1->next;
//             }
//             if (l2 != nullptr) {
//                 sum += l2->val;
//                 l2 = l2->next;
//             }

//             carry = sum / 10; // Calculate the carry for the next iteration
//             sum = sum % 10; // Get the digit to add to the result

//             current->next = new ListNode(sum); // Create a new node for the result
//             current = current->next; // Move the pointer to the next node in the result
//         }

//         return result->next; // Skip the initial empty node, return the actual result
//     }
// };

// This is the version I wrote from start, but encounter a problem that I cant carry in the new digit after nullptr.
// And I send it to gpt and find out that "current = new ListNode(carry)" is not working, so modified like this:
class Solution {
public:
    int carry = 0;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *current = l1;
        while(current != nullptr || l2 != nullptr || carry != 0){
            if(current != nullptr && l2 != nullptr){
                current->val += carry;
                carry = 0;
                current->val += l2->val;
                if(current->val >= 10){
                    carry = current->val / 10;
                    current->val %= 10;
                }

				if(current->next == nullptr && (l2->next != nullptr || carry != 0)){
                    current->next = new ListNode();
                }

                current = current->next;
                l2 = l2->next;
            }else if(l2 == nullptr && carry != 0){
                current->val += carry;
                carry = 0;
                if(current->val >= 10){
                    carry = current->val / 10;
                    current->val %= 10;
                }

				if(current->next == nullptr && (l2->next != nullptr || carry != 0)){
                    current->next = new ListNode();
                }

                current = current->next;
            }else{
                break;
            }
        }

        return l1;
    }
};

