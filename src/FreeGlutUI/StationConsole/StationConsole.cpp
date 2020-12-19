// StationConsole.cpp : Defines the entry point for the application.
//

#include <StationConsole.h>
#include <artnet-setdmx.h>
#include <artnet-dmxconsole.h>

int main(int argc, char** argv)
{
	std::cout << "Hello CMake." << std::endl;
	//ArtNetSetDmx::Inst()->Run(argc, argv);
	ArtNetDmxConsole::Inst()->Run(argc, argv);
	return 0;
}