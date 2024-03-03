//==================================================================================
// Written by Andrew Byerly and Ashlee Salmon
// February 18th, 2024
// RomanNumeralConverter.cpp
// This program will not prompt the user for input as the intention is that this
// program will primarily be tested using .txt files. *Precondition for File: The 
// first line must be an integer value specifying the number of lines that contain 
// roman numerals to be tested. These aforementioned roman numerals must be strings
// that ONLY contain roman symbols "I, V, X, L, C, D, M". The program itself will
// then iterate over each line of the test file, first verifying that each roman
// numeral is constructed within legal bounds (outputing that it's an invalid roman
// numeral if it doesn't follow said rules). After verifying that each roman numeral
// is valid, it will compute the decimal equivalent value of the roman numeral and
// print out the decimal equivalent.
//==================================================================================

#include <iostream>
using namespace std;

//==================================================================================
// numOccurrences()
// This function will take a char 'target' as well as a string 'str' as parameters
// and return the number of times the char 'target' occurs in the string 'str'.
// Parameters:
//    A char 'target' that specifies the character we are searching for.
//    A string 'str' that holds the string value we are searching for the target in.
// Return Value:
//    An integer 'count' that will represent the number of times the target 
//    character occurs the the given string.
//==================================================================================
int numOccurances(char target, string str) {
 
 // initializes count variable and sets it equal to 0.
 int count = 0;
 
 // iterates over each index in string 'str' and increments the count variable if
 // the current index in the string contains the char 'target'.
 for(int i = 0; i < str.length(); i++) {
  if (str[i] == target) {
   count++;
  }
 }
 
 // returns the integer 'count' variable.
 return count;
}

//==================================================================================
// validRoman()
// This function will take a string 'rNum' and will determine whether or not it
// follows the conventional rules for roman numerals (No more than three occurances
// of M, C, X, or I appearing consecutively or no more than one occurance of D, L,
// or V at all). Returning true if it follows these rules, and false if otherwise.
// Parameters:
//    A string 'rNum' that contains a string made up of only roman numerals.
// Return Value:
//    A boolean 'rStatus' that will evaluate as true if the given string followed
//    the roman numeral rules and will evaluate as false if otherwise.
// *Precondition: The input string must only contain roman numeral symbols (I, V, X,
// L, C, D, M).
//==================================================================================
bool validRoman(string rNum) {
 
 // creates an integer 'count' setting it equal to 0 and a boolean 'rStatus' setting
 // it equal to true by default.
 bool rStatus = true;
 int count = 0;
 
 // if D, L, or V occur more than once in the string set rStatus equal to false.
 if (numOccurances('D', rNum) > 1 || numOccurances('L', rNum) > 1 || numOccurances('V', rNum) > 1) {
  rStatus = false;
 }
 
 // if the length of the string is greater than or equal to 4, check each 
 // substring of length 4 to verify M, C, X, or I do not appear more than 3 times 
 // consecutively, if at any point this pattern appears set rStatus equal to false.
 if (rNum.length() >= 4) {
  while (rStatus && count <= rNum.length() - 4) {
   if (rNum[count] == 'M' || rNum[count] == 'C' || rNum[count] == 'X' || rNum[count] == 'I') {
    if (numOccurances(rNum[count], rNum.substr(count, 4)) == 4) {
     rStatus = false;
     }
   }
   count++;
  }
 }
 
 // returns the 'rStatus' boolean variable.
 return rStatus;
}

//==================================================================================
// romanToDecimal()
// This function will take a roman numeral string 'rNum' and compute and return it's
// decimal/integer 'rSum' equivalent, regardless if it follows the roman numeral 
// rules or not.
// Parameters:
//    A string 'rNum' that contains a string made up of only roman numerals.
// Return Value:
//    An integer 'rSum' that will represent the total decimal equivalent of the
//    given string/roman numeral.
// *Precondition: The input string must only contain roman numeral symbols (I, V, X,
// L, C, D, M).
//==================================================================================
int romanToDecimal(string rNum) {

 // creates an array, specifying the valid roman numerals.
 // creates an array, storing the decimal equivalent of each roman numeral.
 // creates an integer to store the length of conversion arrays.
 char romanNumerals[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
 int decimalEquiv[] = {1, 5, 10, 50, 100, 500, 1000};
 int numConversions = 7;
 
 // creates, 'rSum', 'prevNum', and 'curNum' variables and sets them equal to 0.
 int rSum = 0;
 int prevNum = 0;
 int curNum = 0;
 
 // iterates over each index of the given string 'rNum' in inverse order, nested 
 // for loop iterates over each symbol in 'romanNumerals' finding its equivalent.
 // Uses the index of the equivalent to find the symbol decimal equivalent in the 
 // 'decimalEquiv' array. Then adds/subtracts that value from the total sum based on
 // whether or not it had a greater or smaller previous value.
 // (+ if greater, - if smaller)
 for (int i = rNum.length() - 1; i >= 0; i--) {
  for (int j = 0; j < numConversions; j++) {
   if (romanNumerals[j] == rNum[i]) {
    curNum = decimalEquiv[j];
    if (curNum < prevNum) {
     rSum -= curNum;
    } else {
     rSum += curNum;
    }
   }
  }
  prevNum = curNum;
 }
 
 // returns the 'rSum' integer variable.
 return rSum;
}

//==================================================================================
// main()
// This function will act as the backbone of the program, taking each function and
// leveraging it in the manner it's intended. It will start by reading in the number
// of roman numerals we are looking to test, then iterating over each line of the
// file for the specified number of tests. Each iteration will read in the roman
// numeral located at the position of the pointer (one line for each iteration) and
// then invoke the 'validRoman()' function on the read in valid to determine if it
// follows the rules and is considered a valid roman numeral. After determination
// the main() function will either call the 'romanToDecimal()' function to output
// the decimal equivalent of the valid roman numeral (true) or it will output that 
// the roman numeral is 'not a valid roman numeral!' (false).
//==================================================================================
int main() {

 // creates integer 'numTests' and string 'romanNumeral' to store file input.
 int numTests = 0;
 string romanNumeral;
 
 // reads the first line of the file to specify the amount of tests the file has.
 cin >> numTests;
 
 // iterates for each line of tests specified by the input number 'numTests'. Each
 // iteration will read in the roman numeral on the line the pointer in references,
 // outputing the decimal equivalent of the roman numeral if it's a valid roman
 // numeral and an error message if it's not.
 for (int i = 1; i <= numTests; i++) {
  cin >> romanNumeral;
  if (validRoman(romanNumeral)) {
   cout << i << ": " << romanNumeral << " is equal to " << romanToDecimal(romanNumeral) << endl;
  } else {
   cout << i << ": " << romanNumeral << " is not a valid roman numeral!" << endl;
  }
 }
 
 return 0;
}
