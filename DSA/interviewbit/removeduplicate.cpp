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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* deleteDuplicates(ListNode* A) {

    ListNode* head;
    ListNode* current = A;
    ListNode* previous;
    while(current != NULL && current->next !=NULL)
    {
        if(current->val == current->next->val)
        {
            current = current->next;
        }
        else
        {
            previous = current;
            head = current;
            current = current->next;
            break;
        }
    }
    if(current == 0)
    {
        return head;
    }    
        
   while(current->next != NULL)
    {
        if(current->val == current->next->val)
        {
            current = current->next->next;
        }
        else
        {
            previous->next = current;
            previous =previous->next;
            current = current->next;
        }
    }
    return head;

}

int main() {

    int SIZE_A = 8, SIZE_B = 7;
    int A[SIZE_A] = {1, 1, 1, 1, 1, 1, 1,1};
    int B[SIZE_B] = {3, 5, 8,14,15,17,19};
    // int A[SIZE] = {0,1};
    ListNode * head_A = new ListNode(1);
    ListNode * head_B = new ListNode(3);

    ListNode * current = head_A;
    for(int i =1;i<SIZE_A;i++)
    {
            current->next = new ListNode(A[i]);
            current = current->next;
    } 

    current = head_B;

    for(int i =1;i<SIZE_B;i++)
    {
            current->next = new ListNode(B[i]);
            current = current->next;
    }

    int counter = 0;
    current = head_A;
    do
    {
        std::cout << current->val << ' '<< current->next<<'\n';
        current = current->next;
    } while (current!=NULL);

    current = deleteDuplicates(head_A);
    do
    {
        std::cout << current->val <<'\n';
        current = current->next;
    } while (current!=NULL);
    
}