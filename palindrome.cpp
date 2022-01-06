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
int solve(ListNode* A) {
    ListNode* head = A;
    stack <int> s;
    int counter = 0, middle=0;
    ListNode* current = A;
    while(current != NULL)
    {
        counter++;
        s.push(current->val);
        current = current->next;
    }
    middle = counter/2;
    current = head;
    while(current != NULL && middle >0)
    {
        middle--;
        int val_temp = s.top();
        if(current->val == val_temp)
        {
            s.pop();
            current = current->next;
        }
        else
        {
            return 0;
        }
    }
    return 1;

}



int main() {

    int SIZE = 21;
    int A[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
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

    cout << solve(head_m);    
}