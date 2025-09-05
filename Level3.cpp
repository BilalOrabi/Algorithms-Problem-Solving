#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream> 
#include <iomanip>
#include <cctype>


using namespace std;

const string ClientsFileName = "ClientFile.txt";

int RandomNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}

int ReadNumber(string massage)
{
	int Number = 0;
	cout << massage << endl;
	cin >> Number;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "invalid Number please enter valid Number ?" << endl;
		cin >> Number;
	}
	return Number;
}

void FindFirstLatterOfString(string Line)
{

	bool IsFirstLatter = true;

	for (int i = 0; i <= Line.length(); i++)
	{
		if (Line[i] != ' ' && IsFirstLatter)
		{
			cout << Line[i] << "\n";
		}
		IsFirstLatter = (Line[i] == ' ' ? true : false);



	}
}

string UpperFirstLatterOfEachWord(string Line)
{

	bool IsFirstLatter = true;

	for (int i = 0; i <= Line.length(); i++)
	{
		if (Line[i] != ' ' && IsFirstLatter)
		{
			Line[i] = toupper(Line[i]);

		}
		IsFirstLatter = (Line[i] == ' ' ? true : false);



	}
	return Line;

}

string LowerFirstLatterOfEachWord(string Line)
{

	bool IsFirstLatter = true;

	for (int i = 0; i <= Line.length(); i++)
	{
		if (Line[i] != ' ' && IsFirstLatter)
		{
			Line[i] = tolower(Line[i]);

		}
		IsFirstLatter = (Line[i] == ' ' ? true : false);



	}
	return Line;

}

string ReadString()
{
	string S1 = "";

	cout << "Please Enter Your String?\n";
	getline(cin, S1);

	return S1;
}

char ReadChar()
{
	char ch1 = ' ';

	cout << "Please Enter Your Charectar?\n";
	cin >> ch1;

	return ch1;
}

string LowerAllStringLatter(string Line)
{
	for (int i = 0; i <= Line.length(); i++)
	{
		Line[i] = tolower(Line[i]);
	}

	return Line;

}

string UpperAllStringLatter(string Line)
{



	for (int i = 0; i <= Line.length(); i++)
	{
		Line[i] = toupper(Line[i]);
	}
	return Line;

}

char InvertCharectarCase(char Charectar)
{

	return isupper(Charectar) ? tolower(Charectar) : toupper(Charectar);
}

string InvertAllStringCharectarCase(string S1)
{
	for (int i = 0; i <= S1.length(); i++)
	{
		S1[i] = InvertCharectarCase(S1[i]);

	}
	return S1;
}

short CountCapitalLatters(string S1)
{
	short CapitalCounter = 0;
	for (short i = 0; i <= S1.length(); i++)
	{
		if (isupper(S1[i]))
		{
			CapitalCounter++;
		}
	}
	return CapitalCounter;
}


short CountSmallLatters(string S1)
{
	short SmallCounter = 0;
	for (short i = 0; i <= S1.length(); i++)
	{
		if (islower(S1[i]))
		{
			SmallCounter++;
		}
	}
	return SmallCounter;
}

short CountLatter(string S1, char Latter)
{
	short Counter = 0;
	for (int i = 0; i <= S1.length(); i++)
	{
		if (S1[i] == Latter)
		{
			Counter++;
		}
	}
	return Counter;
}

short CountLatter(string S1, char Latter, bool MatchCase)
{
	short counter = 0;
	for (int i = 0; i < S1.length(); i++)
	{
		if (MatchCase)
		{
			if (S1[i] == Latter)
				counter++;
		}
		else
			if (tolower(S1[i]) == tolower(Latter))
				counter++;
	}
	return counter;

}

bool IsVowel(char Latter)
{
	Latter = tolower(Latter);

	return ((Latter == 'a') || (Latter == 'e') || (Latter == 'i') || (Latter == 'o') || (Latter == 'u'));
}

short CountVowel(string S1)
{
	short counter = 0;
	for (int i = 0; i < S1.length(); i++)
	{
		if (IsVowel(S1[i]))
			counter++;
	}
	return counter;
}

void PrintAllVowelsInString(string S1)
{
	cout << "\n Vowels in string are: ";
	for (int i = 0; i < S1.length(); i++)
	{
		if (IsVowel(S1[i]))
		{
			cout << S1[i] << "\t";
		}
	}
}

void PrintEachWordInString(string S1)
{
	string Delimiter = " ";
	short pos = 0;
	string sWord = "";

	while ((pos = S1.find(Delimiter)) != S1.npos)
	{
		sWord = S1.substr(0, pos);
		if (sWord != "")
		{
			cout << sWord << endl;
		}
		S1.erase(0, pos + Delimiter.length());
	}
	if (S1 != "")
	{
		cout << S1 << endl;
	}
}

short CountWords(string S1)
{
	string Delimiter = " ";
	short pos = 0;
	short Counter = 0;
	string sWord = "";

	while ((pos = S1.find(Delimiter)) != S1.npos)
	{
		sWord = S1.substr(0, pos);
		if (sWord != "")
		{
			Counter++;
		}

		S1.erase(0, pos + Delimiter.length());
	}
	if (S1 != "")
	{
		Counter++;
	}
	return Counter;
}

vector <string> SplitFunction(string S1, string Delimiter)
{
	short pos = 0;
	string sWord = "";
	vector<string> vSplitWords;

	while ((pos = S1.find(Delimiter)) != S1.npos)
	{
		sWord = S1.substr(0, pos);
		if (sWord != "")
		{
			vSplitWords.push_back(sWord);
		}
		S1.erase(0, pos + Delimiter.length());
	}
	if (S1 != "")
	{
		vSplitWords.push_back(S1);
	}
	return vSplitWords;
}

string TrimLeft(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ')
		{
			return S1.substr(i, S1.length() - i);
		}

	}
}

string TrimRight(string S1)
{
	for (short i = S1.length() - 1; i >= 0; i--)
	{
		if (S1[i] != ' ')
		{
			return S1.substr(0, i + 1);
		}

	}
}

string Trim(string S1)
{
	return TrimLeft(TrimRight(S1));
}

string JoinFunction(vector<string> vString, string Delimiter)
{

	string S1 = "";
	for (string& S : vString)
	{
		S1 = S1 + S + Delimiter;
	}
	return S1.substr(0, S1.length() - Delimiter.length());

}

string JoinFunction(string arr[], short ArrLength, string Delimiter)
{
	string S1 = "";
	for (short i = 0; i < ArrLength; i++)
	{
		S1 = S1 + arr[i] + Delimiter;
	}
	return (S1.substr(0, S1.length() - Delimiter.length()));
}

string ReverseWordsInString(string S1)
{
	vector<string> vString;
	string S2 = "";
	vString = SplitFunction(S1, " ");

	vector<string>::iterator iter = vString.end();
	while (iter != vString.begin())
	{
		iter--;
		S2 = S2 + *iter + " ";
	}
	return S2.substr(0, S2.length() - 1);

}

string ReplaceWordsUsingBuiltInFun(string S1, string StringToreplace, string sReplace)
{

	short pos = S1.find(StringToreplace);

	while (pos != S1.npos)
	{
		S1.replace(pos, StringToreplace.length(), sReplace);
		pos = S1.find(StringToreplace);
	}

	return S1;

}

string ReplaceWordsManually(string S1, string StringToreplace, string sReplaceTo, bool MatchCase = true)
{
	vector<string>vString;
	vString = SplitFunction(S1, " ");


	for (string& s : vString)
	{
		if (MatchCase)
		{
			if (s == StringToreplace)
			{
				s = sReplaceTo;
			}
		}
		else
		{

			if (LowerAllStringLatter(s) == LowerAllStringLatter(StringToreplace))

				s = sReplaceTo;
		}



	}

	return JoinFunction(vString, " ");

}

string RemoveAllPunct(string S1)
{
	string S2 = "";

	for (short i = 0; i < S1.length(); i++)
	{
		if (!ispunct(S1[i]))
		{
			S2 += S1[i];
		}
	}
	return S2;
}


struct stClientData
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;
};


stClientData ReadClientData()
{

	stClientData Client;

	cout << "Enter Account Number : ";
	getline(cin >> ws, Client.AccountNumber);

	cout << "Enter PinCode : ";
	getline(cin, Client.PinCode);

	cout << "Enter Name : ";
	getline(cin, Client.Name);

	cout << "Enter Phone Number : ";
	getline(cin, Client.Phone);

	cout << "Enter AccountBalance : ";
	cin >> Client.AccountBalance;

	return Client;


}

string ConvertClientDataToLine(stClientData Client, string Seprater = "#//#")
{
	string ClientRecord = "";

	ClientRecord += Client.AccountNumber + Seprater;
	ClientRecord += Client.PinCode + Seprater;
	ClientRecord += Client.Name + Seprater;
	ClientRecord += Client.Phone + Seprater;
	ClientRecord += to_string(Client.AccountBalance);

	return ClientRecord;
}

stClientData ConvertLineToRecord(string LineRecord, string Seperator)
{
	vector<string> vRecords;
	stClientData Client;

	vRecords = SplitFunction(LineRecord, Seperator);

	Client.AccountNumber = vRecords[0];
	Client.PinCode = vRecords[1];
	Client.Name = vRecords[2];
	Client.Phone = vRecords[3];
	Client.AccountBalance = stod(vRecords[4]);

	return Client;
}

void PrintClientRecord(stClientData Client)
{
	
	cout << "|  " << setw(15) << left << Client.AccountNumber;
	cout << "|  " << setw(10) << left << Client.PinCode;
	cout << "|  " << setw(40) << left << Client.Name;
	cout << "|  " << setw(12) << left << Client.Phone;
	cout << "|  " << setw(12) << left << Client.AccountBalance;

}

void PrintClientCard(stClientData Client)
{
	cout << "\n\nThe Following are the client Details:\n";
	cout << "\nAccount Number: " << Client.AccountNumber;
	cout << "\nPin Code      : " << Client.PinCode;
	cout << "\nName          : " << Client.Name;
	cout << "\nPhone         : " << Client.Phone;
	cout << "\nAccount Balance: " << Client.AccountBalance;

}


void SaveClientInFile(string LineRecord, string FileName)
{
	fstream ClientsFile;
	ClientsFile.open(FileName, ios::out | ios::app);

	if (ClientsFile.is_open())
	{
		ClientsFile << LineRecord << endl;

		ClientsFile.close();
	}
}

void AddNewClient()
{
	stClientData Client;
	Client = ReadClientData();
	SaveClientInFile(ClientsFileName, ConvertClientDataToLine(Client));

}

void AddClients()
{
	char AddMore = 'Y';
	do
	{

		system("cls");
		cout << "Adding New Client:\n\n";

		AddNewClient();
		cout << "Client Added Succsessfully, do you want to  add more clients?  Y/N ";
		cin >> AddMore;

	} while (toupper(AddMore) == 'Y');
}

vector <stClientData> LoadClientDataFromFile(string FileName)
{
	vector <stClientData> vClient;
	fstream ClientFile;
	ClientFile.open(ClientsFileName, ios::in);

	if (ClientFile.is_open())
	{
		string Line;
		stClientData stClient;

		while (getline(ClientFile, Line))
		{
			stClient = ConvertLineToRecord(Line, "#//#");
			vClient.push_back(stClient);
		}
		ClientFile.close();
	}
	return vClient;
}

void PrintAllClientData(vector <stClientData> vClients)
{
	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
	cout << "\n______________________________________________________________________________________________________";
	cout << "_______________________________________________________\n" << endl;

	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";

	cout << "\n____________________________________________________________" << endl;
	cout << "_______________________________________________________\n" << endl;

	for (stClientData s : vClients)
	{
		PrintClientRecord(s);
		cout << endl;
	}


	cout << "\n_________________________________________" << endl;
	cout << "_________________________________________\n" << endl;
}

string ReadAccountNumber()
{
	string AccountNumber;
	cout << "\nPlease Enter AccountNumber? ";
	cin >> AccountNumber;

	return AccountNumber;
}

bool FindClientByAccountNumber(string AccountNumber, stClientData & sClients)
{
	vector<stClientData> vClients = LoadClientDataFromFile(ClientsFileName);

	for (stClientData C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			sClients = C;
			return true;
		}
	}
	return false;
}

int main()
{
	srand((unsigned)time(NULL));

	string AccountNumber = ReadAccountNumber();
	stClientData sClients;







	system("pause>0");


	return 0;
}







