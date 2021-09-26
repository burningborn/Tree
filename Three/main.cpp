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

#define HOME_WORK

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

#ifdef HOME_WORK
	BinaryTree tree = feelTree();//дерево заполненное статическим массивом
	cout << delimiter << endl;
	const int n = 3;//размер массива
	int arr[n]{}; //добавляемый массив
	fillArr(n, arr);//функция заполнения массива уникальными (не повторяющимися) значениями
	showArr(n, arr);//вывод массива на экран
	cout << delimiter << endl;
	tree.addArr(n, arr);//функция добавления массива к дереву
	cout << endl;
	tree.display(); // дерево после заполнения
	cout << endl;
	cout << delimiter << endl;
	cout << "Минимальное  значение бинарного дерева: " << tree.findMin() << endl;
	cout << "Максимальное значение бинарного дерева: " << tree.findMax() << endl;
#endif // HOME_WORK

}
