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
    int temp,counter = 0,counterS = 0,couterB = 0;
    while (current->next != NULL)
    {
        current = current->next;
        counter++;
    }
    currentEnd = current;
    counter++;
    B = B%counter;
    couterB = counter - B - 1;
    current = head;
    while(current != NULL && couterB>0)
    {
        current = current->next;
        couterB--;
    }
    currentEnd->next = head;
    head = current->next;
    current->next = NULL;

    return head;

}

int main() {

    int SIZE = 8, B = 89;
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