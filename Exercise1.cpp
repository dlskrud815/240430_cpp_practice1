#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s = "Police say two people are suspected of trying to create a shortcut for their construction work.The two have been detained and the case is under further investigation.The 38-year-old man and 55-year-old woman were working near the affected area, the 32nd Great Wall.";

	//2. s ���ڿ��� ���� ���
	cout << "���ڿ��� ����: " << s.length() << endl;

	//3. 100��° ���� ���(index�� 0���� ����)
	int input;
	cout << "�� ��° ����? ";
	cin >> input;
	cout << input << "��° ���� : " << s[input - 1] << endl;

	//4. "two"��� ���ڰ� ó�� ������ index ���
	cout << "two��� ���ڰ� ó�� ������ index: " << s.find("two") << endl;

	//5. "two"��� ���ڰ� �ι�° ������ index ���
	cout << "two��� ���ڰ� �ι�° ������ index: " << s.find("two", s.find("two")+1) << endl;

	return 0;
}