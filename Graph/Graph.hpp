#ifndef GRAPH
#define GRAPH
#include <vector>

#include <iostream>
#include <exception>
#include <stack>
#include <queue>
#include <iomanip>
#include <sstream>
#include "../HelpFunctions.hpp"

class Graph
{
public:
	// Матрица весов
	using WeightMatrix = std::vector<std::vector<double>>;

	Graph(const Graph& graph);
	Graph(const WeightMatrix& weightMatrix);
	Graph(const size_t n);

	WeightMatrix& getWeightMatrix();
	void ClearGraph();
	void FillRandomly(const int MIN_WEIGHT = 1, const int MAX_WEIGTH = 1);
	size_t getVertexCount() const;
	void InsertVertex();
	void DeleteVertex(const size_t i);
	// Создать дугу
	void CreateArc(const size_t i, const size_t j, const double WEIGHT = 1);
	// Создать ребро
	void CreateEdge(const size_t i, const size_t j, const double WEIGHT = 1);
	// Удалить дугу
	void DeleteArc(const size_t i, const size_t j);
	// Удалить ребро
	void DeleteEdge(const size_t i, const size_t j);
	// Вывод матрицы весов с точностью весов PRECISION
	void PrintGraph(const size_t PRECISION = 0) const;

	// Обход в глубину, начиная с вершины i (вовзращает путь)
	std::vector<size_t> DepthFirstSearch(size_t i = 0) const;
	// Поиск в глубину, начиная с вершины i (возвращает путь)
	std::vector<size_t> BreadthFirstSearch(size_t i = 0) const;
	// Алгоритм Дейкстры, возвращающий пару векторов: вектор кратчайших путей (веса) и вектор путей
	std::pair<std::vector<double>, std::vector<std::vector<size_t>>> Dijkstra(const size_t STARTING_VERTEX = 0) const;
	// Возвращает вектор гамильтоновых путей графа - простых путей (т.е. без петель), проходящих через каждую
	// вершину графа только один раз
	std::vector<std::vector<size_t>> HamiltonianPath() const;
	// Возвращает максимальный поток из истока s в сток t
	int FordFulkerson(const int s, const int t) const;
	
private:
	WeightMatrix weightMatrix{};
	// Существует ли связь между вершинами i и j
	bool ExistLink(const size_t i, const size_t j) const;
	//bool BFSforFordFulkerson(int s, int t, int path[]) const;
	int FordFulkerson(const int s, const int t, std::vector<std::vector<int>>& graph) const;
	int BFSforFordFulkerson(const int s, const int t, std::vector<int>& parent, std::vector<std::vector<int>>& graph) const;
};
#endif