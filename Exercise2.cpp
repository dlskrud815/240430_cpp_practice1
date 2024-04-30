#include <iostream>
#include <string>
using namespace std;

bool strIntCheck(string* ptr);
void strInput(string* ptr);

int main()
{
	string str1, str2;

	//1. �� ���ڿ��� �Է� �޾Ƽ� �� ��� �������� �˻�, �ƴϸ� �ٽ� �Է� �޵���
	cout << "ù ��° ���ڿ� �Է�: ";
	cin >> str1;
	strInput(&str1);

	cout << "�� ��° ���ڿ� �Է�: ";
	cin >> str2;
	strInput(&str2);

	//2. �տ��� �Է� ���� �� ���ڸ� �̾� �ٿ��� ���
	cout << endl << str1 + str2 << endl;

	//3. �տ��� �Է� ���� �� ������ ���� ���
	cout << endl << stoi(str1) + stoi(str2) << endl;

	return 0;
}

bool strIntCheck(string* ptr)
{
	string str(*ptr);

	for (int i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i])) //���� ����
		{
			return false;
		}
	}

	return true; //��� ����
}

void strInput(string* ptr)
{
	while (1)
	{
		if (!strIntCheck(ptr))
		{
			cout << "���ڸ� �Է����ּ���." << endl
				<< "[���Է�]" << endl;
			cin >> *ptr;
		}
		else break;
	}
}
