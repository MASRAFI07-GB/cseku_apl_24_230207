// create a linked list and delete the nth node from the last
#include <bits/stdc++.h>
using namespace std;
struct node
{
  int data;
  struct node *next;
};
// printing the list
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

void delete_nth_node_from_last(struct node *&head, int n)
{
  struct node *current = head, *current1;
  int size = 0;
  // taking the size of the current list
  while (current != NULL)
  {
    size++;
    current = current->next;
  }

  // taking the index of the deleting node from the first
  int index = size - n + 1;
  // when size of the list is 1
  if (index == 1)
  {
    head = head->next;
    return;
  }

  current = head;
  current1 = current->next;
  int cnt = 1;
  while (current1 != NULL)
  {
    cnt++;
    if (cnt == index)
    {
      // deleting the node
      current->next = current1->next;
    }

    // updating current and current1
    current = current->next;
    current1 = current1->next;
  }

  return;
}

int main()
{
  int num_of_nodes;
  cin >> num_of_nodes;
  struct node *head, *tail, *current;
  // createing the head of the list
  head = new node();
  cin >> head->data;
  tail = head;
  tail->next;
  // size is decreased by one as one element is already taken
  num_of_nodes--;
  // createing the whole list
  while (num_of_nodes--)
  {
    int element;
    cin >> element;
    current = new node();
    current->data = element;
    tail->next = current;
    tail = current;
    tail->next = NULL;
  }

  int n;
  cin >> n;

  cout << "print the list before deleting the nth node from the last:" << endl;
  print(head);
  delete_nth_node_from_last(head, n);
  cout << "print the list after deleting the nth node from the last:" << endl;
  print(head);
}
