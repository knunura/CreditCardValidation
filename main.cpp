#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

bool isvalidcc(const string&);
void doubleDigits(vector<int>&);
int addEven(vector<int>&);
int addOdd(vector<int>&);
int sumResults(int, int);
bool isDivisible(int);


int main()
{
    //
    // PLEASE DO NOT CHANGE function main
    //
    vector<string> cardnumbers = {
         "371449635398431", "4444444444444448", "4444424444444440", "4110144110144115",
        "4114360123456785", "4061724061724061", "5500005555555559", "5115915115915118",
        "5555555555555557", "6011016011016011", "372449635398431", "4444544444444448",
        "4444434444444440", "4110145110144115", "4124360123456785", "4062724061724061",
        "5501005555555559", "5125915115915118", "5556555555555557", "6011116011016011",
         "372449635397431", "4444544444444448", "4444434444544440", "4110145110184115",
        "4124360123457785", "4062724061724061", "5541005555555559", "5125115115915118",
        "5556551555555557", "6011316011016011"
    };

    int i;
    vector<string>::iterator itr;

    for (i = 1, itr = cardnumbers.begin(); itr != cardnumbers.end(); ++itr, i++) {
        cout << setw(2)  << i << " "
             << setw(17) << *itr
             << ((isvalidcc(*itr)) ? " is valid" : " is not valid") << endl;

        
    }

    return 0;
}

/*
 This function evaluates the credit card numbers that was passed as a reference to see if it is valid.
 This function calls five other functions that do the math behind the scenes.
 */
bool isvalidcc(const string& thisItr){
    int evenResults, oddResults, sumResult = 0;
    bool isValid = false;
    vector<int> myVector = {};  //A vector that will hold the INTEGER values of STRING cardnumbers
    
    for(int i = 0; i < thisItr.length(); i++){  //Iterate through passed reference
        myVector.push_back(thisItr[i] - '0');   //Coverts each string value of passed vector into an integer through ASCII values
    }
    
    reverse(myVector.begin(), myVector.end());  //Reverses order of integer values for simple evaluation from right to left
    
    doubleDigits(myVector);                     //Pass by reference. Doubles every digit from right to left
    evenResults = addEven(myVector);            //Pass by reference. Adds every even element from right to left. Stores value in evenResults
    oddResults = addOdd(myVector);              //Pass by reference. Adds every odd element from right to left. Stores value in oddResults
    sumResult = sumResults(evenResults, oddResults);    //Pass by value. Adds even and odd results and stores in sumResult
    (isDivisible(sumResult)) ? isValid = true : isValid;    //If sumResult is divisible by 10, then change isValid flag to true. Otherwise leave isValid as false
    
    return isValid;
}

/*
 This function contains the reversed integer vector values of creditcard numbers and doubles every second digit from right to left.
 If doubling of a digit results in a two-digit number, it adds the two digits to get a single digit number.
 */
void doubleDigits(vector<int> &myVector){
    for(int i = 1; i < myVector.size(); i += 2){    //Iterates from second element from the right of the vector
        myVector[i] *= 2;                           //Double the current digit
        if(myVector[i] > 9){                        //If the digit is two-digits
            int x = myVector[i] / 10 % 10;          //Save the first digit in variable 'x'
            int y = myVector[i] % 10;               //Save the second digit in variable 'y'
            myVector[i] = x + y;                    //Add both digits and store in current element
        }
    }
}

/*
 This function takes in the reversed integer vector of card numbers and adds all the single-digit numbers from doubleDigits().
 */
int addEven(vector<int> &myVector){
    int addEven = 0;
    
    for(int i = 1; i < myVector.size(); i += 2){    //Iterates from second element from the right of the vector
        addEven += myVector[i];                     //Stores sumation in variable addEven as it iterates
    }
    
    return addEven;
}

/*
 This function takes in the reversed integer vector of card numbers and adds all digits in the odd places from right to left
 in the card number.
 */
int addOdd(vector<int> &myVector){
    int addOdd = 0;
    
    for(int i = 0; i < myVector.size(); i += 2){
        addOdd += myVector[i];
    }
    
    return addOdd;
}
           
/*
 This function takes the value of the even and odd digits summation of previous functions and adds their results.
 */
int sumResults(int even, int odd){
    return even + odd;
}

/*
 This function checks if the sum of the results of the credit card numbers are dividible by 10 and returns true if so.
 */
bool isDivisible(int result){
    if(result % 10 == 0){   //If a number is divisible by 10 then its value modulo (%) 10 will return 0
        return true;
    }
    else{
        return false;
    }
}

