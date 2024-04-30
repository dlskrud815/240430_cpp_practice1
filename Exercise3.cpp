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
	for (int i = 0; i < s.length(); i++)
	{
		if (i >= 1 && i <= 5)
		{
			s[i] = 'o';
		}
	}
	cout << "coooooon이 되도록 변경.. " << s << endl;

	//5. "con"이 되도록 변경
	s.erase(1, 5);
	cout << "con이 되도록 변경.. " << s << endl;

	return 0;
}