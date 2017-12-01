#include <iostream>
#include <string>

int main()
{
	std::string t;
	int sum = 0;
	char temp = 0;
	std::cin >> t;
	int half_len = t.length() / 2;

	for (unsigned int i = 0; i < t.length(); ++i)
	{
		temp = t[half_len];
		if (t[i] == temp)
		{
			sum += t[i] - '0';
		}
		if (half_len == t.length() - 1)
		{
			half_len = 0;
		}
		else
		{
			++half_len;
		}
	}
	std::cout << sum;

	system("PAUSE");
	return 0;
}