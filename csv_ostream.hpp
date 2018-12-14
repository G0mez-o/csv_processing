#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

void all_output(std::vector<std::vector<double>> vec, int rows, int columns)
{
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++)
      std::cout << "data[" << i+1 << "]" << "[" << j+1 << "]:" << vec[i][j] << std::endl;
  std::cout << "rows: " << rows << "  &&  columns: " << columns << std::endl;
}

void col_output(std::vector<std::vector<double>> vec, int rows, int num)
{
  for (int i = 0; i < rows; i++)
    std::cout << "data[" << i+1 << "]" << "[" << num << "]" << vec[i][num] << std::endl;
}

void row_output(std::vector<std::vector<double>> vec, int num, int columns)
{
  for (int i = 0; i < columns; i++)
    std::cout << "data[" << num << "]" << "[" << i+1 << "]" << vec[num][i] << std::endl;
}
