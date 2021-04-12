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
	int i = count;
	Node* node = this->first;
	cout << "List { ";
	while ((node != NULL)&&(i > 0)) {
		if (node->next == NULL) {
			cout << node->value << " }\n";
			system("pause");
			return;
		}
		cout << node->value << ", ";
		node = node->next;
		i--;
	}
	return;
}

bool List::isCircle() {
	if (this->count == 0)
	{
		throw logic_error("List is empty");
	}
	Node* node1 = this->first;
	Node* node2 = this->first->next;
	while (node1 != NULL) {
		if ((node1->next == NULL)||(node2->next == NULL)) return false;
		if (node2->next->next == NULL) return false;
		if (node1 == node2) return true;
		node1 = node1->next;
		node2 = node2->next->next;
	}
}