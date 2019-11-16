/*
 * Node.h
 *
 *  Created on: 5 nov 2019
 *      Author: Alessandro
 */

#ifndef SRC_NODE_H_
#define SRC_NODE_H_

#include <iostream>

using namespace std;


template <typename T>
class List;

template<typename T>
class Node {
	friend class List<T> ;
private:
	T data;
	Node<T> *next;
	Node<T>* prec;

public:
	Node(T dataIn);
	~Node();
	T getData();
	void setNext(Node<T> *p);
	void setPrev(Node<T>* p);
	Node<T>* getNext();
	Node<T>* getPrev();

};

template<typename T>
Node<T>::Node(T dataIn) {
	this->data = dataIn;
	this->next = NULL;
	this->prec=NULL;
}

template<typename T>
Node<T>::~Node() {

}

template<typename T>
T Node<T>::getData() {
	return data;
}

template<typename T>
void Node<T>::setNext(Node<T> *p) {
	next = p;
}
template<typename T>
Node<T>* Node<T>::getNext() {
	return next;
}

template <typename T>
Node<T>* Node<T>:: getPrev(){
	return prec;
}


template <typename T>
void Node<T>:: setPrev(Node<T>* p){
	prec=p;
}
#endif /* SRC_NODE_H_ */
