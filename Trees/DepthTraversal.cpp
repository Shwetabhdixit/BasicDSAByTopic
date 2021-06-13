#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; */

class Solution {
  public:
  	

  
  void inOrderHelper(Node* root, vector<int>& v)
  {
      if(root==NULL)
      {
          return ;
      }
      inOrderHelper(root->left,v);
      v.push_back(root->data);
      inOrderHelper(root->right,v);
      return ;
  }
  
  void preOrderHelper(Node* root, vector<int>& v)
  {
      if(root==NULL)
      {
          return ;
      }
    	v.push_back(root->data);
      preOrderHelper(root->left,v);
      preOrderHelper(root->right,v);
      return ;
  }
  
  void postOrderHelper(Node* root, vector<int>& v)
  {
      if(root==NULL)
      {
          return ;
      }
      postOrderHelper(root->left,v);
      postOrderHelper(root->right,v);
      v.push_back(root->data);
      return ;
  }
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        vector<int> v;
        inOrderHelper(root,v);
        return v;
    }
    vector<int> preOrder(Node* root) {
        vector<int> v;
        preOrderHelper(root,v);
        return v;
    }
    vector<int> postOrder(Node* root) {
        vector<int> v;
        postOrderHelper(root,v);
        return v;
    }
};

// { Driver Code Starts.

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        Solution ob;
        vector<int> res = ob.inOrder(root);
        cou<<"INORDER "<<endl;
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cou<<"PREORDER "<<endl;
        vector<int> res1 = ob.preOrder(root);
        for (int i = 0; i < res1.size(); i++) cout << res1[i] << " ";
        cou<<"POSTORDER "<<endl;
        vector<int> res2 = ob.postOrder(root);
        for (int i = 0; i < res2.size(); i++) cout << res2[i] << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends
