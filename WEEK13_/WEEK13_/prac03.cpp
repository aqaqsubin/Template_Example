#include <iostream>
#include <algorithm>
#include <forward_list>
#include <functional>


/* compGreater
 * ���� �� 2���� ���Ͽ� x�� y���� ũ�� true, �ƴϸ� false�� �����ϴ� operator overloading ����  */
class compGreater {
public:
	bool operator() (int x, int y) const {
		return x > y;
	}
};
/* compLess
 * ���� �� 2���� ���Ͽ� y�� x���� ũ�� true, �ƴϸ� false�� �����ϴ� operator overloading ����  */
class compLess {
public:
	bool operator() (int x, int y) const {
		return x < y;
	}
};
template <typename ForwardIterator, typename Compare>
void bubble_sort(ForwardIterator first, ForwardIterator last, Compare comp) {

	for (auto sorted = first; first != last; last = sorted) {
		sorted = first;

		for (auto cur = first, prev = first; ++cur != last; ++prev) {
			if (comp(*cur, *prev)) {
				std::iter_swap(cur, prev);
				sorted = cur;
			}
		}

	}
}
int main() {
	std::forward_list<int> values{ 7, 0, 6, 1, 5, 2, 4, 3 };
	std::cout << "�������� ����" << std::endl;
	/* Functor compLess ���� */
	compLess compLess; 
	bubble_sort(values.begin(), values.end(), compLess);

	for (auto it = values.begin(); it != values.end(); ++it) {
		std::cout << ' ' << *it;
	}
	std::cout << std::endl;
	std::cout << "�������� ����" << std::endl;

	/* Functor compGreator ���� */
	compGreater compGreater; 
	bubble_sort(values.begin(), values.end(), compGreater);

	for (auto it = values.begin(); it != values.end(); ++it) {
		std::cout << ' ' << *it;
	}
	std::cout << std::endl;
	getchar();
}