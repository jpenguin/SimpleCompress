//
// Created by jpenguin on 1/30/22.
//

#include "Compress.h"

void Compress::write(string *uniqueWords, int numUniqueWords, int *wordOccurrences, int numWords)
{
    ofstream output ("output.jzip");
    if (output.is_open())
    {
        for(int count = 0; count < numWords; count ++){
            output << wordOccurrences[count] << " " ;
        }
        output << "\n\n\n";
        for(int count = 0; count < numUniqueWords; count ++){
            output << uniqueWords[count] << " " ;
        }
        output.close();
    }
    else cout << "Unable to create file";
}
