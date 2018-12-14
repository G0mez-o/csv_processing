#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include "split.hpp"

class csv_mat
{
public:
  std::vector<std::vector<double>> data_base;
  int rows, columns;
  std::string filename;
  csv_mat();
  auto name();
  auto row();
  auto column();
  auto  value(int, int);
  void output();
};

csv_mat::csv_mat()
{
  std::cout << "Please input filename!!:";
  std::cin >> filename;
  std::ifstream ifs(filename);
  std::string line;
  for (rows = 0; getline(ifs, line); rows++)
    {
      std::vector<double> save_data;
      std::vector<std::string> strvec = split(line, ',');
      for (columns = 0; columns < strvec.size(); columns++)
	save_data.push_back(stold(strvec.at(columns)));
      data_base.push_back(save_data);
    }
  std::cout << "Finished input data from " << filename << std::endl;
}
auto csv_mat::name() { return filename; }
auto csv_mat::row() { return rows; }
auto csv_mat::column() { return columns; }
auto csv_mat::value(int i, int j) { return data_base[i-1][j-1]; }

void csv_mat::output()
{
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++)
      std::cout << "data[" << i+1 << "]" << "[" << j+1 << "]:" << data_base[i][j] << std::endl;
  std::cout << "row: " << rows << "  &&  column: " << columns << std::endl;
}
