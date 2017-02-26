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
	int iCase, iNow;
	char cSur;
	int iN;
	int **ippArr;
	int i, j;
	bool bF;
	
	cin >> iCase;
	iNow = 1;
	while(iNow <= iCase)
		{
		bF = true;
		cin >> cSur >> cSur >> iN;
		
		ippArr = new int* [iN];
		for (i = 0; i < iN; i++)
			ippArr[i] = new int[iN];
		
		for (i = 0; i < iN; i++)
			for (j = 0; j < iN; j++)
				cin >> ippArr[i][j]; 
		
		for (i = 0; i < iN; i++)
			for (j = 0; j < iN; j++)
				if (  ippArr[i][j] != ippArr[iN - i - 1][iN - j - 1]
					||ippArr[i][j] < 0)
					bF = false;
		
		if (bF == true)
			cout << "Test #" << iNow << ": Symmetric." << endl;
		else
			cout << "Test #" << iNow << ": Non-symmetric." << endl;
			
		iNow++;
		}
	return 0;
}
