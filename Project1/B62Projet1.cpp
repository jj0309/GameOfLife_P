/* #include <windows_console.h>
#include <iostream>

using namespace windows_console;
using namespace std;

int main() {

	csl << window::title("GAME OF LIFE")
		<< window::fit(300, 150, "Consolas", 3, 1.0)
		<< window::unresizable
		<< window::unclosable
		<< window::center
		<< cursor::invisible;

	image im;
	csl >> im;

	im << brush(dot, text_color(white), background_color(dark, black))
		<< fill;
	im << pen(dot, text_color(bright, blue), background_color(bright, blue))
		<< point(50, 25)
		<< line(0, 0, 100, 100)
		<< circle(100, 100, 25);
	//im << no_brush
		//<< rectangle(112, 21, 112, 21);

	csl << im;

	buffer::size_type width{}, height{};
	csl >> buffer(width, height);
	size_t posX{ width / 2 }, posY{ height / 2 };

	image baseImage;
	csl >> baseImage;

	baseImage	<< brush(dot, text_color(dark, blue), background_color(dark, blue))
				<< fill;
	baseImage	<< pen(dot, text_color(bright, blue), background_color(bright, blue));

	im << pen(dot, text_color(dark, black), background_color(bright, blue));


	csl << key_events::add_filter<key_filter_up>;
	csl << console_events::enable_mouse_tracking;

	bool quit{};
	while (!quit) {
		im = baseImage;
		console_events consoleEvents;
		consoleEvents.read_events();
		while (consoleEvents.key_events_count() > 0) {
			switch (consoleEvents.next_key_event().ascii_value()) {
				case 'w':
				case 'W':	--posY;		break;
				case 'a':
				case 'A':	--posX;		break;
				case 's':
				case 'S':	++posY;		break;
				case 'd':
				case 'D':	++posX;		break;
				case 27: quit = true;	break;

			}

			im << rectangle(posX - 3, posY - 3, posX + 3, posY + 3);
			csl << im;

		}
		while (consoleEvents.mouse_events_count() > 0) {
			mouse_event e{ consoleEvents.next_mouse_event() };
			im << circle(e.x(), e.y(), 10);
		}
	}
	
<<<<<<< HEAD
	im << rectangle(posX - 3, posY - 3, posX + 3, posY + 3);
	csl << im;
=======
	
>>>>>>> 31344898b4c995dcd8b34840af0e9d1e1d38043a


	
	

	return 0;
}*/