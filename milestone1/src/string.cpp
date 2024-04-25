#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(int argc, char *argv[] ) {
    // Prompt the user to enter the input filename
    
    string inputFilename;
    inputFilename=argv[1];

    // Open the input file
    ifstream inputFile(inputFilename);

    // Check if the input file is opened successfully
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open input file " << inputFilename << endl;
        return 1;
    }

    // Read the contents of the input file into a string
    string fileContents;
    string line;
    while (getline(inputFile, line)) {
        fileContents += line + "\n";
             // Append each line to the fileContents string
    }
    string modifiedString;
    char prev=' ';
    int c=0;
    for (char ch : fileContents) {
        if (ch == '"'&&prev=='('&&!c) {
            modifiedString += '\\';
            c=1;
        }else if(ch == '"'&&c){
            modifiedString += '\\';
            c=0;
        }
        modifiedString += ch;
        prev=ch;
    }
    
    

    // Close the input file
    inputFile.close();

    // Prompt the user to enter the output filename
    string outputFilename;
    outputFilename=argv[2];

    // Open the output file
    ofstream outputFile(outputFilename);

    // Check if the output file is opened successfully
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open output file " << outputFilename << endl;
        return 1;
    }

    // Write the contents of the string to the output file
    outputFile << modifiedString;

    // Close the output file
    outputFile.close();

    return 0;
}