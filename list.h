template<typename type>
class List {
private:
	template<typename type>
	class Node { // Ячейка хранящая данные списка
	public:
		type data; //Хранимые данные
		Node* next; // Указатель на следующий элемент
		Node* prev; // Указатель на предыдущий элемент

		Node(type data = 0, Node* next = nullptr, Node* prev = nullptr) // Конструктор
		{
			this->data = data;
			this->next = next;
			this->prev = prev;
		}

	};

	size_t size; // Переменная хранящая размер списка
	Node<type>* head; // Указатель на первый элемент списка
	Node<type>* tail; // Указатель на последний элемент списка

public:
	List(); // Конструктор (1)
	~List(); // Деструктор (2)

	// Добавление элементов (3)
	void Add(type data); // Добавление элемента в конец (3)
	void AddHead(type data); // Добавление элемента в начало (3)
	void Insert(type data, int index); // Добавление элемента по заданному индексу (3)

	// Удаление элементов (4)
	void DeleteBack(); // Удалить последний элемент списка (4)
	void DeleteFront(); // Удалить первый элемент списка (4)
	void Delete(int index); // Удалить элемент по заданному индексу (4)

	type& operator[](const int index); // Перегруженный оператор индексирования, позволяет получить выбранный элемент списка (5)
	bool Search(type data); // Поиск заданных элементов (5)

	//void DeleteAllSelected(type data); // Удаление всех выбранных элементов из списка (Задание из 7 варианта)

	size_t GetSize(); // Получение размера списка

	void Show(); // Вывод списка на экран (Задание из 7 варианта)
	
	void DeleteAllSelected(type data, List<type>& list);

	void Clear(); // Очистка списка

	void Revers(); // Развернуть список (для удобной индексации)
};
