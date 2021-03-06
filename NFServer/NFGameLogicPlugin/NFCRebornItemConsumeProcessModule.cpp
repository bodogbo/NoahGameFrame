// -------------------------------------------------------------------------
//    @FileName      :   NFCPotionConsumeProcessModule.cpp
//    @Author           :   LvSheng.Huang
//    @Date             :   2013-09-28
//    @Module           :   NFCPotionConsumeProcessModule
//    @Desc             :   道具消费机制类,详细的具体某类道具消费流程以及扣除机制
// -------------------------------------------------------------------------

#include "NFCRebornItemConsumeProcessModule.h"

bool NFCRebornItemConsumeProcessModule::Init()
{
    return true;
}

bool NFCRebornItemConsumeProcessModule::AfterInit()
{
    m_pKernelModule = dynamic_cast<NFIKernelModule*>( pPluginManager->FindModule( "NFCKernelModule" ) );
    m_pItemConsumeManagerModule = dynamic_cast<NFIItemConsumeManagerModule*>( pPluginManager->FindModule( "NFCItemConsumeManagerModule" ) );
    m_pPackModule = dynamic_cast<NFIPackModule*>( pPluginManager->FindModule( "NFCPackModule" ) );
    m_pElementInfoModule = dynamic_cast<NFIElementInfoModule*>( pPluginManager->FindModule( "NFCElementInfoModule" ) );
    m_pLevelModule = dynamic_cast<NFILevelModule*>( pPluginManager->FindModule( "NFCLevelModule" ) );
    m_pLogModule = dynamic_cast<NFILogModule*>( pPluginManager->FindModule( "NFCLogModule" ) );

    assert( NULL != m_pKernelModule );
    assert( NULL != m_pItemConsumeManagerModule );
    assert( NULL != m_pPackModule );
    assert( NULL != m_pElementInfoModule );
    assert( NULL != m_pLevelModule );
    assert( NULL != m_pLogModule );

    //包括了复活药水(满血蓝)
    m_pItemConsumeManagerModule->ResgisterConsumeModule( EGameItemSubType::EGIT_ITEM_REBORN, this );

    return true;
}

bool NFCRebornItemConsumeProcessModule::Shut()
{
    return true;
}

bool NFCRebornItemConsumeProcessModule::Execute( const float fLasFrametime, const float fStartedTime )
{
    return true;
}


int NFCRebornItemConsumeProcessModule::ConsumeLegal( const NFIDENTID& self, int nItemRowID, const NFIDataList& other )
{
    return 1;
}

int NFCRebornItemConsumeProcessModule::ConsumeSelf( const NFIDENTID& self, int nItemRowID )
{
    //得到数量-1
    int nCount = m_pPackModule->GetGridCount( self, nItemRowID );
    nCount--;

    if ( nCount >= 0 )
    {
        //消费成功
        if ( 0 == nCount )
        {
            m_pPackModule->DeleteGrid( self, nItemRowID );

        }
        else
        {
            m_pPackModule->SetGridCount( self, nItemRowID, nCount );
        }

        return 1;
    }

    //失败

    return 0;
}

int NFCRebornItemConsumeProcessModule::ConsumeProcess( const NFIDENTID& self, const std::string& strItemName, const NFIDataList& other )
{
    //附加效果

//     NFIPropertyManager* pPropertyManager = m_pElementInfoModule->GetPropertyManager( strItemName );
//     if ( pPropertyManager )
//     {
//         NFIProperty* pItemEffectProperty = pPropertyManager->GetElement( "EffectProperty" );
//         NFIProperty* pItemEffectValue = pPropertyManager->GetElement( "EffectValue" );
//         if ( pItemEffectProperty && pItemEffectValue )
//         {
//             NFCDataList valueEffectProperty( pItemEffectProperty->QueryString().c_str(), "," );
//             NFCDataList valueEffectValue( pItemEffectValue->QueryString().c_str(), "," );
//             if ( valueEffectProperty.GetCount() == valueEffectValue.GetCount() )
//             {
//                 for ( int i = 0; i < valueEffectProperty.GetCount(); i++ )
//                 {
//                     //先测定目标是否有此属性(其实是担心配错了)
//                     for ( int j = 0; j < other.GetCount(); j++ )
//                     {
//                         NFIDENTID identOther = other.ObjectVal( j );
//                         if ( !identOther.IsNull() )
//                         {
//                             NFIObject* pObject = m_pKernelModule->GetObject( identOther );
//                             if ( pObject )
//                             {
//                                 std::string strCurProperty = valueEffectProperty.StringVal( i );
//                                 std::string strMaxProperty = "MAX" + strCurProperty;
//                                 NFIProperty* pOtherCurProperty = pObject->GetPropertyManager()->GetElement( strCurProperty );
//                                 NFIProperty* pOtherMaxProperty = pObject->GetPropertyManager()->GetElement( strMaxProperty );
//                                 if ( pOtherCurProperty && pOtherMaxProperty )
//                                 {
//                                     //药物，只能是绝对值，百分比不要了，百分比让BUFF去做
//                                     //而且，只有最大值的那种，才能使用，因此，这里只能有 HP MP CSP 3样属性
//                                     //重要的是，不能超过最大值，这几个属性那个都是整型数据
//                                     //类似最大HP之类的，不能通过药剂直接修改属性，而是通过BUFF来修改，只要是分层属性都通过BUFF修改
//                                     int nAddValue = boost::lexical_cast<int>( valueEffectValue.StringVal( i ) );
//                                     int nCurValue = pOtherCurProperty->QueryInt();
//                                     int nMaxValue = pOtherMaxProperty->QueryInt();
// 
//                                     if ( nCurValue <= 0 )
//                                     {
//                                         nCurValue += nAddValue;
//                                         if ( nCurValue > nMaxValue )
//                                         {
//                                             nCurValue = nMaxValue;
//                                         }
//                                         pOtherCurProperty->SetInt( nCurValue );
//                                     }
// 
//                                 }
//                                 else
//                                 {
//                                     m_pLogModule->LogProperty(NFILogModule::NLL_ERROR_NORMAL, self, strCurProperty, "", __FUNCTION__, __LINE__);
//                                     return 0;
//                                 }
//                             }
//                         }
//                     }
//                 }
// 
//                 return other.GetCount();
//             }
//         }
//     }
// 
//     m_pLogModule->LogItem(NFILogModule::NLL_ERROR_NORMAL, self, strItemName, "There is no element", __FUNCTION__, __LINE__);

    return 0;
}
