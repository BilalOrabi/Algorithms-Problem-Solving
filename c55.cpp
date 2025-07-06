#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

//int PrintDigitsFrequency(int Number, short DigitToCheck)
//{
//	int remainder = 0;
//	int FreqCounter = 0;
//	while (Number > 0)
//	{
//		remainder = Number % 10;
//		Number = Number / 10;
//		if (remainder == DigitToCheck)
//		{
//			FreqCounter++;
//		}
//	}
//	return FreqCounter;
//
//	
//
//
//}
//
//void PrintAllDigitsFrequency(int Number)
//{
//	for (int i = 0; i <= 9; i++)
//	{
//		int DigitToCheck = 0;
//		DigitToCheck = PrintDigitsFrequency(Number, i);
//
//			if (DigitToCheck > 0)
//			{
//				cout << " Digit " << i << " Frequncy is " << DigitToCheck << " Time(s) " << endl;
//			}
//	}
//}

//int ReadPostiveNumber(string massage)
//{
//	int Number = 0;
//	do
//	{
//		cout << massage << endl;
//		cin >> Number;
//	} while (Number <= 0);
//
//	return Number;
//}
//
//int ReverseNumber(int Number)
//{
//	int remainder = 0;
//	int Number2 = 0;
//	while (Number > 0)
//	{
//		remainder = Number % 10;
//		Number = Number / 10;
//		Number2 = Number2 * 10 + remainder;
//	}
//	return Number2;
//}
//
//void PrintDigits(int Number)
//{
//	int Number2 = 0;
//	Number2 = ReverseNumber(Number);
//
//	if (Number == Number2)
//	{
//		cout << " this Number is palindrome! " << endl;
//	}
//	else
//		cout << "this number is not palindrome." << endl;
//	
//}

int ReadNumber()
{
	int Number = 0;
	cout << "Please Enter a number : ";
	cin >> Number;
	return Number;
}

enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

 enPrimeNotPrime CheakPrime(int Number)
{
	int M = round(Number / 2);
	for (int counter = 2; counter <= M; counter++)
	{
		if (counter % 2 == 0)
		{
			return enPrimeNotPrime::NotPrime;
		}
		return enPrimeNotPrime::Prime;
	}
}

int ReadPostiveNumber(string massage)
{
	int Number = 0;
	do
	{
		cout << massage << endl;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}

string ReadText()
{
	string Text ="";
	cout << " Enter the Text  that you want to Encrypt : " << endl;
	getline(cin,Text);
	return Text;
}

void PrintReversedNumber(int number)
{
	int reminder = 0;
	while (number > 0)
	{
		reminder = number % 10;
		number = number / 10;
		cout << reminder << endl;
	}
}

void PrintInvertedPattern(int Number)
{
	cout << "\n";

	for (int i = Number; i >= 1; i--)
	{
		
		for (int j = 1; j <= i; j++)
		{
			cout << i;
		}

		cout << endl;
	}

	
}

bool GuessPassWord(string password)
{
	cout << "\n";
	string word = "";
	int counter = 0;
	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int z = 65; z <= 90; z++)
			{
				counter++;

				word = word + char(i);
				word = word + char(j);
				word = word + char(z);
				cout << "Trail [" << counter << "]  : " << word << endl;
				if (word == password)
				{
					cout << "\nPassword is " << word << endl;
					cout << "Found after " << counter << " Trail's\n";
					return true;
				}
				word = "";
			}
		}
	}
	return false;
}

string EncryptText(string text, short EncryptionKey)
{
	for (int i = 0; i <= text.length(); i++)
	{
		text[i] = char((int)text[i] + EncryptionKey);
	}
	return text;
}

string DecryptText(string text, short EncryptionKey)
{
	for (int i = 0; i <= text.length(); i++)
	{
		text[i] = char((int)text[i] - EncryptionKey);
	}
	return text;
}

int RandomNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}

enum enRandomCharType { SmallLatter = 1, CapitalLatter = 2, SpChar = 3, Digit = 4 };

char GenerateRandomChar(enRandomCharType CharType)
{
	switch (CharType)
	{

	case enRandomCharType::SmallLatter:
	{
		return char(RandomNumber(97, 122));
		break;
	}

	case enRandomCharType::CapitalLatter:
	{
		return char(RandomNumber(65, 90));
		break;
	}

	case enRandomCharType::SpChar:
	{
		return char(RandomNumber(33, 47));
		break;
	}

	case enRandomCharType::Digit:
	{
		return char(RandomNumber(48, 57));
		break;
	}

	}
		
		
	
	
		  
}

string GenrateWord(enRandomCharType CharType,int length)
{
	string word;
	for (int i = 1; i <= length; i++)
	{
		word += GenerateRandomChar(enRandomCharType::CapitalLatter);
	}
	return word;
	
}

string GenrateKey()
{
	string key = "";
	key = key + GenrateWord(enRandomCharType::CapitalLatter, 4) + "-";
	key = key + GenrateWord(enRandomCharType::CapitalLatter, 4) + "-";
	key = key + GenrateWord(enRandomCharType::CapitalLatter, 4) + "-";
	key = key + GenrateWord(enRandomCharType::CapitalLatter, 4);

	return key;
}

void GenrateKeys(short  NumberOFKeys)
{
	for (int i = 1; i <= NumberOFKeys; i++)
	{
		cout << "Key [" << i << "] : " << GenrateKey() << endl;
	}
}

void ReadArray(int Array[100],int& Arraylength)
{
	cout << "Please Enter Number of Array Element: " << endl;
	cin >> Arraylength;

	cout << "Enter Array elements : " << endl;
	for (int i = 0; i <= Arraylength-1; i++)
	{
		cout << "Element [" << i + 1 << "] : " << endl;
		cin >> Array[i];

	}

	
}

void FillArrayWithRandomNumbers(int Array[100], int& Arraylength)
{
	for (int i = 0; i < Arraylength; i++)
	{
		Array[i] = RandomNumber(1, 100);
	}
}

void PrintArray(int Array[100], int Arraylength)
{
	for (int i = 0; i < Arraylength; i++)
	{
		cout << Array[i] << " ";
	}
	cout << endl;
}

int MaxNumberInArray(int Array[100], int Arraylength)
{
	int max = 0;
	
	for (int i = 0; i < Arraylength; i++)
	{
		if (Array[i] > max)
			max = Array[i];

	}
	return max;
}

int TimesRepeated(int Array[100], int Arraylength, int NumberToCheck)
{
	int count = 0;
	for (int i = 0; i < Arraylength; i++)
	{
		if (NumberToCheck == Array[i])
		{
			count++;
		}
	}
	return count;
}

void CopyPrintOnlyPrimeNumbers(int Array[100], int Arraylength, int Array2[100], int& Arraylength2)
{
	int counter = 0;
	for (int i = 0; i < Arraylength; i++)
	{
		if (CheakPrime(Array[i] == enPrimeNotPrime::Prime))
		{
			Array2[counter] = Array[i];
			counter++;
		}
	}
	
}

void SumArrays(int Array[100], int Array2[100], int ArraySum[100], int Arraylength)
{
	
	for (int i = 0; i < Arraylength; i++)
	{
		ArraySum[i] = Array[i] + Array2[i];
		
		
	}
	
}

int FindNumberPostionInArray(int Array[100], int Arraylength, int Number)
{
	for (int i = 0; Arraylength; i++)
	{
		if (Array[i] == Number)
		{
			return Number;
		}
	}
	
	return -1;
}

bool IsNumberInArray(int Array[100], int Arraylength, int Number)
{
	return FindNumberPostionInArray(Array, Arraylength, Number) != -1;
}

void AddArrayElement(int Number, int Array[100], int& Arraylength)
{
	Arraylength++;
	Array[Arraylength - 1] = Number;
}


void InputUserNumberInArray(int Array[100], int& Arraylength)
{
	bool AddMore;
	do
	{
		AddArrayElement(ReadNumber(), Array, Arraylength);
		cout << "do you want to add more Numbers : [0]:NO,[1]:Yes? ";
		cin >> AddMore;

	} while (AddMore == 1);
}

//void CopyArray(int array[100], int array2[100], int Arraylength, int Arraylength2)
//{
//
//}

int main()
{
	//Seeds the random number generator in C++, called only once
     srand((unsigned)time(NULL));

	 int Array[100] , Array2[100] , ArraySum[100];

	 int Arraylength ;
	 int Arraylength2 = 0;


	 FillArrayWithRandomNumbers(Array, Arraylength);

	 cout << "Array Elements 1 : \n";
	 PrintArray(Array, Arraylength);



	 cout << "Array Elements 2 : \n";
	 cout << "this shit is not working";
	 PrintArray(Array2, Arraylength2);

	 
	 

	return 0;
}


