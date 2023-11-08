#include <stdio.h>
#include <stdlib.h>

// Structure to represent an element with its value, list index, and element index
struct Element {
    int value;
    int listIndex;
    int elementIndex;
};

// Function to swap two elements
void swap(struct Element* arr, int i, int j) {
    struct Element temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Min-heapify function to maintain the heap property
void minHeapify(struct Element* arr, int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left].value < arr[smallest].value)
        smallest = left;

    if (right < size && arr[right].value < arr[smallest].value)
        smallest = right;

    if (smallest != i) {
        swap(arr, i, smallest);
        minHeapify(arr, size, smallest);
    }
}

// Function to print elements in sorted order
void printSorted(int lists[][4], int m, int n) {
    struct Element* heap = (struct Element*)malloc(m * sizeof(struct Element));
    for (int i = 0; i < m; i++) {
        heap[i].value = lists[i][0];
        heap[i].listIndex = i;
        heap[i].elementIndex = 0;
    }

    int heapSize = m;

    // Build a min-heap
    for (int i = (m / 2 - 1); i >= 0; i--)
        minHeapify(heap, heapSize, i);

    while (heapSize != 0) {
        // Get the minimum element from the heap
        struct Element min = heap[0];

        // Print the minimum element
        printf("%d ", min.value);

        // Replace the minimum element with the next element from the same list
        int listIndex = min.listIndex;
        int elementIndex = min.elementIndex + 1;
        if (elementIndex < n) {
            heap[0] = (struct Element){lists[listIndex][elementIndex], listIndex, elementIndex};
        } else {
            // If the list is exhausted, replace it with the last element in the heap
            heap[0] = heap[heapSize - 1];
            heapSize--;
        }

        // Heapify to maintain the heap property
        minHeapify(heap, heapSize, 0);
    }

    free(heap);
}

int main() {
    int m = 5; // Number of lists
    int n = 4; // Size of each list
    int lists[5][4] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50},
        {16, 18, 22, 28}
    };

    printf("Sorted Output: ");
    printSorted(lists, m, n);

    return 0;
}