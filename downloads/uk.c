#include <stdio.h>
#include <gd.h>
#include <math.h>

void draw_uk_flag(gdImagePtr img);
void fillTriangle(gdImagePtr img, int x1, int y1, int x2, int y2, int x3, int y3, int color);

int main() {
    int width = 1200;
    int height = width / 2;

    gdImagePtr img = gdImageCreateTrueColor(width, height);
    gdImageAlphaBlending(img, 0);

    draw_uk_flag(img);

    FILE *outputFile = fopen("./../images/uk_flag.png", "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "打開輸出文件時發生錯誤。\n");
        return 1;
    }

    gdImagePngEx(img, outputFile, 9);
    fclose(outputFile);
    gdImageDestroy(img);

    return 0;
}

void draw_uk_flag(gdImagePtr img) {
    int width = gdImageSX(img);
    int height = gdImageSY(img);

    int red, white, blue;
    red = gdImageColorAllocate(img, 204, 0, 0);
    white = gdImageColorAllocate(img, 255, 255, 255);
    blue = gdImageColorAllocate(img, 0, 0, 153);

    gdImageFilledRectangle(img, 0, 0, width, height, blue);

    // 繪製斜線
    {
        int line_thickness = 100;
        gdImageSetThickness(img, line_thickness);

        // 繪製白色斜線
        int x1 = 0, y1 = 600, x2 = 1200, y2 = 0;
        gdImageLine(img, x1, y1, x2, y2, white);

        x1 = 0, y1 = 0, x2 = 1200, y2 = 600;
        gdImageLine(img, x1, y1, x2, y2, white);
    }

    // 繪製紅色斜線
    {
        int line_thickness = 33;
        gdImageSetThickness(img, line_thickness);

        // 繪製紅色斜線
        int x1 = 566, y1 = 300, x2 = 1166, y2 = 0;
        gdImageLine(img, x1, y1, x2, y2, red);

        x1 = 1233, y1 = 600, x2 = 633, y2 = 300;
        gdImageLine(img, x1, y1, x2, y2, red);

        x1 = 566, y1 = 300, x2 = -33, y2 = 0;
        gdImageLine(img, x1, y1, x2, y2, red);

        x1 = 600, y1 = 316.5, x2 = 0, y2 = 616.5;
        gdImageLine(img, x1, y1, x2, y2, red);
    }

    // 繪製白色斜線
    {
        int line_thickness = 33;
        gdImageSetThickness(img, line_thickness);

        // 繪製斜線
        int x1 = 0, y1 = 600, x2 = 1200, y2 = 0;
        gdImageLine(img, x1, y1, x2, y2, red);

        x1 = 1200, y1 = 16.5, x2 = 600, y2 = 316.5;
        gdImageLine(img, x1, y1, x2, y2, white);

        x1 = 0, y1 = 583.5, x2 = 600, y2 = 283.5;
        gdImageLine(img, x1, y1, x2, y2, white);
    }

    // 繪製白色十字
    int cross_width = width / 32;
    int cross_arm_width = width / 32;
    int center_x = width / 2;
    int center_y = height / 2;

    gdImageFilledRectangle(img, center_x + 2.7 * cross_width, 0, center_x - 2.7 * cross_width, height, white);
    gdImageFilledRectangle(img, 0, center_y + 2.7 * cross_arm_width, width, center_y - 2.7 * cross_arm_width, white);

    // 繪製紅色十字
    gdImageFilledRectangle(img, center_x + 1.5 * cross_width, 0, center_x - 1.5 * cross_width, height, red);
    gdImageFilledRectangle(img, 0, center_y + 1.5 * cross_arm_width, width, center_y - 1.5 * cross_arm_width, red);
}