#include <iostream>
#include <fstream>
#include <vector>
#include <map>

void ALU(std::string, int, std::string, std::string);
void Search_loop(std::string, int, std::ifstream&);
void RAM(std::ifstream& file, std::string str);
void Cmp(std::string, int size, std::string);
bool Cmp_ALU(std::string, int, std::string);
void file_loop(std::ifstream&, std::string);
int CPU(std::string, std::string, int, int);
void compile(std::ifstream&, std::string);
std::vector<std::string> vec_loop;
std::map<std::string, int> mp;
void CU(std::string, int);
void print(std::string);
bool flag_loop = false;
bool flag_loop_jump = true;
int main()
{
    std::string str;
    std::ifstream file;
    compile(file, str);
    file.open("file.text");
    while (!file.eof()) {
        std::getline(file, str);
        if (flag_loop_jump) {
            RAM(file, str);
        } else {
            flag_loop_jump = true;
        }
    }
    file.close();
}

void print(std::string str)
{
    if (mp[str]) {
        std::cout << mp[str] << std::endl;
    } else {
        std::cout << "print now" << std::endl;
        exit(0);
    }
}

void file_loop(std::ifstream& file, std::string str)
{
    std::string str_1;
    file.close();
    file.open("file.text");
     while (!file.eof()) {
        std::getline(file, str_1);
        if (str == str_1) {
        RAM(file, str);
        return;
        }
    }
}

void Search_loop(std::string str, int size, std::ifstream& file)
{
    int i = size;
    std::string str_vec;
    while (str[i] == ' ') {++i;}
    while (i <= str.length() - 1) {
        str_vec += str[i];
        ++i;
    }
    bool flagg = true;
    for (int i = 0; i < vec_loop.size(); ++i) {
        if (vec_loop[i] == str_vec) {
            file_loop(file, str_vec);
            flagg = false;
            break;
        }
    }
    if (flagg) {
        std::cout << "Error not loop"  << std::endl;
        exit(0);
    }
}

void CU(std::string str, int size, std::string flag)
{
    std::string eax1 = "eax";
    std::string ebx2 = "ebx";
    std::string ecx3 = "ecx";
    std::string edx4 = "edx";
    int i = size;
    while (str[i] == ' ') { ++i;}
    if (CPU(eax1, str, 0, i)) {
        ALU(str, (i+eax1.length()), flag, eax1);
    } else if (CPU(ebx2, str, 0, i)) {
        ALU(str, (i+ebx2.length()), flag, ebx2);
    } else if (CPU(ecx3, str, 0, i)) {
        ALU(str, (i+ecx3.length()), flag, ecx3);
    } else if (CPU(edx4, str, 0, i)) {
        ALU(str, (i+edx4.length()), flag, edx4);
    } else {
        std::cout << "Not register:" << std::endl;
        exit(0);
    }
}

void Cmp(std::string str, int size, std::string flag)
{
    std::string eax1 = "eax";
    std::string ebx2 = "ebx";
    std::string ecx3 = "ecx";
    std::string edx4 = "edx";
    int i = size;
    while (str[i] == ' ') { ++i;}
    if (CPU(eax1, str, 0, i)) {
       flag_loop = Cmp_ALU(str, (i+eax1.length()), eax1);
    } else if (CPU(ebx2, str, 0, i)) {
        flag_loop = Cmp_ALU(str, (i+ebx2.length()), ebx2);
    } else if (CPU(ecx3, str, 0, i)) {
        flag_loop = Cmp_ALU(str, (i+ecx3.length()), ecx3);
    } else if (CPU(edx4, str, 0, i)) {
        flag_loop = Cmp_ALU(str, (i+edx4.length()), edx4);
    } else {
        std::cout << "Not register cmp:" << std::endl;
        exit(0);
    }
    if (!flag_loop) {
        flag_loop_jump = false;
    } else {
        flag_loop_jump = true;
    }
}

int CPU(std::string str, std::string str1, int size, int size1)
{
    int i = size;
    int j = size1;
    int count = 0;
    while (str[i] == str1[j]) {
        ++count;
        ++i;
        ++j;
    }
    if (count == str.length()) {
        return str.length();
    } else {
        return 0;
    }
}

void RAM(std::ifstream& file, std::string str)
{
    std::string cmp = "cmp";
    std::string mov1 = "mov";
    std::string add2 = "add";
    std::string sub3 = "sub";
    std::string div4 = "div";
    std::string mul5 = "mul";
    std::string loop = "loop";
    std::string jump = "jump";
    std::string print = "print";

    if (CPU(cmp, str, 0, 0)) {
        Cmp(str, cmp.length(), cmp);
    } else if (CPU(mov1, str, 0, 0)) {
        CU(str, mov1.length(), mov1);
    } else if (CPU(add2, str, 0, 0)) {
        CU(str, add2.length(), add2);
    } else if (CPU(sub3, str, 0, 0)) {
        CU(str, sub3.length(), sub3);
    } else if (CPU(div4, str, 0, 0)) {
        CU(str, div4.length(), div4);
    } else if (CPU(mul5, str, 0, 0)) {
        CU(str, mul5.length(), mul5);
    } else if (CPU(print, str, 0, 0)) {
        CU(str, print.length(), print);
    } else if (CPU(loop, str, 0, 0)) {
    } else if (CPU(jump, str, 0, 0)) {
        Search_loop(str, jump.length(), file);
    } else {
        if (str != "")
        std::cout << "Error instruction" << str  << "::" <<std::endl;
    }
}

bool Cmp_ALU(std::string str, int size, std::string register1)
{
    int i = size;
    bool flag = false;
    bool flag1 = false;
    while (str[i] == ' ') { ++i;}
    if (str[i] != ',' && str[i] != ';') {
        std::cout << "Error -> ','" << std::endl;
        exit(0);
    }
    if (str[i] != ';') {
        ++i;
    }
    int number = 0;
     while(str[i] >= 48 && str[i] <= 57){
        number = number * 10;
        number += (str[i] - 48);
        ++i;
        flag = true;
    }
     std::string str_register;
     while (str[i] >= 97 && str[i] <= 122) {
        str_register += str[i];
        ++i;
        flag1 = true;
     }
     if (flag && flag1) {
        std::cout << "Error cmp1-> registrer" << std::endl;
        exit(0);
     }
     while (str[i] == ' ') {++i;}
     if (str[i] != ';') {
        std::cout << "Error cmp2 -> ';'" << std::endl;
        exit(0);
     }
     if (flag) {
        if (mp[register1] == number) {
            return true;
        }
        return false;
     }
     if (flag1) {
        if (mp[register1] == mp[str_register]) {
            return true;
        }
        return false;
     }
    return false;
}

void ALU(std::string str, int size, std::string instruction, std::string register1)
{
    int i = size;
    bool flag = false;
    bool flag1 = false;
    while (str[i] == ' ') { ++i;}
    if (str[i] != ',' && str[i] != ';') {
        std::cout << "Error -> ','" << std::endl;
        exit(0);
    }
    if (str[i] != ';') {
        ++i;
    }
    int number = 0;
     while(str[i] >= 48 && str[i] <= 57){
        number = number * 10;
        number += (str[i] - 48);
        ++i;
        flag = true;
    }
     std::string str_register;
     while (str[i] >= 97 && str[i] <= 122) {
        str_register += str[i];
        ++i;
        flag1 = true;
     }
     if (flag && flag1) {
        std::cout << "Error -> registrer" << std::endl;
        exit(0);
     }
     while (str[i] == ' ') {++i;}
     if (str[i] != ';') {
        std::cout << "Error -> ';'" << std::endl;
        exit(0);
     }

     if (instruction == "print") {
        print(register1);
        return;
     }

     if (instruction == "mov") {
        if (flag) {
            if (!mp[register1]) {
                 mp[register1] = number;
            } else {
                mp[register1] = number;
            }
        }
        if (flag1) {
            if (mp[register1]) {
                if (mp[str_register]) {
                    mp[register1] = mp[str_register];
                } else {
                    mp[register1] = 0;
                }
            }
        }
        return;
     }
     if (instruction == "add") {
        if (flag) {
            if (mp[register1]) {
                int tmp = mp[register1];
                tmp += number;
                mp[register1] = tmp;
            } else {
                std::cout << "Error not registrer1" << std::endl;
                exit(0);
            }
        }
        if (flag1) {
            if (mp[register1]) {
                if (mp[str_register]) {
                    mp[register1] += mp[str_register];
                } else {
                    std::cout << "Error not register2" << std::endl;
                    exit(0);
                }
            }
         }
        return;
      }

      if (instruction == "sub") {
        if (flag) {
            if (mp[register1]) {
                int tmp = mp[register1];
                tmp -= number;
                mp[register1] = tmp;
            } else {
                std::cout << "Error not registrer4" << std::endl;
                exit(0);
            }
        }
        if (flag1) {
            if (mp[register1]) {
                if (mp[str_register]) {
                    mp[register1] -= mp[str_register];
                } else {
                    std::cout << "Error not register5" << std::endl;
                    exit(0);
                }
            } else {
            std::cout << "Error not register6" << std::endl;
            exit(0);
            }
          }
          return;
       }

       if (instruction == "div") {
        if (flag) {
            if (mp[register1]) {
                int tmp = mp[register1];
                tmp /= number;
                mp[register1] = tmp;
            } else {
                std::cout << "Error not registrer7" << std::endl;
                exit(0);
            }
        }
        if (flag1) {
            if (mp[register1]) {
                if (mp[str_register]) {
                    mp[register1] /= mp[str_register];
                } else {
                    std::cout << "Error not register8" << std::endl;
                    exit(0);
                }
            } else {
            std::cout << "Error not register9" << std::endl;
            exit(0);
            }
          }
          return;
        }

        if (instruction == "mul") {
        if (flag) {
            if (mp[register1]) {
                int tmp = mp[register1];
                tmp *= number;
                mp[register1] = tmp;
            } else {
                std::cout << "Error not registrer11" << std::endl;
                exit(0);
            }
        }
        if (flag1) {
            if (mp[register1]) {
                if (mp[str_register]) {
                    mp[register1] *= mp[str_register];
                } else {
                    std::cout << "Error not register22" << std::endl;
                    exit(0);
                }
            } else {
            std::cout << "Error not register33" << std::endl;
            exit(0);
            }
          }
          return;
        }
}

void compile(std::ifstream& file, std::string str)
{
    std::string loop_ = "loop";
    int i = 0;
    int count;
    file.open("file.text");
    while (!file.eof()) {
        std::getline(file,str);
        while (loop_[i] == str[i]) {
            ++i;
            ++count;
        }
        if (count == loop_.length()) {
            vec_loop.push_back(str);
        }
        i = 0;
        count = 0;
    }
    file.close();
}
