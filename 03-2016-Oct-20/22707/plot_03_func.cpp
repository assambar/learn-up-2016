#include <iostream>

const char* const SVG_BEGIN =
    "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">";
const char* const SVG_END =
    "</svg>";

void drawLine(int lineX1, int lineY1, int lineX2, int lineY2, const char* const lineStroke, int lineWidth) {
   std::cout << "<line x1=\"" << lineX1 << "\" y1=\"" << lineY1 
          << "\" x2=\"" << lineX2 << "\" y2=\"" << lineY2
          << "\" stroke=\"" << lineStroke 
          << "\" stroke-width=\"" << lineWidth << "\" />" << std::endl;
}
    
int main() {
    std::cout << SVG_BEGIN << std::endl;
    int rectX = 25;
    int rectY = 25;
    std::cout << "<rect x=\"" << rectX <<  "\" y=\"" << rectY << "\" width=\"200\" height=\"200\" fill=\"lime\" stroke-width=\"4\" stroke=\"pink\" />" << std::endl;
    std::cout << "<circle cx=\"125\" cy=\"125\" r=\"75\" fill=\"orange\" />" << std::endl;
    std::cout << "<polyline points=\"50,150 50,200 200,200 200,100\" stroke=\"red\" stroke-width=\"4\" fill=\"none\" />" << std::endl;
    std::cout << "<line x1=\"50\" y1=\"50\" x2=\"200\" y2=\"200\" stroke=\"blue\" stroke-width=\"4\" />" << std::endl;
    
    drawLine(150, 50, 230, 200, "yellow", 3);    
    drawLine(50, 150, 200, 250, "green", 2);    
           
    std::cout << "<line x1=\"230\" y1=\"90\" x2=\"200\" y2=\"200\" stroke=\"blue\" stroke-width=\"1\" />" << std::endl;
    
    std::cout << SVG_END;
}