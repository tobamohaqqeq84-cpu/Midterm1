//Toba Mohaqqeq
//Comsc 210
//midterms 1

#include <iostream> //for input and output streams
using namespace std; //for standard nmespace,so you dont have to use std::cout
const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20; //constants for the minimum and maximum number of rows and columns.
class DoublyLinkedList { //Declaring that implements a doubly linked list of integers.
private: //This is the private section of the class.

struct Node { // this struct is what each node in the list will look like.
int data;  // the number that the node will hold.
Node* prev;  //Popinter to the previous node in the list.
Node* next;  //Pointer to the next node in the list.

Node(int val, Node* p = nullptr, Node* n = nullptr) {  //this makes a new node with the given value and pointers.
data = val; //sets the data to the given value.
prev = p;   //link the previous node to the given node.
next = n;  //link the next node to the given node.
}
};
Node* head;  // a pointer to the first node in the list.
Node* tail;  // a pointer to the last node in the list (so we can add to the end of the list quickly).
public:
DoublyLinkedList() { head = nullptr; tail = nullptr; }// this is the constructor for the class., empty head/tail
void insert_after(int value, int position) { //this function adds a new node with the given value after the given position.(0 =first)
if (position < 0) { //this is like a guard against the negative numbers.
cout << "Position must be >= 0." << endl; // the reports invalid input to the user.
return; //this is the return statement that ends the function.
}
Node* newNode = new Node(value); //this creates a new node with the given value.
if (!head) { //this checks if the list is empty.(if this list is empty)
head = tail = newNode; // the new nde becomes both head an tail 
return; //this is the return statement that ends the function.(done)
}
Node* temp = head; // start from the head of the list.(first node)
for (int i = 0; i < position && temp; ++i) ///this is a for loop that goes through the list until it reaches the given position.
temp = temp->next; //this moves the pointer to the next node in the list each time. 
if (!temp) { // this checks if the position is greater than the size of the list, if it went too far.
cout << "Position exceeds list size. Node not inserted.\n"; // prints an error message to the user.
delete newNode; //this deletes the new node that was created, so no memory is leaked.
return;
}
newNode->next = temp->next; //this links the new node to the next node in the list.
newNode->prev = temp; //this connects the new node to the previous node in the list.
if (temp->next)  //this checks if thr temp is not the last node in the list.
temp->next->prev = newNode; //fix the previous pointer of the next node.
else
tail = newNode; //if the temp is the last node in the list, the new node becomes the tail.
temp->next = newNode; //this links the previous node to the new node.
}
void delete_val(int value) { // this function deletes the first node with the given value.
if (!head) return; //this checks if the list is empty and skips the rest of the function if it is.
Node* temp = head; //start from the head of the list.
while (temp && temp->data != value) //this is a while loop that goes through the list until it finds the node with the given value.
temp = temp->next; //this moves the pointer to the next node in the list each time.
if (!temp) return; //this chekes if the value was found n the list, if not, it will stop the funcion. 
if (temp->prev) //this checks if there was a node before the one that was found.
temp->prev->next = temp->next; // thsi skips the temp in the forward direction. 
else // if there was no node before the one that was found.
head = temp->next; // move the head to the next node.
if (temp->next) //this checks if there was a node after the one that was found.
temp->next->prev = temp->prev; //this skips the temp in the backward direction.
else 
tail = temp->prev; //if there was no node after the one that was found, move the tail to the previous node.(moves the tail backward)
delete temp; //this deletes the node that was found.
} // end of this function. 

void delete_pos(int pos) { // this deletes the node a the specific position.(so 1 means the first node)
if (!head) {  //This checks if the list is empty.
cout << "List is empty." << endl; // pribts an error massage to the user.
return;
}
if (pos == 1) { // if the position is 1, then the first node is deleted.(if we delete the first node)
pop_front(); //use the pop_front function. (this calls the pop front function)
return;
}
Node* temp = head; //start from the head of the list.
for (int i = 1; i < pos; i++){
if (!temp) {
cout << "Position doesn't exist." << endl;
return;
}
else
temp = temp->next;
}
if (!temp) {
cout << "Position doesn't exist." << endl;
return;
}
if (!temp->next) {
pop_back();
return;
}
Node* tempPrev = temp->prev;
tempPrev->next = temp->next;
temp->next->prev = tempPrev;
delete temp;
}
void push_back(int v) {
Node* newNode = new Node(v);
if (!tail)
head = tail = newNode;
else {
tail->next = newNode;
newNode->prev = tail;
tail = newNode;
}
}
void push_front(int v) {
Node* newNode = new Node(v);
if (!head)
head = tail = newNode;
else {
newNode->next = head;
head->prev = newNode;
head = newNode;
}
}
void pop_front() {
if (!head) {
cout << "List is empty." << endl;
return;
}
Node * temp = head;
if (head->next) {
head = head->next;
head->prev = nullptr;
}
else
head = tail = nullptr;
delete temp;
}
void pop_back() {
if (!tail) {
cout << "List is empty." << endl;
return;
}
Node * temp = tail;
if (tail->prev) {
tail = tail->prev;
tail->next = nullptr;
}
else
head = tail = nullptr;
delete temp;
}
~DoublyLinkedList() {
while (head) {
Node* temp = head;
head = head->next;
delete temp;
}
}
void print() {
Node* current = head;
if (!current) {
cout << "List is empty." << endl;
return;
}
while (current) {
cout << current->data << " ";
current = current->next;
}
cout << endl;
}
void print_reverse() {
Node* current = tail;
if (!current) {
cout << "List is empty." << endl;
return;
}
while (current) {
cout << current->data << " ";
current = current->prev;
}
cout << endl;
}
};
int main() {
cout << MIN_NR + MIN_LS + MAX_NR + MAX_LS; // dummy statement to avoid
compiler warning
return 0;
}
