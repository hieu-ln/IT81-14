#include <iostream>
#include <ctime>
using namespace std ;
# define MAX 3000 
int a[MAX] ;
int n ;
void init(int a[], int &n)
{
	cout << "Nhap vao so luong phan tu cua danh sach: \n" ;
	cin >> n ;
	for(int i = 0; i < n; i++)
		a[i] = rand() % 10000 + 1 ;
	cout << "Danh sach da duoc nhap ngau nhien nhu sau\n" ;
	for(int i = 0; i < n; i++)
		cout << a[i] << "	" ;
	cout << endl ;
}
void input(int a[], int &n)
{
	cout << "Nhap vao so luong phan tu cua danh sach: " ;
	cin >> n ;
	cout << "Nhap vao cac phan tu cua danh sach:\n" ;
	for(int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = " ;
		cin >> a[i] ;
	}
}
void output(int a[], int n)
{
	for(int i = 0; i < n; i++)
		cout << a[i] << "	" ;
	cout << endl ;
}
void CopyArray(int a[], int b[], int n)
{
	for(int i = 0; i < n; i++)
		b[i] = a[i] ;
}
void InsertionSort(int a[], int n)
{
	int x, i, j ;
	for(int i = 1; i < n; i++)
	{
		x = a[i] ;
		j = i - 1 ;
		while(0 <= j && x < a[j])
		{
			a[j + 1] = a[j] ;
			j-- ;
		}
		a[j + 1] = x ;
	}
}
void swap(int &a, int &b)
{
	int t = a;
	a = b ;
	b = t ;
}
void SelectionSort(int a[], int n)
{
	int minidx, i, j ;
	for(i = 0; i < n - 1; i++)
	{
		minidx = i ;
		for(j = i + 1; j < n; j++)
			if(a[j] < a[minidx])
				minidx = j ;
		swap(a[minidx], a[i]);
	}
}
void InterchangeSort(int a[], int n)
{
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			if(a[i] > a[j])
				swap(a[i], a[j]) ;
}
void BubbleSort(int a[], int n)
{
	for(int i = 0; i < n - 1; i++)
		for(int j = n - 1; j > i; j--)
			if(a[j - 1] > a[j])
				swap(a[j], a[j - 1]) ;
}
void QuickSort(int a[], int left, int right)
{
	int x = a[(left + right)/2] ;
	int i = left ;

	int j = right ;
	while(i < j)
	{
		while(a[i] < x)
			i++ ;
		while(a[j] > x)
			j-- ;
		if(i <= j)
		{
			swap(a[i], a[j]) ;
			i++ ;
			j-- ;
		}
	}
	if(left < j)
		QuickSort(a, left, j) ;
	if(i < right)
		QuickSort(a, i, right) ;
}
void shift(int a[], int i, int n)
{
	int j = 2 * i + 1 ;
	if(j >= n)
		return ;
	if(j + 1 < n)
		if(a[j] < a[j + 1])
			j++ ;
	if(a[i] >= a[j])
		return ;
	else
	{
		int x = a[i] ;
		a[i] = a[j] ;
		a[j] = x ;
		shift(a, j, n) ;
	}
}
void HeapSort(int a[], int n)
{
	int i = n / 2 ;
	while(i >= 0)
	{
		shift(a, i, n - 1) ;
		i-- ;
	}
	int right = n - 1 ;
	while(right > 0)
	{
		swap(a[0], a[right]) ;
		right-- ;
		if(right > 0)
			shift(a, 0, right) ;
	}
}
int Search(int a[], int n, int X)
{
	int i = 0 ;
	while(i < n && a[i] != X)
		i++ ;
	if(i < n)
		return i ;
	return -1 ;
}
int BinarySearch(int a[], int n, int X)
{
	int left = 0, right = n - 1, mid ;
	while(left <= right)
	{
		mid = (left + right) / 2 ;
		if(a[mid] == X)
			return mid ;
		if(X > a[mid])
			left = mid + 1 ;
		else
			right = mid - 1 ;
	}
	return -1 ;
}
int main()
{
	int b[MAX] ;
	clock_t start ;
	double duration ;
	int choice, x, i ;
	system("cls") ;
	cout << " ---------- BAI TAP 1 , CHUONG 3 , XEP THU TU VA TIM KIEM ---------- " << endl;
	cout << "0. Khoi tao danh sach ngau nhien " << endl ;
	cout << "1. Nhap danh sach " << endl ;
	cout << "2. Xuat danh sach " << endl ;
	cout << "3. Xep thu tu danh sach bang SELECTION SORT" << endl ;
	cout << "4. Xep thu tu danh sach bang INSERTION SORT" << endl ;
	cout << "5. Xep thu tu danh sach bang BUBBLE SORT" << endl ;
	cout << "6. Xep thu tu danh sach bang INTERCHANGE SORT" << endl ;
	cout << "7. Xep thu tu danh sach bang QUICK SORT" << endl ;
	cout << "8. Xep thu tu danh sach bang HEAP SORT" << endl ;
	cout << "9. Tim kiem phan tu x bang TIM KIEM TUAN TU" << endl ;
	cout << "10. Tim kiem phan tu x bang TIM KIEM NHI PHAN" << endl ;
	cout << "11. Thoat" << endl ;
	do{
		cout << "\nVui long chon so de thu hien: " ;
		cin >> choice ;
		switch(choice)
		{
		case 0:
			init(a, n) ;
			break ;
		case 1:
			input(a, n) ;
			break ;
		case 2:
			cout << "Danh sach la: " << endl ;
			output(a, n) ;
			break ;
		case 3:
			CopyArray(a, b, n) ;
			start = clock() ;
			SelectionSort(b, n) ;
			duration = (clock() - start) / (double) CLOCKS_PER_SEC ;
			if(n < 100)
			{
				cout << "DS sau khi xep thu tu voi SELECTION SORT la:\n" ;
				output(b, n) ;
			}
			if(duration > 0)
				cout << "Thoi gian SELECTION SORT: " << duration * 1000000 ;
			break ;
		case 4:
			CopyArray(a, b, n) ;
			start = clock() ;
			InsertionSort(b, n) ;
			duration = (clock() - start) / (double) CLOCKS_PER_SEC ;
			if(n < 100)
			{
				cout << "DS sau khi xep thu tu voi INSERTION SORT la:\n" ;
				output(b, n) ;
			}
			if(duration > 0)
				cout << "Thoi gian INSERTION SORT: " << duration * 1000000 ;
			break ;
		case 5:
			CopyArray(a, b, n) ;
			start = clock() ;
			BubbleSort(b, n) ;
			duration = (clock() - start) / (double) CLOCKS_PER_SEC ;
			if(n < 100)
			{
				cout << "DS sau khi xep thu tu voi BUBBLE SORT la:\n" ;
				output(b, n) ;
			}
			if(duration > 0)
				cout << "Thoi gian BUBBLE SORT: " << duration * 1000000 ;
			break ;
		case 6:
			CopyArray(a, b, n) ;
			start = clock() ;
			InterchangeSort(b, n) ;
			duration = (clock() - start) / (double) CLOCKS_PER_SEC ;
			if(n < 100)
			{
				cout << "DS sau khi xep thu tu voi INTERCHANGE SORT la:\n" ;
				output(b, n) ;
			}
			if(duration > 0)
				cout << "Thoi gian INTERCHANGE SORT: " << duration * 1000000 ;
			break ;
		case 7:
			CopyArray(a, b, n) ;
			start = clock() ;
			QuickSort(b, 0, n - 1) ;
			duration = (clock() - start) / (double) CLOCKS_PER_SEC ;
			if(n < 100)
			{
				cout << "DS sau khi xep thu tu voi QUICK SORT la:\n" ;
				output(b, n) ;
			}
			if(duration > 0)
				cout << "Thoi gian QUICK SORT: " << duration * 1000000 ;
			break ;
		case 8:
			CopyArray(a, b, n) ;
			start = clock() ;
			HeapSort(b, n) ;
			duration = (clock() - start) / (double) CLOCKS_PER_SEC ;
			if(n < 100)
			{
				cout << "DS sau khi xep thu tu voi HEAP SORT la:\n" ;
				output(b, n) ;
			}
			if(duration > 0)
				cout << "Thoi gian HEAP SORT: " << duration * 1000000 ;
			break ;
		case 9:
			cout << "Vui long nhap gia tri x: " ;
			cin >> x ;
			start = clock() ;
			i = Search(a, n, x) ;
			duration = (clock() - start) / (double) CLOCKS_PER_SEC ;
			if(i == -1)
				cout << "Khong tim thay x = " << x << " trong day !" << endl ;
			else
				cout << "Tim thay x = " << x << " tai vi tri i = " << i << endl ;
			if(duration > 0)
				cout << "\nThoi gian tim kiem TUAN TU la: " << duration * 1000000 ;
			break ;
		case 10:
			cout << "Vui long nhap gia tri x: " ;
			cin >> x ;
			start = clock() ;
			i = BinarySearch(a, n, x) ;
			duration = (clock() - start) / (double) CLOCKS_PER_SEC ;
			if(i == -1)
				cout << "Khong tim thay x = " << x << " trong day !" << endl ;
			else
				cout << "Tim thay x = " << x << " tai vi tri i = " << i << endl ;
			if(duration > 0)
				cout << "\nThoi gian tim kiem NHI PHAN la: " << duration * 1000000 ;
			break ;
		case 11:
			cout << "Chao tam biet\n" ;
			break;
		default:
			break ;
		}
	} while(choice < 11) ;
	system("pause") ;
	return 0 ;
}