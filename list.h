template<typename type>
class List {
private:
	template<typename type>
	class Node { // ������ �������� ������ ������
	public:
		type data; //�������� ������
		Node* next; // ��������� �� ��������� �������
		Node* prev; // ��������� �� ���������� �������

		Node(type data = 0, Node* next = nullptr, Node* prev = nullptr) // �����������
		{
			this->data = data;
			this->next = next;
			this->prev = prev;
		}

	};

	size_t size; // ���������� �������� ������ ������
	Node<type>* head; // ��������� �� ������ ������� ������
	Node<type>* tail; // ��������� �� ��������� ������� ������

public:
	List(); // ����������� (1)
	~List(); // ���������� (2)

	// ���������� ��������� (3)
	void Add(type data); // ���������� �������� � ����� (3)
	void AddHead(type data); // ���������� �������� � ������ (3)
	void Insert(type data, int index); // ���������� �������� �� ��������� ������� (3)

	// �������� ��������� (4)
	void DeleteBack(); // ������� ��������� ������� ������ (4)
	void DeleteFront(); // ������� ������ ������� ������ (4)
	void Delete(int index); // ������� ������� �� ��������� ������� (4)

	type& operator[](const int index); // ������������� �������� ��������������, ��������� �������� ��������� ������� ������ (5)
	bool Search(type data); // ����� �������� ��������� (5)

	//void DeleteAllSelected(type data); // �������� ���� ��������� ��������� �� ������ (������� �� 7 ��������)

	size_t GetSize(); // ��������� ������� ������

	void Show(); // ����� ������ �� ����� (������� �� 7 ��������)
	
	void DeleteAllSelected(type data, List<type>& list);

	void Clear(); // ������� ������

	void Revers(); // ���������� ������ (��� ������� ����������)
};
