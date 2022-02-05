#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main(void) {

    char field[10][21];
    int i, x = 4, y = 5;
    char key;
    int ox, oy;
    int ax = 5, ay = 3;
    int count = 0;

    srand(time(NULL));

    do {
        sprintf(field[0], "##################"); //sprintf - to type directly to string"
        for(i = 1; i < 9; i++) {
            sprintf(field[i], "#                 #");
        }
        sprintf(field[9], "##################");

        field[x][y] = '@';
        field[ax][ay] = '*';

        system("cls"); //to clear the console, from <conio.h>

        printf("COUNT: %d\n", count);

        for (i = 0; i < 10; i++)
        {
            printf("%s\n", field[i]);
        }

        key = getch(); //to proceed without pushing buttons

        ox = x;
        oy = y;

        if(key == 'w') x--;
        else if(key == 's') x++;
        else if(key == 'd') y++;
        else y--;

        if(field[x][y] == '#') {
            x = ox;
            y = oy;
        }
        if ((x == ax) && (y == ay)) {
            ++count;
            ax = rand() * 1.0 / RAND_MAX * 8 + 1;
            ay = rand() * 1.0 / RAND_MAX * 18;
        }
    } while(key != 'e');

    return 0;
}