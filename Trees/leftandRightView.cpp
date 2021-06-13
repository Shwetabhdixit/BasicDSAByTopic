// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

vector<int> leftView(struct Node *root);

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
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
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
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        vector<int> vec = leftView(root);
        for(int x : vec)
        cout<<x<<" ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
struct calNode{
  Node* p;
  int level;
};

vector<int> rightSideView(Node* root) {
        vector<int> v;
        if(root==NULL)
        {
            return v;
        }
        queue<calNode*> q;
        calNode* new_root = new calNode();
        new_root->level=0;
        new_root->p=root;
        map<int,int> m;
        q.push(new_root);
        while(!q.empty())
        {
            calNode* current = q.front();
            if(m.find(current->level)==m.end())
            {
                m[current->level] = current->p->data;
            }
            if(current!=NULL && current->p!=NULL && current->p->right!=NULL)
            {
                calNode* right = new calNode();
                right->p = current->p->right;
                right->level = current->level+1;
                q.push(right);
            }
            if(current!=NULL && current->p!=NULL && current->p->left!=NULL)
            {
                calNode* left = new calNode();
                left->p = current->p->left;
                left->level = current->level+1;
                q.push(left);
            }
            q.pop();
        }
        for(auto it=m.begin();it!=m.end();it++)
        {
            v.push_back(it->second);
        }
        return v;
    }
vector<int> leftView(Node *root)
{
   vector<int> v;
   if(root==NULL)
   {
       return v;
   }
   queue<calNode*> q;
   calNode* new_root = new calNode();
   new_root->p=root;
   new_root->level=0;
   q.push(new_root);
   map<int,int> m;
   while(!q.empty())
   {
       calNode* current = q.front();
       if(m.find(current->level)==m.end())
       {
           m[current->level] = current->p->data;
       }
       calNode* left = new calNode();
       calNode* right = new calNode();
       if(current!=NULL && current->p!=NULL && current->p->left!=NULL)
       {
           left->p = current->p->left;
           left->level = current->level+1;
           q.push(left);
       }
       if(current!=NULL && current->p!=NULL && current->p->right!=NULL)
       {
           right->p = current->p->right;
           right->level = current->level+1;
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

