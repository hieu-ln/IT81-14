#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
using namespace std;

#define MAX 20

struct node
{
	int info;
	node *link;
};
node *first[MAX];
int n;
char vertex[MAX];

node *sp;
node *front, *rear;

//STACK
void initStack()
{
	sp = NULL;
}
int isEmptyS()
{
	if (sp == NULL)
		return 1;
	return 0;
}
void pushS(int x)
{
	node *p;
	p = new node;
	p->info = x;
	p->link = sp;
	sp = p;
}
int popS(int &x)
{
	if(sp!= NULL)
	{
		node *p = sp;
		x = p -> info;
		sp= p ->link;
		delete p;
		return 1;
	}
	return 0;
}
//QUEUE
void initQueue()
{
	front = NULL;
	rear = NULL;
}
int isEmptyQ()
{
	if(front == NULL)
		return 1;
	return 0;
}
void pushQ(int x)
{
	node *p = new node;
	p->info = x;
	p->link = NULL;
	if(rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}
int popQ(int &x)
{
	if(front != NULL)
	{
		node *p = front;
		front = p->link;
		x = p->info;
		if(front == NULL)
		{
			rear = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}

void initGraph(int &n)
{
	for(int i = 0; i < n; i++)
		first[i] = NULL;
	n = 0;
}
void insertLast(node *&first, node*p)
{
	if(first == NULL)
		first = p;
	else
	{
		node *q = first;
		while(q	-> link != NULL)
		{
			q = q -> link;
		}
		q -> link = p;
	}
}
void inputGraphFromText()
{
	string line;
	ifstream myfile("danhsachke1.txt");
	if(myfile.is_open())
	{
		myfile >> n;
		for(int i = 0; i < n; i++)
			myfile >> vertex[i];
		string str;
		int i = 0;
		while(getline(myfile, str))
		{
			istringstream ss(str);
			int u;
			while(ss >> u)
			{
				node *p = new node;
				p->info = u;
				p->link = NULL;
				insertLast(first[i - 1], p);
			}
			i++;
		}
	}
}

void inputGraph()
{
	cout << "Nhap so dinh cua do thi: ";
	cin >> n;
	cout << "Nhap ten dinh: ";
	for(int i = 0; i < n; i++)
		cin >> vertex[i];
	for(int i = 0; i < n+ 1; i++)
	{
		if(i > 0)
			cout << "Nhap DSK cua dinh thu " << i - 1 << " (" << vertex[i - 1] << ")";
		int u;
		string str;
		while(getline(cin, str))
		{
			istringstream ss(str);
			while(ss >> u)
			{
				node *p = new node;
				p->info = u;
				p->link = NULL;
				insertLast(first[i - 1], p);
			}
			break;
		}
	}
}
//Cau 5.2:
void outputGraph()
{
	for(int i = 0; i < n; i++)
	{
		cout << "Dinh " << i << " (" << vertex[i] << "): ";
		node *p = first[i];
		while(p != NULL)
		{
			cout << p->info << " ";
			p = p->link;
		}
		cout << endl;
	}
}
void output(int a[], int n)
{
	for(int i = 0; i < n; i++)
		cout << vertex[a[i]] << " ";
}

//BFS
int C[100];
int bfs[100];
int nbfs = 0;
void initC()
{
	for(int i = 0; i < n; i++)
		C[i] = 1;
}
void BFS(int v)
{
	int p;
	node *w;
	pushQ(v);
	C[v] = 0;
	while(front != NULL)
	{
		popQ(p);
		bfs[nbfs] = p;
		w = first[p];
		nbfs++;
		while(w != NULL)
		{
			if(C[w->info])
			{
				pushQ(w->info);
				C[w->info] = 0;
			}
			w = w->link;
		}
	}
}
//Cau 4.4: Duyet do thi theo chieu sau
int dfs[100];
int ndfs = 0;
void DFS(int s)
{
	pushS(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int u = s;
	node *v = NULL;
	while(isEmptyS() == 0)
	{
		if(v == NULL)
			popS(u);
		v = first[u];
		while(v != NULL)
		{
			if(C[v->info] == 1)
			{
				pushS(u);
				pushS(v->info);
				dfs[ndfs] = v->info;
				ndfs++;
				C[v->info] = 0;
				u = v->info;
				break;
			}
			v = v->link;
		}
	}
}
void search_By_Bfs(int x, int v)
{
	int p;
	node *w;
	pushQ(v);
	C[v] = 0;
	while(front != NULL)
	{
		popQ(p);
		if(x == p)
		{
			cout << "Tim thay " << x << endl;
			return;
		}
		w = first[p];
		while(w != NULL)
		{
			if(C[w->info])
			{
				pushQ(w->info);
				C[w->info] = 0;
			}
			w = w->link;
		}
	}
}

int main()
{
	int choice, x;
	system("cls");
	cout << "-------- Bai tap 5, chuong 5, do thi --------\n";
	cout << "1. Khoi tao danh sach ke rong\n";
	cout << "2. Nhap danh sach ke tu file text\n";
	cout << "3. Nhap danh sach ke\n";
	cout << "4. Xuat danh sach ke\n";
	cout << "5. Duyet do thi theo chieu rong (BFS)\n";
	cout << "6. Duyet do thi theo chieu sau (DFS)\n";
	cout << "7. Tim dinh co gia tri x theo BFS\n";
	cout << "8. Thoat\n";
	do{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			n = 10;
			initGraph(n);
			cout << "Khoi tao danh sach rong thanh cong\n";
			break;
		case 2:
			inputGraphFromText();
			cout << "Nhap ma tran ke tu file text thanh cong:\n";
			outputGraph();
			break;
		case 3:
			inputGraph();
			break;
		case 4:
			outputGraph();
			break;
		case 5:
			initQueue();
			initC();
			cout << "Vui long nhap dinh xuat phat: ";
			cin >> x;
			nbfs = 0;
			BFS(x);
			cout << "Thu tu sau khi duyet BFS:\n";
			output(bfs, n);
			cout << endl;
			break;
		case 6:
			initStack();
			initC();
			cout << "Vui long nhap dinh xuat phat: ";
			cin >> x;
			ndfs = 0;
			DFS(x);
			cout << "Thu tu dinh sau khi duyet DFS:\n";
			output(dfs, n);
			cout << endl;
			break;
		case 7:
			initQueue();
			initC();
			cout << "Vui long nhap gia tri can tim: ";
			cin >> x;
			initQueue();
			initC();
			nbfs = 0;
			search_By_Bfs(x, 0);
			break;
		case 8:
			cout << "Tam biet\n";
			break;
		default:
			break;
		}
	}while(choice != 8);
	return 0;
}