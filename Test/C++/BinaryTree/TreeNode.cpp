#include "TreeNode.h"
TreeNode::TreeNode(int value):nodeValue(value)
{
    left=NULL;
    right=NULL;
}
TreeNode::~TreeNode()
{
    if(left ！= NULL)
    {
        delete left;
    }
    if(right ！= NULL)
    {
        delete right;
    }    
}

int TreeNode::degree() const
{
   if(left == NULL && right == NULL)
   {
       return 0;
   }
   if(left != NULL && right != NULL)
   {
       return 2;
   }
   return 1;
}

int TreeNode::depth() const
{
    int leftcount=0;
    int rightcount=0;
    if(left != NULL)
    {
         leftcount +=left->count();
    }
    if(right != NULL)
    {
         rightcount +=right->count();
    }
    return leftcount+rightcount+1;
}

int TreeNode::preOrder(Visit visit) const
{
    (* visit)(this);
    if(this ->left != NULL)
    {
        this->left->preOrder(visit);
    }
    if(this ->right != NULL)
    {
        this->right->preOrder(visit);
    }
}

int TreeNode::midOrder(Visit visit) const
{
    
    if(this ->left != NULL)
    {
        this->left->midOrder(visit);
    }
    (* visit)(this);
    if(this ->right != NULL)
    {
        this->right->midOrder(visit);
    }
}
int TreeNode::postOrder(Visit visit) const
{
    
    if(this ->left != NULL)
    {
        this->left->postOrder(visit);
    }    
    if(this ->right != NULL)
    {
        this->right->postOrder(visit);
    }
    (* visit)(this);
}
