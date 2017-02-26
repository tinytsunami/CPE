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
int iDate;     //日
int iMonth;    //月，但同時代表日
int iCount;    //測資總數

cin >> iCount;
while (iCount > 0)
    {
    cin >> iMonth >> iDate;

    //process
    if (iMonth % 2 == 1)    //奇數月基準在到偶數月上
        if(iMonth < 8)    //8月前的奇數月是大月，反之
            iDate = -((31 - iDate) + (iMonth + 1)); // 計算少幾天
        else
            iDate = -((30 - iDate) + (iMonth + 1)); // 計算少幾天
    else // 偶數月
        iDate = iDate - iMonth; // 計算多幾天或少幾天

    // 二月沒有基準日期，已計算1、2月跟2/2的差
    // 計算偏移量在4/4
    // 2/2到2/28還有26天、3月完全度過31天、以及4/1到4/4的日子
    if (iMonth == 1||iMonth == 2)
        iDate -= (26 + 31 + 4); 

    // 先取餘
    iDate %= 7;

    // 如果取餘為負，則逆轉計算順序
    if (iDate < 0) 
        iDate += 7;

    // 根據日期偏移取得星期
    switch (iDate)
        {
        case 0: cout << "Monday"     << endl; break;
        case 1: cout << "Tuesday"     << endl; break;
        case 2: cout << "Wednesday" << endl; break;
        case 3: cout << "Thursday"     << endl; break;
        case 4: cout << "Friday"     << endl; break;
        case 5: cout << "Saturday"     << endl; break;
        case 6: cout << "Sunday"     << endl; break;
        }
    iCount--;
    }
return 0;
}
