#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

void clearArray(int a[], int b, string out[]);
void writeArray(int a[], int b, string out[], int index, bool underscore);
int howMany1s(string binaryV, int bits);
//void printArray(string arr[], int bits);

ofstream out("testvects.txt");
ofstream outputfile("expected.txt");

int main(int argc, char * argv[])
{
    int bits = 0;
    bool underscore = false;
    if(argc < 2) //which means only ./a.out is on the command line
    {
        cout << "usage: ./a.out numberOfBits -u/underscore" << endl;
        return 0;
    }
    else
    {
        bits = atoi(argv[1]);
        string s1 = "";
        if(argc > 2)  s1 = argv[2];

        if(s1 == "-u" || s1 == "-underscore")
            underscore = true;
    }

    int index = 0; 
    int bitArray[bits];
    
    int temp = 0;
    int end = pow(2, bits);
    string outArray[end];

    clearArray(bitArray, bits, outArray);

    for(int i = 0; i < end; i++)
    {
        //cout << i << endl;
        
        if(i == 0)
            writeArray(bitArray, bits, outArray,i, underscore);

        else
        {
            temp = i;
            do
            {
                //cout << "i: " << i << " %2 = " << temp %2 << endl;
                bitArray[index] = temp % 2;
                temp = temp / 2;
                index++;
            } while (temp > 0);

            writeArray(bitArray, bits, outArray, i, underscore);
            clearArray(bitArray, bits, outArray);
            index = 0;
        }
    }
}

void writeArray(int  arr[], int bits, string outt[], int index, bool under)
{
    string binary = "";
    int ones = 0;

    for(int i = bits-1; i >= 0; i--)
    {
        binary += to_string(arr[i]);
        
    }
    howMany1s(binary, bits);
    //cout << binary << endl;
    outt[index] = binary;

    if(under)
        out << outt[index] << " " << endl; 
    else
        out << outt[index] << endl;
}

void clearArray(int  arr[], int bits, string out[])
{
    for(int i = 0; i < bits; i++)
    {
        arr[i] = 0;
    }

    for(int i = 0; i < (2^bits); i++)
        out[i] = "";
}

int howMany1s(string binaryV, int bits){
    int oneCounter = 0;
    for(int i = 0; i < bits; i++){
        if(binaryV[i] == '1'){
            oneCounter++;
        }
    }
    outputfile << oneCounter << endl;
    return oneCounter;
}