// Chuong 3 Bai 1
#include <stdio.h>
#include <iostream>
#include <ctime>
using namespace std;

#define MAX 5000
// Cau 1.1
int a[MAX];
int n;
// Cau 1.2
void init (int a[], int &n)
{
	cout << "Nhap so luong phan tu cua danh sach: ";
	cin >> n;
	for (int i = 0; i < n; i++)
		a[i] = rand() % 10000 + 1;
	cout << "Danh sach da duoc nhap ngau nhien nhu sau: " << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
	cout << endl;
}
void input (int a[], int &n)
{
	cout << "Nhap so luong phan tu cua danh sach: ";
	cin >> n;
	cout << "Nhap vao cac phan tu cua danh sach: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]=";
		cin >> a[i];
	}
}
// Cau 1.3
void output (int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
	cout << endl;
}
void coppyArray (int a[], int b[], int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}
// Cau 1.4
void insertionSort (int a[], int n)
{
	int i, key, j;
	for (i = 0; i < n; i++)
	{
		key = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}
void swap (int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
// Cau 1.5
void selectionSort (int a[], int n)
{
	int i, j, min_idx;
	for(i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i; j < n; j++)
			if (a[j] < a[min_idx])
				min_idx = j;	
		swap(a[min_idx], a[j]);
	}
}
// Cau 1.6
void interchangeSort (int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a [i] > a[j])
				swap (a[i], a[j]);
}
// Cau 1.7
void bubbleSort (int arr[], int n)
{
	int i, j;
	bool haveswap = false;
	for (i = 0; i < n - 1; i++)
	{
		haveswap = false;
		for (j = 0; j < n - 1; j++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap (arr[i], arr[i + 1]);
				haveswap = true;
			}
		}
		if (haveswap = false)
			break;
	}
}
// Cau 1.8
int partition (int a[], int low, int high)
{
	int pivot = a[high];
	int left = low;
	int right = high - 1;
	while (true)
	{
		while (left <= right && a[left] < pivot)
			left++;
		while (right >= left && a[right] > pivot)
			right--;
		if (left >= right)
			break;
		swap (a[left], a[right]);
		left++;
		right--;
	}
	swap (a[left], a[right]);
	return left;
}
void quickSort (int a[], int low, int high)
{
	if (low < high)
	{
		int pi = partition (a, low, high);
		quickSort (a, low, pi - 1);
		quickSort (a, pi + 1, high);
	}
}
// Cau 1.9
void heapify (int a[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && a[l] > a[largest])
		largest = l;
	if (r < n && a[r] > a[largest])
		largest = r;
	if (largest != i)
	{
		swap (a [i], a[largest]);
		heapify (a, n, largest);
	}
}
void heapSort (int a[], int n)
{
	for (int i = (n / 2) - 1; i >= 0; i--)
		heapify (a, n, i);
	for (int i =  n - 1; i >= 0; i--)
	{
		swap (a[0], a[i]);
		heapify (a, i, 0);
	}
}
// Cau 1.10
void searchSequence (int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
		i++;
	if (i == n)
		cout << "Khong tim thay: " << endl;
	else
		cout << "Tim thay vi tri " << i;
}
// Cau 1.11
int searchBinary (int a[],int l, int r, int x)
{
	if (r >= 1)
	{
		int mid = 1 + (r - 1) / 2;
		if (a[mid] == x)
			return mid;
		if (a[mid] > x)
			return searchBinary (a, l, mid - 1, x);
		return searchBinary (a, mid + 1, r, x);
	}
	return - 1;
}
int main()
{
	int b[MAX];
	clock_t start;
	double duration;
	int choice, x, i;
	system ("cls");
	cout << "---------- BAI TAP 1, CHUONG 3, XEP THU TU VA TIM KIEM ----------" << endl;
	cout << "0.Khoi tao danh sach ngau nhien. " << endl;
	cout << "1.Nhap danh sach. " << endl;
	cout << "2.Xuat danh sach. " << endl;
	cout << "3.Xep thu tu danh sach bang SELECTION SORT. " << endl;
	cout << "4.Xep thu tu danh sach bang INSERTION SORT. " << endl;
	cout << "5.Xep thu tu danh sach bang BUBBLE SORT. " << endl;
	cout << "6.Xep thu tu danh sach bang INTERCHANGE SORT. " << endl;
	cout << "7.Xep thu tu danh sach bang QUICK SORT. " << endl;
	cout << "8.Xep thu tu danh sach bang HEAP SORT. " << endl;
	cout << "9.Tim kiem phan tu x bang TIM KIEM TUAN TU. " << endl;
	cout << "10.Tim kiem phan tu x bang TIM KIEM NHI PHAN. " << endl;
	cout << "11.Thoat" << endl;
	do{
		cout << "\nVui long con so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
			case 0:
				init (a, n);
				break;
			case 1:
				input (a, n);
				break;
			case 2:
				cout << "Danh sach la: " << endl;
				output (a, n);
				break;
			case 3:
				coppyArray (a, b ,n);
				start = clock();
				selectionSort(b, n);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "Danh sach khi xep thu tu SELECTION SORT la: " << endl;
					output (b, n);
				}
				if (duration > 0)
					cout << "Thoi gian SELECTION SORT : " << duration * 1000000 << " Microsenconds." << endl;
				break;
			case 4:
				coppyArray (a, b ,n);
				start = clock();
				insertionSort(b, n);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "Danh sach khi xep thu tu INSERTION SORT la: " << endl;
					output (b, n);
				}
				if (duration > 0)
					cout << "Thoi gian INSERTION SORT : " << duration * 1000000 << " Microsenconds." << endl;
				break;
			case 5:
				coppyArray (a, b ,n);
				start = clock();
				bubbleSort(b, n);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "Danh sach khi xep thu tu BUBBLE SORT la: " << endl;
					output (b, n);
				}
				if (duration > 0)
					cout << "Thoi gian BUBBLE SORT : " << duration * 1000000 << " Microsenconds." << endl;
				break;
			case 6:
				coppyArray (a, b ,n);
				start = clock();
				interchangeSort(b, n);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "Danh sach khi xep thu tu INTERCHAGE SORT la: " << endl;
					output (b, n);
				}
				if (duration > 0)
					cout << "Thoi gian INTERCHAGE SORT : " << duration * 1000000 << " Microsenconds." << endl;
				break;
			case 7:
				coppyArray (a, b ,n);
				start = clock();
				quickSort(b, 0, n);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "Danh sach khi xep thu tu QUICK SORT la: " << endl;
					output (b, n);
				}
				if (duration > 0)
					cout << "Thoi gian QUICK SORT : " << duration * 1000000 << " Microsenconds." << endl;
				break;
			case 8:
				coppyArray (a, b ,n);
				start = clock();
				heapSort(b, n);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if (n < 100)
				{
					cout << "Danh sach khi xep thu tu HEAP SORT la: " << endl;
					output (b, n);
				}
				if (duration > 0)
					cout << "Thoi gian HEAP SORT : " << duration * 1000000 << " Microsenconds." << endl;
				break;
			case 9:
				cout << "Vui long nhap gia tri can tim x 1= ";
				cin >> x;
				start = clock();
				searchSequence (a, n ,x);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if (duration > 0)
					cout << "Thoi gian TIM KIEM TUAN TU : " << duration * 1000000 << " Microsenconds." << endl;
				break;
			case 10:
				cout << "Vui long nhap gia tri can tim x = ";
				cin >> x;
				start = clock();
				i = searchBinary (a, 0, n ,x);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if (i == -1)
					cout << "Khong tim thay gia tri x = " << x << "trong danh sach." << endl;
				else
					cout << "Tim thay x = " << x << " trong danh sach. " << endl;
				if (duration > 0)
					cout << "Thoi gian TIM KIEM NHI PHAN : " << duration * 1000000 << " Microsenconds." << endl;
				break;
			case 11:
				cout << "------Goodbye------ " << endl;
				break;
			default:
				break;
		}
	} while(choice != 11);
	system ("pause");
	return 0;
}