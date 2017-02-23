/*********************************************************
*
*  Copyright © 2013, Innovation Roleplay Engine.
*
*  All Rights Reserved.
*
*  Redistribution and use in source and binary forms,
*  with or without modification,
*  is permitted only for authors.
*
*********************************************************/

#include "StdInc.h"
#include "CRegisteredCommands.h"

CRegisteredCommands::CRegisteredCommands( CResource* pResource )
{
	this->m_pResource = pResource;
}

CRegisteredCommands::~CRegisteredCommands( void )
{
	this->ClearCommands();

	this->m_pResource = nullptr;
}

bool CRegisteredCommands::Add( string strCommandName, MonoObject* pDelegate, bool bRestricted, bool bCaseSensitive )
{
	SCommand* pCommand = this->GetCommand( strCommandName );

	if( pCommand && pCommand->pDelegate == pDelegate )
	{
		return false;
	}

	pCommand = new SCommand;

	pCommand->strName			= strCommandName;
	pCommand->pDelegate			= pDelegate;
	pCommand->bRestricted		= bRestricted;
	pCommand->bCaseSensitive	= bCaseSensitive;

	this->m_Commands.push_back( pCommand );

	return true;
}

bool CRegisteredCommands::Execute( CElement* pPlayer, string strCommandName, list< string > argv )
{
	bool bHandled = false;

	int iCompareResult;

	for( const auto& pCommand : this->m_Commands )
	{
		if( pCommand->bCaseSensitive )
		{
			iCompareResult = strcmp( pCommand->strName.c_str(), strCommandName.c_str() );
		}
		else
		{
			iCompareResult = stricmp( pCommand->strName.c_str(), strCommandName.c_str() );
		}

		if( iCompareResult == 0 )
		{
			this->Invoke( pPlayer, pCommand->pDelegate, strCommandName, argv );

			bHandled = true;
		}
	}

	return bHandled;
}

bool CRegisteredCommands::Remove( string strCommandName, MonoObject* pDelegate )
{
	bool bFound = false;

	iterator iter = this->m_Commands.begin();

	int iCompareResult;

	while( iter != this->m_Commands.end() )
	{
		if( ( *iter )->bCaseSensitive )
		{
			iCompareResult = strcmp( ( *iter )->strName.c_str(), strCommandName.c_str() );
		}
		else
		{
			iCompareResult = stricmp( ( *iter )->strName.c_str(), strCommandName.c_str() );
		}

		if( iCompareResult == 0 )
		{
			if( ( *iter )->pDelegate != pDelegate )
			{
				iter++;

				continue;
			}

			delete *iter;

			iter = this->m_Commands.erase( iter );

			bFound = true;
		}
		else
		{
			iter++;
		}
	}

	return bFound;
}

void CRegisteredCommands::ClearCommands( void )
{
	const_iterator iter = this->m_Commands.begin();

	for( ; iter != this->m_Commands.end(); iter++ )
	{
		delete *iter;
	}

	this->m_Commands.clear();
}

CRegisteredCommands::SCommand* CRegisteredCommands::GetCommand( string strName )
{
	for( CRegisteredCommands::SCommand* pCommand : this->m_Commands )
	{
		pCommand->strName.compare( strName );

		if( pCommand->bCaseSensitive )
		{
			if( pCommand->strName == strName )
			{
				return pCommand;
			}
		}
		else if( stricmp( pCommand->strName.c_str(), strName.c_str() ) )
		{
			return pCommand;
		}
	}

	return nullptr;
}

void CRegisteredCommands::Invoke( CElement* pPlayer, MonoObject* pDelegate, const string& strCommandName, list< string > argv )
{
	CMonoMTALib* pMTALib = this->m_pResource->GetDomain()->GetMTALib();
	CMonoCorlib* pCorlib = this->m_pResource->GetDomain()->GetCorlib();

	assert( pMTALib );
	assert( pCorlib );

	MonoString* pCommandName	= this->m_pResource->GetDomain()->NewString( strCommandName );
	MonoArray* pArguments		= mono_array_new( **this->m_pResource->GetDomain(), **pCorlib->Class[ "string" ], argv.size() );

	uint index = 0;

	for( const string& arg : argv )
	{
		mono_array_set( pArguments, MonoString*, index++, this->m_pResource->GetDomain()->NewString( arg ) );
	}

	PVOID* params = new PVOID[ 3 ];

	params[ 0 ] = pPlayer->GetMonoObject();
	params[ 1 ] = pCommandName;
	params[ 2 ] = pArguments;

	this->m_pResource->GetDomain()->Set( false );

	MonoObject* pException = nullptr;

	mono_runtime_delegate_invoke( pDelegate, params, &pException );

	delete [] params;

	this->m_pResource->GetDomain()->HandleException( pException );
}
