//
// Created by jpenguin on 1/30/22.
//

#include "Compress.h"

/*******************************************************************************
* Function Name: Compress::GetData()
* Parameters: Pointers to word list, number list, unique word count, word count
* Return Value: void
* Purpose: Fill array with list of unique words and numbered occurrences
*******************************************************************************/
void Compress::GetData(ifstream &toCompress,
                       string *uniqueWords,
                       int *numUniqueWords,
                       int *wordOccurrences,
                       int *numWords)
{
    int
        index;                                        //position of word in list
    string currentWord;
    bool found;
    // Put next word into currentWord; because we're using
    // arrays and not vectors, stop at 1000 words
    while (toCompress >> currentWord && *numWords < 1000) {
        found = false;
        for (int i = 0; i <= *numUniqueWords; i++) {
            if (uniqueWords[i] == currentWord) {
                found =
                    true;            // set to true if currentWord found in list
                index =
                    i;                          //set index to position found at
                break;                                 //if found, exit for loop
            }
        }
        if (!found) {
            uniqueWords[*numUniqueWords] =
                currentWord;                         //if not found, add to list
            index =
                *numUniqueWords;             //set index to lat position on list
            *numUniqueWords +=
                1;                       //next unique word will go in next spot
        }
        wordOccurrences[*numWords] =
            index;             //append position word was found or was placed at
        *numWords +=
            1;                                      //increment total word count
    }
}

/*************************************************************************
* Function Name: Compress::Write()
* Parameters: Word list, number list, word count, unique word count
* Return Value: void
* Purpose: Write arrays to file
*************************************************************************/
void Compress::Write(string *uniqueWords,
                     int numUniqueWords,
                     int *wordOccurrences,
                     int numWords)
{
    ofstream output("output.jzip");
    if (output.is_open()) {
        for (int count = 0; count < numWords; count++) {
            output << wordOccurrences[count] << " ";
        }
        output << "\n\n\n";
        for (int count = 0; count < numUniqueWords; count++) {
            output << uniqueWords[count] << " ";
        }
        output.close();
    }
    else cout << "Unable to create file";
}
