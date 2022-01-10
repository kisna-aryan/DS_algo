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
ListNode* solve(ListNode* A) {
    ListNode* head = A;
    vector <ListNode> vectList;
    ListNode* current = A;
    ListNode* previous;
    int temp,counter = 1,counterS = 0,middle = 0;
    while (current != NULL)
    {
        if(counter%2 == 0)
        {
            vectList[counter -1].push_back(current);
        }
        current = current->next;
        counter++;
    }
    middle = counter/2;
    current = head;
    while(current !=NULL)
    {
        if(counter%2==0)
        {
            if(counterS == 1)
            {
                counterS = 0;
                previous->val = current->val;
                current->val = temp;
            }
            else
            {
                temp = current->val;
                previous = current;
                counterS++;
            }

        }
        current = current->next;
        counter++;
    }
    return head;

}

int main() {

    int SIZE = 6;
    int A[SIZE] = {1, 2, 3, 4, 5, 6};
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

    current = solve(head_m);
    do
    {
        std::cout << current->val <<'\n';
        current = current->next;
    } while (current!=NULL);    
}