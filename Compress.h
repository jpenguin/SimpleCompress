//
// Created by jpenguin on 1/30/22.
//

#ifndef COMPRESS_H
#define COMPRESS_H

#include <string>
#include <fstream>
#include <iostream>

using std::cout;
using std::ifstream;
using std::ofstream;
using std::string;

class Compress
{
public:
    static void GetData(ifstream &, string[], int *, int[], int *);
    static void Write(string[], int, int[], int);
};

#endif // COMPRESS_H
