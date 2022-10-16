#include<iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include<queue>
#include<vector>
#include <chrono>

using namespace std;

void HoanVi(int& a, int& b);

void GenerateRandomData(int a[], int n);

void GenerateSortedData(int a[], int n);

void GenerateReverseData(int a[], int n);

void GenerateNearlySortedData(int a[], int n);

void GenerateData(int a[], int n, int dataType);

void selectionSort(int a[], int n);

void insertionSort(int a[], int n);

void bubbleSort(int a[], int n);

void shellSort(int a[], int n);

void heapSort(int a[], int n);

void merge(int a[], int l, int mid, int r);

void mergeSort(int a[], int l, int r);

void quickSort(int a[], int l, int r);

int get_max(int a[], int n);

void radixSort(int a[], int n);

int init_and_run_Algorithm(int choice1, int a[], int n);

