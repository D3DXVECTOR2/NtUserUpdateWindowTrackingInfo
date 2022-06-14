#include <Windows.h>
#include <string>
#include <array>
#include <cstddef>
#include <cstdint>
#include <vector>
#include "Driver.h"


void main( )
{
	// call this as soon as ur app starts
	kernel->initialize( );

	int PID = 4940;

	if ( !kernel->init( PID ) )
	{
		MessageBoxA( 0, "Driver did not attach!", 0, 0 );
	}

	kernel->read_virtual_memory<uintptr_t>( 0 ); // bsod most likely
	
}