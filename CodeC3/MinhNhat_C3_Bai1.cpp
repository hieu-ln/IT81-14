#include <iostream>
using namespace std;

#define MAX 100
int a[MAX];
int n;

void nhap()
{
	cout << "Nhap vao so luong phan tu: ";
	cin >> n;
	cout << "Nhap vao cac gi tri cho phan tu: ";
	for (int i = 0; i < n;i++)
	{
		cin >> a[i];
	}
}
void xuat()
{
	cout << "Gia tri cac phan tu cua danh sach laf: ";
	for (int i = 0; i< n; i++)
	{
		cout << a[i] << " ";
	}
}
void insertionSort()
{
	int x, i, j;
	for(int i = 1; i < n; i++)
	{
		x = a[i];
		j= i - 1;
		while(j >= 0 && x < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
void swap(int x, int y)
{
	int temp;
	temp = y;
	y = x;
	x = temp;
}
void selectionSort()
{
	int min_pos, i, j;
	for(i = 0; i < n; i++)
	{
		min_pos =i;
		for(j = i + 1; j< n;j++)
			if(a[j] < a[min_pos])
				min_pos= j;
		swap(a[min_pos], a[i]);
	}
}
void interchangeSort()
{
	for(int i = 0; i < n- 1; i++)
		for(int j = i + 1; j < n; j++)
			if(a[i] > a[j])
				swap(a[i], a[j]);
}
void bubbleSort()
{
	for(int i= 0; i< n - 1; i++)
		for(int j = n -1; j >i; j--)
			if(a[j-1] > a[j])
				swap(a[j], a[j - 1]);
}
void quickSort(int left, int right)
{
	int x = a[(left + right) / 2];
	int i = left;
	int j= right;
	while(i < j)
	{
		while(a[i] < x) i++;
		while(a[j] > x) i--;
		if(i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if(left <j) quickSort(left, j);
	if(i < right) quickSort(i, right);
}
void shift(int i, int n)
{
	int j = 2*j + 1;
	if(j >= n)
		return;
	if(j + 1 < n)
		if(a[j] < a[j + 1])
			j++;
	if(a[i] >= a[j])
		return;
	else
	{
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift(j, n);
	}
}
void heapSort()
{
	int i = n/2;
	while(i >= 0)
	{
		shift(i, n - 1);
		i--;
	}
	int right = n - 1;
	while(right > 0)
	{
		swap(a[0], a[right]);
		right--;
		if(right > 0)
			shift(0, right);
	}
}
int search(int x)
{
	int i = 0;
	while(i < n && a[i] != x)
		i++;
	if(i < n)
		return i;
	return -1;
}
int binarySearch(int x)
{
	int left = 0, right = n - 1, mid;
	while(left <= right)
	{
		mid = (left + right) / 2;
		if(a[mid] == x) return mid;
		if(x > a[mid]) left = mid + 1;
		else right = mid - 1;
	}
	return -1;
}
int main()
{
	int c, x;
	do{
		cout << "1.Nhap\n2. Xuat\n3. Insertsort\n4. SelectionSort\n5. InterchangeSort\n6.BubbleSort\n7. QuickSort\n8. Heapsort\n9. Tim kiem tuan tu\n10. Tim kiem nhi phan\n11. thoat!\nChon: ";
		cin >> c;
		switch(c)
		{
		case 1:
			nhap();
			break;
		case 2:
			xuat();
			break;
		case 3:
			insertionSort();
			break;
		case 4:
			selectionSort();
			break;
		case 5:
			interchangeSort();
			break;
		case 6:
			bubbleSort();
			break;
		case 7:
			quickSort(0, n);
			break;
		case 8:
			heapSort();
			break;
		case 9:
			cout << "nhap vao so muon tim : ";
			cin >> x;
			cout << " phan tu tim duoc o vi tri: " << search(x) << endl;
			break;
		case 10:
			cout << "nhap vao so muon tim : ";
			cin >> x;
			cout << " phan tu tim duoc o vi tri: " << binarySearch(x) << endl;
			break;
		case 11:
			cout << "tam biet!";
			break;
		}
	}while(c != 11);
}