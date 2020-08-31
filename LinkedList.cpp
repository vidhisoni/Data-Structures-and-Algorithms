#include <iostream>
#include <assert.h>
#include <stack>
#include <unordered_set>

class Node
{
public:
	int data;
	Node* next;
};

void pushNode(Node** pHead, int newData)
{
	Node* newNode = new Node();
	newNode->data = newData;
	newNode->next = *pHead;
	*pHead = newNode;
}

void insertNode(Node* prevNode, int newData)
{
	if (prevNode != NULL)
	{
		Node* newNode = new Node();
		newNode->data = newData;
		newNode->next = prevNode->next;
		prevNode->next = newNode;
	}
	else
	{
		return;
	}
}

void append(Node** pHead, int newData)
{
	Node* newNode = new Node();
	Node* pLastNode = *pHead;

	newNode->data = newData;
	newNode->next = NULL;

	if (*pHead == NULL)
	{
		*pHead = newNode;
		return;
	}

	while (pLastNode->next != NULL)
	{
		pLastNode = pLastNode->next;
	}

	pLastNode->next = newNode;
}

void deleteNode(Node** pHead, int key)
{
	Node* temp = *pHead;
	Node* prev = NULL;

	if(temp != NULL && temp->data == key)
	{
		*pHead = temp->next;
		delete temp;
		return;
	}

	while (temp != NULL && temp->data != key)
	{
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL)
	{
		return;
	}

	prev->next = temp->next;
	delete(temp);
}

int getLength(Node** pHead)
{
	int count = 0;
	Node* current = *pHead;

	while (current != NULL)
	{
		current = current->next;
		++count;
	}
	return count;
}

bool searchKey(Node** pHead, int key)
{
	Node* current = *pHead;
	while (current != NULL)
	{
		if (current->data == key)
		{
			return true;
		}
		current = current->next;
	}
	return false;
}

int getNthVal(Node* pHead, int index)
{
	int count = 0;
	Node* current = pHead;
	
	while (current != NULL)
	{
		if (count == index)
		{
			return current->data;
		}
		++count;
		current = current->next;
	}
	return -1;
}

int getNthValLast(Node* pHead, int index)
{
	int count = 0;
	Node* mainPtr = pHead;
	Node* refPtr = pHead;

	if (index == 0)
	{
		assert(0);
	}
	if (pHead != NULL)
	{
		while (count != index)
		{
			if (refPtr == NULL)
			{
				assert(0);	
			}
			refPtr = refPtr->next;
			++count;
		}

		while (refPtr != NULL)
		{
			refPtr = refPtr->next;
			mainPtr = mainPtr->next;
		}
		return (mainPtr->data);
	}
	else
	{
		return -1;
	}
}

int printMiddle(Node* pHead)
{
	int count = 0;
	Node* mid = pHead;

	while (pHead != NULL)
	{
		if (count & 1)
		{
			mid = mid->next;
		}
		++count;
		pHead = pHead->next;
	}
	if (mid != NULL)
	{
		return mid->data;
	}
	else
	{
		return -1;
	}
}

int countNode(Node* pHead, int num)
{
	Node* current = pHead;
	int count = 0;

	while (current != NULL)
	{
		if (current->data == num)
		{
			++count;
		}
		current = current->next;
	}
	return count;
}

int countNode(Node* commonNode)
{
	int count = 1;
	Node* temp = commonNode;
	while (temp->next != commonNode)
	{
		temp = temp->next;
		++count;
	}
	return count;
}

int detectLoop(Node* pHead)
{
	Node* slowPtr = pHead;
	Node* fastPtr = pHead;

	while (slowPtr && fastPtr && fastPtr->next)
	{
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
		if (slowPtr == fastPtr)
		{
			 return countNode(slowPtr);
		}
	}
	return 0;
}

void printList(Node* pNode)
{
	while (pNode != NULL)
	{
		std::cout << pNode->data << " ";
		pNode = pNode->next;
	}
	std::cout << "\n";
}

void deleteList(Node** pNode)
{
	Node* current = *pNode;
	Node* next;

	while (current != NULL)
	{
		next = current->next;
		delete current;
		current = next;
	}
}

bool isPalindrome(Node* pHead)
{
	Node* slowPtr = pHead;
	std::stack <int> s;

	while (slowPtr != NULL)
	{
		s.push(slowPtr->data);
		slowPtr = slowPtr->next;
	}

	while (pHead != NULL)
	{
		int data = s.top();
		s.pop();

		if (pHead->data != data)
		{
			return false;
		}
		pHead = pHead->next;
	}
	return true;
}

void removeDuplicate(Node* pHead)
{
	Node* pPtr = pHead;
	Node* nextNext = NULL;

	if (pPtr == NULL)
	{
		return;
	}

	while (pPtr->next != NULL)
	{
		if (pPtr->data == pPtr->next->data)
		{
			nextNext = pPtr->next->next;
			delete(pPtr->next);
			pPtr->next = nextNext;
		}
		else
		{
			pPtr = pPtr->next;
		}
	}
}

void removeDuplicateUnsorted(Node* pHead)
{
	std::unordered_set<int> uset;
	Node* current = pHead;
	Node* prev = pHead;

	while (current != NULL)
	{
		if (uset.find(current->data) != uset.end())
		{
			prev->next = current->next;
			delete(current);
		}
		else
		{
			uset.insert(current->data);
			prev = current;
		}
		current = prev->next;
	}
}

void swap(Node** node1, Node** node2)
{
	Node* temp = NULL;
	temp = *node1;
	*node1 = *node2;
	*node2 = temp;
}

void swapNodes(Node* pHead, int x, int y)
{
	Node** nodeX = NULL;
	Node** nodeY = NULL;

	Node** temp = &pHead;

	if (x == y)
	{
		return;
	}

	while (*temp)
	{
		if ((*temp)->data == x)
		{
			nodeX = temp;
		}
		else if ((*temp)->data == y)
		{
			nodeY = temp;
		}
		temp = &(*temp)->next;
	}

	if (nodeX && nodeY)
	{
		swap(nodeX, nodeY);
		swap(&(*nodeX)->next, &(*nodeY)->next);
	}
}

int main()
{
	Node* head = new Node();
	Node* second = new Node();
	Node* third = new Node();

	//pushNode(&head, 20);
	//pushNode(&head, 4);
	//pushNode(&head, 15);
	//pushNode(&head, 10);
	//Create a loop for testing 
	//head->next->next->next->next = head;
	//int countNode = detectLoop(head);
	//if (countNode != 0)
	//	std::cout << "\nLoop found. Length: "<<countNode;
	//else
	//	std::cout << "\nNo Loop";

	head->data = 2;
	head->next = second;

	second->data = 1;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	pushNode(&head, 4);

	insertNode(second, 5);

	append(&head, 6);
	append(&head, 7);

	//deleteNode(&head, 6);
	/* Let us create a sorted linked list to test the functions
	Created linked list will be 11->11->11->13->13->20 */
	/*pushNode(&head, 20);
	pushNode(&head, 13);
	pushNode(&head, 13);
	pushNode(&head, 11);
	pushNode(&head, 11);
	pushNode(&head, 11);*/

	printList(head);
	//removeDuplicateUnsorted(head);

	swapNodes(head, 2, 5);
	printList(head);

	/*if (isPalindrome(head))
	{
		std::cout << "\nIs a palindrome";
	}
	else
	{
		std::cout << "Is not a palindrome";
	}*/

	/*int count = countNode(head, 2);
	std::cout << "\nCount is: " << count;*/

	/*int valAtIndex = getNthValLast(head, 2);
	std::cout << "\nValue is " << valAtIndex;*/

	/*int valMid = printMiddle(head);
	std::cout << "\nValue is " << valMid;*/

	/*int length = getLength(&head);
	std::cout << "\nLength of linked list: " << length;

	bool search = searchKey(&head, 6);
	if (search)
	{
		std::cout << "\nKey found";
	}
	else
	{
		std::cout << "\nKey not found";
	}*/

	deleteList(&head);

	return 0;
}