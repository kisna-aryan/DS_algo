// Your First C++ Program


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <vector>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
ListNode* solve(ListNode* A) {
    ListNode* head = A;
    ListNode* curr = A;
    ListNode* prev = NULL;
    while (curr != NULL && curr->next != NULL)
    {
        int temp_val = curr->val;
        curr->val = curr->next->val;
        curr->next->val = temp_val;

        // struct ListNode* temp = curr->next;
        // curr->next = temp->next;
        // temp->next = curr;
 
        // if (prev == NULL) {
        //     head = temp;
        // }
        // else {
        //     prev->next = temp;
        // }
 
        // prev = curr;
        curr = curr->next->next;
    }
    return head;
}


int main() {

    int SIZE = 18;
    int A[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17 };
    // int A[SIZE] = {0,1};
    ListNode * head_m = new ListNode(0);
    ListNode * current = head_m;

    for(int i =1;i<SIZE;i++)
    {
            current->next = new ListNode(A[i]);
            current = current->next;
    } 

    int counter = 0;
    current = head_m;
    do
    {
        std::cout << current->val << ' '<< current->next<<'\n';
        current = current->next;
    } while (current!=NULL);

    current = solve(head_m);
    do
    {
        std::cout << current->val <<'\n';
        current = current->next;
    } while (current!=NULL);
    
}