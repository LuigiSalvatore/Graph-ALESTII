#include "Graph.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>

using namespace std;

Graph::Graph()
{
}

Graph::Graph(string filename)
{
    ifstream file;
    file.open(filename);
    string line, v, w;
    if (file.is_open())
    {
        while (getline(file, line))
        {
            stringstream ss(line);
            getline(ss, v, ' ');
            getline(ss, w, ' ');
            addEdge(v, w);
        }
        file.close();
    }
}

vector<string> Graph::getAdj(string v)
{
    return graph[v];
}

vector<string> Graph::getVerts()
{
    vector<string> keys;
    for (auto const &element : graph)
        keys.push_back(element.first);
    return keys;
}

void Graph::addEdge(string v, string w)
{
    addToList(v, w);
    addToList(w, v);
}

void Graph::addToList(string v, string w)
{
    vector<string> &list = graph[v];
    list.push_back(w);
}
