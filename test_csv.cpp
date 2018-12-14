#include <iostream>
#include "csv_class.hpp"

int main()
{
  csv_mat data;
  std::cout << data.value(1, 1) << std::endl;
  data.rowout(1);
  std::cout << data.num() << std::endl;;
}
