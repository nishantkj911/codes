*/
/*The function removes the loop from the linked list if present
You are required to complete this method*/
void removeTheLoop(Node *head)
{
    if (!head)
        return;
        
     //Your code here
     for(Node *temp = head; temp != NULL; temp = temp->next)
     {
         for (Node *temp2 = head; temp2 != temp; temp2 = temp2->next) // if loop is at head and there's only one node this won't work
         {
            if (temp2 == temp->next)
            {
                // cout<<"Loop found at "<<temp2->data<<endl;
                temp->next = NULL;
                return;
            }
         }
         
         // checking if it's a self loop
         if (temp == temp->next)
         {
            //  cout<<"found a self loop at "<<temp->data<<endl;
             temp->next = NULL;
             return;
         }
     }
}
