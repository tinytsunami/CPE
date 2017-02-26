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
int iRangeBegin;		//下界
int iRangeEnd;			//上界
int iCount;				//計數
int iTemp;				//下邊界的根號開始

long long int lliSquare;	//平方

while (cin >> iRangeBegin >> iRangeEnd)
	{
	//exit
	if (iRangeBegin==0 && iRangeEnd==0) 
		break;

	//initialize
	iCount = 0;
	iTemp = 0;

	//process
	do
		{
		iTemp++;
		lliSquare = iTemp * iTemp;
		if(lliSquare >= iRangeBegin && lliSquare <= iRangeEnd)
			iCount++;
		} while (lliSquare < iRangeEnd);

	//output
	cout << iCount << endl;
	}
return 0;
}
