#include <iostream>
class Kesar
{
public:
    void true_algorithm(std::string str);
    void untrue_algorithm(std::string str);
    void set_true(std::string str);
    void set_false(std::string str);
    std::string get_true();
    std::string get_false();
private:
    std::string str1;
    std::string str2;
};
int main()
{
    Kesar obj;
    int flag = 0;
    do
    {
    std::cout << "[0] Exit: \n[1] Enter a simple message: \n[2] Enter an encrypted message: \n[3] read the encrypted look: \n[4] read the look simple։ " << std::endl;
    std::string str = "";
    std::cin >> flag;
    std::cin.ignore(1);
    switch(flag)
    {
        case 1:
            std::cout << " Enter a simple message " << std::endl;
            std::getline(std::cin, str);
            obj.true_algorithm(str);
            break;
        case 2:
            std::cout << " Enter an encrypted message:" << std::endl;
            std::getline(std::cin, str);
            obj.untrue_algorithm(str);
            break;
        case 3:
            std::cout << obj.get_true() << std::endl;
            break;
        case 4:
            std::cout << obj.get_false() << std::endl;
            break;
        case 0:
            break;
    }
    }while(flag != 0);
}
std::string Kesar::get_false()
{
    return str2;
}
std::string Kesar::get_true()
{
    return str1;
}
void Kesar::set_false(std::string str)
{
    str2 = str;
}
void Kesar::set_true(std::string str)
{
    str1 = str;
}
void Kesar::true_algorithm(std::string str) {
    std::string str1;
    for(int i = 0; i < str.length(); ++i) {
        if((str[i] >= 97 && str[i] <= 122) || (str[i] >= 65 && str[i] <= 90)) {
            int a = str[i];
            if (a == 97 || a == 65) {
                a += 23;
                str1 += a;
                continue;
            }
            if (a == 98 || a == 66) {
                a+= 23;
                str1 += a;
                continue;
            }
            if (a == 99 || a == 67) {
                a += 23;
                str1 += a;
                continue;
            }
            a -= 3;
            str1 += a;
        }
        if ((str[i] < 97 || str[i] > 122) && (str[i] < 65 || str[i] > 90)) {
            str1 += str[i];
        }
    }
    set_true(str1);
    set_false(str);
}
void Kesar::untrue_algorithm(std::string str) {
    std::string str2;
    for(int i = 0; i < str.length(); ++i) {
        if((str[i] >= 97 && str[i] <= 122) || (str[i] >= 65 && str[i] <= 90)) {
            int a = str[i];
            if (a == 122 || a == 90) {
                a -= 23;
                str2 += a;
                continue;
            }
            if (a == 121 || a == 89) {
                a -= 23;
                str2 += a;
                continue;
            }
            if (a == 120 || a == 88) {
                a -= 23;
                str2 += a;
                continue;
            }
            a += 3;
            str2 += a;
        }
        if ((str[i] < 97 || str[i] > 122) && (str[i] < 65 || str[i] > 90)) {
            str2 += str[i];
        }
    }
    set_false(str2);
    set_true(str);
}

