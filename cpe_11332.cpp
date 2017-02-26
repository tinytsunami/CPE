//============================================================
// 標頭檔
//============================================================
#include <iostream>
//============================================================
// 命名空間
//============================================================
using namespace std;
//============================================================
// 每一位數字和
// Input: number
// Output: sum (digits of number)
//============================================================
int iNumberSum (int iNumber)
{
int iCount = 0;
while (iNumber > 0)
	{
	iCount += iNumber % 10;
	iNumber /= 10;
	}
return iCount;
}
//============================================================
// 主程式
//============================================================
int main()
{
int iNumber;
while (cin >> iNumber)
	{
	//exit
	if (iNumber == 0)
		break;
	//process
	while (iNumber >= 10)
		iNumber = iNumberSum(iNumber);
	//output
	cout << iNumber << endl;
	}
return 0;
}