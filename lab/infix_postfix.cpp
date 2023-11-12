#include<bits/stdc++.h>
using namespace std;

int precedence(char ch) {
	if (ch == '^')
		return 3;
	else if (ch == '/' || ch == '*')
		return 2;
	else if (ch == '+' || ch == '-')
		return 1;
	else
		return -1;
}

string infixToPostfix(string s) {

	stack<char> st;
	string ans = "";

	for (int i = 0; i < s.length(); i++) {
		char ch = s[i];


		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
			ans += ch;


		else if (ch == '(')
			st.push('(');


		else if (ch == ')') {
			while (st.top() != '(')
			{
				ans += st.top();
				st.pop();
			}
			st.pop();
		}

		else {
			while (!st.empty() && precedence(s[i]) <= precedence(st.top())) {
				ans += st.top();
				st.pop();
			}
			st.push(ch);
		}
	}

	while (!st.empty()) {
		ans += st.top();
		st.pop();
	}

	return ans;
}

int main() {
	string s;
	cout << "Enter infix expression: ";
	cin >> s;
	cout << "The postfix expression is: " << infixToPostfix(s);
	return 0;
}
