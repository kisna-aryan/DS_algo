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
    ListNode *head = A;
    ListNode *current = A;
    ListNode *previous;
    int counter = 0;
    if(current->val==0 && current->next==NULL)
    {
        return A;
    }
    else if(current->val==0 && current->next!=NULL)
    {
        current = current->next;
    }

    while(current->next != NULL)
    {
        if (current->val==1)
        {
            previous = current;
            current = current->next;
        }
        else
        {
            previous->next = current->next;
            current->next = head;
            head = current;
            current=previous;
        }
        counter += 1;
    }
    if(current->val ==0)
    {
            previous->next = NULL;
            current->next = head;
            head = current;
    }
return head;
}

int main() {

    int SIZE = 18;
    int A[SIZE] = {0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0 };
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