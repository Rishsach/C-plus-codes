#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    node* next;
};

void print(node*);

struct node* create_node(int x)
{
    struct node* temp = new node;
    temp -> data = x;
    temp -> next = NULL;
    return temp;
}

void push(node** head, int x)
{
    struct node* store = create_node(x);
    if (*head == NULL) {
        *head = store;
        return;
    }
    struct node* temp = *head;
    while (temp -> next) {
        temp = temp -> next;
    }
    temp -> next = store;
}

void split_list(node* head, node** a, node** b)
{
    struct node* fast = head -> next;
    struct node* slow = head;
    while (fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    struct node* temp = slow -> next;
    slow -> next = NULL;
    *a = head;
    *b = temp;
}

struct node* reverse(node* b)
{
    struct node* curr = b;
    struct node* next = NULL;
    struct node* prev = NULL;
    while (curr != NULL) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void merge(node* a, node* b, node** c)
{
    struct node* temp = a;
    *c = create_node(0);
    struct node* curr = *c;
    while (temp && b) {
        curr -> next = create_node(temp -> data - b -> data);
        b = b -> next;
        temp = temp -> next;
        curr = curr -> next;
        
    }
    if (b != NULL) {
        curr -> next = b;
        curr = curr -> next;
    }
    curr -> next = reverse(a);
    *c = (*c) -> next;
}

struct node* modifyTheList(struct node* head)
{
    
    struct node* a;
    struct node* b;
    struct node* c;
    split_list(head, &a, &b);
    struct node* temp = reverse(b);
    merge(temp, a, &c);
    return c;
}

void print(node* head)
{
    struct node* temp = head;
    while (temp) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

int main()
{
    struct node* l = NULL;
    push(&l, 1);
    push(&l, 2);
    push(&l, 3);
    push(&l, 4);
    push(&l, 5);
    push(&l, 6);
    cout << "Before the modify operation" << endl;
    print(l);
    l = modifyTheList(l);
    cout << "\nAfter the modify operation" << endl;
    print(l);

    return 0;
}
