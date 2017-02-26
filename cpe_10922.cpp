//============================================================
// 標頭檔
//============================================================
#include <iostream>
#include <string>
//============================================================
//命名空間
//============================================================
using namespace std;
//============================================================
// 主程式
//============================================================
int main()
{
string strNumber;        //輸入的數字
int iNumberCount;        //數字和
int iDegree;             //階數
unsigned int uiIndex;    //迴圈用
int iLenght;             //輸入的長度

while (cin >> strNumber)
    {
    //initialize
    iDegree = 1;
    iNumberCount = 0;
    iLenght = strNumber.length();

    //first to calc
    for (uiIndex = 0; uiIndex < iLenght; uiIndex++)
        {
        char &c = strNumber[uiIndex];
        if (c >= 48 && c <= 57)
            iNumberCount += (c - 48);
        }

    //exit
    if(iNumberCount == 0)
        break;

    cout << strNumber;

    //Is multiple of 9?
    if (iNumberCount % 9 == 0)
        {
        while (iNumberCount > 9)
            {
            strNumber = totring (iNumberCount);
            iNumberCount = 0;
            for (uiIndex = 0; uiIndex < iLenght; uiIndex++)
                {
                char &c = strNumber[uiIndex];
                if (c >= 48 && c <= 57)
                    iNumberCount += (c - 48);
                }
            iDegree++;
            }
        cout << " is a multiple of 9 and has 9-degree "<< iDegree << "."<< endl;
        }
    else
        cout << " is not a multiple of 9."<< endl;
    }
return 0;
}

