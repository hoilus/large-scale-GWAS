#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
  // reads data from file and transposes it; 1st row = column headers, stored into colNames
  std::vector <std::string> colNames;
  int ncols;
  // process header line: store names of columns
  ifstream fin;
  fin.open("readpheno_header.txt");
  std::string line;
  std::getline(fin, line);
  std::istringstream issHead(line);
  string headerName;
  while (issHead >> headerName) colNames.push_back(headerName);
  ncols = colNames.size();

  // count number of remaining lines: data rows
  int nrows = 0;
  while (getline(fin, line))
    nrows++;

  // initialize data matrix
  std::vector < std::vector <string> > data(nrows, std::vector <string> (ncols));
  fin.clear(); fin.seekg(0, std::ios::beg); // rewind
  getline(fin, line); // throw out header

  // read and store data
  for (int r = 0; r < nrows; r++) {
    getline(fin, line);
    std::istringstream iss(line);
    string value;
    std::vector <string> values;
    while (iss >> value) values.push_back(value);
    if (values.size() != ncols) {
      std::cerr << "ERROR: Wrong number of entries in data row:" << std::endl;
      std::cerr << line << std::endl;
      std::cerr << "Expected " << ncols << " fields; parsed " << values.size() << std::endl;
      exit(1);
    }
    for (int c = 0; c < ncols; c++)
      data[r][c] = values[c];
  }
  fin.close();

  //print out the inputdata
/*  std::cout << nrows << std::endl;
  typedef std::vector <std::string> Path;
  for( Path::size_type i=0; i<rowNames.size(); ++i)
    std::cout << rowNames[i] << ' ';
  std::cout << std::endl;
*/
  for (int i = 0; i < nrows; i++)
  {
      for (int j = 0; j < ncols; j++)
      {
          std::cout << data[i][j] << '  ';
      }
      std::cout << std::endl;
  }

  return 0;
}
