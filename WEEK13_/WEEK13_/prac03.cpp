#include <iostream>
#include <algorithm>
#include <forward_list>
#include <functional>


/* compGreater
 * 인자 값 2개를 비교하여 x가 y보다 크면 true, 아니면 false를 리턴하는 operator overloading 구현  */
class compGreater {
public:
	bool operator() (int x, int y) const {
		return x > y;
	}
};
/* compLess
 * 인자 값 2개를 비교하여 y가 x보다 크면 true, 아니면 false를 리턴하는 operator overloading 구현  */
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
	std::cout << "오름차순 정렬" << std::endl;
	/* Functor compLess 생성 */
	compLess compLess; 
	bubble_sort(values.begin(), values.end(), compLess);

	for (auto it = values.begin(); it != values.end(); ++it) {
		std::cout << ' ' << *it;
	}
	std::cout << std::endl;
	std::cout << "내림차순 정렬" << std::endl;

	/* Functor compGreator 생성 */
	compGreater compGreater; 
	bubble_sort(values.begin(), values.end(), compGreater);

	for (auto it = values.begin(); it != values.end(); ++it) {
		std::cout << ' ' << *it;
	}
	std::cout << std::endl;
	getchar();
}