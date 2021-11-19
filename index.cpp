//TODO:
// 1)Доделать удаление по заданному числу
// 2)Оформить отчет

#include <iostream>
#include <vector>
#include "functionsForList.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "RU");
	//Счет индексов начинается не слева направо, а наоборот
	//Имеем массив a = [1,2,3,4,5]
	//В данном случае a[0] = 5, a[1] = 4
	//При добавлении элемента в голову заменяем a[0] на другой!!!

	List<int> list;



	int S; // Число для добавления
	int number; // Номер выбора
	int counter; // кол-во элементов в массиве

	cout << "Введите кол-во элементов в массиве: " << endl;
	cin >> counter;
	int* mas = new int[counter]; // Массив с элементами
	cout << "Введите элементы массива: ";

	for (int i = 0; i < counter; i++)
	{
		cin >> mas[i];
		list.AddHead(mas[i]);
	}

	while (1)
	{
		system("cls");
		cout << "\n\t\t\t 1. Добавление записи в начало списка";
		cout << "\n\t\t\t 2. Добавление записи в конец списка";
		cout << "\n\t\t\t 3. Удаление записи из начала списка";
		cout << "\n\t\t\t 4. Вывод";
		cout << "\n\t\t\t 5. Очистка списка";
		cout << "\n\t\t\t 6. Поиск по значению";
		cout << "\n\t\t\t 7. Выход";
		cout << "\n\n\n\tВведите номер пункта: ";
		cin >> number;
		switch (number)
		{
		case 1: cout << "Введите элемент:";
			cin >> S;
			list.AddHead(S);
			cout << "\n\n\t\tУспешно добавлено!\n";
			system("pause");
			break;
		case 2: cout << "Введите элемент:";
			cin >> S;
			list.Add(S);
			cout << "\n\n\t\tУспешно добавлено!\n";
			system("pause");
			break;

		case 3: list.DeleteFront();
			cout << "\n\n\t\tЗапись удалена из начала списка\n";
			system("pause");
			break;
		case 4: cout << "\n\n\t\tСписок: ";
			list.Show();
			system("pause");
			break;
		case 5: list.Clear();
			cout << "\n\n\t\tСписок очищен\n";
			system("pause");
			break;
		case 6: cout << "\n\n\t\tВведите элемент для поиска";
			cin >> S;
			list.Search(S);
			system("pause");
			break;
		case 7: exit(1);
		default: break;
		}
	}
	system("pause");
}