#include<iostream>

using namespace std;

// check if any cell is unassigned
bool unassignedCell(int grid[9][9], int& row, int& col){
    for(row=0; row<9; row++){
        for(col=0; col<9; col++){
            if(grid[row][col]==0){
                return true;
            }
        }
    }

    return false;
}

// check if number is already used in column
bool usedInCol(int grid[9][9], int col, int i){
    for(int rows=0; rows<9; rows++){
        if(grid[rows][col]==i){
            return false;
        }
    }
    return false;
}

// check if number is already used in row
bool usedInRow(int grid[9][9], int row, int i){
    for(int cols=0; cols<9; cols++){
        if(grid[row][cols]==i){
            return true;
        }
    }
    return false;
}

// check if number is already used in box
bool usedInBox(int grid[9][9], int boxRow, int boxCol, int i){
    for(int row=0; row<3; row++){
        for(int col=0; col<3; col++){
            if(grid[row+boxRow][col+boxCol]==i){
                return true;
            }
        }
    }
    return false;
}

bool isSafe(int grid[9][9], int row, int col, int i){
    if(!usedInCol(grid, col, i) && !usedInRow(grid, row, i) && !usedInBox(grid, row-(row%3), col-(col%3), i) && grid[row][col]==0){
        return true;
    }

    return false;
}

bool solve(int grid[9][9]){
    int row, col;
    if(!unassignedCell(grid, row, col)){
        return true;
    }
    for(int i=1; i<=9; i++){
        if(isSafe(grid, row, col, i)){
            grid[row][col] = i;
            if(solve(grid)){
                return true;
            }
            grid[row][col] = 0;
        }
    }

    return false;
}

void printGrid(int grid[9][9]){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int grid[9][9] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
					{ 5, 2, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 8, 7, 0, 0, 0, 0, 3, 1 },
					{ 0, 0, 3, 0, 1, 0, 0, 8, 0 },
					{ 9, 0, 0, 8, 6, 3, 0, 0, 5 },
					{ 0, 5, 0, 0, 9, 0, 6, 0, 0 },
					{ 1, 3, 0, 0, 0, 0, 2, 5, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 7, 4 },
					{ 0, 0, 5, 2, 0, 6, 3, 0, 0 } }; 

    // cout<<"Enter numbers";
    // for(int i=0; i<9; i++){
    //     for(int j=0; j<9; j++){
    //         cin>>grid[i][j];
    //     }
    // }

    if(solve(grid)==true){
        printGrid(grid);
    }
    else{
        cout<<"Solution Not possible";
    }
    return 0;
}