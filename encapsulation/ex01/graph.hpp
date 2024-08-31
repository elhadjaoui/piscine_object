#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include "Vector2.hpp"

class Graph
{

private:
    Vector2 size;
    std::vector<Vector2 *> points;

public:
    Graph(Vector2 size): size(size) {}
    void add_point(Vector2* point) {
        if (point->x >= 0 && point->x < size.x && point->y >= 0 && point->y < size.y) {
            points.push_back(point);
        } 
        else 
            std::cout << "Point " << point << " is out of bounds and will not be added.\n";
    }

/*

    friend std::ostream& operator<<(std::ostream& os, const Graph& graph) {
        for (int i = static_cast<int>(graph.size.getY()); i >= 0; --i) {
            os << i << " ";
            for (int j = 0; j <= static_cast<int>(graph.size.getX()); ++j) {
                bool is_point = false;
                for (std::vector<Vector2 *>::const_iterator it = graph.points.begin(); it != graph.points.end(); ++it) {
                    if (static_cast<int>((*it)->getX()) == j && static_cast<int>((*it)->getY()) == i) {
                        is_point = true;
                        break;
                    }
                }
                os << (is_point ? "X " : ". ");
            }
            os << std::endl;
        }
        os << "  ";
        for (int j = 0; j <= static_cast<int>(graph.size.getX()); ++j) {
            os << j << " ";
        }
        os << std::endl;
        return os;
    }
*/
    friend std::ostream &operator<<(std::ostream &p_os, const Graph &p_graph)
    {
       for (int i = p_graph.size.getY() + 1; i >= 0 ; i--)
         {
            p_os << i;
              for (int j = 0; j <= p_graph.size.getX() + 1; j++)
              {
                for (std::vector<Vector2 *>::const_iterator it = p_graph.points.begin(); it != p_graph.points.end(); ++it)
                {
                    if ((*it)->getX() == j && (*it)->getY() == i)
                    {
                        p_os << " X ";
                        break;
                    }
              }
                  p_os << " . ";
              }
                p_os << std::endl;
        } 

        for (int i = 0; i <= p_graph.size.getX() + 1; i++)
        {
            p_os << "  "<<i << "";
        }
        return p_os;
    }
};

#endif