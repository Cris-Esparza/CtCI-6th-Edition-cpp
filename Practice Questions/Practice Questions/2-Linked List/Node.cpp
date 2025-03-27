#include "Node.h"

// Constructors
Node::NewNode(void)
{
	n_data = 0;
	n_next = nullptr;
}

Node::NewNode(int data)
{
	n_data = data;
}

Node::NewNode(int data, Node* next)
{
	n_data = data;
	n_next = next;
}

// Getters
int Node::getData() const
{
	return n_data;
}

Node* Node::getNext() const
{
	return n_next;
}

// Setters
void Node::setData(int data)
{
	n_data = data;
}

void Node::setNext(Node* next)
{
	n_next = next;
}
