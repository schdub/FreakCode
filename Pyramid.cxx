#include <bits/stdc++.h>

enum Direction {
    right,
    bottom,
    left,
    top,
};

template <class T>
int numDigits(T number) {
    assert(number >= 0);
    int digits = 0;
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}

void drawPyramid(std::ostream & rStream, int aSide, int aStep) {
    Direction dir = Direction::right;
    int curLev = 0;
    int row{0}, col{0};
    int rowDirection{0}, colDirection{1};
    std::vector<std::vector<int>> field(aSide, std::vector(aSide, -1));
    auto coordsIsValid = [](int aRow, int aCol, int aSide) -> bool {
        return (aRow >= 0 && aCol >= 0 && aRow < aSide && aCol < aSide);
    };
    for (;;) {
        assert(coordsIsValid(row, col, aSide));
        field[row][col] = curLev;
        int newRow = row + rowDirection;
        int newCol = col + colDirection;
        bool isOk = coordsIsValid(newRow, newCol, aSide);
        if (!isOk || field[newRow][newCol] != -1) {
            switch (dir) {
            case Direction::right:
                dir = Direction::bottom;
                rowDirection=1;
                colDirection=0;
                break;
            case Direction::bottom:
                dir = Direction::left;
                rowDirection=0;
                colDirection=-1;
                break;
            case Direction::left:
                dir = Direction::top;
                rowDirection=-1;
                colDirection=0;
                break;
            case Direction::top:
                dir = Direction::right;
                rowDirection=0;
                colDirection=1;
                curLev += aStep;
                break;
            }
            newRow = row + rowDirection;
            newCol = col + colDirection;
        }
        row = newRow;
        col = newCol;
        if (field[row][col] != -1) break;
    }

    int maxDigits = numDigits( (aSide-1) * aStep ) + 1;
    for (const std::vector<int> & v: field) {
        for (int c{}; c < aSide; ++c) {
            rStream << std::setw(maxDigits) << std::setfill(' ') << v[c];
        }
        rStream << std::endl;
    }
    rStream << std::endl;
}

int main(int argc, char** argv) {
    drawPyramid(std::cout, 4, 1);
    drawPyramid(std::cout, 4, 2);
    drawPyramid(std::cout, 5, 1);
    drawPyramid(std::cout, 5, 2);
    drawPyramid(std::cout, 10, 100);
    drawPyramid(std::cout, 11, 200);
}
