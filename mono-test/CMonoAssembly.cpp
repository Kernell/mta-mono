#include "stdafx.h"
#include "CMonoAssembly.h"

CMonoAssembly::CMonoAssembly( MonoDomain* pDomain, const char* szPath )
{
	this->m_szPath	= szPath;
	this->m_pDomain = pDomain;

	this->m_pAssembly = mono_domain_assembly_open( this->m_pDomain, szPath );

	if( !this->m_pAssembly )
	{
		printf( "Failed to create assembly from %s\n", szPath );

		return;
	}

	this->m_pImage = mono_assembly_get_image( this->m_pAssembly );
	
	if( !this->m_pImage )
	{
		printf( "Failed to get image from assembly %s\n", szPath );

		return;
	}
}

CMonoAssembly::~CMonoAssembly()
{
}

const char* CMonoAssembly::GetImageName()
{
	return mono_image_get_name( this->m_pImage );
}

const char* CMonoAssembly::GetImageFileName()
{
	return mono_image_get_filename( this->m_pImage );
}

CMonoClass* CMonoAssembly::GetClass( const char* szNameSpace, const char* szClassName )
{
	return this->GetClass( mono_class_from_name( this->m_pImage, szNameSpace, szClassName ) );
}

CMonoClass* CMonoAssembly::GetClass( MonoClass* pMonoClass )
{
	if( pMonoClass )
	{
		CMonoClass* pClass = this->GetFromList( pMonoClass );

		if( !pClass )
		{
			pClass = new CMonoClass( this, pMonoClass );
		}

		return pClass;
	}

	return NULL;
}

void CMonoAssembly::AddToList( CMonoClass* pClass )
{
	this->m_List.push_back( pClass );
}

CMonoClass* CMonoAssembly::GetFromList( MonoClass* pMonoClass )
{
	std::list< CMonoClass* >::const_iterator iter = this->m_List.begin();

	for( ; iter != this->m_List.end(); iter++ )
	{
		if( ( *iter )->GetMonoClass() == pMonoClass )
		{
			return *iter;
		}
	}

	return NULL;
}

void CMonoAssembly::RemoveFromList( CMonoClass* pClass )
{
	if( !this->m_List.empty() )
	{
		this->m_List.remove( pClass );
	}
}