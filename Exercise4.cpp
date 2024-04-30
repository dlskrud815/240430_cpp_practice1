#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <time.h>
using namespace std;

//학생 정보 구조체
struct stdInfo
{
	int stdNo, stdAge, stdKoreanAge;
	string stdName, stdBirth;

	//초기화
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

	cout << "** c++ 종합 실습 **" << endl << endl;

	//1. 사용자에게 몇 명의 학생을 입력할 것인지 묻기
	cout << "몇 명의 학생 정보를 입력? ";
	cin >> stdNum;
	vector <stdInfo> stdInfoVec(stdNum); //학생 정보 구조체 벡터

	//2. 학생 수만큼 "이름 나이 생일" 순서로 한 번에 입력 받기
	//나이를 입력 받지 않고 생년월일로 입력 받은 후 계산
	for (int i = 0; i < stdNum; i++)
	{
		if (i == 0)
		{
			cout << endl << "[입력 예시]" << endl
				<< "0번 학생" << endl
				<< "이름: 이나경" << endl
				<< "생년월일: 20010815" << endl;
		}

		stdInfoVec[i].stdNo = i + 1;
		
		cout << endl << i + 1 << "번 학생" << endl << "이름: ";
		cin >> stdInfoVec[i].stdName;
		
		cout << "생년월일: ";
		cin >> stdInfoVec[i].stdBirth;

		//생년월일 확인
		CheckBirthInput(stdInfoVec, i);

		//생년월일 여섯자리 숫자 확인 완료 후 나이 계산
		//나이 계산 후 벡터에 넣음
		CalStudentAge(stdInfoVec, i);
	}

	//3. 1) 학생 정보 출력, 2) 평균 나이, 3) 가장 빠른 생일, 4) 프로그램 종료 네 가지 기능 모두 구현
	//동명이인이나 같은 생년월일 등 조회 조건이 같을 경우 모두 출력하도록 함
	while (1)
	{
		cout << endl << "[옵션]" << endl
			<< "1) 학생 정보 출력, 2) 평균 나이, 3) 가장 빠른 생일, 4) 프로그램 종료" << endl;
		cin >> option1;

		switch (option1)
		{
		case 1:
			cout << endl << "1) 전체 학생 정보 출력, 2) 특정 학생 정보 출력" << endl;
			cin >> option2;
			SelectOption_PrintStudentInfo(option2, stdInfoVec);
			break;
		case 2:
			cout << endl << "1) 만 나이 평균 출력, 2) 년 나이 평균 출력" << endl;
			cin >> option2;
			SelectOption_PrintStudentAgeAverage(option2, stdInfoVec);
			break;
		case 3:
			cout << endl << "1) 생일이 가장 빠른 학생 정보 출력, 2) 나이가 가장 많은 학생 정보 출력" << endl;
			cin >> option2;
			SelectOption_PrintEarlyBirthday(option2, stdInfoVec);
			break;
		case 4:
			return 0;
		}
	}
	//반복 입력 필수


	return 0;
}


void CheckBirthInput(vector <stdInfo>& stdInfoVec, int i)
{
	while (1)
	{
		bool birthCheck = true;

		if (stdInfoVec[i].stdBirth.size() != 8) //생년월일 여덟자리가 아닐 경우
		{
			cout << endl << "* 생년월일 여덟자리를 입력해주세요." << endl
				<< "[재입력]" << endl;
			cin >> stdInfoVec[i].stdBirth;
		}
		else //생년월일이 여덟자리 일 경우
		{
			for (int j = 0; j < stdInfoVec[i].stdBirth.size(); j++) //입력한 생년월일에 대해
			{
				if (!isdigit(stdInfoVec[i].stdBirth[j])) //문자가 검출될 경우
				{
					cout << endl << "* 생년월일을 숫자로 입력해주세요." << endl
						<< "[재입력]" << endl;
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

void CalStudentAge(vector<stdInfo>& stdInfoVec, int i)//생년월일 이용 나이 계산
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

	//년 나이 계산
	age = c_year - year;
	stdInfoVec[i].stdKoreanAge = age + 1;

	//만나이 계산
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
		cout << endl << "학생 이름: ";
		cin >> stdName;

		for (int i = 0; i < stdInfoVec.size(); i++)
		{
			if (stdInfoVec[i].stdName == stdName) //벡터 내 검색 이름 존재
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
		cout << endl << "학생들의 평균 만 나이는.. "
			<< CalStudentAgeAverage(stdInfoVec) << "세" << endl;
		break;
	case 2:
		cout << endl << "학생들의 평균 년 나이는.. "
			<< CalStudentKoreanAgeAverage(stdInfoVec) << "세" << endl;
		break;
	}
}

void SelectOption_PrintEarlyBirthday(int option, vector <stdInfo> stdInfoVec)
{
	switch (option)
	{
	case 1:
		cout << endl << "생일이 가장 빠른 학생은.. " << endl;
		PrintEarlyBirthdayStudentInfo(stdInfoVec);
		break;
	case 2:
		cout << endl << "나이가 가장 많은 학생은.. " << endl;
		PrintEarlyBirthStudentInfo(stdInfoVec);
		break;
	}
}


void PrintStudentInfo(vector<stdInfo> stdInfoVec, int i)
{
	cout << endl << stdInfoVec[i].stdNo << "번 학생" << endl
		<< "이름: " << stdInfoVec[i].stdName << endl
		<< "년나이: " << stdInfoVec[i].stdKoreanAge << endl
		<< "만나이: " << stdInfoVec[i].stdAge << endl
		<< "생년월일: " << stdInfoVec[i].stdBirth << endl;
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