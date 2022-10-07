#include <iostream>
#include <fstream>
#include <map>
using namespace std;

struct Instruction {
    map<int, string> mp;
};

void DEC(string);
void INC(string);
void PRINT(string);
Instruction split(const string& s);
void ARITHMETIC(string, string, char);
void FEACH(map<int, Instruction>, int);
void LEBLE(map<int, Instruction>, int);
bool HELPERS(map<int, Instruction>, int);
int COMPARE(map<int, Instruction>, int&);
void COMPARE_HELP(map<int, Instruction>, int&);

map<string, int> registers_count = {
    {"R1", 1}, {"R2", 2}, {"R3", 3}, {"R4", 4},{"R5", 5},
    {"R6", 6}, {"R7", 7}, {"R8", 8}, {"R9", 9}, {"R10", 10}
};

map<string, char> Opcode = {
    {"mov", '='}, {"add", '+'}, {"and", '&'},
    {"or", '|'}, {"sub", '-'}, {"div", '/'}, {"mul", '*'}
};

map<string, void(*)(string)> help = {
    {"print", &PRINT}, {"inc", &INC},
    {"dec", &DEC}
};
map<string, string> jmp_help = {
    {"jmp", ""}, {"je", "=="}, {"jne", "!="}, {"jg", ">"},
    {"jge", ">="}, {"jl", "<"}, {"jle", "<="}, {"cmp", ""}
};

map<int, Instruction> code;

map<string, int> Register;

map<string, int> Lable;

int main() {
    int IP = -1;
    string str;
    ifstream file;
    file.open("file.text");
    while (!file.eof()) {
        getline(file, str);
        if (str != "") {
        code[++IP] = split(str);
        }
    }
    for (int ip = 0; ip < IP; ++ip) {
        LEBLE(code, ip);
    }
    for (int ip = 0; ip <= IP; ++ip) {
        ip = COMPARE(code, ip);
        if(HELPERS(code, ip)) {
            FEACH(code, ip);
        }
    }
    file.close();
}

int COMPARE(map<int, Instruction> feach, int& IP)
{
    bool b = false;
    auto it  = feach[IP].mp;
    if (jmp_help.find(it[0]) != jmp_help.end()) {
        if (it[0] == "cmp") {
            b = true;
        } else if (it[0] == "jmp") {
            IP = Lable[it[1]];
        }
    }
    if (b) {
        COMPARE_HELP(feach, IP);
        return IP;
    }
    return IP;
}

void COMPARE_HELP(map<int, Instruction> feach, int& IP)
{
    bool flag = false;
    auto it = feach[IP].mp;
    int r1 = Register[it[1]];
    int r2 = Register[it[2]];
    string str = "";
    auto i = feach[++IP].mp;
    string s = jmp_help[i[0]];

    if (s == "==" && r1 == r2)
        flag = true;
    else if (s == "!=" && r1 != r2)
        flag = true;
    else if (s == ">" && r1 > r2)
        flag = true;
    else if (s == ">=" && r1 >= r2)
        flag = true;
    else if (s == "<" && r1 < r2)
        flag = true;
    else if (s == "<=" && r1 <= r2)
        flag = true;

    if (jmp_help.find(i[0]) != jmp_help.end() && flag) {
        IP = Lable[i[1]];
    } else {
        ++IP;
    }
}

bool HELPERS(map<int, Instruction> feach, int IP)
{
    void (*p_ptr)(string);
    string str = "";
    bool flag = true;
    for (auto it : feach[IP].mp)
    {
        if (help.find(it.second) != help.end()) {
            p_ptr = help[it.second];
            flag = false;
        } else {
            if (registers_count.find(it.second) != registers_count.end()) {
                str = it.second;
                p_ptr(str);
                return false;
            }
        }
        if (flag) {
            return true;
        }
    }
    return true;
}

Instruction split(const string& s)
{
    int index = 0;
    Instruction ret;
    string str = "";
    string s1 = " ,";
    int i = 0, j = 0;
    bool flag = false;
    while (i < s.size()) {
        if (s1.find(s[i]) != -1) {
            flag = true;
            ++i;
        }
        if (flag) {
            ret.mp[index] = str;
            str = "";
            flag = false;
            ++index;
        }
        if (s[i] != ' ') {
            str += s[i];
        }
        ++i;
    }
    ret.mp[index] = str;
    return ret;
}

void FEACH(map<int, Instruction> feach, int IP)
{
    char ch;
    string str = "";
    string str2 = "";
    bool flag = true;
    bool flag_loop = true;
       for (auto it : feach[IP].mp) {
            if (Opcode.find(it.second) != Opcode.end()) {
                ch = Opcode[it.second];
                flag_loop = false;
            }
            if (flag_loop) {
                return;
            }
            if ((registers_count.find(it.second) != registers_count.end()) && flag) {
                str = it.second;
                flag = false;
            } else {
                str2 = it.second;
            }
        }
    ARITHMETIC(str, str2, ch);
}


void ARITHMETIC(string str, string val, char ch)
{
    int value = 0;
    if (val[0] >= '0' && val[0] <= '9') {
        value = stoi(val);
    } else {
        value = Register[val];
    }
    if (ch == '=') {
        Register[str] = value;
    }
    if (Register.find(str) != Register.end()) {
        if (ch == '+') {
            Register[str] += value;
        } else if (ch == '-') {
            Register[str] -= value;
        } else if (ch == '/') {
           Register[str] /= value;
        } else if (ch == '*') {
           Register[str] *= value;
        } else if (ch == '&') {
           Register[str] &= value;
        } else if (ch == '|') {
            Register[str] |= value;
        }
    } else {
        cout << "Error not register" << endl;
        exit(0);
    }
}

void PRINT(string str)
{
    if (Register.find(str) != Register.end()) {
        cout << Register[str] << endl;
    } else {
        cout << "Error not register print" << endl;
        exit(0);
    }
}

void LEBLE(map<int, Instruction> feach, int IP)
{
    string l = ":";
    string cmp = "cmp";
    bool flag = false;
    for (auto it : feach[IP].mp) {
        if (jmp_help.find(it.second) != jmp_help.end()) {
            return;
        }
        if (Opcode.find(it.second) != Opcode.end()) {
            return;
        } else if (it.second.find(l) != -1) {
            Lable[it.second] = IP;
            return;
        }
    }
}

void INC(string str)
{
    ++Register[str];
}

void DEC(string str)
{
    --Register[str];
}



/*#include <iostream>
#include <fstream>
#include <vector>
#include <map>

void Arifmetic(std::string instruction, std::string, std::string, int, bool, bool, char);
void Lexical_analysis(std::string, std::string&, int&, bool&);
int  RIP_REGISTER(std::string, std::string, int, int);
void ALU(std::string, int, std::string, std::string);
void Search_loop(std::string, int, std::ifstream&);
void Instruction(std::ifstream& file, std::string str);
void Cmp(std::string, int size, std::string);
bool Cmp_ALU(std::string, int, std::string);
void file_loop(std::ifstream&, std::string);
void compile(std::ifstream&, std::string);
void Number(std::string, int&);
bool flag_loop_jump = true;
void Fetch(std::string, int);
void print(std::string);
bool flag_loop = false;
void EXIT();

class CPU {
    public:
    std::string cmp = "cmp";
    std::string mov1 = "mov";
    std::string add2 = "add";
    std::string sub3 = "sub";
    std::string div4 = "div";
    std::string mul5 = "mul";
    std::string loop = "loop";
    std::string jump = "jump";
    std::string print = "print";
}C;

class RAM {
    public:
    std::map<std::string, int> mp;
    std::vector<std::string> vec_loop;
}ram;

class REGISTER {
    public:
    std::string eax1 = "eax";
    std::string ebx2 = "ebx";
    std::string ecx3 = "ecx";
    std::string edx4 = "edx";
}R;


int main()
{
    std::string str;
    std::ifstream file;
    compile(file, str);
    file.open("file.text");
    while (!file.eof()) {
        std::getline(file, str);
        if (flag_loop_jump) {
            Instruction(file, str);
        } else {
            flag_loop_jump = true;
        }
    }
    file.close();
}

void print(std::string str)
{
    if (ram.mp[str]) {
        std::cout << ram.mp[str] << std::endl;
    } else {
         EXIT();
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
            Instruction(file, str);
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
    for (int i = 0; i < ram.vec_loop.size(); ++i) {
        if (ram.vec_loop[i] == str_vec) {
            file_loop(file, str_vec);
            flagg = false;
            break;
        }
    }
    if (flagg) {
        EXIT();
    }
}

void Fetch(std::string str, int size, std::string flag)
{
    int i = size;
    while (str[i] == ' ') { ++i;}
    if (RIP_REGISTER(R.eax1, str, 0, i)) {
        ALU(str, (i + R.eax1.length()), flag, R.eax1);
    } else if (RIP_REGISTER(R.ebx2, str, 0, i)) {
        ALU(str, (i + R.ebx2.length()), flag, R.ebx2);
    } else if (RIP_REGISTER(R.ecx3, str, 0, i)) {
        ALU(str, (i + R.ecx3.length()), flag, R.ecx3);
    } else if (RIP_REGISTER(R.edx4, str, 0, i)) {
        ALU(str, (i + R.edx4.length()), flag, R.edx4);
    } else {
         EXIT();
    }
}

void Cmp(std::string str, int size, std::string flag)
{
    int i = size;
    while (str[i] == ' ') { ++i;}
    if (RIP_REGISTER(R.eax1, str, 0, i)) {
       flag_loop = Cmp_ALU(str, (i + R.eax1.length()), R.eax1);
    } else if (RIP_REGISTER(R.ebx2, str, 0, i)) {
        flag_loop = Cmp_ALU(str, (i + R.ebx2.length()), R.ebx2);
    } else if (RIP_REGISTER(R.ecx3, str, 0, i)) {
        flag_loop = Cmp_ALU(str, (i + R.ecx3.length()), R.ecx3);
    } else if (RIP_REGISTER(R.edx4, str, 0, i)) {
        flag_loop = Cmp_ALU(str, (i + R.edx4.length()), R.edx4);
    } else {
         EXIT();
    }
    if (!flag_loop) {
        flag_loop_jump = false;
    } else {
        flag_loop_jump = true;
    }
}

int RIP_REGISTER(std::string str, std::string str1, int size, int size1)
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

void Instruction(std::ifstream& file, std::string str)
{
    if (RIP_REGISTER(C.cmp, str, 0, 0)) {
        Cmp(str, C.cmp.length(), C.cmp);
    } else if (RIP_REGISTER(C.mov1, str, 0, 0)) {
        Fetch(str, C.mov1.length(), C.mov1);
    } else if (RIP_REGISTER(C.add2, str, 0, 0)) {
        Fetch(str, C.add2.length(), C.add2);
    } else if (RIP_REGISTER(C.sub3, str, 0, 0)) {
        Fetch(str, C.sub3.length(), C.sub3);
    } else if (RIP_REGISTER(C.div4, str, 0, 0)) {
        Fetch(str, C.div4.length(), C.div4);
    } else if (RIP_REGISTER(C.mul5, str, 0, 0)) {
        Fetch(str, C.mul5.length(), C.mul5);
    } else if (RIP_REGISTER(C.print, str, 0, 0)) {
        Fetch(str, C.print.length(), C.print);
    } else if (RIP_REGISTER(C.loop, str, 0, 0)) {
    } else if (RIP_REGISTER(C.jump, str, 0, 0)) {
        Search_loop(str, C.jump.length(), file);
    } else {
        if (str != "")
         EXIT();
    }
}

void Number(std::string str, int& i, int& number, bool& flag) {
    while(str[i] >= '0' && str[i] <= '9') {
        number = number * 10;
        number += (str[i] - '0');
        ++i;
    }
    flag = true;
}

void Lexical_analysis(std::string str, std::string& register1, int& i, bool& flag1)
{
    while (str[i] >= 'a' && str[i] <= 'z') {
        register1 += str[i];
        ++i;
        flag1 = true;
    }
}

bool Cmp_ALU(std::string str, int size, std::string register1)
{
    int i = size;
    bool flag = false;
    bool flag1 = false;
    int number = 0;
    std::string str_register;

    while (str[i] == ' ') { ++i;}
    if (str[i] != ',' && str[i] != ';') {
        EXIT();
    }
    if (str[i] != ';') {
        ++i;
    }
    if (str[i] >= '0' && str[i] <= '9') {
        Number(str, i, number, flag);
    }
    if (str[i] >= 'a' && str[i] <= 'z') {
        Lexical_analysis(str, str_register, i, flag1);
    }
    if (flag && flag1) {
        EXIT();
    }
    while (str[i] == ' ') {++i;}
    if (str[i] != ';') {
        EXIT();
    }
    if (flag) {
        if (ram.mp[register1] == number) {
            return true;
        }
        return false;
    }
    if (flag1) {
        if (ram.mp[register1] == ram.mp[str_register]) {
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
    int number = 0;
    while (str[i] == ' ') { ++i;}
    if (str[i] != ',' && str[i] != ';') {
        EXIT();
    }
    if (str[i] != ';') {
        ++i;
    }
    while(str[i] >= '0' && str[i] <= '9'){
        Number(str, i, number, flag);
    }
    std::string str_register;
    if (str[i] >= 'a' && str[i] <= 'z') {
        Lexical_analysis(str, str_register, i, flag1);
    }
    if (flag && flag1) {
        EXIT();
    }
    while (str[i] == ' ') {++i;}
    if (str[i] != ';') {
        EXIT();
    }

    if (instruction == C.print) {
        print(register1);
        return;
    }

    if (instruction == C.mov1) {
        if (flag) {
            ram.mp[register1] = number;
        }
        if (flag1) {
            if (ram.mp[register1]) {
                if (ram.mp[str_register]) {
                    ram.mp[register1] = ram.mp[str_register];
                } else {
                    ram.mp[register1] = 0;
                }
            }
        }
        return;
    }
    if (instruction == C.add2) {
        Arifmetic(instruction, register1, str_register, number, flag,flag1, '+');
        return;
    }
    if (instruction == C.sub3) {
        Arifmetic(instruction, register1, str_register, number, flag,flag1, '-');
        return;
    }
    if (instruction == C.div4) {
        Arifmetic(instruction, register1, str_register, number, flag,flag1, '/');
        return;
    }
    if (instruction == C.mul5) {
        Arifmetic(instruction, register1, str_register, number, flag,flag1, '*');
    }
}
void Arifmetic(std::string instruction, std::string register1, std::string str_register, int number, bool flag, bool flag1, char x)
{
    if (flag) {
        if (ram.mp[register1]) {
            if (x == '+')
                ram.mp[register1] += number;
            if (x == '-')
                ram.mp[register1] -= number;
            if (x == '/')
                ram.mp[register1] /= number;
            if (x == '*')
                ram.mp[register1] *= number;
        } else {
            EXIT();
        }
    }
    if (flag1) {
        if (ram.mp[register1]) {
            if (ram.mp[str_register]) {
                if (x == '+')
                    ram.mp[register1] += ram.mp[str_register];
                if (x == '-')
                    ram.mp[register1] -= ram.mp[str_register];
                if (x == '/')
                    ram.mp[register1] /= ram.mp[str_register];
                if (x == '*')
                    ram.mp[register1] *= ram.mp[str_register];
            } else {
                EXIT();
            }
        } else {
            EXIT();
        }
    }
}


void compile(std::ifstream& file, std::string str)
{
    int i = 0;
    int count;
    file.open("file.text");
    while (!file.eof()) {
        std::getline(file,str);
        while (C.loop[i] == str[i]) {
            ++i;
            ++count;
        }
        if (count == C.loop.length()) {
            ram.vec_loop.push_back(str);
        }
        i = 0;
        count = 0;
    }
    file.close();
}

void EXIT()
{
    std::cout << "Error code" << std::endl;
    exit(0);
}
*/
