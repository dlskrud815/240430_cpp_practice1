#include <iostream>
#include <string>
using namespace std;

bool CheckOnlyInt(string* ptr);
void InputLoop(string* ptr);

int main()
{
	string str1, str2;

	//1. �� ���ڿ��� �Է� �޾Ƽ� �� ��� �������� �˻�, �ƴϸ� �ٽ� �Է� �޵���
	cout << "ù ��° ���ڿ� �Է�: ";
	cin >> str1;
	InputLoop(&str1);

	cout << "�� ��° ���ڿ� �Է�: ";
	cin >> str2;
	InputLoop(&str2);

	//2. �տ��� �Է� ���� �� ���ڸ� �̾� �ٿ��� ���
	cout << endl << str1 + str2 << endl;

	//3. �տ��� �Է� ���� �� ������ ���� ���
	cout << endl << stoi(str1) + stoi(str2) << endl;

	return 0;
}

bool CheckOnlyInt(string* ptr)
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

void InputLoop(string* ptr)
{
	while (1)
	{
		if (!CheckOnlyInt(ptr))
		{
			cout << "���ڸ� �Է����ּ���." << endl
				<< "[���Է�]" << endl;
			cin >> *ptr;
		}
		else break;
	}
}
