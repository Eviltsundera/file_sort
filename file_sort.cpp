#include "file_sort.h"
#include <fstream>
#include <string>
#include <iostream>

void file_sort(const std::string& filename) {
    uint32_t current_series_len = 1;
    uint32_t file_len = get_file_length_in_lines(filename);

    while (current_series_len < file_len) {
        divide_file(filename, current_series_len);
        merge_files(filename, current_series_len);
        current_series_len *= 2;
    }
}

void get(std::ifstream& in, std::string& str) {
    if (!str.empty()) {
        return;
    }
    if (in) {
        in >> str;
    }
}

void transfer_series(std::ofstream& out, std::ifstream& in, uint32_t series_len) {
    std::string input;
    for (uint32_t i = 0; i < series_len; ++i) {
        if (in) {
            get(in, input);
            if (!input.empty()) {
                out << input << '\n';
                input = "";
            }
        } else {
            break;
        }
    }
}

void divide_file(const std::string& filename, uint32_t series_len) {
    std::ofstream outf1("f1.txt", std::ios::trunc);
    std::ofstream outf2("f2.txt", std::ios::trunc);
    std::ifstream inf(filename);

    bool flag = true;
    while (inf) {
        if (flag) {
            transfer_series(outf1, inf, series_len);
            flag = false;
        } else {
            transfer_series(outf2, inf, series_len);
            flag = true;
        }
    }
}

uint32_t get_file_length_in_lines(const std::string& filename) {
    std::ifstream inf(filename);

    std::string input;
    uint32_t counter = 0;
    while (inf) {
        getline(inf, input);
        ++counter;
    }

    return counter - 1;
}

void merge_files(const std::string& filename, uint32_t series_len) {
    std::ifstream inf1("f1.txt");
    std::ifstream inf2("f2.txt");
    std::ofstream outf(filename, std::ios::trunc);

    while (inf1 || inf2) {
        uint32_t merged_from_1 = 0;
        uint32_t merged_from_2 = 0;
        std::string str1;
        std::string str2;

        while ((merged_from_1 < series_len && inf1) || (merged_from_2 < series_len && inf2)) {
            if (merged_from_1 < series_len && inf1) {
                get(inf1, str1);
            }
            if (merged_from_2 < series_len && inf2) {
                get(inf2, str2);
            }

            if (str1.empty() && str2.empty()) {
                break;
            }
            if (str1.empty()) {
                outf << str2 << '\n';
                str2 = "";
                merged_from_2++;
                continue;;
            }
            if (str2.empty()) {
                outf << str1 << '\n';
                str1 = "";
                merged_from_1++;
                continue;
            }

            if (str1 < str2) {
                outf << str1 << '\n';
                str1 = "";
                merged_from_1++;
            } else {
                outf << str2 << '\n';
                str2 = "";
                merged_from_2++;
            }
        }
    }

}

