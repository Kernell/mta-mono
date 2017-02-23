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
#include "CFunctions.h"
#include "extra/CLuaArguments.h"

int CFunctions::monoInit( lua_State *pLuaVM )
{
	if( pLuaVM )
	{
		CResource *pResource = g_pModule->GetResourceManager()->GetFromList( pLuaVM );

		if( pResource == nullptr )
		{
			CLuaArgument pLuaArgument( pLuaVM, -1 );

			string strName = pLuaArgument.GetString();

			if( !strName.empty() )
			{
				pResource = g_pModule->GetResourceManager()->Create( pLuaVM, strName );
			}
		}

		if( pResource != nullptr )
		{
			pResource->Init();

			return 1;
		}
	}

	return 0;
}

int CFunctions::monoEventHandler( lua_State *pLuaVM )
{
	if( pLuaVM )
	{
		CResource *pResource = g_pModule->GetResourceManager()->GetFromList( pLuaVM );

		if( pResource )
		{
			string	strEventName;
			void*	pThis = nullptr;

			CLuaArguments pLuaArgs;

			pLuaArgs.ReadArguments( pLuaVM );
			
			if( pLuaArgs.Count() == 0 )
			{
				return 0;
			}

			uint i = 0;

			list< CLuaArgument* > argv;

			vector < CLuaArgument* > _args = pLuaArgs.GetArguments();

			for( const auto& iter : _args )
			{
				eLuaType iLuaType = iter->GetType();

				switch( i )
				{
					case 0:
					{
						strEventName = iter->GetString();

						break;
					}
					case 2:
					{
						pThis = iter->GetLightUserData();

						break;
					}
					case 3:
					{
						if( iLuaType == eLuaType::Nil )
						{
							break;
						}

						// dot not break
					}
					default:
					{
						argv.push_back( iter );

						break;
					}
				}

				i++;
			}
			
			if( pResource->CallEvent( strEventName, pThis, argv ) )
			{
				return 1;
			}
		}
	}

	return 0;
}

int CFunctions::monoCommandHandler( lua_State* pLuaVM )
{
	if( pLuaVM )
	{
		CResource *pResource = g_pModule->GetResourceManager()->GetFromList( pLuaVM );

		if( pResource )
		{
			CLuaArguments pLuaArgs;

			pLuaArgs.ReadArguments( pLuaVM );
			
			if( pLuaArgs.Count() == 0 )
			{
				return 0;
			}

			void* pPlayerSource = nullptr;
			string strCommandName;

			uint i = 0;

			list< string > argv;

			for( const auto& iter : pLuaArgs.GetArguments() )
			{
				switch( i )
				{
					case 0:
					{
						pPlayerSource = iter->GetLightUserData();

						break;
					}
					case 1:
					{
						strCommandName = iter->GetString();

						break;
					}
					default:
					{
						if( iter->GetType() == eLuaType::String )
						{
							argv.push_back( iter->GetString() );
						}

						break;
					}
				}

				i++;
			}
			
			if( pResource->ExecuteCommand( pPlayerSource, strCommandName, argv ) )
			{
				return 1;
			}
		}
	}

	return 0;
}
