#include <stdio.h>
#include <cmath>

int add(int iNumberA, int iNumberB)
{
int arriNumber[2] = { (iNumberA + iNumberB) / 10, (iNumberA + iNumberB) % 10 };

return *arriNumber;
}

int getDigit(int iNumber)
{
int iDigit = 0;

while ((iNumber / pow(10, iDigit)) >= 1)
    iDigit++;
return iDigit;
}

void createEachNumber(int *iEachNumber, int iNumber)
{
int i = 0;//Loop Used

for (i = getDigit(iNumber); i > 0; i--)
    {
    iEachNumber[10 - i] = iNumber % 10;
    iNumber /= 10;
    }
for (i = 0; i < 10; i++)
    if (iEachNumber[i] < 0 || iEachNumber[i] >= 10)
        iEachNumber[i] = -1;
}

void reverseArray(int *arriArray)
{
int iPosition = 0;
int i = 0;//Loop Used

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

int main(void)
{
int iNumberA = 0;
int iNumberB = 0;
int iEachNumberA[10];
int iEachNumberB[10];
int iCarryCount = 0;
int arriCarryTemp[2] = { 0, 0 };
int i = 0;//Loop Used

while (scanf_s("%d %d", &iNumberA, &iNumberB))
    {

    if (iNumberA == 0 && iNumberB == 0)
        break;

    createEachNumber(iEachNumberA, iNumberA);
    createEachNumber(iEachNumberB, iNumberB);

    reverseArray(iEachNumberA);
    reverseArray(iEachNumberB);

    for (i = 0; i < 10; i++)
        {
        *arriCarryTemp = add(iEachNumberA[i], iEachNumberB[i] + arriCarryTemp[0]);
        iCarryCount += arriCarryTemp[0];
        }

    if (iCarryCount > 0)
        {
        if (iCarryCount > 1)
            printf("%d carry operations.\n", iCarryCount);
        else
            printf("%d carry operation.\n", iCarryCount);
        }
    else
        printf("No carry operation.\n");

    iCarryCount = 0;
    for (i = 0; i < 10; i++)
        iEachNumberA[i] = -1;
    for (i = 0; i < 10; i++)
        iEachNumberB[i] = -1;        
    }
return 0;
}