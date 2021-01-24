// #include <iostream>
#include "BinaryTree.h"
// using namespace std;

BinaryTree::BinaryTree()
{
    root=NULL;
}

Node* BinaryTree::create(map<int,int> &BinaryTree,int index)
{
     if(BinaryTree.find(index) == BinaryTree.end())
     {
         return NULL;
     }
     TreeNode *node=new TreeNode();
     node->nodeValue=BinaryTree[index];
     node->left=create(BinaryTree,index*2);
     node->right=create(BinaryTree,index*2+1);
     return node;
}

int BinaryTree::getMaxDepth(TreeNode *root)
{
    if(root == NULL)
       return 0;
    else
    {
        /* code */
        int left=getMaxDepth(root->left);
        int right=getMaxDepth(root->right);
        return 1+ Math.max(left,right);
    }
    
}

void BinaryTree::preOrder(Visit visit) const
{
    
}