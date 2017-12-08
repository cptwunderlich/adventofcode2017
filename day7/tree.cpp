#include <vector>
#include <iostream>
#include <fstream>
#include <unordered_map>

/* Advent of Code Day 7
 *
 * This code assumes well-formed input.
 *
 * Benjamin Maurer (maurer.benjamin@gmail.com)
 * GitHub: github.com/cptwunderlich
 */

using intvec = std::vector<int>;
using strsize = std::string::size_type;

std::unordered_map<std::string, size_t> names{};
std::vector<std::vector<bool> > adjmatrix{};
std::vector<int> weights{};

std::string findName(size_t val) {
    for (auto entry : names) {
        if (entry.second == val) return entry.first;
    }
}

std::string findRoot() {
    for (size_t col=0; col < adjmatrix[0].size(); ++col) {
        size_t row;
        for (row=0; row < adjmatrix.size(); ++row) {
            if (adjmatrix[row][col]) break;
        }

        if (row >= adjmatrix.size()) return findName(col);
    }

    return "ERROR";
}

size_t insert(size_t &i, const std::string &name, int weight, ssize_t parent) {
    auto num = i;
    auto p = names.insert({name, num});
    if (p.second) {
        i++;
    
        if (weights.size() <= num) {
            weights.resize(num+1);
        }
        if (weights[num] < weight) weights[num] = weight;

        if (adjmatrix.size() <= num) {
            adjmatrix.resize(num+1);
            for (auto &v : adjmatrix) {
                v.resize(num+1);
            }
        }
    }

    num = p.first->second;
    if (parent >= 0) {
        adjmatrix[parent][num] = true;
    }

    return num;
}

void parseLine(const std::string &s) {
    static size_t i = 0;

    strsize pos = s.find(' ');
    std::string node = s.substr(0, pos);
    pos += 2;
    strsize pos2 = s.find(')', pos);
    std::string weight = s.substr(pos, pos2-(pos));

    size_t p = insert(i, node, std::stoi(weight), -1);

    //std::cout << "Node: " << node << " weight: " << weight;
    
    pos = s.find("->", pos2);
    if (pos != std::string::npos) {
        std::string neighbor;

        while (pos2 < s.length()) {
            pos = s.find(' ', pos);
            pos2 = s.find(',', pos);
            if (pos2 == std::string::npos) pos2 = s.length();
            pos++;
            neighbor = s.substr(pos, (pos2)-pos);
            insert(i, neighbor, 0, p);
            pos = pos2;
        }
    }

    //std::cout << '\n';
}

void printMat() {
    std::cout << "\n\n\n";

    for (size_t i = 0; i < adjmatrix.size(); ++i) {
        std::cout << findName(i) << " " << i << " ";
    
        for (bool c : adjmatrix[i]) {
            std::cout << ((c)? 1 : 0) << " ";
        }
        std::cout << "\n";
    }
}


int main() {
    std::ifstream f{"./input.txt"};
    for (std::string s; std::getline(f, s);) {
        parseLine(s);
    }
    f.close();

    std::cout << "Root: " << findRoot() << std::endl;

    //printMat();

    return 0;
}
