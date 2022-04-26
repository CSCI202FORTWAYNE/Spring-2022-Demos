#ifndef GRAPH_H 
#define GRAPH_H
#include "unorderedLinkedList.h"
#include "linkedqueue.h"
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::string;

class graphType
{
public:
    bool isEmpty() const;
    void createGraph();
    void clearGraph();
    void printGraph() const;
    void depthFirstTraversal();
    void dftAtVertex(int vertex);
    void breadthFirstTraversal();
    graphType(int size = 0);
    ~graphType();
protected:
    int maxSize;
    int gSize;
    unorderedLinkedList<int> * graph;
private:
    void dft(int v, bool visited[]);
};

bool graphType::isEmpty() const
{
    return (gSize == 0);
}

void graphType::createGraph()
{
    ifstream infile;
    string fileName;

    int index;
    int vertex;
    int adjacentVertex;

    if(gSize != 0)
        clearGraph();
    
    cout << "Enter input file name: ";
    cin >> fileName;
    cout << endl;
    infile.open(fileName.c_str());
    if(!infile.is_open())
    {
        cout << "Cannot open input file." << endl;
        return;
    }
    infile >> gSize;
    for(index = 0; index < gSize; index++)
    {
        infile >> vertex;
        infile >> adjacentVertex;
        while(adjacentVertex != -999)
        {
            graph[vertex].insertLast(adjacentVertex);
            infile >> adjacentVertex;
        }
    }
    infile.close();
}

void graphType::clearGraph()
{
    for(int i = 0; i < gSize; i++)
        graph[i].destroyList();
    
    gSize = 0;
}

graphType::graphType(int size)
{
    maxSize = size;
    gSize = 0;
    graph = new unorderedLinkedList<int>[size];
}

graphType::~graphType()
{
    clearGraph();
    delete [] graph;
}

void graphType::printGraph() const
{
    for(int i = 0; i < gSize; i++)
    {
        cout << i << " ";
        graph[i].print();
        cout << endl;
    }
    cout << endl;
}

void graphType::dft(int v, bool visited[])
{
    visited[v] = true;
    cout << " " << v << " ";
    linkedListIterator<int> graphIt;
    for(graphIt = graph[v].begin(); graphIt != graph[v].end(); ++graphIt)
    {
        int w = *graphIt;
        if(!visited[w])
            dft(w, visited);
    }
}

void graphType::depthFirstTraversal()
{
    bool * visited;
    visited = new bool[gSize];
    for(int i = 0; i < gSize; i++)
        visited[i] = false;
    
    for(int i = 0; i < gSize; i++)
    {
        if(!visited[i])
            dft(i, visited);
    }

    delete [] visited;

}

void graphType::dftAtVertex(int vertex)
{
    bool * visited;
    visited = new bool[gSize];
    for(int i = 0; i < gSize; i++)
    {
        visited[i] = false;
    }

    dft(vertex, visited);
    delete [] visited;
}

void graphType::breadthFirstTraversal()
{
    linkedQueueType<int> queue;
    bool * visited;
    visited = new bool[gSize];
    for(int i = 0; i < gSize; i++)
    {
        visited[i] = false;
    }
    linkedListIterator<int> graphIt;
    for(int i = 0; i < gSize; i++)
    {
        if(!visited[i])
        {
            queue.enqueue(i);
            visited[i];
            cout << " " << i << " ";
            while(!queue.isEmptyQueue())
            {
                int u = queue.dequeue();
                for(graphIt = graph[u].begin(); graphIt != graph[u].end(); ++graphIt)
                {
                    int w = *graphIt;
                    if(!visited[w])
                    {
                        queue.enqueue(w);
                        visited[w] = true;
                        cout << " " << w << " ";
                    }
                }
            }
        }
    }
    delete [] visited;
}

#endif