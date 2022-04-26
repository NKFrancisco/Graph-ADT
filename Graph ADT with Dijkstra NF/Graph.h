////
// Author:		Nick Francisco
// School:		Everett Community College
// Class:		CS 233 Advance Data Structures and Intro to Algorithms 
// Quarter:		Spring 2021
// Assignment:  Program 4 Graph ADT w/ Dijkstra's Algorithm
// Description: This program implements a graph data structure utilizing an  
//	adjacency list. It also uses dijkstras algorithm to find the shortest 
//	path to every vertex on the map given a starting vertex 
////

#pragma once

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Graph
{
private:

	class Node
	{
	public:

		typedef pair<int, int> edge;

		//Node 
		int value = 0;
		int travelWeight = 0;

		vector<edge> edgeList;

		Node* prevPath;

		//Constructor
		Node(int key) {
			this->value = key;
			this->prevPath = nullptr;
		}
	};

	//Total Nodes
	int total;

	//Adjacency List 
	vector<Node*> adjList;

public:

	//Constructor
	Graph() {
		total = 0;
	}
	
	void addVertex(int key) {

		//Empty List
		if (adjList.size() == 0) {

			Node* vert = new Node(key);
			adjList.push_back(vert);
			total = total + 1;

			return;
		}
		//Not Empty
		else {

			//Checking if in adjList already
			for (int i = 0; i < adjList.size(); i++) {

				Node *temp = adjList.at(i);

				if (temp->value == key) {
					return;
				}
			}

			//Not in adjList adding
			Node* vert = new Node(key);
			adjList.push_back(vert);
			total = total + 1;
		}

	}

	void addEdge(int key, int connectingKey, int weight) {

		//Empty Map
		if (this->total == 0) {
			return;
		}
		else {
			for (int i = 0; i < adjList.size(); i++) {

				Node* first = adjList.at(i);

				if (first->value == key) {
					//Found First Node 

					for (int j = 0; j < adjList.size(); j++) {

						Node* second = adjList.at(j);

						if (second->value == connectingKey) {
							//Found Conecting Node 
							
							//Connecting edge to first node
							first->edgeList.push_back(make_pair(connectingKey, weight));

							//Connecting edge to second node
							second->edgeList.push_back(make_pair(key, weight));
						
						}
					}
				}
			}
		}
	}

	//For PQ
	struct ComparePtr
	{
		bool operator ()(const Node* left, const Node* right) const
		{
			return left->travelWeight > right->travelWeight;
		}
	};

	bool compareWeight(int first, int second) const {
		return (first > second); 
	}

	//Finds Shortest path 
	void shortestPath(int key) {

		//Empty Map Check
		if (total == 0) {
			return;
		}

		//Priority Queue
		priority_queue < Node*, vector<Node*>, ComparePtr > pq;

		//Distance Vector
		vector<Node*> distance; 

		//Finding starting node and addiing to PQ
		Node* start = nullptr;

		for (int i = 0; i < total; i++) {
			if (adjList.at(i)->value == key) {
				start = adjList.at(i);
			}
		}

		//Key not in map
		if (start == nullptr) {
			return;
		}
		
		//Setting weight and adding
		start->travelWeight = 0; 
		pq.push(start);

		//Adding remaning vertices to PQ with max weight
		for (int i = 0; i < total; i++) {
			if (adjList.at(i)->value != key) {
				
				Node* temp = adjList.at(i);
				temp->travelWeight = 9999; 
			}
		}

		while (!pq.empty()) {

			//Extrating first node froom PQ
			Node* current = pq.top();
			pq.pop();

			//Looping throught adj vertexes
			for (int i = 0; i < current->edgeList.size(); i++) {

				int nextKey = current->edgeList.at(i).first;
				Node* adj = findKey(nextKey);

				int totalWeight = current->travelWeight + current->edgeList.at(i).second;

				if (totalWeight < adj->travelWeight) {

					adj->travelWeight = totalWeight;
					adj->prevPath = current; 

					pq.push(adj); 
				}
			}
		}

		//Printing shortest path for all nodes 
		for (int i = 0; i < total; i++) {

			cout << adjList.at(i)->value << " - Travel Weight: "
				<< adjList.at(i)->travelWeight << endl << "Path: ";
			
			vector<Node*> path; 
			Node* it = adjList.at(i)->prevPath;

			while (it != nullptr) {

				path.push_back(it);
				it = it->prevPath;
			}

			if (path.size() > 0) {

				for (int j = path.size() - 1; j >= 0; j--) {
					cout << path.at(j)->value << "->";
				}
			}

			cout << adjList.at(i)->value << endl << endl;
		}

		//Erasing travelWight and prevPath for future 
		//shortest paths 
		for (int i = 0; i < total; i++) {

			Node* it = adjList.at(i);
			it->travelWeight = 0;
			it->prevPath = nullptr;
		}
	}

	Node* findKey(int key) {

		for (int i = 0; i < total; i++) {
			if (adjList.at(i)->value == key)
				return adjList.at(i);
		}
	}
};

