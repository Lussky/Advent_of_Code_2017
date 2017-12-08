#include <iostream>
#include <string>
#include <fstream>

int Find_Difference( std::string line );

int main()
{
	std::string line;
	int sum = 0;
	int n; std::cin >> n;

	std::fstream file;
	file.open("input.txt", std::ios::in);
	
	if (file.good() == false)
	{
		std::cout << "File doesn't exist!";
		exit(0);
	}

	while (getline(file, line))
	{
		for (int i = 0; i < n; ++i)
		{
			//getline(std::cin, line);
			sum += Find_Difference(line);
			Find_Difference(line);
			std::cout << Find_Difference(line) << std::endl;
		}
	}
	
	file.close();
	file.clear();

	std::cout << sum << std::endl;

	system("PAUSE");
	return 0;
}

int Find_Difference( std::string line )
{
	int max, min, temp;
	std::string segment;
	max = min = std::stoi(line.substr(0,4));

	for ( int i = 0; i < line.length(); ++i )
	{
		if ( line[i] == ' ' )
			continue;

		if ( line[i + 1] != ' ' )
		{
			segment = line[i];
			for ( ; i < line.length(); ++i )
			{
				if ( line[i + 1] != ' ' )
					segment += line[i + 1];
				else
					break;
			}
			temp = std::stoi(segment);
		}
		else
			temp = line[i] - '0';

		if ( max < temp )
			max = temp;
		if ( min > temp )
			min = temp;
	}

	return max - min;
}