# Credits INI Documentation

## Overview

**⚠️ Work In Progress (WIP) ⚠️**

This documentation page is currently under development. The Credits INI file contains credits configuration settings and parameters for game credits display and management.

## Status

- **Documentation Status**: In Progress
- **Completion**: ~10%
- **Last Updated**: [Current Date]

## Planned Sections

- [ ] Overview and Usage
- [ ] Properties
- [ ] Enum Value Lists
- [ ] Examples
- [ ] Best Practices
- [ ] Notes

## Related Documentation

- [Campaign](Campaign.md) - Credits can be earned in campaigns
- [Object](Object.md) - Credits affect object costs
- [SpecialPower](SpecialPower.md) - Credits affect special power costs

---

**Note**: This page will be completed as part of the GMX documentation effort. For now, refer to the existing game files and source code for Credits template information.

## Example Structure

```ini
Credits
;//////////////////////////////////////////////////////////////////////////////
;FILE: Credits.ini   //////////////////////////////////////////////////////////
;//////////////////////////////////////////////////////////////////////////////
; Credits Format:
; The Credits.ini file is easy to use, at first glance though, it looks messed up.
; Here's a brief tutorial on the steps needed to enter the credits.
;--------------------------------------------------------------------------------
; The credits work by first declaring the style "Style =" you want for the text that will
; follow until another style is declared.  Then you can enter any number of "Text =" lines
; that will be using that style. Finally, you can have any number of "Blank" lines you want,
; anywhere in the file.
;
; -------------
; STYLES:
; Styles can be one of four types:
;     "TITLE"
;     "MINORTITLE"
;     "NORMAL"
;     "COLUMN"
; "TITLE" is the largest font, so every text line after that will be large.
; "MINORTITLE" is smaller the TITLE but should be used for important things other then Big Titles :)
; "NORMAL" is the smallest font, and should be used for the normal texts like names.
; "COLUMN" uses the same font as Normal but now requres that ever two "Text =" lines below it, will be on
;          one line in the screen.  Look at the example below to more visually understand this.
; You declare a style with a line like this and they can be declared in any order:
; Style = TITLE
;
; --------------
; TEXT:
; Text lines are the lines that will contain the text that will actually be displayed.  This line can
; contain either quoted strings, String Labels, or <BLANK>.
;
; Quoted strings are anything within double quotes ("Blah").  These should only be used for strings that
; are not going to be translated (so things like names).
; Example: Text = "Chris Huybregts"
;
; String labels are strings that we look up in the string file for.  How the code knows it's a string label
; is by searching for a ':' in the label.  This should be used for titles, positions, whatever. Remember that
; if you add a label here, it needs to also live in the Generals.str file
; Example: Text = GUI:Programmer
;
; <BLANK> is used if we want to have a no text in a text field.  This is useful for columns in which you don't
; want something in one or the other columns.
; Example: Text = <BLANK>
;
; ---------------
; BLANK:
; Blank is used whenever we want a blank line to separate text. Just put this identifier, with nothing else following it.
; Example: Blank
;
; ----------------
; EXAMPLE:
; Here's an example of each of the things.
;
; Credits
;   "This is where the header goes"
;   Style = TITLE
;   Text = GUI:EAPacificTitle
;   Blank
;   Style = NORMAL
;   Text = GUI:LegalStuff
;   Blank
;   Blank
;   Style = MINORTITLE
;   Text = GUI:Programmers
;   Style = COLUMN
;   Text = GUI:SeniorProgrammers
;   Text = "John Doe"
;   Text = <BLANK>
;   Text = "Jane Doe"
; END
; The output of the above would look like:
;               EA Pacific //In big letters
;
;               Trademark  // in a smaller text
;
;
;              Programmers // in the middle size font
;  Senior Programmers     John Doe  // the columns
;                         Jane Doe  // an example of using <BLANK>



Credits
; BEGIN HEADER
  ScrollRate              = 2                   ;How many pixels to move
  ScrollRateEveryFrames   = 1                   ;How many frames inbetween that we do the ScrollRate
  ScrollDown            = NO                    ;We can scroll up, or down... don't ask my why we'd want to scroll down
  TitleColor            = R:161 G:179 B:255 A:255 ;Color for style type TITLE
  MinorTitleColor       = R:161 G:179 B:255 A:255 ;Color for style type MINORTITLE
  NormalColor           = R:209 G:218 B:255 A:255 ;Color for style type NORMAL ;R:255 G:190 B:0 A:255
; END HEADER


  



  Style = MINORTITLE
  Text = CREDITS:TEXTINSTRFILES
  Style = NORMAL
  Text = CREDITS:TEXTINSTRFILES
  Blank
  Blank
  Style = MINORTITLE
  Text = CREDITS:TEXTINSTRFILES
  Style = NORMAL
  Text = CREDITS:TEXTINSTRFILES
  Blank
  Blank
  Style = MINORTITLE
  Text = CREDITS:TEXTINSTRFILES
  Style = NORMAL
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Blank
  Blank
  Style = MINORTITLE
  Text = CREDITS:TEXTINSTRFILES
  Style = NORMAL
  Text = CREDITS:TEXTINSTRFILES
  Blank
  Blank
  Style = MINORTITLE
  Text = CREDITS:TEXTINSTRFILES
  Style = NORMAL
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Blank
  Blank
  Style = MINORTITLE
  Text = CREDITS:TEXTINSTRFILES
  Style = NORMAL
  Text = CREDITS:TEXTINSTRFILES
  Blank
  Blank
  Style = MINORTITLE
  Text = CREDITS:TEXTINSTRFILES
  Style = NORMAL
  Text = CREDITS:TEXTINSTRFILES
  Blank
  Blank
  Style = MINORTITLE
  Text = CREDITS:TEXTINSTRFILES
  Style = NORMAL
  Text = CREDITS:TEXTINSTRFILES
  Blank
  Blank
  Style = MINORTITLE
  Text = CREDITS:TEXTINSTRFILES
  Style = NORMAL
  Text = CREDITS:TEXTINSTRFILES
  Blank
  Blank
  Style = MINORTITLE
  Text = CREDITS:TEXTINSTRFILES
  Style = NORMAL
  Text = CREDITS:TEXTINSTRFILES
  Blank
  Blank
  Style = MINORTITLE
  Text = CREDITS:TEXTINSTRFILES
  Style = NORMAL
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Blank
  Blank
  Style = MINORTITLE
  Text = CREDITS:TEXTINSTRFILES
  Style = NORMAL
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Text = CREDITS:TEXTINSTRFILES
  Blank
  Blank
  Style = MINORTITLE
  Text = CREDITS:TEXTINSTRFILES
  Style = MINORTITLE
  Text = CREDITS:TEXTINSTRFILES
  Blank
  Blank
  Blank
  Blank
  Blank
  Blank
  Blank
  Blank
  Blank
  Blank
  Blank
  Blank
  Blank
  Blank
  Blank
  Blank
  Blank
  Blank
  Style = NORMAL
  Text = CREDITS:TEXTINSTRFILES
End
```

## Source Files

- Header: [`GeneralsMD/Code/GameEngine/Include/GameLogic/Credits.h`](../GeneralsMD/Code/GameEngine/Include/GameLogic/Credits.h)
- Source: [`GeneralsMD/Code/GameEngine/Source/GameLogic/Credits/Credits.cpp`](../GeneralsMD/Code/GameEngine/Source/GameLogic/Credits/Credits.cpp)
