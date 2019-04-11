#include <iostream>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <iomanip>
#include <sstream>

//Muniru Lamin
//COSC320 Lab-7
//Last Updated 04/03/19




/***********************************************************************************************/
//Hex conversion function									/
//Takes in a size_t value, and converts it to a hexidecimal					/
//and prints it out										/
///*********************************************************************************************/
void Hexcon(size_t x)
{
	std::cout << std::hex << x;
}

/***********************************************************************************************/
//Hashing function										/
//Takes in a size_t value and performs a hash on the value given				/
//Use the multiplication method, returns a size_t hash value.					/		
/***********************************************************************************************/
size_t hash(size_t x)
{

	size_t w = 32;
	size_t p = 17;
	size_t W = size_t(1) << w;		//Used bit shifting instead to write less lines of codes.
	size_t a = 72559;
	size_t ans = size_t((a * x )% W) >> (w - p);		//bit shifting also used here.
	return ans;
}

/***********************************************************************************************/
//String manipulation function									/
//Base 128 string conversion. Gets a word or a sentence from the user then does the 		/
//Base 128 conversion, where ASCII values are used as a base 128.				/		
//Returns a hash of the sum of the string converted to int.					/
/***********************************************************************************************/
size_t hashString(std::string word)
{
	int temp = 0;
	int innerhash = 0;
	int size = word.length() - 1;
	for(int i = size; i >= 0; i--)
	{
		temp = word[size - 1] * (i + 1);
		innerhash += temp;
	}



	return hash(innerhash);
}

/***********************************************************************************************/
//String conversion function									/
//ASCII addition conversion.									/
//Takes string from the user, converts each character to int and adds up all its ASCII		/		
//values.											/
/***********************************************************************************************/
size_t hashString2(std::string sentence)
{
	int answer;
	int size = sentence.length() - 1;
	char temp;
	for(int i = 0; i < size; i++)
	{
		temp = sentence.at(i);
		answer += int(temp);

	}


	return hash(answer);
}



/***********************************************************************************************/
//Main program											/
//Asks the user what they would like to test, option between 2 string function			/
//Calls string function, the prints out answer to user with their original			/		
//Input they entered										/
/***********************************************************************************************/
int main()
{
	int option;
	do{
		std::cout << "String input menu" << std::endl;
		std::cout << "input 1 to test string function with ASCII being used as Base - 128 digits" << std::endl;
		std::cout << "input 2 to test a different type of string function " << std::endl;
		std::cout << "input 3 to end program: ";
		std::cin >> option;

		if(option == 1)
		{
			int wordInput;
			std::cout << "Base 128 digits string function" << std::endl;
			std::cout << "Input 1 for a single word, and 2 for a sentence: ";
			std::cin >> wordInput;
			if(wordInput == 1)
			{
				std::string str1;
				std::cout << "Input a word: ";
				std::cin >> str1;
				std::cout << "Your word: " << str1 << std::endl;
				std::cout << "Hash of the word in hexidecimal: ";
				Hexcon(hashString(str1));
				std::cout << std::endl;
			}
			else if(wordInput == 2)
			{
				std::string str2;
				std::cout << "Input a sentence: ";
				std::cin.ignore();
				std::getline(std::cin,str2);
				std::cout << "Your Sentence is: " << str2 << std::endl;
				std::cout << "Hash of the sentence in hexidecimal is: ";
				Hexcon(hashString(str2));
				std::cout << std::endl;
			}
		}
		else if(option == 2)
		{
			int wordInput;
			std::cout << "Other string function" << std::endl;
			std::cout << "Input 1 for a single word, and 2 for a sentence: ";
			std::cin >> wordInput;
			if(wordInput == 1)
			{
				std::string str1;
				std::cout << "Input a word: ";
				std::cin >> str1;
				std::cout << "Your word: " << str1 << std::endl;
				std::cout << "Hash of the word in hexidecimal: ";
				Hexcon(hashString2(str1));
				std::cout << std::endl;
			}
			if(wordInput == 2)
			{
				std::string str2;
				std::cout << "Input a sentence: ";
				std::cin >> str2;
			}
		}
	}while(option != 3);
	return 0;
}
