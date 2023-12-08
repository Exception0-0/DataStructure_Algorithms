#include <iostream>
using namespace std;
class AVL
{
public:
	AVL *left;
	int key;
	int height;
	AVL *right;
	AVL(int key)
	{
		this->left = NULL;
		this->key = key;
		this->height = 1;
		this->right = NULL;	
	}
};

int getHeight(AVL *node)
{
	if (node == NULL)
		return 0;
	return node->height;
}

int factor(AVL *node)
{
	if(node == NULL)
		return 0;
	return getHeight(node->left) - getHeight(node->right);
}

// travesal
void preOrder(AVL *node){
	if (node != NULL){
		cout << node->key << " ";
		preOrder(node->left);
		preOrder(node->right);
	}
}

// Right rotation code
AVL *Rrotation(AVL *node){
	AVL *Lnode = node->left;
	AVL *Rnode = Lnode->right;
	Lnode->right = node;
	node->left = Rnode;
	node->height = 1 + max(getHeight(node->left), getHeight(node->right));
	Lnode->height = 1 + max(getHeight(Lnode->left), getHeight(Lnode->right));
	return Lnode;
}

// Left rotation code
AVL *Lrotation(AVL *node){
	AVL *Rnode = node->right;
	AVL *Lnode = Rnode->left;
	Rnode->left = node;
	node->right = Lnode;
	Rnode->height = 1 + max(getHeight(Rnode->left), getHeight(Rnode->right));
	node->height = 1 + max(getHeight(node->left), getHeight(node->right));
	return Rnode;
}

AVL *insertion(AVL *node, int key){
	if (node == NULL)
		return new AVL(key);

	else if (node->key > key)
		node->left = insertion(node->left, key);

	else if (node->key < key)
		node->right = insertion(node->right, key);

	else{
		cout << "key can't add...\n";
		return node;
	}

	node->height = 1 + max(getHeight(node->left), getHeight(node->right));
	int BF = factor(node);

	// left left rotation
	if (BF > 1 && node->left->key > key)
		return Rrotation(node);

	// Right Right Rotation
	else if (BF < -1 && node->right->key < key)
		return Lrotation(node);

	// Left Right Rotation
	else if (BF > 1 && node->left->key < key){
		node->left = Lrotation(node->left);
		return Rrotation(node);
	}

	// Right Left Rotation
	else if (BF < -1 && node->right->key > key){
		node->right = Rrotation(node->right);
		return Lrotation(node);
	}

	return node;
}

AVL *deletion(AVL *node, int key){
	if (node == NULL){
		cout << "key can't delete...\n";
		return node;
	}
	else if (node->key > key)
		node->left = deletion(node->left, key);

	else if (node->key < key)
		node->right = deletion(node->right, key);

	else if (node->right == NULL){
		AVL *temp = node->left;
		delete node;
		return temp;
	}

	else if (node->left == NULL){
		AVL *temp = node->right;
		delete node;
		return temp;
	}

	else{
		AVL *temp = node;
		AVL *del = node->left;
		while (del != NULL && del->right != NULL){
			temp = del;
			del = del->right;
		}
		if (temp != node){
			temp->right = del->left;
			node->key = del->key;
		}
		else{
			temp->left = del->left;
			node->key = del->key;
		}
		delete del;
	}
	node->height = 1 + max(getHeight(node->left), getHeight(node->right));
	int BF = factor(node);

	// left left rotation
	if (BF > 1 && factor(node->left) >= 0){
		cout<<"left left\n";
		return Rrotation(node);
	}
	// Right Right Rotation
	else if (BF < -1 && factor(node->right) <= 0){
		cout<<"right right\n";
		return Lrotation(node);
	}
	// Left Right Rotation
	else if (BF > 1 && factor(node->left) < 0){
		cout<<"left right\n";
		node->left = Lrotation(node->left);
		return Rrotation(node);
	}

	// Right Left Rotation
	else if (BF < -1 && factor(node->right) > 0){
		cout<<"right left\n";
		node->right = Rrotation(node->right);
		return Lrotation(node);
	}

	return node;
}
int main(){
	AVL *root = NULL;
	root = insertion(root,50);
	root = insertion(root,100);
	root = insertion(root,200);
	root = insertion(root,300);
	root = insertion(root,250);
	root = insertion(root,120);
	root = insertion(root,130);

	preOrder(root);
	cout<<"\n";
	deletion(root,50);
	preOrder(root);
	cout<<"\n";
	return 0;
}