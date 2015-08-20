#include <stdio.h>
//#include <iostream>

int wordCount(char word, char page[])
{
    int iCount = 0;
    int i = 0;//Loop Used
    for (i = 0; i < 99; i++)
        if (page[i] == word || page[i] == (char)((int)word+32))
            iCount += 1;
    return iCount;
}

int main(void)
{
    int iLineCount = 0;
    int iWordCount[26];
    int strSaveString[26][2] = {};
    int iMaxNumber = 0;
    char strPage[30][99] = {};
    int i = 0; //Loop Used
    int j = 0; //Loop Used

    for (i = 0; i < 26; i++)
        iWordCount[i] = 0;
    scanf_s("%d", &iLineCount);
    for (i = 0; i <= iLineCount; i++)
        gets_s(strPage[i]);
    for (i = 0; i < 26; i++)
    {
        for (j = 0; j <= iLineCount; j++)
            iWordCount[i] += wordCount((char)(65 + i), strPage[j]);
        if (iWordCount[i] > 0)
        {
            strSaveString[i][0] = (65 + i);
            strSaveString[i][1] = iWordCount[i];
            if (iWordCount[i] > iMaxNumber)
                iMaxNumber = iWordCount[i];
        }
    }
    for (i = iMaxNumber; i > 0; i--)
        for (j = 0; j < 26; j++)
            if (strSaveString[j][1] == i)
                printf("%c %d\n", (char)strSaveString[j][0], (char)strSaveString[j][1]);
    //system("PAUSE");
    return 0;
}