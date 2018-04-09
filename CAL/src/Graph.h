/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <stdlib.h>
#include <vector>
#include <queue>
#include <list>
#include <limits>
#include <cmath>
#include "MutablePriorityQueue.h"

using namespace std;

template <class T> class Edge;
template <class T> class Graph;
template <class T> class Vertex;

#define INF std::numeric_limits<double>::max()

/************************* Vertex  **************************/

template <class T>
class Vertex {
	T info;                // contents
	vector<Edge<T> > adj;  // outgoing edges
	bool visited;          // auxiliary field
	long double x;		   // latitude
	long double y;         // longitude
	double dist = 0;
	Vertex<T> *path = NULL;
	int queueIndex = 0; 		// required by MutablePriorityQueue

	bool processing = false;
public:
	void addEdge(Vertex<T> *d, int idRua, string nomeRua, bool sentido);
	Vertex(T in);
	Vertex(T in, long double x, long double y);
	bool operator<(Vertex<T> & vertex) const; // // required by MutablePriorityQueue
	T getInfo() const;
	double getDist() const;
	Vertex *getPath() const;
	friend class Graph<T>;
	friend class MutablePriorityQueue<Vertex<T>>;

	bool removeEdgeTo(Vertex<T> *d);
	long double getX();
	long double getY();
	vector<Edge<T> > getAdj();

};

template <class T>
vector<Edge<T> > Vertex<T>::getAdj(){
	return this->adj;
}

template <class T>
long double Vertex<T>::getX(){
	return this->x;
}

template <class T>
long double Vertex<T>::getY(){
	return this->y;
}

template <class T>
Vertex<T>::Vertex(T in): info(in) {}

template <class T>
Vertex<T>::Vertex(T in, long double x, long double y): info(in) {
	this->x = x;
	this->y = y;
};


/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */
template <class T>
void Vertex<T>::addEdge(Vertex<T> *d, int idRua, string nomeRua, bool sentido ) {
	long double w = acos (sin(this->x)*sin(d->x)+cos(this->x)*cos(d->x)*cos(abs(this->y - d->y)));
	adj.push_back(Edge<T>(d, w, idRua, nomeRua, sentido));
}

template <class T>
bool Vertex<T>::operator<(Vertex<T> & vertex) const {
	return this->dist < vertex.dist;
}

template <class T>
T Vertex<T>::getInfo() const {
	return this->info;
}

template <class T>
double Vertex<T>::getDist() const {
	return this->dist;
}

template <class T>
Vertex<T> *Vertex<T>::getPath() const {
	return this->path;
}

/********************** Edge  ****************************/

template <class T>
class Edge {
	Vertex<T> * dest;      // destination vertex
	int idRua;
	string nomeRua;
	double weight;         // edge weight
	bool sentido;
public:
	Edge(Vertex<T> *d, double w);
	Edge(Vertex<T> *d, double w, int idRua, string nomeRua, bool sentido);
	friend class Graph<T>;
	friend class Vertex<T>;
	int getIdRua();
	bool getSentido();
	Vertex<T> *getDest();
	double getWeight();
};

template <class T>
Vertex<T> *Edge<T>::getDest(){
	return this->dest;
}

template <class T>
double Edge<T>::getWeight(){
	return this->weight;
}

template <class T>
bool Edge<T>::getSentido(){
	return this->sentido;
}

template <class T>
int Edge<T>::getIdRua(){
	return this->idRua;
}

template <class T>
Edge<T>::Edge(Vertex<T> *d, double w): dest(d), weight(w) {}

template <class T>
Edge<T>::Edge(Vertex<T> *d, double w, int idRua, string nomeRua, bool sentido): dest(d), weight(w) {
	this->idRua = idRua;
	this->nomeRua = nomeRua;
	this->sentido = sentido;
}


/*************************** Graph  **************************/

template <class T>
class Graph {
	vector<Vertex<T> *> vertexSet;    // vertex set

public:
	Graph();
	Vertex<T> *findVertex(const T &in) const;
	bool addVertex(const T &in);
	bool addVertex(const T &in, long double latitude, long double longitude);
	bool addEdge(const T &sourc, const T &dest, double w);
	int getNumVertex() const;
	vector<Vertex<T> *> getVertexSet() const;

	bool removeEdge(const T &sourc, const T &dest);
	bool removeVertex(const T &in);
	vector<T> dfs() const;
	void dfsVisit(Vertex<T> *v, vector<T> & res) const;
	vector<T> bfs(const T & source) const;
	vector<T> topsort() const;
	int maxNewChildren(const T & source, T &inf) const;
	bool isDAG() const;
	bool dfsIsDAG(Vertex<T> *v) const;

	Vertex<T> * initSingleSource(const T &origin);
	bool relax(Vertex<T> *v, Vertex<T> *w, double weight);

	void dijkstraShortestPath(const T &s);
	void dijkstraShortestPathOld(const T &s);
	void unweightedShortestPath(const T &s);
	void bellmanFordShortestPath(const T &s);
	vector<T> getPath(const T &origin, const T &dest) ;

	void floydWarshallShortestPath();
	vector<T> getfloydWarshallPath(const T &origin, const T &dest) const;

	vector<Vertex<T> *> getVertexSet();
	Edge<T> findEdge(const T &origin, const T &dest);
};

template <class T>
Graph<T>::Graph(){

}

template <class T>
Edge<T> Graph<T>::findEdge(const T &origin, const T &dest){

	for(int i = 0; i < this->findVertex(origin)->getAdj().size(); i++){
		if(this->findVertex(origin)->getAdj().at(i).getDest()->getInfo() == dest)
			return this->findVertex(origin)->getAdj().at(i);
	}
	return Edge<T>(NULL,0);
}


template <class T>
vector<Vertex<T> *> Graph<T>::getVertexSet(){
	return this->vertexSet;
}

template <class T>
int Graph<T>::getNumVertex() const {
	return vertexSet.size();
}

template <class T>
vector<Vertex<T> *> Graph<T>::getVertexSet() const {
	return vertexSet;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
template <class T>
Vertex<T> * Graph<T>::findVertex(const T &in) const {
	if(!vertexSet.empty())
	for (auto v : vertexSet)
		if (v->info == in)
			return v;
	return NULL;
}

/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
template <class T>
bool Graph<T>::addVertex(const T &in) {
	if ( findVertex(in) != NULL)
		return false;
	vertexSet.push_back(new Vertex<T>(in));
	return true;
}

template <class T>
bool Graph<T>::addVertex(const T &in, long double latitude, long double longitude) {
	if ( findVertex(in) != NULL)
		return false;
	vertexSet.push_back(new Vertex<T>(in, latitude, longitude));
	return true;
}

/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
template <class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, double w) {
	auto v1 = findVertex(sourc);
	auto v2 = findVertex(dest);
	if (v1 == NULL || v2 == NULL)
		return false;
	v1->addEdge(v2,w);
	return true;
}

template <class T>
bool Graph<T>::removeEdge(const T &sourc, const T &dest) {
	auto v1 = findVertex(sourc);
	auto v2 = findVertex(dest);
	if (v1 == NULL || v2 == NULL)
		return false;
	return v1->removeEdgeTo(v2);
}

template <class T>
bool Vertex<T>::removeEdgeTo(Vertex<T> *d) {
	for (auto it = adj.begin(); it != adj.end(); it++)
		if (it->dest  == d) {
			adj.erase(it);
			return true;
		}
	return false;
}

template <class T>
bool Graph<T>::removeVertex(const T &in) {
	for (auto it = vertexSet.begin(); it != vertexSet.end(); it++)
		if ((*it)->info  == in) {
			auto v = *it;
			vertexSet.erase(it);
			for (auto u : vertexSet)
				u->removeEdgeTo(v);
			delete v;
			return true;
		}
	return false;
}

/*
 * Performs a depth-first search (dfs) in a graph (this).
 * Returns a vector with the contents of the vertices by dfs order.
 * Follows the algorithm described in theoretical classes.
 */
template <class T>
vector<T> Graph<T>::dfs() const {
	vector<T> res;
	for (auto v : vertexSet)
		v->visited = false;
	for (auto v : vertexSet)
	    if (! v->visited)
	    	dfsVisit(v, res);
	return res;
}

/*
 * Auxiliary function that visits a vertex (v) and its adjacent, recursively.
 * Updates a parameter with the list of visited node contents.
 */
template <class T>
void Graph<T>::dfsVisit(Vertex<T> *v, vector<T> & res) const {
	v->visited = true;
	res.push_back(v->info);
	for (auto & e : v->adj) {
		auto w = e.dest;
	    if ( ! w->visited)
	    	dfsVisit(w, res);
	}
}


/*
 * Performs a breadth-first search (bfs) in a graph (this), starting
 * from the vertex with the given source contents (source).
 * Returns a vector with the contents of the vertices by dfs order.
 * Follows the algorithm described in theoretical classes.
 */
template <class T>
vector<T> Graph<T>::bfs(const T & source) const {
	vector<T> res;
	auto s = findVertex(source);
	if (s == NULL)
		return res;
	queue<Vertex<T> *> q;
	for (auto v : vertexSet)
		v->visited = false;
	q.push(s);
	s->visited = true;
	while (!q.empty()) {
		auto v = q.front();
		q.pop();
		res.push_back(v->info);
		for (auto & e : v->adj) {
			auto w = e.dest;
		    if ( ! w->visited ) {
				q.push(w);
				w->visited = true;
		    }
		}
	}
	return res;
}


/*
 * Performs a topological sorting of the vertices of a graph (this).
 * Returns a vector with the contents of the vertices by topological order.
 * If the graph has cycles, returns an empty vector.
 * Follows the algorithm described in theoretical classes.
 */

template<class T>
vector<T> Graph<T>::topsort() const {
	vector<T> res;

	for (auto v : vertexSet)
		v->indegree = 0;
	for (auto v : vertexSet)
		for (auto & e : v->adj)
			e.dest->indegree++;

	queue<Vertex<T>*> q;
	for (auto v : vertexSet)
		if (v->indegree == 0)
			q.push(v);

	while( !q.empty() ) {
		Vertex<T>* v = q.front();
		q.pop();
		res.push_back(v->info);
		for(auto & e : v->adj) {
			auto w = e.dest;
			w->indegree--;
			if(w->indegree == 0)
				q.push(w);
		}
	}

	if ( res.size() != vertexSet.size() ) {
		res.clear();
		return res;
	}

	return res;
}


/*
 * Performs a breadth-first search in a graph (this), starting
 * from the vertex with the given source contents (source).
 * During the search, determines the vertex that has a maximum number
 * of new children (adjacent not previously visited), and returns the
 * contents of that vertex and the number of new children.
 */

template <class T>
int Graph<T>::maxNewChildren(const T & source, T &inf) const {
	auto s = findVertex(source);
	if (s == NULL)
			return 0;
	queue<Vertex<T> *> q;
	int maxChildren = 0;
	inf = s->info;
	for (auto v : vertexSet)
		v->visited = false;
	q.push(s);
	s->visited = true;
	while (!q.empty()) {
		auto v = q.front();
		q.pop();
		int nChildren=0;
		for (auto & e : v->adj) {
			auto w = e.dest;
			if ( ! w->visited ) {
				w->visited = true;
				q.push(w);
				nChildren++;
			}
		}
		if (nChildren>maxChildren) {
			maxChildren = nChildren;
			inf = v->info;
		}
	}
	return maxChildren;
}


/*
 * Performs a depth-first search in a graph (this), to determine if the graph
 * is acyclic (acyclic directed graph or DAG).
 * During the search, a cycle is found if an edge connects to a vertex
 * that is being processed in the the stack of recursive calls (see theoretical classes).
 * Returns true if the graph is acyclic, and false otherwise.
 */

template <class T>
bool Graph<T>::isDAG() const {
	for (auto v : vertexSet) {
		v->visited = false;
		v->processing = false;
	}
	for (auto v : vertexSet)
	    if (! v->visited)
	    	if ( ! dfsIsDAG(v) )
	    		return false;
	return true;
}

/**
 * Auxiliary function that visits a vertex (v) and its adjacent, recursively.
 * Returns false (not acyclic) if an edge to a vertex in the stack is found.
 */
template <class T>
bool Graph<T>::dfsIsDAG(Vertex<T> *v) const {
	v->visited = true;
	v->processing = true;
	for (auto & e : v->adj) {
		auto w = e.dest;
    	if (w->processing)
    		return false;
	    if (! w->visited)
	    	if (! dfsIsDAG(w))
	    		return false;
	}
	v->processing = false;
	return true;
}

/**************** Single Source Shortest Path algorithms ************/

template<class T>
Vertex<T> * Graph<T>::initSingleSource(const T &origin) {
	for (auto v : vertexSet) {
		v->dist = INF;
		v->path = nullptr;

	}
	auto s = findVertex(origin);
	s->dist = 0;
	return s;
}

template<class T>
bool Graph<T>::relax(Vertex<T> *v, Vertex<T> *w, double weight) {
	if (v->dist + weight < w->dist) {
		w->dist = v->dist + weight;
		w->path = v;
		return true;
	} else
		return false;
}

template<class T>
void Graph<T>::dijkstraShortestPath(const T &origin) {
	auto s = initSingleSource(origin);
	MutablePriorityQueue<Vertex<T>> q;
	q.insert(s);
	while (!q.empty()) {
		auto v = q.extractMin();
		for (auto e : v->adj) {
			auto oldDist = e.dest->dist;
			if (relax(v, e.dest, e.weight)) {
				if (oldDist == INF)
				q.insert(e.dest);
				else
				q.decreaseKey(e.dest);
			}
		}
	}
}

template<class T>
vector<T> Graph<T>::getPath(const T &origin, const T &dest)  {
	dijkstraShortestPath(origin);
	vector<T> res;
	auto v = findVertex(dest);
	if (v == nullptr || v->dist == INF) // missing or disconnected
	return res;
	for (; v != nullptr; v = v->path)
		res.push_back(v->info);
	//res.reverse(res.begin(), res.end());
	return res;
}

template<class T>
void Graph<T>::unweightedShortestPath(const T &orig) {
	// TODO
}

template<class T>
void Graph<T>::bellmanFordShortestPath(const T &orig) {
	// TODO
}


/**************** All Pairs Shortest Path  ***************/

template<class T>
void Graph<T>::floydWarshallShortestPath() {
	// TODO
}

template<class T>
vector<T> Graph<T>::getfloydWarshallPath(const T &orig, const T &dest) const{
	vector<T> res;
	// TODO
	return res;
}


#endif /* GRAPH_H_ */
