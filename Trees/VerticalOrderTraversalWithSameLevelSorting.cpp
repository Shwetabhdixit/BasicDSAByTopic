/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 
 
 Question link  - https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/submissions/
 // please suggest a better solution
 */
struct calNode{
    TreeNode* p;
    int hd;
    int level;
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        calNode* new_root = new calNode();
        new_root->hd=0;
        new_root->level=0;
        new_root->p = root;
        queue<calNode*> q;
        q.push(new_root);
        map<int,vector<pair<int,int>>> m;
        while(!q.empty())
        {
            calNode* current = q.front();
            if(m.find(current->hd)!=m.end())
            {
                vector<pair<int,int>> tempvec = m[current->hd];
                tempvec.push_back(make_pair(current->level,current->p->val));
                m[current->hd] = tempvec;
            }
            else
            {
                vector<pair<int,int>> temp;
                temp.push_back(make_pair(current->level,current->p->val));
                m[current->hd]=temp;
            }
            if(current!=NULL && current->p!=NULL && current->p->left!=NULL)
            {
                calNode* left = new calNode();
                left->p=current->p->left;
                left->level=current->level+1;
                left->hd=current->hd-1;
                q.push(left);
            }
            if(current!=NULL && current->p!=NULL && current->p->right!=NULL)
            {
                calNode* right = new calNode();
                right->p=current->p->right;
                right->level=current->level+1;
                right->hd=current->hd+1;
                q.push(right);
            }
            q.pop();
        }
        vector<vector<int>> v;
        for(auto it =m.begin();it!=m.end();it++)
        {
            map<int,vector<int>> nm;
            vector<pair<int,int>> outervec = it->second;
            for(int i=0;i<outervec.size();i++)
            {
                if(nm.find(outervec[i].first)!=nm.end())
                {
                    vector<int> temp2 = nm[outervec[i].first];
                    temp2.push_back(outervec[i].second);
                    sort(temp2.begin(),temp2.end());
                    nm[outervec[i].first] = temp2;
                }
                else
                {
                    vector<int> temp3;
                    temp3.push_back(outervec[i].second);
                    nm[outervec[i].first] = temp3;
                }
            }
            vector<int> finVec;
            for(auto kt = nm.begin();kt!=nm.end();kt++)
            {
                vector<int> finVecInter = nm[kt->first];
                for(int k=0;k<finVecInter.size();k++)
                {
                    finVec.push_back(finVecInter[k]);
                }
            }
            v.push_back(finVec);
            
        }
        return v;
    }
};
