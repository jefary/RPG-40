
//Partners: Brian Vega
//Bullet Points:
//Extra Credit:

#include "/public/read.h"
#include "/public/colors.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <unistd.h>
using namespace std;

vector<string> world_map {
	"*****************************************************************************************",
	"* .                 T             .       ...                                           *",
	"*T      P     P           P           P   T   T       T P     T         T   .     T . T *",
	"*   . T             T  . . . T           P     . T T   .       P T     .     T     .    *",
	"* .   T T   T   . T T . T       . T   . .     . T   T         T     .               .   *",
	"*T  P . T     P         .       T       P       P T     .       . . P         T P   T . *",
	"* T . T   T P P               P   T   T T   P P   P T P P . T         P         T       *",
	"*.  T   T . P         .   T . T             P   .     T . . .   T     T P   T . T .   T *",
	"*               T T         T P P T T     T   P   T         P           P     P         *",
	"* P P . P   P T T T   T   . P         P   T   T     .     .   T     . T     . . . P     *",
	"*       T   T . . T T .   T   P     .         T P     T P  R    T P T .   P   P T   .   *",
	"*     T       T               P T T P T   .   .     T     P   P   T P P     T       P P *",
	"* P P . P T         P P . T     T P     T .   T T     . .           T       T       T P *",
	"* . T       T .   T       P   T       P   T       P T   P P   T         T T     T       *",
	"* B   G   B B P     B                       B * G   *                       B * * B     *",
	"* *   G * G B             G G       *   B             B B               *     * * *     *",
	"* P     P P B   G G *     P   P B       G               P P P           G       * * B G *",
	"*       G         * G *   B P B       B B P B   B     P               P       *         *",
	"*B *   * B   *       B *   *       G           G G B * P G G        *   G             B *",
	"* P *   S         G   P   G   G   *         P G G           G G   B     * * G   G       *",
	"* P P                     * B P   G   B   B B               B G B     G G B       *   P *",
	"*   *   B *   * P B       P   P * P       P         G     * G G   B     B     P B   P   *",
	"* G G B B *   P   B B         B   G     B *   B   B B   *   B       G   B P         G P *",
	"*   B         *            R    P P   B * *               B   * P B   P G * P * G P     *",
	"*     P P G P         *       P G                   P P       P P         G             *",
	"* G G         P   *     P     G   B *         *       G B   G   P   P     B G   B B     *",
	"*     *   B   G           P P   P P G       P     P       B B   P *     P         G   G *",
	"*         * B *         P P   *   * P           B   G B *             G   G B P     B   *",
	"*   ~ * ~ *     ~ G G     G *   B G *       *     G B     * * B B * * G   R   * * B G G *",
	"* B G     *     G * ~ *         B     *     ~     * *     *   * * ~ * G *   * * *   ~   *",
	"* B ~             G *     G G       G   *     * G ~   B G       * ~ ~ G   *   *   G ~ * *",
	"* G G B   G * B * G ~ * * B ~ G B   B B * ~   ~ *         * G * *   * B *     G   ~   G *",
	"*~  B   * B ~     G   G ~ G   * G   G * B G G * ~   G B     B   B   B   B B     G   B G *",
	"* B ~ G G   G   ~   G         G G   G G     ~   G     B   B B *   B   ~   ~   B   *     *",
	"* ~ G B G     ~ *       *   G *   ~     ~     ~   G B   * *   ~ * * B   G * ~ *   * G B *",
	"*     * ~   *   G  R  G   * B   ~   G * B ~     ~ *   *     *     G G   B B   B * B     *",
	"G   B G B * G B   * ~ G *     G *   *               ~   G * * * * * R * B     * * * * ~ *",
	"*   G B   ~ *     B *   ~ G ~     * G * G     G   ~ * B         ~     ~   B           ~ *",
	"* *   B B   G B   G     B     * ~ G *   *         *   G G   B   G B * G G B G B G * B G *",
	"*   B   * B G G   *     G G *   G G   ~ ~ B G ~ G G G   G     B ~   *     B   * *   ~   *",
	"*   G G ~   G G   G             G *   B   *   G     ~     B *   G     G G *   *       G *",
	"*****************************************************************************************",
};

char get_world_location(size_t row, size_t col) {
    if (row >= world_map.size()) return ' ';
    if (col >= world_map.at(row).size()) return ' ';
    return world_map.at(row).at(col);
}

void set_world_location(size_t row, size_t col, char c) {
    if (row >= world_map.size()) return;
    if (col >= world_map.at(row).size()) return;
    world_map.at(row).at(col) = c;
}

void print_world(size_t player_row, size_t player_col) {
    clearscreen();
    movecursor(0,0);
    for (size_t row = 0; row < world_map.size(); row++) {
        for (size_t col = 0; col < world_map.at(row).size(); col++) {
            if (row == player_row and col == player_col) cout <<'H';
            else
                cout << world_map.at(row).at(col);
        }
        cout << endl;
    }
}

int main() {
    const int ROWS = world_map.size();
    const int COLS = world_map.at(0).size(); //MAKE SURE ALL ROWS ARE THE SAME SIZE OR BAD TIMES
    const int FPS = 60;
    int row = ROWS/8, col = COLS/8;
    int last_row = -1, last_col = -1; //Save our last position so we only redraw on update
	int invPotion = 0, invSword = 0;
	int heroHealth = 100;
    set_raw_mode(true);
    show_cursor(false);
    while (true) {
        int c = toupper(quick_read());
        if (c == 'Q') break;
        if (c == UP_ARROW) row--;
        if (c == DOWN_ARROW) row++;
        if (c == LEFT_ARROW) col--;
        if (c == RIGHT_ARROW) col++;
        if (!(row == last_row and col == last_col)) { //If we moved...
            print_world(row,col); //...redraw the map
            last_row = row;
            last_col = col;
            movecursor(2,COLS+5);
            cout << YELLOW << "(!) OBJECTIVE: COMPLETE ALL FIVE RIDDLES WITHOUT DYING!" << RESET;
			movecursor(3,COLS+5);
			cout << CYAN << "Health: " << heroHealth << RESET;
            movecursor(4,COLS+5);
			cout << GREEN << "INVENTORY:" << RESET;
			if (invSword > 0) {
				movecursor(5,COLS+10);
				cout << GREEN << "Equipped - UPGRADED SWORD!" << RESET;
			}
			if (invPotion > 0) {
				movecursor(6,COLS+10);
				cout << GREEN << invPotion << "x - Health Potion" << RESET;
			}
            cout.flush();
        }
        if (get_world_location(row, col) == 'P') {
            set_world_location(row,col,' ');
			invPotion++;
            movecursor(4,COLS+15);
            cout << "Health potion picked up!\n";
        }
        if (get_world_location(row, col) == 'S') {
			set_world_location(row, col, ' ');
			invSword++;
            movecursor(4, COLS+15);
            cout << "Sword picked up!";
        }
        if (c == ERR) usleep(1'000'000 / FPS);
    }
    set_raw_mode(false);
    show_cursor(true);
    movecursor(0,0);
    clearscreen();
}
