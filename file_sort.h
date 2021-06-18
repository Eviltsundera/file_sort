#pragma once
#include <string>

void file_sort(const std::string& filename);

uint32_t get_file_length_in_lines(const std::string& filename);

void divide_file(const std::string& filename, uint32_t series_len);

void merge_files(const std::string& filename, uint32_t series_len);
