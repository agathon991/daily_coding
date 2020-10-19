#include <string>

// This problem was asked by Google.
// 
// Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, and deserialize(s), which deserializes the string back into the tree.
// 
// For example, given the following Node class
// 
// class Node :
//     def __init__(self, val, left = None, right = None) :
//     self.val = val
//     self.left = left
//     self.right = right
//     The following test should pass :
// 
// node = Node('root', Node('left', Node('left.left')), Node('right'))
// assert deserialize(serialize(node)).left.left.val == 'left.left'

using namespace std;

class node;
class node
{
public:
    string * val;
    node * left;
    node * right;

    node(string val, node * left = NULL, node * right = NULL)
    {
        this->val = new string(val);
        this->left = left;
        this->right = right;
    }

    ~node()
    {
    }
};

string serialize(node * n, string &s)
{
    s.append(n->val->c_str());
    s.append("|");
    s.append(to_string(n->left ? 1: 0));
    s.append("|");
    s.append(to_string(n->right ? 1: 0));
    s.append("|");

    if (n->left)
    {
        serialize(n->left, s);
    }

    if (n->right)
    {
        serialize(n->right, s);
    }
    return s;
}

void read_value(string& s, string & subs, size_t & off)
{
    size_t v = s.find("|", off);
    subs = s.substr(off, v - off);
    off += ((v - off) + 1);
    return;
}

node * deserialize(string s, size_t & off)
{
    node * ln = NULL;
    node * rn = NULL;

    string value = "";
    string lnode = "";
    string rnode = "";

    read_value(s, value, off);
    read_value(s, lnode, off);
    read_value(s, rnode, off);

    ln = atoi(lnode.c_str()) ? deserialize(s, off) : NULL;
    rn = atoi(rnode.c_str()) ? deserialize(s, off) : NULL;

    node * n = new node(value, ln, rn);

    return n;
}

int main()
{
    node n = node("root", &node("left", &node("left.left")), &node("right"));

    string s = "";
    size_t off = 0;
    node * p = deserialize(serialize(&n, s), off);
    int corrvalue = p->left->left->val->compare("left.left");

    printf("%s\n", ((corrvalue == 0) ? "True" : "False"));

     return 0;
}
