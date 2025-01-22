#include <iostream>
#include <vector>
using namespace std;

void display(vector<vector<char>> &board){
	cout<<"=============================\n"<<"       SUDOKU BOARD\n"<<"=============================\n";
    for(int i=0;i<board.size();i++){
        if (i % 3 == 0 && i != 0) {
            cout << "------------------------" << endl;
        }
        for(int j=0;j<board[0].size();j++){
            if(j%3==0 && j!=0){
                cout<<"| ";
            }
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"_________________________\n";
}

bool isValid(vector<vector<char>> &board,int row,int col,char c) { 
    for(int i = 0; i < 9; i++) {
        int x = (3 * (row / 3)) + (i / 3);
        int y = (3 * (col / 3)) + (i % 3);

        if(board[i][col] == c)
            return false;
        if(board[row][i] == c)
            return false;
        if(board[x][y] == c)
            return false;
    }
    return true;
}

bool solve(vector<vector<char>>& board){
    for(int i=0;i<board.size();i++) {
        for(int j=0;j<board[0].size();j++) {
            if(board[i][j] == '.'){
                for(char c='1';c<='9';c++) {
                    if(isValid(board,i,j,c)){
                        board[i][j]=c;
                        if(solve(board)==true)
                            return true; 
                        else 
                            board[i][j]='.';
                    }
                }
                return false;
            }
        }
    }       
    return true;
}

void solver(vector<vector<char>> &board){
    display(board);
    int x=0;
        do{
        cout<<"\nENTER CHOICE:-)\n";
        cout<<"1.USE_SOLVER\n2.ENTER_VALUE\n";
        cout<<"Choice:";
        int n1;
        cin>>n1;
        if(n1==1){
            x++;
            solve(board);
        }
        else if(n1==2){
            system("cls");
            display(board);
            cout<<"Enter the position: "<<endl;
            int row,col;
            char val;
            cout<<"Row:";
            cin>>row;
            cout<<"Column:";
            cin>>col;
            cout<<"value:";
            cin>>val;
            board[row-1][col-1]=val;
        }
    }while(x==0);
}

int main(){
    system("cls");
    vector<vector<char>> board(9,vector<char>(9,'.'));
    solver(board);
    system("cls");
    display(board);
    cout<<"=============================\n"<<"         SOLUTION\n";
    cout<<"=============================\n"<<"Thank you for using the Sudoku solver!\n";
    return 0;
}
