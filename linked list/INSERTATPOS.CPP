Node* insert(Node* head, int n, int pos, int val) {
    Node* newNode = new Node(val);
    
    // Special case: Insert at position 0 (beginning)
    if (pos == 0) {
        newNode->next = head;
        return newNode;
    }
    
    // Traverse to position (pos-1)
    Node* temp = head;  // Use temp, don't modify head!
    int size = 0;       // Declare OUTSIDE the loop
    
    while (temp != NULL && size < pos - 1) {
        temp = temp->next;
        size++;
    }
    
    // Check if position is valid
    if (temp == NULL) {
        delete newNode;
        return head;
    }
    
    // Insert the node
    newNode->next = temp->next;
    temp->next = newNode;
    
    return head;
}