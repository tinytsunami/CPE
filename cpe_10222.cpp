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
string csKey = "`1234567890-="                    //字表
               "qwertyuiop[]asdfghjkl;\'\\"
               "zxcvbnm,./";
string sInput;                                    //輸入
int index;                                        //迴圈用
int iLenght;                                      //用於迴圈紀錄長度

//input
while (getline(cin,sInput))
    {
    for (char &c : sInput)
        {
        if (c == ' ')
            cout << c;
        else
            {
            //A~Z to a~z
            if (c >= 65 && c <= 90) c += 32;
            //get new word
            iLenght = csKey.length();
            for (index = 0; index < iLenght; index++)
                if (c == csKey[index])
                    {
                    cout << csKey[index - 2];
                    break;
                    }
            }
        }
    cout << endl;
    }

return 0;
}