#include <iostream>
#include "LLbinTree.h"  
using namespace std;
int main() 
{
    BinaryTree<int> tree;  
    tree.setRoot(1);
    tree.setLeftChild(1, 2);
    tree.setRightChild(1, 3);
    cout << "Root set to: " << tree.getRoot() << endl;
    tree.setLeftChild(2, 4);
    tree.setRightChild(2, 5);
    tree.setLeftChild(3, 6);
    tree.setRightChild(3, 7);
    tree.setLeftChild(4, 8);
    tree.setRightChild(4, 9);
    tree.setLeftChild(5, 10);
    tree.setRightChild(5, 11);
    cout<<"sibling: "<<tree.findNodeSiblings(2)<<endl;
    if(tree.isExternalNode(10))
    {
        cout<<"external"<<endl;
    }
    else
    {
        cout<<"not external"<<endl;
    }
    if(tree.isInternalNode(3))
    {
        cout<<"internal"<<endl;
    }
    else
    {
        cout<<"not internal"<<endl;
    }

    cout << "Preorder traversal: ";
    tree.displaypre();
    cout << endl;
    
    cout << "Inorder traversal: ";
    tree.displaypost();
    cout << endl;
    
    cout << "Postorder traversal: ";
    tree.displayin();
    cout << endl;
    
    cout << "Level order traversal: ";
    tree.LevelOrder();
    cout << endl << endl;
    


    BinaryTree<int> b;  
    b.setRoot(10);
    cout << "Root set to: " << b.getRoot() << endl;
    b.setLeftChild(10,11);
    b.setRightChild(10, 12);
    b.setLeftChild(11, 13);
    b.setRightChild(11, 14);
    b.setLeftChild(14, 16);
    b.setRightChild(16, 7);
    b.setRightChild(12, 15);
    b.LevelOrder();
    cout<<endl;
    //b.mirror();
    //b.LevelOrder();
    //cout<<endl;

    BinaryTree<int> n = b.getMirrorImage();
    n.LevelOrder();
    cout<<endl;

    BinaryTree<int> abc = n;
    cout<<"new: ";
    abc.LevelOrder();
    cout<<endl;

 
    BinaryTree<char> a;
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
    a.displayParenthesized();
    cout<<endl;
    a.LevelOrder();
    //BinaryTree<char> x(a);
    //x.LevelOrder();
}