#include <iostream>
#include <fstream>
#include <string>
#include <map>

std::map<std::string, int> mp;
std::map<std::string, std::string> st;
bool is_in_bool = false;
bool is_in_while = false;
int cmp_scope = 0;
int cmp_bracket = 0;
void text(std::string str, std::ifstream& file);
void type(std::string, int);
void varible(std::string, int);
int varible_popoxakan(std::string);
bool true_false(std::string, int);
void string_type(std::string, int);
void uf_condition(std::string, int, std::ifstream& file);
void is_scope(int);
bool cmp(int, std::string, int);
void to_cout_see(std::string, int);
int operation(int, char, int);
void vuy_while(std::string, int, std::ifstream& file);
bool cmp1(int);
int main() {
    char data[1000];
    std::string str = "";
    std::ifstream file;
    file.open("file.txt");
    while (!file.eof()) {
        file.getline(data, 1000);
        text(data, file);
    }
    is_scope(cmp_scope);
    is_scope(cmp_bracket);
}
void text (std::string str, std::ifstream& file) {
    std::string stri = "itip";
    std::string strd = "dtip";
    std::string strb = "btip";
    std::string strs = "stip";
    std::string struf = "uf";
    std::string to_see = "tosee";
    std::string while_vuy = "vuy";
    int j = 0;
    int count = 0;
    for (int i = 0; i < str.length(); ++i) {
        if (is_in_bool) {
            if (str[i] != '}') {
                return;}
        }
        if (str[i] == '}') {
            is_in_bool = false;
            cmp_scope += 1;
            return;
        }
        if (is_in_while) {
            if(str[i] != ')'){
                return;
            }
        }
        if (str[i] == ')') {
            is_in_while = false;
            cmp_bracket += 1;
            return;
        }
        while (str[i] == stri[j]) {
            ++i;
            ++j;
            ++count;
        }
        if (count == stri.length()) {
            type(str, count);
            return;
        }
        while (str[i] == strd[j]) {
            ++i;
            ++j;
            ++count;
        }
        if (count == strd.length()) {
            type(str, count);
            return;
        }
        while (str[i] == strb[j]) {
            ++i;
            ++j;
            ++count;
        }
        if (count == strb.length()) {
            type(str, count);
            return;
        }
        while (str[i] == strs[j]) {
            ++i;
            ++j;
            ++count;
        }
        if (count == strs.length()) {
            string_type(str, count);
            return;
        }
        while (str[i] == struf[j]) {
            ++i;
            ++j;
            ++count;
        }
        if (count == struf.length()) {
            uf_condition(str, count, file);
            return;
        }
        while (str[i] == to_see[j]) {
            ++j;
            ++i;
            ++count;
        }
        if (count == to_see.length()) {
            to_cout_see(str, count);
            return;
        }
        while (str[i] == while_vuy[j]) {
            ++i;
            ++j;
            ++count;
        }
        if (count == while_vuy.length()) {
            vuy_while(str, count, file);
            return;
        } else {
            std::cout << "! Error" << std::endl;
            exit(0);
        }
    }
}
void type (std::string str1, int count1) {
    int i = count1;
    if (str1[i] != ' ') {
        std::cout << "Error ' ' " << std::endl;
        exit(0);
    }
    while (str1[i] == ' ') { ++i;}
    varible(str1, i);
    return;
}
void varible (std::string str, int num) {
    std::string varible_name = "";
    int count = 0;
    int number = 0;
    while (str[num] >= 97 && str[num] <= 122) {
        varible_name += str[num];
        ++num;
        ++count;
    }
    if (count < 2) {
        std::cout << "Error" << std::endl;
        exit(0);
    }
    count = 0;
    if (str[num] >= 65 && str[num] <= 90) {
        std::cout << "Error: " << std::endl;
        exit(0);
    }
    while (str[num] == ' ') { ++num;}
    if (str[num] == ';') {
        int end = varible_popoxakan( varible_name );
        if ( end == 1 )
        {
            std::cout << " ERROR ";
            exit(0);
        }
        if ( end == 0 )
        {
            mp[varible_name] = number;
        }
        varible_name = "";
        number = 0;
        return;
    }
    if (str[num] != '=') {
        std::cout << "Error  = : " << std::endl;
        exit(0);
    }
    ++num;
    count = 0;
    while (str[num] == ' ') { ++num;}
    while (str[num] >= 48 && str[num] <= 57) {
        number = number * 10;
        number += (str[num] - 48);
        ++num;
        ++count;
    }
    if (count == 0) {
        bool bace = true_false(str, num);
        if (bace) {
            number = 1;
            num += 4;
        } else {
            number = 0;
            num += 5;
        }
        count = 1;
        bace = 0;
    }
    int numpluse = 0;
    while (str[num] == ' ') { ++num;}
    int operatore = 0;
    if (str[num] == '+' || str[num] == '-' || str[num] == '/' || str[num] == '*' || str[num] == '%') {
        char opr = str[num];
        operatore += 1;
        if (count == 0) {
            std::cout << "error  operator " << std::endl;
            exit(0);
        }
        count = 0;
        ++num;
        while (str[num] == ' ') { ++num;}
        while (str[num] >= 48 && str[num] <= 57) {
            numpluse = numpluse * 10;
            numpluse += (str[num] - 48);
            ++num;
            ++count;
        }
        if (count == 0) {
            std::cout << "error";
            exit(0);
        }
        int n = operation(number, opr, numpluse);
        number = n;
    }
    if (count == 0) {
        std::cout << "Error value " << std::endl;
        exit(0);
    }
    count = 0;
    while (str[num] == ' ') { ++num;}
    if (str[num] != ';') {
        std::cout << "Error ;" << std::endl;
        exit(0);
    }
    int end = varible_popoxakan ( varible_name );
    if ( end == 1 )
    {
        std::cout << " ERROR ";
        exit(0);
    }
    if ( end == 0 )
    {
        mp[varible_name] = number;
    }
    varible_name = "";
    number = 0;
    return;
}
int varible_popoxakan ( std::string str )
{
    if ( mp.count ( str ) == 1 )
    {
        return 1;
    }
    if ( st.count( str ) == 1 )
    {
        return 1;
    } else
        return 0;
}
bool true_false (std::string str, int num) {
    std::string btrue = "true";
    std::string bfalse = "false";
    int i = num;
    int j = 0;
    int count = 0;
    while (str[i] == btrue[j]) {
        ++i;
        ++j;
        ++count;
    }
    if (count == btrue.length()) {
        return true;
    }
    count = 0;
    while (str[i] == bfalse[j]) {
        ++i;
        ++j;
        ++count;
    }
    if (count == bfalse.length()) {
        return false;
    } else {
        std::cout << "Error (false) " << std::endl;
        exit(0);
    }
}
void string_type (std::string str, int num) {
    std::string sum = "";
    std::string sum1 = "";
    int i = num;
    int count = 0;
    if (str[i] != ' ') {
        std::cout << "Error" << std::endl;
        exit(0);
    }
    while (str[i] == ' ') { ++i;}
    while (str[i] >= 97 && str[i] <= 122) {
        sum += str[i];
        ++i;
        ++count;
    }
    if (count < 2) {
        std::cout << "Error" << std::endl;
        exit(0);
    }
    while (str[i] == ' ') { ++i;}
    if (str[i] != '=') {
        std::cout << "Error '=' string " << std::endl;
        exit(0);
    }
    ++i;
    while (str[i] == ' ') { ++i;}
    if (str[i] != '<') {
        std::cout << "Error string '<' " << std::endl;
        exit(0);
    }
    ++i;
    while (str[i] == ' ') { ++i;}
    while (str[i] != '>') {
        sum1 += str[i];
        ++i;
    }
    ++i;
    while (str[i] == ' ') { ++i;}
    if (str[i] != ';') {
        std::cout << "Error string ;" << std::endl;
        exit(0);
    }
    int end = varible_popoxakan(str);
    if ( end == 1 )
    {
        std::cout << " ERROR ";
        exit(0);
    }
    if ( end == 0 )
    {
        st[sum] = sum1;
    }
    sum = "";
    sum1 = "";
    return;
}
void uf_condition (std::string str, int count, std::ifstream& file) {
    std::string str1 = "";
    std::string str2 = "";
    std::string str3 = "";
    int i = count;
    while (str[i] == ' '){ ++i;}
    if (str[i] != ':') {
        std::cout << "Error uf condition ':'" << std::endl;
        exit(0);
    }
    ++i;
    while (str[i] == ' ') { ++i;}
    while (str[i] >= 97 && str[i] <= 122) {
        str1 += str[i];
        ++i;
    }
    while (str[i] == ' ') { ++i;}
    if (str[i] != '=' && str[i] != '<' && str[i] != '>' ) {
        std::cout << "error" << std::endl;
        exit(0);
    }
    while (str[i] == '='|| str[i] == '<' || str[i] == '>') {
        str2 += str[i];
        ++i;
    }
    while (str[i] == ' ') { ++i;}
    while (str[i] >= 97 && str[i] <= 122) {
        str3 += str[i];
        ++i;
    }
    while (str[i] == ' '){ ++i;}
    if (str[i] != ':') {
        std::cout << "Error uf ::" << std::endl;
        exit(0);
    }
    ++i;
    while (str[i] == ' ') { ++i;}
    if (str[i] != '{') {
        std::cout << "error {  " << std::endl;
        exit(0);
    }
    cmp_scope += 1;
    bool uf = varible_popoxakan(str1);
    bool uf1 = varible_popoxakan(str3);
    int mp_value = mp[str1];
    int mp_number = mp[str3];
    if (uf == 1 && uf1 == 1) {
        bool tru_false = cmp(mp_value, str2, mp_number);
        if (tru_false) {
            char data[1000];
            while (!file.eof()) {
                file.getline(data, 1000);
                if (data == "}") {
                    cmp_scope += 1;
                    return;
                }
                text(data, file);
            }
        }
        uf = false;
        is_in_bool = true;
        return;
    } else {
        std::cout << "Error uf condition " << std::endl;
        exit(0);
    }
    return;
}
bool cmp (int start, std::string cmp, int end) {
    if (cmp == "==") {
        if (start == end) {
            return true;
        } else {
            return false;
        }
    }
    if (cmp == "<") {
        if (start < end) {
            return true;
        } else {
            return false;
        }
    }
    if (cmp == ">") {
        if (start > end) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}
void is_scope (int scope) {
    int cmp_scope = scope % 2;
    if (cmp_scope == 0) {
        return;
    } else {
        std::cout << "Error scope (   )" << std::endl;
        exit(0);
    }
}
void to_cout_see (std::string str, int num) {
    std::string str1 = "";
    int i = num;
    int count = 0;
    int while_count = 0;
    while (str[i] == ' ') { ++i;}
    do
    {
        if (str[i] != '<') {
            std::cout << "Error tosee '<' " << std::endl;
            exit(0);
        }
        while (str[i] == '<') {
            ++i;
            ++count;
        }
        if (count != 2) {
            std::cout << "Error << tosee " << std::endl;
            exit(0);
        }
        count = 0;
        while (str[i] == ' ') { ++i;}
        while (str[i] >= 97 && str[i] <= 122) {
            str1 += str[i];
            ++i;
            ++count;
        }
        if (count < 2) {
            std::cout << "Error varible" << std::endl;
            exit(0);
        }
        count = 0;
        char cp =  ' ';
        while (str[i] == ' ') { ++i;}
        if (str[i] == '-' || str[i] == '+') {
            cp = str[i];
            ++i;
            ++count;
        }
        bool no_symbol = true;
        for (std::map<std::string, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr) {
            if ((*itr).first  == str1) {
                if (cp == '-') {
                    while (mp[str1]) {
                    std::cout << mp[str1] << " ";
                    --mp[str1];
                    }
                } else if (cp == '+' ) {
                    int mp_int = mp[str1];
                        for (int i = mp_int; ;++i) {
                            std::cout << i << " ";
                        }
                } else if(count == 0) {
                    std::cout << mp[str1] << " ";
                }
                no_symbol = false;
            }
        }
        for (std::map<std::string, std::string>::iterator itr = st.begin(); itr != st.end(); ++itr) {
            if ((*itr).first  == str1) {
                std::cout << (*itr).second << " ";
                no_symbol = false;
            }
        }
        if (no_symbol) {
            std::cout << "Error" << std::endl;
            exit(0);
        }
        str1 = "";
        while (str[i] == ' ') { ++i;}
        if (str[i] == ';') {
            return;
        }
    } while( str[i] != ';');
}
int operation (int num, char ch, int sum){
    std::string str1 = "";
    if (ch == '+') {
        int number = num  + sum;
        return number;
    }
    if (ch == '-') {
        int number1 = num - sum;
        return number1;
    }
    if (ch == '/') {
        int number3 = num / sum;
        return number3;
    }
    if (ch == '*') {
        int number4 = num * sum;
        return number4;
    }
    if (ch == '%') {
        int number5 = num % sum;
        return number5;
    }
    return 0;
}
void vuy_while (std::string str, int count , std::ifstream& file) {
    std::string str1 = "";
    std::string str2 = "";
    int str3 = 0;
    int i = count,count1 = 0;
    while (str[i] == ' ') { ++i;}
    if (str[i] != '[') {
        std::cout << "Error vuy condition '['" << std::endl;
        exit(0);
    }
    ++i;
    while (str[i] == ' ') { ++i;}
    while (str[i] >= 97 && str[i] <= 122) {
        str1 += str[i];
        ++i;
    }
    while (str[i] == ' ') { ++i;}
    if (str[i] != ']') {
        std::cout << "Error vuy ]" << std::endl;
        exit(0);
    }
    ++i;
    while (str[i] == ' ') { ++i;}
    if (str[i] != '(') {
        std::cout << "error (  " << std::endl;
        exit(0);
    }
    cmp_bracket += 1;
    bool uf = varible_popoxakan(str1);
    int mp_value = mp[str1];
    if (uf == 1) {
        bool tru_1 = cmp1(mp[str1]);
        if (tru_1) {
            char data[1000];
            while (!file.eof()) {
                file.getline(data, 1000);
                if (data == ")") {
                    cmp_bracket += 1;
                    return;
                }
                text(data, file);
            }
        }
        uf = false;
        is_in_while = true;
        return;
    } else {
        std::cout << "Error vuy condition " << std::endl;
        exit(0);
    }
    return;
}
bool cmp1 (int num){
    if (num != 0) {
        return 1;
    } else {
        return 0;
    }
}
