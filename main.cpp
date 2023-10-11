#include "Program.h"

int main() {
    try {
        Program().run();
    } catch (std::exception& error) {
        std::cout << error.what();
    }



    return 0;
}
