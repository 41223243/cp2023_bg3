#include <stdio.h>
#include <gd.h>
#include <math.h>

// Declare the rotation function
void rotateFilledPolygon(int x_orig, int y_orig, double rotation_ang, gdPoint *points, int num_points) {
    int i;
    double angle_rad = rotation_ang * M_PI / 180.0;

    for (i = 0; i < num_points; i++) {
        int x = points[i].x - x_orig;
        int y = points[i].y - y_orig;

        points[i].x = x_orig + (int)(x * cos(angle_rad) - y * sin(angle_rad));
        points[i].y = y_orig + (int)(x * sin(angle_rad) + y * cos(angle_rad));
    }
}

int main() {
    // Image dimensions
    int width = 800;
    int height = 600;

    // Create a true-color image
    gdImagePtr img = gdImageCreateTrueColor(width, height);
    gdImageAlphaBlending(img, 0);

    // Open the output file
    FILE *outputFile = fopen("hellogd1.png", "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening the output file.\n");
        return 1;
    }

    // Define color indices
    int red = gdImageColorAllocate(img, 255, 0, 0);
    int blue = gdImageColorAllocate(img, 0, 0, 255);
    int black = gdImageColorAllocate(img, 0, 0, 0);
    int white = gdImageColorAllocate(img, 255, 255, 255);

    // Draw filled rectangles, ellipse, line, and polygons
    gdImageFilledRectangle(img, 0, 0, width, height, white);
    gdImageFilledRectangle(img, 0, 0, (int)width / 4, (int)height / 4, blue);

    gdImageFilledEllipse(img, (int)width * 3 / 4, (int)height / 4, (int)width / 4, (int)width / 4, red);
    gdImageEllipse(img, (int)width * 3 / 4, (int)height * 3 / 4, (int)width / 4, (int)width / 4, red);
    gdImageLine(img, (int)width / 2, (int)height / 2, (int)width / 2, (int)height / 2 + 100, blue);

    gdPoint points[4] = {
        { (int)width / 4, (int)height * 3 / 4 },
        { (int)width / 4 + 100, (int)height * 3 / 4 },
        { (int)width / 4 + 100, (int)height * 3 / 4 + 100 },
        { (int)width / 4, (int)height * 3 / 4 + 100 }
    };

    // Call the rotation function for the first polygon
    rotateFilledPolygon((int)width / 4 + 50, (int)height * 3 / 4 + 50, 45.0, points, 4);
    gdImagePolygon(img, points, 4, black);

    gdPoint points2[4] = {
        { (int)width / 3, (int)height / 2 },
        { (int)width / 3 + 100, (int)height / 2 },
        { (int)width / 3 + 100, (int)height / 2 + 100 },
        { (int)width / 3 - 50, (int)height / 2 + 100 }
    };

    // Call the rotation function for the second polygon
    rotateFilledPolygon((int)width / 3 + 50, (int)height / 2 + 50, 30.0, points2, 4);
    gdImageFilledPolygon(img, points2, 4, red);

    // Save the image to the output file
    gdImagePngEx(img, outputFile, 9);
    fclose(outputFile);

    // Free the memory used by the image
    gdImageDestroy(img);

    return 0;
}