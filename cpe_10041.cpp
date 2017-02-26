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
int iCase;			//case use
int *ipFamily;		//family use
int iFamilyCount;

int iFamilyMax;
int iFamilyMin;

int iCountTemp;
int iMinTemp;		//answer
int i,j;			//loop used

cin >> iCase;
while (iCase > 0)
	{
	//input
	cin >> iFamilyCount;
	ipFamily = new int[iFamilyCount];
	iFamilyMax = 0;
	iFamilyMin = 30000;
	for (i = 0; i < iFamilyCount; i++)
		{
		cin >> ipFamily[i];
		if (ipFamily[i] > iFamilyMax) iFamilyMax = ipFamily[i];
		if (ipFamily[i] < iFamilyMin) iFamilyMin = ipFamily[i];
		}

	//process
	iMinTemp = 0x7FFFFFFF;
	for (i = iFamilyMin; i < iFamilyMax; i++)
		{
		iCountTemp = 0;
		for (j = 0; j < iFamilyCount; j++)
			iCountTemp += abs(ipFamily[j] - i);
		if (iCountTemp < iMinTemp)
			iMinTemp = iCountTemp;
		}

	//output
	cout << iMinTemp << endl;
	delete ipFamily;
	iCase--;
	}
return 0;
}