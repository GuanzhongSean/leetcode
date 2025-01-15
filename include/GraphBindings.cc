#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "Graph.h"

namespace py = pybind11;

PYBIND11_MODULE(libGraph, m) {
	py::class_<Graph::Node>(m, "Node")
		.def(py::init<int>())
		.def(py::init<int, std::vector<Graph::Node *>>())
		.def_readwrite("val", &Graph::Node::val)
		.def_property(
			"neighbors",
			[](const Graph::Node &node) -> std::vector<Graph::Node *> {
				return node.neighbors;
			},
			[](Graph::Node &node, const std::vector<Graph::Node *> &neighbors) {
				node.neighbors = neighbors;
			})
		.def("print", [](const Graph::Node &node) { node.print(); });

	py::class_<Graph, std::shared_ptr<Graph>>(m, "Graph")
		.def(py::init<const std::vector<std::vector<int>> &>())
		.def("print", [](const Graph &graph) { graph.print(); })
		.def("__getitem__", &Graph::get, py::return_value_policy::reference)
		.def("get", &Graph::get, py::return_value_policy::reference);
}
