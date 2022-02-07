//
// Created by jpenguin on 1/30/22.
//

#ifndef COMPRESS_H
#define COMPRESS_H

#include <string>
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::string;
class Compress
{
public:
    /*******************************************************************************
     * Function Name: Compress::GetData()
     * Parameters: Pointers to word list, number list, unique word count, word
     *count Return Value: void Purpose: Fill array with list of unique words and
     *numbered occurrences
     *******************************************************************************/
    static void GetData(ifstream &, string[], int *, int[], int *);
    /*************************************************************************
     * Function Name: Compress::Write()
     * Parameters: Word list, number list, word count, unique word count
     * Return Value: void
     * Purpose: Write arrays to file
     *************************************************************************/
    static void Write(string[], int, int[], int);
};

#endif // COMPRESS_H
