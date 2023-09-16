
#include "Node.h"

//Constructors
Node::Node()
{
	m_data = 0;
	m_next = nullptr;
	m_display = nullptr;
}
Node::Node(void* data)
{
	m_data = data;
	m_next = nullptr;
	m_display = nullptr;
}
//Getters
void* Node::getData()
{
	return m_data;
}
Node* Node::getNext()
{
	return m_next;
}
//Setters
void Node::setData(void* data)
{
	m_data = data;
}
void Node::setNext(Node* next)
{
	m_next = next;
}
void Node::setDisplay(void(*display)(void* arg))
{
	m_display = display;
}
//Display
void Node::display()
{
	m_display(m_data);
	//cout << "->";
}

//Destructor
Node::~Node()
{}

