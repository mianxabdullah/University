#include "binTree.h"
int main()
{
     BinaryTree<int> b(4);
     b.setRoot(1);
     b.setLeftChild(1, 2);
     b.setRightChild(1, 3);
     b.setLeftChild(2, 4);
     b.setRightChild(2, 5);
     b.setLeftChild(3, 6);
     b.setRightChild(3, 7);
     b.setLeftChild(4, 8);
     b.setRightChild(4, 9);
     b.setLeftChild(5, 10);
     cout<<"Display Level: ";
     b.displaylevel(3);
     cout<<"LevelOfNode: "<<b.findLevelOfNode(10)<<endl;
     cout<<"Height of tree: ";
     b.heightOfTree();
     cout << "Acendents: ";
     b.DisplayAncestors(10);
     cout << endl
          << "Decendents: ";
     b.DisplayDecendents(2);
     cout << endl;
     b.LevelOrder();
     cout << "PreOrder: ";
     b.preorder();
     cout << endl
          << "PostOrder: ";
     b.postorder();
     cout << endl
          << "InOrder: ";
     b.inorder();

     BinaryTree<char> a(5);
     a.setRoot('A');
     a.setLeftChild('A', 'B');
     a.setRightChild('A', 'C');
     a.setLeftChild('B', 'D');
     a.setRightChild('B', 'E');
     a.setRightChild('C', 'F');
     a.setRightChild('D', 'H');
     a.setLeftChild('E', 'I');
     a.setRightChild('E', 'J');
     a.setLeftChild('I', 'K');

     cout << endl
          << "Parenthsize View: ";
     a.displayParenthesis();

     cout << endl;
     b.removee(2);
     b.LevelOrder();
}