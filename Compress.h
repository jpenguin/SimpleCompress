//
// Created by jpenguin on 1/30/22.
//

#ifndef COMPRESS_H
#define COMPRESS_H

#include <string>
#include <fstream>
#include <iostream>

using std::string;
using std::cout;
using std::ofstream;
using std::ifstream;

class Compress
{
public:
    void GetData(ifstream &, string[], int *, int[], int *);
    void Write(string[], int, int[], int);
};




#endif //COMPRESS_H
