#include <stack>
#include <string>

using namespace std;

bool balancedBrackets(string str) {
	// Write your code here.
	int count = 0;
	char x;
	for (char c : str)
	{

		if (c == '(' || c == '{' || c == '[')
		{
			count++;
			continue;
		}
		else
		{
			count--;
			if (count < 0) return false;
		}
	}
	
	return count == 0;
}

