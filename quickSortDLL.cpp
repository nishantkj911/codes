#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
 
/* a Node of the doubly linked list */
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *lastNode(Node *root)
{
    while (root && root->next)
        root = root->next;
    return root;
}
void swap ( int* a, int* b )
{   int t = *a;      *a = *b;       *b = t;   }
 
Node* partition(Node *l, Node *h);
void _quickSort(struct Node* l, struct Node *h)
{
    if (h != NULL && l != h && l != h->next)
    {
        struct Node *p = partition(l, h);
        _quickSort(l, p->prev);
        _quickSort(p->next, h);
    }
}
 
void quickSort(struct Node *head)
{
    // Find last Node
    struct Node *h = lastNode(head);
 
    // Call the recursive QuickSort
    _quickSort(head, h);
}
// A utility function to print contents of arr
void printList(struct Node *head)
{
    while (head)
    {
        cout << head->data << "  ";
        head = head->next;
    }
    cout << endl;
}
 struct Node* newNode(int data){
	 struct Node *temp= (struct Node*)malloc(sizeof(struct Node));
	 temp->data=data;
	 temp->next=NULL;
	 temp->prev=NULL;
	 return temp;
	
	 }
	 
 
/* Driver program to test above function */
int main()
{
    int t,x,n,i;
  scanf("%d",&t);
  while(t--)
  {
  /* Start with the empty list */
  struct Node *p,*temp,*head = NULL;
   scanf("%d",&n);
  scanf("%d",&x);
head=newNode(x);
 p=head;
  for(i=0;i<n-1;i++){
  scanf("%d",&x);
   /* Let us create the doubly linked list 10<->8<->4<->2 */
	temp=newNode(x);
	 p->next=temp;
	 temp->prev=p;
       p=p->next;
  }
  //printList(head); 
  /* delete Nodes from the doubly linked list */
	
    quickSort(head);
  /* Modified linked list will be NULL<-8->NULL */
  printList(head);           
  while(head->next!=NULL)
  {
	  temp=head;
	  head=head->next;
	  free(temp);
	  }
	  free(head);
	}
    return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
/* a Node of the doubly linked list */
/*struct Node
{
    int data;
    Node *next;
    Node *prev;
};
   struct Node *lastNode(Node *root)
{
    while (root && root->next)
        root = root->next;
    return root;
}
void _quickSort(Node* l, Node *h)
{
    if (h != NULL && l != h && l != h->next)
    {
        struct Node *p = partition(l, h);
        _quickSort(l, p->prev);
        _quickSort(p->next, h);
    }
}
 
void quickSort(Node *head)
{
    // Find last Node
    struct Node *h = lastNode(head);
 
    // Call the recursive QuickSort
    _quickSort(head, h);
}*/
Node* partition(Node *left, Node *right){
    //Your code goes here
    Node *pivot = left;
    Node *l = left, *h = right, *swap = NULL;
    
    while (true)
    {
        // while (l != h && h->next != l && l->data <= pivot->data)
        while (l != right && l->data <= pivot->data)
            l = l->next;
            
        while (h != pivot && h->data > pivot->data)
            h = h->prev;
            
        if (l == h || h->next == l || h == pivot)
            break;
            
        // cout<<"Interchanging "<<h->data<<" and "<<l->data<<endl;
        int temp = h->data;
        h->data = l->data;
        l->data = temp;
        
        l = l->next;
        h = h->prev;
        
        /*for (Node *temp = left; temp != right->next; temp = temp->next)
            cout<<temp->data<<" ";
        cout<<endl;*/
    }
    
    if (l == right && l == h)
        swap = l;
    else
        swap = l->prev;
        
    
    // cout<<"Interchanging "<<swap->data<<" and "<<pivot->data<<endl;
    int temp = swap->data;
    swap->data = pivot->data;
    pivot->data = temp;
    
    return swap;
    
}