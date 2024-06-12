import java.util.*;

public class Game {
    static Scanner input = new Scanner(System.in);
    static Random rand = new Random();
    public static int n = input.nextInt();
    public static final int m = n;
    public static int[][] q = new int[21][21];
    public static int[][] p = new int[21][21];
    public static int emtiaz1 = 2 * n, emtiaz2 = 2 * n;

    public static void GameBoardb1(int n) {
        int i, j;
        System.out.print("   ");
        if (n > 14) {
            for (i = 0; i < 9; i++) {
                System.out.print(i + 1 + "  ");
            }
            for (i = 9; i < n; i++) {
                System.out.print(i + 1 + " ");
            }

        }
        System.out.print("\n");
        if (n > 14) {
            for (i = 0; i < 9; i++) {
                System.out.print(i + 1);
                for (j = 0; j < n; j++) {
                    if (q[i][j] == -1) {
                        System.out.print("  " + "x");
                    } else if (q[i][j] == -2) {
                        System.out.print("  " + "*");
                    } else if (q[i][j] == -3) {
                        System.out.print("  " + "+");
                    } else {
                        System.out.print("  " + ".");
                    }
                }
                System.out.print("\n");
            }
            for (i = 9; i < n; i++) {
                System.out.print(i + 1 + " ");
                for (j = 0; j < n; j++) {
                    if (q[i][j] == -1) {
                        System.out.print("x  ");
                    } else if (q[i][j] == -2) {
                        System.out.print("*  ");
                    } else if (q[i][j] == -3) {
                        System.out.print("+  ");
                    } else {
                        System.out.print(".  ");
                    }

                }
                System.out.print("\n");
            }
        }
        /************************************************************** */
        System.out.println("next map!");
        System.out.print("   ");
        if (n > 14) {
            for (i = 0; i < 9; i++) {
                System.out.print(i + 1 + "  ");
            }
            for (i = 9; i < n; i++) {
                System.out.print(i + 1 + " ");
            }

        }
        System.out.print("\n");
        if (n > 14) {
            for (i = 0; i < 9; i++) {
                System.out.print(i + 1);
                for (j = 0; j < n; j++) {
                    if (p[i][j] == -2) {
                        System.out.print("  " + "*");
                    } else if (p[i][j] == -3) {
                        System.out.print("  " + "+");
                    } else {
                        System.out.print("  " + ".");
                    }
                }
                System.out.print("\n");
            }
            for (i = 9; i < n; i++) {
                System.out.print(i + 1 + " ");
                for (j = 0; j < n; j++) {
                    if (p[i][j] == -2) {
                        System.out.print("*  ");
                    } else if (p[i][j] == -3) {
                        System.out.print("+  ");
                    } else {
                        System.out.print(".  ");
                    }
                }
                System.out.print("\n");
            }
        }
    }

    /***************************************************************************************************** */
    public static  void GameBoardb2(int n) {
        int i, j;
        System.out.print("   ");
        if (n > 14) {
            for (i = 0; i < 9; i++) {
                System.out.print(i + 1 + "  ");
            }
            for (i = 9; i < n; i++) {
                System.out.print(i + 1 + " ");
            }

        }
        System.out.print("\n");
        if (n > 14) {
            for (i = 0; i < 9; i++) {
                System.out.print(i + 1);
                for (j = 0; j < n; j++) {
                    if (p[i][j] == -1) {
                        System.out.print("  " + "x");
                    } else if (p[i][j] == -2) {
                        System.out.print("  " + "*");
                    } else if (p[i][j] == -3) {
                        System.out.print("  " + "+");
                    } else {
                        System.out.print("  " + ".");
                    }
                }
                System.out.print("\n");
            }
            for (i = 9; i < n; i++) {
                System.out.print(i + 1 + " ");
                for (j = 0; j < n; j++) {
                    if (p[i][j] == -1) {
                        System.out.print("x  ");
                    } else if (p[i][j] == -2) {
                        System.out.print("*  ");
                    } else if (p[i][j] == -3) {
                        System.out.print("+  ");
                    } else {
                        System.out.print(".  ");
                    }
                }
                System.out.print("\n");
            }
        }

        /*************************************************/
        System.out.println("next map!");
        System.out.print("   ");
        if (n > 14) {
            for (i = 0; i < 9; i++) {
                System.out.print(i + 1 + "  ");
            }
            for (i = 9; i < n; i++) {
                System.out.print(i + 1 + " ");
            }

        }
        System.out.print("\n");
        if (n > 14) {
            for (i = 0; i < 9; i++) {
                System.out.print(i + 1);
                for (j = 0; j < n; j++) {
                    if (q[i][j] == -2) {
                        System.out.print("  " + "*");
                    } else if (q[i][j] == -3) {
                        System.out.print("  " + "+");
                    } else {
                        System.out.print("  " + ".");
                    }
                }
                System.out.print("\n");
            }
            for (i = 9; i < n; i++) {
                System.out.print(i + 1 + " ");
                for (j = 0; j < n; j++) {
                    if (q[i][j] == -2) {
                        System.out.print("*  ");
                    } else if (q[i][j] == -3) {
                        System.out.print("+  ");
                    } else {
                        System.out.print(".  ");
                    }

                }
                System.out.print("\n");
            }
        }

    }

    /************************************************************************************************************** */

    public static void GameBoard(int n) {
        int i, j;

        System.out.print("   ");
        if (n > 14) {
            for (i = 0; i < 9; i++) {
                System.out.print(i + 1 + "  ");
            }
            for (i = 9; i < n; i++) {
                System.out.print(i + 1 + " ");
            }

        }
        System.out.print("\n");
        if (n > 14) {
            for (i = 0; i < 9; i++) {
                System.out.print(i + 1);
                for (j = 0; j < n; j++) {
                    if (q[i][j] == -1) {
                        System.out.print("  " + "x");
                    } else if (q[i][j] == -2) {
                        System.out.print("  " + "*");
                    } else if (q[i][j] == -3) {
                        System.out.print("  " + "+");
                    } else {
                        System.out.print("  " + ".");
                    }
                }
                System.out.print("\n");
            }
            for (i = 9; i < n; i++) {
                System.out.print(i + 1 + " ");
                for (j = 0; j < n; j++) {
                    if (q[i][j] == -1) {
                        System.out.print("x  ");
                    } else if (q[i][j] == -2) {
                        System.out.print("*  ");
                    } else if (q[i][j] == -3) {
                        System.out.print("+  ");
                    } else {
                        System.out.print(".  ");
                    }

                }
                System.out.print("\n");
            }
        }
        /*************************************************/
        System.out.println("next map!");
        System.out.print("   ");
        if (n > 14) {
            for (i = 0; i < 9; i++) {
                System.out.print(i + 1 + "  ");
            }
            for (i = 9; i < n; i++) {
                System.out.print(i + 1 + " ");
            }

        }
        System.out.print("\n");
        if (n > 14) {
            for (i = 0; i < 9; i++) {
                System.out.print(i + 1);
                for (j = 0; j < n; j++) {
                    if (p[i][j] == -1) {
                        System.out.print("  " + "x");
                    } else if (p[i][j] == -2) {
                        System.out.print("  " + "*");
                    } else if (p[i][j] == -3) {
                        System.out.print("  " + "+");
                    } else {
                        System.out.print("  " + ".");
                    }
                }
                System.out.print("\n");
            }
            for (i = 9; i < n; i++) {
                System.out.print(i + 1 + " ");
                for (j = 0; j < n; j++) {
                    if (p[i][j] == -1) {
                        System.out.print("x  ");
                    } else if (p[i][j] == -2) {
                        System.out.print("*  ");
                    } else if (p[i][j] == -3) {
                        System.out.print("+  ");
                    } else {
                        System.out.print(".  ");
                    }
                }
                System.out.print("\n");
            }
        }
    }

    public static void shelik2b1(int shelik, int i, int j) {
        i = i - 1;
        j = j - 1;
        if (shelik == 1) {
            emtiaz1 -= 1;
            if (p[i][j] == -1) {
                emtiaz1 += 1;
                p[i][j] = -3;
            } else {
                p[i][j] = -2;
            }
        } else if (shelik == 2) {
            emtiaz1 -= 7;
            if (p[i][j - 1] == -1) {
                emtiaz1 += 1;
                p[i][j - 1] = -3;
            } else {
                p[i][j - 1] = -2;
            }
            if (p[i - 1][j] == -1) {
                emtiaz1 += 1;
                p[i - 1][j] = -3;
            } else {
                p[i - 1][j] = -2;
            }
            if (p[i][j] == -1) {
                emtiaz1 += 1;
                p[i][j] = -3;
            } else {
                p[i][j] = -2;
            }
            if (p[i + 1][j] == -1) {
                emtiaz1 += 1;
                p[i + 1][j] = -3;
            } else {
                p[i + 1][j] = -2;
            }
            if (p[i][j + 1] == -1) {
                emtiaz1 += 1;
                p[i][j + 1] = -3;
            } else {
                p[i][j + 1] = -2;
            }

        }
    }

    public static void shelik2b2(int shelik, int i, int j) {
        i = i - 1;
        j = j - 1;
        if (shelik == 1) {
            emtiaz2 -= 1;
            if (q[i][j] == -1) {
                emtiaz2 += 1;
                q[i][j] = -3;
            } else {
                q[i][j] = -2;
            }
        } else {
            emtiaz2 -= 7;
            if (q[i][j] == -1) {
                emtiaz2 += 1;
                q[i][j] = -3;
            } else {
                q[i][j] = -2;
            }
            if (q[i + 1][j] == -1) {
                emtiaz2 += 1;
                q[i + 1][j] = -3;
            } else {
                q[i + 1][j] = -2;
            }
            if (q[i - 1][j] == -1) {
                emtiaz2 += 1;
                q[i - 1][j] = -3;
            } else {
                q[i - 1][j] = -2;
            }
            if (q[i][j + 1] == -1) {
                emtiaz2 += 1;
                q[i][j + 1] = -3;
            } else {
                q[i][j + 1] = -2;
            }
            if (q[i][j - 1] == -1) {
                emtiaz2 += 1;
                q[i][j - 1] = -3;
            } else {
                q[i][j - 1] = -2;
            }
        }
    }

    public static int payanb1() {
        int i, j, count = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (q[i][j] == -1) {
                    count = 1;
                }
            }
        }
        if (count == 1) {
            return 0; // edame bazi
        } else {
            return 1; // payan bazi
        }
    }

    public static int payanb2() {
        int i, j, count = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (p[i][j] == -1) {
                    count = 1;
                }
            }
        }
        if (count == 1) {
            return 0; // edame bazi
        } else {
            return 1; // payan bazi
        }
    }

    /************************************************************************************************************************************************** */
    public static void main(String[] args) {
        if (n < 15) {
            System.out.println("n bayad bein 15 ta 20 bashad ");
            while (n < 15 || n > 20) {
                n = input.nextInt();
            }
        }

        GameBoard(n);
        // GameBoardb1(n);
        // GameBoardb2(n);

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        System.out.print("Tedade bazicon:");
        int TedadBazicon = input.nextInt();
        while (TedadBazicon != 1 && TedadBazicon != 2) {
            System.out.print(
                    "Khata!! tedad bayad 1 ya 2 bashad. dobare tedad ra vared konid:\n");
            TedadBazicon = input.nextInt();
        }
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        int a, b, i;
        int ghayegh1x, navche1x, navshekan1x, nav1x;
        int ghayegh1y, navche1y, navshekan1y, nav1y;
        int shelik;

        int jahat;

        if (TedadBazicon == 2) {

            System.out.println("bazicon 1 mokhtasat ghayeghha ra vared konad ebteda x sepas y:");
            for (i = 0; i < 3; i++) {
                ghayegh1x = input.nextInt();
                ghayegh1y = input.nextInt();
                while ((ghayegh1x - 1 >= n || ghayegh1x < 1 || ghayegh1y - 1 >= n || ghayegh1y < 1)) {
                    System.out.println("Khata! mokhtasat sahih vared konid!");
                    ghayegh1x = input.nextInt();
                    ghayegh1y = input.nextInt();
                }

                if (q[ghayegh1x - 1][ghayegh1y - 1] == 0
                        && !(ghayegh1x - 1 >= n || ghayegh1x < 1 || ghayegh1y - 1 >= n || ghayegh1y < 1)) {

                    q[ghayegh1x - 1][ghayegh1y - 1] = -1;
                    GameBoard(n);
                    System.out.printf("\n");
                } else {

                    while (!(q[ghayegh1x - 1][ghayegh1y - 1] == 0)) {
                        System.out.println("Khata! mokhtasat sahih vared konid!");
                        ghayegh1x = input.nextInt();
                        ghayegh1y = input.nextInt();
                    }
                    q[ghayegh1x - 1][ghayegh1y - 1] = -1;
                    GameBoard(n);
                    System.out.printf("\n");
                }
            }
            /*******************************************************************/
            System.out.println(
                    "bazicon 1 mokhtasat navcheha va jahat ra vared konad ebteda x sepas y baray amodi 1 va ofoghi 2:");
            for (i = 0; i < 2; i++) {

                navche1x = input.nextInt();
                navche1y = input.nextInt();
                jahat = input.nextInt();

                if (jahat != 1 && jahat != 2) {
                    while (jahat != 1 && jahat != 2) {
                        System.out.println("jahat 1 ya 2 ast ");
                        jahat = input.nextInt();
                    }
                }
                if (jahat == 1) {
                    while (!((navche1y - 1 >= 0 && navche1y - 1 <= n - 1)
                            && (navche1x - 1 <= n - 1 && navche1x - 3 >= 0))) {
                        System.out.println("Khata! mokhtasat sahih vared konid.");
                        navche1x = input.nextInt();
                        navche1y = input.nextInt();
                    }
                    while (!(q[navche1x - 1][navche1y - 1] == 0 && q[navche1x - 2][navche1y - 1] == 0
                            && q[navche1x - 3][navche1y - 1] == 0)) {
                        System.out.println("Khata! mokhtasat sahih vared konid.");
                        navche1x = input.nextInt();
                        navche1y = input.nextInt();
                    }
                    q[navche1x - 1][navche1y - 1] = -1;
                    q[navche1x - 2][navche1y - 1] = -1;
                    q[navche1x - 3][navche1y - 1] = -1;
                    GameBoard(n);
                    System.out.printf("\n");
                }
                if (jahat == 2) {
                    while (!((navche1x - 1 >= 0 && navche1x - 1 <= n - 1)
                            && (navche1y - 1 <= n - 1 && navche1y - 3 >= 0))) {
                        System.out.println("Khata! mokhtasat sahih vared konid.");
                        navche1x = input.nextInt();
                        navche1y = input.nextInt();
                    }
                    while (!(q[navche1x - 1][navche1y - 1] == 0 && q[navche1x - 1][navche1y - 2] == 0
                            && q[navche1x - 1][navche1y - 3] == 0)) {
                        System.out.println("Khata! mokhtasat sahih vared konid.");
                        navche1x = input.nextInt();
                        navche1y = input.nextInt();
                    }
                    q[navche1x - 1][navche1y - 1] = -1;
                    q[navche1x - 1][navche1y - 2] = -1;
                    q[navche1x - 1][navche1y - 3] = -1;
                    GameBoard(n);
                    System.out.printf("\n");
                }
            }
            /*******************************************************************/
            System.out.println(
                    "bazicon 1 mokhtasat navshekanha va jahat ra vared konad ebteda x sepas y baray amodi 1 va ofoghi 2:");
            for (i = 0; i < 2; i++) {
                navshekan1x = input.nextInt();
                navshekan1y = input.nextInt();
                jahat = input.nextInt();

                if (jahat != 1 && jahat != 2) {
                    while (jahat != 1 && jahat != 2) {
                        System.out.println("jahat 1 ya 2 ast ");
                        jahat = input.nextInt();
                    }
                }
                if (jahat == 1) {
                    while (!((navshekan1y - 1 >= 0 && navshekan1y - 1 <= n - 1)
                            && (navshekan1x - 1 <= n - 1 && navshekan1x - 2 >= 0))) {
                        System.out.println("Khata! mokhtasat sahih vared konid.");
                        navshekan1x = input.nextInt();
                        navshekan1y = input.nextInt();
                    }
                    while (!(q[navshekan1x - 1][navshekan1y - 1] == 0 && q[navshekan1x - 2][navshekan1y - 1] == 0)) {
                        System.out.println("Khata! mokhtasat sahih vared konid.");
                        navshekan1x = input.nextInt();
                        navshekan1y = input.nextInt();
                    }
                    q[navshekan1x - 1][navshekan1y - 1] = -1;
                    q[navshekan1x - 2][navshekan1y - 1] = -1;
                    GameBoard(n);
                    System.out.printf("\n");
                }
                if (jahat == 2) {
                    while (!((navshekan1x - 1 >= 0 && navshekan1x - 1 <= n - 1)
                            && (navshekan1y - 1 <= n - 1 && navshekan1y - 2 >= 0))) {
                        System.out.println("Khata! mokhtasat sahih vared konid.");
                        navshekan1x = input.nextInt();
                        navshekan1y = input.nextInt();
                    }
                    while (!(q[navshekan1x - 1][navshekan1y - 1] == 0 && q[navshekan1x - 1][navshekan1y - 2] == 0)) {
                        System.out.println("Khata! mokhtasat sahih vared konid.");
                        navshekan1x = input.nextInt();
                        navshekan1y = input.nextInt();
                    }
                    q[navshekan1x - 1][navshekan1y - 1] = -1;
                    q[navshekan1x - 1][navshekan1y - 2] = -1;
                    GameBoard(n);
                    System.out.printf("\n");
                }
            }
            /*******************************************************************/
            System.out.println(
                    "bazicon 1 mokhtasat nav va jahat ra vared konad ebteda x sepas y baray amodi 1 va ofoghi 2:");

            nav1x = input.nextInt();
            nav1y = input.nextInt();
            jahat = input.nextInt();

            if (jahat != 1 && jahat != 2) {
                while (jahat != 1 && jahat != 2) {
                    System.out.println("jahat 1 ya 2 ast ");
                    jahat = input.nextInt();
                }
            }
            if (jahat == 1) {
                while (!((nav1y - 2 >= 0 && nav1y - 1 <= n - 1)
                        && (nav1x - 1 <= n - 1 && nav1x - 4 >= 0))) {
                    System.out.println("Khata! mokhtasat sahih vared konid.");
                    nav1x = input.nextInt();
                    nav1y = input.nextInt();
                }
                while (!(q[nav1x - 1][nav1y - 1] == 0 && q[nav1x - 2][nav1y - 1] == 0
                        && q[nav1x - 3][nav1y - 1] == 0 && q[nav1x - 1][nav1y - 2] == 0 && q[nav1x - 2][nav1y - 2] == 0
                        && q[nav1x - 3][nav1y - 2] == 0)) {
                    System.out.println("Khata! mokhtasat sahih vared konid.");
                    nav1x = input.nextInt();
                    nav1y = input.nextInt();
                }
                q[nav1x - 1][nav1y - 1] = -1;
                q[nav1x - 2][nav1y - 1] = -1;
                q[nav1x - 3][nav1y - 1] = -1;
                q[nav1x - 4][nav1y - 1] = -1;
                q[nav1x - 1][nav1y - 2] = -1;
                q[nav1x - 2][nav1y - 2] = -1;
                q[nav1x - 3][nav1y - 2] = -1;
                q[nav1x - 4][nav1y - 2] = -1;
                GameBoard(n);
                System.out.printf("\n");
            }
            if (jahat == 2) {
                while (!((nav1x - 2 >= 0 && nav1x - 1 <= n - 1)
                        && (nav1y - 1 <= n - 1 && nav1y - 4 >= 0))) {
                    System.out.println("Khata! mokhtasat sahih vared konid.");
                    nav1x = input.nextInt();
                    nav1y = input.nextInt();
                }
                while (!(q[nav1x - 1][nav1y - 1] == 0 && q[nav1x - 1][nav1y - 2] == 0
                        && q[nav1x - 1][nav1y - 3] == 0 && q[nav1x - 2][nav1y - 1] == 0 && q[nav1x - 2][nav1y - 2] == 0
                        && q[nav1x - 2][nav1y - 3] == 0)) {
                    System.out.println("Khata! mokhtasat sahih vared konid.");
                    nav1x = input.nextInt();
                    nav1y = input.nextInt();
                }
                q[nav1x - 1][nav1y - 1] = -1;
                q[nav1x - 1][nav1y - 2] = -1;
                q[nav1x - 1][nav1y - 3] = -1;
                q[nav1x - 1][nav1y - 4] = -1;
                q[nav1x - 2][nav1y - 1] = -1;
                q[nav1x - 2][nav1y - 2] = -1;
                q[nav1x - 2][nav1y - 3] = -1;
                q[nav1x - 2][nav1y - 4] = -1;
                GameBoard(n);
                System.out.printf("\n");
            }
            /********************************************************* */
            /********************************************************* */

            System.out.println("bazicon 2 mokhtasat ghayeghha ra vared konad ebteda x sepas y:");
            for (i = 0; i < 3; i++) {
                ghayegh1x = input.nextInt();
                ghayegh1y = input.nextInt();
                while ((ghayegh1x - 1 >= n || ghayegh1x < 1 || ghayegh1y - 1 >= n || ghayegh1y < 1)) {
                    System.out.println("Khata! mokhtasat sahih vared konid!");
                    ghayegh1x = input.nextInt();
                    ghayegh1y = input.nextInt();
                }

                if (p[ghayegh1x - 1][ghayegh1y - 1] == 0
                        && !(ghayegh1x - 1 >= n || ghayegh1x < 1 || ghayegh1y - 1 >= n || ghayegh1y < 1)) {

                    p[ghayegh1x - 1][ghayegh1y - 1] = -1;
                    GameBoard(n);
                    System.out.printf("\n");
                } else {

                    while (!(p[ghayegh1x - 1][ghayegh1y - 1] == 0)) {
                        System.out.println("Khata! mokhtasat sahih vared konid!");
                        ghayegh1x = input.nextInt();
                        ghayegh1y = input.nextInt();
                    }
                    p[ghayegh1x - 1][ghayegh1y - 1] = -1;
                    GameBoard(n);
                    System.out.printf("\n");
                }
            }
            /*******************************************************************/
            System.out.println(
                    "bazicon 2 mokhtasat navcheha va jahat ra vared konad ebteda x sepas y baray amodi 1 va ofoghi 2:");
            for (i = 0; i < 2; i++) {
                navche1x = input.nextInt();
                navche1y = input.nextInt();
                jahat = input.nextInt();

                if (jahat != 1 && jahat != 2) {
                    while (jahat != 1 && jahat != 2) {
                        System.out.println("jahat 1 ya 2 ast ");
                        jahat = input.nextInt();
                    }
                }
                if (jahat == 1) {
                    while (!((navche1y - 1 >= 0 && navche1y - 1 <= n - 1)
                            && (navche1x - 1 <= n - 1 && navche1x - 3 >= 0))) {
                        System.out.println("Khata! mokhtasat sahih vared konid.");
                        navche1x = input.nextInt();
                        navche1y = input.nextInt();
                    }
                    while (!(p[navche1x - 1][navche1y - 1] == 0 && p[navche1x - 2][navche1y - 1] == 0
                            && p[navche1x - 3][navche1y - 1] == 0)) {
                        System.out.println("Khata! mokhtasat sahih vared konid.");
                        navche1x = input.nextInt();
                        navche1y = input.nextInt();
                    }
                    p[navche1x - 1][navche1y - 1] = -1;
                    p[navche1x - 2][navche1y - 1] = -1;
                    p[navche1x - 3][navche1y - 1] = -1;
                    GameBoard(n);
                    System.out.printf("\n");
                }
                if (jahat == 2) {
                    while (!((navche1x - 1 >= 0 && navche1x - 1 <= n - 1)
                            && (navche1y - 1 <= n - 1 && navche1y - 3 >= 0))) {
                        System.out.println("Khata! mokhtasat sahih vared konid.");
                        navche1x = input.nextInt();
                        navche1y = input.nextInt();
                    }
                    while (!(p[navche1x - 1][navche1y - 1] == 0 && p[navche1x - 1][navche1y - 2] == 0
                            && p[navche1x - 1][navche1y - 3] == 0)) {
                        System.out.println("Khata! mokhtasat sahih vared konid.");
                        navche1x = input.nextInt();
                        navche1y = input.nextInt();
                    }
                    p[navche1x - 1][navche1y - 1] = -1;
                    p[navche1x - 1][navche1y - 2] = -1;
                    p[navche1x - 1][navche1y - 3] = -1;
                    GameBoard(n);
                    System.out.printf("\n");
                }
            }
            /*******************************************************************/
            System.out.println(
                    "bazicon 2 mokhtasat navshekanha va jahat ra vared konad ebteda x sepas y baray amodi 1 va ofoghi 2:");
            for (i = 0; i < 2; i++) {
                navshekan1x = input.nextInt();
                navshekan1y = input.nextInt();
                jahat = input.nextInt();

                if (jahat != 1 && jahat != 2) {
                    while (jahat != 1 && jahat != 2) {
                        System.out.println("jahat 1 ya 2 ast ");
                        jahat = input.nextInt();
                    }
                }
                if (jahat == 1) {
                    while (!((navshekan1y - 1 >= 0 && navshekan1y - 1 <= n - 1)
                            && (navshekan1x - 1 <= n - 1 && navshekan1x - 2 >= 0))) {
                        System.out.println("Khata! mokhtasat sahih vared konid.");
                        navshekan1x = input.nextInt();
                        navshekan1y = input.nextInt();
                    }
                    while (!(p[navshekan1x - 1][navshekan1y - 1] == 0 && p[navshekan1x - 2][navshekan1y - 1] == 0)) {
                        System.out.println("Khata! mokhtasat sahih vared konid.");
                        navshekan1x = input.nextInt();
                        navshekan1y = input.nextInt();
                    }
                    p[navshekan1x - 1][navshekan1y - 1] = -1;
                    p[navshekan1x - 2][navshekan1y - 1] = -1;
                    GameBoard(n);
                    System.out.printf("\n");
                }
                if (jahat == 2) {
                    while (!((navshekan1x - 1 >= 0 && navshekan1x - 1 <= n - 1)
                            && (navshekan1y - 1 <= n - 1 && navshekan1y - 2 >= 0))) {
                        System.out.println("Khata! mokhtasat sahih vared konid.");
                        navshekan1x = input.nextInt();
                        navshekan1y = input.nextInt();
                    }
                    while (!(p[navshekan1x - 1][navshekan1y - 1] == 0 && p[navshekan1x - 1][navshekan1y - 2] == 0)) {
                        System.out.println("Khata! mokhtasat sahih vared konid.");
                        navshekan1x = input.nextInt();
                        navshekan1y = input.nextInt();
                    }
                    p[navshekan1x - 1][navshekan1y - 1] = -1;
                    p[navshekan1x - 1][navshekan1y - 2] = -1;
                    GameBoard(n);
                    System.out.printf("\n");
                }
            }
            /*******************************************************************/
            System.out.println(
                    "bazicon 2 mokhtasat nav va jahat ra vared konad ebteda x sepas y baray amodi 1 va ofoghi 2:");

            nav1x = input.nextInt();
            nav1y = input.nextInt();
            jahat = input.nextInt();

            if (jahat != 1 && jahat != 2) {
                while (jahat != 1 && jahat != 2) {
                    System.out.println("jahat 1 ya 2 ast ");
                    jahat = input.nextInt();
                }
            }
            if (jahat == 1) {
                while (!((nav1y - 2 >= 0 && nav1y - 1 <= n - 1)
                        && (nav1x - 1 <= n - 1 && nav1x - 4 >= 0))) {
                    System.out.println("Khata! mokhtasat sahih vared konid.");
                    nav1x = input.nextInt();
                    nav1y = input.nextInt();
                }
                while (!(p[nav1x - 1][nav1y - 1] == 0 && p[nav1x - 2][nav1y - 1] == 0
                        && p[nav1x - 3][nav1y - 1] == 0 && p[nav1x - 1][nav1y - 2] == 0 && p[nav1x - 2][nav1y - 2] == 0
                        && p[nav1x - 3][nav1y - 2] == 0)) {
                    System.out.println("Khata! mokhtasat sahih vared konid.");
                    nav1x = input.nextInt();
                    nav1y = input.nextInt();
                }
                p[nav1x - 1][nav1y - 1] = -1;
                p[nav1x - 2][nav1y - 1] = -1;
                p[nav1x - 3][nav1y - 1] = -1;
                p[nav1x - 4][nav1y - 1] = -1;
                p[nav1x - 1][nav1y - 2] = -1;
                p[nav1x - 2][nav1y - 2] = -1;
                p[nav1x - 3][nav1y - 2] = -1;
                p[nav1x - 4][nav1y - 2] = -1;
                GameBoard(n);
                System.out.printf("\n");
            }
            if (jahat == 2) {
                while (!((nav1x - 2 >= 0 && nav1x - 1 <= n - 1)
                        && (nav1y - 1 <= n - 1 && nav1y - 4 >= 0))) {
                    System.out.println("Khata! mokhtasat sahih vared konid.");
                    nav1x = input.nextInt();
                    nav1y = input.nextInt();
                }
                while (!(p[nav1x - 1][nav1y - 1] == 0 && p[nav1x - 1][nav1y - 2] == 0
                        && p[nav1x - 1][nav1y - 3] == 0 && p[nav1x - 2][nav1y - 1] == 0 && p[nav1x - 2][nav1y - 2] == 0
                        && p[nav1x - 2][nav1y - 3] == 0)) {
                    System.out.println("Khata! mokhtasat sahih vared konid.");
                    nav1x = input.nextInt();
                    nav1y = input.nextInt();
                }
                p[nav1x - 1][nav1y - 1] = -1;
                p[nav1x - 1][nav1y - 2] = -1;
                p[nav1x - 1][nav1y - 3] = -1;
                p[nav1x - 1][nav1y - 4] = -1;
                p[nav1x - 2][nav1y - 1] = -1;
                p[nav1x - 2][nav1y - 2] = -1;
                p[nav1x - 2][nav1y - 3] = -1;
                p[nav1x - 2][nav1y - 4] = -1;
                GameBoard(n);
                System.out.printf("\n");
            }
            System.out.println("shoroe bazi");
            int count = 1;
            int x, y;
            int model, estesna;
            int entekhabx, entekhaby;
            int ab = 0;
            asli2: do {
                if (count % 2 == 1) { // bazicon1
                    System.out.println("noe shlik: adad 1 baraye 1 khane adad 2 baraye 5 khane");
                    shelik = input.nextInt();

                    if (shelik != 1 && shelik != 2) {
                        while (shelik != 1 && shelik != 2) {
                            System.out.println("jahat 1 ya 2 ast ");
                            shelik = input.nextInt();
                        }
                    }

                    System.out.println("be kodam khane?");
                    x = input.nextInt();
                    y = input.nextInt();
                    while ((x - 1 >= n || x < 1 || y - 1 >= n || y < 1)) {
                        System.out.println("Khata! mokhtasat sahih vared konid!");
                        x = input.nextInt();
                        y = input.nextInt();
                    }
                    shelik2b1(shelik, x, y);
                    GameBoardb1(n);
                    System.out.println("**************" + emtiaz1);

                }
                if (count % 2 == 0) {// bazicon2 computer
                    System.out.println("noe shlik: adad 1 baraye 1 khane adad 2 baraye 5 khane");
                    shelik = input.nextInt();

                    if (shelik != 1 && shelik != 2) {
                        while (shelik != 1 && shelik != 2) {
                            System.out.println("jahat 1 ya 2 ast ");
                            shelik = input.nextInt();
                        }
                    }

                    System.out.println("be kodam khane?");
                    x = input.nextInt();
                    y = input.nextInt();
                    while ((x - 1 >= n || x < 1 || y - 1 >= n || y < 1)) {
                        System.out.println("Khata! mokhtasat sahih vared konid!");
                        x = input.nextInt();
                        y = input.nextInt();
                    }
                    shelik2b2(shelik, x, y);
                    GameBoardb2(n);
                    System.out.println("**************" + emtiaz2);
                }
                /*
                 * etmam1: if (emtiaz1 <= 0) {
                 * if (payanb1() == 0) {
                 * break etmam1;
                 * } else {
                 * System.out.println("bayad keshti khod ra befroshid.model an ra vared konid!"
                 * );
                 * 
                 * do {
                 * model = input.nextInt();
                 * } while (1 >= model && model >= 4);
                 * estesna = model;
                 * emtiaz1 = estesna + emtiaz1;
                 * if (model == 4) {
                 * model = 8;
                 * }
                 * for (i = 0; i < model; i++) {
                 * do {
                 * System.out.println(
                 * "keshti mored nazr ra entekhab konid. ebteda x va sepas y ra vared konid.bayad kol keshti ra entekhab konid"
                 * );
                 * entekhabx = input.nextInt();
                 * entekhaby = input.nextInt();
                 * } while ((entekhabx - 1 >= n || entekhabx < 1 || entekhaby - 1 >= n ||
                 * entekhaby < 1
                 * || q[entekhabx][entekhaby] != -1));
                 * q[entekhabx][entekhaby] = 0; // ba forokhtan chizi tabdil be noghte mishavad
                 * 
                 * }
                 * 
                 * }
                 * }
                 * etmam2: if (emtiaz2 <= 0) {
                 * if (payanb2() == 0) {
                 * break etmam2;
                 * } else {
                 * 
                 * System.out.println("bayad keshti  ra befroshad.model an ra vared konid!");
                 * 
                 * model = rand.nextInt(4) + 1;
                 * emtiaz2 = model + emtiaz2;
                 * if (model == 4) {
                 * model = 8;
                 * }
                 * for (i = 0; i < model; i++) {
                 * System.out.println(
                 * "keshti mored nazr ra entekhab konid. ebteda x va sepas y ra vared konid.bayad kol keshti ra entekhab konid"
                 * );
                 * entekhabx = rand.nextInt(n) + 1;
                 * entekhaby = rand.nextInt(n) + 1;
                 * q[entekhabx][entekhaby] = 0; // ba forokhtan chizi tabdil be noghte mishavad
                 * 
                 * }
                 * }
                 * 
                 * }
                 * !((emtiaz1 == 0 && payanb1() == 0) || (emtiaz2 == 0 && payanb2() == 0))
                 */
                if (payanb1() == 1) {
                    ab = 2;
                    break asli2;
                }
                if (payanb2() == 1) {
                    ab = 1;
                    break asli2;
                }
                count++;

            } while (emtiaz1 > 0 && emtiaz2 > 0);
            if (emtiaz1 <= 0 || ab == 2) {
                System.out.println(emtiaz1);
                System.out.println(emtiaz2);
                System.out.println("Payan Bazi! bazicon2 baranda ast!");
            } else if (emtiaz2 <= 0 || ab == 1) {
                System.out.println(emtiaz1);
                System.out.println(emtiaz2);
                System.out.println("Payan Bazi! bazikon 1  baranda ast!");
            }

        }
        /************************************************************** */
        /************************************************************* */
        /************************************************************* */

        if (TedadBazicon == 1) {

            System.out.println("bazicon 1 mokhtasat ghayeghha ra vared konad ebteda x sepas y:");
            for (i = 0; i < 3; i++) {
                ghayegh1x = input.nextInt();
                ghayegh1y = input.nextInt();
                while ((ghayegh1x - 1 >= n || ghayegh1x < 1 || ghayegh1y - 1 >= n || ghayegh1y < 1)) {
                    System.out.println("Khata! mokhtasat sahih vared konid!");
                    ghayegh1x = input.nextInt();
                    ghayegh1y = input.nextInt();
                }

                if (q[ghayegh1x - 1][ghayegh1y - 1] == 0
                        && !(ghayegh1x - 1 >= n || ghayegh1x < 1 || ghayegh1y - 1 >= n || ghayegh1y < 1)) {

                    q[ghayegh1x - 1][ghayegh1y - 1] = -1;
                    GameBoard(n);
                    System.out.printf("\n");
                } else {

                    while (!(q[ghayegh1x - 1][ghayegh1y - 1] == 0)) {
                        System.out.println("Khata! mokhtasat sahih vared konid!");
                        ghayegh1x = input.nextInt();
                        ghayegh1y = input.nextInt();
                    }
                    q[ghayegh1x - 1][ghayegh1y - 1] = -1;
                    GameBoard(n);
                    System.out.printf("\n");
                }
            }
            /*******************************************************************/
            System.out.println(
                    "bazicon 1 mokhtasat navcheha va jahat ra vared konad ebteda x sepas y baray amodi 1 va ofoghi 2:");
            for (i = 0; i < 2; i++) {
                navche1x = input.nextInt();
                navche1y = input.nextInt();
                jahat = input.nextInt();

                if (jahat != 1 && jahat != 2) {
                    while (jahat != 1 && jahat != 2) {
                        System.out.println("jahat 1 ya 2 ast ");
                        jahat = input.nextInt();
                    }
                }
                if (jahat == 1) {
                    while (!((navche1y - 1 >= 0 && navche1y - 1 <= n - 1)
                            && (navche1x - 1 <= n - 1 && navche1x - 3 >= 0))) {
                        System.out.println("Khata! mokhtasat sahih vared konid.");
                        navche1x = input.nextInt();
                        navche1y = input.nextInt();
                    }
                    while (!(q[navche1x - 1][navche1y - 1] == 0 && q[navche1x - 2][navche1y - 1] == 0
                            && q[navche1x - 3][navche1y - 1] == 0)) {
                        System.out.println("Khata! mokhtasat sahih vared konid.");
                        navche1x = input.nextInt();
                        navche1y = input.nextInt();
                    }
                    q[navche1x - 1][navche1y - 1] = -1;
                    q[navche1x - 2][navche1y - 1] = -1;
                    q[navche1x - 3][navche1y - 1] = -1;
                    GameBoard(n);
                    System.out.printf("\n");
                }
                if (jahat == 2) {
                    while (!((navche1x - 1 >= 0 && navche1x - 1 <= n - 1)
                            && (navche1y - 1 <= n - 1 && navche1y - 3 >= 0))) {
                        System.out.println("Khata! mokhtasat sahih vared konid.");
                        navche1x = input.nextInt();
                        navche1y = input.nextInt();
                    }
                    while (!(q[navche1x - 1][navche1y - 1] == 0 && q[navche1x - 1][navche1y - 2] == 0
                            && q[navche1x - 1][navche1y - 3] == 0)) {
                        System.out.println("Khata! mokhtasat sahih vared konid.");
                        navche1x = input.nextInt();
                        navche1y = input.nextInt();
                    }
                    q[navche1x - 1][navche1y - 1] = -1;
                    q[navche1x - 1][navche1y - 2] = -1;
                    q[navche1x - 1][navche1y - 3] = -1;
                    GameBoard(n);
                    System.out.printf("\n");
                }
            }
            /*******************************************************************/
            System.out.println(
                    "bazicon 1 mokhtasat navshekanha va jahat ra vared konad ebteda x sepas y baray amodi 1 va ofoghi 2:");
            for (i = 0; i < 2; i++) {
                navshekan1x = input.nextInt();
                navshekan1y = input.nextInt();
                jahat = input.nextInt();

                if (jahat != 1 && jahat != 2) {
                    while (jahat != 1 && jahat != 2) {
                        System.out.println("jahat 1 ya 2 ast ");
                        jahat = input.nextInt();
                    }
                }
                if (jahat == 1) {
                    while (!((navshekan1y - 1 >= 0 && navshekan1y - 1 <= n - 1)
                            && (navshekan1x - 1 <= n - 1 && navshekan1x - 2 >= 0))) {
                        System.out.println("Khata! mokhtasat sahih vared konid.");
                        navshekan1x = input.nextInt();
                        navshekan1y = input.nextInt();
                    }
                    while (!(q[navshekan1x - 1][navshekan1y - 1] == 0 && q[navshekan1x - 2][navshekan1y - 1] == 0)) {
                        System.out.println("Khata! mokhtasat sahih vared konid.");
                        navshekan1x = input.nextInt();
                        navshekan1y = input.nextInt();
                    }
                    q[navshekan1x - 1][navshekan1y - 1] = -1;
                    q[navshekan1x - 2][navshekan1y - 1] = -1;
                    GameBoard(n);
                    System.out.printf("\n");
                }
                if (jahat == 2) {
                    while (!((navshekan1x - 1 >= 0 && navshekan1x - 1 <= n - 1)
                            && (navshekan1y - 1 <= n - 1 && navshekan1y - 2 >= 0))) {
                        System.out.println("Khata! mokhtasat sahih vared konid.");
                        navshekan1x = input.nextInt();
                        navshekan1y = input.nextInt();
                    }
                    while (!(q[navshekan1x - 1][navshekan1y - 1] == 0 && q[navshekan1x - 1][navshekan1y - 2] == 0)) {
                        System.out.println("Khata! mokhtasat sahih vared konid.");
                        navshekan1x = input.nextInt();
                        navshekan1y = input.nextInt();
                    }
                    q[navshekan1x - 1][navshekan1y - 1] = -1;
                    q[navshekan1x - 1][navshekan1y - 2] = -1;
                    GameBoard(n);
                    System.out.printf("\n");
                }
            }
            /*******************************************************************/
            System.out.println(
                    "bazicon 1 mokhtasat nav va jahat ra vared konad ebteda x sepas y baray amodi 1 va ofoghi 2:");

            nav1x = input.nextInt();
            nav1y = input.nextInt();
            jahat = input.nextInt();

            if (jahat != 1 && jahat != 2) {
                while (jahat != 1 && jahat != 2) {
                    System.out.println("jahat 1 ya 2 ast ");
                    jahat = input.nextInt();
                }
            }
            if (jahat == 1) {
                while (!((nav1y - 2 >= 0 && nav1y - 1 <= n - 1)
                        && (nav1x - 1 <= n - 1 && nav1x - 4 >= 0))) {
                    System.out.println("Khata! mokhtasat sahih vared konid.");
                    nav1x = input.nextInt();
                    nav1y = input.nextInt();
                }
                while (!(q[nav1x - 1][nav1y - 1] == 0 && q[nav1x - 2][nav1y - 1] == 0
                        && q[nav1x - 3][nav1y - 1] == 0 && q[nav1x - 1][nav1y - 2] == 0 && q[nav1x - 2][nav1y - 2] == 0
                        && q[nav1x - 3][nav1y - 2] == 0)) {
                    System.out.println("Khata! mokhtasat sahih vared konid.");
                    nav1x = input.nextInt();
                    nav1y = input.nextInt();
                }
                q[nav1x - 1][nav1y - 1] = -1;
                q[nav1x - 2][nav1y - 1] = -1;
                q[nav1x - 3][nav1y - 1] = -1;
                q[nav1x - 4][nav1y - 1] = -1;
                q[nav1x - 1][nav1y - 2] = -1;
                q[nav1x - 2][nav1y - 2] = -1;
                q[nav1x - 3][nav1y - 2] = -1;
                q[nav1x - 4][nav1y - 2] = -1;
                GameBoard(n);
                System.out.printf("\n");
            }
            if (jahat == 2) {
                while (!((nav1x - 2 >= 0 && nav1x - 1 <= n - 1)
                        && (nav1y - 1 <= n - 1 && nav1y - 4 >= 0))) {
                    System.out.println("Khata! mokhtasat sahih vared konid.");
                    nav1x = input.nextInt();
                    nav1y = input.nextInt();
                }
                while (!(q[nav1x - 1][nav1y - 1] == 0 && q[nav1x - 1][nav1y - 2] == 0
                        && q[nav1x - 1][nav1y - 3] == 0 && q[nav1x - 2][nav1y - 1] == 0 && q[nav1x - 2][nav1y - 2] == 0
                        && q[nav1x - 2][nav1y - 3] == 0)) {
                    System.out.println("Khata! mokhtasat sahih vared konid.");
                    nav1x = input.nextInt();
                    nav1y = input.nextInt();
                }
                q[nav1x - 1][nav1y - 1] = -1;
                q[nav1x - 1][nav1y - 2] = -1;
                q[nav1x - 1][nav1y - 3] = -1;
                q[nav1x - 1][nav1y - 4] = -1;
                q[nav1x - 2][nav1y - 1] = -1;
                q[nav1x - 2][nav1y - 2] = -1;
                q[nav1x - 2][nav1y - 3] = -1;
                q[nav1x - 2][nav1y - 4] = -1;
                GameBoard(n);
                System.out.printf("\n");
            }
            /********************************************************* */
            /********************************************************* */

            System.out.println("bazicon 2 mokhtasat ghayeghha ra vared konad ebteda x sepas y:");
            for (i = 0; i < 3; i++) {
                ghayegh1x = rand.nextInt(n) + 1;
                ghayegh1y = rand.nextInt(n) + 1;
                while ((ghayegh1x - 1 >= n || ghayegh1x < 1 || ghayegh1y - 1 >= n || ghayegh1y < 1)) {
                    System.out.println("Khata! mokhtasat sahih vared konid!");
                    ghayegh1x = rand.nextInt(n) + 1;
                    ghayegh1y = rand.nextInt(n) + 1;
                }

                if (p[ghayegh1x - 1][ghayegh1y - 1] == 0
                        && !(ghayegh1x - 1 >= n || ghayegh1x < 1 || ghayegh1y - 1 >= n || ghayegh1y < 1)) {

                    p[ghayegh1x - 1][ghayegh1y - 1] = -1;
                    GameBoard(n);
                    System.out.printf("\n");
                } else {

                    while (!(p[ghayegh1x - 1][ghayegh1y - 1] == 0)) {
                        System.out.println("Khata! mokhtasat sahih vared konid!");
                        ghayegh1x = rand.nextInt(n) + 1;
                        ghayegh1y = rand.nextInt(n) + 1;
                    }
                    p[ghayegh1x - 1][ghayegh1y - 1] = -1;
                    GameBoard(n);
                    System.out.printf("\n");
                }
            }
            /*******************************************************************/
            System.out.println(
                    "bazicon 2 mokhtasat navcheha va jahat ra vared konad ebteda x sepas y baray amodi 1 va ofoghi 2:");
            for (i = 0; i < 2; i++) {
                navche1x = rand.nextInt(n) + 1;
                navche1y = rand.nextInt(n) + 1;
                jahat = rand.nextInt(2) + 1;

                if (jahat == 1) {
                    while (!((navche1y - 1 >= 0 && navche1y - 1 <= n - 1) && (navche1x - 1 <= n - 1 && navche1x - 3 >= 0))) {
                        System.out.println("Khata! mokhtasat sahih vared konid.");
                        navche1x = rand.nextInt(n) + 1;
                        navche1y = rand.nextInt(n) + 1;
                    }
                    while (!(p[navche1x - 1][navche1y - 1] == 0 && p[navche1x - 2][navche1y - 1] == 0
                            && p[navche1x - 3][navche1y - 1] == 0)) {
                        System.out.println("Khata! mokhtasat sahih vared konid.");
                        navche1x = rand.nextInt(n) + 1;
                        navche1y = rand.nextInt(n) + 1;
                    }
                    p[navche1x - 1][navche1y - 1] = -1;
                    p[navche1x - 2][navche1y - 1] = -1;
                    p[navche1x - 3][navche1y - 1] = -1;
                    GameBoard(n);
                    System.out.printf("\n");
                }
                if (jahat == 2) {
                    while (!((navche1x - 1 >= 0 && navche1x - 1 <= n - 1)
                            && (navche1y - 1 <= n - 1 && navche1y - 3 >= 0))) {
                        System.out.println("Khata! mokhtasat sahih vared konid.");
                        navche1x = rand.nextInt(n) + 1;
                        navche1y = rand.nextInt(n) + 1;
                    }
                    while (!(p[navche1x - 1][navche1y - 1] == 0 && p[navche1x - 1][navche1y - 2] == 0
                            && p[navche1x - 1][navche1y - 3] == 0)) {
                        System.out.println("Khata! mokhtasat sahih vared konid.");
                        navche1x = rand.nextInt(n) + 1;
                        navche1y = rand.nextInt(n) + 1;
                    }
                    p[navche1x - 1][navche1y - 1] = -1;
                    p[navche1x - 1][navche1y - 2] = -1;
                    p[navche1x - 1][navche1y - 3] = -1;
                    GameBoard(n);
                    System.out.printf("\n");
                }
            }
            /*******************************************************************/
            System.out.println(
                    "bazicon 2 mokhtasat navshekanha va jahat ra vared konad ebteda x sepas y baray amodi 1 va ofoghi 2:");
            for (i = 0; i < 2; i++) {
                navshekan1x = rand.nextInt(n) + 1;
                navshekan1y = rand.nextInt(n) + 1;
                jahat = rand.nextInt(2) + 1;

                if (jahat == 1) {
                    while (!((navshekan1y - 1 >= 0 && navshekan1y - 1 <= n - 1)
                            && (navshekan1x - 1 <= n - 1 && navshekan1x - 2 >= 0))) {
                        System.out.println("Khata! mokhtasat sahih vared konid.");
                        navshekan1x = rand.nextInt(n) + 1;
                        navshekan1y = rand.nextInt(n) + 1;
                    }
                    while (!(p[navshekan1x - 1][navshekan1y - 1] == 0 && p[navshekan1x - 2][navshekan1y - 1] == 0)) {
                        System.out.println("Khata! mokhtasat sahih vared konid.");
                        navshekan1x = rand.nextInt(n) + 1;
                        navshekan1y = rand.nextInt(n) + 1;
                    }
                    p[navshekan1x - 1][navshekan1y - 1] = -1;
                    p[navshekan1x - 2][navshekan1y - 1] = -1;
                    GameBoard(n);
                    System.out.printf("\n");
                }
                if (jahat == 2) {
                    while (!((navshekan1x - 1 >= 0 && navshekan1x - 1 <= n - 1)
                            && (navshekan1y - 1 <= n - 1 && navshekan1y - 2 >= 0))) {
                        System.out.println("Khata! mokhtasat sahih vared konid.");
                        navshekan1x = rand.nextInt(n) + 1;
                        navshekan1y = rand.nextInt(n) + 1;
                    }
                    while (!(p[navshekan1x - 1][navshekan1y - 1] == 0 && p[navshekan1x - 1][navshekan1y - 2] == 0)) {
                        System.out.println("Khata! mokhtasat sahih vared konid.");
                        navshekan1x = rand.nextInt(n) + 1;
                        navshekan1y = rand.nextInt(n) + 1;
                    }
                    p[navshekan1x - 1][navshekan1y - 1] = -1;
                    p[navshekan1x - 1][navshekan1y - 2] = -1;
                    GameBoard(n);
                    System.out.printf("\n");
                }
            }
            /*******************************************************************/
            System.out.println(
                    "bazicon 2 mokhtasat nav va jahat ra vared konad ebteda x sepas y baray amodi 1 va ofoghi 2:");

            nav1x = rand.nextInt(n) + 1;
            nav1y = rand.nextInt(n) + 1;
            jahat = rand.nextInt(2) + 1;

            if (jahat == 1) {
                while (!((nav1y - 2 >= 0 && nav1y - 1 <= n - 1)
                        && (nav1x - 1 <= n - 1 && nav1x - 4 >= 0))) {
                    System.out.println("Khata! mokhtasat sahih vared konid.");
                    nav1x = rand.nextInt(n) + 1;
                    nav1y = rand.nextInt(n) + 1;
                }
                while (!(p[nav1x - 1][nav1y - 1] == 0 && p[nav1x - 2][nav1y - 1] == 0
                        && p[nav1x - 3][nav1y - 1] == 0 && p[nav1x - 1][nav1y - 2] == 0 && p[nav1x - 2][nav1y - 2] == 0
                        && p[nav1x - 3][nav1y - 2] == 0)) {
                    System.out.println("Khata! mokhtasat sahih vared konid.");
                    nav1x = rand.nextInt(n) + 1;
                    nav1y = rand.nextInt(n) + 1;
                }
                p[nav1x - 1][nav1y - 1] = -1;
                p[nav1x - 2][nav1y - 1] = -1;
                p[nav1x - 3][nav1y - 1] = -1;
                p[nav1x - 4][nav1y - 1] = -1;
                p[nav1x - 1][nav1y - 2] = -1;
                p[nav1x - 2][nav1y - 2] = -1;
                p[nav1x - 3][nav1y - 2] = -1;
                p[nav1x - 4][nav1y - 2] = -1;
                GameBoard(n);
                System.out.printf("\n");
            }
            if (jahat == 2) {
                while (!((nav1x - 2 >= 0 && nav1x - 1 <= n - 1)
                        && (nav1y - 1 <= n - 1 && nav1y - 4 >= 0))) {
                    System.out.println("Khata! mokhtasat sahih vared konid.");
                    nav1x = rand.nextInt(n) + 1;
                    nav1y = rand.nextInt(n) + 1;
                }
                while (!(p[nav1x - 1][nav1y - 1] == 0 && p[nav1x - 1][nav1y - 2] == 0
                        && p[nav1x - 1][nav1y - 3] == 0 && p[nav1x - 2][nav1y - 1] == 0 && p[nav1x - 2][nav1y - 2] == 0
                        && p[nav1x - 2][nav1y - 3] == 0)) {
                    System.out.println("Khata! mokhtasat sahih vared konid.");
                    nav1x = rand.nextInt(n) + 1;
                    nav1y = rand.nextInt(n) + 1;
                }
                p[nav1x - 1][nav1y - 1] = -1;
                p[nav1x - 1][nav1y - 2] = -1;
                p[nav1x - 1][nav1y - 3] = -1;
                p[nav1x - 1][nav1y - 4] = -1;
                p[nav1x - 2][nav1y - 1] = -1;
                p[nav1x - 2][nav1y - 2] = -1;
                p[nav1x - 2][nav1y - 3] = -1;
                p[nav1x - 2][nav1y - 4] = -1;
                GameBoard(n);
                System.out.printf("\n");
            }
            System.out.println("shoroe bazi");
            int count = 1;
            int x, y;
            int model, estesna;
            int entekhabx, entekhaby;
            int ab = 0;
            asli1: do {
                if (count % 2 == 1) { // bazicon1
                    System.out.println("noe shlik: adad 1 baraye 1 khane adad 2 baraye 5 khane");
                    shelik = input.nextInt();

                    if (shelik != 1 && shelik != 2) {
                        while (shelik != 1 && shelik != 2) {
                            System.out.println("jahat 1 ya 2 ast ");
                            shelik = input.nextInt();
                        }
                    }

                    System.out.println("be kodam khane?");
                    x = input.nextInt();
                    y = input.nextInt();
                    while ((x - 1 >= n || x < 1 || y - 1 >= n || y < 1)) {
                        System.out.println("Khata! mokhtasat sahih vared konid!");
                        x = input.nextInt();
                        y = input.nextInt();
                    }
                    shelik2b1(shelik, x, y);
                    GameBoardb1(n);
                    System.out.println("**************" + emtiaz1);

                }
                if (count % 2 == 0) {// bazicon2 computer
                    System.out.println("\n*******\nnobate computer ast");
                    shelik = rand.nextInt(2) + 1;

                    if (shelik == 2) {
                        x = rand.nextInt(n) + 2;
                        y = rand.nextInt(n) + 2;
                    } else {
                        x = rand.nextInt(n) + 1;
                        y = rand.nextInt(n) + 1;
                    }
                    shelik2b2(1, x, y);
                    GameBoardb2(n);
                    System.out.println("**************" + emtiaz2);
                }
                /*
                 * etmam1: if (emtiaz1 <= 0) {
                 * if (payanb1() == 0) {
                 * break etmam1;
                 * } else {
                 * System.out.println("bayad keshti khod ra befroshid.model an ra vared konid!"
                 * );
                 * 
                 * do {
                 * model = input.nextInt();
                 * } while (1 >= model && model >= 4);
                 * estesna = model;
                 * emtiaz1 = estesna + emtiaz1;
                 * if (model == 4) {
                 * model = 8;
                 * }
                 * for (i = 0; i < model; i++) {
                 * do {
                 * System.out.println(
                 * "keshti mored nazr ra entekhab konid. ebteda x va sepas y ra vared konid.bayad kol keshti ra entekhab konid"
                 * );
                 * entekhabx = input.nextInt();
                 * entekhaby = input.nextInt();
                 * } while ((entekhabx - 1 >= n || entekhabx < 1 || entekhaby - 1 >= n ||
                 * entekhaby < 1
                 * || q[entekhabx][entekhaby] != -1));
                 * q[entekhabx][entekhaby] = 0; // ba forokhtan chizi tabdil be noghte mishavad
                 * 
                 * }
                 * 
                 * }
                 * }
                 * etmam2: if (emtiaz2 <= 0) {
                 * if (payanb2() == 0) {
                 * break etmam2;
                 * } else {
                 * 
                 * System.out.println("bayad keshti  ra befroshad.model an ra vared konid!");
                 * 
                 * model = rand.nextInt(4) + 1;
                 * emtiaz2 = model + emtiaz2;
                 * if (model == 4) {
                 * model = 8;
                 * }
                 * for (i = 0; i < model; i++) {
                 * System.out.println(
                 * "keshti mored nazr ra entekhab konid. ebteda x va sepas y ra vared konid.bayad kol keshti ra entekhab konid"
                 * );
                 * entekhabx = rand.nextInt(n) + 1;
                 * entekhaby = rand.nextInt(n) + 1;
                 * q[entekhabx][entekhaby] = 0; // ba forokhtan chizi tabdil be noghte mishavad
                 * 
                 * }
                 * }
                 * 
                 * }
                 * !((emtiaz1 == 0 && payanb1() == 0) || (emtiaz2 == 0 && payanb2() == 0))
                 */

                if (payanb1() == 1) {
                    ab = 2;
                    break asli1;
                }
                if (payanb2() == 1) {
                    ab = 1;
                    break asli1;
                }
                count++;

            } while (emtiaz1 > 0 && emtiaz2 > 0);

            if (emtiaz1 <= 0 || ab == 2) {
                System.out.println(emtiaz1);
                System.out.println(emtiaz2);
                System.out.println("Payan Bazi! computer baranda ast!");
            } else if (emtiaz2 <= 0 || ab == 1) {
                System.out.println(emtiaz1);
                System.out.println(emtiaz2);
                System.out.println("Payan Bazi! bazikon 1  baranda ast!");
            }
        }
    }

}