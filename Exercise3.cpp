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
	for (int i = 0; i < s.length(); i++)
	{
		if (i >= 1 && i <= 5)
		{
			s[i] = 'o';
		}
	}
	cout << "coooooon�� �ǵ��� ����.. " << s << endl;

	//5. "con"�� �ǵ��� ����
	s.erase(1, 5);
	cout << "con�� �ǵ��� ����.. " << s << endl;

	return 0;
}