#include <iostream>
#include <unordered_map>
#include <random>
using namespace std;

// remove duplicates from an unsorted linked list

// create a simple node
struct Node {
	int data = 0;
	Node* next = nullptr;
};

// insert function
void insert(Node*& head, int data)
{
	Node* newNode = new Node;	// create a new node
	newNode->data = data;	// set its data
	newNode->next = head;	// set the head as the next of the newly created node
	head = newNode;		// set the new node as the head
}

//print function
void printList(Node* head)
{
	while (head)
	{
		cout << head->data << "--->";
		head = head->next;
	}
	cout << "nullptr" << endl;
}

// medthod one
void removeDuplicates1(Node* head)
{
	// make sure the head and it's next node are not null
	if (head == nullptr || (head && head->next == nullptr))
	{
		return;
	}

	// iterate through the linked list
	// create a current node and set it as the head
	Node* curr = head;
	while (curr)
	{
		// create a runner node and set it as the current node that'll look ahead
		Node* runner = curr;
		while (runner->next != nullptr)
		{
			// if the current node's data and the next node's data are the same, set the runner to the next->next node
			if (runner->next->data == curr->data)
			{
				runner->next = runner->next->next;
			}
			else
			{
				runner = runner->next;
			}
		}
		curr = curr->next;
	}
}

/// <summary>
/// Removed duplicates using a hash table
/// </summary>
/// <param name="head"></param>
void removeDuplicates2(Node* head)
{
	// first check that the head and its next node are not null
	if (head == nullptr || (head && head->next == nullptr))
	{
		return;
	}

	// create a hash table
	unordered_map<int, int> nodeMap;
	Node* prev = head;
	Node* curr = head->next;
	nodeMap[head->data] = 1;
	while (curr != nullptr)
	{
		while (curr && nodeMap.find(curr->data) != nodeMap.end())
		{
			curr = curr->next;
		}
		prev->next = curr;
		prev = curr;
		if (curr)
		{
			nodeMap[curr->data] = 1;
			curr = curr->next;
		}
	}
}

/// <summary>
/// Generate a random integer between min and max
/// </summary>
/// <param name="min"></param>
/// <param name="max"></param>
/// <returns></returns>
static inline int random_range(const int min, const int max)
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> distribution(min, max);
	return distribution(mt);
}


int main()
{
	cout << "Method 1 \n";
	Node* head = nullptr;
	for (int i = 0; i < 10; i++)
	{
		insert(head, random_range(1, 7));
	}
	printList(head);
	removeDuplicates1(head);
	printList(head);

	cout << "Method 2: \n";
	Node* head1 = nullptr;
	for (int i = 0; i < 10; i++)
	{
		insert(head1, random_range(1, 7));
	}
	printList(head1);
	removeDuplicates2(head1);
	printList(head1);

	return 0;
}
