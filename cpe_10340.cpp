#include <stdio.h>

int main()
{
char strCodeS[99];
char strCodeT[99];
int iCodeTPosition = 0;
bool bFlag = false;
int iIndex = 0;
int i = 0;//Loop Used

while (gets_s(strCodeS))
    {
    bFlag = false;
    iCodeTPosition = 0;
    iIndex = 0;
    for (i = 0; i < sizeof(strCodeS); i++)
        {
        strCodeS[i] = (int)strCodeS[i];
        if (strCodeS[i] == 32)
            bFlag = true;
        else
            strCodeT[i] = 0;
        if (bFlag)
            {
            if (strCodeS[i] < 64 || strCodeS[i] > 123)
                strCodeS[i] = 0;
            strCodeT[iCodeTPosition - 1] = strCodeS[i];
            strCodeS[i] = 0;
            iCodeTPosition += 1;
            }
        }
    bFlag = false;
    for (i = 0; i < sizeof(strCodeT); i++)
        {
        if (strCodeS[iIndex] == strCodeT[i])
            iIndex += 1;
        if (strCodeS[iIndex] == 0)
            bFlag = true;
        }
    if (bFlag)
        printf("Yes\n");
    else
        printf("No\n");
    }
return 0;
}