#include <iostream>
#include "puzzle_n_minus_1.hpp"


int main(){
    Puzzle p(4,4);

    p.printBoard();
    std::cout << std::endl;
    p.makeMove(right);
    p.makeMove(right);
    p.makeMove(right);

    // p.printBoard();
    // std::cout << std::endl;

    // p.makeMove(left);
    // p.makeMove(left);
    // p.makeMove(left);

    // p.printBoard();
    // std::cout << std::endl;

    p.makeMove(down);
    p.makeMove(down);
    p.makeMove(down);

    // p.printBoard();
    // std::cout << std::endl;

    // p.makeMove(up);
    // p.makeMove(up);
    // p.makeMove(up);

    p.printBoard();
    std::cout << std::endl;

    p.makeMove(left);
    p.makeMove(left);
    p.makeMove(left);

    p.printBoard();
    std::cout << std::endl;

    p.makeMove(left);
    p.printBoard();
    std::cout << std::endl;

    std::cout << p.getTileAt(0,2) << std::endl;

    return 0;
}