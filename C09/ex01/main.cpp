#include "RPN.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "commande example: ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 \" " << std::endl;
        return -1;
    }
    RPN rpn;
    rpn.calculateRpn(av[1]);
}
