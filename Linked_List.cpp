#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{
public:
	LinkedList(T value)
	{
		this->value = value;
	}

	T value;
	LinkedList* next = nullptr;

	friend std::ostream& operator <<(std::ostream& out, const LinkedList<T>& list)
	{
		while (list.next != nullptr)
		{
			out << list.value;
		}
		return out;
	}

};

template <typename T>
class MyArray
{
public:
	MyArray(std::initializer_list<T> elements) {

		this->length = int(elements.size());

		auto* begin = elements.begin();

		arr = new T[length]{};

		int i = 0;
		while (i < length) {
			arr[i] = *begin;
			begin++;
			i++;
		}
	}

	bool AddToHead(T data);
	bool AddToTail(T data);
	T DeleteFromHead();
	T DeleteFromTail();
	void DeleteAll();
	void show();
	void SetSize(int grow);
	void GetSize();

private:
	T* arr{};
	int length{};
	int size{};
};

template <typename T>
bool MyArray<T>::AddToHead(T data)
{
	T* arr_copy = new T[size];
	for (int i = 0; i < size; i++) {
		arr_copy[i] = this->arr[i];
	}
	SetSize(1);

	for (int i = 0; i < size - 1; i++) {
		this->arr[i] = arr_copy[i];
	}
	this->arr[size - 1] = data;

	return true;
}

template <typename T>
bool MyArray<T>::AddToTail(T data)
{
	T* arr_copy = new T[size];
	for (int i = 0; i < size; i++) {
		arr_copy[i] = this->arr[i];
	}
	SetSize(1);

	this->arr[0] = data;
	for (int i = 1; i < size; i++) {
		this->arr[i] = arr_copy[i - 1];
	}

	return true;
}

template <typename T>
T MyArray<T>::DeleteFromHead()
{
	if (this->size < 0)
		return 0;

	SetSize(-1);
	return 1;
}

template <typename T>
T MyArray<T>::DeleteFromTail()
{
	if (this->size < 0)
		return 0;

	T* arr_copy = new T[size];
	for (int i = 1; i < size; i++) {
		arr_copy[i - 1] = this->arr[i];
	}
	SetSize(-1);
	for (int i = 0; i < size; i++) {
		this->arr[i] = arr_copy[i];
	}
	return 1;
}

template <typename T>
void MyArray<T>::DeleteAll()
{
	if (this->size >= 0) {
		for (int i = size - 1; i >= 0; i--) {
			DeleteFromHead();
		}
	}
	cout << "\nWe remove all from Linked List," << endl;
	show();
}

template<typename T>
void MyArray<T>::show() {
	cout << "linked List now: " << endl;
	for (int i = 0; i < this->size; i++)
	{
		cout << this->arr[i] << " ";
	}
	cout << endl;
}

template <typename T>
void MyArray<T>::SetSize(int grow) {
	this->size += grow;
	T* arr = new T[size];
}

template <typename T>
void MyArray<T>::GetSize()
{
	cout << "size: " << this->size << endl;
}


int main()
{
	MyArray<int> some_nums{};
	int element = -1;
	int choice = -1;

	cout << "If you want add to head - enter \"1\"," << endl
		<< "If you want add to tail - enter \"2\"," << endl
		<< "if you want to delete from head - enter \"3\"," << endl
		<< "if you want to delete from tail - enter \"4\"," << endl
		<< "if you want to end it - enter \"0\":";

	while (choice != 0) {
		cout << "\n->";
		cin >> choice;
		if (choice == 0) {
			some_nums.show();
		}
		else if (choice == 1) {
			cout << "Enter element for list: ";
			cin >> element;
			some_nums.AddToHead(element);
		}
		else if (choice == 2) {
			cout << "Enter element for list: ";
			cin >> element;
			some_nums.AddToTail(element);
		}
		else if (choice == 3) {
			some_nums.DeleteFromHead();
		}
		else
		{ // choice == 4
			some_nums.DeleteFromTail();
		}
	}
	some_nums.DeleteAll();

	return 0;
}
