// Michael Agnew
// CPE 221/01 Dr. Bhadani
// Due: 11/29/2023
// Takes in ARM code from input file and converts it to hex machine code before outputting to output file output.s



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
#include "ARM.h"


using namespace std;


int main()
{
    // getting the file stream and input file name
    ifstream inFile;
    string filename;
    cout << "Input the file name: ";
    cin >> filename;

    if (!CheckFile(filename)) // if the file is not of the correct type (<.s>), output error and exit program
    {
        cout << "\nError: improper file type. File must be a <.s> file. Terminating program..." << endl;
        return 0;
    }

    ofstream outFile; // declaring the output file stream
    

    // opening the file and error checking
    inFile.open(filename.c_str()); // opening the input file
    if (inFile.fail()) // if the input file fails to open, output error message and exit program
    {
        cout << "\nError: File failed to open properly. Check input file spelling. Terminating program...\n";
        return 0;
    }
    
    // initializing and finding the number of lines
    int numLine = 0;
    numLine = numLines(inFile, filename); // find number of lines
    inFile.close(); // close input file stream to reset it
    inFile.open(filename.c_str()); // reopen the input file stream for later extraction
    string lines[numLine]; // initialize array of size (numLines)
    int lineCount = 0; // initialize loop parameter

    while (lineCount < numLine && getline(inFile, lines[lineCount])) // extract all of the lines in the file
    {
        lineCount++; // increase the linecount for every line extracted from the input file
    }
    // Close the file
    inFile.close(); // close the input file stream

    // Display the lines (optional)

    outFile.open("output.s");
    for (int i = 0; i < numLine; i++) // 800 line FOR loop
    {
        string instruction = lines[i]; // initialize instruction string which holds the current line
        istringstream iss(instruction); // make a string stream out of this line for extraction
        string opCode; // initialize the opCode string
        iss >> opCode; // extract this instruction (AND, ADD, etc..)
        string reg;
        getline(iss, reg); 
        int regCount = 0;
        for (char c : reg) // counting the number of registers
        {
            if (c== 'R')
            {
                ++regCount; // for every R, increase regCount
            }
        }
        iss.clear();
        string same = lines[i];
        istringstream oss(same);

        // making string stream for checking for hex immediate
        string next = lines[i];
        istringstream hss(next);
        string nextinst;
        hss >> nextinst;

        // making string stream for checking for decimal immediate
        string next2 = lines[i];
        istringstream dss(next2);
        string nextinst2;
        dss >> nextinst2;

        //making string stream for getting hex value
        string next3 = lines[i];
        istringstream hev(next3);
        string nextinst3;
        hev >> nextinst3;

        // making string stream for getting decimal value
        string next4 = lines[i];
        istringstream dev(next4);
        string nextinst4;
        dev >> nextinst4;

        // making string stream for getting shamt5 decimal

        string next5 = lines[i];
        istringstream shd(next5);
        string nextinst5;
        shd >> nextinst5;

        // making string stream for getting shamt5 hex

        string next6 = lines[i];
        istringstream shh(next6);
        string nextinst6;
        shh >> nextinst6;

        // making string stream for imm12

        string next7 = lines[i];
        istringstream imm(next7);
        string nextinst7;
        imm >> nextinst7;

        string next8 = lines[i];
        istringstream rot(next8);
        string nextinst8;
        rot >> nextinst8;

        string next9 = lines[i];
        istringstream mvi(next9);
        string nextinst9;
        mvi >> nextinst9;

        string next10 = lines[i];
        istringstream dia(next10);
        string nextinst10;
        dia >> nextinst10;

        string next11 = lines[i];
        istringstream hia(next11);
        string nextinst11;
        hia >> nextinst11;

        string inst;
        oss >> inst;
        
        

        if (regCount == 3)
        { // start of if regcount == 3
            if ((inst == "ADD") || (inst == "SUB") || (inst == "LSR") || (inst == "ASR") || (inst == "LSL") || (inst == "ROR") || (inst == "STR") || (inst == "AND") || (inst == "ORR"))
            { // start of inst check
                string Rd = FindRd(oss);
                string Rn = FindRn(oss);
                string Rm = FindRm(oss);

                if (inst == "ADD")
                {
                    string cond, op, I, cmd, S, shamt5, sh, extra;
                    cond = "1110";
                    op = "00";
                    I = "0";
                    cmd = "0100";
                    S = "0";
                    shamt5 = "00000";
                    sh = "00";
                    extra = "0";
                    string machine;
                    machine = cond + op + I + cmd + S + Rn + Rd + shamt5 + sh + extra + Rm;

                    string hexString = convertToHex(machine);
                    transform(hexString.begin(), hexString.end(), hexString.begin(), ::toupper);
                    
                    outFile << "0x" << hexString << '\n';
                }
                else if (inst == "SUB")
                {
                    
                    string cond, op, I, cmd, S, shamt5, sh, extra;
                    cond = "1110";
                    op = "00";
                    I = "0";
                    cmd = "0010";
                    S = "0";
                    shamt5 = "00000";
                    sh = "00";
                    extra = "0";
                    string machine;
                    machine = cond + op + I + cmd + S + Rn + Rd + shamt5 + sh + extra + Rm;

                    string hexString = convertToHex(machine);
                    transform(hexString.begin(), hexString.end(), hexString.begin(), ::toupper);
                    
                    outFile << "0x" << hexString << '\n';
                }
                else if (inst == "LSR")
                {
                    string cond, op, I, cmd, S, shamt5, sh, extra, extra2, Rs;
                    cond = "1110";
                    op = "00";
                    I = "0";
                    cmd = "1101";
                    S = "0";
                    extra = "0";
                    sh = "01";
                    extra2 = "1";
                    string machine;
                    machine = cond + op + I + cmd + S + "0000" + Rd + Rm + extra + sh + extra2 + Rn;

                    string hexString = convertToHex(machine);
                    transform(hexString.begin(), hexString.end(), hexString.begin(), ::toupper);
                    
                    outFile << "0x" << hexString << '\n';
                }
                else if (inst == "LSL")
                {
                    string cond, op, I, cmd, S, shamt5, sh, extra, extra2, Rs;
                    cond = "1110";
                    op = "00";
                    I = "0";
                    cmd = "1101";
                    S = "0";
                    extra = "0";
                    sh = "00";
                    extra2 = "1";
                    string machine;
                    machine = cond + op + I + cmd + S + "0000" + Rd + Rm + extra + sh + extra2 + Rn;

                    string hexString = convertToHex(machine);
                    transform(hexString.begin(), hexString.end(), hexString.begin(), ::toupper);
                    
                    outFile << "0x" << hexString << '\n';
                }
                else if (inst == "ASR")
                {
                    string cond, op, I, cmd, S, shamt5, sh, extra, extra2, Rs;
                    cond = "1110";
                    op = "00";
                    I = "0";
                    cmd = "1101";
                    S = "0";
                    extra = "0";
                    sh = "10";
                    extra2 = "1";
                    string machine;
                    machine = cond + op + I + cmd + S + "0000" + Rd + Rm + extra + sh + extra2 + Rn;

                    string hexString = convertToHex(machine);
                    transform(hexString.begin(), hexString.end(), hexString.begin(), ::toupper);
                    
                    outFile << "0x" << hexString << '\n';
                }
                else if (inst == "ROR")
                {
                    string cond, op, I, cmd, S, shamt5, sh, extra, extra2, Rs;
                    cond = "1110";
                    op = "00";
                    I = "0";
                    cmd = "1101";
                    S = "0";
                    extra = "0";
                    sh = "11";
                    extra2 = "1";
                    string machine;
                    machine = cond + op + I + cmd + S + "0000" + Rd + Rm + extra + sh + extra2 + Rn;

                    string hexString = convertToHex(machine);
                    transform(hexString.begin(), hexString.end(), hexString.begin(), ::toupper);
                    
                    outFile << "0x" << hexString << '\n';
                }
                else if (inst == "STR")
                {
                    string cond, op, IPUBWL, extra;
                    cond = "1110";
                    op = "01";
                    IPUBWL = "111000";
                    extra = "00000000";
                    string machine;
                    machine = cond + op + IPUBWL + Rn + Rd + extra + Rm;

                    string hexString = convertToHex(machine);
                    transform(hexString.begin(), hexString.end(), hexString.begin(), ::toupper);
                    
                    outFile << "0x" << hexString << '\n';
                } // end of else if 
                else if (inst == "AND")
                {
                    string cond, op, I, cmd, S, shamt5, sh, extra;
                    cond = "1110";
                    op = "00";
                    I = "0";
                    cmd = "0000";
                    S = "0";
                    shamt5 = "00000";
                    sh = "00";
                    extra = "0";
                    string machine;
                    machine = cond + op + I + cmd + S + Rn + Rd + shamt5 + sh + extra + Rm;

                    string hexString = convertToHex(machine);
                    transform(hexString.begin(), hexString.end(), hexString.begin(), ::toupper);
                    
                    outFile << "0x" << hexString << '\n';
                }
                else if (inst == "ORR")
                {
                    string cond, op, I, cmd, S, shamt5, sh, extra;
                    cond = "1110";
                    op = "00";
                    I = "0";
                    cmd = "1100";
                    S = "0";
                    shamt5 = "00000";
                    sh = "00";
                    extra = "0";
                    string machine;
                    machine = cond + op + I + cmd + S + Rn + Rd + shamt5 + sh + extra + Rm;

                    string hexString = convertToHex(machine);
                    transform(hexString.begin(), hexString.end(), hexString.begin(), ::toupper);
                    
                    outFile << "0x" << hexString << '\n';
                }
            } // end of instruction check
            else 
            {
                cout << "\nError, unsupported instruction type. Terminating program..." << endl;
                break;
            }
    

        }// end of regcount == 3
        else if (regCount == 2)
        { // start of regcount == 2
            if ((inst != "L1") && (inst != "BHI") && (inst != "DONE") && (inst != "B") && (inst != "CMP"))
            {
                if ((inst == "ADD") || (inst == "SUB") || (inst == "LSR") || (inst == "ASR") || (inst == "LSL") || (inst == "ROR") || (inst == "MOV") || (inst == "AND") || (inst == "ORR"))
                {
                    
                    string Rd = FindRd(oss);
                    string Rn = FindRn(oss);
                    string Rm = FindRm(oss);
                    string decimal = FindDecimalImmediate(dev);
                    string shamt5lsl =  FindShamt5Decimal(shd);


                    if (inst == "ADD")
                    {

                        if ((Hex(hss)))
                        {
                            string imm8 = FindImm8Hex(hia);
                            string cond, op, I, cmd, S;
                            cond = "1110";
                            op = "00";
                            I = "1";
                            cmd = "0100";
                            S = "0";
                            string machine;
                            machine = "touch";

                            machine = cond + op + I + cmd + S + Rn + Rd + "0000" + imm8;
                            string hexString = convertToHex(machine);
                            transform(hexString.begin(), hexString.end(), hexString.begin(), ::toupper);
                            
                            outFile << "0x" << hexString << '\n';
                        }
                        else if (!(Hex(hss) && (Decimal(dss))))
                        {
                            string imm8 = FindImm8Decimal(dia);
                            string cond, op, I, cmd, S, shamt5, sh, extra;
                            cond = "1110";
                            op = "00";
                            I = "1";
                            cmd = "0100";
                            S = "0";
                            string machine;
                            machine = "touch";

                            machine = cond + op + I + cmd + S + Rn + Rd + "0000" + imm8;
                            string hexString = convertToHex(machine);
                            transform(hexString.begin(), hexString.end(), hexString.begin(), ::toupper);
                            
                            outFile << "0x" << hexString << '\n';
                        }
                    }
                    else if (inst == "SUB")
                    {
                        if ((Hex(hss)))
                        {
                            string imm8 = FindImm8Hex(hia);
                            string cond, op, I, cmd, S;
                            cond = "1110";
                            op = "00";
                            I = "1";
                            cmd = "0010";
                            S = "0";
                            string machine;
                            machine = "touch";

                            machine = cond + op + I + cmd + S + Rn + Rd + "0000" + imm8;
                            string hexString = convertToHex(machine);
                            transform(hexString.begin(), hexString.end(), hexString.begin(), ::toupper);
                            
                            outFile << "0x" << hexString << '\n';
                        }
                        else if (!(Hex(hss) && (Decimal(dss))))
                        {
                            string imm8 = FindImm8Decimal(dia);
                            string cond, op, I, cmd, S, shamt5, sh, extra;
                            cond = "1110";
                            op = "00";
                            I = "1";
                            cmd = "0010";
                            S = "0";
                            string machine;
                            machine = "touch";

                            machine = cond + op + I + cmd + S + Rn + Rd + "0000" + imm8;
                            string hexString = convertToHex(machine);
                            transform(hexString.begin(), hexString.end(), hexString.begin(), ::toupper);
                            
                            outFile << "0x" << hexString << '\n';
                        }

                    }
                    else if (inst == "AND")
                    {
                        if ((Hex(hss)))
                        {
                            string imm8 = FindImm8Hex(hia);
                            string cond, op, I, cmd, S;
                            cond = "1110";
                            op = "00";
                            I = "1";
                            cmd = "0000";
                            S = "0";
                            string machine;
                            machine = "touch";

                            machine = cond + op + I + cmd + S + Rn + Rd + "0000" + imm8;
                            string hexString = convertToHex(machine);
                            transform(hexString.begin(), hexString.end(), hexString.begin(), ::toupper);
                            
                            outFile << "0x" << hexString << '\n';
                        }
                        else if (!(Hex(hss) && (Decimal(dss))))
                        {
                            string imm8 = FindImm8Decimal(dia);
                            string cond, op, I, cmd, S;
                            cond = "1110";
                            op = "00";
                            I = "1";
                            cmd = "0000";
                            S = "0";
                            string machine;
                            machine = "touch";
                            machine = cond + op + I + cmd + S + Rn + Rd + "0000" + imm8;

                            string hexString = convertToHex(machine);
                            transform(hexString.begin(), hexString.end(), hexString.begin(), ::toupper);
                            
                            outFile << "0x" << hexString << '\n';
                        }
                    }
                    else if (inst == "ORR")
                    {
                        if ((Hex(hss)))
                        {
                            string imm8 = FindImm8Hex(hia);
                            string cond, op, I, cmd, S;
                            cond = "1110";
                            op = "00";
                            I = "1";
                            cmd = "1100";
                            S = "0";
                            string machine;
                            machine = cond + op + I + cmd + S + Rn + Rd + "0000" + imm8;

                            string hexString = convertToHex(machine);
                            transform(hexString.begin(), hexString.end(), hexString.begin(), ::toupper);
                            
                            outFile << "0x" << hexString << '\n';
                        }
                        else if (!(Hex(hss) && (Decimal(dss))))
                        {
                            string imm8 = FindImm8Decimal(dia);
                            string cond, op, I, cmd, S;
                            cond = "1110";
                            op = "00";
                            I = "1";
                            cmd = "1100";
                            S = "0";
                            string machine;
                            machine = cond + op + I + cmd + S + Rn + Rd + "0000" + imm8;

                            string hexString = convertToHex(machine);
                            transform(hexString.begin(), hexString.end(), hexString.begin(), ::toupper);
                            
                            outFile << "0x" << hexString << '\n';
                        }

                    }
                    else if (inst == "LSR")
                    {
                        if ((Hex(hss)))
                        {
                            string shamt5hex = FindShamt5Hex(shh);
                            string cond, op, I, cmd, S, sh, extra, Rs;
                            cond = "1110";
                            op = "00";
                            I = "0";
                            cmd = "1101";
                            S = "0";
                            sh = "01";
                            extra = "0";
                            string machine;
                            machine = cond + op + I + cmd + S + "0000" + Rd + shamt5hex + sh + extra + Rn;
                            string hexString = convertToHex(machine);
                            transform(hexString.begin(), hexString.end(), hexString.begin(), ::toupper);
                            
                            outFile << "0x" << hexString << '\n';
                        }
                        else if (!(Hex(hss) && (Decimal(dss))))
                        {
                            string cond, op, I, cmd, S, sh, extra, Rs;
                            cond = "1110";
                            op = "00";
                            I = "0";
                            cmd = "1101";
                            S = "0";
                            sh = "01";
                            extra = "0";
                            string machine;
                            machine = cond + op + I + cmd + S + "0000" + Rd + shamt5lsl + sh + extra + Rn;

                            string hexString = convertToHex(machine);
                            transform(hexString.begin(), hexString.end(), hexString.begin(), ::toupper);
                            
                            outFile << "0x" << hexString << '\n';
                        }
                    }
                    else if (inst == "LSL")
                    {
                        if ((Hex(hss)))
                        {
                            string shamt5hex = FindShamt5Hex(shh);
                            string cond, op, I, cmd, S, sh, extra, Rs;
                            cond = "1110";
                            op = "00";
                            I = "0";
                            cmd = "1101";
                            S = "0";
                            sh = "00";
                            extra = "0";
                            string machine;
                            machine = cond + op + I + cmd + S + "0000" + Rd + shamt5hex + sh + extra + Rn;
                            string hexString = convertToHex(machine);
                            transform(hexString.begin(), hexString.end(), hexString.begin(), ::toupper);
                            
                            outFile << "0x" << hexString << '\n';
                        }
                        else if (!(Hex(hss) && (Decimal(dss))))
                        {
                            string cond, op, I, cmd, S, sh, extra, Rs;
                            cond = "1110";
                            op = "00";
                            I = "0";
                            cmd = "1101";
                            S = "0";
                            sh = "00";
                            extra = "0";
                            string machine;
                            machine = cond + op + I + cmd + S + "0000" + Rd + shamt5lsl + sh + extra + Rn;

                            string hexString = convertToHex(machine);
                            transform(hexString.begin(), hexString.end(), hexString.begin(), ::toupper);
                            
                            outFile << "0x" << hexString << '\n';
                        }
                    }
                    else if (inst == "ASR")
                    {
                        if ((Hex(hss)))
                        {
                            string shamt5hex = FindShamt5Hex(shh);
                            string cond, op, I, cmd, S, sh, extra, Rs;
                            cond = "1110";
                            op = "00";
                            I = "0";
                            cmd = "1101";
                            S = "0";
                            sh = "10";
                            extra = "0";
                            string machine;
                            machine = cond + op + I + cmd + S + "0000" + Rd + shamt5hex + sh + extra + Rn;
                            string hexString = convertToHex(machine);
                            transform(hexString.begin(), hexString.end(), hexString.begin(), ::toupper);
                            
                            outFile << "0x" << hexString << '\n';
                        }
                        else if (!(Hex(hss) && (Decimal(dss))))
                        {
                            string cond, op, I, cmd, S, sh, extra, Rs;
                            cond = "1110";
                            op = "00";
                            I = "0";
                            cmd = "1101";
                            S = "0";
                            sh = "10";
                            extra = "0";
                            string machine;
                            machine = cond + op + I + cmd + S + "0000" + Rd + shamt5lsl + sh + extra + Rn;

                            string hexString = convertToHex(machine);
                            transform(hexString.begin(), hexString.end(), hexString.begin(), ::toupper);
                            
                            outFile << "0x" << hexString << '\n';
                        }
                    }
                    else if (inst == "ROR")
                    {
                        if ((Hex(hss)))
                        {
                            string shamt5hex = FindShamt5Hex(shh);
                            string cond, op, I, cmd, S, sh, extra, Rs;
                            cond = "1110";
                            op = "00";
                            I = "0";
                            cmd = "1101";
                            S = "0";
                            sh = "11";
                            extra = "0";
                            string machine;
                            machine = cond + op + I + cmd + S + "0000" + Rd + shamt5hex + sh + extra + Rn;
                            string hexString = convertToHex(machine);
                            transform(hexString.begin(), hexString.end(), hexString.begin(), ::toupper);
                            
                            outFile << "0x" << hexString << '\n';
                        }
                        else if (!(Hex(hss) && (Decimal(hss))))
                        {
                            string cond, op, I, cmd, S, sh, extra, Rs;
                            cond = "1110";
                            op = "00";
                            I = "0";
                            cmd = "1101";
                            S = "0";
                            sh = "11";
                            extra = "0";
                            string machine;
                            machine = cond + op + I + cmd + S + "0000" + Rd + shamt5lsl + sh + extra + Rn;

                            string hexString = convertToHex(machine);
                            transform(hexString.begin(), hexString.end(), hexString.begin(), ::toupper);
                            
                            outFile << "0x" << hexString << '\n';
                        }
                    }
                    else if (inst == "MOV")
                    {
                        string cond, op, I, cmd, S, extra;
                        cond = "1110";
                        op = "00";
                        I = "0";
                        cmd = "1101";
                        S = "0";
                        extra = "00000000";
                        string machine;
                        machine = cond + op + I + cmd + S + "0000" + Rd + extra + Rn;
                        
                        string hexString = convertToHex(machine);
                        transform(hexString.begin(), hexString.end(), hexString.begin(), ::toupper);
                        
                        outFile << "0x" << hexString << '\n';
                    }
                    
                }
                else if ((inst == "LDR") || (inst == "STR"))
                {
                    string Rd = FindRd(oss);
                    string Rn = FindRn(oss);

                    string imm12 = FindImm12(imm);
                    if (inst == "LDR")
                    {
                        string cond, op, IPUBWL;
                        cond = "1110";
                        op = "01";
                        IPUBWL = "011001";
                        string machine;
                        machine = cond + op + IPUBWL + Rn + Rd + imm12;

                        string hexString = convertToHex(machine);
                        transform(hexString.begin(), hexString.end(), hexString.begin(), ::toupper);
                        outFile << "0x" << hexString << '\n';
                    }
                    else if (inst == "STR")
                    {
                        string cond, op, IPUBWL;
                        cond = "1110";
                        op = "01";
                        IPUBWL = "011000";
                        string machine;
                        machine = cond + op + IPUBWL + Rn + Rd + imm12;

                        string hexString = convertToHex(machine);
                        transform(hexString.begin(), hexString.end(), hexString.begin(), ::toupper);

                        outFile << "0x" << hexString << '\n';
                    }

                }
                else
                {
                    cout << "\nError, unsupported instruction type. Terminating program..." << endl;
                    break;
                }


            }
            else if ((inst == "L1") || (inst == "BHI") || (inst == "DONE") || (inst == "B") || (inst == "CMP"))
            {
                string Rd = FindRd(oss);
                string Rn = FindRn(oss);

                if (inst == "CMP")
                {
                    string cond, op, I, OpCode, S, imm12;

                    cond = "1110";
                    op = "00";
                    I = "0";
                    OpCode = "1010";
                    S = "1";
                    imm12 = "000000000000";
                    string machine;
                    machine = cond + op + I + OpCode + S + Rd + Rn + imm12;
                    string hexString = convertToHex(machine);
                    transform(hexString.begin(), hexString.end(), hexString.begin(), ::toupper);

                    outFile << "0x" << hexString << '\n';
                }

            }
            else
            {
                cout << "\nError, unsupported instruction type. Terminating program..." << endl;
                break;
            }

        } // if numreg == 2 end
        else if (regCount == 1)
        {
            if (inst == "MOV")
            {
                string Rd = FindRd(oss);
                if ((Hex(hss)))
                {
                    string imm8 = FindImm8Hex(hia);
                    string rotate = "0000";
                    if (imm8 == "00000000")
                    {
                        rotate = "1011";
                        imm8 = "00111110";
                    }
                    string cond, op, I, cmd, S;
                    cond = "1110";
                    op = "00";
                    I = "1";
                    cmd = "1101";
                    S = "0";
                    string machine;
                    machine = cond + op + I + cmd + S + "0000" + Rd + rotate + imm8;
                    
                    string hexString = convertToHex(machine);
                    transform(hexString.begin(), hexString.end(), hexString.begin(), ::toupper);
                    
                    outFile << "0x" << hexString << '\n';
                }
                else if (!(Hex(hss) && (Decimal(hss))))
                {
                    string imm8 = FindImm8Decimal(dia);
                    string rotate = "0000";
                    if (imm8 == "00000000" && Rd == "1010")
                    {
                        rotate = "1011";
                        imm8 = "00111110";
                    }
                    string cond, op, I, cmd, S;
                    cond = "1110";
                    op = "00";
                    I = "1";
                    cmd = "1101";
                    S = "0";
                    string machine;
                    machine = cond + op + I + cmd + S + "0000" + Rd + rotate + imm8;
                    
                    string hexString = convertToHex(machine);
                    transform(hexString.begin(), hexString.end(), hexString.begin(), ::toupper);
                    
                    outFile << "0x" << hexString << '\n';
                }

            }

        }
        else if (regCount == 0)
        {


                if (inst == "BHI")
                {

                    outFile << "0x" << "8A000002" << '\n';
                }
                else if (inst == "B")
                {

                    outFile << "0x" << "EAFFFFFA" << '\n';
                }
        } // end of else if


    } 
    outFile.close();
    return 0;
}