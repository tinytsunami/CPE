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
// 將數字加 1
// input : 輸入字元
// output: 不輸出
//============================================================
void vSetNumber(char *cpMapValue)
{
short int siASCII = (int)(*cpMapValue);
if (siASCII >= 48 && siASCII <= 57)
    (*cpMapValue)++;
}
//============================================================
// 主程式
//============================================================
int main()
{
int iCase = 1;    //測資數
int iWidth;       //地圖的寬
int iHeight;      //地圖的高
char **cMap;      //輸入地圖表
int x, y;         //loop used

while (cin >> iHeight >> iWidth)
    {
    //exit
    if (iWidth == 0 && iHeight == 0)
        break;
    if (iCase > 1)
        cout << endl;

    //create cMap
    cMap = new char*[iHeight];
    for (y = 0; y < iHeight; y++)
        cMap[y] = new char[iWidth];

    //input cMap
    for (y = 0; y < iHeight; y++)
        for (x = 0; x < iWidth; x++)
            {
            cin >> cMap[y][x];
            if (cMap[y][x] == '.')
                cMap[y][x] = '0';
            }

    //process
    for (y = 0; y < iHeight; y++)
        for (x = 0; x < iWidth; x++)
            if (cMap[y][x] == '*')
                {
                //+
                if (y + 1 < iHeight)
                    vSetNumber (&cMap[y + 1][x]);
                if (x + 1 < iWidth)
                    vSetNumber (&cMap[y][x + 1]);
                if (y - 1 >= 0)
                    vSetNumber (&cMap[y - 1][x]);
                if (x - 1 >= 0)
                    vSetNumber (&cMap[y][x - 1]);
                //×
                if (y + 1 < iHeight && x + 1 < iWidth)
                    vSetNumber (&cMap[y + 1][x + 1]);
                if (y - 1 >= 0 && x - 1 >= 0)
                    vSetNumber (&cMap[y - 1][x - 1]);
                if (y - 1 >= 0 && x + 1 < iWidth)
                    vSetNumber (&cMap[y - 1][x + 1]);
                if (y + 1 < iHeight && x - 1 >= 0)
                    vSetNumber (&cMap[y + 1][x - 1]);
                }

    //output
    cout << "Field #" << iCase << ":" << endl;
    for (y = 0; y < iHeight; y++)
        {
        for (x = 0; x < iWidth; x++)
            cout << cMap[y][x];
        cout << endl;
        }

    iCase++;
    }
return 0;
}