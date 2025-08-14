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
concept Sizeable = requires(T a, size_t i) {
	{ a.size() } -> std::convertible_to<size_t>;
};


template<typename T>
concept Cont = Comparable<T> && Indexable<T> && Sizeable<T>;

/*!
	@brief ���������� ���������.
	@version 1.0.
	@date 11.08.2025.
	@warning ������� ������ � ������� �����.

	������������ ���������� ���������� ���������. ����������� ������� ��� ������ - ��������� ���������, �������� ������� �� ������� [] � ����� .size();

	@param arr ���������
	@param isDescending ���� ���������� �� �������� 
	@return ����� ���������, ���������������
*/
template<Cont T>
T insertion_sort(T&& arr, bool isDescending = false)
{
	T copy_arr = std::forward<T>(arr);
	size_t len = copy_arr.size();

	if (len <= 1)
	{
		return copy_arr;
	}

	for (size_t i = 1; i < len; ++i)
	{
		auto copy_elem = copy_arr[i];
		size_t j = i;

		while (j > 0 && ((isDescending && copy_arr[j - 1] < copy_elem) || (!isDescending && copy_arr[j - 1] > copy_elem)))
		{
			copy_arr[j] = copy_arr[j - 1];
			j -= 1;
		}
		copy_arr[j] = copy_elem;
	}

	return copy_arr;
}

/*!
	@brief ���������� �������.
	@version 1.0.
	@date 11.08.2025.
	@warning ������� ������ � ������� �����.

	������������ ���������� ���������� �������. ����������� ������� ��� ������ - ��������� ��������� � �������� ������� �� ������� [];

	@param arr ���������
	@return ����� ���������, ���������������
*/
template<Cont T>
T selection_sort(T&& arr)
{
	T copy_arr = std::forward<T>(arr);
	size_t len = copy_arr.size();

	if (len <= 1)
	{
		return copy_arr;
	}

	for (size_t i = 0; i < len - 1; ++i) 
	{
		size_t minIndex = i; 
		for (size_t j = i + 1; j < len; ++j) 
		{ 
			if (copy_arr[j] < copy_arr[minIndex]) 
			{
				minIndex = j;
			}
		}
		std::swap(copy_arr[minIndex], copy_arr[i]);
	}

	return copy_arr;
}