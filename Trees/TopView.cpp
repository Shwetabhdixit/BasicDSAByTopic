// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

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

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

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
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends

/***
Same logic as bottom view, only the first entry in the map is the final one, since we now looking for the topmost node
***/

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    
    struct calNode{
        Node* p;
        int hd;
    };
    vector<int> topView(Node *root)
    {
        vector<int> v;
        if(root==NULL)
        {
            return v;
        }
        calNode* new_root = new calNode();
        new_root->hd=0;
        new_root->p = root;
        queue<calNode*> q;
        q.push(new_root);
        map<int,int> m;
        while(!q.empty())
        {
            calNode* current = q.front();
            calNode* left =  new calNode();
            calNode* right = new calNode();
            if(m.find(current->hd)==m.end())
            {
                m[current->hd] = current->p->data;
            }
            if(current!=NULL && current->p!=NULL && current->p->left!=NULL)
            {
                left->hd = current->hd-1;
                left->p = current->p->left;
                q.push(left);
            }
            if(current!=NULL & current->p!=NULL && current->p->right!=NULL)
            {
                right->hd = current->hd+1;
                right->p = current->p->right;
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

};



// { Driver Code Starts.

int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
