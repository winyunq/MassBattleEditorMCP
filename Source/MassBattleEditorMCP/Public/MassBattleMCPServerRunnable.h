#pragma once

#include "CoreMinimal.h"
#include "HAL/Runnable.h"
#include "Sockets.h"

class UMassBattleMCPBridge;

class FMassBattleMCPServerRunnable : public FRunnable
{
public:
	FMassBattleMCPServerRunnable(UMassBattleMCPBridge* InBridge, FSocket* InListenerSocket);
	virtual ~FMassBattleMCPServerRunnable() override = default;

	virtual bool Init() override;
	virtual uint32 Run() override;
	virtual void Stop() override;
	virtual void Exit() override;

private:
	void HandleClientConnection(FSocket* InClientSocket);
	void ProcessMessage(FSocket* InClientSocket, const FString& Message);

	UMassBattleMCPBridge* Bridge = nullptr;
	FSocket* ListenerSocket = nullptr;
	FSocket* ClientSocket = nullptr;
	FThreadSafeBool bRunning = true;
};
