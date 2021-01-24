/*
*
*/
#include <iostream>
#include <cmath>
using namespace std;
class TreeNode;
typedef void (*Visit)(const Node *node);
class TreeNode
{
   public:
      int nodeValue;
      TreeNode *left;
      TreeNode *right;
   public:
      TreeNode(int value);
      ~TreeNode();
    /* data */
   public:
      int degree() const;
      int depth() const;
      int count() const;
    public:
       void preOrder(Visit visit) const;
       void midOrder(Visit visit) const;
       void postOrder(Visit visit) const;
};