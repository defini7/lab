#include <iostream>
#include <Windows.h>

void ReadSave(std::string sFileName)
{
	FILE* fSource = nullptr;

	fopen_s(&fSource, sFileName.c_str(), "r");

	WORD wUnknown;
	float fUnknown;
	BYTE bUnknown;
	BYTE bAlign[3];

	DWORD dwVersion;
	char sName[100];
	BYTE bMissionPack; // not used by the game
	DWORD dwLocation;
	float fCamera[3];
	DWORD dwMinuteLength;
	DWORD dwWeatherTimer;
	BYTE bMonth;
	BYTE bDay;
	BYTE bHour;
	BYTE bMinute;
	BYTE bWeekDay;
	BYTE bTimeCopy[4];
	BYTE bIsTimeCopied; // boolean
	BYTE bIsCheated; // bool
	DWORD dwGlobalTime;
	float fGameSpeed;
	float fDeltaTime;
	DWORD dwProcessedFrames;
	WORD wWeatherId;
	DWORD dwVehicleCameraView;
	DWORD dwOnfootCameraView;
	DWORD dwInterior;
	DWORD bOriginalInteriorColor;
	BYTE bInteriorColorFlag;
	DWORD dwChangedInteriorColor;
	DWORD dwUnknown;
	BYTE bIsRiot;
	DWORD dwMaxWantedLevel;
	DWORD dwMaxChaos;
	BYTE bIsGermanLang;
	BYTE bCensoreFlag;
	BYTE bTimeLeftToHideCinematicCameraHelp;
	SYSTEMTIME stTime;
	DWORD dwMarkerHandle;
	BYTE bIsVehicleStealingHelpShown;
	BYTE bIsNitroInTaxis;
	BYTE bIsProstitutesPay;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	fread(&dwVersion, sizeof(DWORD), 1, fSource);
	fread(sName, 100, 1, fSource);
	fread(&bMissionPack, sizeof(BYTE), 1, fSource);
	fread(&bAlign, sizeof(BYTE) * 3, 1, fSource);
	fread(&dwLocation, sizeof(DWORD), 1, fSource);
	fread(fCamera, sizeof(float) * 3, 1, fSource);
	fread(&dwMinuteLength, sizeof(DWORD), 1, fSource);
	fread(&dwWeatherTimer, sizeof(DWORD), 1, fSource);
	fread(&bMonth, sizeof(BYTE), 1, fSource);
	fread(&bDay, sizeof(BYTE), 1, fSource);
	fread(&bHour, sizeof(BYTE), 1, fSource);
	fread(&bMinute, sizeof(BYTE), 1, fSource);
	fread(&bWeekDay, sizeof(BYTE), 1, fSource);
	fread(bTimeCopy, sizeof(BYTE) * 4, 1, fSource);
	fread(&bIsTimeCopied, sizeof(BYTE), 1, fSource);
	fread(&wUnknown, sizeof(WORD), 1, fSource);
	fread(&bIsCheated, sizeof(BYTE), 1, fSource);
	fread(&bAlign, sizeof(BYTE) * 3, 1, fSource);
	fread(&dwGlobalTime, sizeof(DWORD), 1, fSource);
	fread(&fGameSpeed, sizeof(float), 1, fSource);
	fread(&fUnknown, sizeof(float), 1, fSource);
	fread(&fDeltaTime, sizeof(float), 1, fSource);
	fread(&dwProcessedFrames, sizeof(DWORD), 1, fSource);
	fread(&wUnknown, sizeof(WORD), 1, fSource);
	fread(&wUnknown, sizeof(WORD), 1, fSource);
	fread(&wUnknown, sizeof(WORD), 1, fSource);
	fread(&wWeatherId, sizeof(WORD), 1, fSource);
	fread(&dwUnknown, sizeof(DWORD), 1, fSource);
	fread(&dwUnknown, sizeof(DWORD), 1, fSource);
	fread(&dwUnknown, sizeof(DWORD), 1, fSource);
	fread(&dwVehicleCameraView, sizeof(DWORD), 1, fSource);
	fread(&dwOnfootCameraView, sizeof(DWORD), 1, fSource);
	fread(&dwInterior, sizeof(DWORD), 1, fSource);
	fread(&bOriginalInteriorColor, sizeof(BYTE), 1, fSource);
	fread(&bInteriorColorFlag, sizeof(BYTE), 1, fSource);
	fread(&fUnknown, sizeof(float), 1, fSource);
	fread(&dwChangedInteriorColor, sizeof(DWORD), 1, fSource);
	fread(&dwUnknown, sizeof(DWORD), 1, fSource);
	fread(&bIsRiot, sizeof(BYTE), 1, fSource);
	fread(&bUnknown, sizeof(BYTE), 1, fSource);
	fread(&dwMaxWantedLevel, sizeof(DWORD), 1, fSource);
	fread(&dwMaxChaos, sizeof(DWORD), 1, fSource);
	fread(&bUnknown, sizeof(BYTE), 1, fSource);
	fread(&bIsGermanLang, sizeof(BYTE), 1, fSource);
	fread(&bCensoreFlag, sizeof(BYTE), 1, fSource);
	fread(&bTimeLeftToHideCinematicCameraHelp, sizeof(BYTE), 1, fSource);
	fread(&stTime.wYear, sizeof(WORD), 1, fSource);
	fread(&stTime.wMonth, sizeof(WORD), 1, fSource);
	fread(&stTime.wDayOfWeek, sizeof(WORD), 1, fSource);
	fread(&stTime.wDay, sizeof(WORD), 1, fSource);
	fread(&stTime.wHour, sizeof(WORD), 1, fSource);
	fread(&stTime.wMinute, sizeof(WORD), 1, fSource);
	fread(&stTime.wSecond, sizeof(WORD), 1, fSource);
	fread(&stTime.wMilliseconds, sizeof(WORD), 1, fSource);
	fread(&dwMarkerHandle, sizeof(DWORD), 1, fSource);
	fread(&bIsVehicleStealingHelpShown, sizeof(BYTE), 1, fSource);
	fread(&bIsNitroInTaxis, sizeof(BYTE), 1, fSource);
	fread(&bIsProstitutesPay, sizeof(BYTE), 1, fSource);
	fread(&bAlign[0], sizeof(BYTE), 1, fSource);

	fclose(fSource);
}

int main()
{
	ReadSave("GTASAsf1.b");

	return 0;
}
