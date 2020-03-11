#ifndef CONTROLPANELS_CSEQUENCESPANEL_H
#define CONTROLPANELS_CSEQUENCESPANEL_H

#include <vector>

#include <glm/vec3.hpp>

#include "cvar/CCVar.h"

#include "CBaseControlPanel.h"

class wxToggleButton;
class wxSpinCtrlDouble;
class wxSpinDoubleEvent;
struct mstudiobone_t;

namespace hlmv
{
class CSequencesPanel final : public CBaseControlPanel, public cvar::ICVarHandler
{
private:
	static const int ANIMSPEED_MIN = 0;
	static const int ANIMSPEED_MAX = 10;
	static const int ANIMSPEED_DEFAULT = 1;
	static const int ANIMSPEED_SLIDER_MULTIPLIER = 40;

	static const int CROSSHAIR_LINE_WIDTH = 3;
	static const int CROSSHAIR_LINE_START = 5;
	static const int CROSSHAIR_LINE_LENGTH = 10;
	static const int CROSSHAIR_LINE_END = CROSSHAIR_LINE_START + CROSSHAIR_LINE_LENGTH;

	static const int GUIDELINES_LINE_WIDTH = 1;
	static const int GUIDELINES_LINE_LENGTH = 5;
	static const int GUIDELINES_POINT_LINE_OFFSET = 2;
	static const int GUIDELINES_OFFSET = GUIDELINES_LINE_LENGTH + ( GUIDELINES_POINT_LINE_OFFSET * 2 ) + GUIDELINES_LINE_WIDTH;

	static const int GUIDELINES_EDGE_WIDTH = 4;

	struct RootBoneData
	{
		mstudiobone_t* Bone;
		glm::vec3 OriginalRootBonePosition;
	};

public:
	CSequencesPanel( wxWindow* pParent, CModelViewerApp* const pHLMV );
	~CSequencesPanel();

	void Draw3D( const wxSize& size ) override;

	void InitializeUI() override;

	void SetSequence( int iIndex );

	void SetFrame( int iFrame );

protected:
	wxDECLARE_EVENT_TABLE();

	virtual void HandleCVar( cvar::CCVar& cvar, const char* pszOldValue, float flOldValue ) override;

private:
	void SetFrameControlsEnabled( const bool bState );

	void UpdateEvents();

	void UpdateEventInfo( int iIndex );

	void UpdateOrigin();

	void SequenceChanged( wxCommandEvent& event );

	void TogglePlay( wxCommandEvent& event );

	void PrevFrame( wxCommandEvent& event );

	void NextFrame( wxCommandEvent& event );

	void FrameChanged( wxCommandEvent& event );

	void AnimSpeedChanged( wxCommandEvent& event );

	void AnimSpeedSpinnerChanged(wxSpinDoubleEvent& event);

	void ResetAnimSpeed(wxCommandEvent& event);

	void EventChanged( wxCommandEvent& event );

	void OnEditEvents( wxCommandEvent& event );

	void PlaySoundChanged( wxCommandEvent& event );

	void PitchFramerateChanged( wxCommandEvent& event );

	void OnOriginChanged( wxSpinDoubleEvent& event );

	void TestOrigin( wxCommandEvent& event );

private:
	wxChoice* m_pSequence;

	wxToggleButton* m_pTogglePlayButton;
	wxButton* m_pPrevFrameButton;
	wxTextCtrl* m_pSequenceFrame;
	wxButton* m_pNextFrameButton;

	wxSlider* m_pAnimSpeed;
	wxSpinCtrlDouble* m_pAnimSpeedSpinner;
	wxButton* m_pResetSpeedButton;

	wxPanel* m_pSequenceInfo;

	wxStaticText* m_pSequenceIndex;
	wxStaticText* m_pFrameCount;
	wxStaticText* m_pFrameRate;
	wxStaticText* m_pBlends;
	wxStaticText* m_pEventCount;

	wxChoice* m_pEvent;

	wxCheckBox* m_pPlaySound;
	wxCheckBox* m_pPitchFramerate;

	wxButton* m_pEditEvents;

	wxPanel* m_pEventInfo;

	wxStaticText* m_pFrame;
	wxStaticText* m_pEventId;
	wxStaticText* m_pOptions;
	wxStaticText* m_pType;

	wxSpinCtrlDouble* m_pOrigin[ 3 ];

	wxButton* m_pTestOrigins;

	wxCheckBox* m_pShowCrosshair;
	wxCheckBox* m_pShowGuidelines;

	std::vector<RootBoneData> m_RootBonePositions;

private:
	CSequencesPanel( const CSequencesPanel& ) = delete;
	CSequencesPanel& operator=( const CSequencesPanel& ) = delete;
};
}

#endif //CONTROLPANELS_CSEQUENCESPANEL_H