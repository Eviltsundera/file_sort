#pragma once

#include "random_string_generator.h"

class big_file_generator {
public:
    big_file_generator(uint32_t max_str_len, uint32_t amount_of_lines);
    void generate_file() const;
private:
    uint32_t _max_str_len;
    uint32_t _amount_of_lines;
    mutable std::mt19937 _mersenne;
};
