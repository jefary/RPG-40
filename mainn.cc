//People: Quinne Holtermann
//Bullet Points: 3
//Extra Credit:

#include "/public.read.h"
#include "/public/colors.h"
#include <vector>
#include <algorithm>
#include <unistd.h>

using namespace std;

int main() {
  
  cout << YELLOW << "HELLO" << BLUE << " GAMER!" << endl;
  
  cout << BOLDBLUE << "This is... " << BOLDGREEN << "THE GAME!" << endl;
  
  cout << RESET;
  
  setbgcolor(105,0,105);
  
  int num;
  
  cout << "Please hit a number to continue, then press the enter key.";
  cin >> num;
  
  set_cursor_mode(false);
  
  for (int i = 0; i < 2; i++) {
    clearscreen();
    setcolor(44,47,45);
    movecursor(0,0);
    
    cout << "Welcome to the game" << endl;
    usleep(10'000);
  }
  
  cout << RESET;
  resetcolor();
  
  const auto [ROWS,COLS] = get_terminal_size();
  
  cout << ROWS << " " << COLS << endl;
  
  int x = COLS / 2;
  int y = ROWS / 2;
  
  setcolor(104,107,105);
  set_raw_mode(true);
  
  while (true) {
    int ch = quick_read();
    
    if (ch == ERR) {
      usleep(100'000);
    }
    
    if (ch == 'Q' or ch == 'q') break;
    if (ch == UP_ARROW) y--;
    if (ch == DOWN_ARROW) y++;
    if (ch == LEFT_ARROW) x--;
    if (ch == RIGTH_ARROW) x++;
    
    y = clamp(y,0,ROWS - 2);
    x = clamp(x, 0, COLS - 2);
    clearscreen();
    movecursor(y,x);
    
    setbgcolor(45,47,105);
    cout << "YOU MAY NOW ENTER THE GAME... ENJOY :)" << endl;
  }
  
  set_raw_mode(false);
  resetcolor();
  set_cursor_mode(true);
  clearscreen();
  
  return 0;
}
