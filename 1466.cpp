#include <bits/stdc++.h>
using namespace std;

struct Node{
    int value;
    Node *left, *right;

    Node (int v){
        value = v;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert_tree (Node *root, int v){
    if (root == NULL)
        return new Node(v);
    
    if (v < root->value)
        root->left = insert_tree(root->left, v);
    else if (v > root->value)
        root->right = insert_tree (root->right, v);

    return root;
}

vector<Node*> BFS (Node* binary_tree){
    queue<Node*>q;
    vector<Node*>res;

    Node* s = binary_tree;
    q.push(s);

    while (!q.empty()){
        Node* curr = q.front();
        q.pop();
        res.push_back(curr);

        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
    return res;
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int C; cin >> C;
    for (int i=0; i<C; i++){
        cout << "Case " << i+1 << ":\n";
        int N; cin >> N;

        Node* binary_tree=nullptr;
        for (int j=0; j<N; j++){
            int M; cin >> M;
            binary_tree = insert_tree(binary_tree, M);
        }
        vector<Node*>result = BFS(binary_tree);  
        int V = result.size();
        for (int v=0; v<V; v++){
            cout << result[v]->value;
            if (v+1 < V) cout << ' ';
        }
        cout << "\n\n";
    }
    return 0;
}