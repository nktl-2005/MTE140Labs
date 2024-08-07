#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MaxHeap {
private:
    vector<pair<string, int>> heap; //changing each node to now store the patient name and their
                                    //corresponding priority number

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void heapifyUp(int i) {
        while (i != 0 && heap[parent(i)].second < heap[i].second) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < heap.size() && heap[left].second > heap[largest].second)
            largest = left;

        if (right < heap.size() && heap[right].second > heap[largest].second)
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(string patient_name, int priority) {
        heap.push_back(make_pair(patient_name,priority));
        heapifyUp(heap.size() - 1);
    }

    pair<string,int> extractMax() {
        if (heap.size() == 0)
            throw runtime_error("Heap is empty");

        pair<string,int> root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return root;
    }

    void printHeap() { //changing to showcase priority number and name of patient when printing
        for (const pair<string, int>& entry : heap) {
            cout << entry.first << " (" << entry.second << ") ";
        }
        cout << endl;
    }
    //added a bool function to check if the heap is empty and return true or false
    bool isEmpty(){
        return heap.empty();
    }
};
int main() {
    //inserting patients into MaxHeap
    MaxHeap patients;
    patients.insert("Patient A", 5);
    patients.insert("Patient B", 9);
    patients.insert("Patient C", 3);
    patients.insert("Patient D", 5);
    patients.insert("Patient E", 7);

    cout << "Initial heap: ";
    patients.printHeap();

    cout << "Extracting patients based on priority:" << endl;
    //extract until bool returns true
    while (!patients.isEmpty()) {
        pair<string, int> patient = patients.extractMax();
        cout << "Calling patient: " << patient.first << endl;
    }
    return 0;
}