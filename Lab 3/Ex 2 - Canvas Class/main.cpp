#include "Canvas.h"
#include <iostream>

using namespace std;

int main() {
    
    Canvas canvas(20, 20);

    //Circle: centru 10,10, rad 5, cu O
    canvas.DrawCircle(10, 10, 5, 'O');
    cout << "Printing canvas:" << endl;
    canvas.Print();
    cout << endl;

    //Fill circle centru la (15, 15), rad 4, cu 'C'
    canvas.FillCircle(15, 15, 4, 'C');
    cout << "Printing canvas:" << endl;
    canvas.Print();
    cout << endl;

    //Draw rectangle top-left corner (2, 2), bottom-right corner (8, 6), cu 'R'
    canvas.DrawRect(2, 2, 8, 6, 'R');
    cout << "Printing canvas::" << endl;
    canvas.Print();
    cout << endl;

    //Fill rectangle: top-left corner (12, 2), bottom-right corner (18, 6), cu 'F'
    canvas.FillRect(12, 2, 18, 6, 'F');
    cout << "Printing canvas:" << endl;
    canvas.Print();
    cout << endl;

    //Set point la (5, 5) cu 'P'
    canvas.SetPoint(5, 5, 'P');
    cout << "Printing canvas:" << endl;
    canvas.Print();
    cout << endl;

    //Draw a line de la (1, 1) la (10, 10) cu 'L'
    canvas.DrawLine(1, 1, 10, 10, 'L');
    cout << "Printing canvas:" << endl;
    canvas.Print();
    cout << endl;

    //Clear
    canvas.Clear();
    cout << "Canvas after clear:" << endl;
    canvas.Print();
    cout << endl;

    return 0;
}