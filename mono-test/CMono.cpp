#include "stdafx.h"
#include "CMono.h"

CMono::CMono( ) : m_pMonoDomain( NULL )
{
}


CMono::~CMono()
{
	if( this->m_pMonoDomain )
	{
		mono_jit_cleanup( this->m_pMonoDomain );
	}
}

bool CMono::Init( const char* szVersion )
{
//	#ifdef _WIN32
	mono_set_dirs( "./lib", "./etc" );
//	#endif

//	mono_config_parse( NULL );

	mono_debug_init( MONO_DEBUG_FORMAT_MONO );

	this->m_pMonoDomain			= mono_jit_init_version( "Mono Root", szVersion );

	this->AddInternals();

	return true;
}

void CMono::AddInternals()
{
	mono_add_internal_call( "MonoTest.Vector3::Test", CMono::Test );
}

bool CMono::Load( const char * szFilePath )
{
	struct stat buf;

	if( stat( szFilePath, &buf ) == -1 )
	{
		printf( "%s - file not found\n", szFilePath );

		return false;
	}

	CMonoAssembly pAssembly( this->m_pMonoDomain, szFilePath );

	if( !pAssembly.IsValid() )
	{
		return false;
	}

	CMonoClass* pClass = pAssembly.GetClass( pAssembly.GetImageName(), "Resource" );

	if( !pClass )
	{
		printf( "%s::Resource - not found\n", pAssembly.GetImageName() );
		
		return false;
	}

	CMonoObject* pMonoObject = pClass->New();

	if( !pMonoObject )
	{
		printf( "failed to create new object of class '%s::Resource'\n", pAssembly.GetImageName() );

		return false;
	}

	return true;
}

void CMono::Test( MonoObject* vector )
{
	MonoClass* pClass = mono_object_get_class( vector );

	printf( "%s->", mono_class_get_name( pClass ) );

	MonoProperty* pX = mono_class_get_property_from_name( pClass, "X" );

	if( !pX )
	{
		printf( "ERROR\n" );

		return;
	}

	printf( "%s = ", mono_property_get_name( pX ) );

	MonoObject* value = mono_property_get_value( pX, vector, NULL, NULL );

	if( !value )
	{
		printf( "ERROR\n" );

		return;
	}

	float fX = *(float*)mono_object_unbox( value );
	
	printf( "%f\n", fX );
}