// create a linked list and swap two adjacency node
#include <bits/stdc++.h>
using namespace std;
struct node
{
  int data;
  struct node *next;
};
void print(struct node *&head)
{
  struct node *current = head;
  while (current != NULL)
  {
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl;
}

void swap_nodes(struct node *&head)
{
 
  struct node *current = head, *current1 = current->next, *dummy;
  
  dummy = head;
  
  int flag = 0;
  while (1)
  {
    
    if (current == NULL || current1 == NULL)
      break;
    current->next = current1->next;
    current1->next = current;
    if (flag == 0)
    {
      head = current1;
      flag = 1;
      current = current->next;
      if (current == NULL)
        break;
      current1 = current->next;
      continue;
    }
    dummy->next = current1;
    current = current->next;
    if (current == NULL)
      break;
    current1 = current->next;
    dummy = dummy->next->next;
  }
  return;
}

int main()
{
  int n;
  cin >> n;
  struct node *head, *tail, *current;
  head = new node();
  cin >> head->data;
  tail = head;
  tail->next;
  n--;
  while (n--)
  {
    int x;
    cin >> x;
    current = new node();
    current->data = x;
    tail->next = current;
    tail = current;
    tail->next = NULL;
  }

  print(head);
  swap_nodes(head);
  print(head);
}
