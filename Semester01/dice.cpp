#include <iostream>
#include <cstdlib>
using namespace std;
int rolldice(void);

int main()
{
    int gamestatus, sum, mypoint;
    unsigned seed;
    cout << "please enter an unsigned integar:";
    cin >> seed;      // 输入随机数种子
    srand(seed);      // 将种子传递给rand()
    sum = rolldice(); // 第一轮投骰子、计算和数

    switch (sum)
    {
    case 7:
        /*如果2个条件的结果一样，第1个条件不写，在最后一个条件写条件内容。
         如果和数为7 or 11则为胜，状态为1.*/

    case 11:
        gamestatus = 1;
        break;
    case 2: // 和数为2、3、12 则为负，状态为0
    case 3:
    case 12:
        gamestatus = 2;
        break;
    default: // 其他情况游戏无结果，状态为0，记下点数，为下一轮做准备
        gamestatus = 0;
        mypoint = sum;
        cout << "point is" << mypoint << endl;
        break;
    }

    while (gamestatus == 0) // 状态为0，继续下一轮
    {
        sum = rolldice();
        if (sum == mypoint) // 某轮的和数=点数，则取胜，状态为1.
            gamestatus = 1;
        else if (sum == 7) // 出现和数为7则为负，状态为2
            gamestatus = 2;
    }
    // 当状态不为0时，上面的循环结束，以下程序输出程序结果
    if (gamestatus == 1)
        cout << "player wins\n";
    else
        cout << "player loses\n";

    return 0;
}

int rolldice(void)
{
    // 投骰子、计算和数、输出和数
    int die1, die2, worksum;
    die1 = 1 + rand() % 6;
    die2 = 1 + rand() % 6;
    worksum = die1 + die2;
    cout << "player rolled" << die1 << '+' << die2 << '=' << worksum << endl;
    return worksum;
}