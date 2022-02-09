
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <process.h>
#include <stdlib.h>
#include <graphics.h>

#define U 72
#define L 75
#define D 80
#define R 77
#define ESC 27

int a[5][5],
    idle, poly[16][8] = {{200, 150, 255, 150, 255, 205, 200, 205}, {255, 150, 310, 150, 310, 205, 255, 205}, {310, 150, 365, 150, 365, 205, 310, 205}, {365, 150, 420, 150, 420, 205, 365, 205}, {200, 205, 255, 205, 255, 260, 200, 260}, {255, 205, 310, 205, 310, 260, 255, 260}, {310, 205, 365, 205, 365, 260, 310, 260}, {365, 205, 420, 205, 420, 260, 365, 260}, {200, 260, 255, 260, 255, 315, 200, 315}, {255, 260, 310, 260, 310, 315, 255, 315}, {310, 260, 365, 260, 365, 315, 310, 315}, {365, 260, 420, 260, 420, 315, 365, 315}, {200, 315, 255, 315, 255, 370, 200, 370}, {255, 315, 310, 315, 310, 370, 255, 370}, {310, 315, 365, 315, 365, 370, 310, 370}, {365, 315, 420, 315, 420, 370, 365, 370}};
void main()
{
    void init(), draw(), disp(), status(int);
    int er, i, j, k, checkran(), check();
    char c;
    clrscr();
    init();
    disp();
    flushall();
    for (; c != ESC;)
    {
        idle = 0;
        c = getch();
        switch (c)
        {
        case D:
            for (i = 0; i < 4; i++)
                for (j = 1; j < 4; j++)
                    if (a[j][i] == 0)
                        for (k = j; k > 0; k--)
                        {
                            if (a[k - 1][i] != 0)
                                idle++;
                            a[k][i] = a[k - 1][i];
                            a[k - 1][i] = 0;
                        }
            for (i = 0; i < 4; i++)
                for (j = 3; j > 0; j--)
                    if (a[j][i] == a[j - 1][i])
                    {
                        if (a[j][i])
                            idle++;
                        a[j][i] *= 2;
                        for (k = j; k > 0; k--)
                            a[k - 1][i] = a[k - 2][i];
                        a[0][i] = 0;
                    }
            disp();
            switch (checkran())
            {
            case -1:
                status(-1);
                break;
            case 1:
                status(1);
                break;
            case 0:
                er = check();
                break;
            }
            if (er == -1)
                status(-1);
            disp();
            break;

        case U:
            for (i = 0; i < 4; i++)
                for (j = 2; j >= 0; j--)
                    if (a[j][i] == 0)
                        for (k = j; k < 3; k++)
                        {
                            if (a[k + 1][i] != 0)
                                idle++;
                            a[k][i] = a[k + 1][i];
                            a[k + 1][i] = 0;
                        }
            for (i = 0; i < 4; i++)
                for (j = 0; j < 3; j++)
                    if (a[j][i] == a[j + 1][i])
                    {
                        if (a[j][i])
                            idle++;
                        a[j][i] *= 2;
                        for (k = j; k < 3; k++)
                            a[k + 1][i] = a[k + 2][i];
                        a[3][i] = 0;
                    }
            disp();
            switch (checkran())
            {
            case -1:
                status(-1);
                break;
            case 1:
                status(1);
                break;
            case 0:
                er = check();
                break;
            }
            if (er == -1)
                status(-1);
            disp();
            break;

        case R:
            for (i = 0; i < 4; i++)
                for (j = 1; j < 4; j++)
                    if (a[i][j] == 0)
                        for (k = j; k > 0; k--)
                        {
                            if (a[i][k - 1] != 0)
                                idle++;
                            a[i][k] = a[i][k - 1];
                            a[i][k - 1] = 0;
                        }
            for (i = 0; i < 4; i++)
                for (j = 3; j > 0; j--)
                    if (a[i][j] == a[i][j - 1])
                    {
                        if (a[i][j])
                            idle++;
                        a[i][j] *= 2;
                        for (k = j; k > 0; k--)
                            a[i][k - 1] = a[i][k - 2];
                        a[i][0] = 0;
                    }
            disp();
            switch (checkran())
            {
            case -1:
                status(-1);
                break;
            case 1:
                status(1);
                break;
            case 0:
                er = check();
                break;
            }
            if (er == -1)
                status(-1);
            disp();
            break;

        case L:
            for (i = 0; i < 4; i++)
                for (j = 2; j >= 0; j--)
                    if (a[i][j] == 0)
                        for (k = j; k < 3; k++)
                        {
                            if (a[i][k + 1] != 0)
                                idle++;
                            a[i][k] = a[i][k + 1];
                            a[i][k + 1] = 0;
                        }
            for (i = 0; i < 4; i++)
                for (j = 0; j < 3; j++)
                    if (a[i][j] == a[i][j + 1])
                    {
                        if (a[i][j])
                            idle++;
                        a[i][j] *= 2;
                        for (k = j; k < 3; k++)
                            a[i][k + 1] = a[i][k + 2];
                        a[i][3] = 0;
                    }
            disp();
            switch (checkran())
            {
            case -1:
                status(-1);
                break;
            case 1:
                status(1);
                break;
            case 0:
                er = check();
                break;
            }
            if (er == -1)
                status(-1);
            disp();
            break;
        }
    }
}
int check(void)
{
    int i, j;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            if (a[i][j] == 0)
                return 1;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            if (a[i][j] == a[i][j + 1] || a[i][j] == a[i + 1][j])
                return 1;
    return -1;
}
int checkran(void)
{
    int f = 0, i, j, k;
    if (idle == 0)
        return 0;
    randomize();
    if (random(100) % 2 == 0)
    {
        for (i = 0; i < 4; i++)
            for (j = 0; j < 4; j++)
                if (a[i][j] == 0)
                {
                    a[i][j] = 2;
                    return 0;
                }
    }
    else
    {
        for (i = 3; i >= 0; i--)
            for (j = 3; j >= 0; j--)
                if (a[i][j] == 0)
                {
                    a[i][j] = 4;
                    return 0;
                }
    }

    if (f == 0)
        for (i = 0; i < 4; i++)
            for (j = 0; j < 4; j++)
                if (a[i][j] == a[i][j + 1] || a[i][j] == a[i + 1][j])
                {
                    f++;
                    break;
                }
    if (f == 0)
        return -1;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            if (a[i][j] == 2048)
                return 1;
    return 0;
}
void status(int sta)
{
    switch (sta)
    {
    case 1:
        printf("bravo!");
        getch();
        exit(0);
    case -1:
        printf("looser!");
        getch();
        exit(0);
    }
}
void disp(void)
{
    int i, j, k, x, y;
    char buf[] = "blah!";
    settextstyle(1, 0, 1);
    setcolor(14);
    setlinestyle(0, 0, 3);
    outtextxy(3, 3, "");
    for (k = 0, i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
        {
            switch (a[i][j])
            {
            case 0:
                setfillstyle(1, 0);
                break;
            case 2:
                setfillstyle(1, 7);
                break;
            case 4:
                setfillstyle(1, 3);
                break;
            case 8:
                setfillstyle(1, 2);
                break;
            case 16:
                setfillstyle(1, 9);
                break;
            case 32:
                setfillstyle(1, 13);
                break;
            case 64:
                setfillstyle(1, 5);
                break;
            case 128:
                setfillstyle(1, 1);
                break;
            case 256:
                setfillstyle(1, 12);
                break;
            case 512:
                setfillstyle(1, 4);
                break;
            case 1024:
                setfillstyle(1, 6);
                break;
            case 2048:
                setfillstyle(1, 14);
                break;
            case 4096:
                setfillstyle(1, 8);
                break;
            case 8192:
                setfillstyle(1, 0);
                break;
            case 16384:
                setfillstyle(1, 15);
                break;
            }
            fillpoly(4, poly[k++]);
        }
    setcolor(WHITE);
    for (y = 160, i = 0; i < 4; i++, y += 56)
        for (x = 212, j = 0; j < 4; j++, x += 56)
            if (a[i][j] != 0)
            {
                sprintf(buf, "%d", a[i][j]);
                if (a[i][j] < 10)
                    outtextxy(x + 9, y + 3, buf);
                else if (a[i][j] < 100)
                    outtextxy(x + 3, y + 3, buf);
                else if (a[i][j] < 1000)
                    outtextxy(x - 3, y + 3, buf);
                else if (a[i][j] < 10000)
                    outtextxy(x - 9, y + 3, buf);
                else
                    outtextxy(x - 14, y + 3, buf);
            }
}

void init(void)
{
    int gd, gm, er, i, j;
    gd = DETECT;
    gm = DETECT; /* Request auto-detection	*/
    initgraph(&gd, &gm, "");
    er = graphresult(); /* Read result of initialization*/
    if (er != grOk)
    { /* Error occured during init	*/
        printf(" Graphics System Error: %s\n", grapherrormsg(er));
        getch();
        abort();
    }
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            if (j == 4 || i == 4)
                a[i][j] = 1;
            else
                a[i][j] = 0;
    randomize();
    if (random(1398) % 2 == 0)
    {
        a[2][0] = 4;
        a[3][1] = 2;
    }
    else if (random(485) % 3 == 0)
    {
        a[1][1] = 2;
        a[0][3] = 2;
    }
    else if (random(782) % 2 != 0)
    {
        a[0][0] = 2;
        a[1][3] = 4;
    }
    else
    {
        a[0][2] = 2;
        a[2][2] = 2;
    }
    rectangle(1, 1, getmaxx() - 1, getmaxy() - 1);
    setcolor(14);
    setlinestyle(0, 0, 3);
    settextstyle(0, 0, 7);
    outtextxy(206, 27, "2048");
    setfillstyle(1, 0);
    for (i = 0; i < 16; i++)
        fillpoly(4, poly[i]);
}
