#include <iostream>
#include <BinaryTree.h>
using namespace std;

int main()
{
      struct TreeNode node1={'A',NULL,NULL};
      struct TreeNode node2={'B',NULL,NULL};
      struct TreeNode node3={'C',NULL,NULL};
      struct TreeNode node4={'D',NULL,NULL};
      struct TreeNode node5={'E',NULL,NULL};
      struct TreeNode node6={'F',NULL,NULL};
      struct TreeNode node7={'G',NULL,NULL};
      struct TreeNode node8={'H',NULL,NULL};
      struct TreeNode node9={'I',NULL,NULL};
      struct TreeNode node10={'J',NULL,NULL};

      node1.left=&node2;
      node1.right=&node6;
      node2.right=&node3;
      node3.left=&node4;
      node3.right=&node5;
      node6.right=&node7;
      node7.left=&node8;

      int depth=getMaxDepth(&node1);
      cout<<"This BinaryTree MaxDepth is:"<<depth<<endl;


}

