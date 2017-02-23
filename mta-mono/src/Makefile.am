AM_CPPFLAGS=-I. -I./include -I../vendor/lua51/src -I/usr/include/mono-2.0

SUBDIRS = extra lua SharedUtil

lib_LTLIBRARIES=libmta_mono.la

libmta_mono_la_SOURCES = \
	CEvent.cpp \
	CEventManager.cpp \
	CFunctions.cpp \
	CMonoArguments \
	CMonoClass.cpp \
	CMonoCorlib.cpp \
	CMonoDomain.cpp \
	CMonoEvent.cpp \
	CMonoFunctions.cpp \
	CMonoFunctions_Account.cpp \
	CMonoFunctions_Audio.cpp \
	CMonoFunctions_Ban.cpp \
	CMonoFunctions_Blip.cpp \
	CMonoFunctions_Element.cpp \
	CMonoFunctions_Event.cpp \
	CMonoFunctions_Explosion.cpp \
	CMonoFunctions_Marker.cpp \
	CMonoFunctions_Object.cpp \
	CMonoFunctions_Ped.cpp \
	CMonoFunctions_Pickup.cpp \
	CMonoFunctions_Player.cpp \
	CMonoFunctions_RadarArea.cpp \
	CMonoFunctions_Resource.cpp \
	CMonoFunctions_Shape.cpp \
	CMonoFunctions_Team.cpp \
	CMonoFunctions_Vehicle.cpp \
	CMonoFunctions_Water.cpp \
	CMonoFunctions_World.cpp \
	CMonoGC.cpp \
	CMonoInterface.cpp \
	CMonoMethod.cpp \
	CMonoMTALib.cpp \
	CMonoObject.cpp \
	CRegisteredCommands.cpp \
	CResource.cpp \
	CResourceManager.cpp \
	mta-mono.cpp \
	StdInc.cpp
	
libmta_mono_la_LIBADD = -L/usr/lib64 -lmono-2.0 -lm -lrt -ldl -lpthread -lstdc++ -llua_f_defs -lmta_mono_extra -llua -L./lua -L./extra -L../lib -L../vendor/lua51/src
