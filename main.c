#include <stdio.h>

int main(void) {

	FILE *imageFilePtr; // imageFilePtr =  image.ppm  file pointer

	imageFilePtr = fopen("image.ppm", "wb");

	if (imageFilePtr == NULL) {
		puts("File could not be opened\n");
		return -1;
	}

	int imageWidth  = 255;
	int imageHeight = 255;

	fprintf(imageFilePtr, "P3\n%d %d\n255\n", imageWidth, imageHeight);

	for (int j = 0; j < imageHeight; ++j) {
		for (int i = 0; i < imageWidth; ++i) {
			double x = (double) i / (imageWidth - 1);
			double y = (double) j / (imageHeight - 1);
			double z = 0.25;

			int r = (int) (x * 255.999);
			int g = (int) (y * 255.999);
			int b = (int) (z * 255.999);

			fprintf(imageFilePtr, "%d %d %d\n", r, g, b);
		}
	}

	fclose(imageFilePtr);

	return 0;
}
