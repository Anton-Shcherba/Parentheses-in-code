#include <iostream>
#include <stack>

int main()
{
	std::stack <std::pair<char, int>> st;
	char c;
	unsigned res = 0;
	while (std::cin.get(c)) {
		res++;
		if (c == '\n') {
			if (st.empty()) {
				std::cout << "Success";
				break;
			}
			else {
				std::cout << st.top().second;
				break;
			}
		}
		else if (c == '}' || c == ']' || c == ')') {
			if (st.empty()) {
				std::cout << res;
				break;
			}
			else if ((c == '}' && st.top().first == '{') || (c == ']' && st.top().first == '[') || (c == ')' && st.top().first == '(')) {
				st.pop();
				continue;
			}
			else {
				std::cout << res;
				break;
			}
		}
		else if (c == '{' || c == '[' || c == '(') {
			st.push(std::make_pair(c, res));
			continue;
		}
	}
}
