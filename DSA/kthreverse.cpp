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
#include<bits/stdc++.h>

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
ListNode* solve(ListNode* A, int B) {
    ListNode* head = A;
    ListNode* current = A;
    ListNode* currentEnd;
    ListNode* currentStart;
    ListNode* temp;
    ListNode* currentHead = A;
    int counter = 0,counterS = 0,couterB = 0;
    while (current->next != NULL)
    {
        current = current->next;
        counter++;
    }
    counter++;
    couterB = B;
    current = head;
    while(current->next != NULL)
    {
        couterB--;
        if(couterB<=0)
        {
            couterB = B;
            temp = current;
            currentEnd = current;
            currentHead->next = current->next;
            currentEnd->next = currentHead;
            current = temp->next;
        }
        else
        {
            current = current->next;
        }
    }

    return head;

}

int main() {

    int SIZE = 8, B = 2;
    int A[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8};
    // int A[SIZE] = {0,1};
    ListNode * head_m = new ListNode(1);
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

    current = solve(head_m, B);
    do
    {
        std::cout << current->val <<'\n';
        current = current->next;
    } while (current!=NULL);    
}