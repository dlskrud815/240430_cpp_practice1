#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s = "Codingon";

	//2. ù ��° ���� �ҹ��ڷ� ����
	cout << "ù ��° ���� �ҹ��ڷ�.. ";

	for (int i = 0; i < s.length(); i++)
	{
		s[i] = tolower(s[i]);
	}
	cout << s << endl;

	//3. "ding"�̶�� �κй��ڿ� ��ȯ
	cout << "ding�̶�� �κй��ڿ� ��ȯ.. "
		<< s.substr(2, 4) << endl;

	//4. "coooooon"�� �ǵ��� ����
	int startIndex, endIndex;
	char ch;

	cout << endl << "*������ �ε��� �Է�*" << endl
		<< "��𼭺���? ";
	cin >> startIndex;
	cout << "������? ";
	cin >> endIndex;
	cout << "� ���ڷ�? ";
	cin >> ch;

	for (int i = 0; i < s.length(); i++)
	{
		if (i >= startIndex && i <= endIndex)
		{
			s[i] = ch;
		}
	}
	cout << "coooooon�� �ǵ��� ����.. " << s << endl << endl;

	//5. "con"�� �ǵ��� ����
	cout << endl << "*������ �ε��� �Է�*" << endl
		<< "��𼭺���? ";
	cin >> startIndex;
	cout << "������? ";
	cin >> endIndex;
	s.erase(startIndex, endIndex);
	cout << "con�� �ǵ��� ����.. " << s << endl;

	return 0;
}