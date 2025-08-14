// alg.cpp: определяет точку входа для приложения.
//

#include "alg.h"

#include <vector>

#include "sorting.h"

using namespace std;

template <typename T>
void printVector(const std::vector<T>& vec) {
	std::cout << "[ ";
	for (const auto& item : vec) {
		std::cout << item << " ";
	}
	std::cout << "]\n";
}

int main()
{
	std::vector<int> v{ 0, 3, 0, 2, 4, 1, 5, 798, 799, 6, 0 };

	printVector(selection_sort(v));
	
	cout << "Hello CMake." << endl;
	return 0;
}
