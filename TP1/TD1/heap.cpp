#include <iostream>
#include <vector>

using namespace std;

struct Heap {
    vector<int> data;  
};

void HeapInit(Heap& heap) {
    heap.data.push_back(0);  
}

void maxHeapifyUp(Heap& heap, int idx) {
    while (idx > 1 && heap.data[idx] > heap.data[idx / 2]) {
        swap(heap.data[idx], heap.data[idx / 2]);
        idx /= 2;
    }
}

void insertMax(Heap& heap, int val) {
    heap.data.push_back(val);
    maxHeapifyUp(heap, heap.data.size() - 1);
}

void maxHeapifyDown(Heap& heap, int idx, int size) {
    int largest = idx;
    int left = 2 * idx;
    int right = 2 * idx + 1;

    if (left <= size && heap.data[left] > heap.data[largest]) {
        largest = left;
    }
    if (right <= size && heap.data[right] > heap.data[largest]) {
        largest = right;
    }

    if (largest != idx) {
        swap(heap.data[idx], heap.data[largest]);
        maxHeapifyDown(heap, largest, size);
    }
}

int extractMax(Heap& heap) {
    if (heap.data.size() <= 1) {
        cout << "Heap is empty" << endl;
        return 0; 
    }

    int maxVal = heap.data[1];
    int lastIdx = heap.data.size() - 1;
    heap.data[1] = heap.data[lastIdx];
    heap.data.pop_back();

    maxHeapifyDown(heap, 1, heap.data.size() - 1);

    return maxVal;
}

void minHeapifyUp(Heap& heap, int idx) {
    while (idx > 1 && heap.data[idx] < heap.data[idx / 2]) {
        swap(heap.data[idx], heap.data[idx / 2]);
        idx /= 2;
    }
}

void insertMin(Heap& heap, int val) {
    heap.data.push_back(val);
    minHeapifyUp(heap, heap.data.size() - 1);
}

void minHeapifyDown(Heap& heap, int idx, int size) {
    int smallest = idx;
    int left = 2 * idx;
    int right = 2 * idx + 1;

    if (left <= size && heap.data[left] < heap.data[smallest]) {
        smallest = left;
    }
    if (right <= size && heap.data[right] < heap.data[smallest]) {
        smallest = right;
    }

    if (smallest != idx) {
        swap(heap.data[idx], heap.data[smallest]);
        minHeapifyDown(heap, smallest, size);
    }
}

int extractMin(Heap& heap) {
    if (heap.data.size() <= 1) {
        cout << "Heap is empty" << endl;
        return 0; 
    }

    int minVal = heap.data[1];
    int lastIdx = heap.data.size() - 1;
    heap.data[1] = heap.data[lastIdx];
    heap.data.pop_back();

    minHeapifyDown(heap, 1, heap.data.size() - 1);

    return minVal;
}

void printHeap(const Heap& heap) {
    cout << "Heap array (1-based): ";
    for (size_t i = 1; i < heap.data.size(); ++i) {
        cout << heap.data[i] << " ";
    }
    cout << endl;
}

int main() {
    int sequence[] = {27, 12, 8, 45, 17, 63, 100, 5, 75, 90, 26, 32, 188, 95};
    int seqSize = sizeof(sequence) / sizeof(sequence[0]);

    cout << "=== Max-Heap Demonstration ===" << endl;
    Heap maxHeap;
    HeapInit(maxHeap);

    for (int i = 0; i < seqSize; ++i) {
        insertMax(maxHeap, sequence[i]);
        cout << "After inserting " << sequence[i] << " into max-heap: ";
        printHeap(maxHeap);
    }

    cout << "\nExtracting from max-heap:" << endl;
    while (maxHeap.data.size() > 1) {
        int val = extractMax(maxHeap);
        cout << "Extracted max " << val << ": ";
        printHeap(maxHeap);
    }
    extractMax(maxHeap);  

    cout << "\n=== Min-Heap Demonstration ===" << endl;
    Heap minHeap;
    HeapInit(minHeap);

    for (int i = 0; i < seqSize; ++i) {
        insertMin(minHeap, sequence[i]);
        cout << "After inserting " << sequence[i] << " into min-heap: ";
        printHeap(minHeap);
    }

    cout << "\nExtracting from min-heap:" << endl;
    while (minHeap.data.size() > 1) {
        int val = extractMin(minHeap);
        cout << "Extracted min " << val << ": ";
        printHeap(minHeap);
    }
    extractMin(minHeap);  

    return 0;
}