#include<iostream>
#include<queue>
using namespace std;

void printDFS(int** edges, int n,int sv,bool* visited)
{
	cout<<sv<<" ";
	visited[sv]=true;
	for(int i=0;i<n;i++)
	{
		if(sv==i)
		{
			continue;
		}
		if(visited[i] ==false && edges[sv][i]==1)
		{
			printDFS(edges,n,i,visited);
		}
		
	}
	return ;
}
void printBFS(int** edges, int n, int sv,bool* visited)
{
	queue<int> q;
	q.push(sv);
	visited[sv]=true;
	while(!q.empty())
	{
		int currentvertex = q.front();
		cout<<currentvertex<<" ";
		q.pop();
		for(int i=0;i<n;i++)
		{
			if(currentvertex ==i)
			{
				continue;
			}
			if(edges[sv][i]==1 && visited[i]==false)
			{
				q.push(i);
				visited[i]=true;
			}
		}
		
	}
	return;
}
void BFS(int** edges, int n)
{
	bool* visited = new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	for(int i=0;i<n;i++)
	{
		if(visited[i]==false)
		{
			printBFS(edges,n,i,visited);
		}
	}
	cout<<endl;
	delete[] visited;
}

void DFS(int** edges,int n)
{
	bool* visited = new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	for(int i=0;i<n;i++)
	{
		if(visited[i]==false)
		{
			printDFS(edges,n,i,visited);
		}
	}
	cout<<endl;
	delete[] visited;
}


int main()
{
	int n,e;
	cin>>n>>e;
	int** edges = new int*[n];
	for(int i=0;i<n;i++)
	{
		edges[i] = new int[n];
		for(int j=0;j<n;j++)
		{
			edges[i][j]=0;
		}
	}
	for(int i=0;i<e;i++)
	{
		int f,s;
		cin>>f>>s;
		edges[s][f]=1;
		edges[f][s]=1;
	}
	
	cout<<"DFS"<<endl;
	DFS(edges,n);
	cout<<"BFS"<<endl;
	BFS(edges,n);
}
	
