#pragma once
#include <iostream>
using namespace std;

class BinaryTree
{
private:
	class Node {
	private:
		int id;
		int value;
		Node* left;
		Node* right;

	public:
		Node(int id, int value, Node* left, Node* right);
		Node(int id, int value) : Node(id, value, nullptr, nullptr) {}
		~Node(){};

		int getValue() { return value; }
		Node* getLeft() { return left; }
		Node* getRight() { return right; }

		//добавление узла к дереву
		void addNode(int id, int value);

		//методы поиска
		int findIdWithValue(int value);
		int findMin();
		int findMax();

		//вывод на экран
		void display(int level);
	};
private:
	Node* root;
	int nodeCount;


public:
	BinaryTree();
	~BinaryTree() {};

	//методы работы с деревом
	void addNode(int value);
	int findIdWithValue(int value);
	void addArr(int n, int *arr);
	int findMin();
	int findMax();

	// методы вывода на экран
	void display();
};