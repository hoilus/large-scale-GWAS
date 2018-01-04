#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>

#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include <boost/iostreams/copy.hpp>

using namespace std;

int main()
{
  // reads data from file and transposes it; 1st row = column headers, stored into colNames
  std::vector <std::string> colNames;
  int ncols = 100000;
  char * cp;
  char delimi[] = ",";
  // process header line: store names of columns
  std::string file = "/geno.csv.gz";
  if ((int) file.length() > 3 && file.substr(file.length()-3) == ".gz") {
    std::ifstream fin (file.c_str(), ios_base::in | ios_base::binary);
      if (!fin) {
        std::cerr << "Error: Unable to open file: " << file << std::endl;
        exit(1);
      }
    boost::iostreams::filtering_istream boostin;
    boostin.push(boost::iostreams::gzip_decompressor());
    boostin.push(fin);
    // boost::iostreams::copy(boostin, std::cout);
    std::cout << "decompression is successful! " << std::endl;

    std::string line;
//    std::getline(boostin, line);
//    cp = strtok((char *)line.c_str(), delimi);
//    cp = strtok(NULL, delimi); // skip the first column
//    while (cp != NULL) {
/*    try {

    }
*/
//      colNames.push_back(cp);
//      cp = strtok(NULL, delimi);
//    }
//    ncols = colNames.size();
    std::cout << "column number is: " << ncols << std::endl;

    // count number of remaining lines: data rows
    int nrows = 10000;
//    while (getline(boostin, line)) {
////      cp = strtok((char *)line.c_str(), delimi);
////      std::cout << cp << " ";
//      nrows++;
//    }
//    std::cout << std::endl;
    std::cout << "total row number is: " << nrows << std::endl;

  // initialize data matrix
//    std::vector < std::vector <string> > data(nrows, std::vector <string> (ncols));
    std::vector < std::vector <string> > data(100, std::vector <string> (ncols));
    // boostin.clear();
//    boostin.seekg(0, std::ios::beg); // rewind
    //  getline(fin, line); // throw out header
    // read and store data
    // for (int r = 0; r < nrows; r++) {
    int r = 0;
    while (getline(boostin, line)) {
//      getline(boostin, line);
      std::vector <string> values;
      cp = strtok((char *)line.c_str(), delimi);
      cp = strtok(NULL, delimi); // skip the first column
      while (cp != NULL) {
        values.push_back(cp);
        cp = strtok(NULL, delimi);
      }
      if (values.size() != ncols) {
        std::cerr << "ERROR: Wrong number of entries in data row:" << std::endl;
        std::cerr << line << std::endl;
        std::cerr << "Expected " << ncols << " fields; parsed " << values.size() << std::endl;
        exit(1);
      }
      for (int c = 0; c < ncols; c++)
        data[r][c] = values[c];
      r++;
      values.clear();
      if (r >= 100) break;
    }
    fin.close();
    fin.clear();
    boostin.clear();
    // debugging starts
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++)  {
          std::cout << data[i][j] << " ";
      }
      std::cout << std::endl;
    }

    } // end of .gz file readin
  return 0;
}
