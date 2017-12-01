#include <iostream>

int main()
{
	char t;
	int sum = 0;
	char temp = 0;
	do
	{
		std::cin >> t;
		if (t == temp)
		{
			sum += t - 48;
		}
		temp = t;
	} while ( t != '.' );
	std::cout << sum;

	system("PAUSE");
	return 0;
}