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
ListNode* solve(ListNode* A, int B) {
    int counter = 0, next_count = 0;
    ListNode* head;
    ListNode* temp;
    ListNode* current = A;
    if (current->next == NULL)
    {
        return head;
    }
    else
    {
        head = A;
    }

    while(current->next!=NULL)
    {
        current = current->next;
        ++counter;
    }
    if (counter < B)
    {
        head = head->next;
        return head;
    }
    next_count = counter - B;
    current = head;
    for(int i = 0; i<next_count;i++)
    {
        current = current->next;
    }
    temp = current->next;
    current->next = current->next->next;
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

    current = solve(head_m, 1);
    do
    {
        std::cout << current->val <<'\n';
        current = current->next;
    } while (current!=NULL);
    
}