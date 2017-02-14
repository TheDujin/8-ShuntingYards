/*
 * Node.cpp
 *
 *  Created on: Feb 14, 2017
 *      Author: Kevin Jin
 */

#include <iostream>
#include "Node.h"
using namespace std;


Node::Node(char newData) {
  data = newData;
  next = NULL;
}

Node* Node::getNext() {
  return next;
}

char Node::getData() {
  return data;
}

void Node::setNext(Node* newNext) {
  next = newNext;
}

Node::~Node() {
  delete data;
  next = NULL;
}


