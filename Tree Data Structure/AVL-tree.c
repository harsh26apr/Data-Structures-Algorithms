// AVL Tree implementation in C


#include<stdio.h>

struct AVLNode {
    int data;
    int height;
    struct AVLNode *left;
    struct AVLNode *right;
};

typedef struct AVLNode *Node;

Node root = NULL;

// check for emptyness
int isEmpty() {
    return (root==NULL)?1:0;
}

int height(Node t) {
    return (t==NULL)?0:t->height;
}

int max(int x, int y) {
    return (x>y)?x:y;
}

int getHightBalance(Node t) {
    return (t==NULL)?0:(height(t->left)-height(t->right));
}

Node createNode(int val) {
    Node temp = NULL;
    temp = (Node) malloc( sizeof(struct AVLNode));
    temp->data = val;
    temp->height = 0;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node rotateLeft(Node k) {
    Node y = k->right;
    Node t2 = y->left;

    y->left = k;
    k->right = t2;

    k->height = max(height(k->left),height(k->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node rotateRight(Node k) {
  Node x = k->left;
  Node t2 = x->right;

  x->right = k;
  k->left = t2;

  k->height = max(height(k->left), height(k->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}


Node insert(Node t, int val) {

    if(t == NULL) {
        return createNode(val);
    } else if(val < t->data) {
        t->left = insert(t->left, val);
    } else if(val > t->data) {
        t->right = insert(t->right, val);
    } else return t; // duplicate entry

    t->height = max(height(t->left), height(t->right)) + 1;

    int balance = getHightBalance(t);

    if(balance > 1 && val < t->left->data)
        return rotateRight(t);

    if(balance < -1 && val > t->right->data)
        return rotateLeft(t);

    if(balance > 1 && val > t->left->data) {
        t->left = rotateLeft(t->left);
        return rotateRight(t);
    }

    if(balance < -1 && val < t->right->data) {
        t->right = rotateRight(t->right);
        return rotateLeft(t);
    }

    return t;
}

void inorder(Node t) {
    Node temp = t;
    if(temp != NULL) {
        inorder(temp->left);
        printf("%d  ",temp->data);
        inorder(temp->right);
    }
}

void preorder(Node t) {
    Node temp = t;
    if(temp != NULL) {
        printf("%d  ",temp->data);
        inorder(temp->left);
        inorder(temp->right);
    }
}

void postorder(Node t) {
    Node temp = t;
    if(temp != NULL) {
        inorder(temp->left);
        inorder(temp->right);
        printf("%d  ",temp->data);
    }
}

int findMin(Node t) {
    Node temp = t;
    if(temp == NULL) return -999;
    if(temp->left == NULL) return temp->data;
    else return findMin(temp->left);
}

int findMax(Node t) {
    Node temp = t;
    if(temp == NULL) return -999;
    if(temp->right == NULL) return temp->data;
    else return findMax(temp->right);
}

void collapse() {
    collapse_tree(root);
}

void collapse_tree(Node node) {
    if(node!=NULL) {
        collapse_tree(node->left);
        collapse_tree(node->right);
        free(node);
    }
    node=NULL;
}

// Binary search
void searchNode(int val) {
    search(root,val);
}

void search(Node t, int val) {
    Node temp = t;

    if(temp == NULL) return;
    else if(val < temp->data) search(temp->left, val);
    else if(val > temp->data) search(temp->right, val);
    else if(val == temp->data) {
        printf("The element %d found ...\n", val);
        return;
    } else ;
}

Node remove_node(Node t, int val) {
    if(t == NULL) return;
    else if(val < t->data) {
        t->left = remove_node(t->left, val);
    } else if(val > t->data) {
        t->right = remove_node(t->right, val);
    } else if(val == t->data) {
        if(t->right != NULL && t->left!= NULL) {
            t->data = findMin(t->right);
            t->right = remove_node(t->right, t->data);
        } else if(t->right == NULL || t->left == NULL) {
            Node old = (t->left)?(t->left):t->right;
            if(old == NULL) {
                old = t;
                t = NULL;
            } else t = old;
            // free old node
            free(old);
        } else ;
    }

    if(t == NULL) return t;

    t->height = max(height(t->left),height(t->right)) + 1;
    int balance = getHightBalance(t);

    if(balance > 1 && getHightBalance(t->left) >=0 )
        return rotateRight(t);

    if(balance > 1 && getHightBalance(t->left) < 0) {
        t->left = rotateLeft(t->left);
        return rotateRight(t);
    }

    if(balance < -1 && getHightBalance(t->right) <= 0)
        return rotateLeft(t);

    if(balance < -1 && getHightBalance(t->right) > 0) {
        t->right = rotateRight(t->right);
        return rotateLeft(t);
    }

    return t;
}

void main() {
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 15);
    root = insert(root, 14);
    root = insert(root, 13);
    root = insert(root, 12);
    root = insert(root, 11);
    root = insert(root, 10);

    printf("\n");
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);

    printf("\n");
    printf("Maximum value is %d \n",findMax(root));
    printf("Minimum value is %d \n",findMin(root));

    searchNode(4);

    root = remove_node(root, 4);

    printf("\n Inorder traversal is- \n");
    inorder(root);

    // collapse();

}




