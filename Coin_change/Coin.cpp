#include <iostream>
void count(int& mani, int coin, int& count1) {
    int num = 0;
    if (mani >= coin) {
        num = mani / coin;
        count1 += num;
        mani -= num * coin;
        num = 0;
    }
}

enum{five_hundred = 500, two_hundred = 200, one_hundred = 100, fifth = 50, twenty = 20, ten = 10};
int coin(int mani)
{
    int count1 = 0;
    count(mani, five_hundred, count1);
    count(mani, two_hundred, count1);
    count(mani, one_hundred, count1);
    count(mani, fifth, count1);
    count(mani, twenty, count1);
    count(mani, ten, count1);
    return count1;
}
int main() {
    std::cout << coin(2300);
}
