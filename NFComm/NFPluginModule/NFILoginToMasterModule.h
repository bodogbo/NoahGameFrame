// -------------------------------------------------------------------------
//    @FileName         ��    NFILoginNet_ClientModule.h
//    @Author           ��    LvSheng.Huang
//    @Date             ��    2012-12-15
//    @Module           ��    NFILoginNet_ClientModule
//
// -------------------------------------------------------------------------

#ifndef _NFI_LOGINNET_CLIENTMODULE_H_
#define _NFI_LOGINNET_CLIENTMODULE_H_

#include <iostream>
#include "NFILogicModule.h"
#include "NFComm/NFMessageDefine/NFMsgPreGame.pb.h"

class NFILoginToMasterModule
    : public NFINetModule
{

public:

    virtual NFMapEx<int, NFMsg::ServerInfoReport>* GetWorldMap() = 0;
};

#endif
