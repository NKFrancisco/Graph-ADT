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

#include <iostream>
#include "Graph.h"

using namespace std;

Graph buildGraph();		//Adds vertices and edges 

int main() {

	Graph graph = buildGraph();

	//Finding shortest path for all vertices starting
	//with vertex 1 and 14 
	cout << "Shortest Path for 1..." << endl << endl; 
	graph.shortestPath(1);

	cout << "Shortest Path for 14..." << endl << endl;
	graph.shortestPath(14);

	system("pause");
    return 0; 
}

Graph buildGraph() {

	Graph graph;

	//Adding Vertecies
	for (int i = 0; i < 18; i++) {

		graph.addVertex(i);
	}

	for (int i = 20; i < 38; i++)
	{
		graph.addVertex(i);
	}

	//Adding Edges 

	// 0
	graph.addEdge(0, 1, 8);
	graph.addEdge(0, 2, 8);
	graph.addEdge(0, 7, 4);
	graph.addEdge(0, 14, 4);
	graph.addEdge(0, 20, 8);

	// 1
	graph.addEdge(1, 5, 8);

	// 2
	graph.addEdge(2, 3, 5);
	graph.addEdge(2, 6, 2);

	// 3
	graph.addEdge(3, 17, 1);

	// 4
	graph.addEdge(4, 5, 7);
	graph.addEdge(4, 7, 3);
	graph.addEdge(4, 8, 5);

	// 5
	graph.addEdge(5, 6, 8);
	graph.addEdge(5, 8, 1);
	graph.addEdge(5, 25, 6);

	// 6 All edges added

	// 7
	graph.addEdge(7, 11, 1);

	// 8
	graph.addEdge(8, 11, 8);
	graph.addEdge(8, 12, 7);

	// 9
	graph.addEdge(9, 10, 6);
	graph.addEdge(9, 12, 9);
	graph.addEdge(9, 13, 3);

	// 10
	graph.addEdge(10, 13, 5);
	graph.addEdge(10, 17, 2);
	graph.addEdge(10, 30, 4);

	// 11
	graph.addEdge(11, 12, 2);
	graph.addEdge(11, 14, 6);

	// 12
	graph.addEdge(12, 13, 2);
	graph.addEdge(12, 15, 8);
	graph.addEdge(12, 16, 6);

	// 13
	graph.addEdge(13, 17, 9);

	// 14 All edges added

	// 15
	graph.addEdge(15, 35, 7);

	// 16
	graph.addEdge(16, 17, 1);

	// 17 All edges added

	// 20
	graph.addEdge(20, 21, 1);
	graph.addEdge(20, 24, 3);
	graph.addEdge(20, 27, 5);
	graph.addEdge(20, 34, 1);

	// 21
	graph.addEdge(21, 24, 1);

	// 22
	graph.addEdge(22, 23, 8);
	graph.addEdge(22, 25, 1);
	graph.addEdge(22, 26, 8);

	// 23
	graph.addEdge(23, 26, 2);
	graph.addEdge(23, 37, 2);

	// 24
	graph.addEdge(24, 27, 2);
	graph.addEdge(24, 28, 6);

	// 25
	graph.addEdge(25, 26, 7);
	graph.addEdge(25, 28, 1);
	graph.addEdge(25, 29, 6);

	// 26
	graph.addEdge(26, 29, 9);
	graph.addEdge(26, 30, 5);

	// 27
	graph.addEdge(27, 28, 5);
	graph.addEdge(27, 34, 7);

	// 28
	graph.addEdge(28, 31, 5);
	graph.addEdge(28, 32, 1);

	// 29
	graph.addEdge(29, 30, 1);
	graph.addEdge(29, 33, 5);

	// 30
	graph.addEdge(30, 37, 4);

	// 31
	graph.addEdge(31, 32, 4);
	graph.addEdge(31, 34, 3);
	graph.addEdge(31, 35, 9);

	// 32
	graph.addEdge(32, 33, 4);
	graph.addEdge(32, 36, 1);

	// 33
	graph.addEdge(33, 36, 7);

	// 34 All edges added

	// 35
	graph.addEdge(35, 36, 4);
	graph.addEdge(35, 37, 1);

	// 36 All edges added

	// 37 All edges added

	return graph;
}

//Output
/*

Shortest Path for 1...

0 - Travel Weight: 8
Path: 1->0

1 - Travel Weight: 0
Path: 1

2 - Travel Weight: 16
Path: 1->0->2

3 - Travel Weight: 21
Path: 1->0->2->3

4 - Travel Weight: 14
Path: 1->5->8->4

5 - Travel Weight: 8
Path: 1->5

6 - Travel Weight: 16
Path: 1->5->6

7 - Travel Weight: 12
Path: 1->0->7

8 - Travel Weight: 9
Path: 1->5->8

9 - Travel Weight: 20
Path: 1->0->7->11->12->13->9

10 - Travel Weight: 22
Path: 1->0->7->11->12->13->10

11 - Travel Weight: 13
Path: 1->0->7->11

12 - Travel Weight: 15
Path: 1->0->7->11->12

13 - Travel Weight: 17
Path: 1->0->7->11->12->13

14 - Travel Weight: 12
Path: 1->0->14

15 - Travel Weight: 23
Path: 1->0->7->11->12->15

16 - Travel Weight: 21
Path: 1->0->7->11->12->16

17 - Travel Weight: 22
Path: 1->0->7->11->12->16->17

20 - Travel Weight: 16
Path: 1->0->20

21 - Travel Weight: 17
Path: 1->0->20->21

22 - Travel Weight: 15
Path: 1->5->25->22

23 - Travel Weight: 23
Path: 1->5->25->22->23

24 - Travel Weight: 18
Path: 1->0->20->21->24

25 - Travel Weight: 14
Path: 1->5->25

26 - Travel Weight: 21
Path: 1->5->25->26

27 - Travel Weight: 20
Path: 1->5->25->28->27

28 - Travel Weight: 15
Path: 1->5->25->28

29 - Travel Weight: 20
Path: 1->5->25->29

30 - Travel Weight: 21
Path: 1->5->25->29->30

31 - Travel Weight: 20
Path: 1->5->25->28->31

32 - Travel Weight: 16
Path: 1->5->25->28->32

33 - Travel Weight: 20
Path: 1->5->25->28->32->33

34 - Travel Weight: 17
Path: 1->0->20->34

35 - Travel Weight: 21
Path: 1->5->25->28->32->36->35

36 - Travel Weight: 17
Path: 1->5->25->28->32->36

37 - Travel Weight: 22
Path: 1->5->25->28->32->36->35->37

Shortest Path for 14...

0 - Travel Weight: 4
Path: 14->0

1 - Travel Weight: 12
Path: 14->0->1

2 - Travel Weight: 12
Path: 14->0->2

3 - Travel Weight: 16
Path: 14->11->12->16->17->3

4 - Travel Weight: 10
Path: 14->11->7->4

5 - Travel Weight: 15
Path: 14->11->8->5

6 - Travel Weight: 14
Path: 14->0->2->6

7 - Travel Weight: 7
Path: 14->11->7

8 - Travel Weight: 14
Path: 14->11->8

9 - Travel Weight: 13
Path: 14->11->12->13->9

10 - Travel Weight: 15
Path: 14->11->12->13->10

11 - Travel Weight: 6
Path: 14->11

12 - Travel Weight: 8
Path: 14->11->12

13 - Travel Weight: 10
Path: 14->11->12->13

14 - Travel Weight: 0
Path: 14

15 - Travel Weight: 16
Path: 14->11->12->15

16 - Travel Weight: 14
Path: 14->11->12->16

17 - Travel Weight: 15
Path: 14->11->12->16->17

20 - Travel Weight: 12
Path: 14->0->20

21 - Travel Weight: 13
Path: 14->0->20->21

22 - Travel Weight: 22
Path: 14->11->8->5->25->22

23 - Travel Weight: 25
Path: 14->11->12->13->10->30->37->23

24 - Travel Weight: 14
Path: 14->0->20->21->24

25 - Travel Weight: 21
Path: 14->11->8->5->25

26 - Travel Weight: 24
Path: 14->11->12->13->10->30->26

27 - Travel Weight: 16
Path: 14->0->20->21->24->27

28 - Travel Weight: 20
Path: 14->0->20->21->24->28

29 - Travel Weight: 20
Path: 14->11->12->13->10->30->29

30 - Travel Weight: 19
Path: 14->11->12->13->10->30

31 - Travel Weight: 16
Path: 14->0->20->34->31

32 - Travel Weight: 20
Path: 14->0->20->34->31->32

33 - Travel Weight: 24
Path: 14->0->20->34->31->32->33

34 - Travel Weight: 13
Path: 14->0->20->34

35 - Travel Weight: 23
Path: 14->11->12->15->35

36 - Travel Weight: 21
Path: 14->0->20->34->31->32->36

37 - Travel Weight: 23
Path: 14->11->12->13->10->30->37

Press any key to continue . . .

*/