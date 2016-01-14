/*
 * testcircularLinkedList.cpp
 *
 *  Created on: Mar 6, 2014
 *      Author: Ramya Ananth
 */
#include <iostream>
#include <stdio.h>
#include "circularLinkedList.h"

int main()
{
	circularLinkedList<int> list1, list2, list3;
	int num;
	cout<<"***Circular Linked List by Ramya Ananth***"<<endl;
	cout << " Enter numbers ending with  -999"<< endl;
	cin >> num;
	while (num != -999)
	{
		list1.insertNode(num);
		cin >> num;
	}
	cout << endl;
	cout << "Contents of List1: ";
	list1.print();
	cout<<"Length of List1 = "<<list1.length()<<endl;
	cout<<"Is List1 empty : "<<list1.isEmptyList()<<endl;
	cout<<"First element in list : "<<list1.front()<<endl;
	cout<<"Last element in list : "<<list1.back()<<endl;
	cout<<"Contents of List2 after Inserting elements 4 7 8 :"<<endl;
	list2.insertNode(4);
	list2.insertNode(7);
	list2.insertNode(8);
	list2.print();

	cout<<"Assignment overloading (list1 = list2): "<<endl;

	list1 = list2;
	cout<<"Contents of List1 after assignment overloading : "<<endl;
	list1.print();
	cout << "Enter the number to be deleted: ";
	cin >> num;
	list2.deleteNode(num);
	cout << "Contents of List2 After deleting "<< num << " : " << endl;
	list2.print();
	cout << endl;
	cout<<"Length of List2 = "<<list2.length()<<endl;
	cout<<"Is List1 empty : "<<list2.isEmptyList()<<endl;
	cout<<"First element in list : "<<list2.front()<<endl;
	cout<<"Last element in list : "<<list2.back()<<endl;

	cout<<"Search for element 7 in list2 : "<<endl;
	cout<<"Number present(1)/Absent(0):"<<list2.search(2);


	return 0;

}

