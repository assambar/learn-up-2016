#include <iostream>

const char* const SVG_BEGIN =
    "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">";
const char* const SVG_END =
    "</svg>";

int main() {
    std::cout << SVG_BEGIN << std::endl;
    std::cout << "<rect x=\"25\" y=\"25\" width=\"200\" height=\"200\" fill=\"lime\" stroke-width=\"4\" stroke=\"pink\" />" << std::endl;
    std::cout << "<circle cx=\"125\" cy=\"125\" r=\"75\" fill=\"orange\" />" << std::endl;
    std::cout << "<polyline points=\"50,150 50,200 200,200 200,100\" stroke=\"red\" stroke-width=\"4\" fill=\"none\" />" << std::endl;
    std::cout << "<line x1=\"50\" y1=\"50\" x2=\"200\" y2=\"200\" stroke=\"blue\" stroke-width=\"4\" />" << std::endl;
    std::cout << SVG_END;
}