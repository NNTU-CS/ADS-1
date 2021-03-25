#include <locale.h>
#include <iostream>
using namespace std;
// Функция бинарного поиска
int cbinsearch(int* arr, int size, int value, int counter)
{
	int left = 0, right = size - 1;//rigt-правая граница массива,left-левая граница массива

	while (left  <= right)
	{
		int c = (left + right) / 2;// формула вычисления элемента , находящегося в середине ;этот элемент постоянно сдвигается
		if (value == arr[c]) return c;// Если элемент найден, возвращаем его
		else if (value < arr[c]) right = c - 1;//Если элемент меньше серединного , 
											//то сдвигаем правую границу r влево
		else left = c + 1;
	}

	for (int i = 0; i < size; i++)
	{
		if (arr[i] == value)
		{
			counter++;
		}
	}

	return -1;//возвращает -1 , если не найден нужный элемент
}
// Функция инициализации массива случайными чмслами
void init_array(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100; // Заполнение массива
	}
}
void print_array(int* arr, int size)
{
		if (size <= 20)
		{
			for (int i = 0; i < size; i++)
			{
				cout << arr[i] << " ";
			}
			cout << "\n";
		}
		else if (size > 20)
		{
			for (int i = 0; i < 10; i++)
			{
				cout << arr[i] << " ";
			}

			cout << "........ ";
			for (int i = size-10; i < size; i++)
			{
				cout << arr[i] <<" ";
			}
			cout << "\n";
		}
}
void insert_sort(int* arr, int size)
{
	int i, j, pos, temp;
	for (i = 1; i < size; i++)
	{
		pos = i;
		while (pos > 0 && arr[pos - 1] > arr[pos])
		{
			int tmp;
			tmp = arr[pos - 1];
			arr[pos - 1] = arr[pos];
			arr[pos] = tmp;
			pos--;
		}
	}
}
	
int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	int size;
	int value;
	int counter = 0;
	//true позволяет делать цикл вечным
	while (true)
	{
		cout << "Введите размер будущего массива:\n";
		cin >> size;
		int* arr = new int[size]; // Выделил память под массив размера n
		init_array(arr, size);
		cout << "Исходный  массив:\n";
		print_array(arr, size);
		cout << "Отсортированный массив:\n";
		insert_sort(arr,  size);
		print_array(arr, size);
		cout << "Введите элемент для поиска от 0 до 100:\n";
		cin >> value;
		cbinsearch(arr, size, value, counter);
	}
	return 0;
}
