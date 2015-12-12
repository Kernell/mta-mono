using System;
using System.Runtime.CompilerServices;

namespace MultiTheftAuto.Native
{
    public static class Game
    {
        [MethodImpl( MethodImplOptions.InternalCall )]
        public static new extern string     GetType();

        [MethodImpl( MethodImplOptions.InternalCall )]
        public static extern string     GetMapName();

        [MethodImpl( MethodImplOptions.InternalCall )]
        public static extern string     GetRuleValue( string sKey );

        [MethodImpl( MethodImplOptions.InternalCall )]
        public static extern bool       RemoveRuleValue( string sKey );

        [MethodImpl( MethodImplOptions.InternalCall )]
        public static extern bool       SetType( string sType );

        [MethodImpl( MethodImplOptions.InternalCall )]
        public static extern bool       SetMapName( string sName );

        [MethodImpl( MethodImplOptions.InternalCall )]
        public static extern bool       SetRuleValue( string sKey, string sValue );
    }
}
