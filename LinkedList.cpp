
#include "LinkedList.h"

//Constructor
LinkedList::LinkedList()
{
	m_head = nullptr;
}
//Prepend
void LinkedList::prepend(void* data)
{
	Node* temp = nullptr;
	//Allocate new node
	temp = new Node(data);
	//Call new node's setNext method passing head
	temp->setNext(m_head);
	//Assign new node to head
	m_head = temp;
}
//Insert
void LinkedList::insert(void* data, int(*compare)(void* arg1, void* arg2))
{	
	Node* travel = m_head;
	Node* trail = nullptr;

	//Allocate new node
	Node* temp = new Node(data);

	//Temp goes at front of list
	if (m_head == nullptr || compare(temp->getData(), m_head->getData())<=0)
	{
		temp->setNext(m_head);
		m_head = temp;
	}
	else //Temp goes in middle of list
	{
		//Move travel to node "after" temp
		while (travel != nullptr && compare(travel->getData(), temp->getData()) < 0)
		{
			trail = travel;
			travel = travel->getNext();
		}
		trail->setNext(temp);
		temp->setNext(travel);
	}



}
//Purge
void LinkedList::purge()
{
	Node* trail = nullptr;

	while (m_head != nullptr)
	{
		//Reassign trail to head
		trail = m_head;
		//Move head to next
		m_head = m_head->getNext();
		//Delete node trail pointing to
		delete trail;

	}
}
//Destructor
LinkedList::~LinkedList()
{
	purge();
}
//Delete
/*
void LinkedList::deleteNode(void* key) 
{
	Node* travel = m_head;
	Node* trail = nullptr;

	//Check to see if list is not empty
	if (m_head != nullptr)
	{
		if (m_head->getData() == key) //*key here?
		{
			m_head = m_head->getNext();
			delete travel;
		}
		else
		{
			//Move travel to node we want to delete
			while (travel->getNext() != nullptr && travel->getData() != key) //*key here?
			{
				trail = travel;
				travel = travel->getNext();
			}

			if (travel != nullptr)
			{
				trail->setNext(travel->getNext());
				delete travel;
			}
		}
	}


}
*/

void LinkedList::setDisplay(void(*display)(void* arg))
{
	Node* travel = m_head;
	while (travel != nullptr)
	{
		travel->setDisplay(display);
		travel = travel->getNext();
	}
}

void LinkedList::display()
{
	Node* travel = m_head;
	while (travel != nullptr)
	{
		//Display current node contents
		travel->display();
		//Move travel to next node
		travel = travel->getNext();
	}
	cout << "\n\n";
}
