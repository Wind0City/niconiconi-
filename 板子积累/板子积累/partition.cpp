//分治,以汉诺塔为样例的分治思想
/*
对于 N 个圆盘的汉诺塔问题，移动圆盘的过程是：
将起始柱上的 N-1 个圆盘移动到辅助柱上；
将起始柱上遗留的 1 个圆盘移动到⽬标柱上；
将辅助柱上的所有圆盘移动到⽬标柱上。
*/
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
void HNT(int num, string start, string purpose, string help)
{
    if (num == 1) //触底，即此时的操作圆盘数为1
    {
        cout << start << " to " << purpose << endl;
        return;
    }
    else
    {
        HNT(num - 1, start, help, purpose);         //将num-1个放到辅助柱子上，用目标柱子做辅助
        cout << start << " to " << purpose << endl; //将起始柱上剩下的最后一个最大的圆盘放到目标柱子上
        HNT(num - 1, help, purpose, start);         //将辅助柱子上的所有放到目标柱子上，用起始柱子做辅助
    }
}
int main()
{
    HNT(5, "a", "b", "c");
}