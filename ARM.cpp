// Michael Agnew
// Due: 11/29/2023
// Takes in ARM code from input file and converts it to hex machine code before outputting to output file output.s

#include <iostream> // for standard use
#include <iomanip> // for output manipulation, unused for the most part because output is simply to a file
#include <cmath> // for standard math operations
#include <climits> // for INT_MAX
#include <fstream> // for input/output file streams 
#include <string> // for various string-related functions and operations
#include <sstream> // for string stream (literally a saving grace)
#include <bitset> // for controlling bitset of binary numbers
#include <cstdlib> // for standard C++ operations and functions 
#include <algorithm> // for transform, toupper
#include "ARM.h" // including the header file which have function prototypes

using namespace std; // for cin, cout, etc

/*========== REGISTER OBTAINING FUNCTIONS ============*/

/*========== DISCLAIMER: FindRn and FindRm ARE EXACTLY THE SAME AS FindRd JUST 
WITH SLIGHTLY DIFFERENT VARIABLE NAMES =============*/


string FindRd(istringstream &oss)
{ // start of destination register function

    
        
        oss.ignore(INT_MAX, 'R'); // ignore up to R
        int regNum; // initialize the number of Rd
        oss >> regNum; // extract the register number from the string stream


        int binaryNum[4]; // initialize array for Rd
    
        // Counter for binary array
        for (int i = 3; i >= 0; --i) 
        {
            binaryNum[i] = regNum % 2; // convert the value of the register to binary
            regNum /= 2; 
        }
        for (int i = 0; i < 4; i++)
        {
            if (binaryNum[i] != 1) // put the binary number into the right order
            {
                binaryNum[i] = 0;
            }
        }


        string result = "";
        string str; // intialize string to store the value 
        for (int i: binaryNum)
        {
            str += to_string(i); // convert the values to string for combination later
        }

        string Rd = str;
        return Rd; // return Rd 

    
} // end of destination register function

string FindRn(istringstream &oss)
{ // start of destination register function

    
        
        oss.ignore(INT_MAX, 'R'); // ignore up to R
        int regNum; // initialize the number of Rd
        oss >> regNum;


        int binaryNum[4]; // initialize array for Rd
    
        // Counter for binary array
        for (int i = 3; i >= 0; --i) 
        {
            binaryNum[i] = regNum % 2; // convert the value of the register to binary
            regNum /= 2;
        }
        for (int i = 0; i < 4; i++)
        {
            if (binaryNum[i] != 1)
            {
                binaryNum[i] = 0;
            }
        }


        string result = "";
        string str;
        for (int i: binaryNum)
        {
            str += to_string(i); // convert the values to string for combination later
        }

        string Rn = str;
        return Rn; // return Rn 

    
} // end of destination register function

string FindRm(istringstream &oss)
{ // start of destination register function

    
        
        oss.ignore(INT_MAX, 'R'); // ignore up to R
        int regNum; // initialize the number of Rd
        oss >> regNum;


        int binaryNum[4]; // initialize array for Rd
    
        // Counter for binary array
        for (int i = 3; i >= 0; --i) 
        {
            binaryNum[i] = regNum % 2; // convert the value of the register to binary
            regNum /= 2;
        }
        for (int i = 0; i < 4; i++)
        {
            if (binaryNum[i] != 1)
            {
                binaryNum[i] = 0;
            }
        }


        string result = "";
        string str;
        for (int i: binaryNum)
        {
            str += to_string(i); // convert the values to string for combination later
        }

        string Rm = str;
        return Rm; // return Rm 

    
} // end of destination register function


/*================== FILE READING FUNCTIONS =====================*/

int numLines(ifstream &inFile, string filename) // takes in input file stream and filename for processing
{

    int linecount = 0; // initialize the number of lines to 0
    string line; // intialize the string to hold line
    while (getline(inFile, line)) // while there are lines to be extracted from the file, extract them
    {
        linecount++; // for every line extracted, increment the number of lines
    }

    return linecount; // return the number of lines to main
}

bool CheckFile(string &filename) // takes in the name of the input file as a parameter
{

    return (filename.find(".s") != string::npos); // returns true if ".s" is found in the file, false otherwise
}


/*================== LINE READING FUNCTIONS ======================*/

bool Hex(istringstream &hss) // takes in a string stream contaning a line as input
{
    string line; // intialize string variable to hold the line
    getline(hss, line); // extract the line from the filestream
    return (line.find('x') != string::npos); // return true if 'x' is found, false otherwise

}

bool Decimal(istringstream &dss) // takes in a string stream contaning a line as input
{
    string line; // initialize string variable to hold the line
    getline(dss, line); // extract the line from the filestream 
    return ((line.find('#') != string::npos)); // return true if '#' is found, false otherwise

}


/*======================= IMMEDIATE PROCESSING FUNCTIONS =========================*/

/*===== DISCLAIMER: FindHexImmediate and FindDecimalImmediate ARE THE ONLY FUNCTIONS IN THIS
SECTION THAT DO ANYTHING UNIQUE, THE OTHER FUNCTIONS ARE EXACTLY THE SAME BUT WITH DIFFERENT BITSETS =====*/

string FindHexImmediate(istringstream &hev) // takes in a string stream contaning a line as input
{

    hev.ignore(INT_MAX, 'x'); // ignore the line up to 'x' 

    string hexImm; // intialize string to hold hexadecimal value
    hev >> hexImm; // extract the hex value into string
    // now let's convert it into binary

    unsigned int decimalValue; // initialize a decimal value
    stringstream ss; // initialize a string stream
    ss << hex << hexImm; // convert the immediate
    ss >> decimalValue; // extract from string stream into decimal value

    bitset<8> binaryValue(decimalValue); // change the decimal value to binary and set a bitset of 8
    string binvalue = bitset<8>(decimalValue).to_string(); // convert this binary value to string

    return binvalue; // return this string 

}

string FindDecimalImmediate(istringstream &dev) // takes in a string stream contaning a line as input
{

    dev.ignore(INT_MAX, '#'); // ignore the line up to '#'
    int decimal; // intialize decimal int
    dev >> decimal; // extract int into decimal

    bitset<8> binaryNumber = bitset<8>(decimal); // convert the decimal number to binary with bitset of 8

    string binvalue = bitset<8>(decimal).to_string(); // convert this into a string
    
    return binvalue; // return the string binary number
}

string FindShamt5Decimal(istringstream &shd)
{


    shd.ignore(INT_MAX, '#');
    int decimal;
    shd >> decimal;

    bitset<5> binaryNumber = bitset<5>(decimal);

    string binvalue = bitset<5>(decimal).to_string();
    
    return binvalue;
}

string FindShamt5Hex(istringstream &shh)
{

    shh.ignore(INT_MAX, 'x');

    string hexImm;
    shh >> hexImm;
    // now let's convert it into binary

    unsigned int decimalValue;
    stringstream ss;
    ss << hex << hexImm;
    ss >> decimalValue;

    bitset<5> binaryValue(decimalValue);
    string binvalue = bitset<5>(decimalValue).to_string();
    // Display the result    
    return binvalue;

}

string FindImm12(istringstream &imm)
{

    imm.ignore(INT_MAX, '#');
    int decimal;
    imm >> decimal;

    bitset<12> binaryNumber = bitset<12>(decimal);

    string binvalue = bitset<12>(decimal).to_string();
    
    return binvalue;
}

string FindImm8Decimal(istringstream &dia)
{


    dia.ignore(INT_MAX, '#');
    int decimal;
    dia >> decimal;

    bitset<8> binaryNumber = bitset<8>(decimal);

    string binvalue = bitset<8>(decimal).to_string();
    
    return binvalue;
}

string FindImm8Hex(istringstream &hia)
{

    hia.ignore(INT_MAX, 'x');

    string hexImm;
    hia >> hexImm;
    // now let's convert it into binary

    unsigned int decimalValue;
    stringstream ss;
    ss << hex << hexImm;
    ss >> decimalValue;

    bitset<8> binaryValue(decimalValue);
    string binvalue = bitset<8>(decimalValue).to_string();
    // Display the result    
    return binvalue;

}


/*================ BASE CONVERSION FUNCTIONS ====================*/

string convertToHex(const string& machine) // takes in a string of binary machine code as input
{
    bitset<32> bits(machine); // sets the input string to 32 bit 
    unsigned int decimalValue = bits.to_ulong(); // converts bitset to unsigned long int


    stringstream hexStream; // intialize string stream
    hexStream << hex << decimalValue; // convert to HEX 

    return (hexStream.str()); // return this hex code as a literal string
}



