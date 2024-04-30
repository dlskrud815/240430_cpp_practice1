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
void CalStudentAgeAndInput(vector<stdInfo>& stdInfoVec, int i);

void SelectOption_PrintStudentInfo(int option, vector <stdInfo> stdInfoVec);
void SelectOption_PrintStudentAgeAverage(int option, vector <stdInfo> stdInfoVec);
void SelectOption_PrintEarlyBirthday(int option, vector <stdInfo> stdInfoVec);
void SelectOption_EditStudentInfo(int option, int editStdNum, vector <stdInfo>& stdInfoVec);

void PrintStudentInfo(vector<stdInfo> stdInfoVec, int i);

float CalStudentAgeAverage(vector<stdInfo> stdInfoVec, bool useKoreanAge);

void PrintEarlyBirthStudentInfo(vector<stdInfo> stdInfoVec, bool useYear);


int main()
{
	int stdNum, option1, option2, editStdNum;

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

		//�л� ��ȣ �ڵ� ���� �ο�
		stdInfoVec[i].stdNo = i + 1;
		
		//�л� �̸� �Է�
		cout << endl << i + 1 << "�� �л�" << endl << "�̸�: ";
		cin >> stdInfoVec[i].stdName;
		
		//�л� ������� �����ڸ� �Է�
		cout << "�������: ";
		cin >> stdInfoVec[i].stdBirth;

		//������� �ڸ��� �� ���� ���� Ȯ��
		CheckBirthInput(stdInfoVec, i);

		//���� ��� �� ���Ϳ� ����
		CalStudentAgeAndInput(stdInfoVec, i);
	}

	//3. 1) �л� ���� ���, 2) ��� ����, 3) ���� ���� ����, 4) ���α׷� ���� �� ���� ��� ��� ����
	//���������̳� ���� ������� �� ��ȸ ������ ���� ��� ��� ����ϵ��� ��
	while (1)
	{
		cout << endl << "[�ɼ�]" << endl
			<< "1) �л� ���� , 2) ��� ����, 3) ���� ���� ����, 4) ���α׷� ����, 0) �Է� ���� ����" << endl;
		cin >> option1;

		switch (option1)
		{
		case 1: //1) �л� ����
			cout << endl << "1) ��ü �л� ���� ���, 2) Ư�� �л� ���� ���" << endl;
			cin >> option2;
			SelectOption_PrintStudentInfo(option2, stdInfoVec);
			break;
		case 2: //2) ��� ����
			cout << endl << "1) �� ���� ��� ���, 2) �� ���� ��� ���" << endl;
			cin >> option2;
			SelectOption_PrintStudentAgeAverage(option2, stdInfoVec);
			break;
		case 3: //3) ���� ���� ����
			cout << endl << "1) ������ ���� ���� �л� ���� ���, 2) ���̰� ���� ���� �л� ���� ���" << endl;
			cin >> option2;
			SelectOption_PrintEarlyBirthday(option2, stdInfoVec);
			break;
		case 4: //4) ���α׷� ����
			return 0;
		case 0: //0) �Է� �� ����
			cout << endl << "���� ������ ���ϴ� �л� ��ȣ��.. ";
			cin >> editStdNum;
			
			while (1)
			{
				if (editStdNum <= 0 || editStdNum > stdInfoVec.size())
				{
					cout << endl << "* �ش� ��ȣ�� �л��� �������� �ʽ��ϴ�. " << endl
						<< endl << "[���Է�]" << endl
						<< "���� ������ ���ϴ� �л� ��ȣ��.. ";
					cin >> editStdNum;
				}
				else break;
			}
			
			cout << endl << "1) �̸� ����, 2) ������� ����" << endl;
			cin >> option2;
			SelectOption_EditStudentInfo(option2, editStdNum, stdInfoVec);
		}
	}

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

void CalStudentAgeAndInput(vector<stdInfo>& stdInfoVec, int i)//������� �̿� ���� ���
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
	case 1: //1) ��ü �л� ���� ���
		for (int i = 0; i < stdInfoVec.size(); i++)
		{
			PrintStudentInfo(stdInfoVec, i);
		}
		break;
	case 2: //2) Ư�� �л� ���� ���
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
	bool useKoreanAge;

	switch (option)
	{
	case 1: //1) �� ���� ��� ���
		cout << endl << "�л����� ��� �� ���̴�.. "
			<< CalStudentAgeAverage(stdInfoVec, useKoreanAge = false) << "��" << endl;
		break;
	case 2: //2) �� ���� ��� ���
		cout << endl << "�л����� ��� �� ���̴�.. "
			<< CalStudentAgeAverage(stdInfoVec, useKoreanAge = true) << "��" << endl;
		break;
	}
}

void SelectOption_PrintEarlyBirthday(int option, vector <stdInfo> stdInfoVec)
{
	bool useYear;

	switch (option)
	{
	case 1: //1) ������ ���� ���� �л� ���� ���
		cout << endl << "������ ���� ���� �л���.. " << endl;
		PrintEarlyBirthStudentInfo(stdInfoVec, useYear = false);
		break;
	case 2: //2) ���̰� ���� ���� �л� ���� ���
		cout << endl << "���̰� ���� ���� �л���.. " << endl;
		PrintEarlyBirthStudentInfo(stdInfoVec, useYear = true);
		break;
	}
}


void SelectOption_EditStudentInfo(int option, int editStdNum, vector <stdInfo>& stdInfoVec)
{
	switch (option)
	{
	case 1:
		for (int i = 0; i < stdInfoVec.size(); i++)
		{
			if (stdInfoVec[i].stdNo == editStdNum)
			{
				cout << endl << "�̸���.. ";
				cin >> stdInfoVec[i].stdName;
			}
		}
		break;
	case 2:
		for (int i = 0; i < stdInfoVec.size(); i++)
		{
			if (stdInfoVec[i].stdNo == editStdNum)
			{
				cout << endl << "���������.. ";
				cin >> stdInfoVec[i].stdBirth;

				//������� �ڸ��� �� ���� ���� Ȯ��
				CheckBirthInput(stdInfoVec, i);

				//���� ��� �� ���Ϳ� ����
				CalStudentAgeAndInput(stdInfoVec, i);
			}
		}
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


float CalStudentAgeAverage(vector<stdInfo> stdInfoVec, bool useKoreanAge)
{
	float ageSum = 0;

	for (int i = 0; i < stdInfoVec.size(); i++)
	{
		ageSum += useKoreanAge ? stdInfoVec[i].stdKoreanAge : stdInfoVec[i].stdAge;
	}

	return ageSum / stdInfoVec.size();
}


void PrintEarlyBirthStudentInfo(vector<stdInfo> stdInfoVec, bool useYear)
{
	int birth, minBirth = useYear ? 99991231 : 1231;

	for (int i = 0; i < stdInfoVec.size(); i++)
	{
		birth = useYear ? stoi(stdInfoVec[i].stdBirth) : stoi(stdInfoVec[i].stdBirth.substr(4));

		if (birth < minBirth)
		{
			minBirth = birth;
		}
	}

	for (int i = 0; i < stdInfoVec.size(); i++)
	{
		birth = useYear ? stoi(stdInfoVec[i].stdBirth) : stoi(stdInfoVec[i].stdBirth.substr(4));

		if (birth == minBirth)
		{
			PrintStudentInfo(stdInfoVec, i);
		}
	}
}