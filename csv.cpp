#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#define Filename "sample.csv"

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
  int row = 0;
  int column = 0;
  std::ifstream ifs(Filename);
  std::string line;
  std::vector<double> save_data;
  for (int i = 0; getline(ifs, line); i++, row++)
    {
      std::vector<std::string> strvec = split(line, ',');
      for (int j=0; j<strvec.size(); j++, column++)
	save_data.push_back(stold(strvec.at(j)));
    }
  column = column / row;
  // for(int i = 0; i < save_data.size(); i++)
  //   std::cout << save_data[i] << std::endl;

  std::vector<long double> first;
  for (int i = 0; i < column; i++)
    {
      first.push_back(save_data[i]);
      std::cout << first[i] << std::endl;
    }
}
