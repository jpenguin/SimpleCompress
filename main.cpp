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

/*******************************************************************************
 * Function Name: main()
 * Parameters: None
 * Return Value: int
 * Purpose: Chose file and call compression functions
 *******************************************************************************/
int main()
{
    string uniqueWords[1000]; // hold unique word list
    string filename; // Name of chosen file
    int wordOccurrences[1000]; // hold numbers for compressed file
    int numUniqueWords = 0, numWords = 0;
    char choice;

    ifstream toCompress;
    do {
        cout << "Which file?\n\t(1) ECL License\n\t(2) One, Two, Three\n\t(3) "
                "Mr. Bojangles\n\t(4) Exit\n";
        cin >> choice;
        switch (choice) {
        case '1':
            filename = "LICENSE.txt"; // ECL-2.0
            break;
        case '2':
            filename = "sample.txt"; // 1, 2 & 3 repeated
            break;
        case '3':
            filename = "lyrics.txt"; // song lyrics to test with
            break;
        case '4':
            return 0;
        default:
            cout << "\nInvalid Choice\a\nTry again...";
            choice = 'n';
        }
        toCompress.open(filename);
        if (!toCompress)
            cout << "\nFile not found\a\nTry again...";
    } while (!toCompress || choice == 'n');

    try {
        // Pass variables as pointers, so original values are changed.
        // Arrays are already pointers
        Compress::GetData(toCompress, uniqueWords, &numUniqueWords,
                          wordOccurrences, &numWords);
        Compress::Write(uniqueWords, numUniqueWords, wordOccurrences, numWords);
    } catch (...) { // Catch all exceptions
        cout << "\aAn error occurred";
    }

    return 0;
}
