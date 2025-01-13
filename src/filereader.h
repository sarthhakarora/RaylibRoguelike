#ifndef FILEREADERS_H
#define FILEREADERS_H

#include <fstream>
#include <vector>

class Filereader
{
public:
    std::ifstream file;

    std::vector<std::vector<int>> loadCsv(const char* filename);

};


#endif