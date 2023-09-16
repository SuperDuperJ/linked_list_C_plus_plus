#pragma once

#include <iostream>
#include "Node.h"
//#include <string>

using namespace std;

class LinkedList
{
public:
	//Constructor
	LinkedList();
	//Prepend
	void prepend(void* data);
	//Purge
	void purge();
	//Destructor
	~LinkedList();
	//Delete
	//void deleteNode(void* key); 
	//Insert
	void insert(void* data, int(*compare)(void* arg1, void* arg2));
	//Display
	void display();
	//SetDisplay
	void setDisplay(void(*display)(void* arg));

private:
	Node* m_head;

};