#include "../include/Node.hpp"
#include "../include/expressiontree.hpp"
#include <cstdint>
#include <iostream>


int main()
{ std::string expr = "a-(b*c)";
    ExpressionTree tree(expr);

    tree.print_infix_form(tree.get_root());
    std::cout << "\n";
    tree.print_postfix_form(tree.get_root());
    std::cout << "\n";
    tree.print_tree(tree.get_root());
    std::cout << "\n\n\n";
    tree.search_substracts(tree.get_root());
    tree.print_infix_form(tree.get_root());
    std::cout << "\n";
    tree.print_postfix_form(tree.get_root());
    std::cout << "\n";
    tree.print_tree(tree.get_root());
    std::cout << "\n\n\n";
    expr = "8-(c^2-(d*b))";
    std::cout<<expr<<std::endl;
    ExpressionTree tree2(expr);
    tree2.print_infix_form(tree2.get_root());
    std::cout << "\n";
    tree2.print_postfix_form(tree2.get_root());
    std::cout << "\n";
    tree2.print_tree(tree2.get_root());
    std::cout << "\n\n\n";
    tree2.search_substracts(tree2.get_root());
    tree2.print_infix_form(tree2.get_root());
    std::cout << "\n";
    tree2.print_postfix_form(tree2.get_root());
    std::cout << "\n";
    tree2.print_tree(tree2.get_root());
    std::cout << "\n\n\n";
    return 0;
}