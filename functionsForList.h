#include "list.h"
#include <iostream>
using namespace std;


template<typename type>
List<type>::List()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}

template<typename type>
List<type>::~List()
{
}

template<typename type>
void List<type>::Add(type data)
{
	if (head == nullptr) // ���� ������ ���� �� ������ ����� �������, ������� ����� � ������� � ������ ������
	{
		head = tail = new Node<type>(data);
	}
	else // � ��������� ������ ��������� ����� ������� � ����� ������
	{
		Node<type>* current = new Node<type>(data, nullptr, tail); // ������ ����� ������� � ������ ���������� �� ��������� ������� � ���������� �� ��������� ������� ������
		tail->next = current; // ����������� ���������� �������� ������ ��������� ���������� �������� - ����� ������ ��������
		tail = current; // ����������� ��������� �� ��������� ������� - ����� ������ ��������
	}

	size++;
}

template<typename type>
void List<type>::AddHead(type data)
{
	if (head == nullptr) // ���� ������ ���� �� ������ ����� �������, ������� ����� � ������� � ������ ������
	{
		head = tail = new Node<type>(data);;
	}
	else // � ��������� ������ ��������� ����� ������� � ������ ������
	{
		Node<type>* temp = new Node<type>(data, head); // ������ ����� ������� � ������� ���������� �� ���������� ������� � �������� �� ������ ������� ������ � ��������� �� ���������
		head->prev = temp; // ������� �������� ������ � ��������� �� ���������� ������� ���������� ������ ������ �������� ������
		head = temp; // ������� ��������� �� ������ ������� - ������ ������ ��������
	}

	size++; // ����������� ������� ��������� ������
}

template<typename type>
type& List<type>::operator[](const int index)
{
	Node<type>* current;
	int iterator;

	if (index <= size / 2)
	{
		current = head;
		iterator = 0;
		while (true)
		{
			if (iterator == index)
			{
				return current->data;
			}
			else
			{
				current = current->next;
				iterator++;
			}
		}
	}
	else
	{
		current = tail;
		iterator = size - 1;
		while (true)
		{
			if (iterator == index)
			{
				return current->data;
			}
			else
			{
				current = current->prev;
				iterator--;
			}
		}
	}
}

template<typename type>
size_t List<type>::GetSize()
{
	return size;
}

template<typename type>
void List<type>::Show()
{
	Node<type>* temp = tail;

	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->prev;
	}
	cout << endl;
}

template<typename type>
void List<type>::Insert(type data, int index)
{
	if (index == 0)
	{
		AddHead(data);
	}
	else if (index == size)
	{
		Add(data);
	}
	else
	{
		Node<type>* previous;
		Node<type>* current;

		if (index <= size / 2)
		{
			previous = head;

			for (int i = 0; i < index - 1; i++)
			{
				previous = previous->next;
			}

			current = new Node<type>(data, previous->next, previous);
			previous->next->prev = current;
			previous->next = current;
		}
		else
		{
			previous = tail;

			for (int i = size - 1; i > index; i--)
			{
				previous = previous->prev;
			}

			current = new Node<type>(data, previous, previous->prev);
			previous->prev->next = current;
			previous->prev = current;
		}
	}

	size++;
}

template<typename type>
void List<type>::DeleteBack()
{
	if (head) {
		if (head != tail) {
			Node<type>* temp; // ������ ������ �� ������� ������
			tail = tail->prev; // ����������� ��������� �� ��������� ������� - ����� ��������������� ��������
			temp = tail->next; //��� ��� ������ �� ��������� ������� ������ ��������� �� �������������, ���� ������ ���������� �������� �� ��� ��������� �� ���������
			tail->next = nullptr; // ��������� �� ��������� ������� - �������� ��������� �� ���������
			delete temp; // ��� ��� ������ ����� ���������� ������� �������� �� ��������� ������, ������� ��� ����� ��� ������
			--size; // ��������� ������� ��������� ������
		}
		else
		{
			delete head;
			head = tail = nullptr;
			--size;
		}
	}
	else cout << "List is empty!" << endl;
}

template<typename type>
void List<type>::DeleteFront()
{
	if (head) {
		if (head != tail) {
			Node<type>* temp = head; //������ ������ �� ������� ������ � ����������� �� ������ ������� �������� ������
			head = head->next; // ������ �� ������ ������� ������ ����������� ������ ���������� ��������
			head->prev = nullptr; // ������ �� ������ ������� �������� ���� ����������� ��������
			delete temp; // ��� ��� ������ ������� ������ ������ �������� �� ��������� ������, ������� ��� ����� ���   ������
			--size; // ��������� ������� ��������� ������
		}
		else
		{
			delete head;
			head = tail = nullptr;
			--size;
		}
	}
	else cout << "List is empty!" << endl;
}

template<typename type>
void List<type>::Delete(int index)
{
	if (index == 0)
	{
		Node<type>* temp = head;
		head = head->next;
		delete temp;
	}
	else if (index == size - 1)
	{
		Node<type>* temp = tail;
		tail = tail->prev;
		delete temp;
	}
	else
	{
		Node<type>* previous;
		Node<type>* toDelete;

		if (index <= size / 2)
		{
			previous = head;

			for (int i = 0; i < index - 1; i++)
			{
				previous = previous->next;
			}

			toDelete = previous->next;
			previous->next = toDelete->next;
			toDelete->next->prev = previous;
		}
		else
		{
			previous = tail;

			for (int i = size - 1; i > index + 1; i--)
			{
				previous = previous->prev;
			}

			toDelete = previous->prev;
			previous->prev = toDelete->prev;
			toDelete->prev->next = previous;
		}

		delete toDelete;
	}
	size--;
}

template<typename type>
void List<type>::Clear()
{
	while (size > 0)
	{
		Node<type>* temp = head;
		head = head->next;
		delete temp;
		size--;
	}
}

template<typename type>
void List<type>::Revers() {
	Node<type>* first = head; // ������ ��������� ��������� �� ������ � ��������� �������� ������
	Node<type>* lust = tail; // ����������� �� ������ ������ � ����� ������ ��������������
	Node<type>* temp = new Node<type>(); // ������ ����� ������� ������ ��� ��������� ����������
	for (int i = 0; i < (size / 2); ++i) { // ���� ���� ������ ��������� ������ - �������� ��� ������� ������� �������� - �������� �� ��������� ����������
		temp->data = first->data;        // �� ����� ������� �������� �������� �� �������� ��� ������� �� ��������� ������� � � ���� �������� ������ ������� �� ��������� ����������
		first->data = lust->data;        // ����� ����� �������� ������ �� ������ � ��������� ������� � ������ ������ ����� ��������� �� ��������� ������� � ���������� ��������������
		lust->data = temp->data;         // ��������� - ����������� ���, ������ ������������� �������� ������� ������, ��� ��� ��� � ���� ������
		first = first->next;            // ���� ���������� ��������� ����� ������, �� ����������� �������� ����� ���������� ����� �������� ������� ��� ��������
		lust = lust->prev;              // ���� ����������� ����� �� ������, �� ����������� ������� ��������� ����������, ��� ��� �� � ������ �������� �� ��� �� �����
	}
	delete temp; // ������� ��������� ���������� ��� ������������ ������

}

template<typename type>
bool List<type>::Search(type data)
{
	int count = 0;
	Node<type>* p = head;
	while (p)
	{
		if (p->data == data)
			return true;
		p = p->next;
	}
	return false;
}

template<typename type>
void List<type>::DeleteAllSelected(type data, List<type>& list)
{
	int index = list.size;
	for (int i = 0; i <= index; i++)
	{
		if (list[i] == data)
			list.Delete(i);
	}
	cout << "�������� �� ��������� " << data << " ���� �������!" << endl;
}