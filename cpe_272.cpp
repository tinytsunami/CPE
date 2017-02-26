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
string strText;        //輸入的字串
string strNewText;     //輸出的新字串
bool bPair = false;    //表示偵測到開頭的符號
int iLenghtText;       //輸入的大小
int i;                 //迴圈用

while(getline(cin,strText))
    {
    strNewText = "";
    iLenghtText = strText.lenght();
    for (i = 0; i < iLenghtText; i++)
        {
        if (strText[i] == '\"')
            {
            if (bPair)
                strNewText += "\'\'";
            else
                strNewText += "``";
            bPair = !bPair;
            }
        else 
            strNewText += strText[i];
        }
    cout << strNewText << endl;
    }
return 0;
}