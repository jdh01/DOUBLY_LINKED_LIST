#include <iostream>

struct Node {
	int data;
	Node* next;
	Node* prev;
};

Node* GetNewNode(int data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
};

Node* InsertAtHead(Node** headPtr, int data)
{
	Node* temp = *headPtr;
	Node* newNode = GetNewNode(data);
	if (temp == NULL)
	{
		temp = newNode;
		*headPtr = temp;
		return *headPtr;
	}
	temp->prev = newNode;
	newNode->next = temp;
	temp = newNode;
	*headPtr = temp;
	return *headPtr;
}

void InsertAtTail(Node** headPtr, int data)
{
	Node* temp = *headPtr;
	Node* newNode = GetNewNode(data);
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
	newNode->next = NULL;
}

void Print(Node* headPtr)
{
	Node* temp = headPtr;
	while (temp != NULL)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << "\n";
}

void ReversePrint(Node* headPtr)
{
	Node* temp = headPtr;
	if (temp == NULL) return;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	while (temp != NULL) {
		std::cout << temp->data << " ";
		temp = temp->prev;
	}
}

int main() {
	Node* headPtr = NULL;
	InsertAtHead(&headPtr, 2);
	InsertAtHead(&headPtr, 1);
	Print(headPtr);
	InsertAtTail(&headPtr, 3);
	Print(headPtr);
	ReversePrint(headPtr);
}