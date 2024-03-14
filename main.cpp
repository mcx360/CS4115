#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

void compressMatrix(double epsilon = 0) {
    int columnIndex = 0;
    string line;

    while (getline(cin, line)) {
        stringstream lineStream(line);
        double value;

        while (lineStream >> value) {
            if (epsilon == 0) {
                if (value != 0)
                    cout << columnIndex + 1 << " " << value << " ";
            } else {
                if (abs(value) > epsilon)
                    cout << columnIndex + 1 << " " << value << " ";
            }
            columnIndex++;
        }
        columnIndex = 0;
        cout << endl;
    }
}

int main(int argc, char *argv[]) {
    double epsilon = 0;

    if (argc > 2 && string(argv[1]) == "-e") {
        epsilon = fabs(atof(argv[2]));
    }

    compressMatrix(epsilon);

    return 0;
}