/*
 * List.h
 *
 *  Created on: 5 nov 2019
 *      Author: Alessandro
 */

#ifndef SRC_LIST_H_
#define SRC_LIST_H_

#include <iostream>

#include "node.h"
using namespace std;

template<typename T>
class List {
private:
	Node<T> *start;
	Node<T> *end;
	void insertNode(T dataIN);
	void insertSort(T dataIN);
public:
	List();
	~List();
	bool isEmpty();
	bool isEnd(Node<T> *ptr);
	void insertSet(T dataIN);
	bool isInSet(T dataIN);
	void printList();
	Node<T>* getStart();
	Node<T>* searchKey(T value);
	void removeNode(T data);

};

template<typename T>
List<T>::List() {
	this->start = NULL;
	this->end = NULL;
}

template<typename T>
List<T>::~List() {

}

template<typename T>
bool List<T>::isEmpty() {
	bool flag = 0;
	if (start == NULL && end == NULL) {
		flag = 1;
	}
	return flag;
}

template<typename T>
bool List<T>::isEnd(Node<T> *ptr) {
	return ptr == end;
}

template<typename T>
Node<T>* List<T>::getStart() {
	return start;
}

template<typename T>
void List<T>::insertNode(T dataIN) {
	if (isEmpty()) {
		Node<T> *newPtr = new Node<T>(dataIN);
		start = newPtr;
		end = newPtr;
		newPtr->setPrev(start);
		newPtr->setNext(end);

	} else {
		Node<T> *ptr = new Node<T>(dataIN);
		ptr->setPrev(end);
		end->setNext(ptr);
		end = ptr;
		end->setNext(NULL);

	}
}

template<typename T>
void List<T>::insertSort(T dataIN) {
	if (isEmpty()) {
		insertNode(dataIN);
	} else {
		Node<T> *ptr = new Node<T>(dataIN);
		Node<T> *iter = start;
		while (iter != NULL) {
			if (iter == start && iter->getData() > dataIN) {
				ptr->setNext(start);
				start->setPrev(ptr);
				start = ptr;
			} else if (iter == end && iter->getData() < dataIN) {
				end->setNext(ptr);
				ptr->setPrev(end);
				end = ptr;

			} else if (iter->getData() > dataIN) {
				ptr->setNext(iter);
				ptr->setPrev(iter->getPrev());
				Node<T> *prev = iter->getPrev();
				iter->setPrev(ptr);
				prev->setNext(ptr);

			} else {
				iter = iter->getNext();
			}
		}
	}
}

template<typename T>
void List<T>::printList() {
	if (isEmpty() == true) {
		cout << "Error! Empty list!" << endl;
	} else {
		Node<T> *current;
		current = start;
		cout << "[";
		while (current != end) {
			cout << current->getData() << ",";
			current = current->getNext();
		}
		current = end;
		cout << current->getData() << "]" << endl;
	}
}

template<typename T>
Node<T>* List<T>::searchKey(T dataIN) {
	Node<T> *result;
	if (isEmpty()) {
		cout << "ERROR! empty list!" << endl;

	} else {
		bool found = false;
		Node<T> *ptr = start;
		while (ptr != NULL && found == false) {
			if (ptr->getData() == dataIN) {
				found = true;
				result = ptr;
			} else {
				ptr = ptr->getNext();

			}
		}

	}
	return result;
}

template<typename T>
bool List<T>::isInSet(T dataIN) {
	Node<T> *ptr = getStart();
	bool found = false;
	while (isEnd(ptr) == false) {
		if (ptr->getData() == dataIN) {
			found = true;
		} else {
			ptr = ptr->getNext();
		}
	}
	if (ptr->getData() == dataIN) {
		found = true;
	}

	return found;
}

template<typename T>
void List<T>::insertSet(T dataIN) {
	if (isEmpty() == true) {
		insertNode(dataIN);
	} else {
		if (isInSet(dataIN) == false) {
			insertNode(dataIN);
		}
	}

}

template<typename T>
void List<T>::removeNode(T value) {
	Node<T> *ptr = searchKey(value);
	if (ptr != NULL) {
		if (ptr == end) {
			end = ptr->getPrev();
			ptr->~Node();
		} else if (ptr == start) {
			start = ptr->getNext();
			ptr->~Node();
		} else {
			Node<T> *ptr2 = ptr->getPrev();
			Node<T> *ptr3 = ptr->getNext();
			ptr2->setNext(ptr3);
			ptr3->setPrev(ptr2);
			ptr->~Node();
		}
	}

}

#endif /* SRC_LIST_H_ */
