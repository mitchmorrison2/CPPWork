#include <iostream>

using namespace std;


void placePiece(int player);
bool checkBoardForWinner(int x, int y, int player);
bool diagonalUpLeftDownRight(int x, int y, int player);
bool diagonalDownLeftUpRight(int x, int y, int player);
bool verticalCombo(int x, int y, int player);
bool horizontalCombo(int x, int y, int player);
void printBoard(char p1char, char p2char);

bool check_diagonal_combo_SW_NE(int x, int y, int player);
bool check_diagonal_combo_NW_SE(int x, int y, int player);
bool check_vertical_combo(int x, int y, int player);
bool check_horizontal_combo(int x, int y, int player);



const int rows = 9;
const int columns = 7;
int board[rows][columns] = {}; //9 rows and 7 columns of null spaces
int lastMoveX, lastMoveY;

int main()
{
		//int counter = 0;
		//bool winner = false;
		cout << "What character would player 1 like to use?  ";
		char p1char;
		cin >> p1char;
		
		cout << "What character would player 2 like to use?  ";
		char p2char;
		cin >> p2char;
		
		
		printBoard(p1char, p2char);
		
		
		for (int i = 0; i < 32; i++) {
			\
			//moves and checking for player 1
			placePiece(1);
			printBoard(p1char, p2char);
			//winner = checkBoardForWinner(lastMoveX, lastMoveY, 1);
			checkBoardForWinner(lastMoveX, lastMoveY, 1);
			if (checkBoardForWinner(lastMoveX, lastMoveY, 1)) {
				cout << "Player 1 wins!" << endl;
				break;
			}
			}
			
			//moves and checking pieces for player 2
			placePiece(2);
			printBoard(p1char, p2char);
			//winner = checkBoardForWinner(lastMoveX, lastMoveY, 2);
			checkBoardForWinner(lastMoveX, lastMoveY, 2);
			if (checkBoardForWinner(lastMoveX, lastMoveY, 2)) {
				cout << "Player 2 wins!" << endl;
				break;
			}
			}
	return 0;
}


void placePiece(int player) {
	
	int columnPick;
		cout << "Player " << player << " pick a column (1-7):  ";
		cin >> columnPick;
	while (columnPick > columns || columnPick < 1) {
		 cout << "Please select again: ";
		 cin >> columnPick;
	} //makes sure player only picks between 1-7
	
	int number = 0;
	while (board[(rows - 1) - number][(columnPick - 1)] != 0) {
		
		number++;
		if (number > (rows - 1)) {
			cout << "Please select a different column: "; //this column is full
			cin >> columnPick;
			number = 0; //reset number count to work for every turn
		}
	}
	board[(rows - 1) - number][columnPick-1] = player;
	lastMoveX = columnPick - 1;
	lastMoveY = (rows - 1) - number;
}

bool checkBoardForWinner(int x, int y, int player) {
	
	if (check_diagonal_combo_SW_NE(x, y, player)) return true;
	else if (check_diagonal_combo_NW_SE(x, y, player)) return true;
	else if (check_vertical_combo(x, y, player)) return true;
	else if (check_horizontal_combo(x, y, player)) return true;
	else return false;
}

bool diagonalUpLeftDownRight(int x, int y, int player) {
	
	int score = 1;
	int count = 1;
	
	while ((y + count >= 0) && (x + count < columns)) {
		if (board[y + count][x + count] == player) {
			score++;
			count++;
		}
		else break;
	}
	
	count = 1;
	while ((y - count < rows) && (x - count >= 0)) {
		if (board[y-count][x-count] == player) {
			score++;
			count++;
		}
		else break;
	}
	
	if (score == 4) return true;
	else return false;
}

bool diagonalDownLeftUpRight(int x, int y, int player) {
	
	int score = 1;
	int count = 1;
	
	while ((y - count >= 0) && (x + count < columns)) {
		if (board[y-count][x+count] == player) {
			score++;
			count++;
		}
		else break;
	}
	
	count = 1;
	while ((y + count < rows) && (x - count >= 0)) {
		if (board[y + count][x - count] == player) {
			score++;
			count++;
		}
		else break;
	}
	
	if (score == 4) return true;
	else return false;
}

bool verticalCombo(int x, int y, int player) {
	
	int score = 1;
	int count = 1;
	
	while ((y + count >= 0) && (y + count < rows)) {
		if (board[y + count][x] == player) { //check down
			score++;
			count++;
		}
		else break;
	}
	if (score == 4) return true;
	else return false;
}

bool horizontalCombo(int x, int y, int player) {
	
	int score = 1;
	int count = 1;
	
	while ((x+count >= 0) && (x + count < columns)) {
		if (board[y][x + count] == player) { //check left
			score++;
			count++;
		}
		else break;
	}
	count = 1;
	while ((x - count < columns) && (x - count >= 0)) {
		if (board[y][x-count] == player) { //check right
			score++;
			count++;
		}
		else break;
	}
	
	if (score == 4) return true;
	else return false;
}

void printBoard(char p1char, char p2char) {
	
	for (int r = 0; r < rows; r++) { //rows
		for (int c = 0; c <= columns; c++) { //columns
			cout << "| ";
			
			if (board[r][c] == 0) cout << " ";
			else if (board[r][c] == 1) cout << p1char;
			else if (board[r][c] == 2) cout << p2char;
		}
		cout << endl;
	}
	cout << "======================" << endl << endl; 
}






bool check_diagonal_combo_SW_NE(int x, int y, int player)
{
   int score = 1;
   int count = 1;
   
   while((y-count >= 0) && (x+count < columns))
   {
      if (board[y-count][x+count] == player)  //Check SW to NE
      {
         score++;
         count++;
      }
      else break;  //If no combo is detected break from the loop
   }

   count = 1;
   while((y+count < rows) && (x-count >=0))
   {
      if (board[y+count][x-count] == player)  //Check NE to SW
      {
         score++;
         count++;
      }   
      else break;  //If no combo is detected break from the loop
   }
   
   if (score == 4) return true;
   else return false;
}

bool check_diagonal_combo_NW_SE(int x, int y, int player)
{
   int score = 1;
   int count = 1;
   
   while((y+count >= 0) && (x+count < columns))
   {
      if (board[y+count][x+count] == player)  //Check NW to SE
      {
         score++;
         count++;
      }
      else break;  //If no combo is detected break from the loop
   }

   count = 1;
   while((y-count < rows) && (x-count >=0))
   {
      if (board[y-count][x-count] == player)  //Check SE to NW
      {
         score++;
         count++;
      }   
      else break;  //If no combo is detected break from the loop
   }
   
   if (score == 4) return true;
   else return false;
}

bool check_vertical_combo(int x, int y, int player)
{
   int score = 1;
   int count = 1;
   
   while(y+count >= 0 && y+count < rows)
   {
      if (board[y+count][x] == player)  //Check Down
      {
         score++;
         count++;
      }
      else break;  //If no combo is detected break from the loop
   }
  
   if (score == 4) return true;
   else return false;
}

bool check_horizontal_combo(int x, int y, int player)
{
   int score = 1;
   int count = 1;
   
   while((x+count >= 0) && (x+count < columns))
   {
      if (board[y][x+count] == player)  //Check Left
      {
         score++;
         count++;
      }
      else break;  //If no combo is detected break from the loop
   }

   count = 1;
   while((x-count < columns) && (x-count >=0))
   {
      if (board[y][x-count] == player)  //Check Right
      {
         score++;
         count++;
      }   
      else break;  //If no combo is detected break from the loop
   }
   
   if (score == 4) return true;
   else return false;
}
