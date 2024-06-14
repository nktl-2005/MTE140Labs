#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void insertion(Node *& head, int value){
    Node* newNode = new Node();
    newNode->data = value;

    // if list is empty
    if (head == nullptr) {
    head = newNode;
    newNode->next = head;
    } else {
    Node* temp = head;

    //Go through to the last node
    while (temp->next != head){
    temp = temp->next;
    }
    //Point the last node to the new node, and the new node to the head
    temp->next = newNode;
    newNode->next = head;
    }
}

void deletion(Node* head, int delete_number){
        // in the case that the list is empty
        if (head==nullptr || !head) {
            cout << "List is empty and therefore the number is not in the list" << endl;
            return;
        }
        // initizaiting these pointers to changge once the delete number is found
        Node* curr = head;
        Node* prev = nullptr;
        Node* lastOccur = nullptr;
        Node* lastOccurPrev = nullptr;

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
                Node* temp = head;
                while (temp->next !=head) {
                    temp = temp->next;
                }
                // resigning the pointers and deleting the entry correctly
                temp->next = head->next;
                Node* toDelete = head;
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

void display(Node* head){
        //if the list is empty
        if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
        }
        Node* temp = head;
        //
        do {
        cout<< temp->data <<" ";
        temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

int search(Node* head, int target) {
    Node* here = head;
    int count = 0;

    while(here->data != target && here->next != head) {
       
        here = here->next;
        count = count + 1;

        if(count >= 100) { // If the target isn't found in 100 tries, stop trying
            break;
        }

    }

    if(here->data == target) {
            return count;
        } else {
            return -1;
        }
}

int main() {
    // Make a circular linked list where each node is named a number from 0-3, 
    // and the data it holds is an int of that number
    Node* zero = new Node();
    zero->data = 0;
    Node* one = new Node();
    zero->next = one;
    one->data = 1;
    Node* two = new Node();
    one->next = two;
    two->data = 2;
    Node* three = new Node();
    two->next = three;
    three->data = 3;
    three->next = zero;

    // Execute functions
    int search_target = 3;
    int target_index = search(zero, search_target);
    cout << "the index of the node containing " << search_target << " is " <<target_index;
    cout << endl;

    insertion(zero, 4);

    deletion(zero, 1);

    display(zero);

    return 0;
}