#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
  const string ALL_ONES_NAME = "CONST_ALL_ONES";
  // [VECTOR]: covariates are internally stored as rows
  std::vector <std::string> rowNames;

  rowNames = std::vector <std::string> (1, ALL_ONES_NAME); // always include all-1s vector
  int nrows;

  ifstream fin;
  fin.open("readpheno_header.txt");
  std::string line;
  std::getline(fin, line);
  std::istringstream iss(line);
  string FID, IID, covarName;
  iss >> FID >> IID;
  while (iss >> covarName) rowNames.push_back(covarName);
  fin.close();

  //print out the inputdata
  nrows = rowNames.size();
  std::cout << nrows << std::endl;
  typedef std::vector <std::string> Path;
  for( Path::size_type i=0; i<rowNames.size(); ++i)
    std::cout << rowNames[i] << ' ';
  std::cout << std::endl;
/*  for (int i = 0; i < 3; ++i)
  {
      for (int j = 0; j < 4; ++j)
      {
          std::cout << data[i][j] << ' ';
      }
      std::cout << std::endl;
  }
*/
  return 0;
}
