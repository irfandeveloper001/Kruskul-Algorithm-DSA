#include <iostream>
using namespace std;
const int max_vertices = 100;
const int max_edges = 1000;
struct edge{
	int src, dest, weight;
};
class kruskalMst{
	public:
		int parent[max_vertices];
		kruskalMst(int V)
		{
			for(int i=0; i<V; i++)
			{
				parent[i] = i;
			}
		}
		int findParent(int node)
		{
			if(parent[node] == node)
			{
				return node;
			}
			else 
			{
				return findParent(parent[node]);
			}
		}
		int kruskul(edge e[], int E)
		{
			int totalWeight = 0;
			int w[E];  
			for(int i=0; i<E; i++)
			{
				w[i] = e[i].weight;
			}
			for(int i=0; i<E; i++)
			{
				int small = i;
				for(int j=i+1; j<E; j++)
				{
					if(w[j] < w[small])
					{
						small = j;
					}
				}
				if(small != i)
				{
					int temp = w[i];
					w[i] = w[small];
					w[small] = temp;
			}
			}
			for(int i=0; i<E; i++)
			{
				cout <<w[i] <<endl;
			}
			for(int j=0; j<E; j++)
			{ 
				for(int i=0; i<E; i++)
				{
				    if(w[j] == e[i].weight)  // first we used the leastest weighted edge to add....
				    {
						int srcParent = findParent(e[i].src);
						int destParent = findParent(e[i].dest);
						if(srcParent != destParent)
						{
							totalWeight += e[i].weight;
							parent[srcParent] = destParent;
						}
					}
			    }
	    	}
	    	return totalWeight;
		}
};
int main()
{
	int V ,E;
	cout <<"enter the number of vertices and Edges: ";
	cin >> V >> E;
	edge e[max_vertices];
	for(int i=0; i<E; i++) //  edges insteadof vertices because we can add multiple edges
	{ 
		cin >> e[i].src >>e[i].dest >> e[i].weight;
	}
	kruskalMst k(V);
	
	int totalWeight = k.kruskul(e, E);
	 cout << "Total Weight of MST: " << totalWeight << endl;

    return 0;
}
