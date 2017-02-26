//============================================================
// 標頭檔
//============================================================
#include <iostream>
#include <string>
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
const double cdPi = 3.14159265359;    //PI常數
const int ciEarthRadius = 6440;       //地球半徑
string strUnit;                       //單位
double dDegree;                       //角度
double dDistance;                     //距離
double dArcDistance;                  //表面長
double dChordDistance;                //弦長

while (cin >> dDistance >> dDegree >> strUnit)
    {
    if (strUnit == "min")
        dDegree /= 60;

    dDistance += ciEarthRadius;
    dArcDistance = dDistance * 2 * cdPi * dDegree / 360;
    dChordDistance = sqrt(2 * pow (dDistance, 2) * (1 - cos(dDegree / 180 * cdPi)));
    
    printf("%.6lf %.6lf\n", dArcDistance, dChordDistance);
    }
return 0;
}