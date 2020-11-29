#include <iostream>
#include <string>

/* ������ ��ͷ� ȣ��Ǵ� sum�� argument�� 1�� �̹Ƿ�, �̸� ���� template�� �����ؾ� �Ѵ�.
 *  parameter ������ 1���� function sum template�� �߰��� �����Ѵ�.
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