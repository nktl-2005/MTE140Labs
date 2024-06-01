//
#include <iostream>
using namespace std;
class CircularLinkedList {
public:
    int value;
    CircularLinkedList *next;

    void insertion(){

    }

    void deletion(){

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