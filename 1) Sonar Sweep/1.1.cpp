#include <iostream>
#include <fstream>
#include <vector>
#include <string>


void read(std::ifstream& file) {
    std::vector<int> depths;
    int counterit = 0;
    int counter2it = 0;
    int counter = 0;
    std::vector<int>::iterator it;
    std::vector<int>::iterator it1;

    if (file.is_open()) {
        while (!file.eof()) {
            int temp;
            file >> temp;
            depths.push_back(temp);
        }
    }
    else {
        std::cout << "...";
    }
    file.close();

    for (it = depths.begin() + 1; it != depths.end(); ++it) {
        if (*(it - 1) < *(it)) {
            counterit++;
        }
    }

    for (it = depths.begin(), it1 = ++depths.begin(); it1 != depths.end(); ++it, ++it1) {
        if (*it < *it1) {
            counter2it++;
        }
    } 
   

  
    for (int i = 1; i < depths.size(); i++) {
        if (depths[i] > depths[i - 1] ) {
            counter++;
        }
    }
    std::cout << counter << " " << counterit <<  " " << counter2it;

}

int main() {

    std::ifstream file("dane.txt");
    read(file);
}

