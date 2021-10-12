using System;
using System.Threading;
using System.Text;

namespace wot2d
{
    class Program
    {
        public static char obstaclechar = '#';
        public static char playerchar = 'X';
        public static char edgechar = '▒';
        public static char emptychar = ' ';
        public static char bulletchar = 'o';
        public static char enemychar = '¤';

        public static int red;
        public static int stupac;
        public static char[,] arr;
        public static bool endgame;
        public static int playerx, playery, prevpx, prevpy;
        public static DateTime time;
        public static bool bulletexisting;
        public static char bulletmovement;
        public static int bulletx, bullety;
        public static bool enemybulletexisting;
        public static char enemybulletmovement;
        public static int enemybulletx, enemybullety;
        public static int enemyx, enemyy, enemyprevx, enemyprevy, mindistance, praznox, praznoy;
        public static Random rnd;
        public static int r;
        public static char strana;
        public static int obstaclepercentage = 0;
        public static int pass = 0;
        public static int puta = 0;
        public static char winner;
        public static int xapart, yapart;

        private static void drawgrid()
        {
            for (int i = 0; i < red; i++)
            {
                for (int j = 0; j < stupac; j++)
                {
                    if (arr[i, j] == playerchar)
                    {
                        Console.ForegroundColor = ConsoleColor.Green;
                        Console.Write(arr[i, j]);
                        Console.ForegroundColor = ConsoleColor.White;
                    }
                    else if (arr[i, j] == enemychar)
                    {
                        Console.ForegroundColor = ConsoleColor.Red;
                        Console.Write(arr[i, j]);
                        Console.ForegroundColor = ConsoleColor.White;
                    }
                    else if (arr[i, j] == obstaclechar)
                    {
                        Console.ForegroundColor = ConsoleColor.DarkGray;
                        Console.Write(arr[i, j]);
                        Console.ForegroundColor = ConsoleColor.White;
                    }
                    else if (arr[i, j] == edgechar)
                    {
                        Console.ForegroundColor = ConsoleColor.Magenta;
                        Console.Write(arr[i, j]);
                        Console.ForegroundColor = ConsoleColor.White;
                    }
                    else if (arr[i, j] == bulletchar)
                    {
                        Console.ForegroundColor = ConsoleColor.Yellow;
                        Console.Write(arr[i, j]);
                        Console.ForegroundColor = ConsoleColor.White;
                    }
                    else
                        Console.Write(arr[i, j]);
                }
                Console.Write("\n");
            }
        }

        private static void finish()
        {
            if (enemybulletx == playerx && enemybullety == playery)
            {
                //Izgubljeno
                endgame = true;
                winner = 'E';
            }

            if (bulletx == enemyx && bullety == enemyy)
            {
                //Pobjedeno
                endgame = true;
                winner = 'P';
            }
        }

        private static void BackgroundMethod()
        {
            pass++;
            while (endgame == false)
            {
                Console.Clear();

                //Draw grid
                drawgrid();

                if (bulletx == enemybulletx && bullety == enemybullety)
                {
                    enemybulletexisting = false;
                    bulletexisting = false;
                    arr[enemybulletx,enemybullety] = emptychar;
                    arr[bulletx, bullety] = emptychar;
                }

                if (bulletexisting)
                {
                    if(bulletmovement == 'l')
                    {
                        arr[enemybullety, enemybulletx] = emptychar;
                        if (arr[bullety, bulletx - 1] == emptychar || arr[bullety, bulletx - 1] == enemychar)
                        {
                            arr[bullety, bulletx] = emptychar;
                            bulletx = bulletx - 1;
                            arr[bullety, bulletx] = bulletchar;
                        }
                        else
                        {
                            bulletexisting = false;
                            arr[bullety, bulletx] = emptychar;
                        }
                    }
                    if (bulletmovement == 'r')
                    {
                        arr[enemybullety, enemybulletx] = emptychar;
                        if (arr[bullety, bulletx + 1] == emptychar || arr[bullety, bulletx + 1] == enemychar)
                        {
                            arr[bullety, bulletx] = emptychar;
                            bulletx = bulletx + 1;
                            arr[bullety, bulletx] = bulletchar;
                        }
                        else
                        {
                            bulletexisting = false;
                            arr[bullety, bulletx] = emptychar;
                        }
                    }
                    if (bulletmovement == 'd')
                    {
                        arr[bullety, bulletx] = emptychar;
                        if (arr[bullety + 1, bulletx] == emptychar || arr[bullety + 1, bulletx] == enemychar)
                        {
                            bullety = bullety + 1;
                            arr[bullety, bulletx] = bulletchar;
                        }
                        else
                        {
                            bulletexisting = false;
                            arr[bullety, bulletx] = emptychar;
                        }
                    }
                    if (bulletmovement == 'u')
                    {
                        arr[bullety, bulletx] = emptychar;
                        if (arr[bullety - 1, bulletx] == emptychar || arr[bullety - 1, bulletx] == enemychar)
                        {
                            bullety = bullety - 1;
                            arr[bullety, bulletx] = bulletchar;
                        }
                        else
                        {
                            bulletexisting = false;
                            arr[bullety, bulletx] = emptychar;
                        }
                    }
                }

                if (enemybulletexisting)
                {
                    arr[enemybullety, enemybulletx] = emptychar;
                    if (enemybulletmovement == 'l')
                    {
                        arr[enemybullety, enemybulletx] = emptychar;
                        if (arr[enemybullety, enemybulletx - 1] == emptychar || arr[enemybullety, enemybulletx - 1] == playerchar)
                        {
                            arr[enemybullety, enemybulletx] = emptychar;
                            enemybulletx = enemybulletx - 1;
                            arr[enemybullety, enemybulletx] = bulletchar;
                        }
                        else
                        {
                            enemybulletexisting = false;
                            arr[enemybullety, enemybulletx] = emptychar;
                        }
                    }
                    if (enemybulletmovement == 'r')
                    {
                        arr[enemybullety, enemybulletx] = emptychar;
                        if (arr[enemybullety, enemybulletx + 1] == emptychar || arr[enemybullety, enemybulletx + 1] == playerchar)
                        {
                            arr[enemybullety, enemybulletx] = emptychar;
                            enemybulletx = enemybulletx + 1;
                            arr[enemybullety, enemybulletx] = bulletchar;
                        }
                        else
                        {
                            enemybulletexisting = false;
                            arr[enemybullety, enemybulletx] = emptychar;
                        }
                    }
                    if (enemybulletmovement == 'd')
                    {
                        arr[enemybullety, enemybulletx] = emptychar;
                        if (arr[enemybullety + 1, enemybulletx] == emptychar || arr[enemybullety + 1, enemybulletx] == playerchar)
                        {
                            enemybullety = enemybullety + 1;
                            arr[enemybullety, enemybulletx] = bulletchar;
                        }
                        else
                        {
                            enemybulletexisting = false;
                            arr[enemybullety, enemybulletx] = emptychar;
                        }
                    }
                    if (enemybulletmovement == 'u')
                    {
                        arr[enemybullety, enemybulletx] = emptychar;
                        if (arr[enemybullety - 1, enemybulletx] == emptychar || arr[enemybullety - 1, enemybulletx] == playerchar)
                        {
                            enemybullety = enemybullety - 1;
                            arr[enemybullety, enemybulletx] = bulletchar;
                        }
                        else
                        {
                            enemybulletexisting = false;
                            arr[enemybullety, enemybulletx] = emptychar;
                        }
                    }
                }

                finish();

                //Enemy

                //Ako je unutar zone
                if (Math.Abs(enemyx - playerx) <= mindistance && Math.Abs(enemyy - playery) <= mindistance)
                {
                    if (playery < enemyy)
                    {
                        for (int i = playery; i != enemyy; i++)
                        {
                            if (arr[i, playerx] != emptychar && arr[i, playerx] != playerchar && arr[i, playerx] != enemychar)
                            {
                                praznoy ++;
                            }
                        }
                    }
                    else if (playery > enemyy)
                    {
                        for (int i = playery; i != enemyy; i--)
                        {
                            if (arr[i,playerx] != emptychar && arr[i, playerx] != playerchar && arr[i, playerx] != enemychar)
                            {
                                praznoy ++;
                            }
                        }
                    }

                    else if (playerx < enemyx)
                    {
                        for (int i = playerx; i != enemyx; i++)
                        {
                            if (arr[playery, i] != emptychar && arr[playery, i] != playerchar && arr[playery, i] != enemychar)
                            {
                                praznox ++;
                            }
                        }
                    }
                    else if (playerx > enemyx)
                    {
                        for (int i = playerx; i != enemyx; i--)
                        {
                            if (arr[playery, i] != emptychar && arr[playery, i] != playerchar && arr[playery, i] != enemychar)
                            {
                                praznox ++;
                            }
                            else
                            {

                            }
                        }
                    }

                    if (praznox==0 && praznoy!=0)
                    {

                        //priblizi se po x
                        if (enemyx < playerx && arr[enemyy,enemyx+1]!=obstaclechar)
                        {
                            enemyx++;
                        }
                        else if (enemyx > playerx && arr[enemyy, enemyx - 1] != obstaclechar)
                        {
                            enemyx--;
                        }
                        arr[enemyprevy, enemyprevx] = emptychar;
                        arr[enemyy, enemyx] = enemychar;
                        enemyprevx = enemyx;
                        enemyprevy = enemyy;
                    }
                    if (praznoy==0&&praznox!=0)
                    {
                        //priblizi se po y
                        if (enemyy < playery && arr[enemyy + 1, enemyx] != obstaclechar)
                        {
                            enemyy++;
                        }
                        else if (enemyy > playery && arr[enemyy - 1, enemyx] != obstaclechar)
                        {
                            enemyy--;
                        }
                        arr[enemyprevy, enemyprevx] = emptychar;
                        arr[enemyy, enemyx] = enemychar;
                        enemyprevx = enemyx;
                        enemyprevy = enemyy;
                    }
                    if(praznox==0 && praznoy==0)
                    {
                        xapart = Math.Abs(playerx - enemyx);
                        yapart = Math.Abs(playery - enemyy);

                        if (playerx < enemyx && xapart>=yapart)
                        {
                            if (!enemybulletexisting)
                            {
                                puta++;
                                enemybulletexisting = true;
                                enemybulletmovement = 'l';
                                if (arr[enemyy, enemyx - 1] == emptychar)
                                {
                                    enemybulletx = enemyx - 1;
                                    enemybullety = enemyy;
                                    arr[enemybullety, enemybulletx] = bulletchar;
                                }
                                else
                                {
                                    enemybulletexisting = false;
                                }
                            }
                        }
                        if (playerx > enemyx && xapart>=yapart)
                        {
                            if (!enemybulletexisting)
                            {
                                puta++;
                                enemybulletexisting = true;
                                enemybulletmovement = 'r';
                                if (arr[enemyy, enemyx + 1] == emptychar)
                                {
                                    enemybulletx = enemyx + 1;
                                    enemybullety = enemyy;
                                    arr[enemybullety, enemybulletx] = bulletchar;
                                }
                                else
                                {
                                    enemybulletexisting = false;
                                }
                            }
                        }
                        if (playery < enemyy && yapart>=xapart)
                        {
                            if (!enemybulletexisting)
                            {
                                puta++;
                                enemybulletexisting = true;
                                enemybulletmovement = 'u';
                                if (arr[enemyy - 1, enemyx] == emptychar)
                                {
                                    enemybulletx = enemyx;
                                    enemybullety = enemyy - 1;
                                    arr[enemybullety, enemybulletx] = bulletchar;
                                }
                                else
                                {
                                    enemybulletexisting = false;
                                }
                            }
                        }
                        if (playery > enemyy && yapart>=xapart)
                        {
                            if (!enemybulletexisting)
                            {
                                puta++;
                                enemybulletexisting = true;
                                enemybulletmovement = 'd';
                                if (arr[enemyy + 1, enemyx] == emptychar)
                                {
                                    enemybulletx = enemyx;
                                    enemybullety = enemyy + 1;
                                    arr[enemybullety, enemybulletx] = bulletchar;
                                }
                                else
                                {
                                    enemybulletexisting = false;
                                }
                            }
                        }

                        if (playerx < enemyx && xapart < yapart)
                        {
                            if (playery < enemyy)
                            {
                                if (!enemybulletexisting)
                                {
                                    puta++;
                                    enemybulletexisting = true;
                                    enemybulletmovement = 'u';
                                    if (arr[enemyy - 1, enemyx] == emptychar)
                                    {
                                        enemybulletx = enemyx;
                                        enemybullety = enemyy - 1;
                                        arr[enemybullety, enemybulletx] = bulletchar;
                                    }
                                    else
                                    {
                                        enemybulletexisting = false;
                                    }
                                }
                            }
                            if(playery >= enemyy)
                            {
                                if (!enemybulletexisting)
                                {
                                    puta++;
                                    enemybulletexisting = true;
                                    enemybulletmovement = 'd';
                                    if (arr[enemyy + 1, enemyx] == emptychar)
                                    {
                                        enemybulletx = enemyx;
                                        enemybullety = enemyy + 1;
                                        arr[enemybullety, enemybulletx] = bulletchar;
                                    }
                                    else
                                    {
                                        enemybulletexisting = false;
                                    }
                                }
                            }
                        }
                        if (playerx > enemyx && xapart < yapart)
                        {
                            if (playery < enemyy)
                            {
                                if (!enemybulletexisting)
                                {
                                    puta++;
                                    enemybulletexisting = true;
                                    enemybulletmovement = 'u';
                                    if (arr[enemyy - 1, enemyx] == emptychar)
                                    {
                                        enemybulletx = enemyx;
                                        enemybullety = enemyy - 1;
                                        arr[enemybullety, enemybulletx] = bulletchar;
                                    }
                                    else
                                    {
                                        enemybulletexisting = false;
                                    }
                                }
                            }
                            if (playery >= enemyy)
                            {
                                if (!enemybulletexisting)
                                {
                                    puta++;
                                    enemybulletexisting = true;
                                    enemybulletmovement = 'd';
                                    if (arr[enemyy + 1, enemyx] == emptychar)
                                    {
                                        enemybulletx = enemyx;
                                        enemybullety = enemyy + 1;
                                        arr[enemybullety, enemybulletx] = bulletchar;
                                    }
                                    else
                                    {
                                        enemybulletexisting = false;
                                    }
                                }
                            }
                        }
                        if (playery < enemyy && yapart < xapart)
                        {
                            if (playerx < enemyx)
                            {
                                if (!enemybulletexisting)
                                {
                                    puta++;
                                    enemybulletexisting = true;
                                    enemybulletmovement = 'l';
                                    if (arr[enemyy, enemyx - 1] == emptychar)
                                    {
                                        enemybulletx = enemyx - 1;
                                        enemybullety = enemyy;
                                        arr[enemybullety, enemybulletx] = bulletchar;
                                    }
                                    else
                                    {
                                        enemybulletexisting = false;
                                    }
                                }
                            }
                            if (playerx >= enemyx)
                            {
                                if (!enemybulletexisting)
                                {
                                    puta++;
                                    enemybulletexisting = true;
                                    enemybulletmovement = 'r';
                                    if (arr[enemyy, enemyx + 1] == emptychar)
                                    {
                                        enemybulletx = enemyx + 1;
                                        enemybullety = enemyy;
                                        arr[enemybullety, enemybulletx] = bulletchar;
                                    }
                                    else
                                    {
                                        enemybulletexisting = false;
                                    }
                                }
                            }
                        }
                        if (playery > enemyy && yapart < xapart)
                        {
                            if (playerx < enemyx)
                            {
                                if (!enemybulletexisting)
                                {
                                    puta++;
                                    enemybulletexisting = true;
                                    enemybulletmovement = 'l';
                                    if (arr[enemyy, enemyx - 1] == emptychar)
                                    {
                                        enemybulletx = enemyx - 1;
                                        enemybullety = enemyy;
                                        arr[enemybullety, enemybulletx] = bulletchar;
                                    }
                                    else
                                    {
                                        enemybulletexisting = false;
                                    }
                                }
                            }
                            if (playerx >= enemyx)
                            {
                                if (!enemybulletexisting)
                                {
                                    puta++;
                                    enemybulletexisting = true;
                                    enemybulletmovement = 'r';
                                    if (arr[enemyy, enemyx + 1] == emptychar)
                                    {
                                        enemybulletx = enemyx + 1;
                                        enemybullety = enemyy;
                                        arr[enemybullety, enemybulletx] = bulletchar;
                                    }
                                    else
                                    {
                                        enemybulletexisting = false;
                                    }
                                }
                            }
                        }
                    }
                    if (praznoy == 0 && praznox == 0 && playerx!=enemyx && playery != enemyy)
                    {
                        if(strana == 'n')
                        {
                            r = rnd.Next(2);
                        }
                        if (r == 1 && playery!=enemyy)
                        {
                            strana = 'x';
                        }
                        else if(r==0 && playerx!=enemyx)
                        {
                            strana = 'y';
                        }
                        if (strana == 'y' && enemyx != playerx)
                        {
                            //priblizi se po y
                            if (enemyy < playery && arr[enemyy + 1, enemyx] != obstaclechar && arr[enemyy + 1, enemyx] != playerchar && arr[enemyy + 2, enemyx] != playerchar)
                            {
                                enemyy++;
                            }
                            else if (enemyy > playery && arr[enemyy - 1, enemyx] != obstaclechar && arr[enemyy - 1, enemyx] != playerchar && arr[enemyy - 2, enemyx] != playerchar)
                            {
                                enemyy--;
                            }
                            arr[enemyprevy, enemyprevx] = emptychar;
                            arr[enemyy, enemyx] = enemychar;
                            enemyprevx = enemyx;
                            enemyprevy = enemyy;
                        }
                        else if(strana == 'x' && enemyy != playery)
                        {
                            //priblizi se po x
                            if (enemyx < playerx && arr[enemyy, enemyx + 1] != obstaclechar && arr[enemyy, enemyx+1] != playerchar && arr[enemyy, enemyx + 2] != playerchar)
                            {
                                enemyx++;
                            }
                            else if (enemyx > playerx && arr[enemyy, enemyx - 1] != obstaclechar && arr[enemyy, enemyx-1] != playerchar && arr[enemyy, enemyx - 2] != playerchar)
                            {
                                enemyx--;
                            }
                            arr[enemyprevy, enemyprevx] = emptychar;
                            arr[enemyy, enemyx] = enemychar;
                            enemyprevx = enemyx;
                            enemyprevy = enemyy;
                        }
                    }
                }

                //Ako se po x priblizi a po y jos ne
                if (Math.Abs(enemyx - playerx) <= mindistance && Math.Abs(enemyy - playery) > mindistance)
                {
                    if (enemyy < playery && arr[enemyy + 1, enemyx] == emptychar) enemyy++;
                    if (enemyy > playery && arr[enemyy - 1, enemyx] == emptychar) enemyy--;
                    arr[enemyprevy, enemyprevx] = emptychar;
                    arr[enemyy, enemyx] = enemychar;
                    enemyprevx = enemyx;
                    enemyprevy = enemyy;
                }

                //Ako se po y priblizi a po x jos ne
                if (Math.Abs(enemyy - playery) <= mindistance && Math.Abs(enemyx - playerx) > mindistance)
                {
                    if (enemyx < playerx && arr[enemyy, enemyx + 1] == emptychar) enemyx++;
                    if (enemyx > playerx && arr[enemyy, enemyx - 1] == emptychar) enemyx--;
                    arr[enemyprevy, enemyprevx] = emptychar;
                    arr[enemyy, enemyx] = enemychar;
                    enemyprevx = enemyx;
                    enemyprevy = enemyy;
                }

                //Ako je dalje od zone i po x i po y
                if (Math.Abs(enemyx - playerx)>mindistance && Math.Abs(enemyy - playery) > mindistance){
                    int enemyrndmovement = rnd.Next(2);
                    arr[enemyprevy, enemyprevx] = emptychar;
                    //if (enemyx != playerx && enemyy == playery)
                    //{
                    //    if (enemyx < playerx && arr[enemyy, enemyx+1] == emptychar)
                    //    {
                    //        enemyx++;
                    //    }
                    //    else if (enemyx > playerx && arr[enemyy, enemyx - 1] == emptychar)
                    //    {
                    //        enemyx--;
                    //    }
                    //}
                    //else if (enemyy != playery && enemyx == playerx)
                    //{
                    //    if (enemyy < playery && arr[enemyy+1, enemyx] == emptychar)
                    //    {
                    //        enemyy++;
                    //    }
                    //    else if (enemyy > playery && arr[enemyy-1, enemyx] == emptychar)
                    //    {
                    //        enemyy--;
                    //    }
                    //}
                    if (enemyx != playerx && enemyy != playery)
                    {
                        if (enemyrndmovement == 1)
                        {
                            if (enemyx < playerx && arr[enemyy, enemyx+1] == emptychar)
                            {
                                enemyx++;
                            }
                            else if (enemyx > playerx && arr[enemyy, enemyx-1] == emptychar)
                            {
                                enemyx--;
                            }
                        }
                        else
                        {
                            if (enemyy < playery && arr[enemyy+1, enemyx] == emptychar)
                            {
                                enemyy++;
                            }
                            else if (enemyy > playery && arr[enemyy-1, enemyx] == emptychar)
                            {
                                enemyy--;
                            }
                        }
                    }
                    arr[enemyy,enemyx] = enemychar;
                    enemyprevx = enemyx;
                    enemyprevy = enemyy;
                }

                Thread.Sleep(150);
            }
        }

        static void Main(string[] args)
        {
            enemybulletexisting = false;
            bulletexisting = false;
            System.Console.CursorVisible = false;
            endgame = false;
            //Console.Write("Made by: Bager");
            Console.Write("Battlefield height (Recommended 15-25): ");
            red = Convert.ToInt32(Console.ReadLine());
            Console.Write("Battlefield width (Recommended 15-25): ");
            stupac = Convert.ToInt32(Console.ReadLine());
            Console.Write("Obstacle percentage (Recommended 2-15): ");
            obstaclepercentage = Convert.ToInt32(Console.ReadLine());
            Console.Clear();
            mindistance = Math.Min(red, stupac);
            mindistance = mindistance / 5;

            //Field generator

            rnd = new Random();
            arr = new char[red, stupac];
            for (int i = 0; i < red; i++)
            {
                for (int j = 0; j < stupac; j++)
                {
                    if (i == 0 || j == 0 || i == red - 1 || j == stupac - 1)
                    {
                        arr[i, j] = edgechar;
                    }
                    else
                    {
                        arr[i, j] = emptychar;
                    }
                }
            }

            //Obsticles
            int r;
            for (int i = 1; i < red - 1; i++)
            {
                for (int j = 1; j < stupac - 1; j++)
                {
                    r = rnd.Next(100);
                    if (r < obstaclepercentage)
                    {
                        arr[i, j] = obstaclechar;
                    }
                }
            }

            //Setup
            playerx = 1;
            playery = 1;
            prevpx = 1;
            prevpy = 1;
            enemyx = stupac-2;
            enemyy = red-2;
            enemyprevx = stupac - 2;
            enemyprevy = red - 2;
            arr[playery,playerx] = playerchar;
            arr[enemyy,enemyx] = enemychar;
            praznox = 0;
            praznoy = 0;
            strana = 'n';

            drawgrid();

            //Background start process
            var ts = new ThreadStart(BackgroundMethod);
            var backgroundThread = new Thread(ts);
            backgroundThread.Start();

            //Movement
            ConsoleKeyInfo control;
            time = DateTime.Now;
            while(endgame==false)
            {
                prevpx = playerx;
                prevpy = playery;
                if (Console.KeyAvailable)
                {
                    control = Console.ReadKey(true);
                    if (DateTime.Now - time > TimeSpan.FromSeconds(0.6))
                    {
                        switch (control.Key)
                        {
                            case ConsoleKey.D:
                                if (arr[playery, playerx + 1] == emptychar && playerx < stupac)
                                {
                                    playerx++;
                                    arr[prevpy, prevpx] = emptychar;
                                    arr[playery, playerx] = playerchar;
                                    praznox = 0;
                                    praznoy = 0;
                                    strana = 'n';
                                }
                                break;
                            case ConsoleKey.A:
                                if (arr[playery, playerx - 1] == emptychar && playerx > 0)
                                {
                                    playerx--;
                                    arr[prevpy, prevpx] = emptychar;
                                    arr[playery, playerx] = playerchar;
                                    praznox = 0;
                                    praznoy = 0;
                                    strana = 'n';
                                }

                                break;
                            case ConsoleKey.S:
                                if (arr[playery + 1, playerx] == emptychar && playery < red)
                                {
                                    playery++;
                                    arr[prevpy, prevpx] = emptychar;
                                    arr[playery, playerx] = playerchar;
                                    praznox = 0;
                                    praznoy = 0;
                                    strana = 'n';
                                }
                                break;
                            case ConsoleKey.W:
                                if (arr[playery - 1, playerx] == emptychar && playery > 0)
                                {
                                    playery--;
                                    arr[prevpy, prevpx] = emptychar;
                                    arr[playery, playerx] = playerchar;
                                    praznox = 0;
                                    praznoy = 0;
                                    strana = 'n';
                                }
                                break;

                            //Bullet spawn
                            case ConsoleKey.LeftArrow:
                                if (!bulletexisting) {
                                    bulletexisting = true;
                                    bulletmovement = 'l';
                                    if (arr[playery, playerx - 1] == ' ')
                                    {
                                        bulletx = playerx - 1;
                                        bullety = playery;
                                        arr[bullety, bulletx] = bulletchar;
                                    }
                                    else
                                    {
                                        bulletexisting = false;
                                    }
                                }
                                
                                break;
                            case ConsoleKey.RightArrow:
                                if (!bulletexisting) {
                                    bulletexisting = true;
                                    bulletmovement = 'r';
                                    if (arr[playery, playerx + 1] == ' ')
                                    {
                                        bulletx = playerx + 1;
                                        bullety = playery;
                                        arr[bullety, bulletx] = bulletchar;
                                    }
                                    else
                                    {
                                        bulletexisting = false;
                                    }
                                }
                                    
                                break;
                            case ConsoleKey.DownArrow:
                                if (!bulletexisting) {
                                    bulletexisting = true;
                                    bulletmovement = 'd';
                                    if (arr[playery + 1, playerx] == ' ')
                                    {
                                        bulletx = playerx;
                                        bullety = playery + 1;
                                        arr[bullety, bulletx] = bulletchar;
                                    }
                                    else
                                    {
                                        bulletexisting = false;
                                    }
                                }
                                    
                                break;
                            case ConsoleKey.UpArrow:
                                if (!bulletexisting) {
                                    bulletexisting = true;
                                    bulletmovement = 'u';
                                    if (arr[playery - 1, playerx] == ' ')
                                    {
                                        bulletx = playerx;
                                        bullety = playery - 1;
                                        arr[bullety, bulletx] = bulletchar;
                                    }
                                    else
                                    {
                                        bulletexisting = false;
                                    }
                                }
                                    
                                break;

                            case ConsoleKey.Escape:
                                endgame = true;
                                break;
                        }

                        time = DateTime.Now;
                    }
                }
            }
            Thread.Sleep(500);
            if (winner == 'E')
            {
                Console.WriteLine("You lose");
            }
            if (winner == 'P')
            {
                Console.WriteLine("You win");
            }
            Thread.Sleep(1500);
        }
    }
}