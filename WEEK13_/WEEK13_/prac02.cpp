#include <iostream>
#include <string>

/* 마지막 재귀로 호출되는 sum의 argument는 1개 이므로, 이를 위한 template을 구현해야 한다.
 *  parameter 개수가 1개인 function sum template을 추가로 구현한다.
 */
template<typename T>
auto sum(T x) {
	return x;
}
template<typename T, typename...Args>
auto sum(T x, Args... args) {
	return x + sum(args...);
}

int main() {
	auto x = sum(42.5, 10, 11.1f);
	std::cout << x;
	getchar();
}