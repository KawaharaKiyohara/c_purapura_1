#include "tkEngine/tkEnginePreCompile.h"
#include "tkEngine/online/tkLobbyManager.h"

namespace {
	//アプリケーションID・・・どうすっぺか。
	const ExitGames::Common::JString appID = L"41b72c35-96cd-4cab-ab81-cc1313e36213";
	const ExitGames::Common::JString appVersion = L"1.0";
	const ExitGames::Common::JString gameName = L"Basic";
	const ExitGames::Common::JString PLAYER_NAME = L"user";
	const int MAX_SENDCOUNT = 100;
}
namespace tkEngine {
	namespace online {
		CLobbyManager::CLobbyManager(
			ExitGames::Common::JString appID,
			ExitGames::Common::JString gameName,
			ExitGames::Common::JString appVersion ):
			m_loadBalancingClient(*this, appID, appVersion, ExitGames::Photon::ConnectionProtocol::UDP, true)
		{
			ExitGames::Common::Base::setListener(this);
		}
		CLobbyManager::~CLobbyManager()
		{
			m_loadBalancingClient.disconnect();
		}
		void CLobbyManager::Update()
		{
			switch (m_state) {
			case enState_Inited: {
				//認証用のデータを設定。
				ExitGames::LoadBalancing::AuthenticationValues authValue;
				authValue.setUserID(ExitGames::Common::JString() + GETTIMEMS());
				//ユーザー名を設定。
				auto userName = PLAYER_NAME + GETTIMEMS();
				//ロードバランサーに接続。
				auto result = m_loadBalancingClient.connect(authValue, userName);
				if (result == true) {
					//接続中・・・。
					m_state = enState_Connecting;
				}
				else {
					//失敗。
				}
				
			}break;
			case enState_Connected: {
				//ルームに入る or ルームを作る。
				auto result = m_loadBalancingClient.opJoinOrCreateRoom(gameName);
				if (result == true) {
					//ルームに入室中にする。
					m_state = enState_Joinning;
				}
				else {
					//失敗。
				}
			}break;
			case enState_Joined:
				break;
			case enState_Left:
				break;
			}
			m_loadBalancingClient.service();
		}
	}
}