#pragma once

#include <concepts>
#include <utility>

template<typename T>
concept Comparable = requires(const T & a, const T & b) {
	{ a == b } -> std::convertible_to<bool>;
	{ a < b }  -> std::convertible_to<bool>;
	{ a > b }  -> std::convertible_to<bool>;
};

template<typename T>
concept Indexable = requires(T a, size_t i) {
	{ a[i] };
};

template<typename T>
concept ComparableAndIndexable = Comparable<T> && Indexable<T>;

/*!
	@brief Сортировка вставками.
	@version 1.0.
	@date 11.08.2025.
	@warning Создано только в учебных целях.

	Классическая реализация сортировки вставками. Обязательно условие для работы - операторы сравнения и оператор доступа по индексу [];

	@param arr коллекция
	@param len длина сортируемой коллекции
	@return копия коллекции, отсортированная
*/
template<ComparableAndIndexable T>
T insertion_sort(T&& arr, size_t len)
{
	T copy_arr = std::forward<T>(arr);

	if (len <= 1)
	{
		return copy_arr;
	}

	for (size_t i = 1; i < len; ++i)
	{
		auto copy_elem = copy_arr[i];
		size_t j = i;

		while (j > 0 && copy_arr[j - 1] > copy_elem)
		{
			copy_arr[j] = copy_arr[j - 1];
			j -= 1;
		}
		copy_arr[j] = copy_elem;
	}

	return copy_arr;
}