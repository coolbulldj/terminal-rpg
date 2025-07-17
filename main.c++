#include <vector>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

const int _fps = 60;

class display {
    public:

    int _window_x;
    int _window_y;
    vector<string> _window_display;

    display(const int _x, const int _y) {
        _window_x = _x;
        _window_y = _y;
        _window_display = vector<string>(_x * _y, " ");
    }

    void update() {
        system("clear"); // Clear the terminal screen
        // Update logic here
        for (int y = 0; y < this->_window_y; y++) { //int y = 0; y < this->_window_y; y+
            string current_line;
            for (int x = 0; x < this->_window_x; x++) {
                current_line += this->_window_display[x * _window_y + y];
            }
            cout << current_line << endl;
        }
    }
};

class image {
    public:

    int _image_x;
    int _image_y;
    vector<string> _image_data;

    image(const int _x, const int _y) {
        _image_x = _x;
        _image_y = _y;
        _image_data = vector<string>(_x * _y, " "); // Initialize with spaces
    }

    void draw(display &disp, const int x_pos, const int y_pos) {
        // Draw logic here
        for (int y = 0; y < this->_image_y; y++) {
            for (int x = 0; x < this->_image_x; x++) {
                disp._window_display[x * disp._window_y + y] = this->_image_data[x * this->_image_y + y];
            }
        }
    }
};

int main() {
    //do shit
    display myDisplay(30, 10);

    myDisplay._window_display = vector<string>(300, "\u25A0"); // Fill with spaces for demonstration

    image myImage(10, 5);
    myImage._image_data = vector<string>(50, "c"); // Fill with '*' for demonstration
    myImage.draw(myDisplay, 10, 5);



    const int time_per_frame = static_cast<int>( 1000 / _fps ); // Time per frame in milliseconds

      while (true)
      {

        myDisplay.update();

        std::this_thread::sleep_for(chrono::milliseconds(time_per_frame)); // Sleep for the time per frame
      }
      
};