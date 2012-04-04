/******************************************************************************
/ SnM_Track.h
/
/ Copyright (c) 2012 Jeffos
/ http://www.standingwaterstudios.com/reaper
/
/ Permission is hereby granted, free of charge, to any person obtaining a copy
/ of this software and associated documentation files (the "Software"), to deal
/ in the Software without restriction, including without limitation the rights to
/ use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
/ of the Software, and to permit persons to whom the Software is furnished to
/ do so, subject to the following conditions:
/ 
/ The above copyright notice and this permission notice shall be included in all
/ copies or substantial portions of the Software.
/ 
/ THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
/ EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
/ OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
/ NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
/ HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
/ WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
/ FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
/ OTHER DEALINGS IN THE SOFTWARE.
/
******************************************************************************/

//#pragma once

#ifndef _SNM_TRACK_H_
#define _SNM_TRACK_H_

class SNM_TrackInt {
public:
	SNM_TrackInt(MediaTrack* _tr, int _i) : m_tr(_tr), m_int(_i) {}
	~SNM_TrackInt() {}
	MediaTrack* m_tr;
	int m_int;
};

extern int g_SNMMediaFlags;

void ScrollSelTrack(const char* _undoTitle, bool _tcp, bool _mcp);
void ScrollSelTrack(COMMAND_T*);
void copyCutTrackGrouping(COMMAND_T*);
void pasteTrackGrouping(COMMAND_T*);
void removeTrackGrouping(COMMAND_T*);
void SetTrackGroup(COMMAND_T*);
void SetTrackToFirstUnusedGroup(COMMAND_T*);
void saveTracksFolderStates(COMMAND_T*);
void restoreTracksFolderStates(COMMAND_T*);
void setTracksFolderState(COMMAND_T*);
void SelOnlyTrackWithSelEnv(COMMAND_T*);
int trackEnvelopesCount();
const char* trackEnvelope(int _i);
bool trackEnvelopesLookup(const char* _str);
void toggleArmTrackEnv(COMMAND_T*);
void toggleWriteEnvExists(COMMAND_T*);
bool writeEnvExists(COMMAND_T*);
MediaTrack* SNM_GetTrack(ReaProject* _proj, int _idx);
int SNM_GetTrackId(ReaProject* _proj, MediaTrack* _tr);
int SNM_CountSelectedTracks(ReaProject* _proj, bool _master);
MediaTrack* SNM_GetSelectedTrack(ReaProject* _proj, int _idx, bool _withMaster);
void SNM_GetSelectedTracks(ReaProject* _proj, WDL_PtrList<MediaTrack>* _trs, bool _withMaster);
bool SNM_SetSelectedTracks(ReaProject* _proj, WDL_PtrList<MediaTrack>* _trs, bool _unselOthers, bool _withMaster = true);
bool SNM_SetSelectedTrack(ReaProject* _proj, MediaTrack* _tr, bool _unselOthers, bool _withMaster = true);
void SNM_ClearSelectedTracks(ReaProject* _proj, bool _withMaster);
bool GetTrackIcon(MediaTrack* _tr, char* _fnOut, int _fnOutSz);
void SetTrackIcon(MediaTrack* _tr, const char* _fn);
void SetSelTrackIcon(const char* _fn);
bool applyTrackTemplate(MediaTrack* _tr, WDL_FastString* _tmpltChunk, bool _itemsFromTmplt, bool _envsFromTmplt, SNM_ChunkParserPatcher* _p = NULL, bool _isRawTmpltChunk = true);
void ImportTrackTemplateSlot(int _slotType, const char* _title, int _slot);
void ApplyTrackTemplateSlot(int _slotType, const char* _title, int _slot, bool _itemsFromTmplt, bool _envsFromTmplt);
void ReplacePasteItemsTrackTemplateSlot(int _slotType, const char* _title, int _slot, bool _paste);
void LoadApplyTrackTemplateSlot(COMMAND_T*);
void LoadApplyTrackTemplateSlotWithItemsEnvs(COMMAND_T*);
void LoadImportTrackTemplateSlot(COMMAND_T*);
bool autoSaveTrackSlots(int _slotType, const char* _dirPath, char* _fn, int _fnSize, bool _delItems, bool _delEnvs);
void setMIDIInputChannel(COMMAND_T*);
void remapMIDIInputChannel(COMMAND_T*);
void StopTrackPreviewsRun();
bool SNM_PlayTrackPreview(MediaTrack* _tr, PCM_source* _src, bool _pause, bool _loop, double _msi);
bool SNM_PlayTrackPreview(MediaTrack* _tr, const char* _fn, bool _pause, bool _loop, double _msi);
void SNM_PlaySelTrackPreviews(const char* _fn, bool _pause, bool _loop, double _msi);
bool SNM_TogglePlaySelTrackPreviews(const char* _fn, bool _pause, bool _loop, double _msi = -1.0);
void StopTrackPreviews(bool _selTracksOnly);
void StopTrackPreviews(COMMAND_T*);
void CC123Track(MediaTrack* _tr);
void CC123Tracks(WDL_PtrList<void>* _trs);
void CC123SelTracks(COMMAND_T*);

#endif