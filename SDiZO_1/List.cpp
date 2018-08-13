#include "stdafx.h"
#include "List.h"


List::List()
{
	head = NULL;
}


List::~List()
{
	while (head != NULL) {
		Element *e = head->next;
		delete head;
		head = e;
	}
}

void List::AddFr(int value) {
	Element *e = new Element;
	e->data = value;
	e->prev = NULL;
	if (head != NULL) head->prev = e;
	e->next = head;
	head = e;
}

bool List::Search(int value)
{
	Element *e = head;
	while (e != NULL) {
		if (e->data == value) { return true; }
		e = e->next;
	}
	return false;
}

void List::Add(int value1, int value2) {
	bool changed = false;
	if (head != NULL) {
		Element *point = head;
		if (point->data == value1) { point->data = value2; changed = true; }

		while (point->next != NULL) {
			if (point->data == value1) { point->data = value2; changed = true; std::cout << "Wartosc zamieniona.\n"; }
				point = point->next;
			}

		if (!changed) { AddFr(value2); std::cout << "Wartosc dodana na przod.\n"; }
	}
	else { AddFr(value2); std::cout << "Wartosc dodana na przod.\n"; }
}

void List::RmFr() {
	Element *e = head->next;
	delete head;
	head = e;
}

void List::RmBck(Element *&point) {
	Element *buff = point;
	Element *e = point->prev;
	e->next = NULL;
	point = NULL;
	buff->prev = NULL;
	delete buff;
}

void List::RmMid(Element *&point) {
	Element *e = point->next;
	Element *e2 = point->prev;
	Element *buf = point;
	e2->next = e;
	e->prev = e2;
	point = e;
	delete buf;
}

void List::Remove(int value) {
	if (head != NULL) {
		Element *buff;
		Element *point = head;
		bool removed = false;
		while (this->Search(value)) {
			do {
				if (point->data == value) {
					if (point == head) {
						RmFr();
						point = head;
						std::cout << "Wartosc usunieta\n";
						removed = true;
					}
					else {
						if (point->next == NULL) {
							RmBck(point);
							std::cout << "Wartosc usunieta\n";
							removed = true;
						}
						else {
							RmMid(point);
							std::cout << "Wartosc usunieta\n";
							removed = true;
						}
					}
				} if (point != NULL) {
					buff = point->next;
					point = buff;
				}
			} while (point != NULL);
			point = head;
		}
		if (!removed) std::cout << "Nie znaleziono wartosci\n";
	}
}


void List::Display() {
	Element *e = head;
	while (e != NULL) {
	std::cout << e->data << "|";
		e = e->next;
	}
}

