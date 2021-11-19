#include <iostream>
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
	int toDelete; // Число для удаления
	int number; // Номер выбора
	int counter; // кол-во элементов в массиве
	int index;

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
		cout << "\n\t\t\t 7. Удаление заданого числа (всех повторяющихся тоже)";
		cout << "\n\t\t\t 8. Удаление последнего элемента";
		cout << "\n\t\t\t 9. Удаление по индексу";
		cout << "\n\t\t\t 10. Выход";
		cout << "\n\n\n\tВведите номер пункта: ";
		cin >> number;
		switch (number)
		{
		case 1: cout << "Введите элемент: ";
			cin >> S;
			list.AddHead(S);
			cout << "\n\n\t\tУспешно добавлено!\n";
			system("pause");
			break;
		case 2: cout << "Введите элемент: ";
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
		case 6: cout << "\n\n\t\tВведите элемент для поиска: ";
			cin >> S;
			if (list.Search(S))
				cout << "\n\n\t\tЭлемент найден!" << endl;
			else list.Search(S);
			system("pause");
			break;
		case 7: cout << "\n\n\t\tВведите элемент для удаления: ";
			cin >> toDelete;
			list.DeleteAllSelected(toDelete);
			cout << "Элементы со значением " << toDelete << " были удалены!" << endl;
			system("pause");
			break;			
		case 8: list.DeleteBack();
			cout << "\n\n\t\tЗапись удалена из конца списка\n";
			system("pause");
			break;
		case 9: cout << "\n\n\t\tВведите индекс элемента" << endl;
			cout << "\n\n\t\t";
			list.Show();
			cin >> index;
			list.Delete(index);
			cout << "\n\n\t\tЗапись удалена\n";
			system("pause");
			break;
		case 10: exit(1);
		default: break;
		}
	}
	system("pause");
}