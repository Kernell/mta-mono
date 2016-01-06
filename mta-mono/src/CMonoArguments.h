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

class CMonoArguments;

#ifndef __CMONOARGUMENTS_H
#define __CMONOARGUMENTS_H

class CMonoArguments
{
private:
	PVOID*							m_pTmpArgs;
	vector< pair< PVOID, bool > >	m_pArgs;

public:
									CMonoArguments			( void );
									~CMonoArguments			( void );

	template< typename Type >
	bool							Push					( Type Value )
	{
		Type* pValue = new Type;

		*pValue = Value;

		this->m_pArgs.push_back( make_pair( pValue, true ) );

		return true;
	}

	bool							Push					( MonoString* pString );
	bool							Push					( MonoObject* pObject );

	PVOID*							GetArgs					( void );
	const size_t					Length					( void ) const;

	PVOID							operator[]				( int index );
	PVOID*							operator*				( void );
};

#endif
