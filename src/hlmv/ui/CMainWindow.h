#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include "wxHLMV.h"

#include "hlmv/settings/CHLMVSettings.h"
#include "hlmv/CHLMVState.h"

namespace hlmv
{
class CHLMV;
class CMainPanel;

class CMainWindow final : public wxFrame
{
public:
	CMainWindow( CHLMV* const pHLMV );
	~CMainWindow();

	const CHLMV* GetHLMV() const { return m_pHLMV; }
	CHLMV* GetHLMV() { return m_pHLMV; }

	void RunFrame();

	bool LoadModel( const wxString& szFilename );
	bool PromptLoadModel();

	bool SaveModel( const wxString& szFilename );
	bool PromptSaveModel();

	bool LoadBackgroundTexture( const wxString& szFilename );
	bool PromptLoadBackgroundTexture();

	void UnloadBackgroundTexture();

	bool LoadGroundTexture( const wxString& szFilename );
	bool PromptLoadGroundTexture();

	void UnloadGroundTexture();

	void SaveUVMap( const wxString& szFilename, const int iTexture );

	void CenterView();

	void SaveView();

	void RestoreView();

	void TakeScreenshot();

	void DumpModelInfo();

private:
	wxDECLARE_EVENT_TABLE();

	void RefreshRecentFiles();

	void LoadModel( wxCommandEvent& event );
	void LoadBackgroundTexture( wxCommandEvent& event );
	void LoadGroundTexture( wxCommandEvent& event );
	void UnloadGroundTexture( wxCommandEvent& event );
	void SaveModel( wxCommandEvent& event );
	void OpenRecentFile( wxCommandEvent& event );
	void OnExit( wxCommandEvent& event );

	void CenterView( wxCommandEvent& event );
	void SaveView( wxCommandEvent& event );
	void RestoreView( wxCommandEvent& event );
	void TakeScreenshot( wxCommandEvent& event );
	void DumpModelInfo( wxCommandEvent& event );

	void ShowMessagesWindow( wxCommandEvent& event );
	void OpenOptionsDialog( wxCommandEvent& event );

	void OnAbout( wxCommandEvent& event );

	void OnMessagesWindowClosed( wxCloseEvent& event );

private:
	CHLMV* m_pHLMV;
	CMainPanel* m_pMainPanel;

	wxMenuItem* m_RecentFiles[ CHLMVSettings::MAX_RECENT_FILES ];

private:
	CMainWindow( const CMainWindow& ) = delete;
	CMainWindow& operator=( const CMainWindow& ) = delete;
};
}

#endif //CMAINWINDOW_H