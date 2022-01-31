/*******************************************************************************
 * program name: cis65 programming assignment 1
 * created date: 1/30/22
 * created by: josh m dye
 * purpose: compress 1000 words in a plain text file, ignoring formatting
 * acknowledgements:
 * copyright 2022 josh m dye licensed under the
 * educational community license, version 2.0 (the "license"); you may
 * not use this file except in compliance with the license. you may
 * obtain a copy of the license at
 * http://www.osedu.org/licenses/ecl-2.0
 * unless required by applicable law or agreed to in writing,
 * software distributed under the license is distributed on an "as is"
 * basis, without warranties or conditions of any kind, either express
 * or implied. see the license for the specific language governing
 * permissions and limitations under the license.
 *******************************************************************************/
#include <string>
#include <iostream>
#include "Compress.h"

using std::string;
using std::cout;
using std::ifstream;
//using namespace std;

int main()
{
    string uniqueWords[1000];                             //hold unique word list
    int index;                                         //position of word in list
    int wordOccurrences[1000];                 //hold numbers for compressed file
    int numUniqueWords = 0, numWords = 0;
    string currentWord;
    bool found;

    ifstream toCompress;
    //toCompress.open("input.txt");                             //short test file
    toCompress.open("sample.txt");                           //1, 2 & 3 repeated
    //toCompress.open("lyrics.txt");                    //song lyrics to test with

    if (!toCompress) {
        cout << "file could not be opened.";
        return 1;
    }
    while (toCompress >> currentWord) {                //put next word into currentWord
        found = false;
        for (int i = 0; i <= numUniqueWords; i++) {
            if (uniqueWords[i] == currentWord) {
                found = true;                // set to true if currentWord found in list
                index = i;                              //set index to position found at
                break;                                         //if found, exit for loop
            }
        }
        if (!found) {
            uniqueWords[numUniqueWords] = currentWord;           //if not found, add to list
            index = numUniqueWords;                      //set index to lat position on list
            numUniqueWords++;                        //next unique word will go in next spot
        }
        wordOccurrences[numWords] = index;  //append position word was found or was placed at
        numWords++;                                              //increment total word count
    }
    Compress::write(uniqueWords, numUniqueWords, wordOccurrences, numWords);

    return 0;
}
