#include <iostream>


// default parameter 값을 2로 수정한다.
template <typename T, int num = 2>
T add_num(T t) {
	return t + num;
}

int main() {
	int x = 3;
	std::cout << "x : " << add_num(x) << std::endl;
}
