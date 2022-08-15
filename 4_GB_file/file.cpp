#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

void merge_two(std::ifstream& first, std::ifstream& second, std::ofstream& end, long size)
{
    std::string str;
    std::string str1;
    int i = 0;
    for (i; i < size;++i) {
        first >> str;
        second >> str1;
        if (first.eof() || second.eof()) {
            break;
        }
        if (str <= str1) {
            end << str << '\n';
            second.seekg(-1, std::ios::cur);
        } else {
            end << str1 << '\n';
            first.seekg(-1, std::ios::cur);
        }
    }
    while (!first.eof()) {
        first >> str;
            end << str << '\n';
    }
    while (!second.eof()) {
        second >> str1;
            end << str1 << '\n';
        }
}

void Merge(std::vector<int>&arr, int first, int mid, int last)
{
    std::vector<int> tmp(arr.size());
    int f_1 = first;
    int l_1 = mid;
    int f_2 = mid + 1;
    int l_2 = last;
    int i = first;
    while (f_1 <= l_1 && f_2 <= l_2) {
        if (arr[f_1] < arr[f_2]) {
            tmp[i] = arr[f_1];
            ++i;
            ++f_1;
        } else {
            tmp[i] = arr[f_2];
            ++i;
            ++f_2;
        }
    }

    while (f_1 <= l_1) {
        tmp[i] = arr[f_1];
        ++i;
        ++f_1;
    }

    while (f_2 <= l_2) {
        tmp[i] = arr[f_2];
        ++i;
        ++f_2;
    }

    for (int i = first; i <= last; ++i) {
        arr[i] = tmp[i];
    }
}

void MergeSort(std::vector<int>& arr, int first, int last)
{
    if (first < last) {
    int mid = (first + last) / 2;
    MergeSort(arr, first, mid);
    MergeSort(arr, mid + 1, last);
    Merge(arr, first, mid, last);
    }
}
int main () {
    std::vector<int> vec;
    srand(time(0));
    std::ofstream WriteFile("file.txt");
    long size = 1000000;
    for (int i = 0; i < size; ++i) {
    WriteFile << rand() % 9 << '\n';
    }
    WriteFile.close();
    std::string text;
    std::ofstream file1("file1.txt");
    std::ofstream file2("file2.txt");
    std::ofstream file3("file3.txt");
    std::ofstream file4("file4.txt");
    std::ofstream file5("file5.txt");
    std::ofstream file6("file6.txt");
    std::ofstream file7("file7.txt");
    std::ofstream file8("file8.txt");
    std::ofstream file9("file9.txt");
    std::ofstream file10("file10.txt");
    std::ofstream file11("file11.txt");
    std::ofstream file12("file12.txt");
    std::ofstream file13("file13.txt");
    std::ofstream file14("file14.txt");
    std::ofstream file15("file15.txt");
    std::ofstream file16("file16.txt");
    std::ofstream file17("file17.txt");
    std::ofstream file18("file18.txt");
    std::ofstream file19("file19.txt");
    std::ofstream file20("file20.txt");
    std::ifstream ReadFile("file.txt");

    int flag = 1;
    int count = 100000;
    for (int i = 0; i < count;) {
        std::getline(ReadFile, text);
        if (flag == 1) {
        vec.push_back(stoi(text));
        i += (text.size() + 1);
        if (i >= count) {
            flag = 2;
            i = 0;
        MergeSort(vec, 0, vec.size() - 1 );
        for (int j = 0; j < vec.size(); ++j) {
            file1 << vec[j] << '\n';
        }
        vec.clear();
        }
        }

        if (flag == 2) {
        vec.push_back(stoi(text));
        i += (text.size() + 1);
        if (i >= count) {
            flag = 3;
            i = 0;
        MergeSort(vec, 0, vec.size() - 1 );
        for (int j = 0; j < vec.size(); ++j) {
            file2 << vec[j] << '\n';
        }
        vec.clear();
        }
        }

       if (flag == 3) {
        vec.push_back(stoi(text));
        i += (text.size() + 1);
        if (i >= count) {
            flag = 4;
            i = 0;
        MergeSort(vec, 0, vec.size() - 1 );
        for (int j = 0; j < vec.size(); ++j) {
            file3 << vec[j] << '\n';
        }
        vec.clear();
        }
        }

        if (flag == 4) {
        vec.push_back(stoi(text));
        i += (text.size() + 1);
        if (i >= count) {
            flag = 5;
            i = 0;
        MergeSort(vec, 0, vec.size() - 1 );
        for (int j = 0; j < vec.size(); ++j) {
            file4 << vec[j] << '\n';
        }
        vec.clear();
        }
        }

        if (flag == 5) {
        vec.push_back(stoi(text));
        i += (text.size() + 1);
        if (i >= count) {
            flag = 6;
            i = 0;
        MergeSort(vec, 0, vec.size() - 1 );
        for (int j = 0; j < vec.size(); ++j) {
            file5 << vec[j] << '\n';
        }
        vec.clear();
        }
        }

        if (flag == 6) {
        vec.push_back(stoi(text));
        i += (text.size() + 1);
        if (i >= count) {
            flag = 7;
            i = 0;
        MergeSort(vec, 0, vec.size() - 1 );
        for (int j = 0; j < vec.size(); ++j) {
            file6 << vec[j] << '\n';
        }
        vec.clear();
        }
        }

        if (flag == 7) {
        vec.push_back(stoi(text));
        i += (text.size() + 1);
        if (i >= count) {
            flag = 8;
            i = 0;
        MergeSort(vec, 0, vec.size() - 1 );
        for (int j = 0; j < vec.size(); ++j) {
            file7 << vec[j] << '\n';
        }
        vec.clear();
        }
        }

        if (flag == 8) {
        vec.push_back(stoi(text));
        i += (text.size() + 1);
        if (i >= count) {
            flag = 9;
            i = 0;
        MergeSort(vec, 0, vec.size() - 1 );
        for (int j = 0; j < vec.size(); ++j) {
            file8 << vec[j] << '\n';
        }
        vec.clear();
        }
        }

        if (flag == 9) {
        vec.push_back(stoi(text));
        i += (text.size() + 1);
        if (i >= count) {
            flag = 10;
            i = 0;
        MergeSort(vec, 0, vec.size() - 1 );
        for (int j = 0; j < vec.size(); ++j) {
            file9 << vec[j] << '\n';
        }
        vec.clear();
        }
        }

        if (flag == 10) {
        vec.push_back(stoi(text));
        i += (text.size() + 1);
        if (i >= count) {
            flag = 11;
            i = 0;
        MergeSort(vec, 0, vec.size() - 1 );
        for (int j = 0; j < vec.size(); ++j) {
            file10 << vec[j] << '\n';
        }
        vec.clear();
        }
        }

        if (flag == 11) {
        vec.push_back(stoi(text));
        i += (text.size() + 1);
        if (i >= count) {
            flag = 12;
            i = 0;
        MergeSort(vec, 0, vec.size() - 1 );
        for (int j = 0; j < vec.size(); ++j) {
            file11 << vec[j] << '\n';
        }
        vec.clear();
        }
        }

        if (flag == 12) {
        vec.push_back(stoi(text));
        i += (text.size() + 1);
        if (i >= count) {
            flag = 13;
            i = 0;
        MergeSort(vec, 0, vec.size() - 1 );
        for (int j = 0; j < vec.size(); ++j) {
            file12 << vec[j] << '\n';
        }
        vec.clear();
        }
        }

        if (flag == 13) {
        vec.push_back(stoi(text));
        i += (text.size() + 1);
        if (i >= count) {
            flag = 14;
            i = 0;
        MergeSort(vec, 0, vec.size() - 1 );
        for (int j = 0; j < vec.size(); ++j) {
            file13 << vec[j] << '\n';
        }
        vec.clear();
        }
        }

        if (flag == 14) {
        vec.push_back(stoi(text));
        i += (text.size() + 1);
        if (i >= count) {
            flag = 15;
            i = 0;
        MergeSort(vec, 0, vec.size() - 1 );
        for (int j = 0; j < vec.size(); ++j) {
            file14 << vec[j] << '\n';
        }
        vec.clear();
        }
        }

        if (flag == 15) {
        vec.push_back(stoi(text));
        i += (text.size() + 1);
        if (i >= count) {
            flag = 16;
            i = 0;
        MergeSort(vec, 0, vec.size() - 1 );
        for (int j = 0; j < vec.size(); ++j) {
            file15 << vec[j] << '\n';
        }
        vec.clear();
        }
        }

        if (flag == 16) {
        vec.push_back(stoi(text));
        i += (text.size() + 1);
        if (i >= count) {
            flag = 17;
            i = 0;
        MergeSort(vec, 0, vec.size() - 1 );
        for (int j = 0; j < vec.size(); ++j) {
            file16 << vec[j] << '\n';
        }
        vec.clear();
        }
        }

        if (flag == 17) {
        vec.push_back(stoi(text));
        i += (text.size() + 1);
        if (i >= count) {
            flag = 18;
            i = 0;
        MergeSort(vec, 0, vec.size() - 1 );
        for (int j = 0; j < vec.size(); ++j) {
            file17 << vec[j] << '\n';
        }
        vec.clear();
        }
        }

        if (flag == 18) {
        vec.push_back(stoi(text));
        i += (text.size() + 1);
        if (i >= count) {
            flag = 19;
            i = 0;
        MergeSort(vec, 0, vec.size() - 1 );
        for (int j = 0; j < vec.size(); ++j) {
            file18 << vec[j] << '\n';
        }
        vec.clear();
        }
        }
        if (flag == 19) {
        vec.push_back(stoi(text));
        i += (text.size() + 1);
        if (i >= count) {
            flag = 20;
            i = 0;
        MergeSort(vec, 0, vec.size() - 1 );
        for (int j = 0; j < vec.size(); ++j) {
            file19 << vec[j] << '\n';
        }
        vec.clear();
        }
        }
        if (flag == 20) {
        vec.push_back(stoi(text));
        i += (text.size() + 1);
        if (i >= count) {
            flag = 21;
            //i = 0;
        MergeSort(vec, 0, vec.size() - 1 );
        for (int j = 0; j < vec.size(); ++j) {
            file20 << vec[j] << '\n';
        }
        vec.clear();
        }
        }
    }
    file1.close();
    file2.close();
    file3.close();
    file4.close();
    file5.close();
    file6.close();
    file7.close();
    file8.close();
    file9.close();
    file10.close();
    file11.close();
    file12.close();
    file13.close();
    file14.close();
    file15.close();
    file16.close();
    file17.close();
    file18.close();
    file19.close();
    file20.close();

    std::ifstream ReadFile1("file1.txt");
    std::ifstream ReadFile2("file2.txt");
    std::ifstream ReadFile3("file3.txt");
    std::ifstream ReadFile4("file4.txt");
    std::ifstream ReadFile5("file5.txt");
    std::ifstream ReadFile6("file6.txt");
    std::ifstream ReadFile7("file7.txt");
    std::ifstream ReadFile8("file8.txt");
    std::ifstream ReadFile9("file9.txt");
    std::ifstream ReadFile10("file10.txt");
    std::ifstream ReadFile11("file11.txt");
    std::ifstream ReadFile12("file12.txt");
    std::ifstream ReadFile13("file13.txt");
    std::ifstream ReadFile14("file14.txt");
    std::ifstream ReadFile15("file15.txt");
    std::ifstream ReadFile16("file16.txt");
    std::ifstream ReadFile17("file17.txt");
    std::ifstream ReadFile18("file18.txt");
    std::ifstream ReadFile19("file19.txt");
    std::ifstream ReadFile20("file20.txt");

    std::ofstream ReadFile_1("file_1.text");
    std::ofstream ReadFile_2("file_2.text");
    std::ofstream ReadFile_3("file_3.text");
    std::ofstream ReadFile_4("file_4.text");
    std::ofstream ReadFile_5("file_5.text");
    std::ofstream ReadFile_6("file_6.text");
    std::ofstream ReadFile_7("file_7.text");
    std::ofstream ReadFile_8("file_8.text");
    std::ofstream ReadFile_9("file_9.text");
    std::ofstream ReadFile_10("file_10.text");

    merge_two(ReadFile1, ReadFile2, ReadFile_1, size);
    merge_two(ReadFile3, ReadFile4, ReadFile_2, size);
    merge_two(ReadFile5, ReadFile6, ReadFile_3, size);
    merge_two(ReadFile7, ReadFile8, ReadFile_4, size);
    merge_two(ReadFile9, ReadFile10, ReadFile_5, size);
    merge_two(ReadFile11, ReadFile12, ReadFile_6, size);
    merge_two(ReadFile13, ReadFile14, ReadFile_7, size);
    merge_two(ReadFile15, ReadFile16, ReadFile_8, size);
    merge_two(ReadFile17, ReadFile18, ReadFile_9, size);
    merge_two(ReadFile19, ReadFile20, ReadFile_10, size);

    ReadFile_1.close();
    ReadFile_2.close();
    ReadFile_3.close();
    ReadFile_4.close();
    ReadFile_5.close();
    ReadFile_6.close();
    ReadFile_7.close();
    ReadFile_8.close();
    ReadFile_9.close();
    ReadFile_10.close();

    ReadFile1.close();
    ReadFile2.close();
    ReadFile3.close();
    ReadFile4.close();
    ReadFile5.close();
    ReadFile6.close();
    ReadFile7.close();
    ReadFile8.close();
    ReadFile9.close();
    ReadFile10.close();
    ReadFile11.close();
    ReadFile12.close();
    ReadFile13.close();
    ReadFile14.close();
    ReadFile15.close();
    ReadFile16.close();
    ReadFile17.close();
    ReadFile18.close();
    ReadFile19.close();
    ReadFile20.close();

    std::ifstream File1("file_1.text");
    std::ifstream File2("file_2.text");
    std::ifstream File3("file_3.text");
    std::ifstream File4("file_4.text");
    std::ifstream File5("file_5.text");
    std::ifstream File6("file_6.text");
    std::ifstream File7("file_7.text");
    std::ifstream File8("file_8.text");
    std::ifstream File9("file_9.text");
    std::ifstream File10("file_10.text");

    std::ofstream ReadFile1_("file1_.text");
    std::ofstream ReadFile2_("file2_.text");
    std::ofstream ReadFile3_("file3_.text");
    std::ofstream ReadFile4_("file4_.text");
    std::ofstream ReadFile5_("file5_.text");

    merge_two(File1, File2, ReadFile1_, size);
    merge_two(File3, File4, ReadFile2_, size);
    merge_two(File5, File6, ReadFile3_, size);
    merge_two(File7, File8, ReadFile4_, size);
    merge_two(File9, File10, ReadFile5_, size);

    ReadFile1_.close();
    ReadFile2_.close();
    ReadFile3_.close();
    ReadFile4_.close();
    ReadFile5_.close();

    File1.close();
    File2.close();
    File3.close();
    File4.close();
    File5.close();
    File6.close();
    File7.close();
    File8.close();
    File9.close();
    File10.close();

    std::ofstream Writefile1("file1_1.text");
    std::ofstream Writefile2("file1_2.text");

    std::ifstream Read1("file1_.text");
    std::ifstream Read2("file2_.text");
    std::ifstream Read3("file3_.text");
    std::ifstream Read4("file4_.text");
    std::ifstream Read5("file5_.text");

    merge_two(Read1, Read2, Writefile1, size);
    merge_two(Read3, Read4, Writefile2, size);

    Read1.close();
    Read2.close();
    Read3.close();
    Read4.close();

    Writefile1.close();
    Writefile2.close();

    std::ifstream Read_one("file1_1.text");
    std::ifstream Read_two("file1_2.text");

    std::ofstream file_one("one_file.text");

    merge_two(Read_one, Read_two, file_one, size);

    file_one.close();
    std::ifstream File_One("one_file.text");

    std::ofstream End_file("end_file.text");

    merge_two(Read5, File_One, End_file, size);
    End_file.close();
    File_One.close();
    Read5.close();
    ReadFile.close();
}
