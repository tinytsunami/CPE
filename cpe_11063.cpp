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
int *ipSequence;               //input sequence
int iSequenceCount;            //input sequence lenght
int *ipCombination;            //combination sequence
int iAllCombinationCount;      //combination sequence lenght
int iCase = 1;                 //save case numbers
int iIndex;                    //loop used
int iRaw, iCol;                //loop used
bool bB2;                      //flag(is B2-Sequence?)

while (cin >> iSequenceCount)
    {
    bB2 = true;
    //get some memory
    ipSequence = new int[iSequenceCount];
    //init. combination count
    iAllCombinationCount = iSequenceCount;

    for (iIndex = 0; iIndex < iSequenceCount; iIndex++)
        {
        //input sequence
        cin >> ipSequence[iIndex];
        //some exception...
        //definition doesn't match ( b1 < b2 < b3...)
        if (iIndex > 0)
            if (ipSequence[iIndex] < ipSequence[iIndex - 1])
                bB2 = false;
        //get count of combination
        iAllCombinationCount += iIndex;
        }

    //setting combination
    ipCombination = new int[iAllCombinationCount];

    //process
    iIndex = 0;
    for (iCol = 0; iCol < iSequenceCount; iCol++)
        for (iRaw = iCol; iRaw < iSequenceCount; iRaw++)
            {
            ipCombination[iIndex] = ipSequence[iCol] + ipSequence[iRaw];
            iIndex++;
            }

    //check repeat(combination)
    for (iCol = 0; iCol < iAllCombinationCount; iCol++)
        for (iRaw = iCol + 1; iRaw < iAllCombinationCount; iRaw++)
            if(ipCombination[iCol] == ipCombination[iRaw])
                bB2 = false;

    //output answer
    if(bB2 == true)
        cout << "Case #" << iCase <<": It is a B2-Sequence." << endl;
    else
        cout << "Case #"<< iCase <<": It is not a B2-Sequence." << endl;

    //clear memory
    delete ipSequence;
    delete ipCombination;

    iCase++;
    cout << endl;
    }
return 0;
}