class CMonoAssembly;

#ifndef _CMONOASSEMBLY
#define _CMONOASSEMBLY

#include "CMonoClass.h"

class CMonoAssembly
{
private:
	const char*		m_szPath;
	MonoAssembly*	m_pAssembly;
	MonoImage*		m_pImage;
	MonoDomain*		m_pDomain;

	list< CMonoClass* >       m_List;

public:
	CMonoAssembly( MonoDomain* pDomain, const char* szPath );
	~CMonoAssembly();

	bool		IsValid()		{ return this->m_pImage != NULL; }

	const char* GetImageName();
	const char* GetImageFileName();

	CMonoClass* GetClass( const char* szNameSpace, const char* szClassName );
	CMonoClass* GetClass( MonoClass* pMonoClass );

	void		AddToList		( CMonoClass* pClass );
	CMonoClass* GetFromList		( MonoClass* pMonoClass );
	void		RemoveFromList	( CMonoClass* pClass );

	MonoDomain* GetMonoDomain()	{ return this->m_pDomain; }
};

#endif