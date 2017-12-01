#include <iostream>
#include <string>

int main()
{
	std::string t;
	int sum = 0;
	char temp = 0;
	
	std::cin >> t;
	for (unsigned int i = 0; i < t.length(); ++i)
	{
		if (t[i] == temp)
		{
			sum += t[i] - 48;
		}
		temp = t[i];
	}
	std::cout << sum;

	system("PAUSE");
	return 0;
}