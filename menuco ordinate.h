#include <iostream>
#include "iGraphics.h"

void iDraw()
{
    // Your drawing code here
}

void iMouseMove(int mx, int my)
{
    std::cout << "Mouse coordinates: (" << mx << ", " << my << ")" << std::endl;
}

int main()
{
    iInitialize(800, 600, "Graphics Example");
    iSetMouseMoveCallback(iMouseMove);
    iStart();

    return 0;
}
