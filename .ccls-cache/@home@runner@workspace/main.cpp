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
prev = p;
next = n;
}
};
Node* head;
Node* tail;
public:
DoublyLinkedList() { head = nullptr; tail = nullptr; }
void insert_after(int value, int position) {
if (position < 0) {
cout << "Position must be >= 0." << endl;
return;
}
Node* newNode = new Node(value);
if (!head) {
head = tail = newNode;
return;
}
Node* temp = head;
for (int i = 0; i < position && temp; ++i)
temp = temp->next;
if (!temp) {
cout << "Position exceeds list size. Node not inserted.\n";
delete newNode;
return;
}
newNode->next = temp->next;
newNode->prev = temp;
if (temp->next)
temp->next->prev = newNode;
else
tail = newNode;
temp->next = newNode;
}
void delete_val(int value) {
if (!head) return;
Node* temp = head;
while (temp && temp->data != value)
temp = temp->next;
if (!temp) return;
if (temp->prev)
temp->prev->next = temp->next;
else
head = temp->next;
if (temp->next)
temp->next->prev = temp->prev;
else
tail = temp->prev;
delete temp;
}
void delete_pos(int pos) {
if (!head) {
cout << "List is empty." << endl;
return;
}
if (pos == 1) {
pop_front();
return;
}
Node* temp = head;
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
