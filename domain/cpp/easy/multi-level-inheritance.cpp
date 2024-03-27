#include <iostream>

using namespace std;
class Rectangle{
    
    private:
    int width, height;
    
    public:

    Rectangle(){
        cin >> width >> height;
    }
    
    int getWidth(){
        return width;
    }
    
    int getHeight(){
        return height;
    }
    
    void display(){
        cout << width << " " << height << endl;
    }
};

class RectangleArea: public Rectangle{
    private:
    int width, height, area;
    
    public:
    void read_input(){
        width = getWidth();
        height = getHeight();
    }
    
    void display(){
        area = width * height;
        cout << area;
    }
};


int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;
    
    /*
     * Read the width and height
     */
    r_area.read_input();
    
    /*
     * Print the width and height
     */
    r_area.Rectangle::display();
    
    /*
     * Print the area
     */
    r_area.display();
    
    return 0;
}