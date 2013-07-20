#include <iostream>
#include <string>
using namespace std;

template <class T>
struct treeNode {
	T data;
	treeNode<T> *left_ptr, *right_ptr;
	treeNode<T> (T init_data, treeNode<T> *left, treeNode<T> *right) {data = init_data; left_ptr=left; right_ptr=right;}
};

class binarySearchTree {
	
};

int main () {
    return 0;
};
