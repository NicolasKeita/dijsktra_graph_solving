/*
** EPITECH PROJET, 2018
** Graph.hpp
** File description:
** description?
*/

#ifndef DIJKSTRA_TRAINING_GRAPH_HPP
#   define DIJKSTRA_TRAINING_GRAPH_HPP

#include <algorithm>
#include <deque>
#include <stack>

namespace uti::graph {
    template<typename T>
    class Graph;
}
#include "Dijkstra.hpp"
// TODO : Pour enlever les functions "doublons", je peux laisser le param en const et ensuite enlever le const
// TODO : Add const or/and noexcept to appropriate methods

/*
 * A graph contains a container of vertices.
 * Those vertices contains a container of edges and an element to determine their ID (e.g name).
 * In this implementation I only used std::deque as container
 * API public functions :
 *          addVertex(ID_vertex) to create
 *          addVertex(ID_vertex_1, ID_vertex_2, BIDIRECT) to link
 *          getVertex(ID_vertex) to get
 */
namespace uti::graph {
    enum LinkType {
        A_TO_B = 0,
        B_TO_A,
        BIDIRECT
    };
    class CannotFindVertex : public std::exception {};
    template<typename T>
    class Graph {
    public:
        class Vertex;
        class Edge;
    private:
        std::deque<Vertex> _vertices;
    public:
        std::deque<Vertex> &getVertices() { return _vertices; };

        std::stack<T *> dijkstraSolving(const T &begin, const T&end)
        {
            uti::graph::Dijkstra<T> d;
            return d.getShortestPath(*this, begin, end);
        }


        Vertex &addVertex(const T &element) {
            auto it = std::find(_vertices.begin(), _vertices.end(), element);
            if (it != _vertices.end())
                return *it;
            _vertices.push_back(Vertex(element));
            return *_vertices.end();
        };
        Vertex &addVertex(T &element) {
            auto it = std::find(_vertices.begin(), _vertices.end(), element);
            if (it != _vertices.end())
                return *it;
            _vertices.push_back(Vertex(element));
            return *_vertices.end();
        };
    public:
        void addVertex(const T &first_elem, const T &second_elem,
                       LinkType link = A_TO_B, long double distance = 1)
        {
            addVertex(first_elem);
            addVertex(second_elem);
            Vertex &vertex1 = getVertex(first_elem);
            Vertex &vertex2 = getVertex(second_elem);
            switch (link) {
                case A_TO_B : {
                    vertex1.link(vertex2, distance);
                    break;
                }
                case B_TO_A : {
                    vertex2.link(vertex1, distance);
                    break;
                }
                case BIDIRECT : {
                    vertex1.link(vertex2, distance);
                    vertex2.link(vertex1, distance);
                    break;
                }
                default:
                    break;
            }
        }
        void addVertex(T &first_elem, T &second_elem,
                       LinkType link = A_TO_B, long double distance = 1)
        {
            addVertex(first_elem);
            addVertex(second_elem);
            Vertex &vertex1 = getVertex(first_elem);
            Vertex &vertex2 = getVertex(second_elem);
            switch (link) {
                case A_TO_B : {
                    vertex1.link(vertex2, distance);
                    break;
                }
                case B_TO_A : {
                    vertex2.link(vertex1, distance);
                    break;
                }
                case BIDIRECT : {
                    vertex1.link(vertex2, distance);
                    vertex2.link(vertex1, distance);
                    break;
                }
                default:
                    break;
            }
        }
    public:
        Vertex &getVertex(const T &elem) {
            auto it = std::find(_vertices.begin(), _vertices.end(), elem);
            if (it == _vertices.end())
                throw CannotFindVertex();
            return *it;
        }
        Vertex &getVertex(T &elem) {
            auto it = std::find(_vertices.begin(), _vertices.end(), elem);
            if (it == _vertices.end())
                throw CannotFindVertex();
            return *it;
        }

    public:
        class Vertex {
        public:
            explicit Vertex(const T &element) : element{ const_cast<T &>(element) } {}
            explicit Vertex(T &element) : element{ element } {}

            T &element;
            std::deque<Edge> edges;

            Vertex(const Vertex &) = delete;
            Vertex &operator=(const Vertex &) = delete;
            Vertex(Vertex &&) = default;
            Vertex &operator=(Vertex &&) noexcept = default;

            bool operator==(const T &elem) const { return elem == this->element; };
            bool operator==(T &elem) const { return elem == element; };
            bool operator==(const Vertex &elem) const { return elem.element == element; }; // TODO : correct the operator==

            void link(Vertex &other, long double distance) { edges.push_back(Edge(*this, other, distance)); };
        };
    public:
        class Edge {
        public:
            Edge(Vertex &begin, Vertex &end, long double distance)
                : weight{distance},
                  begin{begin},
                  end{end} {}

            Edge(const Edge &) = delete;
            Edge &operator=(const Edge &) = delete;
            Edge(Edge &&) noexcept = default;
            Edge &operator=(Edge &&) noexcept = default;

            long double weight;
            Vertex &begin;
            Vertex &end;

            bool operator==(const Edge &other) { return other.weight == weight; }; // TODO : correct the operator==
        };
    };
}

#endif //DIJKSTRA_TRAINING_GRAPH_HPP
