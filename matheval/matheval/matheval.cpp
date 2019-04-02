#include <iostream>
#include <string>
#include <list>

#include "evaluate.h"

using namespace std;

int main()
{
	list<string> rpn = { "3","4","+" };

	cout << evaluate(rpn);
	getchar();
}