#include <iostream>
#include<vector>
using namespace std;

template <class T = int>
class btree
{
public:
	btree *left;
	T data;
	btree *right;
	btree(T data)
	{
		this->left = NULL;
		this->data = data;
		this->right = NULL;
	}
};

template <class T = int>
btree<T> *insertion(btree<T> *root, T data)
{
	if (root == NULL)
	{
		btree<T>* temp = new btree<T>(data);
		return temp;
	}
	else if (root->data > data)
		root->left = insertion(root->left, data);
	else if (root->data < data)
		root->right = insertion(root->right, data);
	else
		cout << "key can't accepted...\n";
	return root;
}

template <class T = int>
btree<T> *deletion(btree<T> *root, T data)
{
	if (root == NULL)
	{
		cout<<"key can't delete...\n";
		return root;
	}
	else if (root->data > data)
		root->left = deletion(root->left, data);

	else if (root->data < data)
		root->right = deletion(root->right, data);

	else if (root->left == NULL)
	{
		btree<T> *temp = root->right;
		delete root;
		return temp;
	}

	else if (root->right == NULL)
	{
		btree<T> *temp = root->left;
		delete root;
		return temp;
	}

	else
	{
		btree<T> *temp = root;
		btree<T> *del = root->right;
		while (del != NULL && del->left != NULL)
		{
			temp = del;
			del = del->left;
		}
		root->data = del->data;
		if (temp != root)
			temp->left = del->right;

		else
			temp->right = del->right;

		delete del;
	}
	return root;
}

// template <class T = int>
// void inOrder(btree<T> *root)
// {
// 	if (root != NULL)
// 	{
// 		inOrder(root->left);
// 		cout << root->data << " ";
// 		inOrder(root->right);
// 	}
// }
template<class T = int>
void preOrder(btree<T> *root)
{
	if(root != NULL)
	{
		cout<<root->data<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

template<class T=int>
void inOrder(btree<T> *root)
{
	vector<btree<T>*> V;
	V.push_back(root);
	int i = 0;
	while(V[i] != NULL)
	{
		if(V[i]->left != NULL)
		{
			V.push_back(V[i]->left);
			i++;
			continue;
		}
		else
		{
			cout<<V[i]->data<<" ";
		}
		if(V[i]->right != NULL)
		{
			V.push_back(V[i]->right);
			i++;
		}
	}
}

template <class T = int>
void run()
{
	btree<T> *root = NULL;
	while (1)
	{
		int ch;
		cin >> ch;
		T data;
		switch (ch)
		{
		case 1:
			cout << "enter the data: ";
			cin >> data;
			root = insertion(root, data);
			break;
		case 2:
			cout << "enter the data: ";
			cin >> data;
			root = deletion(root, data);
			break;
		case 3:
			inOrder(root);
			cout << "\n";
			break;
		case 4:
			preOrder(root);
			cout<<"\n";
			break;
		case 5:break;
			// root = Rrotation(root);break;
		case 6:exit(0);
		}
	}
}
int main()
{
	run<int>();
	return 0;
}