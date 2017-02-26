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
	int iCase;
	int iSize;
	int *ipSeq = 0;
	int iCount;
	int i, j;
	
	cin >> iCase;
	while (iCase--)
		{
		//Initialize
		iCount = 0;
		
		//Input
		cin >> iSize;
		ipSeq = new int[iSize];
		for (i = 0; i < iSize; i++)
			cin >> ipSeq[i];
			
		//process 
		for (i = 0; i < iSize; i++)
			for (j = i; j < iSize; j++)
				if (ipSeq[i] > ipSeq[j])
					{
					ipSeq[i] ^= ipSeq[j] ^= ipSeq[i] ^= ipSeq[j];
					iCount++;
					}
		//output
		cout << "Optimal train swapping takes " << iCount << " swaps." << endl;
		
		//finish
		delete ipSeq;
		}
	return 0;
}
