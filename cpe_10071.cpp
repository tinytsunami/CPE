//============================================================
// 標頭檔
//============================================================
#include <stdio.h>
#include <stdlib.h>
//============================================================
// 主程式
//============================================================
int main()
{
int iVelocity;  // 速度
int iTime;      // 時間
int iLong;      // 位移

while(scanf_s("%d %d",&iVelocity,&iTime) != EOF)
    {
    iTime *= 2; // double of that time.
    iLong = iVelocity * iTime;
    printf("%d\n", iLong);
    }

return 0;
}