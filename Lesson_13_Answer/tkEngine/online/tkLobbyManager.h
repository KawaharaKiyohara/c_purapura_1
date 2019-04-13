#pragma once

#include "LoadBalancing-cpp/inc/Client.h"


namespace tkEngine {
	namespace online {
		/// <summary>
		/// ���r�[�}�l�[�W���[�B
		/// </summary>
		class CLobbyManager :
			private ExitGames::LoadBalancing::Listener, Noncopyable {
		public:
			/// <summary>
			/// �R���X�g���N�^�B
			/// </summary>
			/// <remarks>
			/// �A�v���P�[�V����ID��Photon Cloud�̃_�b�V���{�[�h�ŃA�v����o�^����ƍ쐬�����ID���w�肵�Ă��������B
			/// 
			/// </remarks>
			/// <param name="appID">�A�v���P�[�V����ID</param>
			/// <param name="gameName">�Q�[���̖��O</param>
			/// <param name="appVersion">�A�v���P�[�V�����o�[�W����</param>
			CLobbyManager(
				ExitGames::Common::JString appID,
				ExitGames::Common::JString gameName = L"Basic",
				ExitGames::Common::JString appVersion = L"1.0f"
			);
			/// <summary>
			/// �f�X�g���N�^�B
			/// </summary>
			~CLobbyManager();
			/// <summary>
			/// �X�V�B
			/// </summary>
			void Update();
		private:
		private:
			// receive and print out debug out here
			void debugReturn(int debugLevel, const ExitGames::Common::JString& string) override
			{
			}

			// implement your error-handling here
			void connectionErrorReturn(int errorCode) override
			{
			}
			void clientErrorReturn(int errorCode) override
			{
			}
			void warningReturn(int warningCode) override
			{
			}
			void serverErrorReturn(int errorCode) override
			{
			}

			// events, triggered by certain operations of all players in the same room
			void joinRoomEventAction(int playerNr, const ExitGames::Common::JVector<int>& playernrs, const ExitGames::LoadBalancing::Player& player) override
			{
			}
			void leaveRoomEventAction(int playerNr, bool isInactive) override
			{
			}
			void customEventAction(int playerNr, nByte eventCode, const ExitGames::Common::Object& eventContent) override
			{
			}

			// callbacks for operations on PhotonLoadBalancing server
			void connectReturn(int errorCode, const ExitGames::Common::JString& errorString, const ExitGames::Common::JString& region, const ExitGames::Common::JString& cluster) override
			{
				//�ڑ��ς݁B
				m_state = enState_Connected;
			}
			void disconnectReturn(void) override
			{
			}
			void createRoomReturn(int localPlayerNr, const ExitGames::Common::Hashtable& gameProperties, const ExitGames::Common::Hashtable& playerProperties, int errorCode, const ExitGames::Common::JString& errorString) override
			{
			}
			void joinOrCreateRoomReturn(int localPlayerNr, const ExitGames::Common::Hashtable& gameProperties, const ExitGames::Common::Hashtable& playerProperties, int errorCode, const ExitGames::Common::JString& errorString) override
			{
			}
			void joinRoomReturn(int localPlayerNr, const ExitGames::Common::Hashtable& gameProperties, const ExitGames::Common::Hashtable& playerProperties, int errorCode, const ExitGames::Common::JString& errorString) override
			{
			}
			void joinRandomRoomReturn(int localPlayerNr, const ExitGames::Common::Hashtable& gameProperties, const ExitGames::Common::Hashtable& playerProperties, int errorCode, const ExitGames::Common::JString& errorString) override
			{
			}
			void leaveRoomReturn(int errorCode, const ExitGames::Common::JString& errorString) override
			{
			}
			void joinLobbyReturn(void) override
			{
			}
			void leaveLobbyReturn(void) override
			{
			}
		private:
			enum EnState {
				enState_Inited,			//�������B
				enState_Connecting,		//���[�h�o�����T�[�ɐڑ����B
				enState_Connected,		//���[�h�o�����T�[�ɐڑ��ς݁B
				enState_Joinning,		//���[���ɓ������B
				enState_Joined,			//���[���ɓ����ς݁B
				enState_Left,			//���[�����甲�������B
			};
			EnState	m_state = enState_Inited;	//�������B
			ExitGames::LoadBalancing::Client m_loadBalancingClient;	
		};
	}
}