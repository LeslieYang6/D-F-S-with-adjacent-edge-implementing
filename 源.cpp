#include<iostream>
#include<vector>

using namespace std;

class Graph
{
private:
	vector<int> arr[100];
public:
	Graph()
	{
		for (int i = 0; i < 100; i++)
			arr[i].push_back(-1);
	}
	void AddEdge(int vertices1, int vertices2);
	void Dfs(int vertices);
	void DFSUtill(vector<int> nearV, vector<int> visited);
};

void Graph::AddEdge(int vertices1, int vertices2)
{   
	if (arr[vertices1][0] == -1)
		arr[vertices1][0] = vertices2;
	for (int i = 0; i < arr[vertices1].size(); i++)
		if (arr[vertices1][i] == vertices2)
			return;
	arr[vertices1].push_back(vertices2);
}

void Graph::Dfs(int x)
{
	vector<int> visited(100, 0);
	visited[x] = 1;
	cout << x << " ";
	DFSUtill(arr[x], visited);
}

void Graph::DFSUtill(vector<int> nearV, vector<int>visited)
{   
	if (nearV[0] == -1)
		return;
	for(int i=0;i<nearV.size();i++)
		if (visited[nearV[i]] != 1)
		{   
			cout << nearV[i] << " ";
			visited[nearV[i]] = 1;
			DFSUtill(arr[nearV[i]], visited);
		}
	return;
}

int main()
{   
	Graph g;
	g.AddEdge(0, 1);
	g.AddEdge(0, 2);
	g.AddEdge(1, 2);
	g.AddEdge(2, 0);
	g.AddEdge(2, 3);
	g.AddEdge(3, 3);

	cout << "Following is Depth First Traversal"
		" (starting from vertex 2) \n";
	g.Dfs(2);
	system("pause");
	return 0;
}