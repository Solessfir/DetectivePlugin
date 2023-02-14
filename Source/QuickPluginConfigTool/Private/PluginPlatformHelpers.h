// Copyright 2020 - Trifolium Digital Limited

#pragma once

/** Platforms Supported
 * Win32
 * Win64
 * Mac
 * Linux
 * PS4
 * XboxOne
 * Switch
 * Android
 * IOS
 * TVOS
 * Lumen
 * HoloLens
 * 
 * etc.
 * 
 */

 /**
  * Identifiable colours for the different platforms.
  */
namespace PlatformColours
{
	static FColor Win64 = FColor(177, 70, 194);
	static FColor Win32 = FColor(177, 70, 194);

	static FColor Mac = FColor(0, 125, 221);
	static FColor Linux = FColor(255, 69, 0);
	static FColor LinuxArm64 = FColor(255, 69, 0);

	static FColor PS4 = FColor(0, 55, 145);
	static FColor XboxOne = FColor(14, 122, 13);
	static FColor Switch = FColor(230, 0, 18);

	static FColor Android = FColor(13, 175, 84);
	static FColor IOS = FColor(0, 120, 215);
	static FColor TVOS = FColor(0, 120, 215);

	static FColor Lumen = FColor(241, 39, 66);
	static FColor HoloLens = FColor(140, 38, 122);

	static FColor Others = FColor(127, 127, 127);
	static FColor Editor_Only = FColor(255, 219, 88);

	static FColor All = FColor(75, 75, 75);
}

/**
 * Flags used to generate the list of plugins shown based on target platforms.
 */
enum class EPlatformFilter : uint32
{
	None =			0,
	Win64 =			1 << 0,
	Win32 =			1 << 1,

	Mac =			1 << 2,
	Linux =			1 << 3,
	LinuxArm64 =	1 << 4,

	PS4 =			1 << 5,
	XboxOne =		1 << 6,
	Switch =		1 << 7,
	
	Android =		1 << 8,
	IOS =			1 << 9,
	TVOS =			1 << 10,

	Lumen =			1 << 11,
	HoloLens =		1 << 12,

	Others =		1 << 13,
	Editor_Only =	1 << 14,

	All = Win64 | Win32 | Mac | Linux | LinuxArm64 | PS4 | XboxOne | Switch | Android | IOS | TVOS | Lumen | HoloLens | Others | Editor_Only
};
ENUM_CLASS_FLAGS(EPlatformFilter);


/**
 * Simple struct that holds some platform inforation for the plugin view.
 */
struct FPlatformStyleInfo
{
	FString PlatformName;
	FColor StyleColour;
	EPlatformFilter FilterId;

	FPlatformStyleInfo(FString&& InPlatformName, FColor InStyleColor, EPlatformFilter InFilterId)
		: PlatformName(MoveTemp(InPlatformName))
		, StyleColour(InStyleColor)
		, FilterId(InFilterId)
	{}
};


/**
 * Collection of specified platforms from stock UE4 plugins.
 * We use these to generate filters. Any platforms not in this list are covered by "Others"
 */
namespace PlatformStyleInfo
{
	static TSharedPtr<FPlatformStyleInfo> Win64StyleInfo = MakeShareable(new FPlatformStyleInfo(TEXT("Win64"), PlatformColours::Win64, EPlatformFilter::Win64));
	static TSharedPtr<FPlatformStyleInfo> Win32StyleInfo = MakeShareable(new FPlatformStyleInfo(TEXT("Win32"), PlatformColours::Win32, EPlatformFilter::Win32));
	static TSharedPtr<FPlatformStyleInfo> MacStyleInfo = MakeShareable(new FPlatformStyleInfo(TEXT("Mac"), PlatformColours::Mac, EPlatformFilter::Mac));
	static TSharedPtr<FPlatformStyleInfo> LinuxStyleInfo = MakeShareable(new FPlatformStyleInfo(TEXT("Linux"), PlatformColours::Linux, EPlatformFilter::Linux));
	static TSharedPtr<FPlatformStyleInfo> LinuxArm64StyleInfo = MakeShareable(new FPlatformStyleInfo(TEXT("LinuxArm64"), PlatformColours::LinuxArm64, EPlatformFilter::LinuxArm64));
	static TSharedPtr<FPlatformStyleInfo> PS4StyleInfo = MakeShareable(new FPlatformStyleInfo(TEXT("PS4"), PlatformColours::PS4, EPlatformFilter::PS4));
	static TSharedPtr<FPlatformStyleInfo> XboxOneStyleInfo = MakeShareable(new FPlatformStyleInfo(TEXT("XboxOne"), PlatformColours::XboxOne, EPlatformFilter::XboxOne));
	static TSharedPtr<FPlatformStyleInfo> SwitchStyleInfo = MakeShareable(new FPlatformStyleInfo(TEXT("Switch"), PlatformColours::Switch, EPlatformFilter::Switch));
	static TSharedPtr<FPlatformStyleInfo> AndroidStyleInfo = MakeShareable(new FPlatformStyleInfo(TEXT("Android"), PlatformColours::Android, EPlatformFilter::Android));
	static TSharedPtr<FPlatformStyleInfo> IOSStyleInfo = MakeShareable(new FPlatformStyleInfo(TEXT("IOS"), PlatformColours::IOS, EPlatformFilter::IOS));
	static TSharedPtr<FPlatformStyleInfo> TVOSStyleInfo = MakeShareable(new FPlatformStyleInfo(TEXT("TVOS"), PlatformColours::TVOS, EPlatformFilter::TVOS));
	static TSharedPtr<FPlatformStyleInfo> LumenStyleInfo = MakeShareable(new FPlatformStyleInfo(TEXT("Lumen"), PlatformColours::Lumen, EPlatformFilter::Lumen));
	static TSharedPtr<FPlatformStyleInfo> HoloLensStyleInfo = MakeShareable(new FPlatformStyleInfo(TEXT("HoloLens"), PlatformColours::HoloLens, EPlatformFilter::HoloLens));
	static TSharedPtr<FPlatformStyleInfo> OthersStyleInfo = MakeShareable(new FPlatformStyleInfo(TEXT("Others"), PlatformColours::Others, EPlatformFilter::Others));

	static TArray<TSharedPtr<FPlatformStyleInfo>> AllStyleInfo =
	{
		Win64StyleInfo,
		Win32StyleInfo,
		MacStyleInfo,
		LinuxStyleInfo,
		LinuxArm64StyleInfo,
		PS4StyleInfo,
		XboxOneStyleInfo,
		SwitchStyleInfo,
		AndroidStyleInfo,
		IOSStyleInfo,
		TVOSStyleInfo,
		LumenStyleInfo,
		HoloLensStyleInfo,
		OthersStyleInfo
	};
}


/**
 * Simple conversion of platform name to platform colour specified by us above.
 */
inline FColor GetBorderColourForPlatform(const FString& InPlatformName)
{
	if (InPlatformName == TEXT("Win64"))
		return PlatformColours::Win64;
	if (InPlatformName == TEXT("Win32"))
		return PlatformColours::Win32;
	if (InPlatformName == TEXT("Mac"))
		return PlatformColours::Mac;
	if (InPlatformName == TEXT("Linux"))
		return PlatformColours::Linux;
	if (InPlatformName == TEXT("LinuxArm64"))
		return PlatformColours::LinuxArm64;
	if (InPlatformName == TEXT("PS4"))
		return PlatformColours::PS4;
	if (InPlatformName == TEXT("XboxOne"))
		return PlatformColours::XboxOne;
	if (InPlatformName == TEXT("Switch"))
		return PlatformColours::Switch;
	if (InPlatformName == TEXT("Android"))
		return PlatformColours::Android;
	if (InPlatformName == TEXT("IOS"))
		return PlatformColours::IOS;
	if (InPlatformName == TEXT("TVOS"))
		return PlatformColours::TVOS;
	if (InPlatformName == TEXT("Lumen"))
		return PlatformColours::Lumen;
	if (InPlatformName == TEXT("HoloLens"))
		return PlatformColours::HoloLens;

	return PlatformColours::Others;
}


/**
 * Parse filter flags for list of platforms (in string format).
 */
inline TArray<FString> PlatformFilterToPlatformIdStrings(const EPlatformFilter NewFilter)
{
	TArray<FString> PlatformIdStrings;
	if (!!(NewFilter & EPlatformFilter::Win64))
		PlatformIdStrings.Add(TEXT("Win64"));
	if (!!(NewFilter & EPlatformFilter::Win32))
		PlatformIdStrings.Add(TEXT("Win32"));
	if (!!(NewFilter & EPlatformFilter::Mac))
		PlatformIdStrings.Add(TEXT("Mac"));
	if (!!(NewFilter & EPlatformFilter::Linux))
		PlatformIdStrings.Add(TEXT("Linux"));
	if (!!(NewFilter & EPlatformFilter::LinuxArm64))
		PlatformIdStrings.Add(TEXT("LinuxArm64"));
	if (!!(NewFilter & EPlatformFilter::PS4))
		PlatformIdStrings.Add(TEXT("PS4"));
	if (!!(NewFilter & EPlatformFilter::XboxOne))
		PlatformIdStrings.Add(TEXT("XboxOne"));
	if (!!(NewFilter & EPlatformFilter::Switch))
		PlatformIdStrings.Add(TEXT("Switch"));
	if (!!(NewFilter & EPlatformFilter::Android))
		PlatformIdStrings.Add(TEXT("Android"));
	if (!!(NewFilter & EPlatformFilter::IOS))
		PlatformIdStrings.Add(TEXT("IOS"));
	if (!!(NewFilter & EPlatformFilter::TVOS))
		PlatformIdStrings.Add(TEXT("TVOS"));
	if (!!(NewFilter & EPlatformFilter::Lumen))
		PlatformIdStrings.Add(TEXT("Lumen"));
	if (!!(NewFilter & EPlatformFilter::HoloLens))
		PlatformIdStrings.Add(TEXT("HoloLens"));
	if (!!(NewFilter & EPlatformFilter::Others))
		PlatformIdStrings.Add(TEXT("Others"));

	return PlatformIdStrings;
}


/**
 * Convert platform string to EPlatformFilter id.
 */
inline EPlatformFilter PlatformIdStringsToFilterId(const FString InPlatformId)
{
	if (InPlatformId == TEXT("Win64"))
		return EPlatformFilter::Win64;
	if(InPlatformId == TEXT("Win32"))
		return EPlatformFilter::Win32;
	if(InPlatformId == TEXT("Mac"))
		return EPlatformFilter::Mac;
	if(InPlatformId == TEXT("Linux"))
		return EPlatformFilter::Linux;
	if (InPlatformId == TEXT("LinuxArm64"))
		return EPlatformFilter::LinuxArm64;
	if(InPlatformId == TEXT("PS4"))
		return EPlatformFilter::PS4;
	if(InPlatformId == TEXT("XboxOne"))
		return EPlatformFilter::XboxOne;
	if(InPlatformId == TEXT("Switch"))
		return EPlatformFilter::Switch;
	if(InPlatformId == TEXT("Android"))
		return EPlatformFilter::Android;
	if(InPlatformId == TEXT("IOS"))
		return EPlatformFilter::IOS;
	if(InPlatformId == TEXT("TVOS"))
		return EPlatformFilter::TVOS;
	if(InPlatformId == TEXT("Lumen"))
		return EPlatformFilter::Lumen;
	if(InPlatformId == TEXT("HoloLens"))
		return EPlatformFilter::HoloLens;

	return EPlatformFilter::Others;
}