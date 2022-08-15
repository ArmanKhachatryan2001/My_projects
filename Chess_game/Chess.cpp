#include <iostream>
#include <string>

void play();
void print(std::string** arr, int size);
void go(std::string** arr, int size);

int main()
{
    play();
}

void play()
{
    std::string K = "♔";//1
    std::string Q = "♕";//1
    std::string R = "♖";//2
    std::string N = "♘";//2
    std::string P = "♗";//8
    std::string B = "♙";//2
    std::string k = "♚";//1
    std::string q = "♛";//1
    std::string r = "♜";//2
    std::string n = "♞";//2
    std::string p = "♝";//8
    std::string b = "♟︎";//2
    int size = 8;
    std::string** arr = new std::string*[size];
    for (int i = 0; i < size; ++i) {
        arr[i] = new std::string[size];
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == 0 && j == 0) {
                arr[i][j] = r;
            }
            if (i == 0 && j == 1) {
                arr[i][j] = n;
            }
            if (i == 0 && j == 2) {
                arr[i][j] = b;
            }
            if (i == 0 && j == 3) {
                arr[i][j] = q;
            }
            if (i == 0 && j == 4) {
                arr[i][j] = k;
            }
            if (i == 0 && j == 5) {
                arr[i][j] = b;
            }
            if (i == 0 && j == 6) {
                arr[i][j] = n;
            }
            if (i == 0 && j == 7) {
                arr[i][j] = r;
            }

            if (i == 1 && j == 0) {
                arr[i][j] = p;
            }
            if (i == 1 && j == 1) {
                arr[i][j] = p;
            }
            if (i == 1 && j == 2) {
                arr[i][j] = p;
            }
            if (i == 1 && j == 3) {
                arr[i][j] = p;
            }
            if (i == 1 && j == 4) {
                arr[i][j] = p;
            }
            if (i == 1 && j == 5) {
                arr[i][j] = p;
            }
            if (i == 1 && j == 6) {
                arr[i][j] = p;
            }
            if (i == 1 && j == 7) {
                arr[i][j] = p;
            }


            if (i == 6 && j == 0) {
                arr[i][j] = P;
            }
            if (i == 6 && j == 1) {
                arr[i][j] = P;
            }
            if (i == 6 && j == 2) {
                arr[i][j] = P;
            }
            if (i == 6 && j == 3) {
                arr[i][j] = P;
            }
            if (i == 6 && j == 4) {
                arr[i][j] = P;
            }
            if (i == 6 && j == 5) {
                arr[i][j] = P;
            }
            if (i == 6 && j == 6) {
                arr[i][j] = P;
            }
            if (i == 6 && j == 7) {
                arr[i][j] = P;
            }

            if (i == 7 && j == 0) {
                arr[i][j] = R;
            }
            if (i == 7 && j == 1) {
                arr[i][j] = N;
            }
            if (i == 7 && j == 2) {
                arr[i][j] = B;
            }
            if (i == 7 && j == 3) {
                arr[i][j] = Q;
            }
            if (i == 7 && j == 4) {
                arr[i][j] = K;
            }
            if (i == 7 && j == 5) {
                arr[i][j] = B;
            }
            if (i == 7 && j == 6) {
                arr[i][j] = N;
            }
            if (i == 7 && j == 7) {
                arr[i][j] = R;
            }
        }
    }
    print(arr, size);
    int flag = 0;
    do {
    std::cout << "9 -> EXIT : go -> 0" << std::endl;
    std::cin >> flag;
    if (flag == 9) {
        exit(0);
    }
    go(arr, size);
    print(arr, size);
    } while (flag == 0);
}

void go(std::string** arr, int size)
{
    std::string K = "♔";
    std::string Q = "♕";
    std::string R = "♖";
    std::string N = "♘";
    std::string P = "♗";
    std::string B = "♙";
    std::string k = "♚";
    std::string q = "♛";
    std::string r = "♜";
    std::string n = "♞";
    std::string p1 = "♝";
    std::string b = "♟︎";
    std::cout << "Enter :< 0 0 >:" << std::endl;
    int i, j;
    std::cin >> i >> j;
    std::string tmp;
    if (arr[i][j] != "") {
        tmp = arr[i][j];
    } else {
        std::cout << "No" << std::endl;
    }
    std::cout << "Enter <1 4>"<< std::endl;
    int m;
    int p;
    std::cin >> m >> p;
    if (arr[m][p] != K && arr[m][p] != Q && arr[m][p] != R && arr[m][p] != N && arr[m][p] != P && arr[m][p] != B && arr[m][p] != k && arr[m][p] != q && arr[m][p] != r && arr[m][p] != n && arr[m][p] != p1 && arr[m][p] != b)  {
        arr[i][j] = "";
        arr[m][p] = tmp;
    } else {
        std::cout << "NO" << std::endl;
    }
}

void print(std::string** arr, int size)
{
    std::cout << "   " << 0 << "     ";
    for (int i = 1; i < 8; ++i) {
        std::cout << i << "     ";
    }
    std::cout << std::endl;
    for (int i = 0; i < size; ++i) {
            std::cout << i << "  ";
            for (int j = 0; j < size; ++j) {
            if (arr[i][j] == "") {
                std::cout << "      ";
            } else {
            std::cout << arr[i][j] << "     ";
            }
        }
        std::cout << std::endl;
    }
}
