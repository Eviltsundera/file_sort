#pragma once

#include <string>
#include <random>

inline std::string generate_random_string(std::mt19937& mersenne, uint32_t max_len) {
    uint32_t len = mersenne() % (max_len - 1) + 1;
    std::string ans;
    for (uint32_t i = 0; i < len; ++i) {
        ans += static_cast<char>(mersenne() % 26 + 'a');
    }
    return ans;
}
