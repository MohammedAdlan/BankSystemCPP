#pragma once

#include <iostream>
#include <vector>

using namespace std;

class clsString
{
	string _value;
public:
	clsString()
	{
		_value = "";
	}

	clsString(string value)
	{
		_value = value;
	}

	void setValue(string value)
	{
		_value = value;
	}

	string GetValue()
	{
		return _value;
	}

	__declspec(property(get = GetValue, put = setValue)) string value;

	static short Length(string S1)
	{
		return S1.length();
	}

	short Length()
	{
		return _value.length();
	}

	static short CounthWords(string S1)
	{
		string delim = " "; //delimiter
		string sWord = ""; //define a string variable

		short pos = 0;
		short Counter = 0;

		//use find() function to get the position of the delimiters
		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); //store the word

			if (sWord != "")
			{
				Counter++;
			}

			S1.erase(0, pos + delim.length()); // erase until position and move to next word
		}

		if (S1 != "")
		{
			Counter++; // it counts last word of the string
		}
		return Counter;
	}

	short CounthWords()
	{
		return CounthWords(_value);
	}

	static string UpperFirstLetterOfEachWord(string S1)
	{
		bool isFirstLetter = true;

		for (int i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLetter)
				S1[i] = toupper(S1[i]);

			isFirstLetter = (S1[i] == ' ' ? true : false);
		}
		return S1;
	}

	void  UpperFirstLetterOfEachWord()
	{
		//no need to return value, this function will directly update the object value
		_value = UpperFirstLetterOfEachWord(_value);
	}

	static string LowerFirstLetterOfEachWord(string S1)
	{
		bool isFirstLetter = true;

		for (int i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLetter)
				S1[i] = tolower(S1[i]);

			isFirstLetter = (S1[i] == ' ' ? true : false);
		}
		return S1;
	}

	void LowerFirstLetterOfEachWord()
	{
		_value = LowerFirstLetterOfEachWord(_value);
	}

	static string UpperAllString(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = toupper(S1[i]);
		}
		return S1;
	}

	void UpperAllString()
	{
		_value = UpperAllString(_value);
	}

	static string LowerAllString(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = tolower(S1[i]);
		}
		return S1;
	}

	void LowerAllString()
	{
		_value = LowerAllString(_value);
	}

	static char InvertCharcterCase(char char1)
	{
		return isupper(char1) ? tolower(char1) : toupper(char1);
	}

	static string InvertAllLettersCase(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = InvertCharcterCase(S1[i]);
		}
		return S1;
	}

	void InvertAllLettersCase()
	{
		_value = InvertAllLettersCase(_value);
	}

	enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

	static short CounterLetters(string S1, enWhatToCount WhatToCount = All)
	{
		if (WhatToCount == All)
			return S1.length();

		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (WhatToCount == CapitalLetters && isupper(S1[i]))
				Counter++;

			if (WhatToCount == SmallLetters && islower(S1[i]))
				Counter++;
		}
		return Counter;
	}

	static short CountCapitalLetters(string S1)
	{
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
			if (isupper(S1[i]))
				Counter++;
		return Counter;
	}

	short CountCapitalLetters()
	{
		return  CountCapitalLetters(_value);
	}

	static short CountSmallLetters(string S1)
	{
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
			if (islower(S1[i]))
				Counter++;
		return Counter;
	}

	short CountSmallLetters()
	{
		return  CountSmallLetters(_value);
	}

	static short CountSpecificLetter(string S1, char Letter, bool MatchCase = true)
	{
		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{
			if (MatchCase)
			{
				if (S1[i] == Letter)
					Counter++;
			}
			else
			{
				if (tolower(S1[i]) == tolower(Letter))
					Counter++;
			}
		}
		return Counter;
	}

	short CountSpecificLetter(char Letter, bool MatchCase = false)
	{
		return CountSpecificLetter(_value, Letter, MatchCase);
	}

	static bool isVowel(char Ch1)
	{
		Ch1 = tolower(Ch1);
		return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'o') || (Ch1 == 'i') || (Ch1 == 'u'));
	}

	static short CountVowels(string S1)
	{
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
			if (isVowel(S1[i]))
				Counter++;
		return Counter;
	}

	short  CountVowels()
	{
		return CountVowels(_value);
	}

	static vector <string> Split(string S1, string Delim = " ")
	{
		vector <string> vString;

		short pos = 0;
		string sWord = ""; //define a string variable

		//use find() function to get the position of the delimiters
		while ((pos = S1.find(Delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); //store the word
			//if (sWord != "")
			//{
			vString.push_back(sWord);
			//}

			S1.erase(0, pos + Delim.length()); // erase until position and move to next word
		}

		if (S1 != "")
		{
			vString.push_back(S1); // it push last word of the string
		}

		return vString;
	}

	vector <string> Split(string Delim = " ")
	{
		return  Split(_value, Delim);
	}

	static string TrimLeft(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(i, S1.length() - 1);
			}
		}

		return "";
	}

	void TrimLeft()
	{
		_value = TrimLeft(_value);
	}

	static string TrimRight(string S1)
	{
		for (short i = S1.length() - 1; i >= 0; i--)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(0, i + 1);
			}
		}

		return "";
	}

	void TrimRight()
	{
		_value = TrimRight(_value);
	}

	static string Trim(string S1)
	{
		return (TrimLeft(TrimRight(S1)));
	}

	void Trim()
	{
		_value = Trim(_value);
	}

	static string JoinString(vector <string> vString, string Delim)
	{
		string String = "";
		for (string& s : vString)
		{
			String += s + Delim;
		}
		return String.substr(0, String.length() - Delim.length()); // to cut last Delim at string tail
	}

	static string JoinString(string arrString[], short Length, string Delim)
	{
		string String = "";
		for (short i = 0; i < Length; i++)
		{
			String += arrString[i] + Delim;
		}
		return String.substr(0, String.length() - Delim.length()); // to cut last Delim at string tail
	}

	static string RverseWordsInString(string S1)
	{
		vector <string> vString;
		string S2 = "";

		vString = Split(S1, " ");

		//declare iterator
		vector<string>::iterator iter = vString.end();
		while (iter != vString.begin())
		{
			--iter;
			S2 += *iter + " ";
		}
		S2 = S2.substr(0, S2.length() - 1); //remove lase space
		return S2;
	}

	void RverseWordsInString()
	{
		_value = RverseWordsInString(_value);
	}

	static string ReplaceWord(string S1, string StringToReplace, string sReplaceTo)
	{
		short pos = S1.find(StringToReplace);

		while (pos != std::string::npos)
		{
			S1 = S1.replace(pos, StringToReplace.length(), sReplaceTo);
			pos = S1.find(StringToReplace); //find next.
		}
		return S1;
	}

	void ReplaceWord(string StringToReplace, string sReplaceTo)
	{
		_value = ReplaceWord(_value, StringToReplace, sReplaceTo);
	}

	static string RemovePuncuations(string S1)
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

	void RemovePuncuations()
	{
		_value = RemovePuncuations(_value);
	}

	static string NumberToText(int Number)
	{
		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
								 "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
								 "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
			return arr[Number] + " ";
		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninty" };
			return arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return "One Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return "One Billion " + NumberToText(Number % 1000000000);
		}

		if (Number >= 2000000000 && Number <= 999999999999)
		{
			return NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}
	}

};


