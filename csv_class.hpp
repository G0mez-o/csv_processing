#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include "split.hpp"
#include "csv_ostream.hpp"

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
  int num();
  void output();
  void colout(int);
  void rowout(int);
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
int csv_mat::num() { return rows*columns; }
void csv_mat::output() { return all_output(data_base, rows, columns); }
void csv_mat::colout(int num) { return col_output(data_base, rows, num); }
void csv_mat::rowout(int num) { return row_output(data_base, num, columns); }
