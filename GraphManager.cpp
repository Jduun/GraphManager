#include <iostream>
#include "WorkWithGraph.hpp"

int main(int argc, char* argv[])
{
    std::string file_input_data = "input_data.txt";
    std::string file_output_log = "output_log.txt";
    std::string file_error_log = "error_log.txt";
    if (argc >= 3)
    {
        file_input_data = argv[1];
        file_output_log = argv[2];
        file_error_log = argv[3];
    }
    FileLogging error_log(file_error_log);
    FileLogging output_log(file_output_log);

    Graph::WeightMatrix weightMatrix{};
    Graph* graph = new Graph(weightMatrix);
    Menu::vany params { graph, file_input_data, output_log, error_log };
    Menu menu = Menu("Главное", std::vector<Menu>
    {
        Menu("Вывести граф (матрицу весов)", mPrintGraph),
        Menu("Операции над графом", std::vector<Menu>
        {    
            Menu("Заполнить матрицу весов случайными числами", mFillRandomly),
            Menu("Очистить граф", mClearGraph),
            Menu("Проверка графа на пустоту", mGraphIsEmpty),
            Menu("Добавить вершину в граф", mInsertVertex),
            Menu("Удалить вершину из графа", mDeleteVertex),
            Menu("Создать ребро в графе", mCreateEdge),
            Menu("Создать дугу в графе", mCreateArc),
            Menu("Удалить ребро из графа", mDeleteEdge),
            Menu("Удалить дугу из графа", mDeleteArc)
        }),
        Menu("Алгоритмы на графе", std::vector<Menu>
        {
            Menu("Обход графа", std::vector<Menu>
            {
                Menu("Обход в ширину", mBreadthFirstSearch),
                Menu("Обход в глубину", mDepthFirstSearch)
            }),
            Menu("Поиск гамильтоновых путей", mHamiltonianPath),
            Menu("Поиск кратчайшего пути Алгоритмом Дейкстры", mDijkstra),
            Menu("Поиск максимального потока на основе поиска в ширину", mFordFulkerson)
        }),
        Menu("Считать граф из файла ", mReadGraphFromFile)
    }, params);
    menu.run();

    delete graph;
    return 0;
}