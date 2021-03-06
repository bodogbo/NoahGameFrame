// -------------------------------------------------------------------------
//    @FileName         ��    NFISLGModule.h
//    @Author           ��    eliteYang
//    @Date             ��    2014-09-11
//    @Module           ��    NFISLGModule
//
// -------------------------------------------------------------------------

#ifndef _NFC_SLG_SERVER_MODULE_H_
#define _NFC_SLG_SERVER_MODULE_H_

#include "NFComm/NFCore/NFMap.h"
#include "NFComm/NFPluginModule/NFIKernelModule.h"
#include "NFComm/NFPluginModule/NFISLGModule.h"
#include "NFComm/NFPluginModule/NFIEventProcessModule.h"
#include "NFComm/NFPluginModule/NFILogicClassModule.h"

class NFCSLGModule : public NFISLGModule
{
public:
    NFCSLGModule( NFIPluginManager* p )
    {
        pPluginManager = p;
    }
    virtual ~NFCSLGModule() {};

    virtual bool Init();
    virtual bool Shut();
    virtual bool Execute( const float fLasFrametime, const float fStartedTime );

    virtual bool AfterInit();
    virtual bool BeforeShut();


protected:


protected:
    NFIEventProcessModule* m_pEventProcessModule;
    NFIKernelModule* m_pKernelModule;
private:
};

#endif // !_NFC_SLG_SERVER_MODULE_H_
