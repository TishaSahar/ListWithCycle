#pragma once

#include <iostream>

using namespace std;

class Node					// Node 
{
public:
	int value;
	Node* next;
	Node(int _value = 0, Node* _next = NULL) {
		value = _value;
		next = _next;
	}

	Node operator = (const Node& N) {
		value = N.value;
		next = N.next;
	}
};

class List {				//Список
	Node* first;
	Node* tail;

public:
	int count;
	List(Node* _first = NULL, Node* _tail = NULL) :first(_first), tail(_tail) { 
		count = 2;
		if (tail == NULL) count--;
		if (first == NULL) count --;
	}
	~List() { first = NULL; }
	List(const List& _p);

	void addV(int _v);
	void addN(Node *_n);

	bool isCircle();

	void Print();
};