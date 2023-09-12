#include <iostream>
using namespace std;
  
void heap(int arr[], int arr_size, int root) {
	int largest = root;
	int l = 2*root + 1;
	int r = 2*root + 2;	  
	if (l < arr_size && arr[l] > arr[largest]) { largest = l; }
	if (r < arr_size && arr[r] > arr[largest]) { largest = r; }
	if (largest != root) {
		swap(arr[root], arr[largest]);
		heap(arr, arr_size, largest);
	}
}
  
void heapSort(int arr[], int arr_size) {
	for(int i = arr_size / 2 - 1; i >= 0; i--) {
		heap(arr, arr_size, i);
    }

	for(int i = arr_size - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		heap(arr, i, 0);
	}
}
  
int main() {	
    int array[] = {7,24,15,3,9};
    int arr_size = 5;

    cout << "Array:" << endl;
	for(int i = 0; i < arr_size; i++)
		cout << array[i] << ' ';
	cout << endl;
	
	heapSort(array, arr_size);
	
	cout << "Sorted array:" << endl;
	for(int i = 0; i < arr_size; i++)
		cout << array[i] << ' ';
	cout << endl;
}