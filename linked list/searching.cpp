int searchInLinkedList(Node<int> *head, int k) {
    Node<int> *temp=head;
   
   while(temp){
       if(k==temp->data){
           return 1;
       }
        temp=temp->next;

   }
   return 0;
    // Write your code here.
}