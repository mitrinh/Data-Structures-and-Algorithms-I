// Michael Trinh
#include <iostream>
using namespace std;

class matrix
{
private:
	int inf = 9999; // value of "infinity"
	int adjMatrix[6][6];
	int weight[6];
public:
	matrix(); // initialize values in adjacency matrix via constructor
	~matrix(); // destructor
	bool shortestPath(); // dijkstra's algorithm
};

matrix::matrix()
{
    // initialize adjacency matrix
	adjMatrix[0][1] = 120;
	adjMatrix[0][2] = 150;
	adjMatrix[0][5] = 500;
	adjMatrix[1][3] = 75;
	adjMatrix[1][5] = 350;
	adjMatrix[2][4] = 250;
	adjMatrix[3][4] = 150;
	for (int i = 0; i < 6; i++) {
		adjMatrix[i][i] = 0;
		for (int j = 0; j < 6; j++) {				
			if (adjMatrix[i][j] < 0) // makes every empty value in array infinity
				adjMatrix[i][j] = inf;
			adjMatrix[j][i] = adjMatrix[i][j]; // reverse values are the same as their original values
		}
	}
	// print out adjacency array
	cout << "Adjacency Matrix:" << endl; 
	cout << "x\\y " << '\t' << '0' << '\t' << '1' << '\t' << '2' << '\t' << '3' << '\t' << '4' << '\t' << '5' << '\t' << endl; // '\t' = tab
	for (int k = 0; k < 6; k++) {
		cout << k << '\t';
		for (int m = 0; m < 6; m++) {
			cout << adjMatrix[k][m] << '\t'; 
		}
		cout << endl;
	}
}

matrix::~matrix() {
}

bool matrix::shortestPath()
{
	int n = 6; // number of vertices in matrix
	int count = 0; // tracks how many vertices are in vertexSet
	// Step 1: Initialize
	int vertexset[6];
	vertexset[0] = 0;
	count++;
	for (int v = 0; v < n; v++) { // initializes all edges around starting point
		weight[v] = adjMatrix[0][v]; // weight[2] = adjMatrix[0][2] = 9999 = infinity
	}
	// Steps 2-n:
	for (int step = 1; step < n; step++) {
		int v = 0; // use v again and set it to starting point
		for (int w = 0; w < n; w++) { // Find smallest weight[v] such that v is not in vertexSet
				for (int i = 0; i < n; i++) { // skips any vertices in vertexSet
					if (vertexset[i] == w) {
						w++;
					}
				}
			if (weight[v] == 0){ // initialize v to next available vertex 
				v = w;
			}
			else if (weight[v] > weight[w]) // Directs v to the lowest weighted path
				v = w;
		}
		vertexset[count] = v; // add v to vertexSet
		count++;
		// Check weight[u] for all u not in vertexSet
		for (int u = 0; u < n; u++) { // for (all vertices u not in vertexSet)
				for (int j = 0; j < n; j++) { // skips any vertices in vertexSet
					if (vertexset[j] == u) {
						u++;
					}
				}
			if (weight[u] > (weight[v] + adjMatrix[v][u])) { // if any of the edges of v have cheaper path 
											        	     // to that vertex than any older paths to that vertex,
														     // update the cost to that path with the cheaper path
				weight[u] = (weight[v] + adjMatrix[v][u]);
			}
		}
	}
	// print cost of shortest path to each location
	for (int k = 0; k < n; k++)
	{
		cout << "Cheapest cost from San Francisco to " << k << " is " << weight[k] << "." << endl;
	}
	return true;
}

int main()
{
	matrix CSAir;
	CSAir.shortestPath();
	//system("pause");
    return 0;
}

