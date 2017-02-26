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
// 反轉數字
// Input: number
// Output: number(reverse)
//============================================================
int iReverse(int iNumber)
{
int iNewNumber = 0;
int iTemp = iNumber;
int iNumberEx = 0;
int i;

while(iNumber > 0)
	{
	iNumberEx++;
	iNumber /= 10;
	}

iNumber = iTemp;
for(i = 1; i <= iNumberEx; i++)
	{
	iNewNumber += (iNumber % 10) * pow(10, iNumberEx - i);
	iNumber /= 10;
	}
	
return iNewNumber;
}
//============================================================
// 識別質數
// Input: number
// Output: bool (Is number prime?)
//============================================================
bool bIsPrime(int iNumber)
{
int i;
for(i = 2;i < (iNumber/2); i++)
	if(iNumber % i == 0)
		return false;
return true;
}
//============================================================
// 主程式
//============================================================
int main()
{
int iNumber;
bool bPrime;
bool bEmirp;
while(cin >> iNumber)
	{
	bPrime = bEmirp = false;
	
	bPrime = bIsPrime(iNumber);
	
	iNumber = iReverse(iNumber);
	bEmirp = bIsPrime(iNumber);
	iNumber = iReverse(iNumber);
	
	if(bEmirp == true && bPrime == true)
		cout << iNumber << " is emirp." << endl;
	if(bEmirp == false && bPrime == true)
		cout << iNumber << " is prime." << endl;
	if(bEmirp == false && bPrime == false)
		cout << iNumber << " is not prime." << endl;
	
	}
return 0;
}
