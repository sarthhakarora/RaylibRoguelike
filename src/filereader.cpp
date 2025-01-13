#include "filereader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector> 

std::vector<std::vector<int>> Filereader::loadCsv(const char* filename)
{
    file.open(filename, std::ios::in);
    std::vector<std::vector<int>> data;

    if(!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;

        return data;    
    }

    std::string rowData;
    std::vector<int> row;
    std::string element;

    int i = 0;

    while (getline(file, rowData)) {
        row.clear();

        std::istringstream stringStream(rowData);

        while (getline(stringStream, element, ',')) {
            row.push_back(std::stoi(element));
            
        }

        data.push_back(row);

        if (i >= 100) {
            break;
        }

    }

    return data;

}