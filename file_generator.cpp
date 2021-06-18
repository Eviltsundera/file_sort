#include "file_generator.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>

big_file_generator::big_file_generator(uint32_t max_str_len, uint32_t amount_of_lines) :
    _max_str_len(max_str_len),
    _amount_of_lines(amount_of_lines),
    _mersenne(static_cast<unsigned int>(time(nullptr))){}

void big_file_generator::generate_file() const {
    std::ofstream outf("../BigFile.txt");

    if (!outf)
    {
        std::cerr << "Uh oh, BigFile.txt could not be opened for writing!" << std::endl;
        exit(1);
    }

    for (uint32_t i = 0; i < _amount_of_lines; ++i) {
        outf << generate_random_string(_mersenne, _max_str_len) << '\n';
    }

    outf.close();

    system("sort ../BigFile.txt > ../SortedBigFile.txt");
}

