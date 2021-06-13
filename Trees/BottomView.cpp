// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


vector <int> bottomView(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

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
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        vector <int> res = bottomView(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends





//Function to return a list containing the bottom view of the given tree.

/***
Logic - 

When you look at a tree from the bottom you can only see one node for each horizontal distance with root being 0.
Suppose, a node has hd as x , the left child has hd as x-1 , and the right child has hd as x+1
So you do a level order traversal , and map the bottommost node corresponding to a horizontal distance ( reason for level order traversal )
If you do not want to create another data type ( calNode here) , you can even use a map
***/
struct calNode{
  Node* node;
  int hd;
};
vector <int> bottomView(Node *root)
{
    vector<int> v;
    if(root == NULL)
    {
        return v;
    }
   queue<calNode*> q; 
   calNode* new_root = new calNode();
   new_root->node = root;
   new_root->hd=0;
   q.push(new_root);
   map<int,int> m;
   while(!q.empty())
   {
       calNode* current = q.front();
       int lhd  = current->hd;
       m[lhd]=current->node->data;
       calNode*  left = new calNode();
       calNode* right = new calNode();
       if(current!=NULL && current->node!=NULL && current->node->left!=NULL)
       {
           left->hd = lhd -1;
           left->node = current->node->left;
           q.push(left);
       }
       if(current!=NULL & current->node!=NULL && current->node->right!=NULL)
       {
           right->hd = lhd+1;
           right->node = current->node->right;
           q.push(right);
       }
       q.pop();
   }
   for(auto it=m.begin();it!=m.end();it++)
   {
       v.push_back(it->second);
   }
   return v;
}


