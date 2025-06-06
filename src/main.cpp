#include "Window/Window.hpp"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main() {
  Window window;
  if (window.init("e", SCREEN_WIDTH, SCREEN_HEIGHT))
    window.run();
  return 0;
}
