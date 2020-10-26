#include <iostream>
int main() {
    char stek[100000];
	char c;
	unsigned size = 0;
	unsigned res = 0;
	while (std::cin.get(c)) {
		res++;
		if (c == '\n') {
			if (size == 0) std::cout << "Success";
			else std::cout << size--;
			break;
		}
		else if (c == '{' || c == '[' || c == '(') {
			stek[size++] = c;
			continue;
		}
		else if (c == '}' || c == ']' || c == ')') {
			if (size == 0) {
				std::cout << res;
				break;
			}
			else if ((c == '}' && stek[size - 1] == '{') || (c == ']' && stek[size - 1] == '[') || (c == ')' && stek[size - 1] == '(')) {
				size--;
				continue;
			}
			else {
				std::cout << res;
				break;
			}
		}
	}
    return 0;
}
