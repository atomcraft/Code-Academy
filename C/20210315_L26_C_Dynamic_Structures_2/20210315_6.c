/*
Задача 6.
Given the struct BSTNode which represents a node in a binary search
tree, write a function BSTMerge() that will merge the contents of two search
trees into one.
The function does not need to preserve the contents of the input trees.
*/
/*
#include <stdio.h>
#include <stdlib.h>

struct BSTNode{
    BSTNode(int data): m_data(data), m_left(nullptr), m_right(nullptr) {}
    int m_data;
    BSTNode *m_left, *m_right;
};

BSTNode *BSTMerge(BSTNode *tree1, BSTNode *tree2){
    stack1 = Stack();
    stack2 = Stack();
    tree1 = root1;
    tree2 = root2;
    BSTNode[] result;
    while(tree1 || tree2 || stack1 || stack2) {
        while (tree1) {
            stack1.push(tree1);
            tree1 = tree1.left;
        }
        while (tree2) {
            stack2.push(tree2);
            tree2 = tree2.left;
        }
        if ((!stack2) || (stack1 && stack1.top().val <= stack2.top().val)) {
            tree1 = stack1.pop();
            result.push_back(tree1.val);
            tree1 = tree1.right;
        }
        else {
            tree2 = stack2.pop();
            result.push_back(tree2.val);
            tree2 = tree2.right;
        }
    }
    return result;
}

void BSTInsert(BSTNode *&root, int data){
    BSTNode **ptr = &root;
    while (*ptr){
        if (data < (*ptr)->m_data)
        ptr = &(*ptr)->m_left;
        else
        ptr = &(*ptr)->m_right;
    }
    *ptr = new BSTNode(data);
}

BSTNode *BSTGenerate(unsigned n){
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> randData(0, 10000);
    BSTNode *root = nullptr;
    while (n--)
    BSTInsert(root, randData(rng));
    return root;
}

void BSTPrint(BSTNode *node){
    if (!node)
    return;
    BSTPrint(node->m_left);
    std::cout << node->m_data << std::endl;
    BSTPrint(node->m_right);
}

void main(int argc, char* argv[]){
    BSTNode *tree1 = BSTGenerate(20);
    BSTNode *tree2 = BSTGenerate(15);
    BSTNode *merged = BSTMerge(tree1, tree2);
    BSTPrint(merged);
}
*/