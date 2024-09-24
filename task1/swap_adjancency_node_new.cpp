// create a linked list and swap two adjacency node
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
// swapping adjacency nodes
void swap_nodes(struct node *&head)
{

    struct node *current = head, *current1 = current->next, *dummy;

    dummy = head;

    int flag = 0;
    while (1)
    {

        // if the size of the list is 0 or 1
        if (current == NULL || current1 == NULL)
            break;

        // swapping two nodes
        current->next = current1->next;
        current1->next = current;
        // during the swapping of first two nodes head is changed. so we use flag to identify the first swapping and managed the head
        if (flag == 0)
        {
            // so that head is not changed
            head = current1;
            flag = 1;
            // updating current and current1 for first sswapping
            current = current->next;
            if (current == NULL)
                break;
            current1 = current->next;
            continue;
        }
        // updating current , current1 and dummy for other swapping
        dummy->next = current1;
        current = current->next;
        if (current == NULL)
            break;
        current1 = current->next;
        dummy = dummy->next->next;
    }
    return;
}

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

    // print the list before swaping the adjancency node
    print(head);

    swap_nodes(head);

    // print the list after swaping the adjancency node
    print(head);
}
