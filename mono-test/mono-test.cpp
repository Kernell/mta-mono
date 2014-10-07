#include "stdafx.h"

#include "CMono.h"

int main( int argc, char* argv[] )
{
	CMono* pMono = new CMono();

	if( pMono->Init( "v4.0.30319" ) )
	{
		printf( "\tInitializing mono done, MemUsage=1337Kb\n" );

		pMono->Load( "MonoTest.dll" );

		char szLine[ 256 ];

		while( true )
		{
			cin.getline( szLine, sizeof( szLine ) );

			if( strcmp( szLine, "exit" ) == 0 )
			{
				break;
			}
			else
			{
				if( pMono->Load( szLine ) )
				{
					printf( "'%s' successfuly loaded\n", szLine );
				}
				else
				{
					printf( "loading '%s' failed\n", szLine );
				}
			}
		}
	}
	else
	{
		printf( "Mono initialization failed\n" );
	}

	delete pMono;
	
	return 0;
}

