#include <iostream>
#include <vector>
#include <memory> // for smart pointers

using namespace std;

// ============================================================
// Strategy Interface - An interface or abstract class that declares the method(s) every algorithm (strategy) must implement.
// ============================================================
class SortingStrategy {
public:
    virtual void sort(vector<int>& arr) = 0; // Pure virtual function
    virtual ~SortingStrategy() {}
};

// ============================================================
// Concrete Strategy: Bubble Sort
// ============================================================
class BubbleSortStrategy : public SortingStrategy {
public:
    void sort(vector<int>& arr) override {
        cout << "Sorting using Bubble Sort" << endl;
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
};

// ============================================================
// Concrete Strategy: Merge Sort
// ============================================================
class MergeSortStrategy : public SortingStrategy {
public:
    void sort(vector<int>& arr) override {
        cout << "Sorting using Merge Sort" << endl;
        mergeSort(arr, 0, arr.size() - 1);
    }

private:
    void mergeSort(vector<int>& arr, int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }

    void merge(vector<int>& arr, int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;

        vector<int> L(n1), R(n2);
        for (int i = 0; i < n1; ++i) L[i] = arr[l + i];
        for (int j = 0; j < n2; ++j) R[j] = arr[m + 1 + j];

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2)
            arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];
    }
};

// ============================================================
// Concrete Strategy: Quick Sort
// ============================================================
class QuickSortStrategy : public SortingStrategy {
public:
    void sort(vector<int>& arr) override {
        cout << "Sorting using Quick Sort" << endl;
        quickSort(arr, 0, arr.size() - 1);
    }

private:
    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            if (arr[j] < pivot) {
                swap(arr[++i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }
};

// ============================================================
// Context - This class uses a reference to a strategy object and delegates the work to it. It doesn't know which exact algorithm is used — it just calls the strategy method.
// ============================================================
class SortingContext {
private:
    unique_ptr<SortingStrategy> strategy;

public:
    SortingContext(unique_ptr<SortingStrategy> strategy)
        : strategy(move(strategy)) {}

    void setStrategy(unique_ptr<SortingStrategy> newStrategy) {
        strategy = move(newStrategy);
    }

    void performSort(vector<int>& arr) {
        strategy->sort(arr);
        printArray(arr);
    }

    void printArray(const vector<int>& arr) {
        cout << "Sorted Array: ";
        for (int num : arr) {
            cout << num << " ";
        }
        cout << "\n\n";
    }
};

// ============================================================
// Client - This is where you decide which strategy to use.
// ============================================================
int main() {

    vector<int> arr;
    
    vector<int> arr1 = {5, 2, 9, 1, 5};
    vector<int> arr2 = {8, 3, 7, 4, 2};
    vector<int> arr3 = {6, 1, 3, 9, 5};

    SortingContext context(make_unique<BubbleSortStrategy>());
    context.performSort(arr1);

    context.setStrategy(make_unique<MergeSortStrategy>());
    context.performSort(arr2);

    context.setStrategy(make_unique<QuickSortStrategy>());
    context.performSort(arr3);

    return 0;
}

/*


 👉 What is Strategy Design Pattern? 
 It is a behavioral design pattern that lets you define a family of algorithms, put each algorithm in its own class, and make them interchangeable during runtime.
 
 👉 Think of it like this
- Sometimes with **Bubble Sort**
- Sometimes with **Quick Sort**
- Or maybe with **Merge Sort**

Instead of writing all sorting logic in one place and using if-else or switch, Strategy Pattern lets you separate each sorting algorithm into its own class.
*/