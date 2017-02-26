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
// 主程式
//============================================================
int main()
{
int *ipSequeue;          //數列
int *ipSeqBothDiff;      //紀錄數列差的數列
int iSequeueSize;        //數列大小
int iSeqBothDiffSize;    //紀錄數列差的數列的大小
int i,j;                 //迴圈用
bool bJolly;             //紀錄答案用

while (cin >> iSequeueSize)
    {
    //get some memory
    iSeqBothDiffSize = iSequeueSize / 2 + iSequeueSize % 2;
    ipSequeue = new int[iSequeueSize];
    ipSeqBothDiff = new int[iSeqBothDiffSize];

    //initialize
    for (i = 0; i < iSequeueSize; i++)
        cin >> ipSequeue[i];
    for (i = 0; i < iSeqBothDiffSize; i++)
        ipSeqBothDiff[i] = i + 1;

    //process
    for (i = iSequeueSize - 1; i > 0; i--)
        {
        int iDiff = abs(ipSequeue[i] - ipSequeue[i - 1]);
        for (j = 0; j < iSeqBothDiffSize; j++)
            if (ipSeqBothDiff[j] == iDiff)
                ipSeqBothDiff[j] = -1; //use (-1) make tag
        }

    //exception
    if (iSequeueSize == 1)
        ipSeqBothDiff[0] = -1;

    //check jolly
    bJolly = true;
    for (i = 0; i < iSeqBothDiffSize; i++)
        if (ipSeqBothDiff[i] != -1)
            bJolly = false;        
    //output
    if (bJolly == true)
        cout << "Jolly" << endl;
    else
        cout << "Not jolly" << endl;

    //clear memory
    delete ipSequeue;
    delete ipSeqBothDiff;
    }
return 0;
}