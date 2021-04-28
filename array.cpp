#include <iostream>
#include <random>
using namespace std;
random_device random;
//Создайте класс динамического массива, в котором реализована проверка выхода за границы массива.
//Перегрузите операторы :[] , =, +, -, 
//++(добавление элемента в конец массива), 
//––(удаление элемента из конца массива).

class Array
{
private:
	int* arr;
	int SIZE;
public:
	Array()
	{
		SIZE = 1;
		arr = new int[SIZE];
		for (int i = 0; i < SIZE; ++i)
		{
			arr[i] = random()%10;
		}
	}

	Array(int n)
	{
		SIZE = n;
		arr = new int[SIZE];
		for (int i = 0; i < SIZE; ++i)
		{
			arr[i] = rand() % 100;
		}
	}

	Array(const Array& source)
	{
		SIZE = source.SIZE;
		arr = new int[SIZE];
		for (int i = 0; i < SIZE; ++i)
		{
			arr[i] = source.arr[i];
		}
	}

	void increasingArray(int newItem)
	{
		if (SIZE != 0)
		{
			int* a;
			a = new int[SIZE];

			for (int i = 0; i < SIZE; ++i)
			{
				a[i] = arr[i];
			}

			delete[] arr;

			SIZE = newItem;
			arr = new int[newItem];

			for (int i = 0; i < newItem; ++i)
			{
				if (i < SIZE)
				{
					arr[i] = a[i];
				}
				else
				{
					arr[i] = 0;
				}
			}
			delete a;
		}
		else
		{
			SIZE = newItem;
			arr = new int[newItem];
		}
	}

	int getSize()
	{
		return SIZE;
	}

	void print()
	{
		for (int i = 0; i < SIZE; ++i)
			cout << arr[i] << "  ";
		cout << endl;
	}

	void sorting()
	{
		int temp;
		for (int i = 0; i < SIZE; ++i)
		{
			temp = arr[i];
			for (int j = i; j < SIZE; ++j)
				if (temp > arr[j])
				{
					temp = arr[j];
					arr[j] = arr[i];
					arr[i] = temp;
				}
		}
	}
	int max()
	{
		int max;

		max = arr[0];

		for (int i = 1; i < SIZE; ++i)
		{
			if (max < arr[i]) max = arr[i];
		}

		return max;
	}
	int min()
	{
		int min;

		min = arr[0];

		for (int i = 1; i < SIZE; ++i)
		{
			if (min > arr[i]) min = arr[i];
		}
		return min;
	}
	int& operator[](int index) {
		return arr[index];
	}

	Array& operator= (const Array& newArr)
	{
		if (this == &newArr)
			return *this;
		arr = newArr.arr;
		SIZE = newArr.SIZE;

		return *this;
	}
	

	~Array()
	{
		delete[] arr;
	}
};

void deleteEl(int*& arr, int& SIZE, int pos)
{
	int* temp = new int[SIZE];
	for (int i = 0; i < SIZE; ++i)
	{
		temp[i] = arr[i];
	}
	delete[]arr;
	arr = new int[SIZE - 1];
	pos--;
	if (pos >= 0 && pos < SIZE)
	{
		for (int i = 0; i < SIZE; ++i)
		{
			if (i >= pos)
			{
				if (i == SIZE - 1)
				{
					break;
				}
				arr[i] = temp[i + 1];
			}
			else
			{
				arr[i] = temp[i];
			}
		}
	}
	cout << endl;
	delete[]temp;
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void changeEl(int*& arr, int& SIZE, int pos, int change)
{
	int* temp = new int[SIZE];
	for (int i = 0; i < SIZE; ++i)
	{
		temp[i] = arr[i];
	}
	delete[]arr;
	arr = new int[SIZE];
	pos--;
	if (pos >= 0 && pos < SIZE)
	{
		for (int i = 0; i < SIZE; ++i)
		{
			if (i == pos)
			{
				arr[i] = change;
			}
			else
			{
				arr[i] = temp[i];
			}
		}
	}
	cout << endl;
	delete[]temp;
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void fillArray(int* const arr, const int size, int range)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = random() % range;
	}
}
void showArray(const int* const arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void push_back(int*& arr, int& size, const int value)
{
	int* newArray = new int[size + 1];

	for (int i = 0; i < size; i++)
	{
		newArray[i] = arr[i];
	}

	newArray[size] = value;

	size++;

	delete[] arr;

	arr = newArray;

}
void pop_back(int*& arr, int& size)
{
	size--;
	int* newArray = new int[size];
	for (int i = 0; i < size; i++)
	{
		newArray[i] = arr[i];
	}

	delete[] arr;

	arr = newArray;

}

int main()
{
	Array arr(10);
	arr.print();
	
	/*Apparent brightness,

		Luminosity,

		Stefan - Boltzmann constant, 5.67 × 10–8 Wm−2 K−4

		1 parsec = 3.09 × 1016 m

		1 lightyear = 9.46 × 1015 m*/



	return 0;
}