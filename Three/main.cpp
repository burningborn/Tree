#include <iostream>
#include <string>
using namespace std;
#include <string>
#include "BinaryTree.h"

#define delimiter    "\n=================================================================================\n"

BinaryTree feelTree() {
	BinaryTree tree;
	int arr[]{ 14, 75, 29, 10, 62, 87, 76, 77, 88, 49 };
	for (int i = 0; i < 10; i++)
		tree.addNode(arr[i]);
	return tree;
}

int fillArr(int n, int *arr)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		int Rand, key = 0;
		do
		{
			Rand = rand() % 200;
			for (int j = 0; j < i; j++)
			{
				if (arr[j] == Rand)
					++key;
				break;
			}
				
		} while (key);
		arr[i] = Rand;
	}
	return *arr;
}

void showArr(int n, int* arr)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ", ";
		if ((i + 1) % 10 == 0)
			cout << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	// 1. ƒерево
	// 2. ”зел дерева 

	BinaryTree tree = feelTree();
	tree.display(); // дерево после заполнени€
	//cout << delimiter << endl;
	cout << tree.findIdWithValue(62) << endl;
	cout << "ћинимальное  значение бинарного дерева: " << tree.findMin() << endl;
	cout << "ћаксимальное значение бинарного дерева: " << tree.findMax() << endl;
	cout << delimiter << endl;
	const int n = 77;
	int arr2[n]{};
	fillArr(n, arr2);
	showArr(n, arr2);
	cout << delimiter << endl;
	tree.addArr(n, arr2);
	cout << endl;
	tree.display(); // дерево после заполнени€
	cout << endl;
	cout << delimiter << endl;
	cout << "ћинимальное  значение бинарного дерева: " << tree.findMin() << endl;
	cout << "ћаксимальное значение бинарного дерева: " << tree.findMax() << endl;

	return 0;
}
