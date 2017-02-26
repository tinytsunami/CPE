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
int iDividend;	//被除數
int iDivisor;	//除數
int iTemp;		//暫時儲存被除數用

//process
while (cin >> iDividend >> iDivisor)
	{
	//exception
	if (iDivisor == 0 || iDivisor == 1)
		{
		cout << "Boring!" << endl;
		continue;
		}

	//save dividend
	iTemp = iDividend;

	//get last item
	while (iDividend % iDivisor == 0)
		iDividend /= iDivisor;

	//boring or not
	if (iDividend == 1)
		{
		//output all sequence
		iDividend = iTemp;
		while (iDividend > 1)
			{
			cout << iDividend << " ";
			iDividend /= iDivisor;
			}
		cout << iDividend << endl;
		}
	else
		cout << "Boring!" << endl;
	}
return 0;
}