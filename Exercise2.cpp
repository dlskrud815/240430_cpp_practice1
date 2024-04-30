#include <iostream>
#include <string>
using namespace std;

bool strIntCheck(string* ptr);
void strInput(string* ptr);

int main()
{
	string str1, str2;

	//1. 두 문자열을 입력 받아서 둘 모두 숫자인지 검사, 아니면 다시 입력 받도록
	cout << "첫 번째 문자열 입력: ";
	cin >> str1;
	strInput(&str1);

	cout << "두 번째 문자열 입력: ";
	cin >> str2;
	strInput(&str2);

	//2. 앞에서 입력 받은 두 숫자를 이어 붙여서 출력
	cout << endl << str1 + str2 << endl;

	//3. 앞에서 입력 받은 두 숫자의 합을 출력
	cout << endl << stoi(str1) + stoi(str2) << endl;

	return 0;
}

bool strIntCheck(string* ptr)
{
	string str(*ptr);

	for (int i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i])) //문자 검출
		{
			return false;
		}
	}

	return true; //모두 숫자
}

void strInput(string* ptr)
{
	while (1)
	{
		if (!strIntCheck(ptr))
		{
			cout << "숫자를 입력해주세요." << endl
				<< "[재입력]" << endl;
			cin >> *ptr;
		}
		else break;
	}
}
