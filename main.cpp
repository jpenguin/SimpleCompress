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
#include "Compress.h"

using std::cin;
using std::cout;
using std::ifstream;

int main()
{
    Compress file;                // Create instance of the compression class
    string uniqueWords[1000];                        // hold unique word list
    int wordOccurrences[1000];            // hold numbers for compressed file
    int numUniqueWords = 0, numWords = 0;
    char choice;

    ifstream toCompress;
    do {
        cout
            << "Which file?\n"
               "\t(1) Short Test\n\t(2) One, Two, Three\n\t(3) Mr. Bojangles\n";
        cin >> choice;
        switch (choice) {
            case '1':
                toCompress.open("input.txt");           // short test file
                break;
            case '2':
                toCompress.open("sample.txt");        // 1, 2 & 3 repeated
                break;
            case '3':
                toCompress.open("lyrics.txt"); // song lyrics to test with
                break;
            default:
                choice = 'n';
        }
    } while (!toCompress || choice == 'n');

    // Pass variables as pointers, so original values are change.
    // Arrays are already pointers
    file.GetData(
        toCompress, uniqueWords, &numUniqueWords, wordOccurrences, &numWords);
    file.Write(uniqueWords, numUniqueWords, wordOccurrences, numWords);

    return 0;
}
