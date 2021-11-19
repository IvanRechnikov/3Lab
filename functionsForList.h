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
	if (head == nullptr) // Если список пуст то создаём новый элемент, который будет и началом и концом списка
	{
		head = tail = new Node<type>(data);
	}
	else // В противном случае добавляем новый элемент в конец списка
	{
		Node<type>* current = new Node<type>(data, nullptr, tail); // Создаём новый элемент с пустым указателем на следующий элемент и указателем на последний элемент списка
		tail->next = current; // Присваивает последнему элементу списка указателю следующего элемента - адрес нового элемента
		tail = current; // Присваиваем указателю на последний элемент - адрес нового элемента
	}

	size++;
}

template<typename type>
void List<type>::AddHead(type data)
{
	if (head == nullptr) // Если список пуст то создаём новый элемент, который будет и началом и концом списка
	{
		head = tail = new Node<type>(data);;
	}
	else // В противном случае добавляем новый элемент в начало списка
	{
		Node<type>* temp = new Node<type>(data, head); // Создаём новый элемент с нулевым указателем на предыдущий элемент и адрессом на первый элемент списка в указателе на следующий
		head->prev = temp; // Первому элементу списка в указатель на предыдущий элемент записываем адресс нового элемента списка
		head = temp; // Передаём указателю на первый элемент - адресс нового элемента
	}

	size++; // Увеличиваем счётчик элементов списка
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
			Node<type>* temp; // Создаём ссылку на элемент списка
			tail = tail->prev; // Присваиваем указателю на последний элемент - адрес предшествующего элемента
			temp = tail->next; //Так как ссылка на последний элемент теперь указывает на предпоследний, берём адресс последнего элемента из его указателя на следующий
			tail->next = nullptr; // Указателю на последний элемент - обнуляем указатель на следующий
			delete temp; // Так как теперь адрес последнего элемент хранится во временной ссылке, удаляем его через эту ссылку
			--size; // Уменьшаем счётчик элементов списка
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
			Node<type>* temp = head; //Создаём ссылку на элемент списка и присваиваем ей адресс первого элемента списка
			head = head->next; // Ссылке на первый элемент списка присваиваем адресс следующего элемента
			head->prev = nullptr; // Ссылке на первый элемент обнуляем поле предыдущего элемента
			delete temp; // Так как первый элемент списка теперь хранится во временной ссылке, удаляем его через эту   ссылку
			--size; // Уменьшаем счётчик элементов списка
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
	Node<type>* first = head; // Создаём временные указатели на первый и последний элементы списка
	Node<type>* lust = tail; // Присваиваем им адреса начала и конца списка соответственно
	Node<type>* temp = new Node<type>(); // Создаём новый элемент списка как временную переменную
	for (int i = 0; i < (size / 2); ++i) { // Суть оего метода разворота списка - Значение под ссылкой первого элемента - положить во временную переменную
		temp->data = first->data;        // На место первого положить значение из элемента под ссылкой на последний элемент а в него положить данные первого из временной переменной
		first->data = lust->data;        // После этого сместить ссылки на первый и последний элемент к центру списка через указатели на следующий элемент и предыдущий соответственно
		lust->data = temp->data;         // Повторять - колличество раз, равное целочисленной половине размера списка, так как идём с двух сторон
		first = first->next;            // Если количество элементов будет чётное, то колличество итераций будет достаточно чтобы поменять местами все элементы
		lust = lust->prev;              // Если колличество буден не чётное, то центральный элемент останется нетронутым, так как он и должен остаться на том же месте
	}
	delete temp; // Удаляем временную переменную для освобождения памяти

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
	cout << "Элементы со значением " << data << " были удалены!" << endl;
}