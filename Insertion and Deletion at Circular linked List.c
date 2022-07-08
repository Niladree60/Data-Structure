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
// Insertion after node in circular linked list 
struct node* insertionafternode(struct node* head, int data , struct node* prevnode){
    struct node* ptr= (struct node*) malloc (sizeof(struct node));
    struct node*p= head;
    while(p!= prevnode){
        p=p->next;
    }
    if(p==prevnode){
        ptr->next=p->next;
        p->next=ptr;
        ptr->data=data;

    }
    return head;
}

// insert after a given node in the  circular linklist
node *insertafternode(node *head, node *prenode, int data)
{
    node *ptr = new node();
    ptr->data = data;

    ptr->next = prenode->next;
    prenode->next = ptr;
    return head;
}

// Insertion at Last node in circular linked list
struct node *insertionatlastnode(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    if (p->next == head)
    {
        p->next = ptr;
        ptr->next = head;
        ptr->data = data;
    }
    return head;
}


// delete by Value
struct node *DeletebyValue(struct node *head, int value)
{
    struct node *p = head;
    struct node *q = head->next;

    

    while (q->data != value )
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }

    return head;
}
// Deletion at any index in circular linked list
struct node* deletionatindex(struct node* head, int index){
    struct node*p= head;
    struct node* q= head->next;
    for(int i =0; i< index-1; i++){
        q=q->next;
        p=p->next;
    }
    p->next=q->next;
    free(q);
    return head;
    
}

// Deletion of first node in circular linked list
struct node* deletionatfirstnode(struct node* head){
    struct node*ptr=head;
    while(ptr->next!= head){
        ptr=ptr->next;
    }
        struct node*p= head;
        ptr->next=head->next;
        head= head->next;
        free(p);
        return head;
      
}
// Deletion of value in circular linked list
struct node* deletionofvalue(struct node* head, int value){
    struct node*p= head;
    struct node* q= head-> next;
    while(q->data != value){
        q=q->next;
        p=p->next;
    }
    if(q->data==value){
        p->next=q->next;
        free(q);
        return head;
    }
   
}
// delete a last node of the cicular linkedlist
node*deletelastnode(node*head){
    node*p=head;
    node*q=head->next;
    while (q->next!=head)
    {
        p=p->next;
        q=q->next;
    }
    p->next=head;
    free(q);
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
