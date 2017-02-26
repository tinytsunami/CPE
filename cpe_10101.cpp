//============================================================
// 標頭檔
//============================================================
#include <iostream>
#include <string>
//============================================================
// 命名空間
//============================================================
using namespace std;
//============================================================
// 主程式
//============================================================
int main()
{
	string strInput;
	int iDigit[4] = {2, 2, 1, 2};
	int iSize, iMaxDigit, iTemp;
	int i;
	
	while (cin >> strInput)
		{
		iSize = strInput.length();
		iMaxDigit = 6 - (iSize - 2) % 7;
		for (i = 0; i < 4; i++)
			if (iMaxDigit > 0)
				{
				iMaxDigit -= iDigit[i];
				iTemp = i;
				}
			else
				break;
		cout << iTemp;
		/*iMaxDigit = (iSize - 2) % 7;	
			
		for (i = 0; i < iSize - 2; i++)
			{
			
			iTemp = iDigit[];
			cout << strInput[i];
			
			}
		cout << strInput[i - 2];
		cout << strInput[i - 1];
		*/
		}
		
	return 0;
}

