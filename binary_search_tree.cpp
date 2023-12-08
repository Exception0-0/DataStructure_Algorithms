#include <iostream>
#include<vector>
using namespace std;

class BST{
public:
	BST *left;
	int data;
	BST *right;
	BST(int data){
		this->left = NULL;
		this->data = data;
		this->right = NULL;
	}
};

BST* insertion(BST *root, int data){
	if (root == NULL){
		BST* temp = new BST(data);
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

BST* deletion(BST *root,int data){
	if (root == NULL){
		cout<<"key can't delete...\n";
		return root;
	}
	else if (root->data > data)
		root->left = deletion(root->left, data);

	else if (root->data < data)
		root->right = deletion(root->right, data);

	else if (root->left == NULL){
		BST *temp = root->right;
		delete root;
		return temp;
	}

	else if (root->right == NULL){
		BST *temp = root->left;
		delete root;
		return temp;
	}

	else{
		BST *temp = root;
		BST *del = root->right;
		while (del != NULL && del->left != NULL){
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