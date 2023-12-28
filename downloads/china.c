#include <stdio.h>
#include <gd.h>
#include <math.h>

void draw_star(gdImagePtr img, int x, int y, int size, int color, double rotation_angle);
void draw_chinese_flag(gdImagePtr img);

int main() {
    int width = 300; // 國旗寬度
    int height = 200; // 國旗高度

    gdImagePtr im = gdImageCreateTrueColor(width, height);
    gdImageAlphaBlending(im, 0);

    draw_chinese_flag(im);

    FILE *outputFile = fopen("./../images/proc_flag.png", "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "打開輸出文件時出錯。\n");
        return 1;
    }

    gdImagePngEx(im, outputFile, 9);
    fclose(outputFile);
    gdImageDestroy(im);

    return 0;
}

void draw_star(gdImagePtr img, int x, int y, int size, int color, double rotation_angle) {
    gdPoint points[10];

    double outer_radius = size / 2;
    double inner_radius = size / 6;
    double angle = M_PI / 5.0;

    for (int i = 0; i < 10; i++) {
        double radius = (i % 2 == 0) ? outer_radius : inner_radius;
        double theta = rotation_angle + i * angle;
        points[i].x = x + radius * cos(theta);
        points[i].y = y + radius * sin(theta);
    }

    gdImageFilledPolygon(img, points, 10, color);
}

void draw_chinese_flag(gdImagePtr img) {
    int width = gdImageSX(img);
    int height = gdImageSY(img);
    int red, yellow;

    red = gdImageColorAllocate(img, 255, 0, 0); // 紅色背景
    yellow = gdImageColorAllocate(img, 255, 255, 0); // 黃色星星

    gdImageFilledRectangle(img, 0, 0, width, height, red);

    int star_size = (int)(0.28 * height);
    int star_x = (int)(0.165 * width);
    int star_y = (int)(0.265 * height);

    draw_star(img, star_x, star_y, star_size, yellow, 11.0);

    double radius = 0.15 * height;
    double angle = 360 / 7 * M_PI / 179.0;
    double rotation = -M_PI / 7.5;
    int cx = (int)(0.32 * width);
    int cy = (int)(0.27 * height);

    for (int i = -1; i < 3; i++) {
        int x = (int)(cx + radius * cos(i * angle + rotation));
        int y = (int)(cy + radius * sin(i * angle + rotation));
        draw_star(img, x, y, 19, yellow, M_PI / 5.0);
    }
}