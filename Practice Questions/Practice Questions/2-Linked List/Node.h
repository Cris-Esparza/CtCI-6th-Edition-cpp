#include <iostream>
using namespace std;

#ifndef NODE_H
#define NODE_H

class Node
{
private:
	int n_data;	// node's data
	Node* n_next;	// next in list

public:
	// Constructors
	NewNode(void);
	NewNode(int data);
	NewNode(int data, Node* next);

	// Getters
	int getData() const;
	Node* getNext() const;

	// Setters
	void setData(int data);
	void setNext(Node* next);
};

#endif 

