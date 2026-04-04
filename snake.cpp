#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <ctime>
using namespace std;

#define MINX 2
#define MINY 2
#define MAXX 35
#define MAXY 20

void gotoxy(int x, int y){
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  _COORD pos;
  pos.X = x;
  pos.Y = y;
  SetConsoleCursorPosition(hConsole, pos);
}

void VeKhung(){
    for (int i = MINX; i <= MAXX; i++){
        for (int j = MINY; j <= MAXY; j++){
            if ((i == MINX) || (i == MAXX) || (j == MINY) || (j == MAXY)){
                gotoxy(i * 2, j);
                printf("+");
            }
        }
    }
}

struct Point{
    int x,y;
};

class CONRAN{
private:
	Point A[100];
    int DoDai;
public:
    void banDau(){
        this->DoDai = 3;
        this->A[0].x = 9; this->A[0].y = 5;
        this->A[1].x = 8; this->A[1].y = 5;
        this->A[2].x = 7; this->A[2].y = 5;
    }
    void Ve(){
    	int i;
        for (i = 0; i < this->DoDai; i++){
            gotoxy(this->A[i].x * 2, this->A[i].y);
            cout << char(219) << char(219);
        }
        gotoxy(this->A[i].x * 2, this->A[i].y);
        cout << "  ";
    }
    void DiChuyen(int Huong){
        for (int i = DoDai; i > 0;i--)
            A[i] = A[i-1];
        
        if (Huong == 0) A[0].x = A[0].x + 1;
        if (Huong == 1) A[0].y = A[0].y + 1;
        if (Huong == 2) A[0].x = A[0].x - 1;
        if (Huong == 3) A[0].y = A[0].y - 1;
    }
    bool KiemTraThua(){
        if (A[0].x < MINX || A[0].x > MAXX - 1 || A[0].y <= MINY || A[0].y >= MAXY) {
            return true;
        }
        for (int i = 1; i < DoDai; i++) {
            if (A[0].x == A[i].x && A[0].y == A[i].y) {
                return true;
            }
        }
        return false;
    }
};

int main(){
    CONRAN snake;
    int Huong = 0;
    snake.banDau();
    snake.Ve();
    VeKhung();
    char t;
    while (1){
        if (kbhit()){
            t = getch();
            if (t == 'd' && Huong != 2) Huong = 0;
            if (t == 's' && Huong != 3) Huong = 1;
            if (t == 'a' && Huong != 0) Huong = 2;
            if (t == 'w' && Huong != 1) Huong = 3;
        }
        snake.Ve();
        snake.DiChuyen(Huong);
        Sleep(200);
        if (snake.KiemTraThua()) {
        	int centerX = (MINX + MAXX) / 2;
            gotoxy(centerX * 2 - 8, MAXY + 2);
            cout << "=== GAME OVER ===" << endl;
            break; 
        }
        Sleep(300);
    } 
    return 0;
}

