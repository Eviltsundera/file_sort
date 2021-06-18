#include "file_generator.h"
#include "file_sort.h"

int main() {
    big_file_generator generator(256, 100000);
    generator.generate_file();
    file_sort("BigFile.txt");
    // проверить можно командой diff  BigFile.txt SortedBigFile.txt
    return 0;
}
