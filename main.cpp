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
	cout << root_ptr->data << endl;
	
	if (root_ptr->left_ptr) {
		print(depth+1, root_ptr->left_ptr);
	};
	if (root_ptr->right_ptr) {
		print(depth+1, root_ptr->right_ptr);
	};
};

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
	binarySearchTree<int> myTree = binarySearchTree<int>(10);
	myTree.addNode(15);
	myTree.addNode(5);
	myTree.addNode(3);
	myTree.addNode(6);
	myTree.addNode(13);
	myTree.addNode(16);
	myTree.print(0, myTree.getHead());
    return 0;
};
