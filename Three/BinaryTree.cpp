#include "BinaryTree.h"

BinaryTree::Node::Node(int id, int value, Node* left, Node* right)
{
	this->id = id;
	this->value = value;
	this->left = left;
	this->right = right;
}

void BinaryTree::Node::addNode(int id, int value)
{
	if (value >= this->value) {//�� ��������� ���� ������
		if (right == nullptr)
			right = new Node(id, value);
		else
			right->addNode(id, value);
	}
	else {//��������� ���� �����
		if (left == nullptr)
			left = new Node(id, value);
		else
			left->addNode(id, value);
	}
}

// ����� �������������� ���� � ��������� ���������	
	int BinaryTree::Node::findIdWithValue(int value)
{
	//��� 1 <=> � <=> ������
	if (this->value == value)
		return id;

	//��� 2 <=> � <=> ����� (���������� ����� ���������)
	int next_id;
	if (left != nullptr) {
		next_id = left->findIdWithValue(value);
		if (next_id != -1)
			return next_id;
	}
	else
		next_id = -1;

	// ��� 3 <=> � <=> ������ (���������� ������ ���������)
	if (right != nullptr) {
		next_id = right->findIdWithValue(value);
		if (next_id != -1)
			return next_id;
	}
	else
		next_id = -1;	
	return next_id;
}

	int BinaryTree::Node::findMin()
	{
		if (this->left == nullptr)
			return this->value;
			this->left->findMin();
	}

	int BinaryTree::Node::findMax()
	{
		if (this->right == nullptr)
			return this->value;
		this->right->findMax();
	}

void BinaryTree::Node::display(int level)
{
	// ����� ����, ������������� ������
	for (int i = 0; i < level; i++)
		cout << '\t';
	cout << "(id = " << id << ", value = " << value << endl;

	// ����� ������� ���������
	if (right != nullptr)
		right->display(level + 1);
	else {
		for (int i = 0; i < level; i++)
			cout << '\t';
		cout << "(nullptr)" << endl;
	}

	// ����� ������ ���������
	if (left != nullptr)
		left->display(level + 1);
	else {
		for (int i = 0; i < level; i++)
			cout << '\t';
		cout << "(nullptr)" << endl;
	}

	// ������������� ������
	for (int i = 0; i < level; i++)
		cout << '\t';
	cout << ")" << endl;
}

	BinaryTree::BinaryTree()
	{
		root = nullptr;
		nodeCount = 0;
	}

	void BinaryTree::addNode(int value)
	{
		if (root == nullptr)
			root = new Node(nodeCount++, value);
		else
			root->addNode(nodeCount++, value);
	}

	int BinaryTree::findIdWithValue(int value)
	{
		if (root == nullptr)
			return -1;
		return root->findIdWithValue(value);
	}

	void BinaryTree::addArr(int n, int *arr)
	{
		if (root == nullptr) {

			root = new Node(nodeCount++, arr[0]);
		for (int i = 1; i < n; i++)
			root->addNode(nodeCount++, arr[i]);
		}
		else			
		for (int i = 0; i < n; i++)	
			root->addNode(nodeCount++, arr[i]);
	}

	int BinaryTree::findMin()
	{
		return root->findMin();
	}

	int BinaryTree::findMax()
	{
		return root->findMax();
	}

	void BinaryTree::display()
	{
		if (root == nullptr)
			cout << "empty tree" << endl;
		else
			root->display(0);
	}