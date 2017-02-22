#include <iostream>

const char* const SVG_BEGIN =
    "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"500\" height=\"500\">";
const char* const SVG_END =
    "</svg>";

void drawLine(int lineX1, int lineY1, int lineX2, int lineY2, const char* const lineStroke, int lineWidth) {
   std::cout << "<line x1=\"" << lineX1 << "\" y1=\"" << lineY1 
          << "\" x2=\"" << lineX2 << "\" y2=\"" << lineY2
          << "\" stroke=\"" << lineStroke 
          << "\" stroke-width=\"" << lineWidth << "\" />" << std::endl;
}

void drawCircle(int cx, int cy, int r, const char* const color) {
    std::cout << "<circle cx=\"" << cx << "\" cy=\"" << cy << "\" r=\"" << r << "\" fill=\"" << color << "\" />" << std::endl;
}
    
int main() {
    std::cout << SVG_BEGIN << std::endl;    
    int rectX = 25;
    int rectY = 25;
    std::cout << "<rect x=\"" << rectX <<  "\" y=\"" << rectY << "\" width=\"200\" height=\"200\" fill=\"lime\" stroke-width=\"4\" stroke=\"pink\" />" << std::endl;  
    std::cout << "<polyline points=\"50,150 50,200 200,200 200,100\" stroke=\"red\" stroke-width=\"4\" fill=\"none\" />" << std::endl;
    
    drawLine(150, 50, 230, 200, "yellow", 3);    
   
    for(int i=0; i <= 25; i++) {
        const char* color;
        switch(i%5) {
            case 0: color = "red"; break;
            case 1: color = "green"; break;
            case 2: color = "blue"; break;
            case 3: color = "yellow"; break;
            case 4: color = "pink"; break;
        }
        int coordinateValue = i * 25;
        drawCircle(coordinateValue, coordinateValue, 5, color);
    }
    std::cout << SVG_END;
}