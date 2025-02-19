#include <iostream>
using namespace std;

class MaxHeap {
    int* heap;
    int size;
    int capacity;

public:
    MaxHeap(int cap) {
        capacity = cap;
        size = 0;
        heap = new int[capacity];
    }

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return (2 * i + 1); }
    int rightChild(int i) { return (2 * i + 2); }

    void insert(int key) {
        if (size == capacity) {
            cout << "Heap Overflow\n";
            return;
        }
        int i = size++;
        heap[i] = key;

        while (i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapify(int i) {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < size && heap[left] > heap[largest])
            largest = left;
        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

    void deleteRoot() {
        if (size == 0) return;

        heap[0] = heap[size - 1];
        size--;
        heapify(0);
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap h(10);
    h.insert(50);
    h.insert(30);
    h.insert(20);
    h.insert(15);
    h.insert(10);
    h.insert(8);
    h.insert(16);

    cout << "Max Heap: ";
    h.display();

    h.deleteRoot();
    cout << "After Deleting Root: ";
    h.display();

    return 0;
}
