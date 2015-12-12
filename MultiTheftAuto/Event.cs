using MultiTheftAuto.EventArgs;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto
{
	public class Event
	{
		public string Name;
		public Element AttachedTo;
		public bool Propagated;
		public string Priority;

		public Event( string name )
			: this( name, null )
		{
		}

		public Event( string name, Element attachedTo, bool propagated = true, string priority = "normal" )
		{
			this.Name			= name;
			this.AttachedTo		= attachedTo;
			this.Propagated		= propagated;
			this.Priority		= priority;
		}

		public bool Add()
		{
			return Event.AddHandler( this.Name, this.AttachedTo, this._OnTrigger, this.Propagated, this.Priority );
		}
		
		public bool Remove()
		{
			return Event.RemoveHandler( this.Name, this.AttachedTo, this._OnTrigger );
		}

		public bool Call( params object[] arguments )
		{
			return Native.Event.Trigger( this.Name, this.AttachedTo.GetUserData(), arguments );
		}

		public bool CallClient( Element baseElement = null, params object[] arguments )
		{
			return Native.Event.TriggerClient( baseElement != null ? baseElement.GetUserData() : Element.Root.GetUserData(), this.Name, this.AttachedTo.GetUserData(), arguments );
		}

		public delegate void CustomEventHandler( Element sender, ElementEventArgs e, params object[] args );

		private CustomEventHandler _OnTrigger;

		public event CustomEventHandler OnTrigger
		{
			add
			{
				lock( this )
				{
					bool isNull = this._OnTrigger == null;

					this._OnTrigger += value;

					if( isNull )
					{
						this.Add();
					}
				}
			}
			remove
			{
				lock( this )
				{
					this._OnTrigger -= value;

					if( this._OnTrigger == null )
					{
						this.Remove();
					}
				}
			}
		}

		#region Static methods

		public static bool Add( string name, bool allowRemoteTrigger )
		{
			return Native.Event.Add( name, allowRemoteTrigger );
		}

		public static bool AddHandler( string eventName, Element attachedTo, Delegate handlerFunction, bool getPropagated = true, string priority = "normal" )
		{
			return Native.Event.AddHandler( eventName, attachedTo.GetUserData(), handlerFunction, getPropagated, priority );
		}

		public static bool RemoveHandler( string eventName, Element attachedTo, Delegate handlerFunction )
		{
			return Native.Event.RemoveHandler( eventName, attachedTo.GetUserData(), handlerFunction );
		}

		public static bool Trigger( string eventName, Element baseElement, params object[] arguments )
		{
			return Native.Event.Trigger( eventName, baseElement.GetUserData(), arguments );
		}

		public static bool TriggerClient( Element sendTo, string name, Element sourceElement, params object[] arguments )
		{
			return Native.Event.TriggerClient( sendTo.GetUserData(), name, sourceElement.GetUserData(), arguments );
		}

		public static bool Cancel( bool cancel = true, string reason = "" )
		{
			return Native.Event.Cancel( cancel, reason );
		}
		
		#endregion
	}
}
