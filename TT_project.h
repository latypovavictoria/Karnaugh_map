#pragma once

#include <memory>
#include <vector>
#define Q_bool_func 16

class Object {
public:
	void print_DNF();
	void parse_data(int argc, char* argv[]);

private:
	void prepare_K_map();
	void get_K_map();

	std::vector<int> bool_func = {};
	std::vector<int> bool_result = {};
	std::vector<std::vector<int>> result_vector = {};
};