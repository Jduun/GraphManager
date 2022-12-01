#ifndef HELP_FUNCTIONS
#define HELP_FUNCTIONS
#include <random>
#include <ctime>
#include <climits>
#include <algorithm>
#include <vector>
#include <iostream>
#include <exception>
#include <iterator>
#include <sstream>
#include "FileLogging/FileLogging.hpp"

inline int getRandom(const int _min, const int _max)
{
    return rand() % (_max - _min + 1) + _min; 
}

inline double inf()
{
	return std::numeric_limits<double>::infinity();
}

inline double getMatrixMaximum(const std::vector<std::vector<double>>& matrix)
{
    double _max = -inf();
    for (auto i : matrix)
    {
        _max = std::max(*std::max_element(i.begin(), i.end()), _max);
    }
    return _max;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v)
{
    out << "[";
    for (size_t i = 0; i < v.size(); i++)
    {
        out << v[i] << (i == v.size() - 1 ? "" : ", ");
    }
    out << "]";
    return out;
}

// std::vector<T> -> std::string
template <typename T>
inline std::string vtos(std::vector<T>& v)
{
    std::stringstream ss;
    ss << v;
    return ss.str();
}

// std::vector<std::vector<T>> -> std::string
template <typename T>
inline std::string vvtos(std::vector<std::vector<T>>& vv)
{
    std::stringstream ss;
    for (auto v : vv)
    {
        ss << v << "\n";
    }
    return ss.str();
}


inline int InputInt(const std::string MSG, const int MIN, const int MAX)
{
    int input{};
    bool exit = false;
    while (!exit)
    {
        std::cout << MSG;
        std::string strInput;
        getline(std::cin, strInput);
        try
        {
            // проверяем strInput на наличие лишних символов(не цифры)
            // и выбрасываем исключение std::invalid_argument,
            // иначе можно ввести такие strInput, что они начинаются с цифр
            // и заканчиваются другими символами (например, "34ffsd", "124ad")
            for (size_t i = 0; i < strInput.length(); i++)
            {
                if (strInput[i] == '-' && i == 0)
                {
                    continue;
                }
                if (strInput[i] < '0' || strInput[i] > '9')
                {
                    throw std::invalid_argument("You can enter integer numbers only.");
                }
            }
            input = std::stoi(strInput);
            exit = true;
        }
        catch(std::invalid_argument const&)
        {
            std::cout << "Можно ввести только целое число!\n";
        }
        catch(std::out_of_range const&)
        {
            std::cout << "Введенное число выходит из допустимого диапазона!\n";
        }
        catch(...)
        {
            std::cout << "Неизвестная ошибка при вводе!\n";
        }
        if (exit && (input < MIN || input > MAX))
        {
            std::cout << "Введенное число выходит из допустимого диапазона!\n";
            exit = false;
        }
    }
    return input;
}


inline int InputInt(const std::string MSG, const int MIN, const int MAX, FileLogging* flog)
{
    int input{};
    bool exit = false;
    while (!exit)
    {
        std::cout << MSG;
        std::string strInput;
        getline(std::cin, strInput);
        try
        {
            // проверяем strInput на наличие лишних символов(не цифры)
            // и выбрасываем исключение std::invalid_argument,
            // иначе можно ввести такие strInput, что они начинаются с цифр
            // и заканчиваются другими символами (например, "34ffsd", "124ad")
            for (size_t i = 0; i < strInput.length(); i++)
            {
                if (strInput[i] == '-' && i == 0)
                {
                    continue;
                }
                if (strInput[i] < '0' || strInput[i] > '9')
                {
                    throw std::invalid_argument("You can enter integer numbers only.");
                    if (flog)
                    {
                        flog->Logging("Incorrect number entry");
                    }
                }
            }
            input = std::stoi(strInput);
            exit = true;
        }
        catch(std::invalid_argument const&)
        {
            std::cout << "Можно ввести только целое число!\n";
            if (flog)
            {
                flog->Logging("Incorrect number entry");
            }
        }
        catch(std::out_of_range const&)
        {
            std::cout << "Введенное число выходит из допустимого диапазона!\n";
            if (flog)
            {
                flog->Logging("The entered number out of range");
            }
        }
        catch(...)
        {
            std::cout << "Неизвестная ошибка при вводе!\n";
            if (flog)
            {
                flog->Logging("Unknown input error");
            }
        }
        if (exit && (input < MIN || input > MAX))
        {
            std::cout << "Введенное число выходит из допустимого диапазона!\n";
            exit = false;
            if (flog)
            {
                flog->Logging("The entered number out of range");
            }
        }
    }
    return input;
}

inline std::string concat(std::string s1, std::string s2)
{
    std::stringstream ss;
    ss << s1 << s2; 
    return ss.str();
}
#endif