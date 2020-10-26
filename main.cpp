#include <iostream>
int main() {
    char stek[100000];
	char c;
	unsigned size = 0;
	while (std::cin.get(c)) {
		if (c == '\n') {
			if (size == 0) std::cout << "Success";
			else std::cout << size + 1;
			break;
		}
		else if (c == '{' || c == '[' || c == '(') {
			stek[size++] = c;
			continue;
		}
		else if (c == '}' || c == ']' || c == ')') {
			if (size == 0) {
				std::cout << size + 1;
				break;
			}
			else if ((c == '}' && stek[size - 1] == '{') || (c == ']' && stek[size - 1] == '[') || (c == ')' && stek[size - 1] == '(')) {
				size--;
				continue;
			}
			else {
				std::cout << size + 1;
				break;
			}
		}
		else size++;
	}
    return 0;
}
