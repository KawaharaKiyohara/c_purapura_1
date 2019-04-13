#include "tkEngine/tkEnginePreCompile.h"
#include "tkEngine/online/tkLobbyManager.h"

namespace {
	//�A�v���P�[�V����ID�E�E�E�ǂ������؂��B
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
				//�F�ؗp�̃f�[�^��ݒ�B
				ExitGames::LoadBalancing::AuthenticationValues authValue;
				authValue.setUserID(ExitGames::Common::JString() + GETTIMEMS());
				//���[�U�[����ݒ�B
				auto userName = PLAYER_NAME + GETTIMEMS();
				//���[�h�o�����T�[�ɐڑ��B
				auto result = m_loadBalancingClient.connect(authValue, userName);
				if (result == true) {
					//�ڑ����E�E�E�B
					m_state = enState_Connecting;
				}
				else {
					//���s�B
				}
				
			}break;
			case enState_Connected: {
				//���[���ɓ��� or ���[�������B
				auto result = m_loadBalancingClient.opJoinOrCreateRoom(gameName);
				if (result == true) {
					//���[���ɓ������ɂ���B
					m_state = enState_Joinning;
				}
				else {
					//���s�B
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