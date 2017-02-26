//============================================================
// 標頭檔
//============================================================
#include <stdio.h>
#include <cmath>
//============================================================
// 如電子電路中、全加器運算的進位
// Input  iNumberA   : 數字A（個位數）
// Input  iNumberB   : 數字B（個位數）
// Output iCarry     : 進位的數（兩個個位數最多就回傳「1」）
//============================================================
int iBothAdd(int iNumberA, int iNumberB)
{
int iCarry; //進位的數
iCarry = (iNumberA + iNumberB) / 10;
return iCarry;
}
//============================================================
// 取得得到數字的位數
// Input  iNumber: 數字
// Output iDigit : 數字的位數
//============================================================
int iGetDigit(int iNumber)
{
int iDigit = 0;

while ((iNumber / pow(10, iDigit)) >= 1)
	iDigit++;

return iDigit;
}
//============================================================
// 將數字分割成個位的陣列
// Input  *iEachNumber: 數字陣列，透過指標直接存入
//                      （不符條件的位置將被設為「-1」）
// Input  Number      : 數字
// Output NULL        : 無
//============================================================
void vCreateEachNumber(int *iEachNumber, int iNumber)
{
int i;//Loop Used

for (i = iGetDigit(iNumber); i > 0; i--)
	{
	iEachNumber[10 - i] = iNumber % 10;
	iNumber /= 10;
	}

for (i = 0; i < 10; i++)
	if (iEachNumber[i] < 0 || iEachNumber[i] >= 10)
		iEachNumber[i] = -1;
}
//============================================================
// 反轉陣列
// Input  *arriArray: 陣列，直接透過指標反轉
//                   （將「-1」當作空位址操作）
// Output NULL      : 無
//============================================================
void vReverseArray(int *arriArray)
{
int iPosition = 0;	// 陣列的位置
int i;				// Loop Used

for (i = 0; i < 10; i++)
	{
	if (arriArray[i] != -1)
		{
		arriArray[iPosition] = arriArray[i];
		arriArray[i] = -1;
		iPosition += 1;
		}
	}

for (i = 0; i < 10; i++)
	{
	if (arriArray[i] == -1)
		arriArray[i] = 0;
	}
}
//============================================================
// 主程式
//============================================================
int main(void)
{
int iNumberA;			// 數字A
int iNumberB;			// 數字B
int iEachNumberA[10];	// 將數字A分解成個位數陣列
int iEachNumberB[10];	// 將數字B分解成個位數陣列
int iCarryCount = 0;	// 紀錄進位的總數
int iCarryTemp = 0;		// 進位的數
int i;					//Loop Used

//輸入兩個數字
while (scanf_s("%d %d", &iNumberA, &iNumberB))
	{
	//都為零就結束
	if (iNumberA == 0 && iNumberB == 0)
		break;

	//將數字分解成陣列
	vCreateEachNumber(iEachNumberA, iNumberA);
	vCreateEachNumber(iEachNumberB, iNumberB);

	//將陣列反轉，把個位數移到第一位
	vReverseArray(iEachNumberA);
	vReverseArray(iEachNumberB);

	//用每一位計算
	for (i = 0; i < 10; i++)
		{
		iCarryTemp = iBothAdd(iEachNumberA[i], iEachNumberB[i] + iCarryTemp);
		iCarryCount += iCarryTemp;
		}

	//輸出計算資料
	if (iCarryCount > 0)
		{
		if (iCarryCount > 1)
			printf("%d carry operations.\n", iCarryCount);
		else
			printf("%d carry operation.\n", iCarryCount);
		}
	else
		printf("No carry operation.\n");

	//使用後把訊息規零
	iCarryCount = 0;
	for (i = 0; i < 10; i++)
		iEachNumberA[i] = -1;
	for (i = 0; i < 10; i++)
		iEachNumberB[i] = -1;
	}

return 0;
}