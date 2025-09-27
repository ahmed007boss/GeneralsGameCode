/*
**	Command & Conquer Generals Zero Hour(tm)
**	Copyright 2025 Electronic Arts Inc.
**
**	This program is free software: you can redistribute it and/or modify
**	it under the terms of the GNU General Public License as published by
**	the Free Software Foundation, either version 3 of the License, or
**	(at your option) any later version.
**
**	This program is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**	GNU General Public License for more details.
**
**	You should have received a copy of the GNU General Public License
**	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

////////////////////////////////////////////////////////////////////////////////
//																																						//
//  (c) 2001-2003 Electronic Arts Inc.																				//
//																																						//
////////////////////////////////////////////////////////////////////////////////

// FILE: ControlBarPopupDescription.cpp /////////////////////////////////////////////////
//-----------------------------------------------------------------------------
//
//                       Electronic Arts Pacific.
//
//                       Confidential Information
//                Copyright (C) 2002 - All Rights Reserved
//
//-----------------------------------------------------------------------------
//
//	created:	Sep 2002
//
//	Filename: 	ControlBarPopupDescription.cpp
//
//	author:		Chris Huybregts
//
//	purpose:
//
//-----------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------------
// SYSTEM INCLUDES ////////////////////////////////////////////////////////////
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// USER INCLUDES //////////////////////////////////////////////////////////////
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// DEFINES ////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// PUBLIC FUNCTIONS ///////////////////////////////////////////////////////////
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// PRIVATE FUNCTIONS //////////////////////////////////////////////////////////
//-----------------------------------------------------------------------------


// INCLUDES ///////////////////////////////////////////////////////////////////////////////////////
#include "PreRTS.h"	// This must go first in EVERY cpp file int the GameEngine

#include "Common/GlobalData.h"
#include "Common/BuildAssistant.h"
#include "Common/Player.h"
#include "Common/PlayerList.h"
#include "Common/PlayerPrerequisite.h"
#include "Common/ObjectPrerequisite.h"
#include "Common/SpecialPower.h"
#include "Common/ThingTemplate.h"
#include "Common/Upgrade.h"
#include "GameClient/AnimateWindowManager.h"
#include "GameClient/DisconnectMenu.h"
#include "GameClient/GameWindow.h"
#include "GameClient/Gadget.h"
#include "GameClient/GadgetTextEntry.h"
#include "GameClient/GadgetPushButton.h"
#include "GameClient/GadgetStaticText.h"
#include "GameClient/GameClient.h"
#include "GameClient/GameText.h"
#include "GameClient/GUICallbacks.h"
#include "GameClient/InGameUI.h"
#include "GameClient/ControlBar.h"
#include "GameClient/DisplayStringManager.h"
#include "GameLogic/GameLogic.h"
#include "GameLogic/Module/OverchargeBehavior.h"
#include "GameLogic/Module/ProductionUpdate.h"
#include "GameLogic/Module/InventoryBehavior.h"
#include "GameLogic/ScriptEngine.h"

#include "GameNetwork/NetworkInterface.h"

static WindowLayout* theLayout = NULL;
static GameWindow* theWindow = NULL;
static AnimateWindowManager* theAnimateWindowManager = NULL;
static GameWindow* prevWindow = NULL;
static Bool useAnimation = FALSE;
void ControlBarPopupDescriptionUpdateFunc(WindowLayout* layout, void* param)
{
	if (TheScriptEngine->isGameEnding())
		TheControlBar->hideBuildTooltipLayout();

	if (theAnimateWindowManager && !TheControlBar->getShowBuildTooltipLayout() && !theAnimateWindowManager->isReversed())
		theAnimateWindowManager->reverseAnimateWindow();
	else if (!TheControlBar->getShowBuildTooltipLayout() && (!TheGlobalData->m_animateWindows || !useAnimation))
		TheControlBar->deleteBuildTooltipLayout();


	if (useAnimation && theAnimateWindowManager && TheGlobalData->m_animateWindows)
	{
		Bool wasFinished = theAnimateWindowManager->isFinished();
		theAnimateWindowManager->update();
		if (theAnimateWindowManager->isFinished() && !wasFinished && theAnimateWindowManager->isReversed())
		{
			delete theAnimateWindowManager;
			theAnimateWindowManager = NULL;
			TheControlBar->deleteBuildTooltipLayout();
		}
	}

}

// ---------------------------------------------------------------------------------------
void ControlBar::showBuildTooltipLayout(GameWindow* cmdButton)
{
	if (TheInGameUI->areTooltipsDisabled() || TheScriptEngine->isGameEnding())
	{
		return;
	}

	Bool passedWaitTime = FALSE;
	static Bool isInitialized = FALSE;
	static UnsignedInt beginWaitTime;
	if (prevWindow == cmdButton)
	{
		m_showBuildToolTipLayout = TRUE;
		if (!isInitialized && beginWaitTime + cmdButton->getTooltipDelay() < timeGetTime())
		{
			//DEBUG_LOG(("%d beginwaittime, %d tooltipdelay, %dtimegettime", beginWaitTime, cmdButton->getTooltipDelay(), timeGetTime()));
			passedWaitTime = TRUE;
		}

		if (!passedWaitTime)
			return;
	}
	else if (!m_buildToolTipLayout->isHidden())
	{
		if (useAnimation && TheGlobalData->m_animateWindows && !theAnimateWindowManager->isReversed())
			theAnimateWindowManager->reverseAnimateWindow();
		else if (useAnimation && TheGlobalData->m_animateWindows && theAnimateWindowManager->isReversed())
		{
			return;
		}
		else
		{
			//			m_buildToolTipLayout->destroyWindows();
			//			deleteInstance(m_buildToolTipLayout);
			//			m_buildToolTipLayout = NULL;
			m_buildToolTipLayout->hide(TRUE);
			prevWindow = NULL;
		}
		return;
	}


	// will only get here the firsttime through the function through this window
	if (!passedWaitTime)
	{
		prevWindow = cmdButton;
		beginWaitTime = timeGetTime();
		isInitialized = FALSE;
		return;
	}
	isInitialized = TRUE;

	if (!cmdButton)
		return;
	if (BitIsSet(cmdButton->winGetStyle(), GWS_PUSH_BUTTON))
	{
		const CommandButton* commandButton = (const CommandButton*)GadgetButtonGetData(cmdButton);

		if (!commandButton)
			return;

		// note that, in this branch, ENABLE_SOLO_PLAY is ***NEVER*** defined...
		// this is so that we have a multiplayer build that cannot possibly be hacked
		// to work as a solo game!
		if (TheGameLogic->isInReplayGame())
			return;

		if (TheInGameUI->isQuitMenuVisible())
			return;

		if (TheDisconnectMenu && TheDisconnectMenu->isScreenVisible())
			return;

		//	if (m_buildToolTipLayout)
		//	{
		//		m_buildToolTipLayout->destroyWindows();
		//		deleteInstance(m_buildToolTipLayout);
		//
		//	}

		m_showBuildToolTipLayout = TRUE;
		//	m_buildToolTipLayout = TheWindowManager->winCreateLayout( "ControlBarPopupDescription.wnd" );
		//	m_buildToolTipLayout->setUpdate(ControlBarPopupDescriptionUpdateFunc);

		populateBuildTooltipLayout(commandButton);
	}
	else
	{
		// we're a generic window
		if (!BitIsSet(cmdButton->winGetStyle(), GWS_USER_WINDOW) && !BitIsSet(cmdButton->winGetStyle(), GWS_STATIC_TEXT))
			return;
		populateBuildTooltipLayout(NULL, cmdButton);
	}
	m_buildToolTipLayout->hide(FALSE);

	if (useAnimation && TheGlobalData->m_animateWindows)
	{
		theAnimateWindowManager = NEW AnimateWindowManager;
		theAnimateWindowManager->reset();
		theAnimateWindowManager->registerGameWindow(m_buildToolTipLayout->getFirstWindow(), WIN_ANIMATION_SLIDE_RIGHT_FAST, TRUE, 200);
	}


}


void ControlBar::repopulateBuildTooltipLayout(void)
{
	if (!prevWindow || !m_buildToolTipLayout)
		return;
	if (!BitIsSet(prevWindow->winGetStyle(), GWS_PUSH_BUTTON))
		return;
	const CommandButton* commandButton = (const CommandButton*)GadgetButtonGetData(prevWindow);
	populateBuildTooltipLayout(commandButton);
}

//-------------------------------------------------------------------------------------------------
/** Helper function to remove hotkey shortcuts like (&B) from button text */
//-------------------------------------------------------------------------------------------------
static UnicodeString removeHotkeyFromText(const UnicodeString& text)
{
	// TheSuperHackers @hotkey Ahmed Salah 27/06/2025 Remove hotkey shortcuts like (&B) from button text in tooltips for cleaner display
	// Convert to wide char string for processing
	const WideChar* str = text.str();
	Int len = text.getLength();
	
	// Create a new string without the hotkey patterns
	UnicodeString result;
	
	for (Int i = 0; i < len; i++)
	{
		// Check if we found the start of a hotkey pattern (&X)
		if (i + 3 < len && 
			str[i] == L'(' && str[i + 1] == L'&' && 
			str[i + 2] >= L'A' && str[i + 2] <= L'Z' && 
			str[i + 3] == L')')
		{
			// Skip the entire (&X) pattern
			i += 3; // Skip past the closing )
		}
		else
		{
			// Add this character to the result
			result.concat(str[i]);
		}
	}
	
	return result;
}

//-------------------------------------------------------------------------------------------------
/** Helper function to generate button alternatives text for tooltips */
//-------------------------------------------------------------------------------------------------
// TheSuperHackers @tooltip Ahmed Salah 27/06/2025 Generate tooltip text for alternative modifier-based command buttons with availability checking
static UnicodeString getButtonAlternativesText(const CommandButton* commandButton, const ControlBar* controlBar)
{
	UnicodeString alternativesText = UnicodeString::TheEmptyString;
	Bool hasAlternatives = false;
	
	// Get the current object for availability checking
	Drawable* draw = TheInGameUI->getFirstSelectedDrawable();
	Object* selectedObject = draw ? draw->getObject() : NULL;
	
	// Helper function to check if an alternative button is available and get its cost
	auto isButtonAvailable = [selectedObject, controlBar](const CommandButton* altButton) -> Bool {
		if (!altButton || !selectedObject || !controlBar) return false;
		// Check availability using the control bar's getCommandAvailability method
		CommandAvailability availability = controlBar->getCommandAvailability(altButton, selectedObject, theWindow);
		return (availability == COMMAND_AVAILABLE);
	};
	
	// Helper function to get cost text for a button
	auto getButtonCostText = [selectedObject](const CommandButton* altButton) -> UnicodeString {
		if (!altButton || !selectedObject) return UnicodeString::TheEmptyString;
		
		Player* player = ThePlayerList->getLocalPlayer();
		if (!player) return UnicodeString::TheEmptyString;
		
		UnsignedInt buttonCost = altButton->getCostOfExecution(player, selectedObject);
		if (buttonCost > 0)
		{
			UnicodeString costText;
			costText.format(L" (%d$)", buttonCost);
			return costText;
		}
		return UnicodeString::TheEmptyString;
	};
	
	// Check for right-click alternatives
	if (commandButton->getRightClickCtrlAltShiftButton() && isButtonAvailable(commandButton->getRightClickCtrlAltShiftButton()))
	{
		if (!hasAlternatives)
		{
			alternativesText = L"\n\n";
			hasAlternatives = true;
		}
		alternativesText.concat(TheGameText->fetch("TOOLTIP:RightClickCtrlAltShiftTo"));
		alternativesText.concat(L" ");
		alternativesText.concat(removeHotkeyFromText(TheGameText->fetch(commandButton->getRightClickCtrlAltShiftButton()->getTextLabel().str())));
		alternativesText.concat(getButtonCostText(commandButton->getRightClickCtrlAltShiftButton()));
		alternativesText.concat(L"\n");
	}
	if (commandButton->getRightClickCtrlAltButton() && isButtonAvailable(commandButton->getRightClickCtrlAltButton()))
	{
		if (!hasAlternatives)
		{
			alternativesText = L"\n\n";
			hasAlternatives = true;
		}
		alternativesText.concat(TheGameText->fetch("TOOLTIP:RightClickCtrlAltTo"));
		alternativesText.concat(L" ");
		alternativesText.concat(removeHotkeyFromText(TheGameText->fetch(commandButton->getRightClickCtrlAltButton()->getTextLabel().str())));
		alternativesText.concat(getButtonCostText(commandButton->getRightClickCtrlAltButton()));
		alternativesText.concat(L"\n");
	}
	if (commandButton->getRightClickCtrlShiftButton() && isButtonAvailable(commandButton->getRightClickCtrlShiftButton()))
	{
		if (!hasAlternatives)
		{
			alternativesText = L"\n\n";
			hasAlternatives = true;
		}
		alternativesText.concat(TheGameText->fetch("TOOLTIP:RightClickCtrlShiftTo"));
		alternativesText.concat(L" ");
		alternativesText.concat(removeHotkeyFromText(TheGameText->fetch(commandButton->getRightClickCtrlShiftButton()->getTextLabel().str())));
		alternativesText.concat(getButtonCostText(commandButton->getRightClickCtrlShiftButton()));
		alternativesText.concat(L"\n");
	}
	if (commandButton->getRightClickAltShiftButton() && isButtonAvailable(commandButton->getRightClickAltShiftButton()))
	{
		if (!hasAlternatives)
		{
			alternativesText = L"\n\n";
			hasAlternatives = true;
		}
		alternativesText.concat(TheGameText->fetch("TOOLTIP:RightClickAltShiftTo"));
		alternativesText.concat(L" ");
		alternativesText.concat(removeHotkeyFromText(TheGameText->fetch(commandButton->getRightClickAltShiftButton()->getTextLabel().str())));
		alternativesText.concat(getButtonCostText(commandButton->getRightClickAltShiftButton()));
		alternativesText.concat(L"\n");
	}
	if (commandButton->getRightClickButton() && isButtonAvailable(commandButton->getRightClickButton()))
	{
		if (!hasAlternatives)
		{
			alternativesText = L"\n\n";
			hasAlternatives = true;
		}
		alternativesText.concat(TheGameText->fetch("TOOLTIP:RightClickTo"));
		alternativesText.concat(L" ");
		alternativesText.concat(removeHotkeyFromText(TheGameText->fetch(commandButton->getRightClickButton()->getTextLabel().str())));
		alternativesText.concat(getButtonCostText(commandButton->getRightClickButton()));
		alternativesText.concat(L"\n");
	}
	if (commandButton->getRightClickCtrlButton() && isButtonAvailable(commandButton->getRightClickCtrlButton()))
	{
		if (!hasAlternatives)
		{
			alternativesText = L"\n\n";
			hasAlternatives = true;
		}
		alternativesText.concat(TheGameText->fetch("TOOLTIP:RightClickCtrlTo"));
		alternativesText.concat(L" ");
		alternativesText.concat(removeHotkeyFromText(TheGameText->fetch(commandButton->getRightClickCtrlButton()->getTextLabel().str())));
		alternativesText.concat(getButtonCostText(commandButton->getRightClickCtrlButton()));
		alternativesText.concat(L"\n");
	}
	if (commandButton->getRightClickAltButton() && isButtonAvailable(commandButton->getRightClickAltButton()))
	{
		if (!hasAlternatives)
		{
			alternativesText = L"\n\n";
			hasAlternatives = true;
		}
		alternativesText.concat(TheGameText->fetch("TOOLTIP:RightClickAltTo"));
		alternativesText.concat(L" ");
		alternativesText.concat(removeHotkeyFromText(TheGameText->fetch(commandButton->getRightClickAltButton()->getTextLabel().str())));
		alternativesText.concat(getButtonCostText(commandButton->getRightClickAltButton()));
		alternativesText.concat(L"\n");
	}
	if (commandButton->getRightClickShiftButton() && isButtonAvailable(commandButton->getRightClickShiftButton()))
	{
		if (!hasAlternatives)
		{
			alternativesText = L"\n\n";
			hasAlternatives = true;
		}
		alternativesText.concat(TheGameText->fetch("TOOLTIP:RightClickShiftTo"));
		alternativesText.concat(L" ");
		alternativesText.concat(removeHotkeyFromText(TheGameText->fetch(commandButton->getRightClickShiftButton()->getTextLabel().str())));
		alternativesText.concat(getButtonCostText(commandButton->getRightClickShiftButton()));
		alternativesText.concat(L"\n");
	}
	
	// Check for left-click modifier alternatives
	if (commandButton->getLeftClickCtrlAltShiftButton() && isButtonAvailable(commandButton->getLeftClickCtrlAltShiftButton()))
	{
		if (!hasAlternatives)
		{
			alternativesText = L"\n\n";
			hasAlternatives = true;
		}
		alternativesText.concat(TheGameText->fetch("TOOLTIP:LeftClickCtrlAltShiftTo"));
		alternativesText.concat(L" ");
		alternativesText.concat(removeHotkeyFromText(TheGameText->fetch(commandButton->getLeftClickCtrlAltShiftButton()->getTextLabel().str())));
		alternativesText.concat(getButtonCostText(commandButton->getLeftClickCtrlAltShiftButton()));
		alternativesText.concat(L"\n");
	}
	if (commandButton->getLeftClickCtrlAltButton() && isButtonAvailable(commandButton->getLeftClickCtrlAltButton()))
	{
		if (!hasAlternatives)
		{
			alternativesText = L"\n\n";
			hasAlternatives = true;
		}
		alternativesText.concat(TheGameText->fetch("TOOLTIP:LeftClickCtrlAltTo"));
		alternativesText.concat(L" ");
		alternativesText.concat(removeHotkeyFromText(TheGameText->fetch(commandButton->getLeftClickCtrlAltButton()->getTextLabel().str())));
		alternativesText.concat(getButtonCostText(commandButton->getLeftClickCtrlAltButton()));
		alternativesText.concat(L"\n");
	}
	if (commandButton->getLeftClickCtrlShiftButton() && isButtonAvailable(commandButton->getLeftClickCtrlShiftButton()))
	{
		if (!hasAlternatives)
		{
			alternativesText = L"\n\n";
			hasAlternatives = true;
		}
		alternativesText.concat(TheGameText->fetch("TOOLTIP:LeftClickCtrlShiftTo"));
		alternativesText.concat(L" ");
		alternativesText.concat(removeHotkeyFromText(TheGameText->fetch(commandButton->getLeftClickCtrlShiftButton()->getTextLabel().str())));
		alternativesText.concat(getButtonCostText(commandButton->getLeftClickCtrlShiftButton()));
		alternativesText.concat(L"\n");
	}
	if (commandButton->getLeftClickAltShiftButton() && isButtonAvailable(commandButton->getLeftClickAltShiftButton()))
	{
		if (!hasAlternatives)
		{
			alternativesText = L"\n\n";
			hasAlternatives = true;
		}
		alternativesText.concat(TheGameText->fetch("TOOLTIP:LeftClickAltShiftTo"));
		alternativesText.concat(L" ");
		alternativesText.concat(removeHotkeyFromText(TheGameText->fetch(commandButton->getLeftClickAltShiftButton()->getTextLabel().str())));
		alternativesText.concat(getButtonCostText(commandButton->getLeftClickAltShiftButton()));
		alternativesText.concat(L"\n");
	}
	if (commandButton->getLeftClickCtrlButton() && isButtonAvailable(commandButton->getLeftClickCtrlButton()))
	{
		if (!hasAlternatives)
		{
			alternativesText = L"\n\n";
			hasAlternatives = true;
		}
		alternativesText.concat(TheGameText->fetch("TOOLTIP:LeftClickCtrlTo"));
		alternativesText.concat(L" ");
		alternativesText.concat(removeHotkeyFromText(TheGameText->fetch(commandButton->getLeftClickCtrlButton()->getTextLabel().str())));
		alternativesText.concat(getButtonCostText(commandButton->getLeftClickCtrlButton()));
		alternativesText.concat(L"\n");
	}
	if (commandButton->getLeftClickAltButton() && isButtonAvailable(commandButton->getLeftClickAltButton()))
	{
		if (!hasAlternatives)
		{
			alternativesText = L"\n\n";
			hasAlternatives = true;
		}
		alternativesText.concat(TheGameText->fetch("TOOLTIP:LeftClickAltTo"));
		alternativesText.concat(L" ");
		alternativesText.concat(removeHotkeyFromText(TheGameText->fetch(commandButton->getLeftClickAltButton()->getTextLabel().str())));
		alternativesText.concat(getButtonCostText(commandButton->getLeftClickAltButton()));
		alternativesText.concat(L"\n");
	}
	if (commandButton->getLeftClickShiftButton() && isButtonAvailable(commandButton->getLeftClickShiftButton()))
	{
		if (!hasAlternatives)
		{
			alternativesText = L"\n\n";
			hasAlternatives = true;
		}
		alternativesText.concat(TheGameText->fetch("TOOLTIP:LeftClickShiftTo"));
		alternativesText.concat(L" ");
		alternativesText.concat(removeHotkeyFromText(TheGameText->fetch(commandButton->getLeftClickShiftButton()->getTextLabel().str())));
		alternativesText.concat(getButtonCostText(commandButton->getLeftClickShiftButton()));
		alternativesText.concat(L"\n");
	}
	
	// TheSuperHackers @feature author 15/01/2025 Add mass production alternatives for modifier keys
	if (commandButton->getEnableMassProduction() && 
		commandButton->getCommandType() == GUI_COMMAND_UNIT_BUILD &&
		commandButton->getThingTemplate())
	{
		// Helper function to get mass production cost text
		auto getMassProductionCostText = [selectedObject](const CommandButton* button, Int multiplier) -> UnicodeString {
			if (!button || !selectedObject) return UnicodeString::TheEmptyString;
			
			Player* player = ThePlayerList->getLocalPlayer();
			if (!player) return UnicodeString::TheEmptyString;
			
			UnsignedInt baseCost = button->getCostOfExecution(player, selectedObject);
			UnsignedInt totalCost = baseCost * multiplier;
			if (totalCost > 0)
			{
				UnicodeString costText;
				costText.format(L" (%d$)", totalCost);
				return costText;
			}
			return UnicodeString::TheEmptyString;
		};
		
		// Helper function to format mass production text with intelligent multiplier placement
		auto formatMassProductionText = [](const UnicodeString& originalText, const UnicodeString& multiplier) -> UnicodeString {
			// Simple approach: replace "Build " with "Build x6 " (case-insensitive)
			UnicodeString result = originalText;
			
			// Check for "Build " (with space) - case insensitive
			UnicodeString lowerText = originalText;
			// Convert to lowercase for comparison
			for (Int i = 0; i < lowerText.getLength(); i++) {
				wchar_t c = lowerText.str()[i];
				if (c >= L'A' && c <= L'Z') {
					// Create new string with lowercase character
					UnicodeString newLowerText;
					for (Int j = 0; j < i; j++) {
						newLowerText.concat(lowerText.str()[j]);
					}
					newLowerText.concat(c + (L'a' - L'A'));
					for (Int j = i + 1; j < lowerText.getLength(); j++) {
						newLowerText.concat(lowerText.str()[j]);
					}
					lowerText = newLowerText;
				}
			}
			
			// Look for "build " pattern
			Int buildSpacePos = -1;
			for (Int i = 0; i <= lowerText.getLength() - 6; i++) {
				if (lowerText.str()[i] == L'b' && lowerText.str()[i+1] == L'u' && 
					lowerText.str()[i+2] == L'i' && lowerText.str()[i+3] == L'l' && 
					lowerText.str()[i+4] == L'd' && lowerText.str()[i+5] == L' ') {
					buildSpacePos = i;
					break;
				}
			}
			
			if (buildSpacePos >= 0) {
				// Found "Build " - replace with "Build x6 "
				UnicodeString newResult;
				// Copy text up to "Build "
				for (Int i = 0; i < buildSpacePos + 6; i++) {
					newResult.concat(originalText.str()[i]);
				}
				// Add multiplier with space
				newResult.concat(multiplier);
				newResult.concat(L" ");
				// Copy rest of text
				for (Int i = buildSpacePos + 6; i < originalText.getLength(); i++) {
					newResult.concat(originalText.str()[i]);
				}
				return newResult;
			} else {
				// No "Build " found - append multiplier at the end
				result.concat(L" ");
				result.concat(multiplier);
				return result;
			}
		};
		
		// Get MaxSimultaneousOfType to limit mass production options
		Int maxSimultaneous = 0;
		if (commandButton->getThingTemplate()) {
			maxSimultaneous = commandButton->getThingTemplate()->getMaxSimultaneousOfType();
		}
		
		// Check for Shift+Click (3x) - only if no Shift button assigned and MaxSimultaneousOfType >= 3 (or unlimited if < 1)
		if (!commandButton->getLeftClickShiftButton() && (maxSimultaneous < 1 || maxSimultaneous >= 3))
		{
			if (!hasAlternatives)
			{
				alternativesText = L"\n\n";
				hasAlternatives = true;
			}
			alternativesText.concat(TheGameText->fetch("TOOLTIP:LeftClickShiftTo"));
			alternativesText.concat(L" ");
			UnicodeString originalText = removeHotkeyFromText(TheGameText->fetch(commandButton->getTextLabel().str()));
			UnicodeString formattedText = formatMassProductionText(originalText, L"3x");
			alternativesText.concat(formattedText);
			alternativesText.concat(getMassProductionCostText(commandButton, 3));
			alternativesText.concat(L"\n");
		}
		
		// Check for Ctrl+Click (6x) - only if no Ctrl button assigned and MaxSimultaneousOfType >= 6 (or unlimited if < 1)
		if (!commandButton->getLeftClickCtrlButton() && (maxSimultaneous < 1 || maxSimultaneous >= 6))
		{
			if (!hasAlternatives)
			{
				alternativesText = L"\n\n";
				hasAlternatives = true;
			}
			alternativesText.concat(TheGameText->fetch("TOOLTIP:LeftClickCtrlTo"));
			alternativesText.concat(L" ");
			UnicodeString originalText = removeHotkeyFromText(TheGameText->fetch(commandButton->getTextLabel().str()));
			UnicodeString formattedText = formatMassProductionText(originalText, L"6x");
			alternativesText.concat(formattedText);
			alternativesText.concat(getMassProductionCostText(commandButton, 6));
			alternativesText.concat(L"\n");
		}
		
		// Check for Alt+Click (9x) - only if no Alt button assigned and MaxSimultaneousOfType >= 9 (or unlimited if < 1)
		if (!commandButton->getLeftClickAltButton() && (maxSimultaneous < 1 || maxSimultaneous >= 9))
		{
			if (!hasAlternatives)
			{
				alternativesText = L"\n\n";
				hasAlternatives = true;
			}
			alternativesText.concat(TheGameText->fetch("TOOLTIP:LeftClickAltTo"));
			alternativesText.concat(L" ");
			UnicodeString originalText = removeHotkeyFromText(TheGameText->fetch(commandButton->getTextLabel().str()));
			UnicodeString formattedText = formatMassProductionText(originalText, L"9x");
			alternativesText.concat(formattedText);
			alternativesText.concat(getMassProductionCostText(commandButton, 9));
			alternativesText.concat(L"\n");
		}
	}
	
	return alternativesText;
}

//-------------------------------------------------------------------------------------------------
void ControlBar::populateBuildTooltipLayout(const CommandButton* commandButton, GameWindow* tooltipWin)
{
	if (!m_buildToolTipLayout)
		return;

	Player* player = ThePlayerList->getLocalPlayer();
	UnicodeString name, cost, descrip;
	UnicodeString requiresFormat = UnicodeString::TheEmptyString, requiresList;
	UnicodeString conflictsFormat = UnicodeString::TheEmptyString, conflictsList;
	Bool firstRequirement = true;
	Bool firstConflicts = true;
	const PlayerPrerequisite* prereq;
	Bool fireScienceButton = false;
	UnsignedInt costToBuild = 0;

	if (commandButton)
	{
		const ThingTemplate* thingTemplate = commandButton->getThingTemplate();
		const UpgradeTemplate* upgradeTemplate = commandButton->getUpgradeTemplate();
		const SpecialPowerTemplate* specialPowerTemplate = commandButton->getSpecialPowerTemplate();

		



		ScienceType	st = SCIENCE_INVALID;
		if (commandButton->getCommandType() != GUI_COMMAND_PLAYER_UPGRADE &&
			commandButton->getCommandType() != GUI_COMMAND_OBJECT_UPGRADE)
		{
			if (commandButton->getScienceVec().size() > 1)
			{
				for (size_t j = 0; j < commandButton->getScienceVec().size(); ++j)
				{
					st = commandButton->getScienceVec()[j];

					if (commandButton->getCommandType() != GUI_COMMAND_PURCHASE_SCIENCE)
					{
						if (!player->hasScience(st) && j > 0)
						{
							//If we're not looking at a command button that purchases a science, then
							//it means we are looking at a command button that can USE the science. This
							//means we want to get the description for the previous science -- the one
							//we can use, not purchase!
							st = commandButton->getScienceVec()[j - 1];
						}

						//Now that we got the science for the button that executes the science, we need
						//to generate a simpler help text!
						fireScienceButton = TRUE;

						break;
					}
					else if (!player->hasScience(st))
					{
						//Purchase science case. The first science we run into that we don't have, that's the
						//one we'll want to show!
						break;
					}
				}
			}
			else if (commandButton->getScienceVec().size() == 1)
			{
				st = commandButton->getScienceVec()[0];
				if (commandButton->getCommandType() != GUI_COMMAND_PURCHASE_SCIENCE)
				{
					//Now that we got the science for the button that executes the science, we need
					//to generate a simpler help text!
					fireScienceButton = TRUE;
				}
			}
		}
		if (thingTemplate)
		{
			UnicodeString kindOfDesc = thingTemplate->getKindOfDescription();
			if (!kindOfDesc.isEmpty())
			{
				descrip = kindOfDesc + L"\n\n";
			}
		}
		if (commandButton->getDescriptionLabel().isNotEmpty())
		{

			descrip += TheGameText->fetch(commandButton->getDescriptionLabel());

			Drawable* draw = TheInGameUI->getFirstSelectedDrawable();
			Object* selectedObject = draw ? draw->getObject() : NULL;
			if (selectedObject)
			{
				//Special case: Append status of overcharge on China power plant.
				if (commandButton->getCommandType() == GUI_COMMAND_TOGGLE_OVERCHARGE)
				{
					{
						OverchargeBehaviorInterface* obi;
						for (BehaviorModule** bmi = selectedObject->getBehaviorModules(); *bmi; ++bmi)
						{
							obi = (*bmi)->getOverchargeBehaviorInterface();
							if (obi)
							{
								descrip.concat(L"\n\n");
								if (obi->isOverchargeActive())
									descrip.concat(TheGameText->fetch("TOOLTIP:TooltipNukeReactorOverChargeIsOn"));
								else
									descrip.concat(TheGameText->fetch("TOOLTIP:TooltipNukeReactorOverChargeIsOff"));
							}
						}
					}
				}

				//Special case: When building units & buildings, the CanMakeType determines reasons for not being able to buy stuff.
				else if (thingTemplate)
				{
					CanMakeType makeType = TheBuildAssistant->canMakeUnit(selectedObject, commandButton->getThingTemplate());
					switch (makeType)
					{
					case CANMAKE_NO_MONEY:
						descrip.concat(L"\n\n");
						descrip.concat(TheGameText->fetch("TOOLTIP:TooltipNotEnoughMoneyToBuild"));
						break;
					case CANMAKE_QUEUE_FULL:
						descrip.concat(L"\n\n");
						descrip.concat(TheGameText->fetch("TOOLTIP:TooltipCannotPurchaseBecauseQueueFull"));
						break;
					case CANMAKE_PARKING_PLACES_FULL:
						descrip.concat(L"\n\n");
						descrip.concat(TheGameText->fetch("TOOLTIP:TooltipCannotBuildUnitBecauseParkingFull"));
						break;
					case CANMAKE_MAXED_OUT_FOR_PLAYER:
						descrip.concat(L"\n\n");
						if (thingTemplate->isKindOf(KINDOF_STRUCTURE))
						{
							descrip.concat(TheGameText->fetch("TOOLTIP:TooltipCannotBuildBuildingBecauseMaximumNumber"));
						}
						else
						{
							descrip.concat(TheGameText->fetch("TOOLTIP:TooltipCannotBuildUnitBecauseMaximumNumber"));
						}
						break;
						//case CANMAKE_NO_PREREQ:
						//	descrip.concat( L"\n\n" );
						//	descrip.concat( TheGameText->fetch( "TOOLTIP:TooltipCannotBuildDueToPrerequisites" ) );
						//	break;
					}
				}

				//Special case: When building upgrades
				else if (upgradeTemplate && !player->hasUpgradeInProduction(upgradeTemplate))
				{
					if (commandButton->getCommandType() == GUI_COMMAND_PLAYER_UPGRADE ||
						commandButton->getCommandType() == GUI_COMMAND_OBJECT_UPGRADE)
					{
						ProductionUpdateInterface* pui = selectedObject->getProductionUpdateInterface();
						if (pui && pui->getProductionCount() == MAX_BUILD_QUEUE_BUTTONS)
						{
							descrip.concat(L"\n\n");
							descrip.concat(TheGameText->fetch("TOOLTIP:TooltipCannotPurchaseBecauseQueueFull"));
						}
						else if (!TheUpgradeCenter->canAffordUpgrade(ThePlayerList->getLocalPlayer(), upgradeTemplate, FALSE))
						{
							descrip.concat(L"\n\n");
							descrip.concat(TheGameText->fetch("TOOLTIP:TooltipNotEnoughMoneyToBuild"));
						}
					}
				}

			}

		}


		// ask each prerequisite to give us a list of the non satisfied prerequisites
		for (Int i = 0; i < commandButton->getEnablePrereqCount(); i++)
		{
			prereq = commandButton->getNthEnablePrereq(i);
			if (!prereq->isSatisfied(player))
			{
				requiresList = prereq->getRequiresList(player);
				conflictsList =  prereq->getConflictList(player);
				if (requiresList != UnicodeString::TheEmptyString)
				{
					// make sure to put in 'returns' to space things correctly
					if (firstRequirement)
						firstRequirement = false;
					else
						requiresFormat.concat(L", ");
				}
				requiresFormat.concat(requiresList);

				if (conflictsList != UnicodeString::TheEmptyString)
				{
					// make sure to put in 'returns' to space things correctly
					if (firstConflicts)
						firstConflicts = false;
					else
						conflictsFormat.concat(L", ");
				}
				conflictsFormat.concat(conflictsList);

			}
		}

		// Check enable caller unit prerequisites
		Drawable* draw = TheInGameUI->getFirstSelectedDrawable();
		Object* selectedObject = draw ? draw->getObject() : NULL;
		if (selectedObject)
		{
			for (Int i = 0; i < commandButton->getEnableCallerUnitPrereqCount(); i++)
			{
				const ObjectPrerequisite* objPrereq = commandButton->getNthEnableCallerUnitPrereq(i);
				if (!objPrereq->isSatisfied(selectedObject))
				{
					requiresList = objPrereq->getRequiresList(selectedObject);
					conflictsList = objPrereq->getConflictList(selectedObject);
					if (requiresList != UnicodeString::TheEmptyString)
					{
						// make sure to put in 'returns' to space things correctly
						if (firstRequirement)
							firstRequirement = false;
						else
							requiresFormat.concat(L", ");
					}
					requiresFormat.concat(requiresList);

					if (conflictsList != UnicodeString::TheEmptyString)
					{
						// make sure to put in 'returns' to space things correctly
						if (firstConflicts)
							firstConflicts = false;
						else
							conflictsFormat.concat(L", ");
					}
					conflictsFormat.concat(conflictsList);
				}
			}
		}

	

		name = TheGameText->fetch(commandButton->getTextLabel().str());

		// Add KindOf description if available
		// TheSuperHackers @tooltip author 15/01/2025 Add KindOf description to tooltip display
		if (thingTemplate)
		{
			UnicodeString kindOfDesc = thingTemplate->getKindOfDescription();
			if (!kindOfDesc.isEmpty())
			{			
				descrip += kindOfDesc;
			}
		}

		if (thingTemplate && commandButton->getCommandType() != GUI_COMMAND_PURCHASE_SCIENCE)
		{
			//We are either looking at building a unit or a structure that may or may not have any
			//prerequisites.

			//Format the cost only when we have to pay for it.
			costToBuild = thingTemplate->calcCostToBuild(player);
			if (costToBuild > 0)
			{
				cost.format(TheGameText->fetch("TOOLTIP:Cost"), costToBuild);
			}

			// ask each prerequisite to give us a list of the non satisfied prerequisites
			for (Int i = 0; i < thingTemplate->getPrereqCount(); i++)
			{
				prereq = thingTemplate->getNthPrereq(i);
				requiresList = prereq->getRequiresList(player);
				conflictsList = prereq->getConflictList(player);
				if (requiresList != UnicodeString::TheEmptyString)
				{
					// make sure to put in 'returns' to space things correctly
					if (firstRequirement)
						firstRequirement = false;
					else
						requiresFormat.concat(L", ");
				}
				requiresFormat.concat(requiresList);

				if (conflictsList != UnicodeString::TheEmptyString)
				{
					// make sure to put in 'returns' to space things correctly
					if (firstConflicts)
						firstConflicts = false;
					else
						conflictsFormat.concat(L", ");
				}
				conflictsFormat.concat(conflictsList);
			}
			
		}
		else if (upgradeTemplate)
		{
			//We are looking at an upgrade purchase icon. Maybe we already purchased it?

			Bool hasUpgradeAlready = player->hasUpgradeComplete(upgradeTemplate);
			Bool hasConflictingUpgrade = FALSE;
			Bool missingScience = FALSE;
			Bool playerUpgradeButton = commandButton->getCommandType() == GUI_COMMAND_PLAYER_UPGRADE;
			Bool objectUpgradeButton = commandButton->getCommandType() == GUI_COMMAND_OBJECT_UPGRADE;

			if (!hasUpgradeAlready)
			{
				//Check if the first selected object has the specified upgrade.
				Drawable* draw = TheInGameUI->getFirstSelectedDrawable();
				if (draw)
				{
					Object* object = draw->getObject();
					if (object)
					{
						hasUpgradeAlready = object->hasUpgrade(upgradeTemplate);
						if (objectUpgradeButton)
						{
							hasConflictingUpgrade = !object->affectedByUpgrade(upgradeTemplate);
						}
					}
				}
			}
			if (hasConflictingUpgrade && !hasUpgradeAlready)
			{
				if (commandButton->getConflictingLabel().isNotEmpty())
				{
					descrip = TheGameText->fetch(commandButton->getConflictingLabel());
				}
				else
				{
					descrip = TheGameText->fetch("TOOLTIP:HasConflictingUpgradeDefault");
				}
			}
			else if (hasUpgradeAlready && (playerUpgradeButton || objectUpgradeButton))
			{
				//See if we can fetch the "already upgraded" text for this upgrade. If not.... use the default "fill me in".
				if (commandButton->getPurchasedLabel().isNotEmpty())
				{
					descrip = TheGameText->fetch(commandButton->getPurchasedLabel());
				}
				else
				{
					descrip = TheGameText->fetch("TOOLTIP:AlreadyUpgradedDefault");
				}
			}
			else if (!hasUpgradeAlready)
			{

				//Do we have a prerequisite science?
				for (size_t i = 0; i < commandButton->getScienceVec().size(); i++)
				{
					ScienceType st = commandButton->getScienceVec()[i];
					if (!player->hasScience(st))
					{
						missingScience = TRUE;
						break;
					}
				}

				//Determine the cost of the upgrade.
				costToBuild = upgradeTemplate->calcCostToBuild(player);
				if (costToBuild > 0)
				{
					cost.format(TheGameText->fetch("TOOLTIP:Cost"), costToBuild);
				}

				if (missingScience)
				{
					if (!descrip.isEmpty())
						descrip.concat(L"\n");
					requiresFormat.format(TheGameText->fetch("CONTROLBAR:Requirements").str(), TheGameText->fetch("CONTROLBAR:GeneralsPromotion").str());
					descrip.concat(requiresFormat);
				}
			}
		}
		else if (st != SCIENCE_INVALID && !fireScienceButton)
		{
			TheScienceStore->getNameAndDescription(st, name, descrip);

			costToBuild = TheScienceStore->getSciencePurchaseCost(st);
			if (costToBuild > 0)
			{
				cost.format(TheGameText->fetch("TOOLTIP:ScienceCost"), costToBuild);
			}

			// ask each prerequisite to give us a list of the non satisfied prerequisites
			if (thingTemplate)
			{
				for (Int i = 0; i < thingTemplate->getPrereqCount(); i++)
				{
					prereq = thingTemplate->getNthPrereq(i);
					requiresList = prereq->getRequiresList(player);

					if (requiresList != UnicodeString::TheEmptyString)
					{
						// make sure to put in 'returns' to space things correctly
						if (firstRequirement)
							firstRequirement = false;
						else
							requiresFormat.concat(L", ");
					}
					requiresFormat.concat(requiresList);
				}
				if (!requiresFormat.isEmpty())
				{
					UnicodeString requireFormat = TheGameText->fetch("CONTROLBAR:Requirements");
					requiresFormat.format(requireFormat.str(), requiresFormat.str());
					if (!descrip.isEmpty())
						descrip.concat(L"\n");
					descrip.concat(requiresFormat);
				}
			}

		}
		if (specialPowerTemplate)
		{
			//We are looking at a special power button
			
			//Get the cost to use the special power
			costToBuild = specialPowerTemplate->getUsingCost();
			if (costToBuild > 0)
			{
				cost.format(TheGameText->fetch("TOOLTIP:Cost"), costToBuild);
			}

			if (!specialPowerTemplate->canAffordUsingPower(player, selectedObject))
			{
				descrip.concat(L"\n\n");
				descrip.concat(TheGameText->fetch("TOOLTIP:TooltipNotEnoughMoneyToBuild"));
			}
			
		}

		// TheSuperHackers @feature author 15/01/2025 Handle inventory replenishment cost using centralized method
		if (commandButton->getCommandType() == GUI_COMMAND_REPLENISH_INVENTORY_ITEM)
		{
			// Get the current object for inventory calculation
			Drawable* draw = TheInGameUI->getFirstSelectedDrawable();
			Object* selectedObject = draw ? draw->getObject() : NULL;
			
			if (selectedObject)
			{
				// Use centralized cost calculation method
				costToBuild = commandButton->getCostOfExecution(player, selectedObject);
				if (costToBuild > 0)
				{
					cost.format(TheGameText->fetch("TOOLTIP:Cost"), costToBuild);
				}

				if (costToBuild > 0 && player->getMoney()->countMoney() < costToBuild)
				{
					descrip.concat(L"\n\n");
					descrip.concat(TheGameText->fetch("TOOLTIP:TooltipNotEnoughMoneyToBuild"));
				}
			}
		}

		// Add module descriptions from template
		// TheSuperHackers @tooltip author 01/01/2025 Append module descriptions to tooltip text
		if (thingTemplate)
		{
			UnicodeString modulesDesc = thingTemplate->getExtendedDescription();
			if (!modulesDesc.isEmpty())
			{
				if (!descrip.isEmpty())
					descrip += L"\n\n";
				descrip += modulesDesc;
			}
		}

		// Add button alternatives for right-click and modifier key combinations
		// TheSuperHackers @tooltip Ahmed Salah 27/06/2025 Append alternative command button descriptions to tooltip text
		UnicodeString alternativesText = getButtonAlternativesText(commandButton, this);
		if (!alternativesText.isEmpty())
		{
			descrip.concat(alternativesText);
		}

		if (!requiresFormat.isEmpty())
		{
			UnicodeString requireFormat = TheGameText->fetch("CONTROLBAR:Requirements");
			requiresFormat.format(requireFormat.str(), requiresFormat.str());
			if (!descrip.isEmpty())
				descrip.concat(L"\n\n");
			descrip.concat(requiresFormat);

		}

		if (!conflictsFormat.isEmpty())
		{
			UnicodeString conflictFormat = TheGameText->fetch("CONTROLBAR:Conflicts");
			conflictsFormat.format(conflictFormat.str(), conflictsFormat.str());
			if (!descrip.isEmpty()) {
				if (!requiresFormat.isEmpty())
				{
					descrip.concat(L"\n");
				}
				else
				{
					descrip.concat(L"\n\n");
				}
			}
				
			descrip.concat(conflictsFormat);
		}
	}
	else if (tooltipWin)
	{

		if (tooltipWin == TheWindowManager->winGetWindowFromId(m_buildToolTipLayout->getFirstWindow(), TheNameKeyGenerator->nameToKey("ControlBar.wnd:MoneyDisplay")))
		{
			name = TheGameText->fetch("CONTROLBAR:Money");
			descrip = TheGameText->fetch("CONTROLBAR:MoneyDescription");
		}
		else if (tooltipWin == TheWindowManager->winGetWindowFromId(m_buildToolTipLayout->getFirstWindow(), TheNameKeyGenerator->nameToKey("ControlBar.wnd:PowerWindow")))
		{
			name = TheGameText->fetch("CONTROLBAR:Power");
			descrip = TheGameText->fetch("CONTROLBAR:PowerDescription");

			Player* playerToDisplay = TheControlBar->getCurrentlyViewedPlayer();

			if (playerToDisplay && playerToDisplay->getEnergy())
			{
				Energy* energy = playerToDisplay->getEnergy();
				descrip.format(descrip, energy->getProduction(), energy->getConsumption());
			}
			else
			{
				descrip.format(descrip, 0, 0);
			}
		}
		else if (tooltipWin == TheWindowManager->winGetWindowFromId(m_buildToolTipLayout->getFirstWindow(), TheNameKeyGenerator->nameToKey("ControlBar.wnd:GeneralsExp")))
		{
			name = TheGameText->fetch("CONTROLBAR:GeneralsExp");
			descrip = TheGameText->fetch("CONTROLBAR:GeneralsExpDescription");
		}
		else
		{
			DEBUG_ASSERTCRASH(FALSE, ("ControlBar::populateBuildTooltipLayout We attempted to call the popup tooltip on a game window that has yet to be hand coded in as this fuction was/is designed for only buttons but has been hacked to work with GameWindows."));
			return;
		}

	}
	GameWindow* win = TheWindowManager->winGetWindowFromId(m_buildToolTipLayout->getFirstWindow(), TheNameKeyGenerator->nameToKey("ControlBarPopupDescription.wnd:StaticTextName"));
	if (win)
	{
		GadgetStaticTextSetText(win, name);
	}

	win = TheWindowManager->winGetWindowFromId(m_buildToolTipLayout->getFirstWindow(), TheNameKeyGenerator->nameToKey("ControlBarPopupDescription.wnd:StaticTextCost"));
	if (win)
	{
		if (costToBuild > 0)
		{
			win->winHide(FALSE);
			GadgetStaticTextSetText(win, cost);
		}
		else
		{
			win->winHide(TRUE);
		}
	}


	win = TheWindowManager->winGetWindowFromId(m_buildToolTipLayout->getFirstWindow(), TheNameKeyGenerator->nameToKey("ControlBarPopupDescription.wnd:StaticTextDescription"));
	if (win)
	{

		static NameKeyType winNamekey = TheNameKeyGenerator->nameToKey(AsciiString("ControlBar.wnd:BackgroundMarker"));
		static ICoord2D lastOffset = { 0, 0 };

		ICoord2D size, newSize, pos;
		Int diffSize;

		DisplayString* tempDString = TheDisplayStringManager->newDisplayString();
		win->winGetSize(&size.x, &size.y);
		tempDString->setFont(win->winGetFont());
		tempDString->setWordWrap(size.x - 10);
		tempDString->setText(descrip);
		tempDString->getSize(&newSize.x, &newSize.y);
		TheDisplayStringManager->freeDisplayString(tempDString);
		tempDString = NULL;
		diffSize = newSize.y - size.y;
		GameWindow* parent = m_buildToolTipLayout->getFirstWindow();
		if (!parent)
			return;

		parent->winGetSize(&size.x, &size.y);
		if (size.y + diffSize < 102) {
			diffSize = 102 - size.y;
		}

		parent->winSetSize(size.x, size.y + diffSize);
		parent->winGetPosition(&pos.x, &pos.y);
		//		if(size.y + diffSize < 102)
		//		{
		//
		//			parent->winSetPosition(pos.x, pos.y -  (102 - (newSize.y + size.y + diffSize) ));
		//		}
		//		else

		//		heightChange = controlBarPos.y - m_defaultControlBarPosition.y;

		GameWindow* marker = TheWindowManager->winGetWindowFromId(NULL, winNamekey);
		static ICoord2D basePos;
		if (!marker)
		{
			return;
		}
		TheControlBar->getBackgroundMarkerPos(&basePos.x, &basePos.y);
		ICoord2D curPos, offset;
		marker->winGetScreenPosition(&curPos.x, &curPos.y);

		offset.x = curPos.x - basePos.x;
		offset.y = curPos.y - basePos.y;

		parent->winSetPosition(pos.x, (pos.y - diffSize) + (offset.y - lastOffset.y));

		lastOffset.x = offset.x;
		lastOffset.y = offset.y;

		win->winGetSize(&size.x, &size.y);
		win->winSetSize(size.x, size.y + diffSize);

		GadgetStaticTextSetText(win, descrip);
	}
	m_buildToolTipLayout->hide(FALSE);

}

// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
void ControlBar::hideBuildTooltipLayout()
{
	if (theAnimateWindowManager && theAnimateWindowManager->isReversed())
		return;
	if (useAnimation && theAnimateWindowManager && TheGlobalData->m_animateWindows)
		theAnimateWindowManager->reverseAnimateWindow();
	else
		deleteBuildTooltipLayout();

}

void ControlBar::deleteBuildTooltipLayout(void)
{
	m_showBuildToolTipLayout = FALSE;
	prevWindow = NULL;
	m_buildToolTipLayout->hide(TRUE);
//	if(!m_buildToolTipLayout)
//		return;
//
//	m_buildToolTipLayout->destroyWindows();
//	deleteInstance(m_buildToolTipLayout);
//	m_buildToolTipLayout = NULL;

	delete theAnimateWindowManager;
	theAnimateWindowManager = NULL;

}
