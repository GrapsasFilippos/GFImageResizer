/*
 * GFImageResizer
 * Copyright (C) 2013  Grapsas A. Filippos
 *
 * GFImageResizer is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
outfile "GFImageResizer-20131128-beta-Win7.exe"
name "GFImageResizer"
installDir "$PROGRAMFILES\GFImageResizer"
LicenseData "..\gpl-3.0.txt"
LicenseBkColor 0xFFFFFF
ShowInstDetails show
ShowUninstDetails show

Page License
Page directory
Page InstFiles
UninstPage uninstConfirm
UninstPage instfiles

RequestExecutionLevel admin
 
Function .onInit
	userInfo::getAccountType
	pop $0
	strCmp $0 "Admin" +3
	messageBox MB_OK "Need admin account type for installation."
	Abort
FunctionEnd

section
	setOutPath "$INSTDIR"
	File /r "..\bin\release\*"
	#File "Program Files\GFImageResizer.exe"
	writeUninstaller "$INSTDIR\uninstaller.exe"
	
	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\GFImageResizer" \
		"DisplayName" "GFImageResizer"
	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\GFImageResizer" \
		"UninstallString" "$\"$INSTDIR\uninstaller.exe$\""
	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\GFImageResizer" \
		"InstallLocation" "$\"$INSTDIR$\""
	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\GFImageResizer" \
		"DisplayVersion" "20131128"
	
	SetShellVarContext all
	CreateDirectory "$SMPROGRAMS\GFImageResizer"
	CreateShortcut "$SMPROGRAMS\GFImageResizer\GFImageResizer.lnk" "$INSTDIR\GFImageResizer.exe"
sectionEnd

section "Uninstall"
	delete "$INSTDIR\uninstaller.exe"
	RMDir /r "$INSTDIR"
	
	DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\GFImageResizer"
	
	SetShellVarContext all
	RMDir /r "$SMPROGRAMS\GFImageResizer"
sectionEnd
