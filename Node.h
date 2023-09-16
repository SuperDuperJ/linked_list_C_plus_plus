#pragma once

#include <iostream>

using namespace std;

class Node
{
public:

	//Constructors
	Node();
	Node(void* data); 
	//Getters
	void* getData(); 
	Node* getNext();
	//Setters
	void setData(void* data);
	void setNext(Node* next);
	void setDisplay(void(*display)(void* arg));
	//Display
	void display();
	//Destructor
	~Node();

private:

	void* m_data;
	Node* m_next;
	void(*m_display)(void* arg);
	//void(*)(void* arg) m_display;

};