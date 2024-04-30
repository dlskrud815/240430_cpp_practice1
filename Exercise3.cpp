#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s = "Codingon";

	//2. 첫 번째 문자 소문자로 변경
	cout << "첫 번째 문자 소문자로.. ";

	for (int i = 0; i < s.length(); i++)
	{
		s[i] = tolower(s[i]);
	}
	cout << s << endl;

	//3. "ding"이라는 부분문자열 반환
	cout << "ding이라는 부분문자열 반환.. "
		<< s.substr(2, 4) << endl;

	//4. "coooooon"이 되도록 변경
	int startIndex, endIndex;
	char ch;

	cout << endl << "*변경할 인덱스 입력*" << endl
		<< "어디서부터? ";
	cin >> startIndex;
	cout << "어디까지? ";
	cin >> endIndex;
	cout << "어떤 문자로? ";
	cin >> ch;

	for (int i = 0; i < s.length(); i++)
	{
		if (i >= startIndex && i <= endIndex)
		{
			s[i] = ch;
		}
	}
	cout << "coooooon이 되도록 변경.. " << s << endl << endl;

	//5. "con"이 되도록 변경
	cout << endl << "*삭제할 인덱스 입력*" << endl
		<< "어디서부터? ";
	cin >> startIndex;
	cout << "어디까지? ";
	cin >> endIndex;
	s.erase(startIndex, endIndex);
	cout << "con이 되도록 변경.. " << s << endl;

	return 0;
}