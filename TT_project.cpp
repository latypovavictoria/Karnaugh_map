#include "TT_project.h"
#include <iostream>


void Object::get_K_map() {
    prepare_K_map();

    std::cout << bool_result[0] << '|' << bool_result[1] << '|' << bool_result[3] << '|' << bool_result[2] << '\n';
    std::cout << bool_result[4] << '|' << bool_result[5] << '|' << bool_result[7] << '|' << bool_result[6] << '\n';
    std::cout << bool_result[12] << '|' << bool_result[13] << '|' << bool_result[15] << '|' << bool_result[14] << '\n';
    std::cout << bool_result[8] << '|' << bool_result[9] << '|' << bool_result[11] << '|' << bool_result[10] << '\n';
}

void Object::prepare_K_map() {

    std::vector<std::vector<int>> bool_vector = {
    { 0,0,0,0 }, { 0,0,0,1 }, { 0,0,1,0 }, { 0,0,1,1 },
    { 0,1,0,0 }, { 0,1,0,1 }, { 0,1,1,0 }, { 0,1,1,1 },
    { 1,0,0,0 }, { 1,0,0,1 }, { 1,0,1,0 }, { 1,0,1,1 },
    { 1,1,0,0 }, { 1,1,0,1 }, { 1,1,1,0 }, { 1,1,1,1 }
    };
    unsigned int i = 0, j = 0;
    for (std::vector<int>temp : result_vector) {
        i++;
        for (std::vector<int>temp1 : bool_vector) {
            j++;
            if (temp == temp1) {
                if (i >= 15 || j >= 15) {
                    break;
                }
                else {
                    std::swap(bool_result[i], bool_result[j]);
                }
            }
        }
    }
}



void Object::parse_data(int argc, char* argv[]) {

    for (unsigned int i = 1; i < argc; i++) {
        bool_func.clear();
        bool_func.push_back(atoi(argv[i]));
        bool_func.push_back(atoi(argv[i + 1]));
        bool_func.push_back(atoi(argv[i + 2]));
        bool_func.push_back(atoi(argv[i + 3]));

        bool_result.push_back(atoi(argv[i + 4]));
        result_vector.push_back(bool_func);

        i += 4;

        if (i >= 80) {
            break;
        }
    }
    try {
        get_K_map();
    }
    catch (const std::string& exception) {
        std::cerr << "You input too little data\n" << exception;
    }
}

int main(int argc, char* argv[])
{
    Object o{};
    o.parse_data(argc, argv);
}



