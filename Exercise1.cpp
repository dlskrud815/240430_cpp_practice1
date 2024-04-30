#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s = "Police say two people are suspected of trying to create a shortcut for their construction work.The two have been detained and the case is under further investigation.The 38-year-old man and 55-year-old woman were working near the affected area, the 32nd Great Wall.";

	//2. s 문자열의 길이 출력
	cout << "문자열의 길이: " << s.length() << endl;

	//3. 100번째 문자 출력(index는 0부터 시작)
	int input;
	cout << "몇 번째 문자? ";
	cin >> input;
	cout << input << "번째 문자 : " << s[input - 1] << endl;

	//4. "two"라는 문자가 처음 나오는 index 출력
	cout << "two라는 문자가 처음 나오는 index: " << s.find("two") << endl;

	//5. "two"라는 문자가 두번째 나오는 index 출력
	cout << "two라는 문자가 두번째 나오는 index: " << s.find("two", s.find("two")+1) << endl;

	return 0;
}