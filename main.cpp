#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

struct GridDim {
  // Grid Dimensions
  int width;
  int height;
};

void formatGrid(GridDim &grid, int magnitude);
void printGrid(vector<vector<char>> grid);
bool isInputValid(string input);
string getUserTarget();

int main() {

  // Declarations and Initializations
  GridDim gridDim;
  string nextTarget = "a1";
  bool isInputValid;
  
  // set grid size
  formatGrid(gridDim, 1);
  
  // declare and populate vectors
  // init a single row and fill with `0` then
  // init the 2D vecor filled with `vector<int> row`.
  char gridTile = '0';
  vector<char> row(gridDim.width, gridTile);
  vector<vector<char>> grid(gridDim.height, row);
  // finish grid creation

  printGrid(grid);

  nextTarget = getUserTarget();
  
  
  
  

  

  return 0;
}

void formatGrid(GridDim &grid, int magnitude) {
  // ascii chars are 5 pixel in width and 11 pixel in height
  // compensate by making square 11 by 5
  grid.width = 11 * magnitude;
  grid.height = 5 * magnitude;
}

void printGrid(vector<vector<char>> grid) {
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid.at(i).size(); j++) {
      cout << grid.at(i).at(j);
    }
    cout << endl;
  }
  cout << endl;
}


bool isInputValid(string input){
  bool validFlag;
  
  if (input.size() > 2){  //too long?
    validFlag = false;
    
  } else if (isalpha(input.at(0)) == false){ //1st char is letter?
    validFlag = false;
    
  } else if (islower(input.at(0)) == false){ //1st char lower case?
    validFlag = false;
    
  } else if (isdigit(input.at(1)) == false){ //2nd char number?
    validFlag = false;
    
  } else {
    validFlag = true;
    
  }  
  
  return validFlag;
}


string getUserTarget() {
  string nextTarget;
  
  // Get Coordinates from the user
  cout << "Enter next target position: ";
  cin >> nextTarget;
  //convert first first char to lower case
  nextTarget.at(0) = tolower(nextTarget.at(0));

  // continue to ask for input until it's valid
  while (isInputValid(nextTarget) == false){
    cout << "Invalid input, please try again." << endl << endl;
    cout << "Enter next target position: ";
    cin >> nextTarget;
  }

  return nextTarget;
}
