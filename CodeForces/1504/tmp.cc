#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int pre[]
typedef struct TreeNode {
    int idx;
    int data;
    TreeNode *Ltree;
    TreeNode *Rtree;
    TreeNode *parent;
} TreeNode;
void IDR (TreeNode *Node){
    if(Node == NULL) {
        return;
    }
    IDR(Node ->Ltree);
    cout << Node -> data << endl;
    IDR(Node ->Rtree);
}
int main() {
    
}