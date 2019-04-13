#pragma once

#include "LoadBalancing-cpp/inc/Client.h"


namespace tkEngine {
	namespace online {
		/// <summary>
		/// ロビーマネージャー。
		/// </summary>
		class CLobbyManager :
			private ExitGames::LoadBalancing::Listener, Noncopyable {
		public:
			/// <summary>
			/// コンストラクタ。
			/// </summary>
			/// <remarks>
			/// アプリケーションIDはPhoton Cloudのダッシュボードでアプリを登録すると作成されるIDを指定してください。
			/// 
			/// </remarks>
			/// <param name="appID">アプリケーションID</param>
			/// <param name="gameName">ゲームの名前</param>
			/// <param name="appVersion">アプリケーションバージョン</param>
			CLobbyManager(
				ExitGames::Common::JString appID,
				ExitGames::Common::JString gameName = L"Basic",
				ExitGames::Common::JString appVersion = L"1.0f"
			);
			/// <summary>
			/// デストラクタ。
			/// </summary>
			~CLobbyManager();
			/// <summary>
			/// 更新。
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
				//接続済み。
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
				enState_Inited,			//初期化。
				enState_Connecting,		//ロードバランサーに接続中。
				enState_Connected,		//ロードバランサーに接続済み。
				enState_Joinning,		//ルームに入室中。
				enState_Joined,			//ルームに入室済み。
				enState_Left,			//ルームから抜けた時。
			};
			EnState	m_state = enState_Inited;	//初期化。
			ExitGames::LoadBalancing::Client m_loadBalancingClient;	
		};
	}
}