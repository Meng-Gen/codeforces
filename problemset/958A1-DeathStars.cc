#include <iostream>
#include <string>
#include <vector>

typedef std::vector<char> MapLine;
typedef std::vector< MapLine > Map;

void PrintMap(Map map) {
    int dim = map.size();
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            std::cout << map[i][j];
        }
        std::cout << std::endl;
    }
}

Map Flip(Map map) {
    Map output;
    int dim = map.size();
    for (int i = 0; i < dim; i++) {
        MapLine map_line;
        for (int j = 0; j < dim; j++) {
            map_line.push_back(map[i][dim - j - 1]);
        }
        output.push_back(map_line);
    }
    return output;
}

Map Rotate(Map map) {
    Map output;
    int dim = map.size();
    for (int i = 0; i < dim; i++) {
        MapLine map_line;
        for (int j = 0; j < dim; j++) {
            map_line.push_back(map[dim - j - 1][i]);
        }
        output.push_back(map_line);
    }
    return output;
}

std::vector< Map > GenerateAllEquivalentMaps(Map map) {
    std::vector< Map > output;
    output.push_back(map);
    output.push_back(Rotate(map));
    output.push_back(Rotate(Rotate(map)));
    output.push_back(Rotate(Rotate(Rotate(map))));
    output.push_back(Flip(map));
    output.push_back(Flip(Rotate(map)));
    output.push_back(Flip(Rotate(Rotate(map))));
    output.push_back(Flip(Rotate(Rotate(Rotate(map)))));
    return output;
}

bool IsIdenticalMap(Map one, Map other) {
    int dim = one.size();
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (one[i][j] != other[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool IsIsomorphicMap(Map one, Map other) {
    std::vector< Map > equivalent_other = GenerateAllEquivalentMaps(other);
    for (int i = 0; i < 8; i++) {
        if (IsIdenticalMap(one, equivalent_other[i])) {
            return true;
        }
    }
    return false;
}

int main(int argc, char* argv[]) {
    int dim = 0;
    Map one;
    Map other;
    std::string input;

    std::cin >> dim;
    for (int i = 0; i < dim; i++) {
        std::cin >> input;
        one.push_back(std::vector<char>(input.begin(), input.end()));
    }
    for (int i = 0; i < dim; i++) {
        std::cin >> input;
        other.push_back(std::vector<char>(input.begin(), input.end()));
    }

    std::cout << (IsIsomorphicMap(one, other) ? "Yes" : "No") << std::endl;
    return 0;
}