//============================================================
// 標頭檔
//============================================================
#include <iostream>
#include <cmath>
//============================================================
// 命名空間
//============================================================
using namespace std;
//============================================================
// 找最大公因數
// Input: a, b
// Output: GCD(a, b)
//============================================================
int iGCD(int a, int b)
{
int t;
while(b != 0)
	{
	t = b;
	b = a % b;
	a = t;
	}
return a;
}
//============================================================
// 轉成十進制
// Input: number(2)
// Output: number(10)
//============================================================
int iToDec(int iNumber)
{
int iTemp;
int iDec;
int iEx; 

iDec = 0;
iEx = 0;
while(iNumber > 0)
	{
	iTemp = iNumber % 10;
	iNumber /= 10;
	iDec += iTemp * pow(2, iEx);
	iEx++;
	}

return iDec;
}
//============================================================
// 團體結構
//============================================================
struct Group
{
int iS;
int iT;
};
//============================================================
// 主程式
//============================================================
int main() 
{
int iCase;
Group *gSeq;
int iE;
int i;
	
cin >> iCase;
	
gSeq = new Group[iCase];
for(i=0;i<iCase;i++)
	{
	cin >> gSeq[i].iS >> gSeq[i].iT;
		
	gSeq[i].iS = iToDec(gSeq[i].iS);
	gSeq[i].iT = iToDec(gSeq[i].iT);
	

	iE = iGCD(gSeq[i].iS, gSeq[i].iT);
	
	if(iE == 1)
		cout << "Pair #" << i << ": " << "Love is not all you need!" << endl;
	else
		cout << "Pair #" << i << ": " << "All you need is love!" << endl;
		
	}

return 0;
}
