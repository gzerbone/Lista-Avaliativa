int heightTree(Node *p){
    if(p == NULL || p->right == NULL || p->left == NULL){
        return 0;
    }else{
        int sideR = 1 + heightTree(p->right);
        int sideL = 1 + heightTree(p->left);

        if(sideR > sideL){
            return sideR;
        }else{
            return sideL;
        }
    }
}

