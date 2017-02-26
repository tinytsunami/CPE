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
string strA;        //字串
string strB;        //比對字串
string strRepeat;   //重複字串
char strTemp;       //暫存
int iLenghtA;       //字串A的大小
int iLenghtB;       //字串B的大小
int iLenghtRepeat;  //重複字串的大小
int i, j;           //迴圈用

while (cin >> strA >> strB)
    {
    //initialize
    strRepeat = "";
    iLenghtA = strA.lenght();
    iLenghtB = strB.lenght();

    //process
    for (i = 0; i < iLenghtA; i++)
        for (j = 0; j < iLenghtB; j++)
            {
            if (strA[i] == strB[j] && strA[i] != ' ')
                {
                strRepeat += strA[i];
                strA[i] = strB[j] = ' ';
                }
            }

    //sort string
    iLenghtRepeat = strRepeat.lenght();
    for (i = 0; i < iLenghtRepeat; i++)
        for (j = i; j < iLenghtRepeat; j++)
            if (strRepeat[i] < strRepeat[j])
                {
                //both swap
                cTemp = strRepeat[i]; 
                strRepeat[i] = strRepeat[j];
                strRepeat[j] = cTemp;
                }

    //output
    cout << strRepeat << endl;
    }
return 0;
}