#include "my_Function.h"

void HoanVi(int& a, int& b)
{
	int x = a;
	a = b;
	b = x;
}

///-------------------------------------------------

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % n;
		int r2 = rand() % n;
		HoanVi(a[r1], a[r2]);
	}
}

void GenerateData(int a[], int n, int dataType)
{
	switch (dataType)
	{
	case 0:	// ngẫu nhiên
		GenerateRandomData(a, n);
		break;
	case 1:	// có thứ tự
		GenerateSortedData(a, n);
		break;
	case 2:	// có thứ tự ngược
		GenerateReverseData(a, n);
		break;
	case 3:	// gần như có thứ tự
		GenerateNearlySortedData(a, n);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}

///--------------------------------------------------

//------------------ Selection Sort ----------------
void selectionSort(int a[], int n) {
	for (int i = 0; i < n; i++) {
		int min_idx = i;

		for (int j = i + 1; j < n; j++){
			if (a[j] < a[min_idx]){
				min_idx = j;
			}
		}

		if (min_idx != i)
			HoanVi(a[min_idx], a[i]);
	}
}

//------------------ Insertion Sort ----------------

void insertionSort(int a[], int n) {
	for (int i = 0; i < n; i++) {
		int key = a[i];
		int j = i - 1;
		
		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			j--;
		}

		HoanVi(a[j + 1], key);
	}
}

//------------------ Bubble Sort -------------------

void bubbleSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++){
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j+1]) {
				HoanVi(a[j], a[i]);
			}
		}
	}
}

//------------------ Shell Sort -------------------

void shellSort(int a[], int n) {
	for (int dis = n / 2; dis > 0; dis /= 2) {

		for (int i = dis; i < n; i++) {
			int t = a[i];
			int j;

			for (j = i; j >= dis && a[j - dis] > t; j -= dis) {
				a[j] = a[j - dis];

			}

			a[j] = t;
		}
	}
}

//------------------ Heap Sort ---------------------

void heapify(int a[], int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && a[largest] < a[left]) {
		largest = left;
	}

	if (right < n && a[largest] < a[right]) {
		largest = right;
	}

	if (largest != i) {
		HoanVi(a[largest], a[i]);
		heapify(a, n, largest);
	}
}

void heapSort(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(a, n, i);
	}

	for (int i = n - 1; i > 0; i--) {
		HoanVi(a[0],a[i]);
		heapify(a, i, 0);
	}
}

//------------------ Merge Sort --------------------

void merge(int a[], int l, int mid, int r)
{
	const int size_left = mid - l + 1;
	const int size_right = r - mid;

	int* L = new int[size_left];
	int* R = new int[size_right];

	for (int i = 0; i < size_left; i++) {
		L[i] = a[l + i];
	}

	for (int j = 0; j < size_right; j++) {
		R[j] = a[mid + 1 + j];
	}

	int i = 0, j = 0, k = l;

	while (i < size_left && j < size_right) {
		
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		}
		else {
			a[k] = R[j];
			j++;
		}

		k++;
	}

	if (i < size_left) {
		a[k] = L[i];
		i++;
		k++;
	}

	if (j < size_right) {
		a[k] = R[j];
		j++;
		k++;
	}

	delete[]L;
	delete[]R;
}

void mergeSort(int a[], int l, int r) {
	if (l >= r)
		return;
	
	int mid = (r + l) / 2;

	mergeSort(a, l, mid);
	mergeSort(a, mid + 1, r);
	merge(a, l, mid, r);
}

//------------------ Quick Sort --------------------

void quickSort(int a[], int l, int r) {
	if (l >= r)
		return;

	int pivot = (r + l) / 2;
	int i = l, j = r;

	while (i < j) {
		while (a[i] < a[pivot]) {
			i++;
		}

		while (a[j] > a[pivot]) {
			j--;
		}

		if (i <= j) {
			HoanVi(a[i], a[j]);
			i++;
			j--;
		}
	}

	if (l < j) {
		quickSort(a, l, j);
	}

	if (i < r) {
		quickSort(a, i, r);
	}
}

//------------------ Radix Sort --------------------

int get_max(int a[], int n) {
	int max = a[0];

	for (int i = 1; i < n; i++) {
		if (max < a[i]) {
			max = a[i];
		}
	}

	return max;
}

void radixSort(int a[], int n)
{
	const int radix = 10;

	int max = get_max(a,n);

	vector<int> q[radix];

	int i, j, k, factor;

	for (factor = 1; max / factor > 0; factor *= radix)
	{


		for (i = 0; i < n; i++)
		{
			q[(a[i] / factor) % radix].push_back(a[i]);
		}

		k = 0;

		for (i = 0; i < radix; i++)
		{
			for (j = 0; j < q[i].size(); j++)
			{
				a[k++] = q[i][j];
			}
		}
	}
}

// ----------------- In Mang ------------------

int init_and_run_Algorithm(int choice1, int a[], int n) {
	if (choice1 == 1) {
		selectionSort(a, n);
	}

	if (choice1 == 2) {
		insertionSort(a, n);
	}


	if (choice1 == 3) {
		bubbleSort(a, n);
	}


	if (choice1 == 4) {
		shellSort(a, n);
	}
		

	if (choice1 == 5) {
		heapSort(a, n);
	}
		

	if (choice1 == 6) {
		mergeSort(a, 0, n - 1);
	}

	if (choice1 == 7) {
		quickSort(a, 0, n - 1);
	}

	if (choice1 == 8) {
		radixSort(a, n);
	}

	return 0;
}


