//Fill out this comment with your names and which bullet points you did
//Partners: Brian Vega
//Bullet Points: 
//Extra Credit: 
//URL to cover art and music: 

#include "/public/read.h"
#include "/public/colors.h"
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

vector<string> main_map = {
	"__________________________________________________", // This is the map(placeholder)
	"|                                                |",
	"|                                                |",
	"|                                                |",
	"|                                                |",
	"|                                                |",
	"|                                                |",
	"|                                                |",
	"|                                                |",
	"|                                                |",
	"|                                                |",
	"|                                                |",
	"|                                                |",
	"|                                                |",
	"|                                                |",
	"|                                                |",
	"|                                                |",
	"|                                                |",
	"|                                                |",
	"|                                                |",
	"__________________________________________________",
};

void print_mainmap(size_t player_row, size_t player_col) { //This prints map
    clearscreen();
    movecursor(0,0);
    for (size_t row = 0; row < main_map.size(); row++) {
        for (size_t col = 0; col < main_map.at(row).size(); col++) {
            if (row == player_row and col == player_col) cout << "🤴";
            else
                cout << main_map.at(row).at(col);
        }
        cout << endl;
    }
}

int main() {
    const int ROWS = main_map.size();
    const int COLS = main_map.at(0).size();
    const int FPS = 60;
    int row = ROWS/2, col = COLS/2;
    int last_row = -1, last_col = -1; //Save our last position so we only redraw on update
    set_raw_mode(true); //Non-blocking IO
    show_cursor(false);
    while (true) {
        int c = toupper(quick_read());
        if (c == 'Q') break;
        if (c == 'W' or c == UP_ARROW) row--;
        if (c == 'S' or c == DOWN_ARROW) row++;
        if (c == 'A' or c == LEFT_ARROW) col--;
        if (c == 'D' or c == RIGHT_ARROW) col++;
        if (!(row == last_row and col == last_col)) { //If we moved...
            print_mainmap(row,col); //...redraw the map
            last_row = row;
            last_col = col;
            movecursor(2,COLS+5);
            movecursor(ROWS+2,0);
            cout.flush();
		}
	}
}
