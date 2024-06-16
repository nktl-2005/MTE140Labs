#include <iostream>
using namespace std;

class CircularLinkedList {
public:
    int data;
    CircularLinkedList* next;
    void insertion(CircularLinkedList *& head, int value);
    void deletion(CircularLinkedList* head, int delete_number);
    void display(CircularLinkedList* head);
    int search(CircularLinkedList* head, int pick);
};

void insertion(CircularLinkedList *& head, int value){
    CircularLinkedList* newNode = new CircularLinkedList();
    newNode->data = value;

    // if list is empty
    if (head == nullptr) {
    head = newNode;
    newNode->next = head;
    } else {
    CircularLinkedList* temp = head;

    //Go through to the last node
    while (temp->next != head){
    temp = temp->next;
    }
    //Point the last node to the new node, and the new node to the head
    temp->next = newNode;
    newNode->next = head;
    }
}

void deletion(CircularLinkedList* head, int delete_number){
        // in the case that the list is empty
        if (head==nullptr || !head) {
            cout << "List is empty and therefore the number is not in the list" << endl;
            return;
        }
        // initizaiting these pointers to changge once the delete number is found
        CircularLinkedList* curr = head;
        CircularLinkedList* prev = nullptr;
        CircularLinkedList* lastOccur = nullptr;
        CircularLinkedList* lastOccurPrev = nullptr;

       // setting values to last node to work backwards
       do {
            if (curr->data == delete_number){
                lastOccur = curr;
                lastOccurPrev = prev;
            }
            //setting up to reassign pointers
            prev = curr;
            curr = curr->next;
       } while (curr !=head);

        // number not found
        if (!lastOccur) {
            cout << "Number provided is not in the list" << endl;
        }

        // if the number is the head node
        if (lastOccur == head) {
            if (head->next == head) {
                delete head;
                head = nullptr;
            }
            else { //there is more than 1 node in the list
                CircularLinkedList* temp = head;
                while (temp->next !=head) {
                    temp = temp->next;
                }
                // resigning the pointers and deleting the entry correctly
                temp->next = head->next;
                CircularLinkedList* toDelete = head;
                head = head->next;
                delete toDelete;
            } 
        }
        else {
            // if the number is not the head node
            lastOccurPrev->next = lastOccur->next;
            delete lastOccur;
        }
    }

void display(CircularLinkedList* head){
        //if the list is empty
        if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
        }
        CircularLinkedList* temp = head;
        //
        do {
        cout<< temp->data <<" ";
        temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

int search(CircularLinkedList* head, int pick) {
    
    // Initialize varibles
    CircularLinkedList* here = head;
    int count = 0;

    // While the target isn't found and we haven't searched a full length of the list
    while(here->data != pick && here->next != head) {
       
       // Go to the next node and increment the index counter
        here = here->next;
        count = count + 1;

    }

    // If the while loop terminated because the target was found, then return the couted index
    if(here->data == pick) {
            return count;
        } else { // If we reached the end of the list, return -1
            return -1;
        }
}

int main() {
    // Make a circular linked list where each node is named a number from 0-3, 
    // and the data it holds is an int of that number
    CircularLinkedList* zero = new CircularLinkedList();
    zero->data = 0;
    CircularLinkedList* one = new CircularLinkedList();
    zero->next = one;
    one->data = 1;
    CircularLinkedList* two = new CircularLinkedList();
    one->next = two;
    two->data = 2;
    CircularLinkedList* three = new CircularLinkedList();
    two->next = three;
    three->data = 3;
    three->next = zero;

    // Execute functions
    int search_target = 3;
    int target_index = search(zero, search_target);
    cout << "The index of the node containing " << search_target << " is: " <<target_index;
    cout << endl;

    insertion(zero, 4);

    deletion(zero, 1);

    display(zero);

    return 0;
}
