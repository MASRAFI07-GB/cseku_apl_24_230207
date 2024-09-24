// create a linked list and delete the nth node from the last
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
void delete_node(struct node *&head, int n)
{
    struct node *current = head, *current1;
    int s = 0;
    while (current != NULL)
    {
        s++;
        current = current->next;
    }

    int x = s - n + 1;
    if (x == 1)
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
        if (cnt == x)
        {
            current->next = current1->next;
        }

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

    head = new node();
    cin >> head->data;
    tail = head;
    tail->next;

    num_of_nodes--;

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
    print(head);
    delete_node(head, n);
    print(head);
}
