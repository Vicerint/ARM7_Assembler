// Michael Agnew
// CPE 221/01
// Due: 11/29/2023
// Takes in ARM code from input file and converts it to hex machine code before outputting to output file output.s

#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <climits>
#include <fstream>
#include <string>
#include <sstream>
#include <bitset>
#include <cstdlib>
#include <algorithm>


using namespace std;


int numLines(ifstream &inFile, string filename); // counting the number of lines in the file

string FindRd(istringstream &oss); // obtains Rd

string FindRn(istringstream &oss); // obtains Rn

string FindRm(istringstream &oss); // obtains Rm

string convertToHex(const string& machine); // converts given string to HEX machine code

string FindHexImmediate(istringstream &hss); // finding the immediate if it's hex

string FindDecimalImmediate(istringstream &hss); // finding the immediate if it's decimal

bool Hex(istringstream &hss); // determining whether or not there are hex immediates in the line

bool Decimal(istringstream &dss); // determine whether or not there are decimal immediates in the line

// other extraneous functions of different bitsets for various immediates

string FindShamt5Decimal(istringstream &shd); 

string FindImm12(istringstream &imm);

string FindShamt5Hex(istringstream &shh);

string FindImm8Hex(istringstream &shh);

string FindImm8Decimal(istringstream &shd);

bool CheckFile(string &filename); // makes sure the file is of the correct type (<.s>)


#endif
