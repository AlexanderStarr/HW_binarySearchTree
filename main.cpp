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
};

template <class T>
binarySearchTree<T>::binarySearchTree(T data) {
	treeNode<T> *tmp = new treeNode<T>(data, NULL, NULL);
	head = tmp;
	size = 1;
};

int main () {
	binarySearchTree<int> myTree = binarySearchTree<int>(10);
    return 0;
};
