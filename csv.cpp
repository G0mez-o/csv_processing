#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

auto split(std::string& input,char delimiter)
{
  std::istringstream stream(input);
  std::string field;
  std::vector<std::string> result;
  while (std::getline(stream, field, delimiter))
    result.push_back(field);
  return result;
}

int main()
{
  int row;
  int column;
  std::string line, filename;
  std::cout << "Please input filename!!" << std::endl;
  std::cin >> filename;
  std::ifstream ifs(filename);
  std::vector<std::vector<double>> data_base;
  for (row = 0; getline(ifs, line); row++)
    {
      std::vector<double> save_data;
      std::vector<std::string> strvec = split(line, ',');
      for (column = 0; column < strvec.size(); column++)
	save_data.push_back(stold(strvec.at(column)));
      data_base.push_back(save_data);
    }
  std::cout << "row:" << row << "  &&  column:" << column << std::endl;
  for (int i = 0; i < row; i++)
      for (int j = 0; j < column; j++)
	std::cout << "data[" << i << "]" << "[" << j << "]:" << data_base[i][j] << std::endl;
}

