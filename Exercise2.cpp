#include <iostream>
#include <string>
using namespace std;

bool strIntCheck(string* ptr);
void strInput(string* ptr);

int main()
{
	string str1, str2;
	int num1, num2;

	//1. �� ���ڿ��� �Է� �޾Ƽ� �� ��� �������� �˻�, �ƴϸ� �ٽ� �Է� �޵���
	cout << "ù ��° ���ڿ� �Է�: ";
	cin >> str1;
	strInput(&str1);

	cout << "�� ��° ���ڿ� �Է�: ";
	cin >> str2;
	strInput(&str2);
	
	num1 = stoi(str1);
	num2 = stoi(str2);

	//2. �տ��� �Է� ���� �� ���ڸ� �̾� �ٿ��� ���
	cout << endl << str1.append(str2) << endl;

	//3. �տ��� �Է� ���� �� ������ ���� ���
	cout << endl << num1 + num2 << endl;

	return 0;
}

bool strIntCheck(string* ptr)
{
	int check = 0;
	string str(*ptr);


	for (int i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			check++;
		}
	}

	if (check == 0) //��� ����
	{
		return true;
	}
	else return false;
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
