#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "YZString.h"
#include "DblLinkedList.h"
using namespace std;
int YZString::countObject = 0;
int YZString::deleteObject = 0;
istream & operator>>(istream & istr, YZString & mstr);
ostream & operator<<(ostream& ostr, const YZString & mstr);
void changer(DblLinkedList list);
int main()
{
	DblLinkedList list1, list2, modList1, modList2;
	YZString inputString, inputStringT;
	ifstream input1, input2; ofstream output1, output2;
	input1.open("infile1.txt");
	input2.open("infile2.txt");
	output1.open("outfile1.txt");
	output2.open("outfile2.txt");
	if (input1.fail() || input2.fail()) {
		cout << "This file is not exist";
	}
	while (input1 >> inputString) {
		list1.insert(inputString);
	}
	list1.testConnections();
	while (input2 >> inputString) {
		list2.insert(inputString);
	}
	cout << "Size of List1: " << list1.getCount() << endl;
	cout << "Size of List2: " << list2.getCount() << endl;
	cout << "Size of ModList1: " << modList1.getCount() << endl;
	cout << "Size of ModList2: " << modList2.getCount() << endl;
	modList1 = list1;
	modList2 = list2;
	cout << "Size of List1: " << list1.getCount() << endl;
	cout << "Size of List2: " << list2.getCount() << endl;
	cout << "Size of ModList1: " << modList1.getCount() << endl;
	cout << "Size of ModList2: " << modList2.getCount() << endl;
	modList1.resetIterator();
	modList2.resetIterator();
	for (int i = 0; i < modList2.getCount(); i++) {
		list1.remove(modList2.next());
	}
	for (int i = 0;i < modList1.getCount();i++) {
		list2.remove(modList1.next());
	}
	cout << "Size of List1: " << list1.getCount() << endl;
	cout << "Size of List2: " << list2.getCount() << endl;
	cout << "Size of ModList1: " << modList1.getCount() << endl;
	cout << "Size of ModList2: " << modList2.getCount() << endl;
	//changer(modList1);
	//changer(modList2);
	cout << "Size of List1: " << list1.getCount() << endl;
	cout << "Size of List2: " << list2.getCount() << endl;
	cout << "Size of ModList1: " << modList1.getCount() << endl;
	cout << "Size of ModList2: " << modList2.getCount() << endl;
	cout << "Current Object: " << inputString.getCurrentObject() << endl;
	cout << "Created Object: " << inputString.getCreatedObject() << endl;
	output1 << modList1;
	output2 << modList2;
	output1.close();
	output2.close();
	input1.close();
	input2.close();
	system("pause");
	return 0;
}
void changer(DblLinkedList list)
{
	list.insert("ZIP");
	list.insert("ZAP");
	cout << "inside of changer function, the size of list is: " << list.getCount() << endl;
}
