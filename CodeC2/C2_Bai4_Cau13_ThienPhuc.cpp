//Project: C2_Bai4_Cau13.cpp
#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 100

int A[MAX], B[MAX], C[MAX];
int n, m;

int max(int m, int n) 
{  
	if (m > n)
		return m;
	else
		return n;
}

void nhap(int A[], int &n)
{
	for (int i = 0; i < n + 1; i++)
	{
		cout << "Nhap he so thu " << i << " = ";
		cin >> A[i];
	}
}

void xuat(int a[], int n) 
{ 
    for (int i = 0; i < n + 1; i++) 
    { 
       cout << a[i]; 
       if (i != 0) 
		   cout << "x^" << i ; 
       if (i != n) 
		   cout << " + "; 
    } 
}

int *add(int A[], int B[], int n, int m) 
{ 
   int size = max(n, m); 
   int *sum = new int[size];
   if (n > m)
   {
   for (int i = 0; i <= n; i++) 
	   sum[i] = A[i]; 
   for (int i = 0; i <= m; i++) 
       sum[i] += B[i];  

   }
   else
   {
	   for (int i = 0; i < m + 1; i++) 
		   sum[i] = B[i];
	   for (int i = 0; i < n + 1; i++) 
		   sum[i] += A[i];  
   }
     return sum; 
}

int *sub(int A[], int B[], int n, int m) 
{ 
	int size = max(m, n); 
    int *hieu = new int[size]; 
    for (int i = 0; i <= n; i++) 
		hieu[i] = A[i]; 
	for (int i = 0; i <= m; i++) 
		hieu[i] -= B[i];  
	return hieu; 
}

int *mul(int A[], int B[], int n, int m) 
{ 
	int *tich = new int[m + n - 1];  
    for (int i = 0; i <= m + n - 1; i++) 
	    tich[i] = 0; 
    for (int i = 0; i <= n; i++) 
    { 
		for (int j = 0; j <= m; j++) 
			tich[i + j] += A[i] * B[j]; 
	} 
	return tich; 
}

void chiadathuc(int A[],int B[],int n,int m)
{
	int i, j, z, x;
    double r[MAX], du[MAX];
	for (i = 0; i <= n; i++)
		du[i] = A[i];
       if (n < m)
		   cout << 0 << "\n";
       else
	   {
		   x = n;
           z = n - m;
           if (n == m)
		   {
			   r[z] = A[n] / B[n];
			   z++;
		   }
           else
		   {
			   while (z >= 0)
			   {
				   r[z] = du[x] / B[m];
                   int y = m;
				   for (i = x; i >= x - m; i--)
				   {
					   du[i] = du[i] - r[z] * B[y];
					   y--;
				   }
				   x--;
				   z--;
			   }
		   }
	   }
       for (i = n - m; i >= 0; i--)
	   {
		   if (i == 0)
			   cout << r[0] << "\n";
		   else
			   if(r[i] != 0)
				   cout << r[i] << "*x^" << i << "+";
	   }
       cout << "Da thuc du: ";
       for (i = x; i >= 0; i--)
	   {
		   if (i == 0)
			   cout << du[0] << "\n";
		   else
			   if (du[i] != 0)
				   cout << du[i] << "*x^" << i << "+";
	   }
}

int main()
{
	int chon;
	int *sum, *hieu, *tich;
	int size;
	while (true)
	{
		cout << "\nNhap chon:\n"
 			 << "0.Thoat\n"
			 << "1. Nhap vao da thuc A\n"
			 << "2. Nhap vao da thuc B\n"
			 << "3. Xuat ca 2 da thuc\n"
			 << "4. Tong 2 da thuc\n"
			 << "5. Hieu 2 da thuc\n"
			 << "6. Tich 2 da thuc\n"
			 << "7. Thuong 2 da thuc\n"
			 << "Chon: ";
		cin >> chon;
		switch(chon)
		{
		case 0:
			return 1;
			break;
		case 1:
			do
			{
				cout << "Nhap so mu cao nhat cua da thuc A: ";
				cin >> n;
				if (n < 0 || n > 100)
					cout << "Nhap sai. Nhap lai\n";
			} while(n < 0 || n > 100);	
			nhap(A, n);
			break;
		case 2:
			do
			{
				cout << "Nhap so mu cao nhat cua da thuc B: ";
				cin >> m;
				if (m < 0 || m > 100)
					cout << "Nhap sai. Nhap lai\n";
			} while (m < 0 || m > 100);
			nhap(B, m);
			break;
		case 3:
			cout << "Xuat 2 danh sach:\n";
			cout << "Danh sach A:\n";
			xuat(A, n);
			cout << "\nDanh sach B:\n";
			xuat(B, m);
			break;
		case 4:
			cout << "Tong 2 da thuc la\n";
			sum = add(A, B, n, m); 
			size = max(n, m); 
			xuat(sum, size); 
			break;
		case 5:
			cout << "Hieu 2 da thuc la\n";
			hieu = sub(A, B, n, m); 
			size = max(n, m); 
			xuat(hieu, size); 
			break;
		case 6:
			cout << "Tich 2 da thuc la\n";
			tich = mul(A, B, n, m);  
			xuat(tich, n + m - 1); 
			break;
		case 7:
			cout << "Thuong 2 da thuc la\n";
			chiadathuc(A, B, n, m);
			break;
		default:
			cout << "Gia tri chon khong hop le\n";
			break;
		}
	}
	return 0;
}