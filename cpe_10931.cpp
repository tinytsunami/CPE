//============================================================
// 標頭檔
//============================================================
#include <iostream>
//============================================================
// 命名空間
//============================================================
using namespace std;
//============================================================
// 主程式
//============================================================
int main()
{
int iInput;		// 使用者輸入
int iCount;		// 計數
int iBit[32];	// 每個位元的bit
int iIndex;		// 紀載iBit目前的位置

while (cin >> iInput)
	{
	//exit
	if (iInput==0) 
		break;

	//initialize
	iCount = 0;
	iIndex = 0;

	//process
	while (iInput > 0)
		{
		iBit[iIndex] = iInput % 2;
		iCount += iInput % 2;
		iInput /= 2;
		iIndex++;
		}

	//output
	cout << "The parity of ";
	while (iIndex > 0)
		{
		iIndex--;
		cout << iBit[iIndex];
		}
	cout << " is " << iCount << " (mod 2)." << endl;
	}
return 0;
}
