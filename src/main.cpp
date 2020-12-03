#include <iostream>
#include <fstream>

#include <sifo/simple_image.h>

int main() {
	simple_image simp;

	std::cout << "Creating pixel image" << std::endl;
	// Write simple .simp image
	int w = 2, h = 2;
	pixel p1 = {170, 0, 255};
	pixel p2 = {0, 132, 255};
	pixel p3 = {0, 208, 255};
	pixel p4 = {255, 119, 0};

	std::cout << "Writing to image file" << std::endl;
	std::fstream im("test.simp", std::ios::out | std::ios::binary | std::ios::trunc);

	std::cout << im.fail() << std::endl;

	std::cout << "1. Writing width and height flags" << std::endl;
	im.write(reinterpret_cast<char *>(&w), sizeof(w));
	im.write(reinterpret_cast<char *>(&h), sizeof(h));
	std::cout << "FINISHED" << std::endl;

	std::cout << "2. Writing pixels" << std::endl;
	im.write(reinterpret_cast<char *>(&p1), sizeof(p1));
	im.write(reinterpret_cast<char *>(&p2), sizeof(p2));
	im.write(reinterpret_cast<char *>(&p3), sizeof(p3));
	im.write(reinterpret_cast<char *>(&p4), sizeof(p4));

	std::cout << "Ending filestream." << std::endl;
	im.close();

	std::cout << "3. Open with simple_image object" << std::endl;
	simp.open("test.simp");

	std::cout << "4. Drawing image" << std::endl;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			pixel p = simp.get(j, i);
			std::cout << "\033[38;2;" << p.r << ";" << p.g << ";" << p.b << "ma";
		}
		std::cout << std::endl;
	}

	return 0;
}

