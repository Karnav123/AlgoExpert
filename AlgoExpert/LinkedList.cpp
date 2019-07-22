#include <vector>
#include <iostream>
using namespace std;

class LinkedList {
public:
	int value;
	LinkedList* next;

	LinkedList(int value);
	void addMany(vector<int> values);
	vector<int> getNodesInArray();
	LinkedList* getNthNode(int n);
};

LinkedList* LinkedList::getNthNode(int n) {
	int counter = 1;
	LinkedList* current = this;
	while (counter < n) {
		current = current->next;
		counter++;
	}
	return current;
}

void removeKthNodeFromEnd(LinkedList* head, int k) {
	// Write your code here.
	if (head == nullptr) return;
	LinkedList * back = head;
	LinkedList * front = head;

	for (int i = 0; i < k; ++i)
	{
		if (front)
			front = front->next;
		else
			return;
	}
	while ( front && front->next != nullptr)
	{
		front = front->next;
		back = back->next;
	}

	if (front == nullptr)
	{
		head = head->next;
		return;
	}
	else if (back && back->next)
		back->next = back->next->next;
	else
		back->next = nullptr;
}

LinkedList::LinkedList(int value) {
	this->value = value;
	this->next = NULL;
}

void LinkedList::addMany(vector<int> values) {
	LinkedList* current = this;
	while (current->next != NULL) {
		current = current->next;
	}
	for (int value : values) {
		current->next = new LinkedList(value);
		current = current->next;
	}
}

vector<int> LinkedList::getNodesInArray() {
	vector<int> nodes{};
	LinkedList* current = this;
	while (current != NULL) {
		nodes.push_back(current->value);
		current = current->next;
	}
	return nodes;
}

LinkedList* findLoop(LinkedList* head)
{
	// Write your code here.
	if (head == nullptr) return head;
	LinkedList * back = head;
	LinkedList * front = head;
	
	while (front != nullptr)
	{
		back = back->next;
		front = front->next->next;

		if (front == back)
		{
			break;
		}
	}

	back = head;
	while (back != front)
	{
		back = back->next;
		front = front->next;
	}

	return back;
}

/*int main() {

	LinkedList test1(0);
	test1.addMany({ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
	test1.getNthNode(10)->next = test1.getNthNode(1);
	bool isEqual = (findLoop(&test1) == test1.getNthNode(1));

	cout << "Is EQUAL: " << isEqual << endl;

	LinkedList test2(0);
	test2.addMany({ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
	test2.getNthNode(10)->next = test2.getNthNode(2);
	bool isEqual2 = (findLoop(&test2) == test2.getNthNode(2));

	int val = test2.getNthNode(2)->value;
	cout << val << endl;
	cout << "Is EQUAL2: " << isEqual2 << endl;


	LinkedList test3(0);
	test3.addMany({ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
	LinkedList result3(0);
	result3.addMany({ 1, 2, 3, 4, 5, 6, 8, 9 });
	removeKthNodeFromEnd(&test3, 3);
	bool res3 = (test3.getNodesInArray() == result3.getNodesInArray());

	LinkedList test4(0);
	test4.addMany({ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
	LinkedList result4(0);
	result4.addMany({ 1, 2, 3, 4, 5, 7, 8, 9 });
	removeKthNodeFromEnd(&test4, 4);
	bool res4 = (test4.getNodesInArray() == result4.getNodesInArray());


	LinkedList test5(0);
	test5.addMany({ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
	LinkedList result5(0);
	result5.addMany({ 1, 2, 3, 4, 6, 7, 8, 9 });
	removeKthNodeFromEnd(&test5, 5);
	bool res5 = (test5.getNodesInArray() == result5.getNodesInArray());

	LinkedList test6(0);
	test6.addMany({ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
	LinkedList result6(0);
	result6.addMany({ 1, 2, 3, 5, 6, 7, 8, 9 });
	removeKthNodeFromEnd(&test6, 6);
	bool res6 = (test6.getNodesInArray() == result6.getNodesInArray());
	
	LinkedList test7(0);
	test7.addMany({ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
	LinkedList result7(0);
	result7.addMany({ 1, 2, 4, 5, 6, 7, 8, 9 });
	removeKthNodeFromEnd(&test7, 7);
	bool res7 = (test7.getNodesInArray() == result7.getNodesInArray());

	LinkedList test8(0);
	test8.addMany({ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
	LinkedList result8(0);
	result8.addMany({ 1, 3, 4, 5, 6, 7, 8, 9 });
	removeKthNodeFromEnd(&test8, 8);
	bool res8 = (test8.getNodesInArray() == result8.getNodesInArray());

	LinkedList test9(0);
	test9.addMany({ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
	LinkedList result9(0);
	result9.addMany({ 2, 3, 4, 5, 6, 7, 8, 9 });
	removeKthNodeFromEnd(&test9, 9);
	bool res9 = (test9.getNodesInArray() == result9.getNodesInArray());

	LinkedList test10(0);
	test10.addMany({ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
	LinkedList result10(1);
	result10.addMany({ 2, 3, 4, 5, 6, 7, 8, 9 });
	removeKthNodeFromEnd(&test10, 10);
	bool res10 = (test10.getNodesInArray() == result10.getNodesInArray());

	cout << res4 << endl;
	cout << res5 << endl;
	cout << res6 << endl;
	cout << res7 << endl;
	cout << res8 << endl;
	cout << res9 << endl;
	cout << res10 << endl;
	return 0;
}*/
