#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int Find_Difference( std::string line );
int Checksum( std::string line );

int main()
{
	std::string line;
	int sum = 0;

	std::fstream file;
	file.open("input1.txt", std::ios::in);
	
	if (file.good() == false)
	{
		std::cout << "File doesn't exist!";
		exit(0);
	}

	while (getline(file, line))
	{
		sum += Checksum(line);
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
		if ( line[i] == '\t' )
			continue;

		if ( line[i + 1] != '\t' )
		{
			segment = line[i];
			for ( ; i < line.length(); ++i )
			{
				if ( line[i + 1] != '\t' )
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

int Checksum( std::string line )
{
	int max, min, temp;
	std::string segment;
	std::vector <int> numbers;
	max = min = std::stoi(line.substr(0, 4));

	for (int i = 0; i < line.length(); ++i)
	{
		if (line[i] == '\t')
			continue;

		if (line[i + 1] != '\t')
		{
			segment = line[i];
			for (; i < line.length(); ++i)
			{
				if (line[i + 1] != '\t')
					segment += line[i + 1];
				else
					break;
			}
			temp = std::stoi(segment);
		}
		else
			temp = line[i] - '0';

		numbers.push_back( temp );
	}

	for ( int i = 0; i < numbers.size(); ++i )
	{
		for ( int j = i + 1; j < numbers.size(); ++j )
		{
			if ( numbers[i] < numbers[j] )
			{
				if ( (numbers[j] % numbers[i]) == 0 )
				{
					return numbers[j] / numbers[i];
				}
			}
			else
			{
				if ( (numbers[i] % numbers[j]) == 0 )
				{
					return numbers[i] / numbers[j];
				}
			}
		}
	}

	//return max/min;
}
