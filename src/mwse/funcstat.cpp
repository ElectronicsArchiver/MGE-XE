
#include "mge/mwbridge.h"
#include "funcstat.h"


MWSEINSTRUCTION_DECLARE_VTABLE(mwseGetBaseHealth)

// GetBaseHealth -> returns <float>
bool mwseGetBaseHealth::execute(mwseInstruction *_this)
{
    VMFLOAT ret = 0;
    const BYTE *actor = reinterpret_cast<const BYTE*>(vmGetTargetActor());

    if(actor)
        ret = *reinterpret_cast<const float *>(actor + 0x2b8);

    return _this->vmPush(ret);
}


MWSEINSTRUCTION_DECLARE_VTABLE(mwseGetBaseMagicka)

// GetBaseMagicka -> returns <float>
bool mwseGetBaseMagicka::execute(mwseInstruction *_this)
{
    VMFLOAT ret = 0;
    const BYTE *actor = reinterpret_cast<const BYTE*>(vmGetTargetActor());

    if(actor)
        ret = *reinterpret_cast<const float *>(actor + 0x2c4);

    return _this->vmPush(ret);
}


MWSEINSTRUCTION_DECLARE_VTABLE(mwseGetBaseFatigue)

// GetBaseFatigue -> returns <float>
bool mwseGetBaseFatigue::execute(mwseInstruction *_this)
{
    VMFLOAT ret = 0;
   const BYTE *actor = reinterpret_cast<const BYTE*>(vmGetTargetActor());

    if(actor)
        ret = *reinterpret_cast<const float *>(actor + 0x2dc);

    return _this->vmPush(ret);
}
