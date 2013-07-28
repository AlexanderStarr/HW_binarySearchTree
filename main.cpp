#include <iostream>
#include <string>
using namespace std;

template <class T>
struct treeNode {
	T data;
	treeNode<T> *left_ptr, *right_ptr;
	treeNode<T> (T init_data, treeNode<T> *left, treeNode<T> *right) {data = init_data; left_ptr=left; right_ptr=right;}
};

template <class T>
class binarySearchTree {
	treeNode<T> *head;
	int size;
public:
	binarySearchTree(){head=NULL; size=0;};
	binarySearchTree(T data);
	treeNode<T> * getHead() {return head;};
	void print(int depth, treeNode<T> *root_ptr);
	void inorderTraverse(treeNode<T> *root_ptr);
	treeNode<T> * treeSearch(T searchData);
	void addNode(T addData);
};

template <class T>
binarySearchTree<T>::binarySearchTree(T data) {
	treeNode<T> *tmp = new treeNode<T>(data, NULL, NULL);
	head = tmp;
	size = 1;
};

template <class T>
void binarySearchTree<T>::print(int depth, treeNode<T> *root_ptr) {
	for (int i=0; i<depth; i++) {
		cout << "\t";
	};
	if (root_ptr) {
		cout << root_ptr->data << endl;
		if (root_ptr->left_ptr || root_ptr->right_ptr) {
			print(depth+1, root_ptr->left_ptr);
			print(depth+1, root_ptr->right_ptr);
		}
	}
	else {
		cout << "NULL" << endl;
	}

};

template <class T>
void binarySearchTree<T>::inorderTraverse(treeNode<T> *root_ptr) {
	if (root_ptr->left_ptr) {
		inorderTraverse(root_ptr->left_ptr);
	};
	cout << root_ptr->data << " ";
	if (root_ptr->right_ptr) {
		inorderTraverse(root_ptr->right_ptr);
	};
}

template <class T>
treeNode<T> * binarySearchTree<T>::treeSearch(T searchData) {
	treeNode<T> *curr = head, *prev = head;
	while (curr) {
		if (searchData == curr->data) {
			return curr;
		}
		else if (searchData < curr->data) {
			prev = curr;
			curr = prev->left_ptr;
		}
		else if (searchData > curr->data) {
			prev = curr;
			curr = prev->right_ptr;
		}
	}
	return prev;
}

template <class T>
void binarySearchTree<T>::addNode(T addData) {
	treeNode<T> *loc = treeSearch(addData);
	treeNode<T> *newNode = new treeNode<T>(addData, NULL, NULL);
	if (newNode->data < loc->data) {
		loc->left_ptr = newNode;
	}
	else if (newNode->data > loc->data) {
		loc->right_ptr = newNode;
	}
};

int main () {
	char type;
	while (type != 'i' && type != 's') {
		cout << "Please choose (s)tring or (i)nteger: ";
		cin >> type;
	}
	cout << "Enter the root node: ";
	char again = 'y';
	if (type == 'i') {
		int node;
		cin >> node;
		binarySearchTree<int> myTree = binarySearchTree<int>(node);
		while (again == 'y') {
			cout << "Enter the new node: ";
			cin >> node;
			myTree.addNode(node);
			cout << "Add another? [y/n] ";
			cin >> again;
		}
		cout << "Your tree is represented below:" << endl;
		myTree.print(0, myTree.getHead());
		cout << endl;
		cout << "The inorder traversal of your tree yields:" << endl;
		myTree.inorderTraverse(myTree.getHead());
		
	}
	else if (type == 's') {
		string node;
		cin >> node;
		binarySearchTree<string> myTree = binarySearchTree<string>(node);
		while (again == 'y') {
			cout << "Enter the new node: ";
			string node;
			cin >> node;
			myTree.addNode(node);
			cout << "Add another? [y/n] ";
			cin >> again;
		}
		cout << "Your tree is represented below:" << endl;
		myTree.print(0, myTree.getHead());
		cout << endl;
		cout << "The inorder traversal of your tree yields:" << endl;
		myTree.inorderTraverse(myTree.getHead());
		
	}
	return 0;
};
