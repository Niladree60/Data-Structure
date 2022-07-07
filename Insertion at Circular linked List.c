#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void cercularLinkedListTraversal(struct Node * head)
{
    struct Node * ptr = head;
    do
    {
        printf("Element : %d \n", ptr -> data);
        ptr = ptr -> next;
    }while(ptr  != head  );
}

struct Node * insertAtFirst(struct Node * head, int data)
{
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node * p = head -> next;
    ptr -> data = data;
    while(p -> next != head)
    {
        p = p -> next;
    }
    // at this point p points points to the last node of CLL
    p-> next = ptr;
    ptr -> next = head;
    head = ptr;
    return head;
}
int main()
{
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;

    // Allocate memory for nodes in the linked list in heap
    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));
    fourth = (struct Node *) malloc(sizeof(struct Node));

    // link first and second node
    head -> data = 4;
    head -> next  = second;

    // link second and third node
    second -> data = 3;
    second -> next  = third;

    // link third and fourth node
    third -> data = 6;
    third -> next  = fourth;

    // terminate the link at the third node
    fourth -> data = 1;
    fourth -> next  = head;
    printf("Before Insert\n");
    cercularLinkedListTraversal(head);
    head = insertAtFirst(head,80);

    printf("After Insert\n");
    cercularLinkedListTraversal(head);

    return 0;
}
