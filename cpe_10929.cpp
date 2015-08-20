#include <stdio.h>

int main(void)
    {
    char strNumber[30];
    int arriNumber[30];
    int iNumberSunA = 0;
    int iNumberSunB = 0;
    int iNumberDifference = 0;
    int i = 0;//Loop used
    while (scanf_s("%s", strNumber, 30))
        {
        printf("%s.\n", strNumber);
        if (strNumber[0] == '0')
            break;
        iNumberSunA = 0;
        iNumberSunB = 0;
        for (i = 0; i < sizeof(strNumber); i++)
            {
            arriNumber[i] = (int)strNumber[i];
            if (arriNumber[i] > 47 && arriNumber[i] < 58)
                {
                arriNumber[i] -= 48;
                if (arriNumber[i] > 0)
                    {
                    if (i % 2)
                        iNumberSunA += arriNumber[i];
                    else
                        iNumberSunB += arriNumber[i];
                    }
                }
            }
        iNumberDifference = (iNumberSunA - iNumberSunB) * (iNumberSunA >= iNumberSunB ? 1 : -1);
        if (iNumberDifference == 0 || iNumberDifference == 11)
            printf("%s is a multiple of 11.\n", strNumber);
        else
            printf("%s is not a multiple of 11.\n", strNumber);
        for (i = 0; i < sizeof(strNumber); i++)
            strNumber[i] = '0';
        }
    return 0;
    }

