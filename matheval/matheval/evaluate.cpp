#include <iostream>
#include <list>
#include <string>
#include <stack>
#include <iterator>
#include <cmath>
#include <algorithm>
#include <cctype>

#include "evaluate.h"

using namespace std;

int get_top(const stack<string>& stack)
{
	if (stack.size() > 0)
	{
		return stoi(stack.top(), nullptr, 10);
	}
	cerr << "Stack is empty!";
	return 0;
}

string evaluate_partial(const string& op, const int a, const int b)
{
	int result;
	if (op == "+")
	{
		result = a + b;
	}
	else if (op == "-")
	{
		result = a - b;
	}
	else if (op == "*")
	{
		result = a * b;
	}
	else if (op == "/")
	{
		if (b == 0)
		{
			cerr << "Cannot divide by zero!";
			return "0";
		}
		result = a / b;
	}
	return to_string(result);
}

bool is_operator(const string& token)
{
	const list<string> operators = { "+", "-", "*", "/" };
	return find(operators.begin(), operators.end(), token) != operators.end();
}

bool is_number(const string& token)
{
	return !token.empty() && find_if(token.begin(), token.end(),
		[](char c) { return !isdigit(c); }) == token.end();
}

int evaluate(const list<string>& expr)
{
	stack<string> tmp;
	list<string>::const_iterator it;
	for (it = expr.begin(); it != expr.end(); ++it)
	{
		if (is_number(*it))
		{
			tmp.push(*it);
		}
		else if (is_operator(*it))
		{
			if (tmp.size() < 2)
			{
				cerr << "Invalid expression!";
				return 0;
			}
			int a = get_top(tmp);
			tmp.pop();
			int b = get_top(tmp);
			tmp.pop();
			tmp.push(evaluate_partial(*it, a, b));
		}
	}
	return get_top(tmp);
}