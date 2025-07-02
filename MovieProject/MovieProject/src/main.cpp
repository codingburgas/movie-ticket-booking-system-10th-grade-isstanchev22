#include <iostream>
#include "../include/menu.h"

int main() {
    std::cout << R"(
 __  __             _       __  __       _       
|  \/  | ___  _ __ (_) ___ |  \/  | __ _(_)_ __  
| |\/| |/ _ \| '_ \| |/ _ \| |\/| |/ _` | | '_ \ 
| |  | | (_) | | | | | (_) | |  | | (_| | | | | |
|_|  |_|\___/|_| |_|_|\___/|_|  |_|\__,_|_|_| |_|

               Welcome to MovieMate!
    )" << std::endl;

    showMenu();
    return 0;
}
