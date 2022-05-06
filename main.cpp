#include <iostream>
#include <vector>
using namespace std;

struct GridDim {
  // Grid Dimensions
  int width;
  int height;
};

void PixelSquare(GridDim &grid, int magnitude);
void PrintGrid(vector<vector<int>> grid);

int main() {

  // set grid size
  GridDim gridDim;
  PixelSquare(gridDim, 3);

  // declare and populate vectors
  // init a single row and fill with `0` then
  // init the 2D vecor filled with `vector<int> row`.
  vector<int> row(gridDim.width, 0);
  vector<vector<int>> grid(gridDim.height, row);

  PrintGrid(grid);

  return 0;
}

void PixelSquare(GridDim &grid, int magnitude) {
  // ascii chars are 5 pixel in width and 11 pixel in height
  // compensate by making square 11 by 5
  grid.width = 11 * magnitude;
  grid.height = 5 * magnitude;
}

void PrintGrid(vector<vector<int>> grid) {
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid.at(i).size(); j++) {
      cout << grid.at(i).at(j);
    }
    cout << endl;
  }
}
