//
#include <iostream>
using namespace std;
class CircularLinkedList {
public:
    struct Node {
        int data;
        Node* next;

        Node(int value) : data(value), next(nullptr) {}
    };

    Node* head;
    void insertion(){}
    
    void deletion(CircularLinkedList* head, int delete_number){
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
            if (curr->data = delete_number){
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

    void display(CircularLinkedList* head){
        if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
        }
        CircularLinkedList* temp = head;
        do {
        cout<< temp->value <<" ";
        temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void search(){

    }
};
typedef CircularLinkedList* Node;
int main() {
    Node *head = new Node();
    Node *second = new Node();



    return 0;
}