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
ListNode* mergeTwoLists(ListNode* A, ListNode* B) {

    ListNode* headA = A;
    ListNode* headB = B;
    ListNode* currentA = A;
    ListNode* currentB = B;
    ListNode* newLinkListHead;
    ListNode* currentNew;

    if(headA == NULL)
    {
        return headB;
    }
    else if(headB == NULL)
    {
        return headA;
    }

    if(currentA->val < currentB->val)
    {
        newLinkListHead = currentA;
        currentA = currentA->next;
    }
    else
    {
        newLinkListHead = currentB;
        currentB = currentB->next;
    }
    currentNew = newLinkListHead;
    do
    {
        if(currentA->val <= currentB->val)
        {
            currentNew->next = currentA;
            currentNew = currentNew->next;
            currentA = currentA->next;
        }
        else
        {
            currentNew->next = currentB;
            currentNew = currentNew->next;
            currentB = currentB->next;
        }

    }while(currentA!=NULL && currentB!=NULL);
    if(currentA==NULL)
    {
        // currentNew->next = currentA;
        // currentNew = currentNew->next;
        currentNew->next = currentB;
    }
    else
    {
        // currentNew->next = currentB;
        // currentNew = currentNew->next;
        currentNew->next = currentA;
    }
    return newLinkListHead;

}

int main() {

    int SIZE_A = 8, SIZE_B = 7;
    int A[SIZE_A] = {1, 2, 4, 8, 9, 10, 13,19};
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

    current = mergeTwoLists(head_A, head_B);
    do
    {
        std::cout << current->val <<'\n';
        current = current->next;
    } while (current!=NULL);
    
}