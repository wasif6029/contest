#include <bits/stdc++.h>

using namespace std;

class DisjointSet{
public:    
    int parent[1000];
    void create_family(int );
    int find_parent(int );
    void make_union(int ,int );
};

void DisjointSet :: create_family(int child)
{
    parent[child]=child;
}
int DisjointSet :: find_parent(int child)
{
    if(child == parent[child])return child;
    return parent[child] = find_parent(parent[child]);
}
void DisjointSet :: make_union(int father,int child)
{
    if(find_parent(father)==find_parent(child))return ;
    parent[child]=father;
}

class Edge{
public:
    int p1,p2,cost;
    Edge(){}
    Edge(int p1,int p2,int cost)
    {
        this->p1 = p1;
        this->p2 = p2;
        this->cost = cost;
    }
    bool operator < (Edge const &e1)
    {
        return cost<e1.cost;
    }
};

template <typename TYPE> class Node{
public:
    int id;
    inline static int ID = 0;
    TYPE element;
    int cost;
    Node(){}
    Node(TYPE element)
    {
        this->element = element;
        id = ++ID;
    }
};

template <typename TYPE> int kruskal(vector<Edge>&edges,const vector<Node<TYPE>>&nodes)
{
    int total_cost=0;
    DisjointSet ds;
    sort(edges.begin(),edges.end());
    for(Node<TYPE> node: nodes)
    {
        ds.create_family(node.id);
    }
    for(Edge edge: edges)
    {   
        int par1 = ds.find_parent(edge.p1);
        int par2 = ds.find_parent(edge.p2);
        if(par1 == par2)continue;
        ds.make_union(par1,par2);
        total_cost+=edge.cost;
    }
    return total_cost;
}



class Point{
public:
    int x,y;
    Point(){}
    Point(int x,int y)
    {
        this->x = x;
        this->y = y;
    }
};

inline int find_cost(Point p1,Point p2)
{
    return abs(p1.x-p2.x) + abs(p1.y-p2.y);
}

int solve(const vector<Point>& points)
{
    vector<Edge>edges;
    vector<Node<Point>>nodes;
    for(Point point:points)
    {
        nodes.push_back(Node(point));
    }
    for(int i = 0;i<nodes.size()-1;i++)
    {
        for(int j = i+1;j<nodes.size();j++)
        {
            edges.push_back(Edge(nodes[i].id,nodes[j].id,find_cost(nodes[i].element,nodes[j].element)));
        }
    }
    return kruskal(edges,nodes);
}

int main() 
{
    int n;
    cin>>n;
    vector<Point>points;
    while(n--)
    {
        int x,y;
        cin>>x>>y;
        points.push_back(Point(x,y));
    }
    cout<<solve(points);
}




/********************

5
0 0
2 2
3 10
5 2
7 0

********************/



























