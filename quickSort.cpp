#include<iostream>
using namespace std;
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1); 
 for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}
void quicksort(int arr[], int low, int high) {
    if (low < high) {
    int pivot_index = partition(arr, low, high);
        quicksort(arr, low, pivot_index - 1);
        quicksort(arr, pivot_index + 1, high);
    }
}
int main() {
 int n;
std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;
  int arr[n];
std::cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
quicksort(arr, 0, n - 1);
std::cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
   return 0;
}
