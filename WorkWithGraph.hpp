#ifndef WORK_WITH_GRAPH
#define WORK_WITH_GRAPH
#include "Graph/Graph.hpp"
#include "HelpFunctions.hpp"
#include "FileLogging/FileLogging.hpp"
#include "Menu/Menu.hpp"

inline void mPrintGraph(Menu::vany params)
{
    auto graph = std::any_cast<Graph*>(params[0]);
    auto foutlog = std::any_cast<FileLogging>(params[2]);
    auto ferrlog = std::any_cast<FileLogging>(params[3]);
    foutlog.Logging(concat("Function call: ", __func__));
    if (graph->getVertexCount() == 0)
    {
        std::cout << "Граф пустой!\n";
        ferrlog.Logging("Attempt to display an empty graph");
        return;
    }
    graph->PrintGraph();
    foutlog.Logging(concat("\n", vvtos(graph->getWeightMatrix())));
}

inline void mGraphIsEmpty(Menu::vany params)
{
    auto graph = std::any_cast<Graph*>(params[0]);
    auto foutlog = std::any_cast<FileLogging>(params[2]);
    foutlog.Logging(concat("Function call: ", __func__));
    std::cout << "Граф пуст: " << (graph->getVertexCount() == 0 ? "да" : "нет") << "\n";
    foutlog.Logging(concat("\n", vvtos(graph->getWeightMatrix())));
}

inline void mInsertVertex(Menu::vany params)
{
    auto graph = std::any_cast<Graph*>(params[0]);
    auto foutlog = std::any_cast<FileLogging>(params[2]);
    auto ferrlog = std::any_cast<FileLogging>(params[3]);
    foutlog.Logging(concat("Function call: ", __func__));
    if (graph->getVertexCount() == INT_MAX)
    {
        std::cout << "Граф слишком большой!\n";
        ferrlog.Logging("Attempt to add a vertex to a very large graph");
    }
    graph->InsertVertex();
    std::cout << "Вершина успешно добавлена!";
    foutlog.Logging(concat("\n", vvtos(graph->getWeightMatrix())));
}

inline void mDeleteVertex(Menu::vany params)
{
    auto graph = std::any_cast<Graph*>(params[0]);
    auto foutlog = std::any_cast<FileLogging>(params[2]);
    auto ferrlog = std::any_cast<FileLogging>(params[3]);
    foutlog.Logging(concat("Function call: ", __func__));
    if (graph->getVertexCount() == 0)
    {
        std::cout << "Граф пустой!\n";
        ferrlog.Logging("Attempt to remove a vertex from an empty graph");
        return;
    }
    int v = InputInt("Введите номер вершины, которую необходимо удалить: ", 0, graph->getVertexCount() - 1, &ferrlog);
    graph->DeleteVertex(v);
    std::cout << "Вершина " << v << " успешно удалена!\n";
    foutlog.Logging(concat("\n", vvtos(graph->getWeightMatrix())));
}

inline void mCreateEdge(Menu::vany params)
{
    auto graph = std::any_cast<Graph*>(params[0]);
    auto foutlog = std::any_cast<FileLogging>(params[2]);
    auto ferrlog = std::any_cast<FileLogging>(params[3]);
    foutlog.Logging(concat("Function call: ", __func__));
    if (graph->getVertexCount() == 0)
    {
        std::cout << "Граф пустой!\n";
        ferrlog.Logging("Attempt to create an edge in an empty graph");
        return;
    }
    int v1 = InputInt("Введите номер первой вершины: ", 0, graph->getVertexCount() - 1, &ferrlog);
    int v2 = InputInt("Введите номер второй вершины: ", 0, graph->getVertexCount() - 1, &ferrlog);
    int w = InputInt("Введите вес ребра: ", INT_MIN, INT_MAX, &ferrlog);
    graph->CreateEdge(v1, v2, w);
    std::cout << "Ребро (" << v1 << ", " << v2 << ") успешно добавлено!\n";
    foutlog.Logging(concat("\n", vvtos(graph->getWeightMatrix())));
}

inline void mCreateArc(Menu::vany params)
{
    auto graph = std::any_cast<Graph*>(params[0]);
    auto foutlog = std::any_cast<FileLogging>(params[2]);
    auto ferrlog = std::any_cast<FileLogging>(params[3]);
    foutlog.Logging(concat("Function call: ", __func__));
    if (graph->getVertexCount() == 0)
    {
        std::cout << "Граф пустой!\n";
        ferrlog.Logging("Attempt to create an arc in an empty graph");
        return;
    }
    int v1 = InputInt("Введите номер первой вершины: ", 0, graph->getVertexCount() - 1, &ferrlog);
    int v2 = InputInt("Введите номер второй вершины: ", 0, graph->getVertexCount() - 1, &ferrlog);
    int w = InputInt("Введите вес ребра: ", INT_MIN, INT_MAX, &ferrlog);
    graph->CreateArc(v1, v2, w);
    std::cout << "Дуга (" << v1 << ", " << v2 << ") успешно добавлено!\n";
    foutlog.Logging(concat("\n", vvtos(graph->getWeightMatrix())));
}

inline void mDeleteEdge(Menu::vany params)
{
    auto graph = std::any_cast<Graph*>(params[0]);
    auto foutlog = std::any_cast<FileLogging>(params[2]);
    auto ferrlog = std::any_cast<FileLogging>(params[3]);
    foutlog.Logging(concat("Function call: ", __func__));
    if (graph->getVertexCount() == 0)
    {
        std::cout << "Граф пустой!\n";
        ferrlog.Logging("Attempt to remove an edge from an empty graph");
        return;
    }
    int v1 = InputInt("Введите номер первой вершины: ", 0, graph->getVertexCount() - 1, &ferrlog);
    int v2 = InputInt("Введите номер второй вершины: ", 0, graph->getVertexCount() - 1, &ferrlog);
    graph->DeleteEdge(v1, v2);
    std::cout << "Ребро (" << v1 << ", " << v2 << ") успешно удалено!\n";
    foutlog.Logging(concat("\n", vvtos(graph->getWeightMatrix())));
}

inline void mDeleteArc(Menu::vany params)
{
    auto graph = std::any_cast<Graph*>(params[0]);
    auto foutlog = std::any_cast<FileLogging>(params[2]);
    auto ferrlog = std::any_cast<FileLogging>(params[3]);
    foutlog.Logging(concat("Function call: ", __func__));
    if (graph->getVertexCount() == 0)
    {
        std::cout << "Граф пустой!\n";
        ferrlog.Logging("Attempt to remove an arc from an empty graph");
        return;
    }
    int v1 = InputInt("Введите номер первой вершины: ", 0, graph->getVertexCount() - 1, &ferrlog);
    int v2 = InputInt("Введите номер второй вершины: ", 0, graph->getVertexCount() - 1, &ferrlog);
    graph->DeleteArc(v1, v2);
    std::cout << "Дуга (" << v1 << ", " << v2 << ") успешно удалено!\n";
    foutlog.Logging(concat("\n", vvtos(graph->getWeightMatrix())));
}

inline void mFillRandomly(Menu::vany params)
{
    auto graph = std::any_cast<Graph*>(params[0]);
    auto foutlog = std::any_cast<FileLogging>(params[2]);
    auto ferrlog = std::any_cast<FileLogging>(params[3]);
    foutlog.Logging(concat("Function call: ", __func__));
    if (graph->getVertexCount() == 0)
    {
        std::cout << "Граф пустой!\n";
        ferrlog.Logging("Attempt to fill an empty graph with random numbers");
        return;
    }
    int minw = InputInt("Введите минимальный вес: ", INT_MIN, INT_MAX, &ferrlog);
    int maxw = InputInt("Введите максимальный вес: ", INT_MIN, INT_MAX, &ferrlog);
    graph->FillRandomly(minw, maxw);
    std::cout << "Матрица весов заполнена случайными числами!\n";
    foutlog.Logging(concat("\n", vvtos(graph->getWeightMatrix())));
}

inline void mBreadthFirstSearch(Menu::vany params)
{
    auto graph = std::any_cast<Graph*>(params[0]);
    auto foutlog = std::any_cast<FileLogging>(params[2]);
    auto ferrlog = std::any_cast<FileLogging>(params[3]);
    foutlog.Logging(concat("Function call: ", __func__));
    if (graph->getVertexCount() == 0)
    {
        std::cout << "Граф пустой!\n";
        ferrlog.Logging("Attempt to apply a BFS in an empty graph");
        return;
    }
    int v = InputInt("Введите номер вершины, с которой надо начинать обход: ", 0, graph->getVertexCount() - 1, &ferrlog);
    std::cout << graph->BreadthFirstSearch(v) << "\n";
    foutlog.Logging(concat("\n", vvtos(graph->getWeightMatrix())));
}

inline void mDepthFirstSearch(Menu::vany params)
{
    auto graph = std::any_cast<Graph*>(params[0]);
    auto foutlog = std::any_cast<FileLogging>(params[2]);
    auto ferrlog = std::any_cast<FileLogging>(params[3]);
    foutlog.Logging(concat("Function call: ", __func__));
    if (graph->getVertexCount() == 0)
    {
        std::cout << "Граф пустой!\n";
        ferrlog.Logging("Attempt to apply a DFS in an empty graph");
        return;
    }
    int v = InputInt("Введите номер вершины, с которой надо начинать обход: ", 0, graph->getVertexCount() - 1, &ferrlog);
    std::cout << graph->DepthFirstSearch(v) << "\n";
    foutlog.Logging(concat("\n", vvtos(graph->getWeightMatrix())));
}

inline void mClearGraph(Menu::vany params)
{
    auto graph = std::any_cast<Graph*>(params[0]);
    auto foutlog = std::any_cast<FileLogging>(params[2]);
    auto ferrlog = std::any_cast<FileLogging>(params[3]);
    foutlog.Logging(concat("Function call: ", __func__));
    if (graph->getVertexCount() == 0)
    {
        std::cout << "Граф пустой!\n";
        ferrlog.Logging("Attempt to clear an empty graph");
        return;
    }
    graph->ClearGraph();
    std::cout << "Теперь граф пуст!\n";
    foutlog.Logging(concat("\n", vvtos(graph->getWeightMatrix())));
}

inline void mDijkstra(Menu::vany params)
{
    auto graph = std::any_cast<Graph*>(params[0]);
    auto foutlog = std::any_cast<FileLogging>(params[2]);
    auto ferrlog = std::any_cast<FileLogging>(params[3]);
    foutlog.Logging(concat("Function call: ", __func__));
    if (graph->getVertexCount() == 0)
    {
        std::cout << "Граф пустой!\n";
        ferrlog.Logging("attempt to apply Dijkstra's algorithm to an empty graph");
        return;
    }
    int v = InputInt("Введите начальную вершину: ", 0, graph->getVertexCount() - 1, &ferrlog);
    auto dijksta = graph->Dijkstra(v);
    for (size_t i = 0; i < dijksta.first.size(); i++)
    {
        if (v != int(i))
        {
            std::cout << "Путь " << v << "->" << i << ": " << dijksta.second[i] << " Длина пути: " << dijksta.first[i] << "\n";
        }
    }
    foutlog.Logging(concat("\n", vvtos(graph->getWeightMatrix())));
}

inline void mHamiltonianPath(Menu::vany params)
{
    auto graph = std::any_cast<Graph*>(params[0]);
    auto foutlog = std::any_cast<FileLogging>(params[2]);
    auto ferrlog = std::any_cast<FileLogging>(params[3]);
    foutlog.Logging(concat("Function call: ", __func__));
    if (graph->getVertexCount() == 0)
    {
        std::cout << "Граф пустой!\n";
        ferrlog.Logging("Attempt to find Hamiltonian paths in an empty graph");
        return;
    }
    auto hps = graph->HamiltonianPath();
    std::cout << "Гамильтоновы пути:\n";
    for (auto i : hps)
    {
        std::cout << i << "\n";
    }
    foutlog.Logging(concat("\n", vvtos(graph->getWeightMatrix())));
}

inline void mReadGraphFromFile(Menu::vany params)
{
    auto graph = std::any_cast<Graph*>(params[0]);
    auto finpdata = std::any_cast<std::string>(params[1]);
    auto foutlog = std::any_cast<FileLogging>(params[2]);
    auto ferrlog = std::any_cast<FileLogging>(params[3]);
    foutlog.Logging(concat("Function call: ", __func__));
    std::fstream fin(finpdata, std::ios::in);
    Graph::WeightMatrix weightMatrix;
    std::vector<double> buffer;
    if (fin.is_open())
    {
        std::string data;
        while (fin >> data)
        {
            buffer.push_back(data == "inf" ? inf() : std::stoi(data));
        }
        int wmsize = std::sqrt(buffer.size());
        if (wmsize * wmsize == buffer.size())
        {
            for (int i = 0; i < wmsize; i++)
            {
                std::vector<double> v;
                for (int j = 0; j < wmsize; j++)
                {
                    v.push_back(buffer[i * wmsize + j]);
                }
                weightMatrix.push_back(v);
            }
            Graph newGraph(weightMatrix);
            *graph = newGraph;
            std::cout << "Граф успешно считан из файла " << finpdata << "!\n";
        }
        else
        {
            std::cout << "Матрица весов в файле не квадратная!\n";
            ferrlog.Logging("Weight matrix is not square");
        }
    }
    else
    {
        std::cout << "Ошибка при открытии файла!\n";
        ferrlog.Logging("Error opening file");
    }
    foutlog.Logging(concat("\n", vvtos(graph->getWeightMatrix())));
}
#endif