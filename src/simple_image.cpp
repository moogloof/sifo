#include <fstream>

#include <sifo/simple_image.h>

// simple_image constructor
// Set file opened flag to false
simple_image::simple_image() {
	_file_opened = false;
}

// simple_image destructor
// Deallocate pixels array
simple_image::~simple_image() {
	delete [] pixels;
}

// simple_image open function
// Opens simple image file and gets pixels
void simple_image::open(std::string f) {
	// Open input stream to file
	std::fstream im;
	im.open(f, std::ios::in | std::ios::binary);

	// Check that file is opened or if a file is already opened
	if (im.fail()) {
		return;
	}

	// Get width and height flags of image
	im.read(reinterpret_cast<char *>(&width), sizeof(width));
	im.read(reinterpret_cast<char *>(&height), sizeof(height));

	// Allocate pixels
	pixels = new pixel[width * height];

	// Read in all pixel data form file
	for (int i = 0; i < width * height; i++) {
		im.read(reinterpret_cast<char *>(pixels + i), sizeof(pixel));
	}

	// Set flag to file opened
	_file_opened = true;

	// Close input stream to file
	im.close();
}

// simple_image get function
// Returns a pixel at a certain (x, y)
pixel simple_image::get(int x, int y) const {
	return pixels[x + y*width];
}

