#include "iostream"

using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

Node* insertBST(Node *root,int val){
    if(root==NULL){
        return new Node(val);
    }
    if(val< root->data){
        root->left= insertBST(root->left,val);
    }
    else{
        root->right= insertBST(root->right,val);
    }
    return root;
}

void inOrderPrint(Node *root){
    if(root==NULL){
        return;
    }
    inOrderPrint(root->left);
    cout<<root->data<<" ";
    inOrderPrint(root->right);
}

Node* searchInBst(Node *root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    if(root->data>key){
        return searchInBst(root->left,key);
    }
    return searchInBst(root->right,key);
}
//Delete BST

Node* inOrderSuccessor(Node *root)
{
    Node *curr=root;
    while(curr && curr->left !=NULL){
        curr=curr->left;
    }
    return curr;
}

Node* deleteInBST(Node* root,int key)
{
    if(key < root->data){
        root->left= deleteInBST(root->left, key);
    }
    else if(root->data < key){
        root->right= deleteInBST(root->right, key);
    }
    else{
        if(root->left==NULL){
            Node *temp=root->right;
            free(root);
            return temp;
        }
        else if (root->right==NULL){
            Node *temp=root->left;
            free(root);
            return temp;
        }
        Node *temp=inOrderSuccessor(root->right);
        root->data=temp->data;
        root->right= deleteInBST(root->right,temp->data);
    }
    return root;
}

int main()
{
    //inserBST
//   Node *root=NULL;
//    root= insertBST(root,5);
//    insertBST(root,1);
//    insertBST(root,3);
//    insertBST(root,4);
//    insertBST(root,2);
//    insertBST(root,7);
//    inOrderPrint(root);


        //SearchInBST
       Node *root=new Node(4);
       root->left=new Node(2);
       root->right=new Node(5);
       root->left->left=new Node(1);
       root->left->right=new Node(3);
       root->right->right=new Node(6);

// tree:     4
//          / \
//         2   5
//        / \   \
//       1  3   6
//    if(searchInBst(root,11)==NULL){
//        cout<<"NOT EXIST";
//    }else{
//        cout<<"EXIST";
//    }

    inOrderPrint(root);
    cout<<endl;
 root= deleteInBST(root,5);
 inOrderPrint(root);
    cout<<endl;
 root= deleteInBST(root,2);
    inOrderPrint(root);


}