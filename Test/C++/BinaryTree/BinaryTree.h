#include "TreeNode.h"
#include <map>
using namespace std;


class BinaryTree
{
    private:
       TreeNode *root;
    private:
       TreeNode *create(map<int,int> &BinaryTree,int index);
    public:
       BinaryTree();
       BinaryTree(map<int,int> &BinaryTree);
       ~BinaryTree();
       int getMaxDepth(TreeNode root);
    public:
       void preOrder(Visit visit) const;
       void midOrder(Visit visit) const;
       void postOrder(Visit visit) const;
};
