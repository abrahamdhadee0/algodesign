#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int value;
    node* next;

    node(int value){
        this->value=value;
        next=nullptr;
    }
};

class linkedlist{
    public:
    node* head;
    node* tail;
    int size;

   linkedlist(){
    head=nullptr;
    tail=nullptr;
    size=0;
   }
 void insertathead(int value){
    node* newnode = new node(value);
    if(size == 0){
        head = newnode;
        tail = newnode;
    } else {
        newnode->next = head;
        head = newnode;
    }
    size++;
}

void inserattail(int value){
    node *newnode = new node(value);
    if(size == 0){
        head = newnode;
        tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
    size++;
}

void insertatpos(int value, int pos){
    if(pos < 0 || pos > size){
        cout << "Invalid position" << endl;
        return;
    }
    if(pos == 0){
        insertathead(value);
        return;
    }
    if(pos == size){
        inserattail(value);
        return;
    } 
    node* newnode = new node(value);
    node* temp = head;
    for(int i = 0; i < pos - 1; i++){
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    size++;
}

void deleteathead(){
    if(size == 0){
        cout << "List is empty" << endl;
        return;
    }
    node* temp = head;
    head = head->next;
    delete temp;
    size--;
    if(size == 0) tail = nullptr; // important
}

void deleteattail(){
    if(size == 0){
        cout << "List is empty" << endl;
        return;
    }
    if(size == 1){
        delete head;
        head = tail = nullptr;
        size = 0;
        return;
    }
    node* temp = head;
    while(temp->next != tail){
        temp = temp->next;
    }
    delete tail;
    tail = temp;
    tail->next = nullptr;
    size--;
}

void deleteatpos(int pos){
    if(pos < 0 || pos >= size){
        cout << "Invalid position" << endl;
        return;
    }
    if(pos == 0){
        deleteathead();
        return;
    }
    if(pos == size - 1){
        deleteattail();
        return;
    }
    node* temp = head;
    for(int i = 0; i < pos - 1; i++){
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
    size--;
}
void display(){
    node* temp = head;
    while(temp != nullptr){
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
int searchInLinkedList(node *head, int k) {
   node* temp=head;
   while(temp){
       if(temp->value==k){
           return 1;
       }
       temp=temp->next;
   }
   return 0;
}
    ListNode* reverseList(ListNode* head) {
         ListNode* prev = NULL;  // What comes before first node?
    ListNode* current =head;  // Where to start?
    while(current !=NULL) {  // When to stop?
      ListNode* next = current->next;     // Save CURRENT's next
         current->next = prev;               // Reverse: current points to prev
        prev = current;                     // Move prev to current
        current = next;                     //urrentto                                           
    }   
    return prev; 
    }
    class Solution {
public:
    ListNode* reverseList(ListNode* head) {
         ListNode* prev = NULL;  // What comes before first node?
    ListNode* current =head;  // Where to start?
    while(current !=NULL) {  // When to stop?
      ListNode* next = current->next;     // Save CURRENT's next
         current->next = prev;               // Reverse: current points to prev
        prev = current;                     // Move prev to current
        current = next;                     //urrentto                                           
    }   
    return prev; 
    }
};
}
};
int main(){
linkedlist l1;
l1.insertathead(10);
l1.insertathead(20);
l1.insertathead(30);
 l1.display();  
}
# LinkedList Code - Complete Line by Line Explanation

## Header and Namespace

```cpp
#include <bits/stdc++.h>
```
- Includes all standard C++ libraries (iostream, vector, algorithm, etc.)
- **Note**: Good for competitive programming, but in production use specific headers like `#include <iostream>`

```cpp
using namespace std;
```
- Allows you to write `cout` instead of `std::cout`
- Brings all std namespace members into global scope

---

## Node Class Definition

```cpp
class node{
```
- Defines a class named `node` (lowercase - consider using `Node` for convention)

```cpp
public:
```
- Makes all following members accessible from outside the class

```cpp
int value;
```
- Stores the actual data of the node (the integer value)

```cpp
node* next;
```
- Pointer to the next node in the list
- Type: pointer to a `node` object
- This creates the "link" in the linked list

```cpp
node(int value){
```
- Constructor: automatically called when you create a new node
- Takes one parameter: the value to store

```cpp
this->value=value;
```
- `this->value` refers to the member variable
- `value` (right side) refers to the parameter
- Assigns the parameter to the member variable
- **Why `this->`?** Because parameter and member have the same name

```cpp
next=nullptr;
```
- Initializes the `next` pointer to `nullptr` (points to nothing)
- Good practice: always initialize pointers!
- `nullptr` is C++11 way of saying "null pointer"

---

## LinkedList Class Definition

```cpp
class linkedlist{
```
- Defines the LinkedList class that manages the nodes

```cpp
public:
```
- All members are public (accessible from anywhere)

```cpp
node* head;
```
- Pointer to the first node in the list
- If list is empty, `head = nullptr`
- This is your "entry point" to the entire list

```cpp
node* tail;
```
- Pointer to the last node in the list
- Allows O(1) insertion at the end
- Without tail, inserting at end would be O(n)

```cpp
int size;
```
- Keeps track of how many nodes are in the list
- Allows O(1) size lookup instead of O(n) traversal

---

## LinkedList Constructor

```cpp
linkedlist(){
```
- Constructor: called when you create a LinkedList object
- No parameters (default constructor)

```cpp
head=nullptr;
tail=nullptr;
size=0;
```
- Initializes empty list
- No nodes yet, so head and tail point to nothing
- Size is 0

**Visual:**
```
head → nullptr
tail → nullptr
size = 0
```

---

## Insert at Head Function

```cpp
void insertathead(int value){
```
- Adds a new node at the beginning of the list
- **Time Complexity:** O(1) - constant time!

```cpp
node* newnode = new node(value);
```
- Creates a new node on the heap using `new`
- Calls node constructor with the value
- `newnode` is a pointer to this newly created node

```cpp
if(size == 0){
```
- Checks if list is empty
- **Why check?** Empty list is a special case

```cpp
head = newnode;
tail = newnode;
```
- If empty: new node is both first AND last
- Both head and tail point to same node

**Visual (empty list):**
```
Before: head → nullptr, tail → nullptr
After:  head → [10] ← tail
```

```cpp
} else {
```
- List already has nodes

```cpp
newnode->next = head;
```
- Make new node point to current first node
- This creates the link!

```cpp
head = newnode;
```
- Update head to point to new node
- New node is now the first node

**Visual (non-empty list):**
```
Before: head → [20] → [30] → nullptr
                              ↑ tail

Step 1: newnode → [10]
        newnode->next = head

        [10] → [20] → [30] → nullptr
         ↑      ↑              ↑
      newnode  head           tail

Step 2: head = newnode

After:  [10] → [20] → [30] → nullptr
         ↑                      ↑
        head                   tail
```

```cpp
size++;
```
- Increment size counter
- Now we have one more node

---

## Insert at Tail Function

```cpp
void inserattail(int value){
```
- Adds a new node at the end of the list
- **Time Complexity:** O(1) - because we have tail pointer!

```cpp
node *newnode = new node(value);
```
- Create new node with the value

```cpp
if(size == 0){
    head = newnode;
    tail = newnode;
```
- Same as insertathead for empty list
- New node is both first and last

```cpp
} else {
```
- List has nodes

```cpp
tail->next = newnode;
```
- Make current last node point to new node
- Links new node into the list

```cpp
tail = newnode;
```
- Update tail to point to new node
- New node is now the last node

**Visual:**
```
Before: [10] → [20] → nullptr
         ↑              ↑
        head          tail

Step 1: tail->next = newnode
        [10] → [20] → [30]
         ↑      ↑      ↑
        head   tail  newnode

Step 2: tail = newnode
        [10] → [20] → [30] → nullptr
         ↑              ↑
        head          tail
```

```cpp
size++;
```
- Increment size

---

## Insert at Position Function

```cpp
void insertatpos(int value, int pos){
```
- Inserts node at specific position (0-indexed)
- pos=0 means beginning, pos=size means end

```cpp
if(pos < 0 || pos > size){
```
- Validates position
- `pos < 0`: negative position is invalid
- `pos > size`: can't insert beyond the list (gap would exist)
- **Note:** `pos == size` is valid (insert at end)

```cpp
cout << "Invalid position" << endl;
return;
```
- Print error message
- Exit function early (don't insert)

```cpp
if(pos == 0){
    insertathead(value);
    return;
```
- Special case: inserting at beginning
- Reuse existing function (code reusability!)
- Exit after insertion

```cpp
if(pos == size){
    inserattail(value);
    return;
```
- Special case: inserting at end
- Reuse existing function
- Exit after insertion

```cpp
node* newnode = new node(value);
```
- Create new node (only if middle insertion)

```cpp
node* temp = head;
```
- Start traversal from head
- `temp` is our "walker" pointer

```cpp
for(int i = 0; i < pos - 1; i++){
```
- Loop to reach node at position (pos-1)
- **Why pos-1?** We need the node BEFORE insertion point

**Example:** Insert at pos=2
```
[10] → [20] → [30] → nullptr
  0      1      2
  
We need to reach node at index 1 (pos-1)
So we can insert AFTER it
```

```cpp
temp = temp->next;
```
- Move temp to next node
- After loop, temp is at position (pos-1)

```cpp
newnode->next = temp->next;
```
- Make new node point to node at position `pos`
- This preserves the link to the rest of the list

```cpp
temp->next = newnode;
```
- Make node at (pos-1) point to new node
- This inserts new node into the list

**Visual (insert 25 at pos=2):**
```
Before: [10] → [20] → [30] → nullptr
         0      1      2

Step 1: temp reaches node 20 (pos-1=1)
        [10] → [20] → [30] → nullptr
                ↑
               temp

Step 2: newnode->next = temp->next
        [25] → [30]
         ↑
       newnode

Step 3: temp->next = newnode
        [10] → [20] → [25] → [30] → nullptr
```

```cpp
size++;
```
- Increment size

---

## Delete at Head Function

```cpp
void deleteathead(){
```
- Removes first node
- **Time Complexity:** O(1)

```cpp
if(size == 0){
    cout << "List is empty" << endl;
    return;
```
- Can't delete from empty list
- Guard clause

```cpp
node* temp = head;
```
- Store head in temp (we'll delete this)

```cpp
head = head->next;
```
- Move head to second node
- Second node becomes new first node

```cpp
delete temp;
```
- Free memory of old first node
- **Important:** Prevents memory leak!

```cpp
size--;
```
- Decrement size

```cpp
if(size == 0) tail = nullptr;
```
- **Critical!** If we deleted the only node, tail should also be nullptr
- Otherwise tail would point to deleted memory (dangling pointer!)

**Visual:**
```
Before: [10] → [20] → [30] → nullptr
         ↑                      ↑
        head                   tail
        temp

Step 1: head = head->next
        [10]   [20] → [30] → nullptr
         ↑      ↑              ↑
        temp   head           tail

Step 2: delete temp
               [20] → [30] → nullptr
                ↑              ↑
               head           tail
```

---

## Delete at Tail Function

```cpp
void deleteattail(){
```
- Removes last node
- **Time Complexity:** O(n) - must traverse to second-last node

```cpp
if(size == 0){
    cout << "List is empty" << endl;
    return;
```
- Guard clause for empty list

```cpp
if(size == 1){
```
- Special case: only one node

```cpp
delete head;
```
- Delete the only node

```cpp
head = tail = nullptr;
```
- Both pointers should be nullptr
- List is now empty

```cpp
size = 0;
return;
```
- Size is 0, exit

```cpp
node* temp = head;
```
- Start traversal

```cpp
while(temp->next != tail){
```
- Find second-last node
- Loop until temp's next IS the tail

```cpp
temp = temp->next;
```
- Move forward

**Visual:**
```
[10] → [20] → [30] → nullptr
                ↑      ↑
              temp    tail

We stop when temp->next == tail
```

```cpp
delete tail;
```
- Free memory of last node

```cpp
tail = temp;
```
- Update tail to point to second-last node
- This node is now the new last node

```cpp
tail->next = nullptr;
```
- Last node should point to nullptr
- **Important:** Break the link to deleted memory

```cpp
size--;
```
- Decrement size

---

## Delete at Position Function

```cpp
void deleteatpos(int pos){
```
- Delete node at specific position

```cpp
if(pos < 0 || pos >= size){
```
- Validate position
- `pos >= size`: can't delete beyond list

```cpp
if(pos == 0){
    deleteathead();
    return;
```
- Special case: delete first node

```cpp
if(pos == size - 1){
    deleteattail();
    return;
```
- Special case: delete last node
- `size - 1` is index of last element

```cpp
node* temp = head;
```
- Start traversal

```cpp
for(int i = 0; i < pos - 1; i++){
    temp = temp->next;
```
- Reach node BEFORE deletion point
- Need (pos-1) to change its next pointer

```cpp
node* todelete = temp->next;
```
- Store pointer to node we want to delete
- This is the node at position `pos`

```cpp
temp->next = temp->next->next;
```
- Skip over the node to delete
- Link (pos-1) directly to (pos+1)

```cpp
delete todelete;
```
- Free memory

**Visual (delete pos=1):**
```
Before: [10] → [20] → [30] → nullptr
         0      1      2

Step 1: temp at pos 0
        [10] → [20] → [30] → nullptr
         ↑      ↑
        temp  todelete

Step 2: temp->next = temp->next->next
        [10] ----→ [30] → nullptr
                   
        [20] (isolated)
         ↑
      todelete

Step 3: delete todelete
        [10] → [30] → nullptr
```

```cpp
size--;
```
- Decrement size

---

## Display Function

```cpp
void display(){
```
- Prints entire list

```cpp
node* temp = head;
```
- Start from beginning

```cpp
while(temp != nullptr){
```
- Loop until end of list
- `temp == nullptr` means we've passed the last node

```cpp
cout << temp->value << " -> ";
```
- Print current node's value
- Print arrow for visualization

```cpp
temp = temp->next;
```
- Move to next node

```cpp
cout << "nullptr" << endl;
```
- Print end of list marker
- Shows list terminates

**Output Example:**
```
30 -> 20 -> 10 -> nullptr
```

---

## Main Function

```cpp
int main(){
```
- Entry point of program

```cpp
linkedlist l1;
```
- Creates a LinkedList object named `l1`
- Calls constructor: head=nullptr, tail=nullptr, size=0

```cpp
l1.insertathead(10);
```
- Insert 10 at beginning
- List: [10] → nullptr

```cpp
l1.insertathead(20);
```
- Insert 20 at beginning
- List: [20] → [10] → nullptr

```cpp
l1.insertathead(30);
```
- Insert 30 at beginning
- List: [30] → [20] → [10] → nullptr

```cpp
l1.display();
```
- Print the list
- Output: `30 -> 20 -> 10 -> nullptr`

---

## Memory Management Notes

**Why `new` and `delete`?**
- `new`: Allocates memory on heap (persists until deleted)
- `delete`: Frees memory to prevent leaks

**Memory Leak Example (BAD):**
```cpp
node* temp = new node(10);
temp = head; // Lost pointer to new node! Memory leak!
```

**Correct Way (GOOD):**
```cpp
node* temp = head; // Just assign, no 'new'
```

---

## Time Complexity Summary

| Operation | Time Complexity | Reason |
|-----------|----------------|--------|
| Insert at Head | O(1) | Direct head access |
| Insert at Tail | O(1) | Have tail pointer |
| Insert at Position | O(n) | Must traverse to position |
| Delete at Head | O(1) | Direct head access |
| Delete at Tail | O(n) | Must find second-last node |
| Delete at Position | O(n) | Must traverse to position |
| Display | O(n) | Must visit all nodes |
| Size | O(1) | Stored as variable |

---

## Key Takeaways

1. **Always initialize pointers** to nullptr
2. **Handle empty list** as special case
3. **Update both head and tail** when needed
4. **Use temp pointers** for traversal (preserve head/tail)
5. **Delete nodes** to prevent memory leaks
6. **Maintain size counter** for O(1) size lookup
7. **Check bounds** before accessing positions