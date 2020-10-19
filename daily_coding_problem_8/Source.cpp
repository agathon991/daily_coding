#include <corecrt.h>
#include <stdio.h>
// 
// This problem was asked by Google.
// 
// A unival tree(which stands for "universal value") is a tree where all nodes under it have the same value.
// 
// Given the root to a binary tree, count the number of unival subtrees.
// 
// For example, the following tree has 5 unival subtrees :
// 
//       0
//      / \
//     1   0
//        / \
//       1   0
//      / \
//     1   1
// 

class node
{
public:
    int val;
    node * left;
    node * right;

    node(int val, node * left = NULL, node * right = NULL)
    {
        this->val = val;
        this->right = right;
        this->left = left;
    }
};


int find_uni_trees(node * n, int & child_tree_val)
{
    int num_trees = 0;
    int left_tree_val = -1;
    int right_tree_val = -1;

    if (n == NULL) return 0;
    if (n->left)  num_trees += find_uni_trees(n->left, left_tree_val);
    if (n->right) num_trees += find_uni_trees(n->right, right_tree_val);

    if (!n->left && !n->right)
    {
        // at a leaf node
        num_trees = 1;
        child_tree_val = n->val;
    }
    else
    {
        // not a leaf node
        if ((left_tree_val == right_tree_val) && (right_tree_val == n->val))
        {
            // matches the children nodes
            num_trees += 1;
        }
        else
        {
            child_tree_val = -1;
        }
    }
    return num_trees;
}



int main(int argc, char** argv)
{
    int child_tree_val = -1;
    node tree = node(0, &node(1), &node(0, &node(1, &node(1), &node(1)), &node(0)));

    printf("Universal trees from node: % 4d\n", find_uni_trees(&tree, child_tree_val));


}


