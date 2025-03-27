#include <iostream>
using namespace std;


// node struct
struct Node {
	int data = 0;
	Node* next = nullptr;
};


// find middle node
void deleteMiddleNode(Node* head)
{

}


// insert node
void insertNode(Node* head, int data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = head;
	head = newNode;
}


// print list
void printList(Node* head)
{
	while (head)
	{
		cout << head->data << "---->";
		head = head->next;
	}

	cout << "nullptr" << endl;
}


int main()
{


	return 0;
}