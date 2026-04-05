#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <ctime>

using namespace std;

void gotoxy( int column, int line );

struct Point{
    int x,y;
};

class CONRAN{
public:
    struct Point A[100];
    int DoDai;
    
    CONRAN(){
        DoDai = 3;
        A[0].x = 10; A[0].y = 10;
        A[1].x = 11; A[1].y = 10;
        A[2].x = 12; A[2].y = 10;
    }
    
    void Ve(){
        for (int i = 0; i < DoDai; i++){
            gotoxy(A[i].x, A[i].y);
            cout << "X";
        }
    }
    
    void DiChuyen(int Huong){
        for (int i = DoDai-1; i > 0; i--)
            A[i] = A[i-1];
        if (Huong==0) A[0].x = A[0].x + 1;
        if (Huong==1) A[0].y = A[0].y + 1;
        if (Huong==2) A[0].x = A[0].x - 1;
        if (Huong==3) A[0].y = A[0].y - 1;
    }

    bool KiemTraTrung(int x, int y) {
        for (int i = 0; i < DoDai; i++) {
            if (A[i].x == x && A[i].y == y) return true;
        }
        return false;
    }
};

void TaoMoi(Point &moi, CONRAN &r) {
    bool trung = true;
    while (trung) {
        moi.x = rand() % 30; 
        moi.y = rand() % 20; 
        
        if(moi.x == 0) moi.x++;
        if(moi.y == 0) moi.y++;

        trung = r.KiemTraTrung(moi.x, moi.y);
    }
}

void VeMoi(Point moi) {
    gotoxy(moi.x, moi.y);
    cout << "*";
}

int main()
{
    srand(time(0));

    CONRAN r;
    Point moi;
    int Huong = 0;
    char t;

    TaoMoi(moi, r);

    while (1){
        if (kbhit()){
            t = getch();
            if (t=='a') Huong = 2;
            if (t=='w') Huong = 3;
            if (t=='d') Huong = 0;
            if (t=='x') Huong = 1;
        }
        
        system("cls"); 
        
        r.DiChuyen(Huong);

        if (r.A[0].x == moi.x && r.A[0].y == moi.y) {
            r.DoDai++;
            TaoMoi(moi, r);
        }

        r.Ve();
        VeMoi(moi);
        
        Sleep(300);
    }

    return 0;
}

void gotoxy( int column, int line )
{
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
}