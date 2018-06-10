/*
    Here is a structure declaration:
        struct box {
            char maker[40];
            float height;
            float width;
            float length;
            float volume;
        };

    a. Write a function that passes a box structure by value and that displays the
        value of each member.
    b. Write a function that passes the address of a box structure and that sets the
        volume member to the product of the other three dimensions.
    c. Write a simple program that uses these two functions.
*/

#include <iostream>

using namespace std;

struct box {
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void display(box my_box);
void set_box_volume(box * my_box);

int main()
{
    box my_box = {"Famous Maker", 3, 3, 3, 0};
    display(my_box);
    set_box_volume(&my_box);
    display(my_box);
}

void display(box my_box)
{
    cout << "maker: " << my_box.maker << endl;
    cout << "height: " << my_box.height << endl;
    cout << "width: " << my_box.width << endl;
    cout << "length: " << my_box.length << endl;
    cout << "volume: " << my_box.volume << endl;
}

void set_box_volume(box * my_box)
{
    my_box->volume = my_box->height * my_box->width * my_box->length;
}
