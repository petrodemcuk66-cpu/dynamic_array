#include <iostream>
using namespace std;

void ShowArray(int* arr, int size) {
	for (int i = 0; i < size; i++)
		cout << arr[i] << ": ";
	cout << endl;
}

void FilleShow(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << "enter element: " << i << ": ";
		cin >> arr[i];
	}
}

int* pop_back(int*& arr, int& size) {
	if (size == 0) return arr;
	int* newArr = new int[size - 1];
	for (int i = 0; i < size - 1; i++)
		newArr[i] = arr[i];
	delete[] arr;
	size--;
	return newArr;
}

int* push_back(int*& arr, int& size, int value) {
	int* newArr = new int[size + 1];
	for (int i = 0; i < size; i++)
		newArr[i] = arr[i];
	newArr[size] = value;
	delete[] arr;
	size++;
	return newArr;

}

int main()
{
	int n;
	cout << "enter initial array size: ";
	cin >> n;

	int* arr = new int[n];
	FilleShow(arr, n);

	cout << "initial array: ";
	ShowArray(arr, n);

	int value;
	cout << "enter value to add: ";
	cin >> value;
	arr = push_back(arr, n, value);

	cout << "After push_back: \t";
	ShowArray(arr, n);

	arr = pop_back(arr, n);
	cout << "After pop_back: \t";
	ShowArray(arr, n);

	delete[] arr;
	return 0;
}