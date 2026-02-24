#include <stdio.h>
#include <unistd.h>
#include <math.h>

// ########## SETTINGS ##########

#define H 30
#define W 120
const char fill_square = '#';
const char fill_background = ' ';
const size_t square_size = 20;
const double speed = 1;
const double angle_step = 0.1;  // in radians

// ########## SETTINGS ##########

typedef struct {
    double x, y;    
} Point;


Point get_rotated_point(Point p, double angle) {
    Point rotated;
    rotated.x = p.x * cos(angle) - p.y * sin(angle);
    rotated.y = p.x * sin(angle) + p.y * cos(angle);

    return rotated;
}

int main() {
    Point center = {W / 2, H / 2};

    double angle = 0;

    while (1) {
        printf("\033c");

        for (int y = 0; y < H; y++) {
            for(int x = 0; x < W; x++) {
                Point point = get_rotated_point((Point){x - center.x, (center.y - y) * 2}, angle);

                if ((int)round(fabs(point.x)) <= square_size / 2 && (int)round(fabs(point.y)) <= square_size / 2) {
                    putchar(fill_square);
                } else {
                    putchar(fill_background);
                }
            }
            printf("\n");
        }

        angle += angle_step;

        usleep(50000 / speed);
    }
}
