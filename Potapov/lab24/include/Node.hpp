#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED
class Node
{
public:
    char token;
    Node *left = nullptr;
    Node *right = nullptr;
    Node() = default;
    ~Node() = default;
    Node(const char data);
    Node(const char data, Node *_left, Node *_right);
    char get_token() const;
    Node* get_left() const;
    Node* get_right() const;
    void rewrite_node(Node* temp_node);
};
#include "../src/Node.cpp"
#endif// NODE_HPP_INCLUDED