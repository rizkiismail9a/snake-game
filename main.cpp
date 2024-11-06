#include <iostream>
#include <raylib.h>

using namespace std;

Color backgroundCanvas = {173, 204, 96, 255};
Color darkGreen = {43, 51, 24, 255};

int cellSize = 30;
int cellCount = 25;

class Food
{
public:
    Vector2 position = {5, 6};

    void Draw()
    {
        DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize, cellSize, darkGreen);
    }
};

int main()
{

    cout << "Program berjalan dengan baik" << endl;
    /**
     * Suatu game itu terdiri dari dua bagian
     * Canvas dan game loop
     */

    // Ini untuk buat canvas
    InitWindow(cellSize * cellCount, cellSize * cellCount, "Snake game");
    SetTargetFPS(60); // Set frame rate, jika tidak, computer bakal run game secepat yang dia bisa

    Food food;

    // Kita loop di sini
    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        // Warnai background
        ClearBackground(backgroundCanvas);
        food.Draw();

        EndDrawing();
    }

    // Jangan lupa destroy window yang udah dibuka
    CloseWindow();
    return 0;
}