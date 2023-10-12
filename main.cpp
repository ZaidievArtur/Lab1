#include "Program.h"

int main() {
    system("chcp 1251");
    try {
        Program().run();
    } catch (std::exception& error) {
        std::cout << error.what();
    }

    return 0;
}
