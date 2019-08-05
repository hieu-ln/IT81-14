// Bai 2, Chuong 4
#include <iostream>
#include <stack>
using namespace std;

// Cau 2.1
struct Node
{
	int info;
	Node* left;
	Node* right;
};
Node* creatNode (int x)
{
	Node* p = new Node ();
	p ->info = x;
	p ->left = p ->right = NULL;
	return p;
}
// Cau 2.4
Node* Find (Node* root, int x)
{
	if (root == NULL)
		return NULL;
	Node* p = root;
	while (p != NULL)
	{
		if (p ->info > x)
			p = p ->left;
		else
			p = p ->right;
	}
	return p;
}
// Cau 2.3
void insertNode (Node* root, int x)
{
	Node* n = creatNode (x);
	if (root == NULL)
	{
		root = n;
		return;
	}
	else
	{
		Node* f = Find (root, x);
		if (f != NULL)
		{
			if (f ->info > x)
				f ->left = n;
			else
				f ->right = n;
		}
	}
}
int leftOf (const int value, const Node* root)
{
	return value < root ->info;
}
int rightOf (const int value, const Node* root)
{
	return value > root ->info;
}
int leftMostValue (const Node *root)
{
	while (root ->left != NULL)
		root = root ->left;
	return root ->info;
}
// Cau 2.5
Node *Delete (Node* root, int value)
{
	if ( root == NULL)
		return root;
	if (leftOf (value, root))
		root ->left = Delete (root ->left, value);
	else
		if (rightOf (value, root))
			root ->right = Delete (root ->right, value);
		else
		{
			if (root ->left == NULL)
			{
				Node *newRoot = root ->right;
				free(root);
				return newRoot;
			}
			if (root ->left == NULL)
			{
				Node *newRoot = root ->left;
				free(root);
				return newRoot;
			}
			root ->info = leftMostValue (root ->right);
			root ->right = Delete (root ->right, root ->info);
		}
		return root;
}
void creatTree(Node* &root, int a[], int n)
{
	for (int i = 0; i < n; i++)
		insertNode (root, a[i]);
}
void inOrder (struct Node *root)
{
	stack<Node*> s;
	Node* curr = root;
	while (curr != NULL || s.empty() == false)
	{
		while (curr != NULL)
		{
			s.push (curr);
			curr = curr ->left;
		}
		curr = s.top ();
		s.pop();
		cout << curr ->info << " ";
	}
}
void preOrder (struct Node *root)
{
	if (root == NULL)
		return;
	stack <Node *> nodeStack;
	nodeStack.push (root);
	while (nodeStack.empty () == false)
	{
		struct Node* temp_Node = nodeStack.top();
		cout << temp_Node ->info << " ";
		nodeStack.pop();
		if (temp_Node ->right)
			nodeStack.push (temp_Node ->right);
		if (temp_Node ->left)
			nodeStack.push (temp_Node ->left);
	}
}
void postOrderInterative (Node* root)
{
	stack<Node*> stk;
	stk.push (root);
	stack<int> out;
	while (!stk.empty())
	{
		Node *curr = stk.top();
		stk.pop();
		out.push (curr ->info);
		if (curr ->left)
			stk.push (curr ->left);
		if (curr ->right)
			stk.push (curr ->right);
	}
	while (!out.empty())
	{
		cout << out.top() << " ";
		out.pop();
	}
}
int main()
{
	Node* root = NULL;
	int a[] = {41, 6, 46, 46, 6, 54, 47, 11, 49, 47 };
	int n = 11;
	creatTree (root, a, n);
	insertNode (root, 24);
	cout << "Duyet LNR: ";
	inOrder (root);
	cout << "Duyet NLR: ";
	preOrder (root);
	cout << "Duyet LRN: ";
	postOrderInterative (root);
	cout << "\nCoa Node: 24";
	root = Delete (root, 24);
	inOrder (root);
	cout << "\nDuyet LNR: ";
	inOrder (root);
	cout << "\nDuyet NLR: ";
	preOrder (root);
	cout << "\nDuyet LRN: ";
	postOrderInterative (root);
	return 0;
}