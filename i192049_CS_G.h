#pragma once
#include <string>
#include<iostream>
using namespace std;
//key tester functions
/*
These all functions are for the sake of GTESt all remaining function that you are going to use to implement the assignment must be made by yourself
otherwise all testcases will be faile.
Don't copy for internet i.e. geekforgeek, github and stackoverflow or by any other mean. And don't share with each other.
*/



string hexadecimal_to_binary(string hexadecimal)
{
    long int i = 0;
    string binary = "";
    while (hexadecimal[i]) {

        switch (hexadecimal[i]) {
        case '0':
            binary += "0000";
            break;
        case '1':
            binary += "0001";
            break;
        case '2':
            binary += "0010";
            break;
        case '3':
            binary += "0011";
            break;
        case '4':
            binary += "0100";
            break;
        case '5':
            binary += "0101";
            break;
        case '6':
            binary += "0110";
            break;
        case '7':
            binary += "0111";
            break;
        case '8':
            binary += "1000";
            break;
        case '9':
            binary += "1001";
            break;
        case 'A':
        case 'a':
            binary += "1010";
            break;
        case 'B':
        case 'b':
            binary += "1011";
            break;
        case 'C':
        case 'c':
            binary += "1100";
            break;
        case 'D':
        case 'd':
            binary += "1101";
            break;
        case 'E':
        case 'e':
            binary += "1110";

            break;
        case 'F':
        case 'f':
            binary += "1111";
            break;
        default:
            cout << "Invalid input "
                << hexadecimal[i];
        }
        i++;
    }
    return binary;
}

char* hexadecimal_to_binary_char(char hexadecimal[])
{
    long int i = 0;
    string binary_str = "";
    while (hexadecimal[i]) {

        switch (hexadecimal[i]) {
        case '0':
            binary_str += "0000";
            break;
        case '1':
            binary_str += "0001";
            break;
        case '2':
            binary_str += "0010";
            break;
        case '3':
            binary_str += "0011";
            break;
        case '4':
            binary_str += "0100";
            break;
        case '5':
            binary_str += "0101";
            break;
        case '6':
            binary_str += "0110";
            break;
        case '7':
            binary_str += "0111";
            break;
        case '8':
            binary_str += "1000";
            break;
        case '9':
            binary_str += "1001";
            break;
        case 'A':
        case 'a':
            binary_str += "1010";
            break;
        case 'B':
        case 'b':
            binary_str += "1011";
            break;
        case 'C':
        case 'c':
            binary_str += "1100";
            break;
        case 'D':
        case 'd':
            binary_str += "1101";
            break;
        case 'E':
        case 'e':
            binary_str += "1110";

            break;
        case 'F':
        case 'f':
            binary_str += "1111";
            break;
        default:
            cout << "Invalid input "
                << hexadecimal[i];
        }
        i++;
    }
    char *binary_arr =new char[binary_str.length()+1]; //s.length();
    strcpy(binary_arr, binary_str.c_str());
    return binary_arr;
}

template<typename T>
T initKeyPermutation(T key){
     //PC-1 table
    key = hexadecimal_to_binary(key);
    int PC_1[56] = { 57, 49, 41, 33, 25, 17, 9,
                     1, 58, 50, 42, 34, 26, 18,
                     10, 2, 59, 51, 43, 35, 27,
                     19, 11, 3, 60, 52, 44, 36,
                     63, 55, 47, 39, 31, 23, 15,
                     7, 62, 54, 46, 38, 30, 22,
                     14, 6, 61, 53, 45, 37, 29,
                     21, 13, 5, 28, 20, 12, 4 };

    string permutedKey = "";
    for (int i = 0; i < 56; i++) 
    {
        permutedKey += key[PC_1[i] - 1];    //array starts from zero and ends at n-1 
    }
    return permutedKey;
}

template <>
char* initKeyPermutation<char*>(char key[])//template specialization for char array
{
    key = hexadecimal_to_binary_char(key);
    int PC_1[56] = { 57, 49, 41, 33, 25, 17, 9,
                     1, 58, 50, 42, 34, 26, 18,
                     10, 2, 59, 51, 43, 35, 27,
                     19, 11, 3, 60, 52, 44, 36,
                     63, 55, 47, 39, 31, 23, 15,
                     7, 62, 54, 46, 38, 30, 22,
                     14, 6, 61, 53, 45, 37, 29,
                     21, 13, 5, 28, 20, 12, 4 };
    char permutedKey[56]="";
    for (int i = 0; i < 56; i++)
    {
        permutedKey [i] += key[PC_1[i] - 1];    //array starts from zero and ends at n-1 
    }
    return permutedKey;     
}

template<typename T>
T halfCircularShift(T half_key, int index) { //shift 

    T shift = "";
    for (int i = 0; i < index; i++) 
    {                       //for no of index
        for (int j = 1; j < 28; j++)
        { 
            //for total nos of binary(the loop starts from one and not 0)
            shift =shift+ half_key[j]; //add to string
        }
        shift = shift+ half_key[0];//adding the first element in the last position 
        half_key = shift;//assigning value 
        shift = "";//assigning empty string 
    }
    return half_key;
}

template<>
char* halfCircularShift<char*>(char * half_key,int index) {//template specialization for char array 


    string shift = "";
    for (int i = 0; i < index; i++)
    {                       //for no of index
        for (int j = 1; j < 28; j++)
        {
            //for total nos of binary(the loop starts from one and not 0)
            shift = shift + half_key[j]; //add to string
        }
        shift = shift + half_key[0];//adding the first element in the last position 
        strcpy(half_key, shift.c_str());//assiging value
        shift = "";//assigning empty string 
    }
    return half_key;
}



template<typename T>
T roundPermutation (T key) {  //56 to 48 bit conversion

    ////PC-2 table 
    int PC_2[48] = { 14, 17, 11, 24, 1, 5,
                         3, 28, 15, 6, 21, 10,
                         23, 19, 12, 4, 26, 8,
                         16, 7, 27, 20, 13, 2,
                         41, 52, 31, 37, 47, 55,
                         30, 40, 51, 45, 33, 48,
                         44, 49, 39, 56, 34, 53,
                         46, 42, 50, 36, 29, 32 };

    T round_permuted_key = "";
    for (int i = 0; i < 48; i++) 
    {
        round_permuted_key = round_permuted_key+ key[PC_2[i] - 1]; //array starts from zero and ends at n-1 
    }
    return round_permuted_key;
}

template<>
char* roundPermutation<char*>(char* key) {  //56 to 48 bit conversion//template specialization for char array

    ////PC-2 table 
    int PC_2[48] = { 14, 17, 11, 24, 1, 5,
                         3, 28, 15, 6, 21, 10,
                         23, 19, 12, 4, 26, 8,
                         16, 7, 27, 20, 13, 2,
                         41, 52, 31, 37, 47, 55,
                         30, 40, 51, 45, 33, 48,
                         44, 49, 39, 56, 34, 53,
                         46, 42, 50, 36, 29, 32 };

    string round_permuted_key_str = "";
    for (int i = 0; i < 48; i++)
    {
        round_permuted_key_str += key[PC_2[i] - 1]; //array starts from zero and ends at n-1 
    }
    strcpy(key, round_permuted_key_str.c_str());//assiging value
    return key;
}

//
////text 
//
template<typename T>
T initTextPermutation(T text) {//initTextPermutation

    text = hexadecimal_to_binary(text);

    // Initial permutation Table for text
    int initial_permutation[64] = { 58, 50, 42, 34, 26, 18, 10, 2,
                             60, 52, 44, 36, 28, 20, 12, 4,
                             62, 54, 46, 38, 30, 22, 14, 6,
                             64, 56, 48, 40, 32, 24, 16, 8,
                             57, 49, 41, 33, 25, 17, 9, 1,
                             59, 51, 43, 35, 27, 19, 11, 3,
                             61, 53, 45, 37, 29, 21, 13, 5,
                             63, 55, 47, 39, 31, 23, 15, 7 }; 
    T permutedText = "";
    for (int i = 0; i < 64; i++) 
    {
        permutedText += text[initial_permutation[i] - 1];   //array starts from zero and ends at n-1 
    }
    return permutedText;
}

//for char array
//tempate specialization

template<>
char* initTextPermutation<char*>(char * text) {
    text = hexadecimal_to_binary_char(text);

    // Initial Permutation Table for text
    int initial_permutation[64] = { 58, 50, 42, 34, 26, 18, 10, 2,
                             60, 52, 44, 36, 28, 20, 12, 4,
                             62, 54, 46, 38, 30, 22, 14, 6,
                             64, 56, 48, 40, 32, 24, 16, 8,
                             57, 49, 41, 33, 25, 17, 9, 1,
                             59, 51, 43, 35, 27, 19, 11, 3,
                             61, 53, 45, 37, 29, 21, 13, 5,
                             63, 55, 47, 39, 31, 23, 15, 7 };
    string permutedText = "";
    for (int i = 0; i < 64; i++)
    {
        permutedText += text[initial_permutation[i] - 1];   //array starts from zero and ends at n-1 
    }
    //return permutedText;
    strcpy(text, permutedText.c_str());
    return text;
}

//
template<typename T>
T expandHalfText(T rightHalfText) {
    int Expansion_D_box_Table[48] = { 32, 1, 2, 3, 4, 5, 4, 5,
                      6, 7, 8, 9, 8, 9, 10, 11,
                      12, 13, 12, 13, 14, 15, 16, 17,
                      16, 17, 18, 19, 20, 21, 20, 21,
                      22, 23, 24, 25, 24, 25, 26, 27,
                      28, 29, 28, 29, 30, 31, 32, 1 };

    T expandedRightHalf = "";
    for (int i = 0; i < 48; i++) 
    {
        expandedRightHalf += rightHalfText[Expansion_D_box_Table[i] - 1];//array starts from zero and ends at n-1 
    }
    return expandedRightHalf;
}
//for char array
//template specialization
template<>
char* expandHalfText<char*>(char* rightHalfText)
{
    int Expansion_D_box_Table[48] = { 32, 1, 2, 3, 4, 5, 4, 5,
                     6, 7, 8, 9, 8, 9, 10, 11,
                     12, 13, 12, 13, 14, 15, 16, 17,
                     16, 17, 18, 19, 20, 21, 20, 21,
                     22, 23, 24, 25, 24, 25, 26, 27,
                     28, 29, 28, 29, 30, 31, 32, 1 };

    char expandedRightHalf[48] = "";
    for (int i = 0; i < 48; i++)
    {
        expandedRightHalf[i] += rightHalfText[Expansion_D_box_Table[i] - 1];//array starts from zero and ends at n-1 
    }    
    return expandedRightHalf;
}

template<typename T>
T XOR(T text, T key) {
    T XOR = "";
    for (int i = 0; i < text.size(); i++) 
    {
        if (text[i] != key[i])
            XOR += "1";
        else 
            XOR += "0";
    }
    return XOR;
}

//for char array
//template specialization
template<>
char* XOR<char*>(char* text, char* key)
{

    string XOR = "";
    int i;
    for (i = 0; text[i] != '\0'; i++)
    {
        if (text[i] != key[i])
            XOR += "1";
        else
            XOR += "0";
    }
    strcpy(text, XOR.c_str());
    return text;
}

template<typename T>
T permutation(T text) {

    int permutation_table[32] = { 16, 7, 20, 21,
                                  29, 12, 28, 17,
                                  1, 15, 23, 26,
                                  5, 18, 31, 10,  
                                  2, 8, 24, 14,
                                  32, 27, 3, 9,
                                  19, 13, 30, 6,
                                  22, 11, 4, 25 };
    T permuted = "";
    for (int i = 0; i < 32; i++)
    {
        permuted = permuted + text[permutation_table[i] - 1];   //array starts from zero and ends at n-1 
    }
    return permuted;
}

// permutation specialized for char array
template<>
char* permutation<char*>(char *text) {

    int permutation_table[32] = { 16, 7, 20, 21,
                                  29, 12, 28, 17,
                                  1, 15, 23, 26,
                                  5, 18, 31, 10,
                                  2, 8, 24, 14,
                                  32, 27, 3, 9,
                                  19, 13, 30, 6,
                                  22, 11, 4, 25 };

    string permuted = "";
    for (int i = 0; i < 32; i++)
    {
        permuted  = permuted + text[permutation_table[i] - 1];   //array starts from zero and ends at n-1 
    }
    strcpy(text,permuted.c_str());
    return text;
}



template<typename T>
T calcSBox(T text) {//text=48bit binary


    int SBOX[8][4][16] = {
    //# Box-1
    { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,//4rows,16columns
    0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
    4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
    15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 },
    //# Box-2
    { 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,//4rows,16columns
    3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
    0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
    13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 },

    //# Box-3
    { 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,//4rows,16columns
    13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
    13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
    1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 },
    //# Box-4
    { 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,//4rows,16columns
    13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
    10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
    3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 },
    //# Box-5                    
    { 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,//4rows,16columns
    14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
    4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
    11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 },
    //# Box-6
    { 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,//4rows,16columns
    10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
    9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
    4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 },
    //# Box-7
    { 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,//4rows,16columns
    13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
    1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
    6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 },
    //# Box-8
    { 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,//4rows,16columns
    1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
    7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
    2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 } 
    };

    T ans = "";//we are storing 4 bits in each loop //4bits =value of the number in binary//creating 4*8=32 binary
    for (int i = 0; i < 8; i++)
    {
        int row, column, value;
        //text is a string of 48 bits binary 
        //each bit is a char
        //to convert each bit ascci value into integer value we have to subtract it from 48
        column = 8 * (text[i * 6 + 1] - 48) + 4 * (text[i * 6 + 2] - 48) + 2 * (text[i * 6 + 3] - 48) + (text[i * 6 + 4] - 48);
        row =    2 * (text[i * 6] - '0') + 1 * (text[i * 6 + 5] - '0');
        value = SBOX[i][row][column];//value of the number at that intersection
        ans += static_cast<char>(value / 8 + 48);//typecasting and assigning
        value %= 8;//value=value%8
        ans += static_cast<char>(value / 4 + 48);;//typecasting and assigning
        value %= 4;
        ans += static_cast<char>(value / 2 + 48);;//typecasting and assigning
        value %= 2;
        ans += static_cast<char>(value + 48);;//typecasting and assigning
    }
    return ans;
}

template<>
char* calcSBox(char* text) {
    int SBOX[8][4][16] = {
        //# Box-1
        { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,//4rows,16columns
        0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
        4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
        15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 },
        //# Box-2
        { 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,//4rows,16columns
        3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
        0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
        13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 },

        //# Box-3
        { 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,//4rows,16columns
        13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
        13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
        1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 },
        //# Box-4
        { 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,//4rows,16columns
        13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
        10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
        3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 },
        //# Box-5                    
        { 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,//4rows,16columns
        14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
        4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
        11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 },
        //# Box-6
        { 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,//4rows,16columns
        10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
        9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
        4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 },
        //# Box-7
        { 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,//4rows,16columns
        13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
        1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
        6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 },
        //# Box-8
        { 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,//4rows,16columns
        1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
        7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
        2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 }
    };

    string ans = "";//we are storing 4 bits in each loop //4bits =value of the number in binary//creating 4*8=32 binary
    for (int i = 0; i < 8; i++)
    {
        int row, column, value;
        //text is a char arr of 48 bits binary 
        //each bit is a char
        //to convert each bit ascci value into integer value we have to subtract it from 48
        column = 8 * (text[i * 6 + 1] - 48) + 4 * (text[i * 6 + 2] - 48) + 2 * (text[i * 6 + 3] - 48) + (text[i * 6 + 4] - 48);//converting bin2dec and storing in column
        row = 2 * (text[i * 6] - 48) + 1 * (text[i * 6 + 5] - 48);//converting bin2dec and storing in row
        value = SBOX[i][row][column];//value of the number at that intersection
        //ans += char(value / 8 + 48);//typecasting and assigning//
        ans += static_cast<char>(value/8+48);
        value %= 8;//value=value%8
        ans += static_cast<char>(value / 4 + 48);;//typecasting and assigning
        value %= 4;
        ans += static_cast<char>(value / 2 + 48);;//typecasting and assigning
        value %= 2;
        ans += static_cast<char>(value  + 48);;//typecasting and assigning
    }
    strcpy(text, ans.c_str());
    return text;
}
