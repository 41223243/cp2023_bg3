#include <stdio.h>
#include <gd.h>
#include <stdlib.h>

void drawJapaneseFlag() {
    int width = 300;   // 寬度
    int height = 200;  // 高度
    int radius = 50;   // 圓圈半徑
    int centerX = 150; // 圓圈中心X座標
    int centerY = 100; // 圓圈中心Y座標

    // 創建一個 24 位的彩色圖片
    gdImagePtr im = gdImageCreateTrueColor(width, height);

    // 設置背景色為白色
    int white = gdImageColorAllocate(im, 255, 255, 255);
    gdImageFill(im, 0, 0, white);

    // 設置圓圈的顏色為紅色
    int red = gdImageColorAllocate(im, 255, 0, 0);

    // 畫紅色圓圈
    gdImageFilledEllipse(im, centerX, centerY, 2 * radius, 2 * radius, red);

    // 輸出圖片到檔案
    FILE *output = fopen("japanese_flag.png", "wb");
    if (output == NULL) {
        fprintf(stderr, "Unable to open file for writing.\n");
        exit(EXIT_FAILURE);
    }

    gdImagePng(im, output);

    // 釋放內存
    gdImageDestroy(im);
    fclose(output);
}

int main() {
    drawJapaneseFlag();
    printf("Japanese flag created: japanese_flag.png\n");
    return 0;
}