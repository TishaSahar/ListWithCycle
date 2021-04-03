#include "List.h"

List::List(const List& _p) {							//Конструктор копирования
	Node* node = new Node(_p.first->value, _p.first->next);
	tail = first = new Node(_p.first->value, _p.first->next);
	count = 1;
	node = node->next;
	while (node != NULL) {
		this->addV(node->value);
		count++;
		node = node->next;
	}
}

void List::addV(int _v) {								//Добавление монома в конец полинома
	Node* node = new Node(_v, NULL);

	if (this->first == NULL)
		this->first = node;
	else
		this->tail->next = node;
	this->tail = node;
	count++;
}

void List::addN(Node *_n) {
	if (this->first == NULL)
		this->first = _n;
	else
		this->tail->next = _n;
	this->tail = _n;
	count++;
}

void List::Print() {
	if (this->count == 0)
	{
		cout << "List is empty" << endl;
		return;
	}

	Node* node = this->first;
	cout << "List { ";
	while (node != NULL) {
		if (node->next == NULL) {
			cout << node->value << " }\n";
			system("pause");
			return;
		}
		cout << node->value << ", ";
		node = node->next;
	}
	return;
}