/*
 * ShuntingYard.cpp
 *
 *  Created on: Feb 14, 2017
 *      Author: Kevin Jin
 */

#include <iostream>
#include "Node.h"
using namespace std;
void push(Node* newNode, Node* & bottom);
Node* pop(Node* & bottom);
Node* peek(Node* & bottom);
int main() {
	Node* head = NULL;
	push(new Node('a'), head);

	push(new Node('b'), head);
	push(new Node('c'), head);
	Node* current = head;
	while (current->getNext() != NULL) {
		cout << current->getData() << endl;
		current = current->getNext();
	}
	cout << current->getData() << endl;

  return 0;
}

void push(Node* newNode, Node* & bottom) {
	if (peek(bottom) != NULL)
		peek(bottom)->setNext(newNode);
	else
		bottom = newNode;
}

Node* pop(Node* & bottom) {
	Node* current = bottom;
	Node* temp = NULL;
	if (current != NULL) {
		if (current->getNext() != NULL) {
			while (current->getNext()->getNext() != NULL)
				current = current->getNext();
			Node* temp = current->getNext();
			current->setNext(NULL);
		}
		else {
			temp = bottom;
			bottom = NULL;
		}
	}
	return temp;
}

Node* peek(Node* & bottom) {
	Node* current = bottom;
		if (current != NULL) {
			while (current->getNext() != NULL)
				current = current->getNext();
			return current;
		}
		else
			return NULL;
}
