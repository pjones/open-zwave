#ifndef _BarrierOperator_H
#define _BarrierOperator_H

#include "command_classes/CommandClass.h"

namespace OpenZWave
{
	class ValueByte;
	class ValueBool;

	/** \brief Implements COMMAND_CLASS_BARRIER_OPERATOR (0x66), a Z-Wave device command class.
	 */
	class BarrierOperator: public CommandClass
	{
	public:
		static CommandClass* Create( uint32 const _homeId, uint8 const _nodeId ){ return new BarrierOperator( _homeId, _nodeId ); }
		virtual ~BarrierOperator(){}

		static uint8 const StaticGetCommandClassId(){ return 0x66; }
		static string const StaticGetCommandClassName(){ return "COMMAND_CLASS_BARRIER_OPERATOR"; }

		// From CommandClass
		virtual bool RequestState( uint32 const _requestFlags, uint8 const _instance, Driver::MsgQueue const _queue );
		virtual bool RequestValue( uint32 const _requestFlags, uint8 const _index, uint8 const _instance, Driver::MsgQueue const _queue );
		virtual uint8 const GetCommandClassId()const{ return StaticGetCommandClassId(); }
		virtual string const GetCommandClassName()const{ return StaticGetCommandClassName(); }
		virtual bool HandleMsg( uint8 const* _data, uint32 const _length, uint32 const _instance = 1 );
		virtual bool SetValue(Value const& _value);

		virtual uint8 GetMaxVersion(){ return 3; }

	protected:
		virtual void CreateVars( uint8 const _instance );

	private:
		BarrierOperator( uint32 const _homeId, uint8 const _nodeId );
	};

} // namespace OpenZWave

#endif
