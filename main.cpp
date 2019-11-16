/*
 * main.cpp
 *
 *  Created on: 5 nov 2019
 *      Author: Alessandro
 */


#include <iostream>
#include "List.h"

using namespace std;


int main(void){
	List<int> newlist;
	newlist.insertSet(1);
	newlist.insertSet(3);
	newlist.insertSet(3);
	newlist.printList();
}
