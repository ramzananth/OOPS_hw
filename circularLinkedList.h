#ifndef H_circularLinkedList
#define H_circularLinkedList

#include <iostream>
#include <stdio.h>
#include <assert.h>
using namespace std;

template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type> *link;
};

// ordered circular linked list
// duplicated values are allowed
template <class Type>
class circularLinkedList
{
public:
	const circularLinkedList<Type>& operator=(const circularLinkedList<Type>&);
		//Overloads the assignment operator.

	void initializeList();
 		//Initializes the list to an empty state.
		//Postcondition: tail = NULL, count = 0

	bool isEmptyList() const;
 		//Function to determine whether the list is empty.
		//Postcondition: Returns true if the list is empty; otherwise, returns false.

	void print() const;
		//Function to output the data contained in each node.

	int length() const;
		//Function to return the number of nodes in the list.
		//Postcondition: The value of count is returned.

	void destroyList();
 		//Function to delete all the nodes from the list.
  		//Postcondition: tail = NULL, count = 0

	Type front() const;
 		//Function to return the first element of the list.
 		//Precondition: The list must exist and must not be empty.
  		//Postcondition: If the list is empty, then the program terminates; otherwise,
		//			   the first element of the list is returned.

	Type back() const;
		//Function to return the last element of the list.
		//Precondition: The list must exist and must not be empty.
		//Postcondition: If the list is empty, then the program terminates; otherwise,
		//			   the last element of the list is returned.

	nodeType<Type>* getTail() const
	{
		return tail;
	}

	bool search(const Type& searchItem) const;
		//Function to determine whether searchItem is in the list.
		//Postcondition: Returns true if searchItem is found in the list; otherwise, it returns false.

	void insertNode(const Type& newitem);
		//Function to insert newitem to the list.
		//Postcondition: tail points to the last node of the new list, newitem is inserted at the
		//				 proper place in the list, and count is incremented by 1.

	void deleteNode(const Type& deleteItem);
  		//Function to delete deleteItem from the list.
 		//Postcondition: If found, the node containing deleteItem is deleted from the
		//			   list, tail points to the last node, and count is decremented by 1.

	circularLinkedList();
   		//Default constructor
 		//Initializes the list to an empty state.
 		//Postcondition: tail = NULL, count = 0

	circularLinkedList(const circularLinkedList<Type>& otherList);
		 //Copy constructor

	~circularLinkedList();
		//Destructor
   		//Deletes all the nodes from the list.
		//Postcondition: The list object is destroyed.

protected:
	int count;		//variable to store the number of elements in the list
	nodeType<Type> *tail; //pointer to the last node of the list, see textbok p.326
private:
	void copyList(const circularLinkedList<Type>& otherList)
	{
		destroyList();
        count = 0;
        //cout<<"re-inserting elements"<<endl;
        nodeType<Type>* temp = otherList.getTail()->link;
        while (count < otherList.length())
        {
        	//cout<<"inserting "<<(int)temp->info<<endl;
        	insertNode(temp->info);
        	count++;
        	temp = temp->link;
        }

	}
		//Function to make a copy of otherList.
		//Postcondition: A copy of otherList is created and assigned to this list.
};

template <class Type>
void circularLinkedList<Type>::destroyList()
{
	nodeType<Type> *temp;
	nodeType<Type> *current;

	if (count == 1)
	{
		delete tail;
		tail = NULL;
		count = 0;
	}
	else{
		current = tail->link;
		tail->link = NULL;

		while(current != NULL)
		{
			temp = current;
			current = current->link;
			delete temp;
		}
		count = 0;
	}
	tail = NULL;
}

template <class Type>
void circularLinkedList<Type>::print() const
{
	nodeType<Type> *temp;
	temp = tail->link;
	int cnt = 0;
	while(cnt < count)
	{
		cnt++;
		//cout<<"contents of list:"<<endl;
		cout<<temp->info<<" ";
		temp = temp->link;
	}
	cout<<endl;
}

template <class Type>
circularLinkedList<Type>::circularLinkedList()
{
	count = 0;
	tail = NULL;
}

template <class Type>
circularLinkedList<Type>::~circularLinkedList()
{
	destroyList();
}

template <class Type>
void circularLinkedList<Type>::initializeList()
{
	destroyList();
}

template <class Type>
bool circularLinkedList<Type>::isEmptyList() const
{
	return(tail == NULL);
}

template <class Type>
int circularLinkedList<Type>::length() const
{
	return count;
}


template <class Type>
void circularLinkedList<Type>::insertNode(const Type& newItem)
{
	nodeType<Type> *current;
	nodeType<Type> *prev;
	nodeType<Type> *newNode;
	bool found;
	newNode = new nodeType<Type>;
	newNode->info = newItem;
	newNode->link = NULL;
	//cout<<"inserting elements"<<endl;

	if (tail == NULL)  //Case 1 - Empty list
	{
		tail = newNode;
		tail->link = tail;
		count++;
		//cout<<"empty list case"<<endl;
	}
	else //Case 2 - Non-empty list
	{

		if (tail->info < newNode->info)
		{
			newNode->link = tail->link;
			tail->link = newNode;
			tail = newNode;
			count++;
		}
		else
		{
			current = tail->link;
			prev = tail;
			found = false;
			while (current != tail && !found)
			{
				if(current->info >= newItem)
				{
					found = true;
					break;
				}
				else
				{
					prev = current;
					current = current->link;
				}
			}
			if (found)
			{
				tail->link = newNode;
				newNode->link = prev;
				count++;
			}
		}
	}
}

template <class Type>
Type circularLinkedList<Type>::front() const
{
	 assert(tail != NULL);
	 return tail->link->info;
}


template <class Type>
Type circularLinkedList<Type>::back() const
{
	 assert(tail != NULL);
	 return tail->info;
}


template <class Type>
void circularLinkedList<Type>::deleteNode(const Type& deleteItem)
{
	nodeType<Type> *current; //pointer to traverse the list
	nodeType<Type> *trailCurrent; //pointer just before current
	bool found;

	if (tail == NULL) //Case 1
		cout << "Cannot delete from an empty list." << endl;
	else
	{
		current = tail->link;
		found = false;
		while (current != NULL && !found) //search the list
		{
			if (current->info >= deleteItem)
			{
				found = true;
			}
			else
			{
				trailCurrent = current;
				current = current->link;
			}
		}
		if (current == NULL) //Case 4
		{
			cout << "The item to be deleted is not in the list.";
		}
		else
			if (current->info == deleteItem)
			{
				if (tail->link == current)
				{
					tail->link = tail->link->link;
					if (tail->link == NULL)
					{
						tail = NULL;
					}
					delete current;
				}
				else
				{
					trailCurrent->link = current->link;
					if (current == tail)
					{
						tail = trailCurrent;
					}
					delete current;
				}
				count--;
			}
			else
				cout << "The item to be deleted is not in the list"<<endl;
	}
}

template <class Type>
bool circularLinkedList<Type>::search(const Type& searchItem) const
{
	bool found = false;
	nodeType<Type> *current; //pointer to traverse the list
	current = tail->link; //start the search at the first node
	while (current != tail && !found)
	{
		if (current->info >= searchItem)
		{
			found = true;
		}
		else
		{
			current = current->link;
		}
		if(current == tail)
		{
			found = true;
		}
		if (found)
		{
			found = (current->info == searchItem); //test for equality
		}
	}
	return found;
}

template <class Type>
const circularLinkedList<Type>& circularLinkedList<Type>::operator=(const circularLinkedList<Type>& otherList)
{
	if(this != &otherList)
	{
		copyList(otherList);
	}
	else
	{
		return *this;
	}
}


#endif
