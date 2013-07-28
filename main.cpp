#include <iostream>
#include <string>
using namespace std;

// Each tree node needs a left pointer and a right pointer.
// Also I use templates so it can handle any data type.
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

// The print function is really just a preorder traversal, with
// preceeding tabs to indicate the depth of the node.
template <class T>
void binarySearchTree<T>::print(int depth, treeNode<T> *root_ptr) {
	for (int i=0; i<depth; i++) {
		cout << "\t";
	};
	if (root_ptr) {
		cout << root_ptr->data << endl;
		
		// It should only print the children if there is at least one.
		if (root_ptr->left_ptr || root_ptr->right_ptr) {
			print(depth+1, root_ptr->left_ptr);
			print(depth+1, root_ptr->right_ptr);
		}
	}
	// Because the order of the nodes is important, NULL should be
	// displayed for missing nodes, so that the order is unambiguous.
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

// This either returns the element containing searchData, or the node
// which should be the parent of searchData.
template <class T>
treeNode<T> * binarySearchTree<T>::treeSearch(T searchData) {
	// It keeps track of the current AND previous node in case
	// searchData is not found.
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
	// If searchData is not found, then this returns the node which
	// is to be searchData's parent.
	return prev;
}

template <class T>
void binarySearchTree<T>::addNode(T addData) {
	// First search for the data in the tree.
	treeNode<T> *loc = treeSearch(addData);
	
	// Then create a new node for the data.
	treeNode<T> *newNode = new treeNode<T>(addData, NULL, NULL);
	
	// loc might not be a node with the same data as newNode, so it must check.
	// It assigns the proper pointer to newNode if the data is not equal.
	// Otherwise, if the data is equal, it does nothing and frees the newNode memory.
	if (newNode->data < loc->data) {
		loc->left_ptr = newNode;
	}
	else if (newNode->data > loc->data) {
		loc->right_ptr = newNode;
	}
	else {
		delete newNode;
	}

};

// This contains the code for the input and output of the tree.
template <class T>
void buildTree() {
	cout << "Enter the root node: ";
	char again = 'y';
	T node;
	cin >> node;
	binarySearchTree<T> myTree = binarySearchTree<T>(node);
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

int main () {
	char type;
	while (type != 'i' && type != 's') {
		cout << "Please choose (s)tring or (i)nteger: ";
		cin >> type;
	}
	if (type == 'i') {
		buildTree<int>();
	}
	else if (type == 's') {
		buildTree<string>();
	}
	return 0;
};
