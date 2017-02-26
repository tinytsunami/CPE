//============================================================
// 標頭檔
//============================================================
#include <iostream>
//============================================================
// 命名空間
//============================================================
using namespace std;
//============================================================
// 執行3n+1規定的操作
// input : 給定3n+1的n
// output: 執行的次數
//============================================================
int iThreeNaddOne(int iN)
{
int iLenght = 0;	//執行的次數
while(iN > 1)
	{
	if(iN % 2 == 1)
		iN = iN * 3 + 1;
	else
		iN /= 2;
	iLenght++;
	}
return iLenght;
}
//============================================================
// 主程式
//============================================================
int main()
{
int iRangeBegin,	// 數字的下邊界
	iRangeEnd,		// 數字的上邊界
	iLenghtTemp,	// 暫存處理次數的變數
	iMaxSave;		// 儲存最大處理
int i;				// Loop used

while (cin >> iRangeBegin >> iRangeEnd)
	{
	//initizalize
	iMaxSave = 0;
	//由於等等可能會交換上下邊界，這邊先做輸出
	cout << iRangeBegin << " " << iRangeEnd << " " ;
	//如果下邊界大過上邊界，則兩者交換
	if (iRangeBegin > iRangeEnd)
		{
		//兩者交換
		iRangeBegin ^= iRangeEnd;
		iRangeEnd ^= iRangeBegin;
		iRangeBegin ^= iRangeEnd;
		}
	//process
	for(i = iRangeBegin; i <= iRangeEnd; i++)
		{
		iLenghtTemp = iThreeNaddOne(i);
		if (iLenghtTemp > iMaxSave)
			iMaxSave = iLenghtTemp;
		}
	//包含邊界本身，再+1
	cout << (iMaxSave + 1) << endl;
	}
return 0;
}