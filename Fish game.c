// arze salam va khaste nabashid khedmate ostad Nouri gerami
//lotfan sedaye systeme khod ra ziyad konid
//in proje be sourate gorohii anajam shode tavasote:
// Elaheh Molaei be shomare daneshjoueie: 4001262728  &  Hananeh Momeni Ghamsari be shomare daneshjoueie : 4001262046
#include <stdio.h>
#include <time.h>
#include <windows.h> //baraye tolide rang va sedaa
#include <stdlib.h>
#include <math.h>

int khuneMahidar[8][16] = {0}; // khune mahi dar---> 8*16=128 ta ke 60 tasho ba raveshe zoj fard be surate zir kashi dar nazar gerefte va tush random mahi mizarim
int sumMahi[4] = {0};          // array 1D baraye jam kardane mahiha tavasote panguan ha

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ protoype +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int baresi6kashi_doresh(int g, int h); //baresi  6 jahate doresh
int baresi(int a, int b);
int baresi_masir(int g, int h, int f, int c);
int mohasebe_U(int g, int h, int f, int c);
void print_results(int sumMahi[], int n);
void print_gameBoard();

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++taghir rang++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
typedef enum
{
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    AQUA = 3,
    RED = 4,
    PURPLE = 5,
    YELLOW = 6,
    WHITE = 7,
    GRAY = 8,
    LIGHT_BLUE = 9,
    LIGHT_GREEN = 10,
    LIGHT_AQUA = 11,
    LIGHT_RED = 12,
    LIGHT_PURPLE = 13,
    LIGHT_YELLOW = 14,
    LIGHT_WHITE = 15
} ConsoleColors;
typedef HANDLE Handle;
typedef CONSOLE_SCREEN_BUFFER_INFO BufferInfo;
typedef WORD Word;
short setTextColor(const ConsoleColors foreground)
{
    Handle consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    BufferInfo bufferInfo;
    if (!GetConsoleScreenBufferInfo(consoleHandle, &bufferInfo))
        return 0;
    Word color = (bufferInfo.wAttributes & 0xF0) + (foreground & 0x0F);
    SetConsoleTextAttribute(consoleHandle, color);
    return 1;
} // end of setTextColor function

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int main()
{
    int i, j, z, shomarande; // i shomarande satr, j shomarande sutun, z shomarande tedade kashi haye daraye 1,2ya3 mahi
    srand(time(NULL));

    //------------------------------------------------------------

    for (i = 1; i <= 3; i++)
    {
        z = 1;
        if (i == 1)
            shomarande = 30;
        if (i == 2)
            shomarande = 20;
        if (i == 3)
            shomarande = 10;
        while (z <= shomarande) //random chidane 20 kashi daraye 2 mahi :
        {
            int rand1 = rand() % 8;
            if (rand1 % 2 == 0) //yani marbut be satr haye 0,2,4,6 dar in surat yek adade tasadofi digari bedast miarim
            {
                int rand2 = (rand() % 7 + 1) * 2;
                if (khuneMahidar[rand1][rand2] == 0)
                {
                    khuneMahidar[rand1][rand2] = i;
                    z++;
                }
            }
            else
            {
                int rand3 = ((rand() % 8) * 2) + 1;
                if (khuneMahidar[rand1][rand3] == 0)
                {
                    khuneMahidar[rand1][rand3] = i;
                    z++;
                }
            }
        }
    }
    //------------------------------------------------------------
    setTextColor(LIGHT_PURPLE);
    printf("=^.^=\nPlease turn up your system volume!!");
    setTextColor(YELLOW);
    printf("\n_____________________________________________________________\n");
    printf("| player 1 your penguins will be shown as : #\t\t    |\n| player 2 your penguins will be shown as : @\t\t    |\n| player 3 your penguins will be shown as : =\t\t    |\n| player 4 your penguins will be shown as : +\t\t    |\n|");
    printf("___________________________________________________________|\n\n");
    setTextColor(WHITE);
    print_gameBoard(); // print playbord kham ke tedad mahi malume faqat
    printf("\n\n");
    //------------------------------------------------------------

    /* tekei kod baraye daryafte tedade bazikonan , in nokte dar nazar gerefte shode ke tedade bazikonan bayad beyne 2ta4 bashad dar qeire
		in soorat ta zamani ke karbar adadi beine 2ta 4 nadade payame khata chap shode va mojadad az karbar tedade bazikonan daryaft shavad*/
    printf("How many players want to play?\n");
    int n; // n=tedade bazikonan
    scanf("%d", &n);
    while (n < 2 || n > 4)
    {
        setTextColor(GRAY);
        printf("%c", 7); //baraye ijade seda
        printf("<WARNING> !! The number of players shoud be between 2 and 4!  Again : How many players want to play?\n");
        setTextColor(WHITE);
        scanf("%d", &n);
    }

    //------------------------------------------------------------
    int a, b, l, sab;

    if (n == 2)
    {
        l = 4;
        sab = 2;
    }
    if (n == 3)
    {
        l = 3;
        sab = 3;
    }
    if (n == 4)
    {
        l = 2;
        sab = 4;
    }
    int m = 1;
    for (int j = 0; j < l; j++)
    {
        m = 1;
        for (i = 0; i < sab; i++)
        {

            printf("player%d please put your penguin(at the first enter the row and then column):", i + 1);
            scanf("%d %d", &a, &b);

            if (baresi(a, b) == 1 && khuneMahidar[a][b] > 0) // yani mokhtasat mojaze va qablan ham po nshde
            {
                sumMahi[m - 1] += khuneMahidar[a][b]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                khuneMahidar[a][b] = -1 * ((m - 1) + 1);
                print_gameBoard();
                printf("\n");
            }
            else
            {
                while (1)
                {
                    setTextColor(GRAY);
                    printf("%c", 7); //baraye ijade seda
                    printf("<WARNING> this tile is unavailable or have been selected before!\nagain player1 please put your penguin(at the first enter the row and then column:");
                    setTextColor(WHITE);
                    scanf("%d %d", &a, &b);

                    if (baresi(a, b) == 1 && khuneMahidar[a][b] > 0)
                    {
                        sumMahi[m - 1] += khuneMahidar[a][b]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                        khuneMahidar[a][b] = -1 * ((m - 1) + 1);
                        print_gameBoard();
                        printf("\n");
                        break;
                    }
                }
            }
            m++;
            printf("\n");
        }

        printf("*******************\n");
    }

    setTextColor(YELLOW);
    printf("\n_____________________________________________________________\n");
    printf("| player 1 your penguins will be shown as : #\t\t    |\n| player 2 your penguins will be shown as : @\t\t    |\n| player 3 your penguins will be shown as : =\t\t    |\n| player 4 your penguins will be shown as : +\t\t    |\n|");
    printf("___________________________________________________________|\n\n");
    setTextColor(WHITE);
    print_gameBoard(); //ke bebinim panguana koja gharar gereftan
    printf("\n\n");

    int g, h, f, c; //g & h mokhtasate panguani ke mikhym harkt bdim va f & j mokhtasate khunei ke in pamguan mikhd bre
    int v, w, k;
    int e = 0, q = 0, t = 0, d = 0, ee, qq, tt, dd; //e tedad panguan hayi az player 1ke 6 kashi doreshun pore //q tedad panguan hayi az player 2ke 6 kashi doreshun pore//t tedad panguan hayi az player 3ke 6 kashi doreshun pore//d tedad panguan hayi az player 4ke 6 kashi doreshun pore
    if (n == 2)
    {
        do //sharte payane bazi ro tuye while nvshtm
        {
			k=0;
            if (e <= 4)
            {
                printf("player1 which penguin do you want to move ?(at the first enter the row and then column:)");
                scanf("%d %d", &g, &h);
                while (khuneMahidar[g][h] == -1 && baresi6kashi_doresh(g, h) == 6)
                {
                    e++;
                    if (e == 4)
                    {
                        ee = e;
                        e = 5; //ke dige varede if nshe
                        k = -1;
                        khuneMahidar[g][h] = 0;
                        setTextColor(GRAY);
                        printf("%c", 7); //baraye ijade seda
                        printf("player 1 all of your penguins are off the screen Wait for all the player penguins or other players to leave!");
                        setTextColor(WHITE);
                        break;
                    }
                    else
                    {
                        khuneMahidar[g][h] = 0;

                        setTextColor(GRAY);
                        printf("%c", 7); //baraye ijade seda
                        printf("this penguin can not move!please select another penguin!\nagain player1 which penguin do you want to move ?(at the first enter the row and then column:)");
                        setTextColor(WHITE);
                        scanf("%d %d", &g, &h);
                    }
                }
                if (baresi(g, h) == 1 && khuneMahidar[g][h] == -1) //yani player 1 faqat mitune panguane khodesho taqiir bde va inke nare kashii ke tush panguan nis ya hazf shde ro entekhab kne!
                {
                    printf("where do you want to go?(at the first enter the row and then column:)");
                    scanf("%d %d", &f, &c);
                    if (baresi(f, c) == 1 && khuneMahidar[f][c] > 0 && baresi_masir(g, h, f, c) == 1) //yani ham maqsad mojaz bshe ham masir
                    {
                        sumMahi[0] += khuneMahidar[f][c]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                        khuneMahidar[f][c] = -1;          //panguan bere be khune maqsad
                        khuneMahidar[g][h] = 0;           //kashi mabda hazf she
                    }
                    else
                    { //else agar maqsad ya masir mojaz nabud va masir ham mojaz nabud
                        do
                        {
                            setTextColor(GRAY);
                            printf("%c", 7); //baraye ijade seda
                            printf("<WARNING>This tile is filled by one of your penguins or another. Or not available or this path is unavailable!\nagain player1 where do you want to go?(at the first enter the row and then column:)");
                            setTextColor(WHITE);
                            scanf("%d %d", &f, &c);
                            v = khuneMahidar[f][c];                                                           //meqdar avaliasho hefz mikne
                            if (baresi(f, c) == 1 && khuneMahidar[f][c] > 0 && baresi_masir(g, h, f, c) == 1) ///yani ham maqsad mojaz bshe ham masir
                            {
                                sumMahi[0] += khuneMahidar[f][c]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                                khuneMahidar[f][c] = -1;          //panguan bere be khune maqsad
                                khuneMahidar[g][h] = 0;           //kashi mabda hazf she
                            }
                        } while (baresi(f, c) == 0 || v <= 0 || baresi_masir(g, h, f, c) != 1);
                    }
                }
                else
                { //else agar mabdaa mojaz nbud
                    do
                    {
                        if (k == -1)
                        {
                            break;
                        }
                        else
                        {
                            setTextColor(GRAY);
                            printf("%c", 7); //baraye ijade seda
                            printf("<WARNING>This tile is filled by one of your penguins or another. Or not available\nagain player1 which penguin do you want to move ?(at the first enter the row and then column:");
                            setTextColor(WHITE);
                            scanf("%d %d", &g, &h);
                            w = khuneMahidar[g][h];                                                              //meqdar avaliasho hefz mikne
                            if (baresi(g, h) == 1 && khuneMahidar[g][h] == -1 )  //yani player 1 faqat mitune panguane khodesho taqiir bde va inke nare kashii ke tush panguan nis ya hazf shde ro entekhab kne!
                            {
                            	if(baresi6kashi_doresh(g, h) == 6){
                            		e++;
                            		ee=e;
								}else{
								
                                printf("where do you want to go?(at the first enter the row and then column:)");
                                scanf("%d %d", &f, &c);
                                if (baresi(f, c) == 1 && khuneMahidar[f][c] > 0 && baresi_masir(g, h, f, c) == 1) //yani ham maqsad mojaz bshe ham masir
                                {
                                    sumMahi[0] += khuneMahidar[f][c]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                                    khuneMahidar[f][c] = -1;          //panguan bere be khune maqsad
                                    khuneMahidar[g][h] = 0;           //kashi mabda hazf she
                                }
                                else
                                { //else agar maqsad ya masir mojaz nabud va masir ham mojaz nabud
                                    do
                                    {
                                        setTextColor(GRAY);
                                        printf("%c", 7); //baraye ijade seda
                                        printf("<WARNING>This tile is filled by one of your penguins or another. Or not available or this path is unavailable!\nagain player1 where do you want to go?(at the first enter the row and then column:)");
                                        setTextColor(WHITE);
                                        scanf("%d %d", &f, &c);
                                        v = khuneMahidar[f][c];                                                           //meqdar avaliasho hefz mikne
                                        if (baresi(f, c) == 1 && khuneMahidar[f][c] > 0 && baresi_masir(g, h, f, c) == 1) ///yani ham maqsad mojaz bshe ham masir
                                        {
                                            sumMahi[0] += khuneMahidar[f][c]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                                            khuneMahidar[f][c] = -1;          //panguan bere be khune maqsad
                                            khuneMahidar[g][h] = 0;           //kashi mabda hazf she
                                        }
                                    } while (baresi(f, c) == 0 || v <= 0 || baresi_masir(g, h, f, c) != 1);
                                }}
                            }
                        }

                    } while (baresi(g, h) == 0 || w != -1);
                }
                printf("\n");
                print_gameBoard();
                printf("\n_____________________________________________________________\n");
                printf("| player 1 your score is: %d   \t\t\t\t    |\n| player 2 your score is: %d    \t\t\t\t    |\n|                                   \t\t\t    |\n|                                   \t\t\t    |\n|", sumMahi[0], sumMahi[1]);
                printf("___________________________________________________________|\n\n");
                printf("\n");
                printf("\n");
            }

            if (q <= 4)
            {
                printf("player2 which penguin do you want to move ?(at the first enter the row and then column:)");
                scanf("%d %d", &g, &h);
                while (khuneMahidar[g][h] == -2 && baresi6kashi_doresh(g, h) == 6)
                {
                    q++;
                    if (q == 4)
                    {
                        qq = q;
                        q = 5;
                        k = -1;
                        khuneMahidar[g][h] = 0;
                        setTextColor(GRAY);
                        printf("%c", 7); //baraye ijade seda
                        printf("player 2 all of your penguins are off the screen Wait for all the player penguins or other players to leave!:\n");

                        setTextColor(WHITE);
                        break;
                    }
                    else
                    {
                        khuneMahidar[g][h] = 0;

                        setTextColor(GRAY);
                        printf("%c", 7); //baraye ijade seda
                        printf("this penguin can not move!please select another penguin!\nagain player2 which penguin do you want to move ?(at the first enter the row and then column:)");
                        setTextColor(WHITE);
                        scanf("%d %d", &g, &h);
                    }
                }
                if (baresi(g, h) == 1 && khuneMahidar[g][h] == -2) //yani player 2 faqat mitune panguane khodesho taqiir bde va inke nare kashii ke tush panguan nis ya hazf shde ro entekhab kne!
                {
                    printf("where do you want to go?(at the first enter the row and then column:)");
                    scanf("%d %d", &f, &c);
                    if (baresi(f, c) == 1 && khuneMahidar[f][c] > 0 && baresi_masir(g, h, f, c) == 1) //yani ham maqsad mojaz bshe ham masir
                    {
                        sumMahi[1] += khuneMahidar[f][c]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                        khuneMahidar[f][c] = -2;          //panguan bere be khune maqsad
                        khuneMahidar[g][h] = 0;           //kashi mabda hazf she
                    }
                    else
                    { //else agar maqsad ya masir mojaz nabud va masir ham mojaz nabud
                        do
                        {
                            setTextColor(GRAY);
                            printf("%c", 7); //baraye ijade seda
                            printf("<WARNING>This tile is filled by one of your penguins or another. Or not available or this path is unavailable!\nagain player2 where do you want to go?(at the first enter the row and then column:)");
                            setTextColor(WHITE);
                            scanf("%d %d", &f, &c);
                            v = khuneMahidar[f][c];                                                           //meqdar avaliasho hefz mikne
                            if (baresi(f, c) == 1 && khuneMahidar[f][c] > 0 && baresi_masir(g, h, f, c) == 1) ///yani ham maqsad mojaz bshe ham masir
                            {
                                sumMahi[1] += khuneMahidar[f][c]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                                khuneMahidar[f][c] = -2;          //panguan bere be khune maqsad
                                khuneMahidar[g][h] = 0;           //kashi mabda hazf she
                            }
                        } while (baresi(f, c) == 0 || v <= 0 || baresi_masir(g, h, f, c) != 1);
                    }
                }
                else
                { //else agar mabdaa mojaz nbud
                    do
                    {
                        if (k == -1)
                        {
                            break;
                        }
                        else
                        {
                            setTextColor(GRAY);
                            printf("%c", 7); //baraye ijade seda
                            printf("<WARNING>This tile is filled by one of your penguins or another. Or not available\nagain player2 which penguin do you want to move ?(at the first enter the row and then column:");
                            setTextColor(WHITE);
                            scanf("%d %d", &g, &h);
                            w = khuneMahidar[g][h];                            //meqdar avaliasho hefz mikne
                            if (baresi(g, h) == 1 && khuneMahidar[g][h] == -2) //yani player 2 faqat mitune panguane khodesho taqiir bde va inke nare kashii ke tush panguan nis ya hazf shde ro entekhab kne!
                            {
                                printf("where do you want to go?(at the first enter the row and then column:)");
                                scanf("%d %d", &f, &c);
                                if (baresi(f, c) == 1 && khuneMahidar[f][c] > 0 && baresi_masir(g, h, f, c) == 1) //yani ham maqsad mojaz bshe ham masir
                                {
                                    sumMahi[1] += khuneMahidar[f][c]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                                    khuneMahidar[f][c] = -2;          //panguan bere be khune maqsad
                                    khuneMahidar[g][h] = 0;           //kashi mabda hazf she
                                }
                                else
                                { //else agar maqsad ya masir mojaz nabud va masir ham mojaz nabud
                                    do
                                    {
                                        setTextColor(GRAY);
                                        printf("%c", 7); //baraye ijade seda
                                        printf("<WARNING>This tile is filled by one of your penguins or another. Or not available or this path is unavailable!\nagain player2 where do you want to go?(at the first enter the row and then column:)");
                                        setTextColor(WHITE);
                                        scanf("%d %d", &f, &c);
                                        v = khuneMahidar[f][c];                                                           //meqdar avaliasho hefz mikne
                                        if (baresi(f, c) == 1 && khuneMahidar[f][c] > 0 && baresi_masir(g, h, f, c) == 1) ///yani ham maqsad mojaz bshe ham masir
                                        {
                                            sumMahi[1] += khuneMahidar[f][c]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                                            khuneMahidar[f][c] = -2;          //panguan bere be khune maqsad
                                            khuneMahidar[g][h] = 0;           //kashi mabda hazf she
                                        }
                                    } while (baresi(f, c) == 0 || v <= 0 || baresi_masir(g, h, f, c) != 1);
                                }
                            }
                        }

                    } while (baresi(g, h) == 0 || w != -2);
                }
            }
            printf("\n");
            print_gameBoard();
            printf("\n\n");
            printf("\n_____________________________________________________________\n");
            printf("| player 1 your score is: %d   \t\t\t\t    |\n| player 2 your score is: %d    \t\t\t\t    |\n|                                   \t\t\t    |\n|                                   \t\t\t    |\n|", sumMahi[0], sumMahi[1]);
            printf("___________________________________________________________|\n\n");
            printf("*******************");

        } while ((ee + qq) != 8);  //sharte payane bazi
        print_results(sumMahi, 2); //dige bazi ke tamum she nobate elame barande hast
    }
    else if (n == 3)
    {
        do
        {
            k=0;
			if (e <= 3)
            {
                printf("player1 which penguin do you want to move ?(at the first enter the row and then column:)");
                scanf("%d %d", &g, &h);
                while (khuneMahidar[g][h] == -1 && baresi6kashi_doresh(g, h) == 6)
                {
                    e++;
                    if (e == 3)
                    {
                        ee = e;
                        e = 4;
                        k = -1;
                        khuneMahidar[g][h] = 0;
                        setTextColor(GRAY);
                        printf("%c", 7); //baraye ijade seda
                        printf("player 1 all of your penguins are off the screen Wait for all the player penguins or other players to leave!");
                        setTextColor(WHITE);
                        break;
                    }
                    else
                    {
                        khuneMahidar[g][h] = 0;

                        setTextColor(GRAY);
                        printf("%c", 7); //baraye ijade seda
                        printf("this penguin can not move!please select another penguin!\nagain player1 which penguin do you want to move ?(at the first enter the row and then column:)");
                        setTextColor(WHITE);
                        scanf("%d %d", &g, &h);
                    }
                }
                if (baresi(g, h) == 1 && khuneMahidar[g][h] == -1) //yani player 1 faqat mitune panguane khodesho taqiir bde va inke nare kashii ke tush panguan nis ya hazf shde ro entekhab kne!
                {
                    printf("where do you want to go?(at the first enter the row and then column:)");
                    scanf("%d %d", &f, &c);
                    if (baresi(f, c) == 1 && khuneMahidar[f][c] > 0 && baresi_masir(g, h, f, c) == 1) //yani ham maqsad mojaz bshe ham masir
                    {
                        sumMahi[0] += khuneMahidar[f][c]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                        khuneMahidar[f][c] = -1;          //panguan bere be khune maqsad
                        khuneMahidar[g][h] = 0;           //kashi mabda hazf she
                    }
                    else
                    { //else agar maqsad ya masir mojaz nabud va masir ham mojaz nabud
                        do
                        {
                            setTextColor(GRAY);
                            printf("%c", 7); //baraye ijade seda
                            printf("<WARNING>This tile is filled by one of your penguins or another. Or not available or this path is unavailable!\nagain player1 where do you want to go?(at the first enter the row and then column:)");
                            setTextColor(WHITE);
                            scanf("%d %d", &f, &c);
                            v = khuneMahidar[f][c];                                                           //meqdar avaliasho hefz mikne
                            if (baresi(f, c) == 1 && khuneMahidar[f][c] > 0 && baresi_masir(g, h, f, c) == 1) ///yani ham maqsad mojaz bshe ham masir
                            {
                                sumMahi[0] += khuneMahidar[f][c]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                                khuneMahidar[f][c] = -1;          //panguan bere be khune maqsad
                                khuneMahidar[g][h] = 0;           //kashi mabda hazf she
                            }
                        } while (baresi(f, c) == 0 || v <= 0 || baresi_masir(g, h, f, c) != 1);
                    }
                }
                else
                { //else agar mabdaa mojaz nbud
                    do
                    {
                        if (k == -1)
                        {
                            break;
                        }
                        else
                        {
                            setTextColor(GRAY);
                            printf("%c", 7); //baraye ijade seda
                            printf("<WARNING>This tile is filled by one of your penguins or another. Or not available\nagain player1 which penguin do you want to move ?(at the first enter the row and then column:");
                            setTextColor(WHITE);
                            scanf("%d %d", &g, &h);
                            w = khuneMahidar[g][h];                            //meqdar avaliasho hefz mikne
                            if (baresi(g, h) == 1 && khuneMahidar[g][h] == -1) //yani player 1 faqat mitune panguane khodesho taqiir bde va inke nare kashii ke tush panguan nis ya hazf shde ro entekhab kne!
                            {
                                printf("where do you want to go?(at the first enter the row and then column:)");
                                scanf("%d %d", &f, &c);
                                if (baresi(f, c) == 1 && khuneMahidar[f][c] > 0 && baresi_masir(g, h, f, c) == 1) //yani ham maqsad mojaz bshe ham masir
                                {
                                    sumMahi[0] += khuneMahidar[f][c]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                                    khuneMahidar[f][c] = -1;          //panguan bere be khune maqsad
                                    khuneMahidar[g][h] = 0;           //kashi mabda hazf she
                                }
                                else
                                { //else agar maqsad ya masir mojaz nabud va masir ham mojaz nabud
                                    do
                                    {
                                        setTextColor(GRAY);
                                        printf("%c", 7); //baraye ijade seda
                                        printf("<WARNING>This tile is filled by one of your penguins or another. Or not available or this path is unavailable!\nagain player1 where do you want to go?(at the first enter the row and then column:)");
                                        setTextColor(WHITE);
                                        scanf("%d %d", &f, &c);
                                        v = khuneMahidar[f][c];                                                           //meqdar avaliasho hefz mikne
                                        if (baresi(f, c) == 1 && khuneMahidar[f][c] > 0 && baresi_masir(g, h, f, c) == 1) ///yani ham maqsad mojaz bshe ham masir
                                        {
                                            sumMahi[0] += khuneMahidar[f][c]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                                            khuneMahidar[f][c] = -1;          //panguan bere be khune maqsad
                                            khuneMahidar[g][h] = 0;           //kashi mabda hazf she
                                        }
                                    } while (baresi(f, c) == 0 || v <= 0 || baresi_masir(g, h, f, c) != 1);
                                }
                            }
                        }

                    } while (baresi(g, h) == 0 || w != -1);
                }
                printf("\n");
                print_gameBoard();
                printf("\n_____________________________________________________________\n");
                printf("| player 1 your score is: %d   \t\t\t\t    |\n| player 2 your score is: %d    \t\t\t\t    |\n| player 3 your score is: %d    \t\t\t\t    |\n|                                   \t\t\t    |\n|", sumMahi[0], sumMahi[1], sumMahi[2]);
                printf("___________________________________________________________|\n\n");
                printf("\n");
                printf("\n");
            }

            if (q <= 3)
            {
                printf("player2 which penguin do you want to move ?(at the first enter the row and then column:)");
                scanf("%d %d", &g, &h);
                while (khuneMahidar[g][h] == -2 && baresi6kashi_doresh(g, h) == 6)
                {
                    q++;
                    if (q == 3)
                    {
                        qq = q;
                        q = 4;
                        k == -1;
                        khuneMahidar[g][h] = 0;
                        setTextColor(GRAY);
                        printf("%c", 7); //baraye ijade seda
                        printf("player 2 all of your penguins are off the screen Wait for all the player penguins or other players to leave!");

                        setTextColor(WHITE);
                        break;
                    }
                    else
                    {
                        khuneMahidar[g][h] = 0;

                        setTextColor(GRAY);
                        printf("%c", 7); //baraye ijade seda
                        printf("this penguin can not move!please select another penguin!\nagain player2 which penguin do you want to move ?(at the first enter the row and then column:)");
                        setTextColor(WHITE);
                        scanf("%d %d", &g, &h);
                    }
                }
                if (baresi(g, h) == 1 && khuneMahidar[g][h] == -2) //yani player 2 faqat mitune panguane khodesho taqiir bde va inke nare kashii ke tush panguan nis ya hazf shde ro entekhab kne!
                {
                    printf("where do you want to go?(at the first enter the row and then column:)");
                    scanf("%d %d", &f, &c);
                    if (baresi(f, c) == 1 && khuneMahidar[f][c] > 0 && baresi_masir(g, h, f, c) == 1) //yani ham maqsad mojaz bshe ham masir
                    {
                        sumMahi[1] += khuneMahidar[f][c]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                        khuneMahidar[f][c] = -2;          //panguan bere be khune maqsad
                        khuneMahidar[g][h] = 0;           //kashi mabda hazf she
                    }
                    else
                    { //else agar maqsad ya masir mojaz nabud va masir ham mojaz nabud
                        do
                        {
                            setTextColor(GRAY);
                            printf("%c", 7); //baraye ijade seda
                            printf("<WARNING>This tile is filled by one of your penguins or another. Or not available or this path is unavailable!\nagain player2 where do you want to go?(at the first enter the row and then column:)");
                            setTextColor(WHITE);
                            scanf("%d %d", &f, &c);
                            v = khuneMahidar[f][c];                                                           //meqdar avaliasho hefz mikne
                            if (baresi(f, c) == 1 && khuneMahidar[f][c] > 0 && baresi_masir(g, h, f, c) == 1) ///yani ham maqsad mojaz bshe ham masir
                            {
                                sumMahi[1] += khuneMahidar[f][c]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                                khuneMahidar[f][c] = -2;          //panguan bere be khune maqsad
                                khuneMahidar[g][h] = 0;           //kashi mabda hazf she
                            }
                        } while (baresi(f, c) == 0 || v <= 0 || baresi_masir(g, h, f, c) != 1);
                    }
                }
                else
                { //else agar mabdaa mojaz nbud
                    do
                    {
                        if (k == -1)
                        {
                            break;
                        }
                        else
                        {
                            setTextColor(GRAY);
                            printf("%c", 7); //baraye ijade seda
                            printf("<WARNING>This tile is filled by one of your penguins or another. Or not available\nagain player2 which penguin do you want to move ?(at the first enter the row and then column:");
                            setTextColor(WHITE);
                            scanf("%d %d", &g, &h);
                            w = khuneMahidar[g][h];                            //meqdar avaliasho hefz mikne
                            if (baresi(g, h) == 1 && khuneMahidar[g][h] == -2) //yani player 2 faqat mitune panguane khodesho taqiir bde va inke nare kashii ke tush panguan nis ya hazf shde ro entekhab kne!
                            {
                                printf("where do you want to go?(at the first enter the row and then column:)");
                                scanf("%d %d", &f, &c);
                                if (baresi(f, c) == 1 && khuneMahidar[f][c] > 0 && baresi_masir(g, h, f, c) == 1) //yani ham maqsad mojaz bshe ham masir
                                {
                                    sumMahi[1] += khuneMahidar[f][c]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                                    khuneMahidar[f][c] = -2;          //panguan bere be khune maqsad
                                    khuneMahidar[g][h] = 0;           //kashi mabda hazf she
                                }
                                else
                                { //else agar maqsad ya masir mojaz nabud va masir ham mojaz nabud
                                    do
                                    {
                                        setTextColor(GRAY);
                                        printf("%c", 7); //baraye ijade seda
                                        printf("<WARNING>This tile is filled by one of your penguins or another. Or not available or this path is unavailable!\nagain player2 where do you want to go?(at the first enter the row and then column:)");
                                        setTextColor(WHITE);
                                        scanf("%d %d", &f, &c);
                                        v = khuneMahidar[f][c];                                                           //meqdar avaliasho hefz mikne
                                        if (baresi(f, c) == 1 && khuneMahidar[f][c] > 0 && baresi_masir(g, h, f, c) == 1) ///yani ham maqsad mojaz bshe ham masir
                                        {
                                            sumMahi[1] += khuneMahidar[f][c]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                                            khuneMahidar[f][c] = -2;          //panguan bere be khune maqsad
                                            khuneMahidar[g][h] = 0;           //kashi mabda hazf she
                                        }
                                    } while (baresi(f, c) == 0 || v <= 0 || baresi_masir(g, h, f, c) != 1);
                                }
                            }
                        }

                    } while (baresi(g, h) == 0 || w != -2);
                }
                printf("\n");
                print_gameBoard();
                printf("\n_____________________________________________________________\n");
                printf("| player 1 your score is: %d   \t\t\t\t    |\n| player 2 your score is: %d    \t\t\t\t    |\n| player 3 your score is: %d    \t\t\t\t    |\n|                                   \t\t\t    |\n|", sumMahi[0], sumMahi[1], sumMahi[2]);
                printf("___________________________________________________________|\n\n");
                printf("\n");
                printf("\n");
            }

            if (t <= 3)
            {
                printf("player3 which penguin do you want to move ?(at the first enter the row and then column:)");
                scanf("%d %d", &g, &h);
                while (khuneMahidar[g][h] == -3 && baresi6kashi_doresh(g, h) == 6)
                {
                    t++;
                    if (t == 3)
                    {
                        tt = t;
                        t = 4;
                        k = -1;
                        khuneMahidar[g][h] = 0;
                        setTextColor(GRAY);
                        printf("%c", 7); //baraye ijade seda
                        printf("player 3 all of your penguins are off the screen  and the resault is:\n");

                        setTextColor(WHITE);
                        break;
                    }
                    else
                    {
                        khuneMahidar[g][h] = 0;

                        setTextColor(GRAY);
                        printf("%c", 7); //baraye ijade seda
                        printf("this penguin can not move!please select another penguin!\nagain player3 which penguin do you want to move ?(at the first enter the row and then column:)");
                        setTextColor(WHITE);
                        scanf("%d %d", &g, &h);
                    }
                }
                if (baresi(g, h) == 1 && khuneMahidar[g][h] == -3) //yani player 3 faqat mitune panguane khodesho taqiir bde va inke nare kashii ke tush panguan nis ya hazf shde ro entekhab kne!
                {
                    printf("where do you want to go?(at the first enter the row and then column:)");
                    scanf("%d %d", &f, &c);
                    if (baresi(f, c) == 1 && khuneMahidar[f][c] > 0 && baresi_masir(g, h, f, c) == 1) //yani ham maqsad mojaz bshe ham masir
                    {
                        sumMahi[1] += khuneMahidar[f][c]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                        khuneMahidar[f][c] = -3;          //panguan bere be khune maqsad
                        khuneMahidar[g][h] = 0;           //kashi mabda hazf she
                    }
                    else
                    { //else agar maqsad ya masir mojaz nabud va masir ham mojaz nabud
                        do
                        {
                            setTextColor(GRAY);
                            printf("%c", 7); //baraye ijade seda
                            printf("<WARNING>This tile is filled by one of your penguins or another. Or not available or this path is unavailable!\nagain player3 where do you want to go?(at the first enter the row and then column:)");
                            setTextColor(WHITE);
                            scanf("%d %d", &f, &c);
                            v = khuneMahidar[f][c];                                                           //meqdar avaliasho hefz mikne
                            if (baresi(f, c) == 1 && khuneMahidar[f][c] > 0 && baresi_masir(g, h, f, c) == 1) ///yani ham maqsad mojaz bshe ham masir
                            {
                                sumMahi[1] += khuneMahidar[f][c]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                                khuneMahidar[f][c] = -3;          //panguan bere be khune maqsad
                                khuneMahidar[g][h] = 0;           //kashi mabda hazf she
                            }
                        } while (baresi(f, c) == 0 || v <= 0 || baresi_masir(g, h, f, c) != 1);
                    }
                }
                else
                { //else agar mabdaa mojaz nbud
                    do
                    {
                        if (k == -1)
                        {
                            break;
                        }
                        else
                        {
                            setTextColor(GRAY);
                            printf("%c", 7); //baraye ijade seda
                            printf("<WARNING>This tile is filled by one of your penguins or another. Or not available\nagain player3 which penguin do you want to move ?(at the first enter the row and then column:");
                            setTextColor(WHITE);
                            scanf("%d %d", &g, &h);
                            w = khuneMahidar[g][h];                            //meqdar avaliasho hefz mikne
                            if (baresi(g, h) == 1 && khuneMahidar[g][h] == -3) //yani player 2 faqat mitune panguane khodesho taqiir bde va inke nare kashii ke tush panguan nis ya hazf shde ro entekhab kne!
                            {
                                printf("where do you want to go?(at the first enter the row and then column:)");
                                scanf("%d %d", &f, &c);
                                if (baresi(f, c) == 1 && khuneMahidar[f][c] > 0 && baresi_masir(g, h, f, c) == 1) //yani ham maqsad mojaz bshe ham masir
                                {
                                    sumMahi[1] += khuneMahidar[f][c]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                                    khuneMahidar[f][c] = -3;          //panguan bere be khune maqsad
                                    khuneMahidar[g][h] = 0;           //kashi mabda hazf she
                                }
                                else
                                { //else agar maqsad ya masir mojaz nabud va masir ham mojaz nabud
                                    do
                                    {
                                        setTextColor(GRAY);
                                        printf("%c", 7); //baraye ijade seda
                                        printf("<WARNING>This tile is filled by one of your penguins or another. Or not available or this path is unavailable!\nagain player2 where do you want to go?(at the first enter the row and then column:)");
                                        setTextColor(WHITE);
                                        scanf("%d %d", &f, &c);
                                        v = khuneMahidar[f][c];                                                           //meqdar avaliasho hefz mikne
                                        if (baresi(f, c) == 1 && khuneMahidar[f][c] > 0 && baresi_masir(g, h, f, c) == 1) ///yani ham maqsad mojaz bshe ham masir
                                        {
                                            sumMahi[1] += khuneMahidar[f][c]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                                            khuneMahidar[f][c] = -3;          //panguan bere be khune maqsad
                                            khuneMahidar[g][h] = 0;           //kashi mabda hazf she
                                        }
                                    } while (baresi(f, c) == 0 || v <= 0 || baresi_masir(g, h, f, c) != 1);
                                }
                            }
                        }

                    } while (baresi(g, h) == 0 || w != -3);
                }
            }
            printf("\n");
            print_gameBoard();
            printf("\n_____________________________________________________________\n");
            printf("| player 1 your score is: %d   \t\t\t\t    |\n| player 2 your score is: %d    \t\t\t\t    |\n| player 3 your score is: %d    \t\t\t\t    |\n|                                   \t\t\t    |\n|", sumMahi[0], sumMahi[1], sumMahi[2]);
            printf("___________________________________________________________|\n\n");
            printf("\n");
            printf("\n");
            printf("*******************");
        } while ((ee + qq + tt) != 9);
        print_results(sumMahi, 3); //dige bazi ke tamum she nobate elame barande hast
    }
    else if (n == 4)
    {
        do
        {
            k=0;
			if (e <= 2) //e tedade panguan hayi az player1 ke natunestn harkat konan va z safe bazi hazf shodan
            {
                printf("player1 which penguin do you want to move ?(at the first enter the row and then column:)");
                scanf("%d %d", &g, &h);
                while (khuneMahidar[g][h] == -1 && baresi6kashi_doresh(g, h) == 6)
                {
                    e++;
                    if (e == 2)
                    {
                        ee = e;
                        e = 3;
                        k = -1;
                        khuneMahidar[g][h] = 0;
                        setTextColor(GRAY);
                        printf("%c", 7); //baraye ijade seda
                        printf("player 1 all of your penguins are off the screen Wait for all the player penguins or other players to leave!");

                        setTextColor(WHITE);
                        break;
                    }
                    else
                    {
                        khuneMahidar[g][h] = 0;

                        setTextColor(GRAY);
                        printf("%c", 7); //baraye ijade seda
                        printf("this penguin can not move!please select another penguin!\nagain player1 which penguin do you want to move ?(at the first enter the row and then column:)");
                        setTextColor(WHITE);
                        scanf("%d %d", &g, &h);
                    }
                }
                if (baresi(g, h) == 1 && khuneMahidar[g][h] == -1) //yani player 1 faqat mitune panguane khodesho taqiir bde va inke nare kashii ke tush panguan nis ya hazf shde ro entekhab kne!
                {
                    printf("where do you want to go?(at the first enter the row and then column:)");
                    scanf("%d %d", &f, &c);
                    while (baresi6kashi_doresh(g, h) == 6)
                    {
                        khuneMahidar[g][h] = 0;
                        e++;
                        printf("this penguin can not move!please select another penguin!\nagain player1 which penguin do you want to move ?(at the first enter the row and then column:)");
                        scanf("%d %d", &g, &h);
                    }
                    if (baresi(f, c) == 1 && khuneMahidar[f][c] > 0 && baresi_masir(g, h, f, c) == 1) //yani ham maqsad mojaz bshe ham masir
                    {
                        sumMahi[0] += khuneMahidar[f][c]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                        khuneMahidar[f][c] = -1;          //panguan bere be khune maqsad
                        khuneMahidar[g][h] = 0;           //kashi mabda hazf she
                    }
                    else
                    { //else agar maqsad ya masir mojaz nabud va masir ham mojaz nabud
                        do
                        {
                            setTextColor(GRAY);
                            printf("%c", 7); //baraye ijade seda
                            printf("<WARNING>This tile is filled by one of your penguins or another. Or not available or this path is unavailable!\nagain player1 where do you want to go?(at the first enter the row and then column:)");
                            setTextColor(WHITE);
                            scanf("%d %d", &f, &c);
                            v = khuneMahidar[f][c];                                                           //meqdar avaliasho hefz mikne
                            if (baresi(f, c) == 1 && khuneMahidar[f][c] > 0 && baresi_masir(g, h, f, c) == 1) ///yani ham maqsad mojaz bshe ham masir
                            {
                                sumMahi[0] += khuneMahidar[f][c]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                                khuneMahidar[f][c] = -1;          //panguan bere be khune maqsad
                                khuneMahidar[g][h] = 0;           //kashi mabda hazf she
                            }
                        } while (baresi(f, c) == 0 || v <= 0 || baresi_masir(g, h, f, c) != 1);
                    }
                }
                else
                { //else agar mabdaa mojaz nbud
                    do
                    {
                        if (k == -1)
                        {
                            break;
                        }
                        else
                        {
                            setTextColor(GRAY);
                            printf("%c", 7); //baraye ijade seda
                            printf("<WARNING>This tile is filled by one of your penguins or another. Or not available\nagain player1 which penguin do you want to move ?(at the first enter the row and then column:");
                            setTextColor(WHITE);
                            scanf("%d %d", &g, &h);
                            w = khuneMahidar[g][h];                            //meqdar avaliasho hefz mikne
                            if (baresi(g, h) == 1 && khuneMahidar[g][h] == -1) //yani player 1 faqat mitune panguane khodesho taqiir bde va inke nare kashii ke tush panguan nis ya hazf shde ro entekhab kne!
                            {
                                printf("where do you want to go?(at the first enter the row and then column:)");
                                scanf("%d %d", &f, &c);
                                if (baresi(f, c) == 1 && khuneMahidar[f][c] > 0 && baresi_masir(g, h, f, c) == 1) //yani ham maqsad mojaz bshe ham masir
                                {
                                    sumMahi[0] += khuneMahidar[f][c]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                                    khuneMahidar[f][c] = -1;          //panguan bere be khune maqsad
                                    khuneMahidar[g][h] = 0;           //kashi mabda hazf she
                                }
                                else
                                { //else agar maqsad ya masir mojaz nabud va masir ham mojaz nabud
                                    do
                                    {
                                        setTextColor(GRAY);
                                        printf("%c", 7); //baraye ijade seda
                                        printf("<WARNING>This tile is filled by one of your penguins or another. Or not available or this path is unavailable!\nagain player1 where do you want to go?(at the first enter the row and then column:)");
                                        setTextColor(WHITE);
                                        scanf("%d %d", &f, &c);
                                        v = khuneMahidar[f][c];                                                           //meqdar avaliasho hefz mikne
                                        if (baresi(f, c) == 1 && khuneMahidar[f][c] > 0 && baresi_masir(g, h, f, c) == 1) ///yani ham maqsad mojaz bshe ham masir
                                        {
                                            sumMahi[0] += khuneMahidar[f][c]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                                            khuneMahidar[f][c] = -1;          //panguan bere be khune maqsad
                                            khuneMahidar[g][h] = 0;           //kashi mabda hazf she
                                        }
                                    } while (baresi(f, c) == 0 || v <= 0 || baresi_masir(g, h, f, c) != 1);
                                }
                            }
                        }
                    } while (baresi(g, h) == 0 || w != -1);
                }
                printf("\n");
                print_gameBoard();
                printf("\n_____________________________________________________________\n");
                printf("| player 1 your score is: %d   \t\t\t\t    |\n| player 2 your score is: %d    \t\t\t\t    |\n| player 3 your score is: %d    \t\t\t\t    |\n| player 4 your score is: %d    \t\t\t\t    |\n|", sumMahi[0], sumMahi[1], sumMahi[2], sumMahi[3]);
                printf("___________________________________________________________|\n\n");
                printf("\n");
                printf("\n");
            }

            if (q <= 2) //q tedad panguan haye hazf shodeye player 2 vaqti hamash hazf she dige vamise ta panguanaye bazikonaye dig ham tamom shan va az safe kharej shn
            {
                printf("player2 which penguin do you want to move ?(at the first enter the row and then column:)");
                scanf("%d %d", &g, &h);
                while (khuneMahidar[g][h] == -2 && baresi6kashi_doresh(g, h) == 6)
                {
                    q++;
                    if (q == 2)
                    {
                        qq = q;
                        q = 3;
                        k = -1;
                        khuneMahidar[g][h] = 0;
                        setTextColor(GRAY);
                        printf("%c", 7); //baraye ijade seda
                        printf("player 2 all of your penguins are off the screen Wait for all the player penguins or other players to leave!");

                        setTextColor(WHITE);
                        break;
                    }
                    else
                    {
                        khuneMahidar[g][h] = 0;

                        setTextColor(GRAY);
                        printf("%c", 7); //baraye ijade seda
                        printf("this penguin can not move!please select another penguin!\nagain player2 which penguin do you want to move ?(at the first enter the row and then column:)");
                        setTextColor(WHITE);
                        scanf("%d %d", &g, &h);
                    }
                }
                if (baresi(g, h) == 1 && khuneMahidar[g][h] == -2) //yani player 2 faqat mitune panguane khodesho taqiir bde va inke nare kashii ke tush panguan nis ya hazf shde ro entekhab kne!
                {
                    printf("where do you want to go?(at the first enter the row and then column:)");
                    scanf("%d %d", &f, &c);
                    if (baresi(f, c) == 1 && khuneMahidar[f][c] > 0 && baresi_masir(g, h, f, c) == 1) //yani ham maqsad mojaz bshe ham masir
                    {
                        sumMahi[1] += khuneMahidar[f][c]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                        khuneMahidar[f][c] = -2;          //panguan bere be khune maqsad
                        khuneMahidar[g][h] = 0;           //kashi mabda hazf she
                    }
                    else
                    { //else agar maqsad ya masir mojaz nabud va masir ham mojaz nabud
                        do
                        {
                            setTextColor(GRAY);
                            printf("%c", 7); //baraye ijade seda
                            printf("<WARNING>This tile is filled by one of your penguins or another. Or not available or this path is unavailable!\nagain player2 where do you want to go?(at the first enter the row and then column:)");
                            setTextColor(WHITE);
                            scanf("%d %d", &f, &c);
                            v = khuneMahidar[f][c];                                                           //meqdar avaliasho hefz mikne
                            if (baresi(f, c) == 1 && khuneMahidar[f][c] > 0 && baresi_masir(g, h, f, c) == 1) ///yani ham maqsad mojaz bshe ham masir
                            {
                                sumMahi[1] += khuneMahidar[f][c]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                                khuneMahidar[f][c] = -2;          //panguan bere be khune maqsad
                                khuneMahidar[g][h] = 0;           //kashi mabda hazf she
                            }
                        } while (baresi(f, c) == 0 || v <= 0 || baresi_masir(g, h, f, c) != 1);
                    }
                }
                else
                { //else agar mabdaa mojaz nbud
                    do
                    {
                        if (k == -1)
                        {
                            break;
                        }
                        else
                        {
                            setTextColor(GRAY);
                            printf("%c", 7); //baraye ijade seda
                            printf("<WARNING>This tile is filled by one of your penguins or another. Or not available\nagain player2 which penguin do you want to move ?(at the first enter the row and then column:");
                            setTextColor(WHITE);
                            scanf("%d %d", &g, &h);
                            w = khuneMahidar[g][h];                            //meqdar avaliasho hefz mikne
                            if (baresi(g, h) == 1 && khuneMahidar[g][h] == -2) //yani player 2 faqat mitune panguane khodesho taqiir bde va inke nare kashii ke tush panguan nis ya hazf shde ro entekhab kne!
                            {
                                printf("where do you want to go?(at the first enter the row and then column:)");
                                scanf("%d %d", &f, &c);
                                if (baresi(f, c) == 1 && khuneMahidar[f][c] > 0 && baresi_masir(g, h, f, c) == 1) //yani ham maqsad mojaz bshe ham masir
                                {
                                    sumMahi[1] += khuneMahidar[f][c]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                                    khuneMahidar[f][c] = -2;          //panguan bere be khune maqsad
                                    khuneMahidar[g][h] = 0;           //kashi mabda hazf she
                                }
                                else
                                { //else agar maqsad ya masir mojaz nabud va masir ham mojaz nabud
                                    do
                                    {
                                        setTextColor(GRAY);
                                        printf("%c", 7); //baraye ijade seda
                                        printf("<WARNING>This tile is filled by one of your penguins or another. Or not available or this path is unavailable!\nagain player2 where do you want to go?(at the first enter the row and then column:)");
                                        setTextColor(WHITE);
                                        scanf("%d %d", &f, &c);
                                        v = khuneMahidar[f][c];                                                           //meqdar avaliasho hefz mikne
                                        if (baresi(f, c) == 1 && khuneMahidar[f][c] > 0 && baresi_masir(g, h, f, c) == 1) ///yani ham maqsad mojaz bshe ham masir
                                        {
                                            sumMahi[1] += khuneMahidar[f][c]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                                            khuneMahidar[f][c] = -2;          //panguan bere be khune maqsad
                                            khuneMahidar[g][h] = 0;           //kashi mabda hazf she
                                        }
                                    } while (baresi(f, c) == 0 || v <= 0 || baresi_masir(g, h, f, c) != 1);
                                }
                            }
                        }
                    } while (baresi(g, h) == 0 || w != -2);
                }
                printf("\n");
                print_gameBoard();
                printf("\n_____________________________________________________________\n");
                printf("| player 1 your score is: %d   \t\t\t\t    |\n| player 2 your score is: %d    \t\t\t\t    |\n| player 3 your score is: %d    \t\t\t\t    |\n| player 4 your score is: %d    \t\t\t\t    |\n|", sumMahi[0], sumMahi[1], sumMahi[2], sumMahi[3]);
                printf("___________________________________________________________|\n\n");
                printf("\n");
                printf("\n");
            }

            if (t <= 2) //t tedade panguanaye hazf shodeye player 3
            {
                printf("player3 which penguin do you want to move ?(at the first enter the row and then column:)");
                scanf("%d %d", &g, &h);
                while (khuneMahidar[g][h] == -3 && baresi6kashi_doresh(g, h) == 6)
                {
                    t++;
                    if (t == 2)
                    {
                        tt = t;
                        t = 3;
                        k = -1;
                        khuneMahidar[g][h] = 0;
                        setTextColor(GRAY);
                        printf("%c", 7); //baraye ijade seda
                        printf("player 3 all of your penguins are off the screen Wait for all the player penguins or other players to leave!");

                        setTextColor(WHITE);
                        break;
                    }
                    else
                    {
                        khuneMahidar[g][h] = 0;

                        setTextColor(GRAY);
                        printf("%c", 7); //baraye ijade seda
                        printf("this penguin can not move!please select another penguin!\nagain player3 which penguin do you want to move ?(at the first enter the row and then column:)");
                        setTextColor(WHITE);
                        scanf("%d %d", &g, &h);
                    }
                }
                if (baresi(g, h) == 1 && khuneMahidar[g][h] == -3) //yani player 3 faqat mitune panguane khodesho taqiir bde va inke nare kashii ke tush panguan nis ya hazf shde ro entekhab kne!
                {
                    printf("where do you want to go?(at the first enter the row and then column:)");
                    scanf("%d %d", &f, &c);
                    if (baresi(f, c) == 1 && khuneMahidar[f][c] > 0 && baresi_masir(g, h, f, c) == 1) //yani ham maqsad mojaz bshe ham masir
                    {
                        sumMahi[1] += khuneMahidar[f][c]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                        khuneMahidar[f][c] = -3;          //panguan bere be khune maqsad
                        khuneMahidar[g][h] = 0;           //kashi mabda hazf she
                    }
                    else
                    { //else agar maqsad ya masir mojaz nabud va masir ham mojaz nabud
                        do
                        {
                            setTextColor(GRAY);
                            printf("%c", 7); //baraye ijade seda
                            printf("<WARNING>This tile is filled by one of your penguins or another. Or not available or this path is unavailable!\nagain player3 where do you want to go?(at the first enter the row and then column:)");
                            setTextColor(WHITE);
                            scanf("%d %d", &f, &c);
                            v = khuneMahidar[f][c];                                                           //meqdar avaliasho hefz mikne
                            if (baresi(f, c) == 1 && khuneMahidar[f][c] > 0 && baresi_masir(g, h, f, c) == 1) ///yani ham maqsad mojaz bshe ham masir
                            {
                                sumMahi[1] += khuneMahidar[f][c]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                                khuneMahidar[f][c] = -3;          //panguan bere be khune maqsad
                                khuneMahidar[g][h] = 0;           //kashi mabda hazf she
                            }
                        } while (baresi(f, c) == 0 || v <= 0 || baresi_masir(g, h, f, c) != 1);
                    }
                }
                else
                { //else agar mabdaa mojaz nbud
                    do
                    {
                        if (k == -1)
                        {
                            break;
                        }
                        else
                        {
                            setTextColor(GRAY);
                            printf("%c", 7); //baraye ijade seda
                            printf("<WARNING>This tile is filled by one of your penguins or another. Or not available\nagain player3 which penguin do you want to move ?(at the first enter the row and then column:");
                            setTextColor(WHITE);
                            scanf("%d %d", &g, &h);
                            w = khuneMahidar[g][h];                            //meqdar avaliasho hefz mikne
                            if (baresi(g, h) == 1 && khuneMahidar[g][h] == -3) //yani player 2 faqat mitune panguane khodesho taqiir bde va inke nare kashii ke tush panguan nis ya hazf shde ro entekhab kne!
                            {
                                printf("where do you want to go?(at the first enter the row and then column:)");
                                scanf("%d %d", &f, &c);
                                if (baresi(f, c) == 1 && khuneMahidar[f][c] > 0 && baresi_masir(g, h, f, c) == 1) //yani ham maqsad mojaz bshe ham masir
                                {
                                    sumMahi[1] += khuneMahidar[f][c]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                                    khuneMahidar[f][c] = -3;          //panguan bere be khune maqsad
                                    khuneMahidar[g][h] = 0;           //kashi mabda hazf she
                                }
                                else
                                { //else agar maqsad ya masir mojaz nabud va masir ham mojaz nabud
                                    do
                                    {
                                        setTextColor(GRAY);
                                        printf("%c", 7); //baraye ijade seda
                                        printf("<WARNING>This tile is filled by one of your penguins or another. Or not available or this path is unavailable!\nagain player2 where do you want to go?(at the first enter the row and then column:)");
                                        setTextColor(WHITE);
                                        scanf("%d %d", &f, &c);
                                        v = khuneMahidar[f][c];                                                           //meqdar avaliasho hefz mikne
                                        if (baresi(f, c) == 1 && khuneMahidar[f][c] > 0 && baresi_masir(g, h, f, c) == 1) ///yani ham maqsad mojaz bshe ham masir
                                        {
                                            sumMahi[1] += khuneMahidar[f][c]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                                            khuneMahidar[f][c] = -3;          //panguan bere be khune maqsad
                                            khuneMahidar[g][h] = 0;           //kashi mabda hazf she
                                        }
                                    } while (baresi(f, c) == 0 || v <= 0 || baresi_masir(g, h, f, c) != 1);
                                }
                            }
                        }

                    } while (baresi(g, h) == 0 || w != -3);
                }
                printf("\n");
                print_gameBoard();
                printf("\n_____________________________________________________________\n");
                printf("| player 1 your score is: %d   \t\t\t\t    |\n| player 2 your score is: %d    \t\t\t\t    |\n| player 3 your score is: %d    \t\t\t\t    |\n| player 4 your score is: %d    \t\t\t\t    |\n|", sumMahi[0], sumMahi[1], sumMahi[2], sumMahi[3]);
                printf("___________________________________________________________|\n\n");
                printf("\n");
                printf("\n");
            }

            if (d <= 2) //d = tedade panguan haye hazf shdeye player 4
            {
                printf("player4 which penguin do you want to move ?(at the first enter the row and then column:)");
                scanf("%d %d", &g, &h);
                while (khuneMahidar[g][h] == -4 && baresi6kashi_doresh(g, h) == 6)
                {
                    d++;
                    if (d == 2)
                    {

                        dd = d;
                        d = 3;
                        k = -1;
                        khuneMahidar[g][h] = 0;
                        setTextColor(GRAY);
                        printf("%c", 7); //baraye ijade seda
                        printf("player 4 all of your penguins are off the screen  and the resault is:\n");

                        setTextColor(WHITE);
                        break;
                    }
                    else
                    {
                        khuneMahidar[g][h] = 0;

                        setTextColor(GRAY);
                        printf("%c", 7); //baraye ijade seda
                        printf("this penguin can not move!please select another penguin!\nagain player4 which penguin do you want to move ?(at the first enter the row and then column:)");
                        setTextColor(WHITE);
                        scanf("%d %d", &g, &h);
                    }
                }
                if (baresi(g, h) == 1 && khuneMahidar[g][h] == -4) //yani player 4 faqat mitune panguane khodesho taqiir bde va inke nare kashii ke tush panguan nis ya hazf shde ro entekhab kne!
                {
                    printf("where do you want to go?(at the first enter the row and then column:)");
                    scanf("%d %d", &f, &c);
                    if (baresi(f, c) == 1 && khuneMahidar[f][c] > 0 && baresi_masir(g, h, f, c) == 1) //yani ham maqsad mojaz bshe ham masir
                    {
                        sumMahi[1] += khuneMahidar[f][c]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                        khuneMahidar[f][c] = -4;          //panguan bere be khune maqsad
                        khuneMahidar[g][h] = 0;           //kashi mabda hazf she
                    }
                    else
                    { //else agar maqsad ya masir mojaz nabud va masir ham mojaz nabud
                        do
                        {
                            setTextColor(GRAY);
                            printf("%c", 7); //baraye ijade seda
                            printf("<WARNING>This tile is filled by one of your penguins or another. Or not available or this path is unavailable!\nagain player4 where do you want to go?(at the first enter the row and then column:)");
                            setTextColor(WHITE);
                            scanf("%d %d", &f, &c);
                            v = khuneMahidar[f][c];                                                           //meqdar avaliasho hefz mikne
                            if (baresi(f, c) == 1 && khuneMahidar[f][c] > 0 && baresi_masir(g, h, f, c) == 1) ///yani ham maqsad mojaz bshe ham masir
                            {
                                sumMahi[1] += khuneMahidar[f][c]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                                khuneMahidar[f][c] = -4;          //panguan bere be khune maqsad
                                khuneMahidar[g][h] = 0;           //kashi mabda hazf she
                            }
                        } while (baresi(f, c) == 0 || v <= 0 || baresi_masir(g, h, f, c) != 1);
                    }
                }
                else
                { //else agar mabdaa mojaz nbud
                    do
                    {
                        if (k == -1)
                        {
                            break;
                        }
                        else
                        {
                            setTextColor(GRAY);
                            printf("%c", 7); //baraye ijade seda
                            printf("<WARNING>This tile is filled by one of your penguins or another. Or not available\nagain player4 which penguin do you want to move ?(at the first enter the row and then column:");
                            setTextColor(WHITE);
                            scanf("%d %d", &g, &h);
                            w = khuneMahidar[g][h];                            //meqdar avaliasho hefz mikne
                            if (baresi(g, h) == 1 && khuneMahidar[g][h] == -4) //yani player 4 faqat mitune panguane khodesho taqiir bde va inke nare kashii ke tush panguan nis ya hazf shde ro entekhab kne!
                            {
                                printf("where do you want to go?(at the first enter the row and then column:)");
                                scanf("%d %d", &f, &c);
                                if (baresi(f, c) == 1 && khuneMahidar[f][c] > 0 && baresi_masir(g, h, f, c) == 1) //yani ham maqsad mojaz bshe ham masir
                                {
                                    sumMahi[1] += khuneMahidar[f][c]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                                    khuneMahidar[f][c] = -4;          //panguan bere be khune maqsad
                                    khuneMahidar[g][h] = 0;           //kashi mabda hazf she
                                }
                                else
                                { //else agar maqsad ya masir mojaz nabud va masir ham mojaz nabud
                                    do
                                    {
                                        setTextColor(GRAY);
                                        printf("%c", 7); //baraye ijade seda
                                        printf("<WARNING>This tile is filled by one of your penguins or another. Or not available or this path is unavailable!\nagain player4 where do you want to go?(at the first enter the row and then column:)");
                                        setTextColor(WHITE);
                                        scanf("%d %d", &f, &c);
                                        v = khuneMahidar[f][c];                                                           //meqdar avaliasho hefz mikne
                                        if (baresi(f, c) == 1 && khuneMahidar[f][c] > 0 && baresi_masir(g, h, f, c) == 1) ///yani ham maqsad mojaz bshe ham masir
                                        {
                                            sumMahi[1] += khuneMahidar[f][c]; //0=yani bazikonq1 va i =0 yani avalin panguane in bazikon
                                            khuneMahidar[f][c] = -4;          //panguan bere be khune maqsad
                                            khuneMahidar[g][h] = 0;           //kashi mabda hazf she
                                        }
                                    } while (baresi(f, c) == 0 || v <= 0 || baresi_masir(g, h, f, c) != 1);
                                }
                            }
                        }

                    } while (baresi(g, h) == 0 || w != -4);
                }
            }
            printf("\n");
            print_gameBoard();
            printf("\n_____________________________________________________________\n");
            printf("| player 1 your score is: %d   \t\t\t\t    |\n| player 2 your score is: %d    \t\t\t\t    |\n| player 3 your score is: %d    \t\t\t\t    |\n| player 4 your score is: %d    \t\t\t\t    |\n|", sumMahi[0], sumMahi[1], sumMahi[2], sumMahi[3]);
            printf("___________________________________________________________|\n\n");
            printf("\n");
            printf("\n");
            printf("*******************");
        } while ((ee + qq + tt + dd) != 8); //sharte payane bazi vaqti hame pamhuana az safe bardashte shan dige bazi tamume dg!
        print_results(sumMahi, n);          //dige bazi ke tamum she nobate elame barande hast//dar har marhale pas az payane bazi tabe  print_results(sumMahi[4]) ra farakhani mi konim
    }
    return 0;
} //end of main function
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int baresi(int a, int b) //tabe barresi espace va dar kadr bodan
{
    if ((a % 2 == 0) && (a >= 0 && a <= 7))
    {
        if ((b % 2 != 0) || (b <= 0 || b >= 16))
            return 0;
        else
            return 1;
    }
    else if ((a % 2 != 0) && (a >= 0 && a <= 7))
    {
        if ((b % 2 == 0) || (b <= 0 || b >= 16))
            return 0;
        else
            return 1;
    }
    else
    {
        return 0;
    }
} //end of barasi function
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int baresi_masir(int g, int h, int f, int c) //tabei ke barresi miknd masir mojaz hast ya na
{
    int o;
    int i, j;
    int s = 0;  //tedade khune haye beine mabda maqsad ro ke mojazan yani 0 ya manfi nistan ro mishmre!
    int u;      //khune haye beine mabda maqsad ro mishmre kollan
                //u ro chetor mohasebe knm?
    if (g == f) // age khune mabdaa va maghsad har do dar yek radif budan
    {

        o = g;                   //radif ro negah midarim!
        if (abs(h - c) % 2 == 0) // yani masir rast o jap
        {
            u = mohasebe_U(g, h, f, c);
            if (c > h) // khune mabdaa chaptare
            {
                for (i = h + 2; i < c; i += 2) //be khune mabdaa maqsad kar ndrimm // ishomarande sotune dar inja
                {
                    if (khuneMahidar[o][i] > 0) //yani 0 nbshee kashi hazf nshde bshe va manfi nbshe yani panguan sar rahesh nbshe
                    {
                        s++;
                    }
                }
                if (s == u)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else if (h > c) //mabda jolotare
            {
                for (i = h - 2; i > c; i -= 2) //be khune mabdaa maqsad kar ndrimm
                {
                    if (khuneMahidar[o][i] > 0) //yani 0 nbshee kashi hazf nshde bshe va manfi nbshe yani panguan sar rahesh nbshe
                    {
                        s++;
                    }
                }
                if (s == u)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
        else
        {
            return 0;
        }
    }
    else if (abs(g - f) == abs(h - c)) //yani masire zarbdari
    {
        u = mohasebe_U(g, h, f, c);
        if (c > h) // khune mabdaa chaptare
        {
            //i shomarande sotun va j shomarand esatr
            if (f < g) //
            {
                for (i = h + 1, j = g - 1; i < c && j > f; i++, j--)
                {
                    if (khuneMahidar[j][i] > 0) //yani 0 nbshee kashi hazf nshde bshe va manfi nbshe yani panguan sar rahesh nbshe
                    {
                        s++;
                    }
                }
                if (s == u)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else if (g < f) //khune mabda paiin tare
            {
                for (i = h + 1, j = g + 1; i < c && j < f; i++, j++)
                {
                    if (khuneMahidar[j][i] > 0) //yani 0 nbshee kashi hazf nshde bshe va manfi nbshe yani panguan sar rahesh nbshe
                    {
                        s++;
                    }
                }
                if (s == u)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
        else if (h > c) //khune mabdaa aqab tare
        {
            //i shomarande sotun va j shomarand esatr
            if (f < g) //khune mabda balatare
            {
                for (i = h - 1, j = g - 1; i > c && j > f; i--, j--)
                {
                    if (khuneMahidar[j][i] > 0) //yani 0 nbshee kashi hazf nshde bshe va manfi nbshe yani panguan sar rahesh nbshe
                    {
                        s++;
                    }
                }
                if (s == u)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else if (f > g) //khune mabda paiin tare
            {
                for (i = h - 1, j = g + 1; i > c && j < f; i--, j++)
                {
                    if (khuneMahidar[j][i] > 0) //yani 0 nbshee kashi hazf nshde bshe va manfi nbshe yani panguan sar rahesh nbshe
                    {
                        s++;
                    }
                }
                if (s == u)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    else
    {
        return 0;
    }
} // end of baresi_masir function
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int mohasebe_U(int g, int h, int f, int c)
{
    int u = 0;
    int i, j; //i shomarande sutun   j shomarandeye satre
    if (g == f)
    {
        int o;
        o = g;
        u = 0;
        if (c > h) // khune mabdaa chaptare
        {
            for (i = h + 2; i < c; i += 2)
            {
                if (baresi(o, i) == 1)
                {
                    u++;
                }
            }
        }
        else if (h > c) //khune mabda rast tare
        {
            for (i = h - 2; i > c; i -= 2)
            {
                if (baresi(o, i) == 1)
                {
                    u++;
                }
            }
        }
    }
    else if (abs(g - f) == abs(h - c))
    {
        if (c > h) // khune maqsad rast tare
        {
            if (f < g) // khune maqsad balatare
            {
                for (i = h + 1, j = g - 1; i < c && j > f; i++, j--)
                {
                    if (baresi(j, i) == 1)
                    {
                        u++;
                    }
                }
            }
            else if (f > g) //khune maqsad paintare
            {
                for (i = h + 1, j = g + 1; i < c && j < f; i++, j++)
                {
                    if (baresi(j, i) == 1)
                    {
                        u++;
                    }
                }
            }
        }
        else if (h > c) // khune maqsad chaptare
        {
            if (f < g) //khune maqsad balatare
            {
                for (i = h - 1, j = g - 1; i > c && j > f; i--, j--)
                {
                    if (baresi(j, i) == 1)
                    {
                        u++;
                    }
                }
            }
            else if (g < f) //khune maqsad paintare
            {
                for (i = h - 1, j = g + 1; i > c && j < f; i--, j++)
                {
                    if (baresi(j, i) == 1)
                    {
                        u++;
                    }
                }
            }
        }
    }
    else
    {
        return 0;
    }
    return u;
} // end of mohasebe_U function
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void print_results(int sumMahi[], int n)
{
    printf("\n");
	int i, win;
    for (i = 0; i < n; i++)
    {
        setTextColor(LIGHT_RED);
        printf("player %d your score is : %d\n", i + 1, sumMahi[i]);
    }
    int max;
    max = sumMahi[0];
    for (i = 0; i < n; i++)
    {
        if (sumMahi[i] >= max)
        {
            max = sumMahi[i];
            win = i;
        }
    }
    setTextColor(AQUA);
    printf("\n**********player%d you are the winner!!!**********", win + 1);
    setTextColor(WHITE);
}//end of print_results function

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void print_gameBoard()
{
    setTextColor(LIGHT_YELLOW);
    printf("column:\t 0     1    2    3    4    5    6    7    8    9    10   11   12   13   14   15\n\n");
    int i, j;
    for (i = 0; i < 8; i++) // print playbord kham ke tedad mahi malume faqat
    {
        setTextColor(LIGHT_YELLOW);
        printf("row=%d-->", i);
        setTextColor(WHITE);
        printf("|");
        for (j = 0; j < 16; j++)
        {
            if (khuneMahidar[i][j] == 0)
            {
                printf("    |");
            }

            else if (khuneMahidar[i][j] == -1)
            {
                setTextColor(RED);
                printf(" #  ");
                setTextColor(WHITE);
                printf("|");
            }
            else if (khuneMahidar[i][j] == -2)
            {
                setTextColor(PURPLE);
                printf(" @  ");
                setTextColor(WHITE);
                printf("|");
            }
            else if (khuneMahidar[i][j] == -3)
            {
                setTextColor(LIGHT_GREEN);
                printf(" =  ");
                setTextColor(WHITE);
                printf("|");
            }
            else if (khuneMahidar[i][j] == -4)
            {
                setTextColor(LIGHT_BLUE);
                printf(" +  ");
                setTextColor(WHITE);
                printf("|");
            }
            else
            {
                printf(" %d  |", khuneMahidar[i][j]);
            }
        }
        printf("\n_________________________________________________________________________________________\n");
    }
} // end of print_gameBoard function

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int baresi6kashi_doresh(int g, int h) //vorodi ke miad be in tabe bayad mokhtasate mabda panguin bshe
{
    int l = 0; //l shomarande tedad kashi haye hazf shde ya por shde dore panguane
    if (khuneMahidar[g][h + 2] <= 0 || baresi(g, h+2) == 0)
    {
        l++;
    }
    if (khuneMahidar[g][h - 2] <= 0 || baresi(g, h-2) == 0)
    {
        l++;
    }
    if (khuneMahidar[g - 1][h + 1] <= 0 || baresi(g-1, h+1) == 0) //bala rast
    {
        l++;
    }
    if (khuneMahidar[g + 1][h + 1] <= 0 || baresi(g+1, h+1) == 0) // pain rast
    {
        l++;
    }
    if (khuneMahidar[g - 1][h - 1] <= 0 || baresi(g-1, h-1) == 0) //bala chap
    {
        l++;
    }
    if (khuneMahidar[g + 1][h - 1] <= 0 || baresi(g+1, h-1) == 0) //pain chap
    {
        l++;
    }
    return l;
}//end of  baresi6kashi_doresh function
//agar khorooji in tabe 6 bashee yani in panguan ro nemitune harkat bede