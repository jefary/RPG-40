
//Partners: Brian Vega, Gaige Unsiog, Quinn
//Bullet Points:(Brian - Map) (Gaige - Combat) (Quinn - Colors)
//Extra Credit:(Brian - Inventory)

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
	"*T      .     .                           T   T       T       T         T   .     T . T *",
	"*   . T     C       T  . . . T                 . T T   .         T ********   T    .    *",
	"* .   T T                                                          *      *  .    T     *", 
	"*T    . T               .       T                 T     .       .       R *   T     T . *",
	"* T . T   T     .                 T   T T           T     . T     /*      *     T       *",
	"*.  T   T .           .   T . T                 .     T . . .   T  ********  T . T .  T *",
	"*               T T         T     T T     T       T                                     *",
	"*     .       T T T   T   .               T   T     .     .   T     . T     . . .       *",
	"*       T   T . . T T .   T         .         T       T         T   T .         T   .   *",
	"*     T       T                 T T   T   .   .     T     P       T         T           *",
	"*     .   T             . T     T       T .   T T     . .           T       T       T P *",
	"* . T       T .   T       .   T       P   T       P T         T         T T     T       *",
	"* B   G   B B P     B                       B * G   *                       B * * B     *",
	"* *     *   B               G       *   B             B B    .          *     * * *     *",
	"*  .        B     G *   .     P B       G  .    T                       G       * * B G *",
	"*       G         * G *   B   B       B B   B   B     P          .    P       *         *",
	"*B * G * B   *       B *   *       G           G   B *     G        *   G             B *",
	"* R  *         .  G   P   G       *         P          .          B     * *     G       *",
	"* P G                    * B P        B   B B               B G B     G G B       *   P *",
	"*   *   B *   * P B       P     *         P         G     * G G   B     B       B       *",
	"* G G B B *   P   B B   ~  ****   B   G B *   B   B B   *   B       G   B P         G P *",
	"*   B         *   ~          S *  P     B * *             B   * P B   P G * P * G P     *",
	"*     P P G P         *    ****                     P P       P P         G             *",
	"* G G         P   *     P     G   B *         *       G B   G   P   P     B G   B B     *",
	"*     *   B   G           P P   P P G   ~   P     P       B B   P *     P         G   G *",
	"*         * B *         P P   *   * P           B   G B *           C G   G B P     B   *",
	"*   ~ * ~ *     ~ G G     G *   B G *       *     G B     * * B B * * G G R~  * * B G G *",
	"* B G     *     G * ~ *         B     *     ~     * *     *   * * ~ * G * ~ * * *   ~   *",
	"* B ~        C    G *     G G       G   *     * G ~   B G       * ~ ~ G   *   *   G ~ * *",
	"* G G B   G * B * G ~ * * B ~ G B   B B * ~   ~ *         * G * * C * B *     G   ~   G *",
	"*~  B   * B ~     G   G ~ G   * G   G * B G G * ~   G B     B   B   B   B B     G   B G *",
	"* B ~ G G   G   ~   G         G G   G G     ~   G     B   B B *   B   ~   ~   B   *     *",
	"* ~ G B G     ~ *  G ~  *   G *   ~     ~     ~   G B   * *   ~ * * B   G * ~ *   * G B *",
	"*     * ~   *   G  R  G   * B   ~   G * B ~     ~ *   *     *   ~ G G G B B   B * B     *",
	"G   B G B * G B G * ~ G *     G *   *      G        ~   G * * * * * R * B     * * * * ~ *",
	"*   G B   ~ *     B *   ~ G ~     * G * G G~  G   ~ * B         ~  G  ~   B           ~ *",
	"* *   B B   G B   G     B     * ~ G *   * GC G    *   G G   B   G B * G G B G B G * B G *",
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

int attack (int& entHealth) { //attack damage to goblin by player
int dmg;
  dmg = (rand() % 5 + 1) * 4;
  entHealth -= dmg;
  return entHealth;
}
int gAttack (int& playerHP) { //attacks from goblin to player
int dmg;
  dmg = (rand() % 2 + 1);
  playerHP -= dmg;
  return playerHP;
  }

void printCombat(int pHealth, int enmHealth) { // this calls to combat sequence
 while (pHealth > 0) {
  cout << "The player attacks" << endl;
  attack(enmHealth);
  cout << "Goblin health: " << enmHealth << endl << endl;
  cout << "The goblin attacks" << endl;
  gAttack(pHealth);
  cout << "Player health: " << pHealth << endl << endl;
  if (enmHealth < 0) {
      cout << "Goblin died!" << endl;
     break;
   }
   else if (pHealth < 0) {
      cout << "GAME OVER!" << endl;
     }
   }
}


void print_world(size_t player_row, size_t player_col) { //Color here!!!
    clearscreen();
    movecursor(0,0);
    for (size_t row = 0; row < world_map.size(); row++) {
        for (size_t col = 0; col < world_map.at(row).size(); col++) {
            if (row == player_row and col == player_col) cout << YELLOW <<'H'<< RESET;
			  else 
                cout << world_map.at(row).at(col);
        }
		cout << endl;
    }
}

int main() {
    const int ROWS = world_map.size();
    const int COLS = world_map.at(0).size(); //MAKE SURE ALL ROWS ARE THE SAME SIZE OR BAD TIME
	const int FPS = 15;
    int row = ROWS/8, col = COLS/8;
    int last_row = -1, last_col = -1; //Save our last position so we only redraw on update
	int invPotion = 0, invSword = 0, invCoin = 0, invRiddle = 0;  //Variables in inventory
	int heroHealth = 100, heroDamage = 1; //Player stats
    set_raw_mode(true);
    show_cursor(false);
    while (true) {
        int c = toupper(quick_read());
        if (c == 'Q') break;
        if (c == UP_ARROW) row--;
        if (c == DOWN_ARROW) row++;
        if (c == LEFT_ARROW) col--;
        if (c == RIGHT_ARROW) col++;
		if (c == 'P') {
			if (invPotion > 0){
				invPotion--;
				heroHealth+= 10;
			}
		}
        if (!(row == last_row and col == last_col)) { //If we moved...
            print_world(row,col); //...redraw the map
            last_row = row;
            last_col = col;
            movecursor(2,COLS+5);
            cout << YELLOW << "(!) OBJECTIVE: COLLECT FIVE RIDDLES (R) & COLLECT FIVE COINS (C) WITHOUT DYING!" << RESET;
			movecursor(3,COLS+5);
			cout << CYAN << "Health: " << heroHealth << RESET;
			movecursor(3,COLS+18);
			cout << CYAN << "Coins: " << invCoin << RESET;
			movecursor(3, COLS+29);
			cout << CYAN << "Riddles: " << invRiddle << RESET;
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
		if(get_world_location(row, col) == 'T') {
			cout << GREEN << "T" << RESET;
		}
		if (get_world_location(row, col) == '.') {
			cout << CYAN << "." << RESET;
		}
        if (get_world_location(row, col) == 'P') {
			cout << CYAN << "P" << RESET;
            set_world_location(row,col,' ');
			invPotion++;
            movecursor(4,COLS+15);
            cout << "Health potion picked up! Press P to use.\n";
        }
		if (get_world_location(row, col) == 'C') {
			cout << YELLOW << "C" << RESET;
			set_world_location(row,col,' ');
			invCoin++;
			movecursor(4, COLS+15);
			cout << "Coin picked up! \n";
		}
        if (get_world_location(row, col) == 'S') {
			set_world_location(row, col, ' ');
			invSword++;
            movecursor(4, COLS+15);
            cout << "Sword picked up!";
        }
		if (get_world_location(row, col) == '~') {
            heroHealth-= 1;
            movecursor(4, COLS+15);
            cout << RED << "You stepped in LAVA! GET OUT!" << RESET;
		}
		if (get_world_location(row, col) == 'R') {
			cout << YELLOW << "R" << RESET;
			set_world_location(row, col, ' ');
			invRiddle++;
			//This would set off the riddle H  over R
			//NPC diologue here
		}
		if (get_world_location(row, col) == 'G'){
			movecursor(8, COLS+10);
			int enmHealth = 50;
			int uiCounter = 9;

			cout << "You entered a fight!" << endl;

			while (heroHealth  > 0 and enmHealth > 0) {
				movecursor(uiCounter, COLS+10);
 				 cout << "The player attacks" << endl;
 				 attack(enmHealth);
				 uiCounter++;
				 movecursor(uiCounter, COLS+10);
				 cout << "Goblin health: " << enmHealth << endl << endl;
				 uiCounter++;
				 movecursor(uiCounter, COLS+10);
  				cout << "The goblin attacks" << endl;
  				gAttack(heroHealth);
				uiCounter++;
				movecursor(uiCounter, COLS+10);
  				cout << "Player health: " << heroHealth << endl << endl;
  				if (enmHealth < 0) {
					uiCounter++;
					movecursor(13, COLS+10);
      				cout << "Goblin died!" << endl;
     				set_world_location(row, col, ' ');
   				}
   				else if (heroHealth < 0) {
      				cout << "GAME OVER!" << endl;
    			 }	
  			 }
			
		}
        if (c == ERR) usleep(1'000'000 / FPS);
		if (invCoin == 5 and invRiddle == 5) {
			clearscreen();
			movecursor(0, 0);
			cout << GREEN << "YOU WIN\n" << RESET;
			return 0;
		}
		if (heroHealth < 0) {
			clearscreen();
			movecursor(0, 0);
			cout << RED << "YOU DIED!\n" << RESET;
			return 0;

		}
    }
    set_raw_mode(false);
    show_cursor(true);
    movecursor(0,0);
    clearscreen();
}
