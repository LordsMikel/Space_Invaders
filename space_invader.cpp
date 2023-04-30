//**************************************************************************
//**************************************************************************
// C++ program to implement Space Invaders game
// Author:  Miguel Medina Cantos
// Grade: Computer engineering - 3th year
// Date:    2023/04/30
// Version: 1.0
// Purpose: Space Invaders game
//**************************************************************************
//**************************************************************************

//**************************************************************************
//Historia de Space Invaders:
//Space Invaders es un videojuego de arcade diseñado por Tomohiro Nishikado y lanzado al mercado en 1978.
//Es uno de los primeros juegos de disparos de la historia, además de ser el primero en permitir que el jugador controle un cañón y dispararle a una horda de alienígenas en movimiento.
//El objetivo es destruir oleadas de alienígenas con un cañón láser y obtener la mayor cantidad de puntos posible.
//Space Invaders fue un éxito comercial, sentando las bases para la industria de los videojuegos.
//Se convirtió en el videojuego más vendido de la época y un clásico de la cultura popular.
//El éxito de Space Invaders llevó a la industria de los videojuegos a entrar en una nueva era, y fue el primer éxito mundial de la industria del entretenimiento electrónico.
//En 2007, la revista Time incluyó a Space Invaders en su lista de los 100 mejores videojuegos de todos los tiempos.
//En 2016, el juego fue galardonado con el Premio a la Excelencia en el Festival Fun & Serious Game de Bilbao.
//Curiosidades:
//El juego fue diseñado por Tomohiro Nishikado, que se inspiró en Breakout, The War of the Worlds y Star Wars.
//El juego fue programado por Nishikado y lanzado en 1978 por Taito Corporation.
//El juego fue un éxito comercial, sentando las bases para la industria de los videojuegos.
//Se convirtió en el videojuego más vendido de la época y un clásico de la cultura popular.
//**************************************************************************


//Librerías:
#include <iostream>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <ncurses.h>
#include <chrono>
#include <thread>

//Definiciones:
#define WIDTH 30
#define HEIGHT 20

//Clase Game:
class Game
{
public:
    //Atributos:
    std::vector<std::string> board;
    int playerPos;
    std::vector<int> bullets;
    std::vector<int> aliens;
    int score;

    //Métodos:
    Game() : playerPos(WIDTH / 2), score(0)
    {
        srand(time(0));
        for (int i = 0; i < HEIGHT; i++)
        {
            board.push_back(std::string(WIDTH, ' '));
        }
    }

    //Métodos:
    //Función para dibujar:
    void draw()
    {
        //Bucle para dibujar:
        erase();
        for (int bullet : bullets)
        {
            mvaddch(bullet / WIDTH, bullet % WIDTH, '|');
        }
        for (int alien : aliens)
        {
            mvaddch(alien / WIDTH, alien % WIDTH, 'V');
        }
        mvaddch(HEIGHT - 1, playerPos, '^');
        for (int i = 0; i < HEIGHT; ++i)
        {
            mvaddch(i, 0, '|');
            mvaddch(i, WIDTH - 1, '|');
        }
        for (int i = 0; i < WIDTH; ++i)
        {
            mvaddch(HEIGHT, i, '-');
        }
        mvprintw(HEIGHT + 1, 0, "Puntuación: %d\n", score);
        mvprintw(HEIGHT + 2, 0, "Use 'a' para mover a la izquierda, 'd' para mover a la derecha, 's' para disparar, 'q' para salir.\n");
        refresh();
    }
    //Función para actualizar:
    void update()
    {
        static int updateCounter = 0;  // Contador de actualizaciones
        const int alienMoveDelay = 10; // Número de actualizaciones antes de mover los aliens

        if (rand() % 10 == 0)
        {
            aliens.push_back(rand() % WIDTH);
        }

        // Sólo mover los aliens cada alienMoveDelay actualizaciones
        if (updateCounter == alienMoveDelay)
        {
            std::vector<int> newAliens;
            for (int &alien : aliens)
            {
                int newAlien = alien + WIDTH;
                if (newAlien < WIDTH * HEIGHT)
                {
                    newAliens.push_back(newAlien);
                }
            }
            aliens = newAliens;

            updateCounter = 0; // Reiniciar el contador
        }
        else
        {
            updateCounter++; // Incrementar el contador
        }

        std::vector<int> newBullets;
        for (int &bullet : bullets)
        {
            int newBullet = bullet - WIDTH;
            if (newBullet >= 0)
            {
                newBullets.push_back(newBullet);
            }
        }
        bullets = newBullets;

        for (int bullet : bullets)
        {
            auto it = std::find(aliens.begin(), aliens.end(), bullet);
            if (it != aliens.end())
            {
                aliens.erase(it);
                score++;
            }
        }

        for (std::string &line : board)
        {
            line = std::string(WIDTH, ' ');
        }
    }

    
    //Función para manejar la entrada:
    //opciones: 'a' para mover a la izquierda, 'd' para mover a la derecha, 's' para disparar, 'q' para salir.
    void handleInput(int input)
    {
        if (input == 'a' && playerPos > 0)
        {
            playerPos--;
        }
        if (input == 'd' && playerPos < WIDTH - 1)
        {
            playerPos++;
        }
        if (input == 's')
        {
            bullets.push_back((HEIGHT - 1) * WIDTH + playerPos);
        }
    }

    //Función para ejecutar:
    void run()
    {
        using namespace std::chrono;

        // Define el número de frames por segundo
        const int FPS = 10;
        const milliseconds FRAME_DURATION(1000 / FPS);
        //nodelay(stdscr, TRUE); // Enable non-blocking input sirve para que no se quede esperando a que el usuario introduzca un caracter
        nodelay(stdscr, TRUE); // Enable non-blocking input
        while (true)
        {
            //frameStart sirve para medir el tiempo que tarda en dibujar un frame
            auto frameStart = high_resolution_clock::now();

            draw();
            int input = getch(); // Get user input
            if (input == 'q')
            {
                break;
            }
            handleInput(input);
            update();

            auto frameEnd = high_resolution_clock::now();
            auto frameTime = duration_cast<milliseconds>(frameEnd - frameStart);

            if (frameTime < FRAME_DURATION)
            {
                std::this_thread::sleep_for(FRAME_DURATION - frameTime);
            }
        }
    }
};

int main()
{
    initscr(); // Initialize the library
    cbreak();  // Line buffering disabled
    noecho();  // Don't echo() while we getch

    Game game;
    game.run();

    endwin(); // End curses mode

    return 0;
}
