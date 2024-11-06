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
    Texture2D texture;

    Food()
    {
        Image image = LoadImage("graphic/dessert.png");
        // Setelah gambar didapat, kita perlu mengubahnya menjadi texture agar bisa dirender
        texture = LoadTextureFromImage(image);

        // Jangan lupa unload untuk membersikan memori
        UnloadImage(image);
    }

    // Di C++ fungsi constructor bisa dihancurkan
    ~Food()
    {
        UnloadTexture(texture);
    }

    void Draw()
    {
        // Kita udah punya gambar, sekarang kita timpa kotak itu dengan gambar burger
        // DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize, cellSize, darkGreen);

        DrawTexture(texture, position.x * cellSize, position.y * cellSize, WHITE);
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

    Food food = Food();

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