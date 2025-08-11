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
	std::vector<int> v{ 31, 41, 59, 26, 41, 58 };

	printVector(insertion_sort(v, v.size()));
	
	cout << "Hello CMake." << endl;
	return 0;
}
