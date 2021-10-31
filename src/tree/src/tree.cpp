#include "BinaryTree.h"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    BinaryTree tree;
    
    BinaryNode *m = new BinaryNode('M',NULL,NULL);
    BinaryNode *n = new BinaryNode('N',NULL,NULL);
    BinaryNode *g = new BinaryNode('G',m,n);
    BinaryNode *k = new BinaryNode('K',NULL,NULL);
    BinaryNode *l = new BinaryNode('L',NULL,NULL);
    BinaryNode *f = new BinaryNode('F',k,l);
    BinaryNode *j = new BinaryNode('J',NULL,NULL);
    BinaryNode *e = new BinaryNode('E',j,NULL);
    BinaryNode *c = new BinaryNode('C',f,g);
    BinaryNode *h = new BinaryNode('H',NULL,NULL);
    BinaryNode *i = new BinaryNode('I',NULL,NULL);
    BinaryNode *d = new BinaryNode('D',h,i);
    BinaryNode *b = new BinaryNode('B',d,e);    
    BinaryNode *a = new BinaryNode('A',b,c);
    tree.setRoot(a);

    tree.inorder();
    tree.preorder();
    tree.postorder();
    tree.levelorder();
    cout << endl;

    cout << "The number of Nodes : " << tree.getCount() << endl;
    cout << "The number of Leaves : " << tree.getLeafCount() << endl;
    cout << "The height of tree : " << tree.getHeight() << endl;

    delete a,b,c,d,e,f;

    return 0;
}