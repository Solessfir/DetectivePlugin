// Copyright 2020 - Trifolium Digital Limited

#include "SProjectFileInfo.h"
#include "ProjectDescriptor.h"
#include "Widgets/Layout/SWidgetSwitcher.h"
#include "Interfaces/IProjectManager.h"
#include "HAL/FileManager.h"

#define LOCTEXT_NAMESPACE "FQuickPluginConfigToolModule"

/** 
 * Colour information we use to relay the status of the uproject file.
 */
namespace ProjectFileInfoPanelHelpers
{
static const FSlateColor CanEditColour(FLinearColor(32.0f/255.0f, 75.0f/255.0f, 16.0f/255.0f));
	static const FSlateColor CanNotEditColour(FLinearColor(179.0f/255.0f, 58.0f/255.0f, 58.0f/255.0f));
}

///////////////////////////////////////////////////////////////////////
// SProjectFileInfo


void SProjectFileInfo::Construct(const FArguments& InArgs)
{
	ProjectFilePath = FPaths::ConvertRelativePathToFull(FPaths::GetProjectFilePath());

	ChildSlot
	[
		SNew(SBorder)
		.Padding(16.0f)
		.BorderImage(FAppStyle::GetBrush("SettingsEditor.CheckoutWarningBorder"))
		.BorderBackgroundColor(ProjectFileInfoPanelHelpers::CanNotEditColour)
		[
			SNew(SBorder)
			.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
			.Padding(4.0f)
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				.Padding( 0.0f, 0.0f, 4.0f, 0.0f )
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					.HAlign(HAlign_Center)
					.AutoWidth()
					[
						SNew(SImage)
						.Image(FAppStyle::GetBrush("LevelEditor.Tabs.Details"))
					]
					+ SHorizontalBox::Slot()
					.HAlign(HAlign_Left)
					[
						SNew(STextBlock)
						.Text(LOCTEXT("ProjectFileInfoStatusStr", "Status"))
						.Font(FAppStyle::GetFontStyle("PropertyWindow.NormalFont"))
					]
				]
				+ SVerticalBox::Slot()
				.AutoHeight()
				[
					SNew(SHorizontalBox)
					+SHorizontalBox::Slot()
					.HAlign(EHorizontalAlignment::HAlign_Center)
					[
						SNew(SVerticalBox)
						+ SVerticalBox::Slot()
						[
							SNew(STextBlock)
							.Text(LOCTEXT("UnableToEditLabel", "Unable to make changes to the project file. Please make sure the uproject is writable."))
							.Font(FAppStyle::GetFontStyle("DetailsView.CategoryFontStyle"))
						]
						+ SVerticalBox::Slot()
						.Padding(4.0f)
						[
							SNew(SBox)
							.HAlign(HAlign_Center)
							[
								SNew(SHorizontalBox)
								+ SHorizontalBox::Slot()
								.HAlign(HAlign_Center)
								.AutoWidth()
								[
									SNew(STextBlock)
									.Text(LOCTEXT("ProjectPathLabel", "Project Path - "))
									.Font(FAppStyle::GetFontStyle("PropertyWindow.NormalFont"))
								]
								+ SHorizontalBox::Slot()
								.HAlign(HAlign_Left)
								[
									SNew(STextBlock)
									.Text(FText::FromString(ProjectFilePath))
									.Font(FAppStyle::GetFontStyle("PropertyWindow.NormalFont"))
								]
							]
						]
					]
				]
			]
		]
	];
}


#undef LOCTEXT_NAMESPACE
