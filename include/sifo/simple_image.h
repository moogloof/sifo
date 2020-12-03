#ifndef SIMPLE_IMAGE
#define SIMPLE_IMAGE

struct pixel {
	int r, g, b;
};

class simple_image {
	private:
		bool _file_opened;
		pixel *pixels;
		int width, height;
	public:
		simple_image();
		~simple_image();
		void open(std::string);
		pixel get(int, int) const;
};

#endif
