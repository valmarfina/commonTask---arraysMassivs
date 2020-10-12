#include <iostream>

void inArray(int array[], const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		std::cin >> array[i];
		if (std::cin.fail())
		{
			//std::cerr << "Некорректный ввод!" << std::endl;
			throw std::exception("Некорректный ввод!");
		}
	}
}

void outArray(int array[], const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

bool isOrderedArray(int array[], const int SIZE)
{
	for (int i = 0; i < SIZE - 1; i++)
	{
		if (array[i] >= array[i + 1])
		{
			return false;
		}
	}
	return true;
}

void permutationArray(int array[], const int SIZE)
{
	for (int i = 0; i < SIZE - 1; i += 2)
	{
		std::swap(array[i], array[i + 1]);
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Введите кол-во элементов для динамического массива: " << std::endl;
	int size_array;
	std::cin >> size_array;
	if (std::cin.fail())
	{
		//std::cerr << "Некорректный ввод!" << std::endl;
		throw std::exception("Некорректный ввод!");
	}

	//динамический
	int* mas_array = new int[size_array];

	//статический
	const int SIZE = 10;
	int array[SIZE];


	try
	{
		std::cout << "Введите элементы динамического массива: " << std::endl;
		inArray(mas_array, size_array);

		std::cout << "Вывод массива: " << std::endl;
		outArray(mas_array, size_array);

		std::cout << "Массив идет по возрастанию?" << std::endl;
		std::cout << isOrderedArray(mas_array, size_array) << std::endl;

		std::cout << "Перестановка соседних элементов массива: " << std::endl;
		permutationArray(mas_array, size_array);
		outArray(mas_array, size_array);

		delete[] mas_array;

		std::cout << "====================================================================" << std::endl;


		std::cout << "Введите элементы статического массива: " << std::endl;
		inArray(array, SIZE);

		std::cout << "Вывод массива: " << std::endl;
		outArray(array, SIZE);

		std::cout << "Массив идет по возрастанию?" << std::endl;
		std::cout << isOrderedArray(array, SIZE) << std::endl;

		std::cout << "Перестановка соседних элементов массива: " << std::endl;
		permutationArray(array, SIZE);
		outArray(array, SIZE);

	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
		//std::cerr << "error" << std::endl;
	}

	return 0;
}