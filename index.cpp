#include <iostream>
#include "functionsForList.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "RU");
	//���� �������� ���������� �� ����� �������, � ��������
	//����� ������ a = [1,2,3,4,5]
	//� ������ ������ a[0] = 5, a[1] = 4
	//��� ���������� �������� � ������ �������� a[0] �� ������!!!

	List<int> list;

	int S; // ����� ��� ����������
	int toDelete; // ����� ��� ��������
	int number; // ����� ������
	int counter; // ���-�� ��������� � �������
	int index;

	cout << "������� ���-�� ��������� � �������: " << endl;
	cin >> counter;
	int* mas = new int[counter]; // ������ � ����������
	cout << "������� �������� �������: ";

	for (int i = 0; i < counter; i++)
	{
		cin >> mas[i];
		list.AddHead(mas[i]);
	}

	while (1)
	{
		system("cls");
		cout << "\n\t\t\t 1. ���������� ������ � ������ ������";
		cout << "\n\t\t\t 2. ���������� ������ � ����� ������";
		cout << "\n\t\t\t 3. �������� ������ �� ������ ������";
		cout << "\n\t\t\t 4. �����";
		cout << "\n\t\t\t 5. ������� ������";
		cout << "\n\t\t\t 6. ����� �� ��������";
		cout << "\n\t\t\t 7. �������� �������� ����� (���� ������������� ����)";
		cout << "\n\t\t\t 8. �������� ���������� ��������";
		cout << "\n\t\t\t 9. �������� �� �������";
		cout << "\n\t\t\t 10. �����";
		cout << "\n\n\n\t������� ����� ������: ";
		cin >> number;
		switch (number)
		{
		case 1: cout << "������� �������: ";
			cin >> S;
			list.AddHead(S);
			cout << "\n\n\t\t������� ���������!\n";
			system("pause");
			break;
		case 2: cout << "������� �������: ";
			cin >> S;
			list.Add(S);
			cout << "\n\n\t\t������� ���������!\n";
			system("pause");
			break;

		case 3: list.DeleteFront();
			cout << "\n\n\t\t������ ������� �� ������ ������\n";
			system("pause");
			break;
		case 4: cout << "\n\n\t\t������: ";
			list.Show();
			system("pause");
			break;
		case 5: list.Clear();
			cout << "\n\n\t\t������ ������\n";
			system("pause");
			break;
		case 6: cout << "\n\n\t\t������� ������� ��� ������: ";
			cin >> S;
			if (list.Search(S))
				cout << "\n\n\t\t������� ������!" << endl;
			else list.Search(S);
			system("pause");
			break;
		case 7: cout << "\n\n\t\t������� ������� ��� ��������: ";
			cin >> toDelete;
			list.DeleteAllSelected(toDelete);
			cout << "�������� �� ��������� " << toDelete << " ���� �������!" << endl;
			system("pause");
			break;			
		case 8: list.DeleteBack();
			cout << "\n\n\t\t������ ������� �� ����� ������\n";
			system("pause");
			break;
		case 9: cout << "\n\n\t\t������� ������ ��������" << endl;
			cout << "\n\n\t\t";
			list.Show();
			cin >> index;
			list.Delete(index);
			cout << "\n\n\t\t������ �������\n";
			system("pause");
			break;
		case 10: exit(1);
		default: break;
		}
	}
	system("pause");
}