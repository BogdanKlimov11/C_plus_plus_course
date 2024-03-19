struct Node {
    int key;
    Node* left, *right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int key) {
    if (root == nullptr) return new Node(key);

    if (key < root->key) root->left = insert(root->left, key);
    else if (key > root->key) root->right = insert(root->right, key);

    return root;
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        std::cout << root->key << " ";
        inorder(root->right);
    }
}

void tree_sort(int arr[], int n) {
    Node* root = nullptr;
    for (int i = 0; i < n; ++i)
        root = insert(root, arr[i]);
    inorder(root);
}
