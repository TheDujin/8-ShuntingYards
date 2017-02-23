/*
 * ShuntingYard.cpp
 *
 *  Created on: Feb 14, 2017
 *      Author: Kevin Jin
 */

#include <iostream>
#include "Node.h"
#include <string.h>
#include <stdio.h>
using namespace std;
void push(Node* newNode, Node* & bottom);
Node* pop(Node* & bottom);
Node* peek(Node* & bottom);
int main() {
	char* input = new char[101];
	Node* head = NULL;

	cout << "Please input the infix expression with spaces between each token." << endl << "Input: ";
	cin.get(input, 100);
	cin.ignore();
	int counter = 0;
	char* output = new char[101];
	bool invalid = false;
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] - '0' >= 0 && input[i] - '0' <= 9) {
			output[counter] = input[i];
			counter++;
		}
		else if (input[i] == '+' || input[i] == '-') {
			while (peek(head) != NULL && (peek(head)->getData() == '^' || peek(head)->getData() == '*' || peek(head)->getData() == '/'
					|| peek(head)->getData() == '+' || peek(head)->getData() == '-')) {
							output[counter] = pop(head)->getData();
							counter++;
						}
						push(new Node(input[i]), head);
		}
		else if (input[i] == '*' || input[i] == '/') {
			while (peek(head) != NULL && (peek(head)->getData() == '^' || peek(head)->getData() == '*' || peek(head)->getData() == '/')) {
				output[counter] = pop(head)->getData();
				counter++;
			}
			push(new Node(input[i]), head);
		}
		else if (input[i] == '^') {
			push(new Node('^'), head);
		}
		else if (input[i] == '(') {
			push(new Node('('), head);
		}
		else if (input[i] == ')') {
			while (peek(head)->getData() != '(') {
				output[counter] = pop(head)->getData();
				counter++;
			}
			pop(head);
		}
		else if (input[i] != '\0' && input[i] != '\r' && input[i] != ' '){
			cout << "Invalid input" << endl;
			invalid = true;
			i = strlen(input);
		}

	}
	if (!invalid) {
		while (peek(head) != NULL) {
			output[counter] = pop(head)->getData();
			counter++;
		}
		cout << output << endl;
	}
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
			temp = current->getNext();
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
