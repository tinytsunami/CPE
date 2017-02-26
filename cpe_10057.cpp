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
int iCount;
int *ipSeqence;	//Q's X1~Xn

int iXnMax;		//Xn's Max
int iXnMin;		//..

int iSumTemp;	// = |X1-A| + |X2-A| +...+ |Xn-A|
int iSumMin;

int iMinA;
int iSameCount;
int iPossibleCount;

int i,j;		//loop used

while (cin >> iCount)
	{
	iXnMax = 0;
	iXnMin = 65536;

	//input
	ipSeqence = new int[iCount];
	for (i = 0; i < iCount; i++)
		{
		cin >> ipSeqence[i];
		if (ipSeqence[i] > iXnMax) iXnMax = ipSeqence[i];
		if (ipSeqence[i] < iXnMin) iXnMin = ipSeqence[i];
		}

	//process
	iSumMin = 65536;
	iMinA = iXnMax;
	iSameCount = 0;
	iPossibleCount = 0;
	for (i = iXnMin; i <= iXnMax; i++)
		{
		iSumTemp = 0;
		for (j = 0; j < iCount; j++)
			iSumTemp += abs(ipSeqence[j] - i);
		if (iSumTemp < iSumMin)
			{
			//the A change
			iMinA = i;
			//re-calc
			iSameCount = 0;
			for (j = 0; j < iCount; j++)
				if (ipSeqence[j] == i)
					iSameCount++;
			//iPossibleCount >= 1
			iPossibleCount = 1;
			//save min
			iSumMin = iSumTemp;
			}
		else if (iSumTemp == iSumMin)
			{
			//a new A.
			iPossibleCount++;
			//find new A, and check same number in seqence.
			for (j = 0; j < iCount; j++)
				if (ipSeqence[j] == i)
					iSameCount++;
			}
		}

	//format
	printf("%d %d %d\n",iMinA,iSameCount,iPossibleCount);
	}
return 0;
}