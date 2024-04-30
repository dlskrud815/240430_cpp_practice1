#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <time.h>
using namespace std;

//�л� ���� ����ü
struct stdInfo
{
	int stdNo, stdAge, stdKoreanAge;
	string stdName, stdBirth;

	//�ʱ�ȭ
	stdInfo() : stdNo(0), stdAge(0), stdKoreanAge(0) {}
};


void CheckBirthInput(vector <stdInfo>& stdInfoVec, int i);
void CalStudentAge(vector<stdInfo>& stdInfoVec, int i);

void SelectOption_PrintStudentInfo(int option, vector <stdInfo> stdInfoVec);
void SelectOption_PrintStudentAgeAverage(int option, vector <stdInfo> stdInfoVec);
void SelectOption_PrintEarlyBirthday(int option, vector <stdInfo> stdInfoVec);

void PrintStudentInfo(vector<stdInfo> stdInfoVec, int i);

float CalStudentAgeAverage(vector<stdInfo> stdInfoVec);
float CalStudentKoreanAgeAverage(vector<stdInfo> stdInfoVec);

void PrintEarlyBirthdayStudentInfo(vector<stdInfo> stdInfoVec);
void PrintEarlyBirthStudentInfo(vector<stdInfo> stdInfoVec);


int main()
{
	int stdNum, option1, option2;

	cout << "** c++ ���� �ǽ� **" << endl << endl;

	//1. ����ڿ��� �� ���� �л��� �Է��� ������ ����
	cout << "�� ���� �л� ������ �Է�? ";
	cin >> stdNum;
	vector <stdInfo> stdInfoVec(stdNum); //�л� ���� ����ü ����

	//2. �л� ����ŭ "�̸� ���� ����" ������ �� ���� �Է� �ޱ�
	//���̸� �Է� ���� �ʰ� ������Ϸ� �Է� ���� �� ���
	for (int i = 0; i < stdNum; i++)
	{
		if (i == 0)
		{
			cout << endl << "[�Է� ����]" << endl
				<< "0�� �л�" << endl
				<< "�̸�: �̳���" << endl
				<< "�������: 20010815" << endl;
		}

		stdInfoVec[i].stdNo = i + 1;
		
		cout << endl << i + 1 << "�� �л�" << endl << "�̸�: ";
		cin >> stdInfoVec[i].stdName;
		
		cout << "�������: ";
		cin >> stdInfoVec[i].stdBirth;

		//������� Ȯ��
		CheckBirthInput(stdInfoVec, i);

		//������� �����ڸ� ���� Ȯ�� �Ϸ� �� ���� ���
		//���� ��� �� ���Ϳ� ����
		CalStudentAge(stdInfoVec, i);
	}

	//3. 1) �л� ���� ���, 2) ��� ����, 3) ���� ���� ����, 4) ���α׷� ���� �� ���� ��� ��� ����
	//���������̳� ���� ������� �� ��ȸ ������ ���� ��� ��� ����ϵ��� ��
	while (1)
	{
		cout << endl << "[�ɼ�]" << endl
			<< "1) �л� ���� ���, 2) ��� ����, 3) ���� ���� ����, 4) ���α׷� ����" << endl;
		cin >> option1;

		switch (option1)
		{
		case 1:
			cout << endl << "1) ��ü �л� ���� ���, 2) Ư�� �л� ���� ���" << endl;
			cin >> option2;
			SelectOption_PrintStudentInfo(option2, stdInfoVec);
			break;
		case 2:
			cout << endl << "1) �� ���� ��� ���, 2) �� ���� ��� ���" << endl;
			cin >> option2;
			SelectOption_PrintStudentAgeAverage(option2, stdInfoVec);
			break;
		case 3:
			cout << endl << "1) ������ ���� ���� �л� ���� ���, 2) ���̰� ���� ���� �л� ���� ���" << endl;
			cin >> option2;
			SelectOption_PrintEarlyBirthday(option2, stdInfoVec);
			break;
		case 4:
			return 0;
		}
	}
	//�ݺ� �Է� �ʼ�


	return 0;
}


void CheckBirthInput(vector <stdInfo>& stdInfoVec, int i)
{
	while (1)
	{
		bool birthCheck = true;

		if (stdInfoVec[i].stdBirth.size() != 8) //������� �����ڸ��� �ƴ� ���
		{
			cout << endl << "* ������� �����ڸ��� �Է����ּ���." << endl
				<< "[���Է�]" << endl;
			cin >> stdInfoVec[i].stdBirth;
		}
		else //��������� �����ڸ� �� ���
		{
			for (int j = 0; j < stdInfoVec[i].stdBirth.size(); j++) //�Է��� ������Ͽ� ����
			{
				if (!isdigit(stdInfoVec[i].stdBirth[j])) //���ڰ� ����� ���
				{
					cout << endl << "* ��������� ���ڷ� �Է����ּ���." << endl
						<< "[���Է�]" << endl;
					cin >> stdInfoVec[i].stdBirth;

					birthCheck = false;
					break;
				}
			}
			if (birthCheck == true)
			{
				break;
			}
		}
	}
}

void CalStudentAge(vector<stdInfo>& stdInfoVec, int i)//������� �̿� ���� ���
{
	time_t timer = time(NULL);
	struct tm* t = localtime(&timer);
	int age, year, month, date, c_year, c_month, c_date;

	year = stoi(stdInfoVec[i].stdBirth.substr(0, 4));
	month = stoi(stdInfoVec[i].stdBirth.substr(4, 2));
	date = stoi(stdInfoVec[i].stdBirth.substr(6, 2));

	c_year = t->tm_year + 1900;
	c_month = t->tm_mon + 1;
	c_date = t->tm_mday;

	//�� ���� ���
	age = c_year - year;
	stdInfoVec[i].stdKoreanAge = age + 1;

	//������ ���
	if (month - c_month > 0)
	{
		age = age - 1;
	}
	else if (month - c_month == 0)
	{
		if (date - c_date > 0)
		{
			age = age - 1;
		}
	}

	stdInfoVec[i].stdAge = age;
}


void SelectOption_PrintStudentInfo(int option, vector <stdInfo> stdInfoVec)
{
	string stdName;

	switch (option)
	{
	case 1:
		for (int i = 0; i < stdInfoVec.size(); i++)
		{
			PrintStudentInfo(stdInfoVec, i);
		}
		break;
	case 2:
		cout << endl << "�л� �̸�: ";
		cin >> stdName;

		for (int i = 0; i < stdInfoVec.size(); i++)
		{
			if (stdInfoVec[i].stdName == stdName) //���� �� �˻� �̸� ����
			{
				PrintStudentInfo(stdInfoVec, i);
			}
		}
		break;
	}
}

void SelectOption_PrintStudentAgeAverage(int option, vector <stdInfo> stdInfoVec)
{
	switch (option)
	{
	case 1:
		cout << endl << "�л����� ��� �� ���̴�.. "
			<< CalStudentAgeAverage(stdInfoVec) << "��" << endl;
		break;
	case 2:
		cout << endl << "�л����� ��� �� ���̴�.. "
			<< CalStudentKoreanAgeAverage(stdInfoVec) << "��" << endl;
		break;
	}
}

void SelectOption_PrintEarlyBirthday(int option, vector <stdInfo> stdInfoVec)
{
	switch (option)
	{
	case 1:
		cout << endl << "������ ���� ���� �л���.. " << endl;
		PrintEarlyBirthdayStudentInfo(stdInfoVec);
		break;
	case 2:
		cout << endl << "���̰� ���� ���� �л���.. " << endl;
		PrintEarlyBirthStudentInfo(stdInfoVec);
		break;
	}
}


void PrintStudentInfo(vector<stdInfo> stdInfoVec, int i)
{
	cout << endl << stdInfoVec[i].stdNo << "�� �л�" << endl
		<< "�̸�: " << stdInfoVec[i].stdName << endl
		<< "�⳪��: " << stdInfoVec[i].stdKoreanAge << endl
		<< "������: " << stdInfoVec[i].stdAge << endl
		<< "�������: " << stdInfoVec[i].stdBirth << endl;
}


float CalStudentAgeAverage(vector<stdInfo> stdInfoVec)
{
	float ageSum = 0;

	for (int i = 0; i < stdInfoVec.size(); i++)
	{
		ageSum += stdInfoVec[i].stdAge;
	}

	return ageSum / stdInfoVec.size();
}

float CalStudentKoreanAgeAverage(vector<stdInfo> stdInfoVec)
{
	float ageSum = 0;

	for (int i = 0; i < stdInfoVec.size(); i++)
	{
		ageSum += stdInfoVec[i].stdKoreanAge;
	}

	return ageSum / stdInfoVec.size();
}


void PrintEarlyBirthdayStudentInfo(vector<stdInfo> stdInfoVec)
{
	int birth, minBirth = 1231;

	for (int i = 0; i < stdInfoVec.size(); i++)
	{
		birth = stoi(stdInfoVec[i].stdBirth.substr(4));

		if (birth < minBirth)
		{
			minBirth = birth;
		}
	}

	for (int i = 0; i < stdInfoVec.size(); i++)
	{
		birth = stoi(stdInfoVec[i].stdBirth.substr(4));

		if (birth == minBirth)
		{
			PrintStudentInfo(stdInfoVec, i);
		}
	}
}

void PrintEarlyBirthStudentInfo(vector<stdInfo> stdInfoVec)
{
	int birth, minBirth = 99991231;

	for (int i = 0; i < stdInfoVec.size(); i++)
	{
		birth = stoi(stdInfoVec[i].stdBirth);

		if (birth < minBirth)
		{
			minBirth = birth;
		}
	}

	for (int i = 0; i < stdInfoVec.size(); i++)
	{
		birth = stoi(stdInfoVec[i].stdBirth);

		if (birth == minBirth)
		{
			PrintStudentInfo(stdInfoVec, i);
		}
	}
}